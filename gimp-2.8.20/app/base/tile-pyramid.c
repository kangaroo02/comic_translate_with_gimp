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

#include <glib-object.h>

#include "base-types.h"

#include "tile.h"
#include "tile-manager.h"
#include "tile-pyramid.h"


#define PYRAMID_MAX_LEVELS  10


struct _TilePyramid
{
  GimpImageType  type;
  guint          width;
  guint          height;
  gint           bytes;
  TileManager   *tiles[PYRAMID_MAX_LEVELS];
  gint           top_level;
};


static gint  tile_pyramid_alloc_levels        (TilePyramid *pyramid,
                                               gint         top_level);
static void  tile_pyramid_validate_tile       (TileManager *tm,
                                               Tile        *tile,
                                               TileManager *tm_below);
static void  tile_pyramid_validate_upper_tile (TileManager *tm,
                                               Tile        *tile,
                                               TileManager *tm_below);

static void  tile_pyramid_write_quarter       (Tile        *dest,
                                               Tile        *src,
                                               const gint   i,
                                               const gint   j);
static void  tile_pyramid_write_upper_quarter (Tile        *dest,
                                               Tile        *src,
                                               const gint   i,
                                               const gint   j);

/**
 * tile_pyramid_new:
 * @type:   type of pixel data stored in the pyramid
 * @width:  bottom level width
 * @height: bottom level height
 *
 * Creates a new #TilePyramid, managing a set of tile-managers where
 * each level is a sized-down version of the level below.
 *
 * This only works correctly if you set a validate procedure using
 * tile_pyramid_set_validate_proc() and invalidate areas. With some
 * small changes, it could be made to work for non-validating tile
 * managers also. But currently only the projection uses it.
 *
 * Only the bottom-most tile-manager is allocated at this point. Upper
 * levels are created only if they are requested.
 *
 * Return value: a newly allocate #TilePyramid
 **/
TilePyramid *
tile_pyramid_new (GimpImageType  type,
                  gint           width,
                  gint           height)
{
  TilePyramid *pyramid;

  g_return_val_if_fail (width > 0, NULL);
  g_return_val_if_fail (height > 0, NULL);

  pyramid = g_slice_new0 (TilePyramid);

  pyramid->type   = type;
  pyramid->width  = width;
  pyramid->height = height;

  switch (type)
    {
    case GIMP_GRAY_IMAGE:
      pyramid->bytes = 1;
      break;

    case GIMP_GRAYA_IMAGE:
      pyramid->bytes = 2;
      break;

    case GIMP_RGB_IMAGE:
      pyramid->bytes = 3;
      break;

    case GIMP_RGBA_IMAGE:
      pyramid->bytes = 4;
      break;

    case GIMP_INDEXED_IMAGE:
    case GIMP_INDEXEDA_IMAGE:
      g_assert_not_reached ();
      break;
    }

  pyramid->tiles[0] = tile_manager_new (width, height, pyramid->bytes);

  return pyramid;
}

/**
 * tile_pyramid_destroy:
 * @pyramid: a #TilePyramid
 *
 * Destroys resources allocated for @pyramid and unrefs all contained
 * tile-managers.
 **/
void
tile_pyramid_destroy (TilePyramid *pyramid)
{
  gint level;

  g_return_if_fail (pyramid != NULL);

  for (level = 0; level <= pyramid->top_level; level++)
    tile_manager_unref (pyramid->tiles[level]);

  g_slice_free (TilePyramid, pyramid);
}

/**
 * tile_pyramid_get_level:
 * @width:  width of the bottom level
 * @height: height of the bottom level
 * @scale:  zoom ratio
 *
 * Calculates the optimal level to request from a #TilePyramid in order
 * to display at a certain @scale.
 *
 * Return value: the level to use for @scale
 **/
gint
tile_pyramid_get_level (gint     width,
                        gint     height,
                        gdouble  scale)
{
  gdouble next = 1.0;
  guint   w    = (guint) width;
  guint   h    = (guint) height;
  gint    level;

  for (level = 0; level < PYRAMID_MAX_LEVELS; level++)
    {
      w >>= 1;
      h >>= 1;

      if (w == 0 || h == 0)
        break;

      if (w <= TILE_WIDTH && h <= TILE_HEIGHT)
        break;

      next /= 2;

      if (next < scale)
        break;
    }

  return level;
}

/**
 * tile_pyramid_get_tiles:
 * @pyramid:    a #TilePyramid
 * @level:      level, typically obtained using tile_pyramid_get_level()
 * @is_premult: location to store whether the pixel data has the alpha
 *              channel pre-multiplied or not
 *
 * Gives access to the #TileManager at @level of the @pyramid.
 *
 * Return value: pointer to a #TileManager
 **/
