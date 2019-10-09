/* GIMP - The GNU Image Manipulation Program
 * Copyright (C) 1995 Spencer Kimball and Peter Mattis
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "config.h"

#include <string.h>

#include <cairo.h>
#include <gegl.h>

#include "libgimpcolor/gimpcolor.h"

#include "core-types.h"

#include "base/pixel-region.h"
#include "base/temp-buf.h"
#include "base/tile-manager.h"

#include "paint-funcs/paint-funcs.h"

#include "gimp.h"
#include "gimpchannel.h"
#include "gimpchannel-combine.h"
#include "gimpcontext.h"
#include "gimpdrawable.h"
#include "gimpdrawable-bucket-fill.h"
#include "gimperror.h"
#include "gimpimage.h"
#include "gimpimage-contiguous-region.h"
#include "gimppattern.h"

#include "gimp-intl.h"


/*  public functions  */

gboolean
gimp_drawable_bucket_fill (GimpDrawable         *drawable,
                           GimpContext          *context,
                           GimpBucketFillMode    fill_mode,
                           gint                  paint_mode,
                           gdouble               opacity,
                           gboolean              do_seed_fill,
                           gboolean              fill_transparent,
                           GimpSelectCriterion   fill_criterion,
                           gdouble               threshold,
                           gboolean              sample_merged,
                           gdouble               x,
                           gdouble               y,
                           GError              **error)
{
  GimpRGB      color;
  GimpPattern *pattern = NULL;

  g_return_val_if_fail (GIMP_IS_DRAWABLE (drawable), FALSE);
  g_return_val_if_fail (gimp_item_is_attached (GIMP_ITEM (drawable)), FALSE);
  g_return_val_if_fail (GIMP_IS_CONTEXT (context), FALSE);
  g_return_val_if_fail (error == NULL || *error == NULL, FALSE);

  if (fill_mode == GIMP_FG_BUCKET_FILL)
    {
      gimp_context_get_foreground (context, &color);
    }
  else if (fill_mode == GIMP_BG_BUCKET_FILL)
    {
      gimp_context_get_background (context, &color);
    }
  else if (fill_mode == GIMP_PATTERN_BUCKET_FILL)
    {
      pattern = gimp_context_get_pattern (context);

      if (! pattern)
        {
          g_set_error_literal (error, GIMP_ERROR, GIMP_FAILED,
			       _("No patterns available for this operation."));
          return FALSE;
        }
    }
  else
    {
      g_warning ("%s: invalid fill_mode passed", G_STRFUNC);
      return FALSE;
    }

  gimp_drawable_bucket_fill_full (drawable,
                                  fill_mode,
                                  paint_mode, opacity,
                                  do_seed_fill,
                                  fill_transparent, fill_criterion,
                                  threshold, sample_merged,
                                  x, y,
                                  &color, pattern);

  return TRUE;
}

