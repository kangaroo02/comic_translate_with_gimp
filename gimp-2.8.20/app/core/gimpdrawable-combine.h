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

#ifndef __GIMP_DRAWABLE_COMBINE_H__
#define __GIMP_DRAWABLE_COMBINE_H__


/*  virtual functions of GimpDrawable, don't call directly  */

void   gimp_drawable_real_apply_region   (GimpDrawable         *drawable,
                                          PixelRegion          *src2PR,
                                          gboolean              push_undo,
                                          const gchar          *undo_desc,
                                          gdouble               opacity,
                                          GimpLayerModeEffects  mode,
                                          TileManager          *src1_tiles,
                                          PixelRegion          *destPR,
                                          gint                  x,
                                          gint                  y);
void   gimp_drawable_real_replace_region (GimpDrawable         *drawable,
                                          PixelRegion          *src2PR,
                                          gboolean              push_undo,
                                          const gchar          *undo_desc,
                                          gdouble               opacity,
                                          PixelRegion          *maskPR,
                                          gint                  x,
                                          gint                  y);


#endif /* __GIMP_DRAWABLE_COMBINE_H__ */