TileManager *
tile_pyramid_get_tiles (TilePyramid *pyramid,
                        gint         level,
                        gboolean    *is_premult)
{
  g_return_val_if_fail (pyramid != NULL, NULL);

  level = tile_pyramid_alloc_levels (pyramid, level);

  g_return_val_if_fail (pyramid->tiles[level] != NULL, NULL);

  if (is_premult)
    *is_premult = (level > 0);

  return pyramid->tiles[level];
}

/**
 * tile_pyramid_invalidate_area:
 * @pyramid: a #TilePyramid
 * @x:
 * @y:
 * @width:
 * @height:
 *
 * Invalidates the tiles in the given area on all levels.
 **/
void
tile_pyramid_invalidate_area (TilePyramid *pyramid,
                              gint         x,
                              gint         y,
                              gint         width,
                              gint         height)
{
  gint level;

  g_return_if_fail (pyramid != NULL);
  g_return_if_fail (x >= 0 && y >= 0);
  g_return_if_fail (width >= 0 && height >= 0);

  if (width == 0 || height == 0)
    return;

  for (level = 0; level <= pyramid->top_level; level++)
    {
      /* Tile invalidation must propagate all the way up in the pyramid,
       * so keep width and height > 0.
       */
      tile_manager_invalidate_area (pyramid->tiles[level],
                                    x, y, MAX (width, 1), MAX (height, 1));

      x      >>= 1;
      y      >>= 1;
      width  >>= 1;
      height >>= 1;
    }
}

/**
 * tile_pyramid_set_validate_proc:
 * @pyramid:   a #TilePyramid
 * @proc:      a function to validate the bottom level tiles
 * @user_data: data to pass to the validation @proc
 *
 * Sets a validation procedure on the bottom-most tile manager.
 **/
void
tile_pyramid_set_validate_proc (TilePyramid      *pyramid,
                                TileValidateProc  proc,
                                gpointer          user_data)
{
  g_return_if_fail (pyramid != NULL);

  tile_manager_set_validate_proc (pyramid->tiles[0], proc, user_data);
}

/**
 * tile_pyramid_get_width:
 * @pyramid: a #TilePyramid
 *
 * Return value: the width of the pyramid's bottom level
 **/
gint
tile_pyramid_get_width (const TilePyramid *pyramid)
{
  g_return_val_if_fail (pyramid != NULL, 0);

  return pyramid->width;
}

/**
 * tile_pyramid_get_height:
 * @pyramid: a #TilePyramid
 *
 * Return value: the height of the pyramid's bottom level
 **/
gint
tile_pyramid_get_height (const TilePyramid *pyramid)
{
  g_return_val_if_fail (pyramid != NULL, 0);

  return pyramid->height;
}

/**
 * tile_pyramid_get_bpp:
 * @pyramid: a #TilePyramid
 *
 * Return value: the number of bytes per pixel stored in the @pyramid
 **/
gint
tile_pyramid_get_bpp (const TilePyramid *pyramid)
{
  g_return_val_if_fail (pyramid != NULL, 0);

  return pyramid->bytes;
}

/**
 * tile_pyramid_get_memsize:
 * @pyramid: a #TilePyramid
 *
 * Return value: size of memory allocated for the @pyramid
 **/
gint64
tile_pyramid_get_memsize (const TilePyramid *pyramid)
{
  gint64 memsize = sizeof (TilePyramid);
  gint   level;

  g_return_val_if_fail (pyramid != NULL, 0);

  for (level = 0; level <= pyramid->top_level; level++)
    memsize += tile_manager_get_memsize (pyramid->tiles[level], TRUE);

  return memsize;
}


/* This function make sure that levels are allocated up to the level
 * it returns. The return value may be smaller than the level that
 * was actually requested.
 */
static gint
tile_pyramid_alloc_levels (TilePyramid *pyramid,
                           gint         top_level)
{
  gint level;

  top_level = MIN (top_level, PYRAMID_MAX_LEVELS - 1);

  if (top_level <= pyramid->top_level)
    return top_level;

  for (level = pyramid->top_level + 1; level <= top_level; level++)
    {
      TileValidateProc  proc;
      gint              width  = pyramid->width  >> level;
      gint              height = pyramid->height >> level;

      if (width == 0 || height == 0)
        return pyramid->top_level;

      /* There is no use having levels that have the same number of
       * tiles as the parent level.
       */
      if (width <= TILE_WIDTH / 2 && height <= TILE_HEIGHT / 2)
        return pyramid->top_level;

      pyramid->top_level    = level;
      pyramid->tiles[level] = tile_manager_new (width, height, pyramid->bytes);

      /* Use the level below to validate tiles. */
      if (level == 1)
        proc = (TileValidateProc) tile_pyramid_validate_tile;
      else
        proc = (TileValidateProc) tile_pyramid_validate_upper_tile;

      tile_manager_set_validate_proc (pyramid->tiles[level],
                                      proc,
                                      pyramid->tiles[level - 1]);
    }

  return pyramid->top_level;
}

