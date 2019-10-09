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

#ifndef __TILE_PYRAMID_H__
#define __TILE_PYRAMID_H__


/* Creates a new tile pyramid with the specified size for the
 *  toplevel. The toplevel size is used to compute the number of
 *  levels and their size. Each level is 1/2 the width and height of
 *  the level above it.
 *
 * The toplevel is level 0. The smallest level in the hierarchy
 *  is "nlevels - 1". That level will be smaller than TILE_WIDTH x
 *  TILE_HEIGHT
 */
TilePyramid * tile_pyramid_new               (GimpImageType      type,
                                              gint               width,
                                              gint               height);
void          tile_pyramid_destroy           (TilePyramid       *pyramid);

gint          tile_pyramid_get_level         (gint               width,
                                              gint               height,
                                              gdouble            scale);

TileManager * tile_pyramid_get_tiles         (TilePyramid       *pyramid,
                                              gint               level,
                                              gboolean          *is_premult);

void          tile_pyramid_invalidate_area   (TilePyramid       *pyramid,
                                              gint               x,
                                              gint               y,
                                              gint               width,
                                              gint               height);

void          tile_pyramid_set_validate_proc (TilePyramid       *pyramid,
                                              TileValidateProc   proc,
                                              gpointer           user_data);

gint          tile_pyramid_get_width         (const TilePyramid *pyramid);
gint          tile_pyramid_get_height        (const TilePyramid *pyramid);
gint          tile_pyramid_get_bpp           (const TilePyramid *pyramid);

gint64        tile_pyramid_get_memsize       (const TilePyramid *pyramid);


#endif /* __TILE_PYRAMID_H__ */
