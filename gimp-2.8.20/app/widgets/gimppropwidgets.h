/* GIMP - The GNU Image Manipulation Program
 * Copyright (C) 1995-1997 Spencer Kimball and Peter Mattis
 *
 * gimppropwidgets.h
 * Copyright (C) 2002 Michael Natterer <mitch@gimp.org>
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

#ifndef __GIMP_APP_PROP_WIDGETS_H__
#define __GIMP_APP_PROP_WIDGETS_H__


/*  GParamBoolean  */

GtkWidget * gimp_prop_expanding_frame_new (GObject     *config,
                                           const gchar *property_name,
                                           const gchar *button_label,
                                           GtkWidget   *child,
                                           GtkWidget  **button);


/*  GParamEnum  */

GtkWidget * gimp_prop_paint_mode_menu_new (GObject     *config,
                                           const gchar *property_name,
                                           gboolean     with_behind_mode,
                                           gboolean     with_replace_modes);


/*  GimpParamColor  */

GtkWidget * gimp_prop_color_button_new    (GObject     *config,
                                           const gchar *property_name,
                                           const gchar *title,
                                           gint         width,
                                           gint         height,
                                           GimpColorAreaType  type);


/*  GParamDouble  */

GtkWidget * gimp_prop_scale_button_new    (GObject     *config,
                                           const gchar *property_name);
GtkWidget * gimp_prop_spin_scale_new      (GObject     *config,
                                           const gchar *property_name,
                                           const gchar *label,
                                           gdouble      step_increment,
                                           gdouble      page_increment,
                                           gint         digits);
GtkWidget * gimp_prop_opacity_spin_scale_new (GObject     *config,
                                              const gchar *property_name,
                                              const gchar *label);


/*  GParamObject (GimpViewable)  */

GtkWidget * gimp_prop_view_new            (GObject     *config,
                                           const gchar *property_name,
                                           GimpContext *context,
                                           gint         size);


/*  GParamDouble, GParamDouble, GParamDouble, GParamDouble, GParamBoolean  */

GtkWidget * gimp_prop_number_pair_entry_new
                                          (GObject     *config,
                                           const gchar *left_number_property,
                                           const gchar *right_number_property,
                                           const gchar *default_left_number_property,
                                           const gchar *default_right_number_property,
                                           const gchar *user_override_property,
                                           gboolean     connect_numbers_changed,
                                           gboolean     connect_ratio_changed,
                                           const gchar *separators,
                                           gboolean     allow_simplification,
                                           gdouble      min_valid_value,
                                           gdouble      max_valid_value);

/*  GParamString  */

GtkWidget * gimp_prop_language_combo_box_new (GObject     *config,
                                              const gchar *property_name);
GtkWidget * gimp_prop_language_entry_new     (GObject     *config,
                                              const gchar *property_name);

GtkWidget * gimp_prop_icon_picker_new        (GObject     *config,
                                              const gchar *property_name,
                                              Gimp        *gimp);

/*  A view on all of an object's properties  */

GtkWidget * gimp_prop_table_new           (GObject     *config,
                                           GType        owner_type,
                                           GimpContext *context);


#endif /* __GIMP_APP_PROP_WIDGETS_H__ */