/* This method is used to validate a pyramid tile from four tiles on
 * the base level.  It needs to pre-multiply the alpha channel because
 * upper levels are pre-multiplied.
 */
static void
tile_pyramid_validate_tile (TileManager *tm,
                            Tile        *tile,
                            TileManager *tm_below)
{
  gint  tile_col;
  gint  tile_row;
  gint  i, j;

  tile_manager_get_tile_col_row (tm, tile, &tile_col, &tile_row);

  for (i = 0; i < 2; i++)
    for (j = 0; j < 2; j++)
      {
        Tile *source = tile_manager_get_at (tm_below,
                                            tile_col * 2 + i,
                                            tile_row * 2 + j,
                                            TRUE, FALSE);
        if (source)
          {
            tile_pyramid_write_quarter (tile, source, i, j);
            tile_release (source, FALSE);
          }
      }
}

/* This method is used to validate tiles in the upper pyramid levels.
 * Here all data has the alpha channel pre-multiplied.
 */
static void
tile_pyramid_validate_upper_tile (TileManager *tm,
                                  Tile        *tile,
                                  TileManager *tm_below)
{
  gint  tile_col;
  gint  tile_row;
  gint  i, j;

  tile_manager_get_tile_col_row (tm, tile, &tile_col, &tile_row);

  for (i = 0; i < 2; i++)
    for (j = 0; j < 2; j++)
      {
        Tile *source = tile_manager_get_at (tm_below,
                                            tile_col * 2 + i,
                                            tile_row * 2 + j,
                                            TRUE, FALSE);
        if (source)
          {
            tile_pyramid_write_upper_quarter (tile, source, i, j);
            tile_release (source, FALSE);
          }
      }
}

/* Average the src tile to one quarter of the destination tile.  The
 * source tile doesn't have pre-multiplied alpha, but the destination
 * tile does.
 */
static void
tile_pyramid_write_quarter (Tile       *dest,
                            Tile       *src,
                            const gint  i,
                            const gint  j)
{
  const guchar *src_data    = tile_data_pointer (src, 0, 0);
  guchar       *dest_data   = tile_data_pointer (dest,
                                                 i * TILE_WIDTH / 2,
                                                 j * TILE_WIDTH / 2);
  const gint    src_ewidth  = tile_ewidth  (src);
  const gint    src_eheight = tile_eheight (src);
  const gint    dest_ewidth = tile_ewidth  (dest);
  const gint    bpp         = tile_bpp     (dest);
  gint          y;

  for (y = 0; y < src_eheight / 2; y++)
    {
      const guchar *src0 = src_data;
      const guchar *src1 = src_data + bpp;
      const guchar *src2 = src0 + bpp * src_ewidth;
      const guchar *src3 = src1 + bpp * src_ewidth;
      guchar       *dst  = dest_data;
      gint          x;

      switch (bpp)
        {
        case 1:
          for (x = 0; x < src_ewidth / 2; x++)
            {
              dst[0] = (src0[0] + src1[0] + src2[0] + src3[0] + 2) >> 2;

              dst += 1;

              src0 += 2;
              src1 += 2;
              src2 += 2;
              src3 += 2;
            }
          break;

        case 2:
          for (x = 0; x < src_ewidth / 2; x++)
            {
              const guint a = src0[1] + src1[1] + src2[1] + src3[1];

              switch (a)
                {
                case 0:    /* all transparent */
                  dst[0] = dst[1] = 0;
                  break;

                case 1020: /* all opaque */
                  dst[0] = (src0[0]  + src1[0] + src2[0] + src3[0] + 2) >> 2;
                  dst[1] = 255;
                  break;

                default:
                  dst[0] = ((src0[0] * (src0[1] + 1) +
                             src1[0] * (src1[1] + 1) +
                             src2[0] * (src2[1] + 1) +
                             src3[0] * (src3[1] + 1)) >> 10);
                  dst[1] = (a + 2) >> 2;
                  break;
                }

              dst += 2;

              src0 += 4;
              src1 += 4;
              src2 += 4;
              src3 += 4;
            }
          break;

        case 3:
          for (x = 0; x < src_ewidth / 2; x++)
            {
              dst[0] = (src0[0] + src1[0] + src2[0] + src3[0] + 2) >> 2;
              dst[1] = (src0[1] + src1[1] + src2[1] + src3[1] + 2) >> 2;
              dst[2] = (src0[2] + src1[2] + src2[2] + src3[2] + 2) >> 2;

              dst += 3;

              src0 += 6;
              src1 += 6;
              src2 += 6;
              src3 += 6;
            }
          break;

        case 4:
          for (x = 0; x < src_ewidth / 2; x++)
            {
              const guint a = src0[3] + src1[3] + src2[3] + src3[3];

              switch (a)
                {
                case 0:    /* all transparent */
                  dst[0] = dst[1] = dst[2] = dst[3] = 0;
                  break;

                case 1020: /* all opaque */
                  dst[0] = (src0[0] + src1[0] + src2[0] + src3[0] + 2) >> 2;
                  dst[1] = (src0[1] + src1[1] + src2[1] + src3[1] + 2) >> 2;
                  dst[2] = (src0[2] + src1[2] + src2[2] + src3[2] + 2) >> 2;
                  dst[3] = 255;
                  break;

                default:
                  {
                    const guint a0 = src0[3] + 1;
                    const guint a1 = src1[3] + 1;
                    const guint a2 = src2[3] + 1;
                    const guint a3 = src3[3] + 1;

                    dst[0] = (src0[0] * a0 +
                              src1[0] * a1 +
                              src2[0] * a2 +
                              src3[0] * a3) >> 10;
                    dst[1] = (src0[1] * a0 +
                              src1[1] * a1 +
                              src2[1] * a2 +
                              src3[1] * a3) >> 10;
                    dst[2] = (src0[2] * a0 +
                              src1[2] * a1 +
                              src2[2] * a2 +
                              src3[2] * a3) >> 10;
                    dst[3] = (a + 2) >> 2;
                  }
                  break;
                }

              dst += 4;

              src0 += 8;
              src1 += 8;
              src2 += 8;
              src3 += 8;
            }
          break;
        }

      dest_data += dest_ewidth * bpp;
      src_data += src_ewidth * bpp * 2;
    }
}

