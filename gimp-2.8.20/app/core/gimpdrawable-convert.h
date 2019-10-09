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

#ifndef __GIMP_DRAWABLE_CONVERT_H__
#define __GIMP_DRAWABLE_CONVERT_H__


void   gimp_drawable_convert_rgb             (GimpDrawable *drawable,
                                              gboolean      push_undo);
void   gimp_drawable_convert_grayscale       (GimpDrawable *drawable,
                                              gboolean      push_undo);

void   gimp_drawable_convert_tiles_rgb       (GimpDrawable *drawable,
                                              TileManager  *new_tiles);
void   gimp_drawable_convert_tiles_grayscale (GimpDrawable *drawable,
                                              TileManager  *new_tiles);


#endif  /*  __GIMP_DRAWABLE_CONVERT_H__  */
