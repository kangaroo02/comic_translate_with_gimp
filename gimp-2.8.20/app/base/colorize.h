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

#ifndef __COLORIZE_H__
#define __COLORIZE_H__


struct _Colorize
{
  gdouble hue;
  gdouble saturation;
  gdouble lightness;

  gint    lum_red_lookup[256];
  gint    lum_green_lookup[256];
  gint    lum_blue_lookup[256];

  gint    final_red_lookup[256];
  gint    final_green_lookup[256];
  gint    final_blue_lookup[256];
};


void   colorize_init      (Colorize      *colorize);
void   colorize_calculate (Colorize      *colorize);
void   colorize           (Colorize      *colorize,
                           PixelRegion   *srcPR,
                           PixelRegion   *destPR);


#endif  /*  __COLORIZE_H__  */
