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

#ifndef __GIMP_IMAGE_SAMPLE_POINTS_H__
#define __GIMP_IMAGE_SAMPLE_POINTS_H__


/*  public sample point adding API
 */
GimpSamplePoint * gimp_image_add_sample_point_at_pos (GimpImage        *image,
                                                      gint              x,
                                                      gint              y,
                                                      gboolean          push_undo);

/*  internal sample point adding API, does not check the sample
 *  point's position and is publically declared only to be used from
 *  undo
 */
void              gimp_image_add_sample_point        (GimpImage       *image,
                                                      GimpSamplePoint *sample_point,
                                                      gint             x,
                                                      gint             y);

void              gimp_image_remove_sample_point     (GimpImage       *image,
                                                      GimpSamplePoint *sample_point,
                                                      gboolean         push_undo);
void              gimp_image_move_sample_point       (GimpImage       *image,
                                                      GimpSamplePoint *sample_point,
                                                      gint             x,
                                                      gint             y,
                                                      gboolean         push_undo);

GList           * gimp_image_get_sample_points       (GimpImage       *image);
GimpSamplePoint * gimp_image_find_sample_point       (GimpImage       *image,
                                                      gdouble          x,
                                                      gdouble          y,
                                                      gdouble          epsilon_x,
                                                      gdouble          epsilon_y);


#endif /* __GIMP_IMAGE_SAMPLE_POINTS_H__ */
