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

#include <gegl.h>

#include "libgimpbase/gimpbase.h"

#include "paint-types.h"

#include "base/temp-buf.h"
#include "base/tile-manager.h"
#include "base/pixel-region.h"

#include "core/gimp.h"
#include "core/gimpdrawable.h"
#include "core/gimpdynamics.h"
#include "core/gimpdynamicsoutput.h"
#include "core/gimperror.h"
#include "core/gimpimage.h"
#include "core/gimppickable.h"

#include "gimpsourcecore.h"
#include "gimpsourceoptions.h"

#include "gimp-intl.h"


enum
{
  PROP_0,
  PROP_SRC_DRAWABLE,
  PROP_SRC_X,
  PROP_SRC_Y
};


static void     gimp_source_core_set_property    (GObject          *object,
                                                  guint             property_id,
                                                  const GValue     *value,
                                                  GParamSpec       *pspec);
static void     gimp_source_core_get_property    (GObject          *object,
                                                  guint             property_id,
                                                  GValue           *value,
                                                  GParamSpec       *pspec);

static gboolean gimp_source_core_start           (GimpPaintCore    *paint_core,
                                                  GimpDrawable     *drawable,
                                                  GimpPaintOptions *paint_options,
                                                  const GimpCoords *coords,
                                                  GError          **error);
static void     gimp_source_core_paint           (GimpPaintCore    *paint_core,
                                                  GimpDrawable     *drawable,
                                                  GimpPaintOptions *paint_options,
                                                  const GimpCoords *coords,
                                                  GimpPaintState    paint_state,
                                                  guint32           time);

#if 0
static void     gimp_source_core_motion          (GimpSourceCore   *source_core,
                                                  GimpDrawable     *drawable,
                                                  GimpPaintOptions *paint_options,
                                                  const GimpCoords *coords);
#endif

static gboolean gimp_source_core_real_get_source (GimpSourceCore   *source_core,
                                                  GimpDrawable     *drawable,
                                                  GimpPaintOptions *paint_options,
                                                  GimpPickable     *src_pickable,
                                                  gint              src_offset_x,
                                                  gint              src_offset_y,
                                                  TempBuf          *paint_area,
                                                  gint             *paint_area_offset_x,
                                                  gint             *paint_area_offset_y,
                                                  gint             *paint_area_width,
                                                  gint             *paint_area_height,
                                                  PixelRegion      *srcPR);

static void    gimp_source_core_set_src_drawable (GimpSourceCore   *source_core,
                                                  GimpDrawable     *drawable);


G_DEFINE_TYPE (GimpSourceCore, gimp_source_core, GIMP_TYPE_BRUSH_CORE)

#define parent_class gimp_source_core_parent_class


static void
gimp_source_core_class_init (GimpSourceCoreClass *klass)
{
  GObjectClass       *object_class     = G_OBJECT_CLASS (klass);
  GimpPaintCoreClass *paint_core_class = GIMP_PAINT_CORE_CLASS (klass);
  GimpBrushCoreClass *brush_core_class = GIMP_BRUSH_CORE_CLASS (klass);

  object_class->set_property               = gimp_source_core_set_property;
  object_class->get_property               = gimp_source_core_get_property;

  paint_core_class->start                  = gimp_source_core_start;
  paint_core_class->paint                  = gimp_source_core_paint;

  brush_core_class->handles_changing_brush = TRUE;

  klass->get_source                        = gimp_source_core_real_get_source;
  klass->motion                            = NULL;

  g_object_class_install_property (object_class, PROP_SRC_DRAWABLE,
                                   g_param_spec_object ("src-drawable",
                                                        NULL, NULL,
                                                        GIMP_TYPE_DRAWABLE,
                                                        GIMP_PARAM_READWRITE));

  g_object_class_install_property (object_class, PROP_SRC_X,
                                   g_param_spec_double ("src-x", NULL, NULL,
                                                        0, GIMP_MAX_IMAGE_SIZE,
                                                        0.0,
                                                        GIMP_PARAM_READWRITE));

  g_object_class_install_property (object_class, PROP_SRC_Y,
                                   g_param_spec_double ("src-y", NULL, NULL,
                                                        0, GIMP_MAX_IMAGE_SIZE,
                                                        0.0,
                                                        GIMP_PARAM_READWRITE));
}

