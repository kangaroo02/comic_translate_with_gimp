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

#ifndef __GIMP_IMAGE_CONVERT_H__
#define __GIMP_IMAGE_CONVERT_H__


#define MAXNUMCOLORS 256


gboolean   gimp_image_convert      (GimpImage               *image,
                                    GimpImageBaseType        new_type,
                                    /* The following params used only for
                                     * new_type == GIMP_INDEXED
                                     */
                                    gint                     num_cols,
                                    GimpConvertDitherType    dither,
                                    gboolean                 alpha_dither,
                                    gboolean                 remove_dups,
                                    GimpConvertPaletteType   palette_type,
                                    GimpPalette             *custom_palette,
                                    GimpProgress            *progress,
                                    GError                 **error);

void  gimp_image_convert_set_dither_matrix (const guchar *matrix,
                                            gint          width,
                                            gint          height);


#endif  /*  __GIMP_IMAGE_CONVERT_H__  */
