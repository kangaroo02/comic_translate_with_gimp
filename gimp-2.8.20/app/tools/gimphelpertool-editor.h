/* GIMP - The GNU Image Manipulation Program
 * Copyright (C) 1995 Spencer Kimball and Peter Mattis
 *
 * GimpHelperTool
 * Copyright (C) 2002-2010  Sven Neumann <sven@gimp.org>
 *                          Daniel Eddeland <danedde@svn.gnome.org>
 *                          Michael Natterer <mitch@gimp.org>
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

#ifndef __GIMP_HELPER_TOOL_EDITOR_H__
#define __GIMP_HELPER_TOOL_EDITOR_H__


void       gimp_helper_tool_editor_init            (GimpHelperTool        *text_tool);
void       gimp_helper_tool_editor_finalize        (GimpHelperTool        *text_tool);

void       gimp_helper_tool_editor_start           (GimpHelperTool        *text_tool);
void       gimp_helper_tool_editor_position        (GimpHelperTool        *text_tool);
void       gimp_helper_tool_editor_halt            (GimpHelperTool        *text_tool);

void       gimp_helper_tool_editor_button_press    (GimpHelperTool        *text_tool,
                                                  gdouble              x,
                                                  gdouble              y,
                                                  GimpButtonPressType  press_type);
void       gimp_helper_tool_editor_button_release  (GimpHelperTool        *text_tool);
void       gimp_helper_tool_editor_motion          (GimpHelperTool        *text_tool,
                                                  gdouble              x,
                                                  gdouble              y);
gboolean   gimp_helper_tool_editor_key_press       (GimpHelperTool        *text_tool,
                                                  GdkEventKey         *kevent);
gboolean   gimp_helper_tool_editor_key_release     (GimpHelperTool        *text_tool,
                                                  GdkEventKey         *kevent);

void       gimp_helper_tool_reset_im_context       (GimpHelperTool        *text_tool);

void       gimp_helper_tool_editor_get_cursor_rect (GimpHelperTool        *text_tool,
                                                  gboolean             overwrite,
                                                  PangoRectangle      *cursor_rect);
void       gimp_helper_tool_editor_update_im_rect  (GimpHelperTool        *text_tool);


#endif /* __GIMP_HELPER_TOOL_EDITOR_H__ */