static void
gimp_source_core_init (GimpSourceCore *source_core)
{
  source_core->set_source   = FALSE;

  source_core->src_drawable = NULL;
  source_core->src_x        = 0.0;
  source_core->src_y        = 0.0;

  source_core->orig_src_x   = 0.0;
  source_core->orig_src_y   = 0.0;

  source_core->offset_x     = 0.0;
  source_core->offset_y     = 0.0;
  source_core->first_stroke = TRUE;
}

static void
gimp_source_core_set_property (GObject      *object,
                               guint         property_id,
                               const GValue *value,
                               GParamSpec   *pspec)
{
  GimpSourceCore *source_core = GIMP_SOURCE_CORE (object);

  switch (property_id)
    {
    case PROP_SRC_DRAWABLE:
      gimp_source_core_set_src_drawable (source_core,
                                         g_value_get_object (value));
      break;
    case PROP_SRC_X:
      source_core->src_x = g_value_get_double (value);
      break;
    case PROP_SRC_Y:
      source_core->src_y = g_value_get_double (value);
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
      break;
    }
}

static void
gimp_source_core_get_property (GObject    *object,
                               guint       property_id,
                               GValue     *value,
                               GParamSpec *pspec)
{
  GimpSourceCore *source_core = GIMP_SOURCE_CORE (object);

  switch (property_id)
    {
    case PROP_SRC_DRAWABLE:
      g_value_set_object (value, source_core->src_drawable);
      break;
    case PROP_SRC_X:
      g_value_set_int (value, source_core->src_x);
      break;
    case PROP_SRC_Y:
      g_value_set_int (value, source_core->src_y);
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
      break;
    }
}

static gboolean
gimp_source_core_start (GimpPaintCore     *paint_core,
                        GimpDrawable      *drawable,
                        GimpPaintOptions  *paint_options,
                        const GimpCoords  *coords,
                        GError           **error)
{
  GimpSourceCore    *source_core = GIMP_SOURCE_CORE (paint_core);
  GimpSourceOptions *options     = GIMP_SOURCE_OPTIONS (paint_options);

  if (! GIMP_PAINT_CORE_CLASS (parent_class)->start (paint_core, drawable,
                                                     paint_options, coords,
                                                     error))
    {
      return FALSE;
    }

  paint_core->use_saved_proj = FALSE;

  if (! source_core->set_source && options->use_source)
    {
      if (! source_core->src_drawable)
        {
          g_set_error_literal (error, GIMP_ERROR, GIMP_FAILED,
			       _("Set a source image first."));
          return FALSE;
        }

      if (options->sample_merged &&
          gimp_item_get_image (GIMP_ITEM (source_core->src_drawable)) ==
          gimp_item_get_image (GIMP_ITEM (drawable)))
        {
          paint_core->use_saved_proj = TRUE;
        }
    }

  return TRUE;
}