/* Average the src tile to one quarter of the destination tile.
 * The source and destination tiles have pre-multiplied alpha.
 */
static void
tile_pyramid_write_upper_quarter (Tile       *dest,
                                  Tile       *src,
                                  const gint  i,
                                  const gint  j)
{
  const guchar *src_data    = tile_data_pointer (src, 0, 0);
  guchar       *dest_data   = tile_data_pointer (dest,
                                                 i * TILE_WIDTH / 2,
                                                 j * TILE_WIDTH / 2);
  const gint    src_ewidth  = tile_ewidth  (src);
  const gint    src_eheight = tile_eheight (src);
  const gint    dest_ewidth = tile_ewidth  (dest);
  const gint    bpp         = tile_bpp     (dest);
  gint          y;

  for (y = 0; y < src_eheight / 2; y++)
    {
      const guchar *src0 = src_data;
      const guchar *src1 = src_data + bpp;
      const guchar *src2 = src0 + bpp * src_ewidth;
      const guchar *src3 = src1 + bpp * src_ewidth;
      guchar       *dst  = dest_data;
      gint          x;

      switch (bpp)
        {
        case 1:
          for (x = 0; x < src_ewidth / 2; x++)
            {
              dst[0] = (src0[0] + src1[0] + src2[0] + src3[0] + 2) >> 2;

              dst += 1;

              src0 += 2;
              src1 += 2;
              src2 += 2;
              src3 += 2;
            }
          break;

        case 2:
          for (x = 0; x < src_ewidth / 2; x++)
            {
              dst[0] = (src0[0] + src1[0] + src2[0] + src3[0] + 2) >> 2;
              dst[1] = (src0[1] + src1[1] + src2[1] + src3[1] + 2) >> 2;

              dst += 2;

              src0 += 4;
              src1 += 4;
              src2 += 4;
              src3 += 4;
            }
          break;

        case 3:
          for (x = 0; x < src_ewidth / 2; x++)
            {
              dst[0] = (src0[0] + src1[0] + src2[0] + src3[0] + 2) >> 2;
              dst[1] = (src0[1] + src1[1] + src2[1] + src3[1] + 2) >> 2;
              dst[2] = (src0[2] + src1[2] + src2[2] + src3[2] + 2) >> 2;

              dst += 3;

              src0 += 6;
              src1 += 6;
              src2 += 6;
              src3 += 6;
            }
          break;

        case 4:
          for (x = 0; x < src_ewidth / 2; x++)
            {
              dst[0] = (src0[0] + src1[0] + src2[0] + src3[0] + 2) >> 2;
              dst[1] = (src0[1] + src1[1] + src2[1] + src3[1] + 2) >> 2;
              dst[2] = (src0[2] + src1[2] + src2[2] + src3[2] + 2) >> 2;
              dst[3] = (src0[3] + src1[3] + src2[3] + src3[3] + 2) >> 2;

              dst += 4;

              src0 += 8;
              src1 += 8;
              src2 += 8;
              src3 += 8;
            }
          break;
        }

      dest_data += dest_ewidth * bpp;
      src_data += src_ewidth * bpp * 2;
    }
}