void
gimp_drawable_bucket_fill_full (GimpDrawable        *drawable,
                                GimpBucketFillMode   fill_mode,
                                gint                 paint_mode,
                                gdouble              opacity,
                                gboolean             do_seed_fill,
                                gboolean             fill_transparent,
                                GimpSelectCriterion  fill_criterion,
                                gdouble              threshold,
                                gboolean             sample_merged,
                                gdouble              x,
                                gdouble              y,
                                const GimpRGB       *color,
                                GimpPattern         *pattern)
{
  GimpImage   *image;
  TileManager *buf_tiles;
  PixelRegion  bufPR, maskPR;
  GimpChannel *mask = NULL;
  gint         bytes;
  gint         x1, y1, x2, y2;
  guchar       col[MAX_CHANNELS];
  TempBuf     *pat_buf = NULL;
  gboolean     new_buf = FALSE;
  gboolean     selection;

  g_return_if_fail (GIMP_IS_DRAWABLE (drawable));
  g_return_if_fail (gimp_item_is_attached (GIMP_ITEM (drawable)));
  g_return_if_fail (fill_mode != GIMP_PATTERN_BUCKET_FILL ||
                    GIMP_IS_PATTERN (pattern));
  g_return_if_fail (fill_mode == GIMP_PATTERN_BUCKET_FILL ||
                    color != NULL);

  image = gimp_item_get_image (GIMP_ITEM (drawable));

  bytes     = gimp_drawable_bytes (drawable);
  selection = gimp_item_mask_bounds (GIMP_ITEM (drawable), &x1, &y1, &x2, &y2);

  if ((x1 == x2) || (y1 == y2))
    return;

  if (fill_mode == GIMP_FG_BUCKET_FILL ||
      fill_mode == GIMP_BG_BUCKET_FILL)
    {
      guchar tmp_col[MAX_CHANNELS];

      gimp_rgb_get_uchar (color,
                          &tmp_col[RED],
                          &tmp_col[GREEN],
                          &tmp_col[BLUE]);

      gimp_image_transform_color (image, gimp_drawable_type (drawable), col,
                                  GIMP_RGB, tmp_col);
      col[gimp_drawable_bytes_with_alpha (drawable) - 1] = OPAQUE_OPACITY;
    }
  else if (fill_mode == GIMP_PATTERN_BUCKET_FILL)
    {
      pat_buf = gimp_image_transform_temp_buf (image,
                                               gimp_drawable_type (drawable),
                                               pattern->mask, &new_buf);
    }
  else
    {
      g_warning ("%s: invalid fill_mode passed", G_STRFUNC);
      return;
    }

  gimp_set_busy (image->gimp);

  /*  Do a seed bucket fill...To do this, calculate a new
   *  contiguous region. If there is a selection, calculate the
   *  intersection of this region with the existing selection.
   */
  if (do_seed_fill)
    {
      mask = gimp_image_contiguous_region_by_seed (image, drawable,
                                                   sample_merged,
                                                   TRUE,
                                                   (gint) threshold,
                                                   fill_transparent,
                                                   fill_criterion,
                                                   (gint) x,
                                                   (gint) y);

      if (selection)
        {
          gint off_x = 0;
          gint off_y = 0;

          if (! sample_merged)
            gimp_item_get_offset (GIMP_ITEM (drawable), &off_x, &off_y);

          gimp_channel_combine_mask (mask, gimp_image_get_mask (image),
                                     GIMP_CHANNEL_OP_INTERSECT,
                                     -off_x, -off_y);
        }

      gimp_channel_bounds (mask, &x1, &y1, &x2, &y2);

      /*  make sure we handle the mask correctly if it was sample-merged  */
      if (sample_merged)
        {
          GimpItem *item;
          gint      off_x, off_y;

          item = GIMP_ITEM (drawable);

          /*  Limit the channel bounds to the drawable's extents  */
          gimp_item_get_offset (item, &off_x, &off_y);

          x1 = CLAMP (x1, off_x, (off_x + gimp_item_get_width (item)));
          y1 = CLAMP (y1, off_y, (off_y + gimp_item_get_height (item)));
          x2 = CLAMP (x2, off_x, (off_x + gimp_item_get_width (item)));
          y2 = CLAMP (y2, off_y, (off_y + gimp_item_get_height (item)));

          pixel_region_init (&maskPR,
                             gimp_drawable_get_tiles (GIMP_DRAWABLE (mask)),
                             x1, y1, (x2 - x1), (y2 - y1), TRUE);

          /*  translate mask bounds to drawable coords  */
          x1 -= off_x;
          y1 -= off_y;
          x2 -= off_x;
          y2 -= off_y;
        }
      else
        {
          pixel_region_init (&maskPR,
                             gimp_drawable_get_tiles (GIMP_DRAWABLE (mask)),
                             x1, y1, (x2 - x1), (y2 - y1), TRUE);
        }

      /*  if the image doesn't have an alpha channel, make sure that
       *  the buf_tiles have.  We need the alpha channel to fill with
       *  the region calculated above
       */
      if (! gimp_drawable_has_alpha (drawable))
        bytes++;
    }
  else if (fill_mode == GIMP_PATTERN_BUCKET_FILL &&
           (pat_buf->bytes == 2 || pat_buf->bytes == 4))
    {
      /* If pattern being applied has an alpha channel, add one to the
       * buf_tiles.
       */
      if (! gimp_drawable_has_alpha (drawable))
        bytes++;
    }

  buf_tiles = tile_manager_new ((x2 - x1), (y2 - y1), bytes);
  pixel_region_init (&bufPR, buf_tiles, 0, 0, (x2 - x1), (y2 - y1), TRUE);

  switch (fill_mode)
    {
    case GIMP_FG_BUCKET_FILL:
    case GIMP_BG_BUCKET_FILL:
      if (mask)
        color_region_mask (&bufPR, &maskPR, col);
      else
        color_region (&bufPR, col);
      break;

    case GIMP_PATTERN_BUCKET_FILL:
      if (mask)
        pattern_region (&bufPR, &maskPR, pat_buf, x1, y1);
      else
        pattern_region (&bufPR, NULL, pat_buf, x1, y1);
      break;
    }

  /*  Apply it to the image  */
  pixel_region_init (&bufPR, buf_tiles, 0, 0, (x2 - x1), (y2 - y1), FALSE);
  gimp_drawable_apply_region (drawable, &bufPR,
                              TRUE, C_("undo-type", "Bucket Fill"),
                              opacity, paint_mode,
                              NULL, NULL, x1, y1);
  tile_manager_unref (buf_tiles);

  /*  update the image  */
  gimp_drawable_update (drawable, x1, y1, x2 - x1, y2 - y1);

  /*  free the mask  */
  if (mask)
    g_object_unref (mask);

  if (new_buf)
    temp_buf_free (pat_buf);

  gimp_unset_busy (image->gimp);
}