static void
gimp_source_core_paint (GimpPaintCore    *paint_core,
                        GimpDrawable     *drawable,
                        GimpPaintOptions *paint_options,
                        const GimpCoords *coords,
                        GimpPaintState    paint_state,
                        guint32           time)
{
  GimpSourceCore    *source_core = GIMP_SOURCE_CORE (paint_core);
  GimpSourceOptions *options     = GIMP_SOURCE_OPTIONS (paint_options);

  switch (paint_state)
    {
    case GIMP_PAINT_STATE_INIT:
      if (source_core->set_source)
        {
          gimp_source_core_set_src_drawable (source_core, drawable);

          source_core->src_x = coords->x;
          source_core->src_y = coords->y;

          source_core->first_stroke = TRUE;
        }
      else if (options->align_mode == GIMP_SOURCE_ALIGN_NO)
        {
          source_core->orig_src_x = source_core->src_x;
          source_core->orig_src_y = source_core->src_y;

          source_core->first_stroke = TRUE;
        }
      break;

    case GIMP_PAINT_STATE_MOTION:
      if (source_core->set_source)
        {
          /*  If the control key is down, move the src target and return */

          source_core->src_x = coords->x;
          source_core->src_y = coords->y;

          source_core->first_stroke = TRUE;
        }
      else
        {
          /*  otherwise, update the target  */

          gint dest_x;
          gint dest_y;

          dest_x = coords->x;
          dest_y = coords->y;

          if (options->align_mode == GIMP_SOURCE_ALIGN_REGISTERED)
            {
              source_core->offset_x = 0;
              source_core->offset_y = 0;
            }
          else if (options->align_mode == GIMP_SOURCE_ALIGN_FIXED)
            {
              source_core->offset_x = source_core->src_x - dest_x;
              source_core->offset_y = source_core->src_y - dest_y;
            }
          else if (source_core->first_stroke)
            {
              source_core->offset_x = source_core->src_x - dest_x;
              source_core->offset_y = source_core->src_y - dest_y;

              source_core->first_stroke = FALSE;
            }

          source_core->src_x = dest_x + source_core->offset_x;
          source_core->src_y = dest_y + source_core->offset_y;

          gimp_source_core_motion (source_core, drawable, paint_options, coords);
        }
      break;

    case GIMP_PAINT_STATE_FINISH:
      if (options->align_mode == GIMP_SOURCE_ALIGN_NO &&
          ! source_core->first_stroke)
        {
          source_core->src_x = source_core->orig_src_x;
          source_core->src_y = source_core->orig_src_y;
        }
      break;

    default:
      break;
    }

  g_object_notify (G_OBJECT (source_core), "src-x");
  g_object_notify (G_OBJECT (source_core), "src-y");
}

void
gimp_source_core_motion (GimpSourceCore   *source_core,
                         GimpDrawable     *drawable,
                         GimpPaintOptions *paint_options,
                         const GimpCoords *coords)

{
  GimpPaintCore      *paint_core   = GIMP_PAINT_CORE (source_core);
  GimpSourceOptions  *options      = GIMP_SOURCE_OPTIONS (paint_options);
  GimpDynamics       *dynamics     = GIMP_BRUSH_CORE (paint_core)->dynamics;
  GimpDynamicsOutput *opacity_output;
  GimpImage          *image        = gimp_item_get_image (GIMP_ITEM (drawable));
  GimpPickable       *src_pickable = NULL;
  PixelRegion         srcPR;
  gint                src_offset_x;
  gint                src_offset_y;
  TempBuf            *paint_area;
  gint                paint_area_offset_x;
  gint                paint_area_offset_y;
  gint                paint_area_width;
  gint                paint_area_height;
  gdouble             fade_point;
  gdouble             opacity;

  opacity_output = gimp_dynamics_get_output (dynamics,
                                             GIMP_DYNAMICS_OUTPUT_OPACITY);

  fade_point = gimp_paint_options_get_fade (paint_options, image,
                                            paint_core->pixel_dist);

  opacity = gimp_dynamics_output_get_linear_value (opacity_output,
                                                   coords,
                                                   paint_options,
                                                   fade_point);
  if (opacity == 0.0)
    return;

  src_offset_x = source_core->offset_x;
  src_offset_y = source_core->offset_y;

  if (options->use_source)
    {
      src_pickable = GIMP_PICKABLE (source_core->src_drawable);

      if (options->sample_merged)
        {
          GimpImage *src_image = gimp_pickable_get_image (src_pickable);
          gint       off_x, off_y;

          src_pickable = GIMP_PICKABLE (gimp_image_get_projection (src_image));

          gimp_item_get_offset (GIMP_ITEM (source_core->src_drawable),
                                &off_x, &off_y);

          src_offset_x += off_x;
          src_offset_y += off_y;
        }

      gimp_pickable_flush (src_pickable);
    }

  paint_area = gimp_paint_core_get_paint_area (paint_core, drawable,
                                               paint_options, coords);
  if (! paint_area)
    return;

  paint_area_offset_x = 0;
  paint_area_offset_y = 0;
  paint_area_width    = paint_area->width;
  paint_area_height   = paint_area->height;

  if (options->use_source &&
      ! GIMP_SOURCE_CORE_GET_CLASS (source_core)->get_source (source_core,
                                                              drawable,
                                                              paint_options,
                                                              src_pickable,
                                                              src_offset_x,
                                                              src_offset_y,
                                                              paint_area,
                                                              &paint_area_offset_x,
                                                              &paint_area_offset_y,
                                                              &paint_area_width,
                                                              &paint_area_height,
                                                              &srcPR))
    {
      return;
    }

  /*  Set the paint area to transparent  */
  temp_buf_data_clear (paint_area);

  GIMP_SOURCE_CORE_GET_CLASS (source_core)->motion (source_core,
                                                    drawable,
                                                    paint_options,
                                                    coords,
                                                    opacity,
                                                    src_pickable,
                                                    &srcPR,
                                                    src_offset_x,
                                                    src_offset_y,
                                                    paint_area,
                                                    paint_area_offset_x,
                                                    paint_area_offset_y,
                                                    paint_area_width,
                                                    paint_area_height);
}

