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

#ifndef __GIMP_HELPER_TOOL_H__
#define __GIMP_HELPER_TOOL_H__


#include "gimpdrawtool.h"


#define GIMP_TYPE_HELPER_TOOL            (gimp_helper_tool_get_type ())
#define GIMP_HELPER_TOOL(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GIMP_TYPE_HELPER_TOOL, GimpHelperTool))
#define GIMP_IS_HELPER_TOOL(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GIMP_TYPE_HELPER_TOOL))
#define GIMP_HELPER_TOOL_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), GIMP_TYPE_HELPER_TOOL, GimpHelperToolClass))
#define GIMP_IS_HELPER_TOOL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GIMP_TYPE_HELPER_TOOL))

#define GIMP_HELPER_TOOL_GET_OPTIONS(t)  (GIMP_HELPER_OPTIONS (gimp_tool_get_options (GIMP_TOOL (t))))


typedef struct _GimpHelperTool       GimpHelperTool;
typedef struct _GimpHelperToolClass  GimpHelperToolClass;

struct _GimpHelperTool
{
  GimpDrawTool    parent_instance;

  GimpText       *proxy;
  GList          *pending;
  guint           idle_id;

  gboolean        moving;
  gboolean		  helper_on;//changes_isaiah

  GimpTextBuffer *buffer;

  GimpText       *text;
  GimpTextLayer  *layer;
  GimpImage      *image;

  GtkWidget      *confirm_dialog;
  GimpUIManager  *ui_manager;

  gboolean        handle_rectangle_change_complete;
  gboolean        text_box_fixed;

  GimpTextLayout *layout;
  gboolean        drawing_blocked;

  /* text editor state: */

  GtkWidget      *style_overlay;
  GtkWidget      *style_editor;

  gboolean        selecting;
  GtkTextIter     select_start_iter;
  gboolean        select_words;
  gboolean        select_lines;

  GtkIMContext   *im_context;
  gboolean        needs_im_reset;

  GtkWidget      *preedit_overlay;
  GtkWidget      *preedit_label;

  gchar          *preedit_string;
  gint            preedit_cursor;

  gboolean        overwrite_mode;
  gint            x_pos;

  GtkWidget      *offscreen_window;
  GtkWidget      *proxy_text_view;

  GtkWidget      *editor_dialog;
};

struct _GimpHelperToolClass
{
  GimpDrawToolClass  parent_class;
};


void       gimp_helper_tool_register               (GimpToolRegisterCallback  callback,
                                                  gpointer                  data);

GType      gimp_helper_tool_get_type               (void) G_GNUC_CONST;

void       gimp_helper_tool_set_layer              (GimpHelperTool *text_tool,
                                                  GimpLayer    *layer);

gboolean   gimp_helper_tool_get_has_text_selection (GimpHelperTool *text_tool);

void       gimp_helper_tool_delete_selection       (GimpHelperTool *text_tool);
void       gimp_helper_tool_cut_clipboard          (GimpHelperTool *text_tool);
void       gimp_helper_tool_copy_clipboard         (GimpHelperTool *text_tool);
void       gimp_helper_tool_paste_clipboard        (GimpHelperTool *text_tool);

void       gimp_helper_tool_create_vectors         (GimpHelperTool *text_tool);
void       gimp_helper_tool_create_vectors_warped  (GimpHelperTool *text_tool);

/*  only for the text editor  */
void       gimp_helper_tool_clear_layout           (GimpHelperTool *text_tool);
gboolean   gimp_helper_tool_ensure_layout          (GimpHelperTool *text_tool);

/*  only for the helper  */


#endif /* __GIMP_HELPER_TOOL_H__ */