static gboolean
gimp_source_core_real_get_source (GimpSourceCore   *source_core,
                                  GimpDrawable     *drawable,
                                  GimpPaintOptions *paint_options,
                                  GimpPickable     *src_pickable,
                                  gint              src_offset_x,
                                  gint              src_offset_y,
                                  TempBuf          *paint_area,
                                  gint             *paint_area_offset_x,
                                  gint             *paint_area_offset_y,
                                  gint             *paint_area_width,
                                  gint             *paint_area_height,
                                  PixelRegion      *srcPR)
{
  GimpSourceOptions *options   = GIMP_SOURCE_OPTIONS (paint_options);
  GimpImage         *image     = gimp_item_get_image (GIMP_ITEM (drawable));
  GimpImage         *src_image = gimp_pickable_get_image (src_pickable);
  TileManager       *src_tiles = gimp_pickable_get_tiles (src_pickable);
  gint               x, y;
  gint               width, height;

  if (! gimp_rectangle_intersect (paint_area->x + src_offset_x,
                                  paint_area->y + src_offset_y,
                                  paint_area->width,
                                  paint_area->height,
                                  0, 0,
                                  tile_manager_width  (src_tiles),
                                  tile_manager_height (src_tiles),
                                  &x, &y,
                                  &width, &height))
    {
      return FALSE;
    }

  /*  If the source image is different from the destination,
   *  then we should copy straight from the source image
   *  to the canvas.
   *  Otherwise, we need a call to get_orig_image to make sure
   *  we get a copy of the unblemished (offset) image
   */
  if ((  options->sample_merged && (src_image                 != image)) ||
      (! options->sample_merged && (source_core->src_drawable != drawable)))
    {
      pixel_region_init (srcPR, src_tiles,
                         x, y, width, height,
                         FALSE);
    }
  else
    {
      TempBuf *orig;

      /*  get the original image  */
      if (options->sample_merged)
        orig = gimp_paint_core_get_orig_proj (GIMP_PAINT_CORE (source_core),
                                              src_pickable,
                                              x, y, width, height);
      else
        orig = gimp_paint_core_get_orig_image (GIMP_PAINT_CORE (source_core),
                                               GIMP_DRAWABLE (src_pickable),
                                               x, y, width, height);

      pixel_region_init_temp_buf (srcPR, orig,
                                  0, 0, width, height);
    }

  *paint_area_offset_x = x - (paint_area->x + src_offset_x);
  *paint_area_offset_y = y - (paint_area->y + src_offset_y);
  *paint_area_width    = width;
  *paint_area_height   = height;

  return TRUE;
}

static void
gimp_source_core_src_drawable_removed (GimpDrawable   *drawable,
                                       GimpSourceCore *source_core)
{
  if (drawable == source_core->src_drawable)
    {
      source_core->src_drawable = NULL;
    }

  g_signal_handlers_disconnect_by_func (drawable,
                                        gimp_source_core_src_drawable_removed,
                                        source_core);
}

static void
gimp_source_core_set_src_drawable (GimpSourceCore *source_core,
                                   GimpDrawable   *drawable)
{
  if (source_core->src_drawable == drawable)
    return;

  if (source_core->src_drawable)
    g_signal_handlers_disconnect_by_func (source_core->src_drawable,
                                          gimp_source_core_src_drawable_removed,
                                          source_core);

  source_core->src_drawable = drawable;

  if (source_core->src_drawable)
    g_signal_connect (source_core->src_drawable, "removed",
                      G_CALLBACK (gimp_source_core_src_drawable_removed),
                      source_core);

  g_object_notify (G_OBJECT (source_core), "src-drawable");
}
