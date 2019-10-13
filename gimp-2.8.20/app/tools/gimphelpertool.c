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
/* changes_isaiah */
#include <limits.h> /* PATH_MAX */
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "display/gimpdisplayshell-dnd.c"

/* end */
#include "config.h"

#include <gegl.h>
#include <gtk/gtk.h>

#include "libgimpbase/gimpbase.h"
#include "libgimpconfig/gimpconfig.h"
#include "libgimpwidgets/gimpwidgets.h"

#include "tools-types.h"

#include "core/gimp.h"
#include "core/gimpcontext.h"
#include "core/gimpimage.h"
#include "core/gimpimage-pick-layer.h"
#include "core/gimpimage-undo.h"
#include "core/gimpimage-undo-push.h"
#include "core/gimplayer-floating-sel.h"
#include "core/gimpmarshal.h"
#include "core/gimptoolinfo.h"
#include "core/gimpundostack.h"

#include "text/gimptext.h"
#include "text/gimptext-vectors.h"
#include "text/gimptextlayer.h"
#include "text/gimptextlayout.h"
#include "text/gimptextundo.h"

#include "vectors/gimpvectors-warp.h"

#include "widgets/gimpdialogfactory.h"
#include "widgets/gimphelp-ids.h"
#include "widgets/gimpmenufactory.h"
#include "widgets/gimptextbuffer.h"
#include "widgets/gimpuimanager.h"
#include "widgets/gimpviewabledialog.h"

#include "display/gimpcanvasgroup.h"
#include "display/gimpdisplay.h"
#include "display/gimpdisplayshell.h"

#include "gimprectangletool.h"
#include "gimphelperoptions.h"
#include "gimphelpertool.h"
#include "gimphelpertool-editor.h"
#include "gimptoolcontrol.h"

#include "gimp-intl.h"

#define TEXT_UNDO_TIMEOUT 3

/*  local function prototypes  */
gchar* read_file(char* name);

static void gimp_helper_tool_rectangle_tool_iface_init(
		GimpRectangleToolInterface *iface);

static void gimp_helper_tool_constructed(GObject *object);
static void gimp_helper_tool_finalize(GObject *object);

static void gimp_helper_tool_control(GimpTool *tool, GimpToolAction action,
		GimpDisplay *display);
static void gimp_helper_tool_button_press(GimpTool *tool,
		const GimpCoords *coords, guint32 time, GdkModifierType state,
		GimpButtonPressType press_type, GimpDisplay *display);
static void gimp_helper_tool_button_release(GimpTool *tool,
		const GimpCoords *coords, guint32 time, GdkModifierType state,
		GimpButtonReleaseType release_type, GimpDisplay *display);
static void gimp_helper_tool_motion(GimpTool *tool, const GimpCoords *coords,
		guint32 time, GdkModifierType state, GimpDisplay *display);
static gboolean gimp_helper_tool_key_press(GimpTool *tool, GdkEventKey *kevent,
		GimpDisplay *display);
static gboolean gimp_helper_tool_key_release(GimpTool *tool,
		GdkEventKey *kevent, GimpDisplay *display);
static void gimp_helper_tool_oper_update(GimpTool *tool,
		const GimpCoords *coords, GdkModifierType state, gboolean proximity,
		GimpDisplay *display);
static void gimp_helper_tool_cursor_update(GimpTool *tool,
		const GimpCoords *coords, GdkModifierType state, GimpDisplay *display);
static GimpUIManager * gimp_helper_tool_get_popup(GimpTool *tool,
		const GimpCoords *coords, GdkModifierType state, GimpDisplay *display,
		const gchar **ui_path);

static void gimp_helper_tool_draw(GimpDrawTool *draw_tool);
static void gimp_helper_tool_draw_selection(GimpDrawTool *draw_tool);

static void gimp_helper_tool_frame_item(GimpHelperTool *text_tool);

static gboolean gimp_helper_tool_rectangle_change_complete(
		GimpRectangleTool *rect_tool);

static void gimp_helper_tool_connect(GimpHelperTool *text_tool,
		GimpTextLayer *layer, GimpText *text);

static void gimp_helper_tool_layer_notify(GimpTextLayer *layer,
		const GParamSpec *pspec, GimpHelperTool *text_tool);
static void gimp_helper_tool_proxy_notify(GimpText *text,
		const GParamSpec *pspec, GimpHelperTool *text_tool);

static void gimp_helper_tool_text_notify(GimpText *text,
		const GParamSpec *pspec, GimpHelperTool *text_tool);
static void gimp_helper_tool_text_changed(GimpText *text,
		GimpHelperTool *text_tool);

static gboolean gimp_helper_tool_apply(GimpHelperTool *text_tool,
		gboolean push_undo);

static void gimp_helper_tool_create_layer(GimpHelperTool *text_tool,
		GimpText *text);

static void gimp_helper_tool_layer_changed(GimpImage *image,
		GimpHelperTool *text_tool);
static void gimp_helper_tool_set_image(GimpHelperTool *text_tool,
		GimpImage *image);
static gboolean gimp_helper_tool_set_drawable(GimpHelperTool *text_tool,
		GimpDrawable *drawable, gboolean confirm);

static void gimp_helper_tool_block_drawing(GimpHelperTool *text_tool);
static void gimp_helper_tool_unblock_drawing(GimpHelperTool *text_tool);

static void gimp_helper_tool_buffer_begin_edit(GimpTextBuffer *buffer,
		GimpHelperTool *text_tool);
static void gimp_helper_tool_buffer_end_edit(GimpTextBuffer *buffer,
		GimpHelperTool *text_tool);

G_DEFINE_TYPE_WITH_CODE (GimpHelperTool, gimp_helper_tool,
		GIMP_TYPE_DRAW_TOOL,
		G_IMPLEMENT_INTERFACE (GIMP_TYPE_RECTANGLE_TOOL,
				gimp_helper_tool_rectangle_tool_iface_init))

#define parent_class gimp_helper_tool_parent_class

void
gimp_helper_tool_register (GimpToolRegisterCallback callback,
		gpointer data)
{
	(* callback) (GIMP_TYPE_HELPER_TOOL,
			GIMP_TYPE_HELPER_OPTIONS,
			gimp_helper_options_gui,
			GIMP_CONTEXT_FOREGROUND_MASK |
			GIMP_CONTEXT_FONT_MASK |
			GIMP_CONTEXT_PALETTE_MASK /* for the color popup's palette tab */,
			"gimp-helper-tool",
			_("Helper"),
			_("Helper Tool: Create or edit text layers"),
			N_("Te_xt"), "T",
			NULL, GIMP_HELP_TOOL_TEXT,
			GIMP_STOCK_TOOL_HELPER,
			data);
}

static void gimp_helper_tool_class_init(GimpHelperToolClass *klass) {
	GObjectClass *object_class = G_OBJECT_CLASS(klass);
	GimpToolClass *tool_class = GIMP_TOOL_CLASS(klass);
	GimpDrawToolClass *draw_tool_class = GIMP_DRAW_TOOL_CLASS(klass);

	object_class->constructed = gimp_helper_tool_constructed;
	object_class->finalize = gimp_helper_tool_finalize;
	object_class->set_property = gimp_rectangle_tool_set_property;
	object_class->get_property = gimp_rectangle_tool_get_property;

	tool_class->control = gimp_helper_tool_control;
	tool_class->button_press = gimp_helper_tool_button_press;
	tool_class->motion = gimp_helper_tool_motion;
	tool_class->button_release = gimp_helper_tool_button_release;
	tool_class->key_press = gimp_helper_tool_key_press;
	tool_class->key_release = gimp_helper_tool_key_release;
	tool_class->oper_update = gimp_helper_tool_oper_update;
	tool_class->cursor_update = gimp_helper_tool_cursor_update;
	tool_class->get_popup = gimp_helper_tool_get_popup;

	draw_tool_class->draw = gimp_helper_tool_draw;

	gimp_rectangle_tool_install_properties(object_class);
}

static void gimp_helper_tool_rectangle_tool_iface_init(
		GimpRectangleToolInterface *iface) {
	iface->execute = NULL;
	iface->cancel = NULL;
	iface->rectangle_change_complete =
			gimp_helper_tool_rectangle_change_complete;
}

static void gimp_helper_tool_init(GimpHelperTool *text_tool) {
	GimpTool *tool = GIMP_TOOL(text_tool);

	text_tool->proxy = NULL;
	text_tool->pending = NULL;
	text_tool->idle_id = 0;
	text_tool->helper_on = FALSE; //changes_isaiah

	text_tool->text = NULL;
	text_tool->layer = NULL;
	text_tool->image = NULL;
	text_tool->layout = NULL;

	text_tool->buffer = gimp_text_buffer_new();

	g_signal_connect(text_tool->buffer, "begin-user-action",
			G_CALLBACK(gimp_helper_tool_buffer_begin_edit), text_tool);
	g_signal_connect(text_tool->buffer, "end-user-action",
			G_CALLBACK(gimp_helper_tool_buffer_end_edit), text_tool);

	text_tool->handle_rectangle_change_complete = TRUE;

	gimp_helper_tool_editor_init(text_tool);

	gimp_tool_control_set_scroll_lock(tool->control, TRUE);
	gimp_tool_control_set_handle_empty_image(tool->control, TRUE);
	gimp_tool_control_set_wants_click(tool->control, TRUE);
	gimp_tool_control_set_wants_double_click(tool->control, TRUE);
	gimp_tool_control_set_wants_triple_click(tool->control, TRUE);
	gimp_tool_control_set_wants_all_key_events(tool->control, TRUE);
	gimp_tool_control_set_precision(tool->control,
			GIMP_CURSOR_PRECISION_PIXEL_BORDER);
	gimp_tool_control_set_tool_cursor(tool->control, GIMP_TOOL_CURSOR_TEXT);
	gimp_tool_control_set_action_object_1(tool->control,
			"context/context-font-select-set");
}

static void gimp_helper_tool_constructed(GObject *object) {
	GimpHelperTool *text_tool = GIMP_HELPER_TOOL(object);
	GimpHelperOptions *options = GIMP_HELPER_TOOL_GET_OPTIONS(text_tool);

	if (G_OBJECT_CLASS(parent_class)->constructed)
		G_OBJECT_CLASS(parent_class)->constructed(object);

	gimp_rectangle_tool_constructor(object);

	text_tool->proxy = g_object_new(GIMP_TYPE_TEXT, NULL);

	gimp_helper_options_connect_text(options, text_tool->proxy);

	g_signal_connect_object(text_tool->proxy, "notify",
			G_CALLBACK(gimp_helper_tool_proxy_notify), text_tool, 0);

	g_object_set(options, "highlight", FALSE, NULL);
}

static void gimp_helper_tool_finalize(GObject *object) {
	GimpHelperTool *text_tool = GIMP_HELPER_TOOL(object);

	if (text_tool->proxy) {
		g_object_unref(text_tool->proxy);
		text_tool->proxy = NULL;
	}

	if (text_tool->buffer) {
		g_object_unref(text_tool->buffer);
		text_tool->buffer = NULL;
	}

	gimp_helper_tool_editor_finalize(text_tool);

	G_OBJECT_CLASS(parent_class)->finalize(object);
}

static void gimp_helper_tool_control(GimpTool *tool, GimpToolAction action,
		GimpDisplay *display) {
	GimpHelperTool *text_tool = GIMP_HELPER_TOOL(tool);

	switch (action) {
	case GIMP_TOOL_ACTION_PAUSE:
	case GIMP_TOOL_ACTION_RESUME:
		break;

	case GIMP_TOOL_ACTION_HALT:
		gimp_helper_tool_editor_halt(text_tool);
		gimp_helper_tool_set_drawable(text_tool, NULL, FALSE);
		break;
	}

	gimp_rectangle_tool_control(tool, action, display);

	GIMP_TOOL_CLASS(parent_class)->control(tool, action, display);
}

static void gimp_helper_tool_button_press(GimpTool *tool,
		const GimpCoords *coords, guint32 time, GdkModifierType state,
		GimpButtonPressType press_type, GimpDisplay *display) {
	GimpHelperTool *text_tool = GIMP_HELPER_TOOL(tool);
	GimpRectangleTool *rect_tool = GIMP_RECTANGLE_TOOL(tool);
	GimpImage *image = gimp_display_get_image(display);
	GimpText *text = text_tool->text;

	text_tool->helper_on = FALSE; //changes_isaiah

	gimp_draw_tool_pause(GIMP_DRAW_TOOL(tool));

	if (tool->display && tool->display != display)
		gimp_tool_control(tool, GIMP_TOOL_ACTION_HALT, display);

	if (press_type == GIMP_BUTTON_PRESS_NORMAL) {
		gimp_tool_control_activate(tool->control);

		gimp_helper_tool_reset_im_context(text_tool);

		text_tool->selecting = FALSE;

		if (gimp_rectangle_tool_point_in_rectangle(rect_tool, coords->x,
				coords->y) && !text_tool->moving) {
			gimp_rectangle_tool_set_function(rect_tool,
					GIMP_RECTANGLE_TOOL_DEAD);
		} else {
			gimp_rectangle_tool_button_press(tool, coords, time, state,
					display);
		}

		/*  bail out now if the user user clicked on a handle of an
		 *  existing rectangle, but not inside an existing framed layer
		 */
		if (gimp_rectangle_tool_get_function(rect_tool)
				!= GIMP_RECTANGLE_TOOL_CREATING) {
			if (text_tool->layer) {
				GimpItem *item = GIMP_ITEM(text_tool->layer);
				gdouble x = coords->x - gimp_item_get_offset_x(item);
				gdouble y = coords->y - gimp_item_get_offset_y(item);

				if (x < 0 || x >= gimp_item_get_width(item) || y < 0
						|| y >= gimp_item_get_height(item)) {
					gimp_draw_tool_resume(GIMP_DRAW_TOOL(tool));
					return;
				}
			} else {
				gimp_draw_tool_resume(GIMP_DRAW_TOOL(tool));
				return;
			}
		}

		/* if the the click is not related to the currently edited text
		 * layer in any way, try to pick a text layer
		 */
		if (!text_tool->moving
				&& gimp_rectangle_tool_get_function(rect_tool)
						== GIMP_RECTANGLE_TOOL_CREATING) {
			GimpTextLayer *text_layer;

			text_layer = gimp_image_pick_text_layer(image, coords->x,
					coords->y);

			if (text_layer && text_layer != text_tool->layer) {
				if (text_tool->image == image)
					g_signal_handlers_block_by_func(image,
							gimp_helper_tool_layer_changed, text_tool);

				gimp_image_set_active_layer(image, GIMP_LAYER(text_layer));

				if (text_tool->image == image)
					g_signal_handlers_unblock_by_func(image,
							gimp_helper_tool_layer_changed, text_tool);
			}
		}
	}

	if (gimp_image_coords_in_active_pickable(image, coords, FALSE, FALSE)) {
		GimpDrawable *drawable = gimp_image_get_active_drawable(image);
		GimpItem *item = GIMP_ITEM(drawable);
		gdouble x = coords->x - gimp_item_get_offset_x(item);
		gdouble y = coords->y - gimp_item_get_offset_y(item);

		/*  did the user click on a text layer?  */
		if (gimp_helper_tool_set_drawable(text_tool, drawable, TRUE)) {
			if (press_type == GIMP_BUTTON_PRESS_NORMAL) {
				/*  if we clicked on a text layer while the tool was idle
				 *  (didn't show a rectangle), frame the layer and switch to
				 *  selecting instead of drawing a new rectangle
				 */
				if (gimp_rectangle_tool_get_function(rect_tool)
						== GIMP_RECTANGLE_TOOL_CREATING) {
					gimp_rectangle_tool_set_function(rect_tool,
							GIMP_RECTANGLE_TOOL_DEAD);

					gimp_helper_tool_frame_item(text_tool);
				}

				if (text_tool->text && text_tool->text != text) {
					gimp_helper_tool_editor_start(text_tool);
				}
			}

			if (text_tool->text && !text_tool->moving) {
				text_tool->selecting = TRUE;

				gimp_helper_tool_editor_button_press(text_tool, x, y,
						press_type);
			} else {
				text_tool->selecting = FALSE;
			}

			gimp_draw_tool_resume(GIMP_DRAW_TOOL(tool));

			return;
		}
	}

	if (press_type == GIMP_BUTTON_PRESS_NORMAL) {
		/*  create a new text layer  */
		text_tool->text_box_fixed = FALSE;

		gimp_helper_tool_connect(text_tool, NULL, NULL);
		gimp_helper_tool_editor_start(text_tool);
		text_tool->helper_on = TRUE;
	}

	gimp_draw_tool_resume(GIMP_DRAW_TOOL(tool));
}

static void gimp_helper_tool_button_release(GimpTool *tool,
		const GimpCoords *coords, guint32 time, GdkModifierType state,
		GimpButtonReleaseType release_type, GimpDisplay *display) {
	GimpRectangleTool *rect_tool = GIMP_RECTANGLE_TOOL(tool);
	GimpHelperTool *text_tool = GIMP_HELPER_TOOL(tool);

	/* changes_isaiah here */
	GimpImage *image = gimp_display_get_image(display);
	gchar *gchar_uri = gimp_image_get_any_uri(image);
	gboolean callhelper = TRUE;
	if (gchar_uri == NULL) {
		callhelper = FALSE;
	}
	//printf("The uri is: %s\n", gchar_uri);
	/* end changes */

	gimp_tool_control_halt(tool->control);

	if (text_tool->selecting) {
		/*  we are in a selection process (user has initially clicked on
		 *  an existing text layer), so finish the selection process and
		 *  ignore rectangle-change-complete.
		 */

		/*  need to block "end-user-action" on the text buffer, because
		 *  GtkTextBuffer considers copying text to the clipboard an
		 *  undo-relevant user action, which is clearly a bug, but what
		 *  can we do...
		 */
		g_signal_handlers_block_by_func(text_tool->buffer,
				gimp_helper_tool_buffer_begin_edit, text_tool);
		g_signal_handlers_block_by_func(text_tool->buffer,
				gimp_helper_tool_buffer_end_edit, text_tool);

		gimp_helper_tool_editor_button_release(text_tool);

		g_signal_handlers_unblock_by_func(text_tool->buffer,
				gimp_helper_tool_buffer_end_edit, text_tool);
		g_signal_handlers_unblock_by_func(text_tool->buffer,
				gimp_helper_tool_buffer_begin_edit, text_tool);

		text_tool->selecting = FALSE;

		text_tool->handle_rectangle_change_complete = FALSE;

		/*  there is no cancelling of selections yet  */
		if (release_type == GIMP_BUTTON_RELEASE_CANCEL)
			release_type = GIMP_BUTTON_RELEASE_NORMAL;
		callhelper = FALSE; //changes_isaiah
	} else if (text_tool->moving) {
		/*  the user has moved the text layer with Alt-drag, fall
		 *  through and let rectangle-change-complete do its job of
		 *  setting text layer's new position.
		 */
//		printf("moving\n");
		callhelper = FALSE; //changes_isaiah
	} else if (gimp_rectangle_tool_get_function(rect_tool)
			== GIMP_RECTANGLE_TOOL_DEAD) {
		/*  the user clicked in dead space (like between the corner and
		 *  edge handles, so completely ignore that.
		 */

//		printf("dead space\n");
//		text_tool->handle_rectangle_change_complete = FALSE;
		callhelper = FALSE; //changes_isaiah
	} else if (release_type == GIMP_BUTTON_RELEASE_CANCEL) {
		/*  user has clicked outside of any text layer in order to
		 *  create a new text, but cancelled the operation.
		 */

		gimp_helper_tool_editor_halt(text_tool);

		text_tool->handle_rectangle_change_complete = FALSE;
		callhelper = FALSE; //changes_isaiah
	}

	else {
		gint x1, y1;
		gint x2, y2;

		/*  otherwise the user has clicked outside of any text layer in
		 *  order to create a new text, fall through and let
		 *  rectangle-change-complete do its job of setting the new text
		 *  layer's size.
		 */

		g_object_get(text_tool, "x1", &x1, "y1", &y1, "x2", &x2, "y2", &y2,
				NULL);

		if (release_type == GIMP_BUTTON_RELEASE_CLICK || (x2 - x1) < 3
				|| (y2 - y1) < 3) {
			/*  unless the rectangle is unreasonably small to hold any
			 *  real text (the user has eitherjust clicked or just made
			 *  a rectangle of a few pixels), so set the text box to
			 *  dynamic and ignore rectangle-change-complete.
			 */

			g_object_set(text_tool->proxy, "box-mode", GIMP_TEXT_BOX_DYNAMIC,
					NULL);

			text_tool->handle_rectangle_change_complete = FALSE;
		}
//		printf("i'm here\n");
		callhelper = FALSE; //changes_isaiah
		if (text_tool->helper_on) {
			callhelper = TRUE; //changes_isaiah
		}
	}
	/*  changes_isaiah  */

	if (callhelper == FALSE) {

	} else {
	    char cwd[PATH_MAX]; /* PATH_MAX incudes the \0 so +1 is not required */
	    char cwd2ftb[] = "/app/tools/helpercore/FillTalkBoxapp ";
		// cwd = /home/isaiah/comic_translate_with_gimp/gimp-2.8.20
	    if (getcwd(cwd, sizeof(cwd)) != NULL) {
	        // printf("Current working dir: %s\n", cwd);
	    } else {
	        perror("getcwd() error");
	        return 1;
	    }
	    char *function_location;
	    function_location = malloc(strlen(cwd) + strlen(cwd2ftb));
	    strcpy(function_location, cwd); /* copy name into the new var */
		strcat(function_location, cwd2ftb); /* add the extension */

	    // char *function_location = "/home/isaiah/comic_translate_with_gimp/gimp-2.8.20/app/tools/helpercore/FillTalkBoxapp ";

		int temp_x = coords->x;
		int temp_y = coords->y;
		int x_size = 0;
		int y_size = 0;
		while (temp_x != 0) {
			temp_x /= 10;
			x_size++;
		}
		while (temp_y != 0) {
			temp_y /= 10;
			y_size++;
		}
		int x = coords->x;
		int y = coords->y;
		char x_char[x_size];
		char y_char[y_size];
		sprintf(x_char, "%d", x);
		sprintf(y_char, "%d", y);

		int calling_size = strlen(function_location) + strlen(gchar_uri)
				+ x_size + y_size + 3;
		char function_calling[calling_size];
			// printf("The x is: %s\n", x_char);
			// printf("The y is: %s\n", y_char);
			// printf("The function_location is: %s\n", function_location);
			// printf("The uri is: %s\n", gchar_uri);
			// printf("x_size is : %d\n", x_size);
			// printf("y_size is : %d\n", y_size);
			// printf("callint size is : %d\n", calling_size);
		//so far so good
		{
			int i = 0;
			int j = 0;
			for (j = 0; j < strlen(function_calling); j++) {
				function_calling[j] = ' ';
			}

			for (j = 0; i < strlen(function_location); i++) {
				function_calling[i] = function_location[j];
				j++;
			}
			//printf("The calling1 is: %s\n", function_calling);

			for (j = 0; i < strlen(function_location) + strlen(gchar_uri);
					i++) {
				function_calling[i] = gchar_uri[j];
				j++;
			}
			//printf("The calling2 is: %s\n", function_calling);

			function_calling[i] = ' ';
			i++;

			for (j = 0;
					i
							< strlen(function_location) + strlen(gchar_uri) + 1
									+ x_size; i++) {
				function_calling[i] = x_char[j];
				j++;
			}
			//printf("The calling3 is: %s\n", function_calling);

			function_calling[i] = ' ';
			i++;

			for (j = 0; j < y_size; i++) {
				function_calling[i] = y_char[j];
				j++;
			}
			function_calling[i] = ' ';
		}
		//printf("The calling is: %s\n", function_calling);
		int status_of_fill_text_box = system(function_calling);

		/* changes_isaiah 開始耍寶 插入圖片 */
		{
			//GimpDisplayShell *shell   = GIMP_DISPLAY_SHELL (data);
			GimpImage * image;
			GimpContext *context;
			//			  GList            *list;
			gboolean open_as_layers;

			//			  printf("Function is working3\n");
			//			  fflush(stdout);

			/* If the app is already being torn down, shell->display might be NULL here.
			 * Play it safe. */
			if (!display) {
				return;
			}

			image = gimp_display_get_image(display);
			context = gimp_get_user_context(display->gimp);

			GIMP_LOG(DND, NULL);

			open_as_layers = (image != NULL);

			//in for loop
		    char cwd2mask_png[] = "/app/tools/helpercore/temp/transparent_mask.png";

		    char *transparent_mask_location;
		    transparent_mask_location = malloc(strlen(cwd) + strlen(cwd2mask_png));
		    strcpy(transparent_mask_location, cwd); /* copy name into the new var */
			strcat(transparent_mask_location, cwd2mask_png); /* add the extension */
			const gchar *uri = transparent_mask_location;
			// printf("The uri is: %s\n", uri);

			// const gchar *uri =
			// 		"/home/isaiah/comic_translate_with_gimp/gimp-2.8.20/app/tools/helpercore/temp/transparent_mask.png";
			GimpPDBStatusType status;
			GError *error = NULL;
			gboolean warn = FALSE;

			if (!display) {
				/* It seems as if GIMP is being torn down for quitting. Bail out. */
				return;
			}

			if (open_as_layers) {
				GList *new_layers;

				new_layers = file_open_layers(display->gimp, context,
						GIMP_PROGRESS(display), image, FALSE, uri,
						GIMP_RUN_INTERACTIVE, NULL, &status, &error);

				if (new_layers) {

					//			              gint x, y;		        	  
					gint width, height;
					width = gimp_image_get_width(image);
					height = gimp_image_get_height(image);

					//			              gimp_display_shell_untransform_viewport (shell, &x, &y,
					//			                                                       &width, &height);

					gimp_image_add_layers(image, new_layers,
							GIMP_IMAGE_ACTIVE_PARENT, -1, 0, 0, width, height,
							_("Drop layers"));

					g_list_free(new_layers);
				} else if (status != GIMP_PDB_CANCEL) {
					warn = TRUE;
				}
			} else if (gimp_display_get_image(display)) {
				/*  open any subsequent images in a new display  */
				GimpImage *new_image;

				new_image = file_open_with_display(display->gimp, context, NULL,
						uri, FALSE, &status, &error);

				if (!new_image && status != GIMP_PDB_CANCEL)
					warn = TRUE;
			} else {
				/*  open the first image in the empty display  */
				image = file_open_with_display(display->gimp, context,
						GIMP_PROGRESS(display), uri, FALSE, &status, &error);

				if (!image && status != GIMP_PDB_CANCEL)
					warn = TRUE;
			}

			/* Something above might have run a few rounds of the main loop. Check
			 * that shell->display is still there, otherwise ignore this as the app
			 * is being torn down for quitting. */
			if (warn && display) {
				gchar *filename = file_utils_uri_display_name(uri);

				gimp_message(display->gimp, G_OBJECT(display),
						GIMP_MESSAGE_ERROR, _("Opening '%s' failed:\n\n%s"),
						filename, error->message);

				g_clear_error(&error);
				g_free(filename);
			}

			if (image)
				gimp_image_flush(image);


			//get all the path
			// cwd = /home/isaiah/comic_translate_with_gimp/gimp-2.8.20

			char cwd2helper_translated_text[] = "/app/tools/helpercore/temp/Translated.txt";
			char cwd2helper_border_text[] = "/app/tools/helpercore/temp/bounded_box_coordinate.txt";


		    char *translated_text_location;
		    char *border_text_location;

		    translated_text_location = malloc(strlen(cwd) + strlen(cwd2helper_translated_text));
		    border_text_location = malloc(strlen(cwd) + strlen(cwd2helper_border_text));

		    strcpy(translated_text_location, cwd); /* copy name into the new var */
			strcat(translated_text_location, cwd2helper_translated_text); /* add the extension */

			strcpy(border_text_location, cwd); /* copy name into the new var */
			strcat(border_text_location, cwd2helper_border_text); /* add the extension */


		    char using_python[] = "python3 ";
		    char cwd_2_Detect_and_Translate[] = "/app/tools/helpercore/Detect_and_Translate.py";
		    char *Detect_and_Translate_location;
		    Detect_and_Translate_location = malloc(strlen(cwd) + strlen(cwd_2_Detect_and_Translate));
		    strcpy(Detect_and_Translate_location, cwd); /* copy name into the new var */
			strcat(Detect_and_Translate_location, cwd_2_Detect_and_Translate); /* add the extension */

		    char *system_Detect_and_Translate_py;
		    system_Detect_and_Translate_py = malloc(strlen(using_python) + strlen(Detect_and_Translate_location));
		    strcpy(system_Detect_and_Translate_py, using_python); /* copy name into the new var */
			strcat(system_Detect_and_Translate_py, Detect_and_Translate_location); /* add the extension */

			/*  插入文字  */
			/*  auto text layer changes_isaiah  */

			text_tool->image = image;					//set image				
			int status_of_detect_and_translate =
					system(system_Detect_and_Translate_py);
					// "python3 /home/isaiah/comic_translate_with_gimp/gimp-2.8.20/app/tools/helpercore/Detect_and_Translate.py");

//				std::ifstream read_translated("/home/isaiah/gimp-helper-2019/gimp-2.8.20/app/tools/helpercore/temp/Translated.txt");
//				std::string read_translated_str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());

			gchar *helper_translated_text;
			gchar *helper_border_text;
//				helper_translated_text = "這是我的翻譯";
			helper_translated_text =
					read_file(translated_text_location);
					//"/home/isaiah/comic_translate_with_gimp/gimp-2.8.20/app/tools/helpercore/temp/Translated.txt"
			helper_border_text =
					read_file(border_text_location);
					// "/home/isaiah/comic_translate_with_gimp/gimp-2.8.20/app/tools/helpercore/temp/bounded_box_coordinate.txt"
			//printf(helper_border_text);

			if (helper_border_text == "fail") {
				g_object_set(text_tool->buffer, "text", helper_translated_text,
						NULL);
				gimp_helper_tool_create_layer(text_tool, NULL);
			} else {
				gint x1, y1;
				gint width, height;
				// 設置切割字符
				const char* delim = ",";

				// 切割字串
				char* pch = strtok(helper_border_text, delim);
				int index = 0;
				while (pch && index < 4) {
					//printf("%s  ", pch);
					if (index == 0) {
						x1 = atoi(pch);
					}
					if (index == 1) {
						y1 = atoi(pch);
					}
					if (index == 2) {
						width = atoi(pch);
					}
					if (index == 3) {
						height = atoi(pch);
					}
					index++;
					pch = strtok(NULL, delim);
				}
				printf("%d, %d, %d, %d", x1, y1, width, height);

				g_object_set(text_tool, "x1", x1, "y1", y1, "x2", x1 + width, "y2", y1 + height, NULL);
				
				g_object_set(text_tool->buffer, "text", helper_translated_text, NULL);
				gimp_helper_tool_create_layer(text_tool, NULL);
				
				/*  function for text_tool properties  */
				GimpUnit box_unit = text_tool->proxy->box_unit;
				gdouble xres, yres;
				gimp_image_get_resolution(image, &xres, &yres);
				g_object_set(text_tool->proxy, "box-mode", GIMP_TEXT_BOX_FIXED,
						"box-width",
						gimp_pixels_to_units(width, box_unit, xres),
						"box-height",
						gimp_pixels_to_units(height, box_unit, yres), NULL);
			}

			/*  auto text layer changes _end  */

		}/*  耍寶結束  */

	}
	/* ends */
	gimp_rectangle_tool_button_release(tool, coords, time, state, release_type,
			display);

	text_tool->handle_rectangle_change_complete = TRUE;
}

static void gimp_helper_tool_motion(GimpTool *tool, const GimpCoords *coords,
		guint32 time, GdkModifierType state, GimpDisplay *display) {
	GimpHelperTool *text_tool = GIMP_HELPER_TOOL(tool);

	if (!text_tool->selecting) {
		gimp_rectangle_tool_motion(tool, coords, time, state, display);
	} else {
		GimpItem *item = GIMP_ITEM(text_tool->layer);
		gdouble x = coords->x - gimp_item_get_offset_x(item);
		gdouble y = coords->y - gimp_item_get_offset_y(item);

		gimp_helper_tool_editor_motion(text_tool, x, y);
	}
}

static gboolean gimp_helper_tool_key_press(GimpTool *tool, GdkEventKey *kevent,
		GimpDisplay *display) {
	GimpHelperTool *text_tool = GIMP_HELPER_TOOL(tool);

	if (display == tool->display)
		return gimp_helper_tool_editor_key_press(text_tool, kevent);

	return FALSE;
}

static gboolean gimp_helper_tool_key_release(GimpTool *tool,
		GdkEventKey *kevent, GimpDisplay *display) {
	GimpHelperTool *text_tool = GIMP_HELPER_TOOL(tool);

	if (display == tool->display)
		return gimp_helper_tool_editor_key_release(text_tool, kevent);

	return FALSE;
}

static void gimp_helper_tool_oper_update(GimpTool *tool,
		const GimpCoords *coords, GdkModifierType state, gboolean proximity,
		GimpDisplay *display) {
	GimpHelperTool *text_tool = GIMP_HELPER_TOOL(tool);
	GimpRectangleTool *rect_tool = GIMP_RECTANGLE_TOOL(tool);

	gimp_rectangle_tool_oper_update(tool, coords, state, proximity, display);

	text_tool->moving = (gimp_rectangle_tool_get_function(rect_tool)
			== GIMP_RECTANGLE_TOOL_MOVING && (state & GDK_MOD1_MASK));
}

static void gimp_helper_tool_cursor_update(GimpTool *tool,
		const GimpCoords *coords, GdkModifierType state, GimpDisplay *display) {
	if (tool->display == display) {
		GimpHelperTool *text_tool = GIMP_HELPER_TOOL(tool);

		if (gimp_rectangle_tool_point_in_rectangle(GIMP_RECTANGLE_TOOL(tool),
				coords->x, coords->y) && !text_tool->moving) {
			gimp_tool_control_set_cursor(tool->control, GDK_XTERM);
			gimp_tool_control_set_cursor_modifier(tool->control,
					GIMP_CURSOR_MODIFIER_NONE);
		} else {
			gimp_rectangle_tool_cursor_update(tool, coords, state, display);
		}
	} else {
		gimp_tool_control_set_cursor(tool->control, GDK_XTERM);
		gimp_tool_control_set_cursor_modifier(tool->control,
				GIMP_CURSOR_MODIFIER_NONE);
	}

	GIMP_TOOL_CLASS(parent_class)->cursor_update(tool, coords, state, display);
}

static GimpUIManager *
gimp_helper_tool_get_popup(GimpTool *tool, const GimpCoords *coords,
		GdkModifierType state, GimpDisplay *display, const gchar **ui_path) {
	GimpHelperTool *text_tool = GIMP_HELPER_TOOL(tool);

	if (gimp_rectangle_tool_point_in_rectangle(GIMP_RECTANGLE_TOOL(text_tool),
			coords->x, coords->y)) {
		if (!text_tool->ui_manager) {
			GimpDialogFactory *dialog_factory;
			GtkWidget *im_menu;
			GList *children;

			dialog_factory = gimp_dialog_factory_get_singleton();

			text_tool->ui_manager = gimp_menu_factory_manager_new(
					gimp_dialog_factory_get_menu_factory(dialog_factory),
					"<TextTool>", text_tool, FALSE);

			im_menu = gtk_ui_manager_get_widget(
					GTK_UI_MANAGER(text_tool->ui_manager),
					"/text-tool-popup/text-tool-input-methods-menu");

			if (GTK_IS_MENU_ITEM(im_menu))
				im_menu = gtk_menu_item_get_submenu(GTK_MENU_ITEM(im_menu));

			/*  hide the generated "empty" item  */
			children = gtk_container_get_children(GTK_CONTAINER(im_menu));
			while (children) {
				gtk_widget_hide(children->data);
				children = g_list_remove(children, children->data);
			}

			gtk_im_multicontext_append_menuitems(
					GTK_IM_MULTICONTEXT(text_tool->im_context),
					GTK_MENU_SHELL(im_menu));
		}

		gimp_ui_manager_update(text_tool->ui_manager, text_tool);

		*ui_path = "/text-tool-popup";

		return text_tool->ui_manager;
	}

	return NULL;
}

static void gimp_helper_tool_draw(GimpDrawTool *draw_tool) {
	GimpHelperTool *text_tool = GIMP_HELPER_TOOL(draw_tool);

	g_object_set(text_tool, "narrow-mode", TRUE, NULL);

	gimp_rectangle_tool_draw(draw_tool, NULL);

	if (!text_tool->text || !text_tool->layer || !text_tool->layer->text) {
		gimp_helper_tool_editor_update_im_rect(text_tool);

		return;
	}

	gimp_helper_tool_ensure_layout(text_tool);

	if (gtk_text_buffer_get_has_selection(GTK_TEXT_BUFFER(text_tool->buffer))) {
		/* If the text buffer has a selection, highlight the selected letters */

		gimp_helper_tool_draw_selection(draw_tool);
	} else {
		/* If the text buffer has no selection, draw the text cursor */

		GimpCanvasItem *item;
		PangoRectangle cursor_rect;
		gint off_x, off_y;
		gboolean overwrite;

		gimp_helper_tool_editor_get_cursor_rect(text_tool,
				text_tool->overwrite_mode, &cursor_rect);

		gimp_item_get_offset(GIMP_ITEM(text_tool->layer), &off_x, &off_y);
		cursor_rect.x += off_x;
		cursor_rect.y += off_y;

		overwrite = text_tool->overwrite_mode && cursor_rect.width != 0;

		item = gimp_draw_tool_add_text_cursor(draw_tool, &cursor_rect,
				overwrite);
		gimp_canvas_item_set_highlight(item, TRUE);
	}

	gimp_helper_tool_editor_update_im_rect(text_tool);
}

static void gimp_helper_tool_draw_selection(GimpDrawTool *draw_tool) {
	GimpHelperTool *text_tool = GIMP_HELPER_TOOL(draw_tool);
	GtkTextBuffer *buffer = GTK_TEXT_BUFFER(text_tool->buffer);
	GimpCanvasGroup *fill_group;
	PangoLayout *layout;
	gint offset_x;
	gint offset_y;
	gint off_x, off_y;
	PangoLayoutIter *iter;
	GtkTextIter sel_start, sel_end;
	gint min, max;
	gint i;

	fill_group = gimp_draw_tool_add_fill_group(draw_tool);
	gimp_canvas_item_set_highlight(GIMP_CANVAS_ITEM(fill_group), TRUE);

	gtk_text_buffer_get_selection_bounds(buffer, &sel_start, &sel_end);

	min = gimp_text_buffer_get_iter_index(text_tool->buffer, &sel_start, TRUE);
	max = gimp_text_buffer_get_iter_index(text_tool->buffer, &sel_end, TRUE);

	layout = gimp_text_layout_get_pango_layout(text_tool->layout);

	gimp_text_layout_get_offsets(text_tool->layout, &offset_x, &offset_y);

	gimp_item_get_offset(GIMP_ITEM(text_tool->layer), &off_x, &off_y);
	offset_x += off_x;
	offset_y += off_y;

	iter = pango_layout_get_iter(layout);

	gimp_draw_tool_push_group(draw_tool, fill_group);

	do {
		if (!pango_layout_iter_get_run(iter))
			continue;

		i = pango_layout_iter_get_index(iter);

		if (i >= min && i < max) {
			PangoRectangle rect;
			gint ytop, ybottom;

			pango_layout_iter_get_char_extents(iter, &rect);
			pango_layout_iter_get_line_yrange(iter, &ytop, &ybottom);

			rect.y = ytop;
			rect.height = ybottom - ytop;

			pango_extents_to_pixels(&rect, NULL);

			gimp_text_layout_transform_rect(text_tool->layout, &rect);

			rect.x += offset_x;
			rect.y += offset_y;

			gimp_draw_tool_add_rectangle(draw_tool, TRUE, rect.x, rect.y,
					rect.width, rect.height);
		}
	} while (pango_layout_iter_next_char(iter));

	gimp_draw_tool_pop_group(draw_tool);

	pango_layout_iter_free(iter);
}

static void gimp_helper_tool_frame_item(GimpHelperTool *text_tool) {
	g_return_if_fail(GIMP_IS_LAYER(text_tool->layer));

	text_tool->handle_rectangle_change_complete = FALSE;

	gimp_rectangle_tool_frame_item(GIMP_RECTANGLE_TOOL(text_tool),
			GIMP_ITEM(text_tool->layer));

	text_tool->handle_rectangle_change_complete = TRUE;
}

static gboolean gimp_helper_tool_rectangle_change_complete(
		GimpRectangleTool *rect_tool) {
	GimpHelperTool *text_tool = GIMP_HELPER_TOOL(rect_tool);

	gimp_helper_tool_editor_position(text_tool);

	if (text_tool->handle_rectangle_change_complete) {
		GimpItem *item = GIMP_ITEM(text_tool->layer);
		gint x1, y1;
		gint x2, y2;

		if (!item) {
			/* we can't set properties for the text layer, because it
			 * isn't created until some text has been inserted, so we
			 * need to make a special note that will remind us what to
			 * do when we actually create the layer
			 */
			text_tool->text_box_fixed = TRUE;

			return TRUE;
		}

		g_object_get(rect_tool, "x1", &x1, "y1", &y1, "x2", &x2, "y2", &y2,
				NULL);

		if (x1 != gimp_item_get_offset_x(item)
				|| y1 != gimp_item_get_offset_y(item)
				|| (x2 - x1) != gimp_item_get_width(item)
				|| (y2 - y1) != gimp_item_get_height(item)) {
			GimpUnit box_unit = text_tool->proxy->box_unit;
			gdouble xres, yres;
			gboolean push_undo = TRUE;
			GimpUndo *undo;

			gimp_image_get_resolution(text_tool->image, &xres, &yres);

			g_object_set(text_tool->proxy, "box-mode", GIMP_TEXT_BOX_FIXED,
					"box-width", gimp_pixels_to_units(x2 - x1, box_unit, xres),
					"box-height", gimp_pixels_to_units(y2 - y1, box_unit, yres),
					NULL);

			undo = gimp_image_undo_can_compress(text_tool->image,
					GIMP_TYPE_UNDO_STACK, GIMP_UNDO_GROUP_TEXT);

			if (undo && gimp_undo_get_age(undo) <= TEXT_UNDO_TIMEOUT
					&& g_object_get_data(G_OBJECT(undo), "reshape-text-layer")
							== (gpointer) item)
				push_undo = FALSE;

			if (push_undo) {
				gimp_image_undo_group_start(text_tool->image,
						GIMP_UNDO_GROUP_TEXT, _("Reshape Text Layer"));

				undo = gimp_image_undo_can_compress(text_tool->image,
						GIMP_TYPE_UNDO_STACK, GIMP_UNDO_GROUP_TEXT);

				if (undo)
					g_object_set_data(G_OBJECT(undo), "reshape-text-layer",
							(gpointer) item);
			}

			gimp_item_translate(item, x1 - gimp_item_get_offset_x(item),
					y1 - gimp_item_get_offset_y(item), push_undo);
			gimp_helper_tool_apply(text_tool, push_undo);

			if (push_undo)
				gimp_image_undo_group_end(text_tool->image);
		}
	}

	return TRUE;
}

static void gimp_helper_tool_connect(GimpHelperTool *text_tool,
		GimpTextLayer *layer, GimpText *text) {
	GimpTool *tool = GIMP_TOOL(text_tool);

	g_return_if_fail(text == NULL || (layer != NULL && layer->text == text));

	if (text_tool->text != text) {
		GimpHelperOptions *options = GIMP_HELPER_TOOL_GET_OPTIONS(tool);

		g_signal_handlers_block_by_func(text_tool->buffer,
				gimp_helper_tool_buffer_begin_edit, text_tool);
		g_signal_handlers_block_by_func(text_tool->buffer,
				gimp_helper_tool_buffer_end_edit, text_tool);

		if (text_tool->text) {
			g_signal_handlers_disconnect_by_func(text_tool->text,
					gimp_helper_tool_text_notify, text_tool);
			g_signal_handlers_disconnect_by_func(text_tool->text,
					gimp_helper_tool_text_changed, text_tool);

			if (text_tool->pending)
				gimp_helper_tool_apply(text_tool, TRUE);

			g_object_unref(text_tool->text);
			text_tool->text = NULL;

			g_object_set(text_tool->proxy, "text", NULL, "markup", NULL, NULL);
			gimp_text_buffer_set_text(text_tool->buffer, NULL);

			gimp_helper_tool_clear_layout(text_tool);
		}

		gimp_context_define_property(GIMP_CONTEXT(options),
				GIMP_CONTEXT_PROP_FOREGROUND, text != NULL);

		if (text) {
			if (text->unit != text_tool->proxy->unit)
				gimp_size_entry_set_unit(GIMP_SIZE_ENTRY(options->size_entry),
						text->unit);

			gimp_config_sync(G_OBJECT(text), G_OBJECT(text_tool->proxy), 0);

			if (text->markup)
				gimp_text_buffer_set_markup(text_tool->buffer, text->markup);
			else
				gimp_text_buffer_set_text(text_tool->buffer, text->text);

			gimp_helper_tool_clear_layout(text_tool);

			text_tool->text = g_object_ref(text);

			g_signal_connect(text, "notify",
					G_CALLBACK(gimp_helper_tool_text_notify), text_tool);
			g_signal_connect(text, "changed",
					G_CALLBACK(gimp_helper_tool_text_changed), text_tool);
		}

		g_signal_handlers_unblock_by_func(text_tool->buffer,
				gimp_helper_tool_buffer_end_edit, text_tool);
		g_signal_handlers_unblock_by_func(text_tool->buffer,
				gimp_helper_tool_buffer_begin_edit, text_tool);
	}

	if (text_tool->layer != layer) {
		if (text_tool->layer)
			g_signal_handlers_disconnect_by_func(text_tool->layer,
					gimp_helper_tool_layer_notify, text_tool);

		text_tool->layer = layer;

		if (layer)
			g_signal_connect_object(text_tool->layer, "notify",
					G_CALLBACK(gimp_helper_tool_layer_notify), text_tool, 0);
	}
}

static void gimp_helper_tool_layer_notify(GimpTextLayer *layer,
		const GParamSpec *pspec, GimpHelperTool *text_tool) {
	GimpTool *tool = GIMP_TOOL(text_tool);

	if (!strcmp(pspec->name, "modified")) {
		if (layer->modified)
			gimp_tool_control(tool, GIMP_TOOL_ACTION_HALT, tool->display);
	} else if (!strcmp(pspec->name, "text")) {
		if (!layer->text)
			gimp_tool_control(tool, GIMP_TOOL_ACTION_HALT, tool->display);
	}
}

static gboolean gimp_helper_tool_apply_idle(gpointer text_tool) {
	return gimp_helper_tool_apply(text_tool, TRUE);
}

static void gimp_helper_tool_proxy_notify(GimpText *text,
		const GParamSpec *pspec, GimpHelperTool *text_tool) {
	if (!text_tool->text)
		return;

	if ((pspec->flags & G_PARAM_READWRITE) == G_PARAM_READWRITE
			&& pspec->owner_type == GIMP_TYPE_TEXT) {
		gimp_helper_tool_block_drawing(text_tool);

		text_tool->pending = g_list_append(text_tool->pending,
				(gpointer) pspec);

		if (text_tool->idle_id)
			g_source_remove(text_tool->idle_id);

		text_tool->idle_id = g_idle_add_full(G_PRIORITY_LOW,
				gimp_helper_tool_apply_idle, text_tool, NULL);
	}
}

static void gimp_helper_tool_text_notify(GimpText *text,
		const GParamSpec *pspec, GimpHelperTool *text_tool) {
	g_return_if_fail(text == text_tool->text);

	gimp_helper_tool_block_drawing(text_tool);

	if ((pspec->flags & G_PARAM_READWRITE) == G_PARAM_READWRITE) {
		GValue value = { 0, };

		g_value_init(&value, pspec->value_type);

		g_object_get_property(G_OBJECT(text), pspec->name, &value);

		g_signal_handlers_block_by_func(text_tool->proxy,
				gimp_helper_tool_proxy_notify, text_tool);

		g_object_set_property(G_OBJECT(text_tool->proxy), pspec->name, &value);

		g_signal_handlers_unblock_by_func(text_tool->proxy,
				gimp_helper_tool_proxy_notify, text_tool);

		g_value_unset(&value);
	}

	/* if the text has changed, (probably because of an undo), we put
	 * the new text into the text buffer
	 */
	if (strcmp(pspec->name, "text") == 0
			|| strcmp(pspec->name, "markup") == 0) {
		g_signal_handlers_block_by_func(text_tool->buffer,
				gimp_helper_tool_buffer_begin_edit, text_tool);
		g_signal_handlers_block_by_func(text_tool->buffer,
				gimp_helper_tool_buffer_end_edit, text_tool);
		if (text->markup)
			gimp_text_buffer_set_markup(text_tool->buffer, text->markup);
		else
			gimp_text_buffer_set_text(text_tool->buffer, text->text);

		g_signal_handlers_unblock_by_func(text_tool->buffer,
				gimp_helper_tool_buffer_end_edit, text_tool);
		g_signal_handlers_unblock_by_func(text_tool->buffer,
				gimp_helper_tool_buffer_begin_edit, text_tool);
	}
}

static void gimp_helper_tool_text_changed(GimpText *text,
		GimpHelperTool *text_tool) {
	/* we need to redraw the rectangle in any case because whatever
	 * changes to the text can change its size
	 */
	gimp_helper_tool_frame_item(text_tool);

	gimp_helper_tool_unblock_drawing(text_tool);
}

static gboolean gimp_helper_tool_apply(GimpHelperTool *text_tool,
		gboolean push_undo) {
	const GParamSpec *pspec = NULL;
	GimpImage *image;
	GimpTextLayer *layer;
	GObject *src;
	GObject *dest;
	GList *list;
	gboolean undo_group = FALSE;

	if (text_tool->idle_id) {
		g_source_remove(text_tool->idle_id);
		text_tool->idle_id = 0;
	}

	g_return_val_if_fail(text_tool->text != NULL, FALSE);
	g_return_val_if_fail(text_tool->layer != NULL, FALSE);

	layer = text_tool->layer;
	image = gimp_item_get_image(GIMP_ITEM(layer));

	g_return_val_if_fail(layer->text == text_tool->text, FALSE);

	/*  Walk over the list of changes and figure out if we are changing
	 *  a single property or need to push a full text undo.
	 */
	for (list = text_tool->pending;
			list && list->next && list->next->data == list->data;
			list = list->next)
		/* do nothing */;

	if (g_list_length(list) == 1)
		pspec = list->data;

	/*  If we are changing a single property, we don't need to push
	 *  an undo if all of the following is true:
	 *   - the redo stack is empty
	 *   - the last item on the undo stack is a text undo
	 *   - the last undo changed the same text property on the same layer
	 *   - the last undo happened less than TEXT_UNDO_TIMEOUT seconds ago
	 */
	if (pspec) {
		GimpUndo *undo = gimp_image_undo_can_compress(image,
				GIMP_TYPE_TEXT_UNDO, GIMP_UNDO_TEXT_LAYER);

		if (undo && GIMP_ITEM_UNDO(undo)->item == GIMP_ITEM(layer)) {
			GimpTextUndo *text_undo = GIMP_TEXT_UNDO(undo);

			if (text_undo->pspec == pspec) {
				if (gimp_undo_get_age(undo) < TEXT_UNDO_TIMEOUT) {
					GimpTool *tool = GIMP_TOOL(text_tool);
					GimpContext *context;

					context = GIMP_CONTEXT(gimp_tool_get_options(tool));

					push_undo = FALSE;
					gimp_undo_reset_age(undo);
					gimp_undo_refresh_preview(undo, context);
				}
			}
		}
	}

	if (push_undo) {
		if (layer->modified) {
			undo_group = TRUE;
			gimp_image_undo_group_start(image, GIMP_UNDO_GROUP_TEXT, NULL);

			gimp_image_undo_push_text_layer_modified(image, NULL, layer);

			/*  see comment in gimp_text_layer_set()  */
			gimp_image_undo_push_drawable_mod(image, NULL, GIMP_DRAWABLE(layer),
					TRUE);
		}

		gimp_image_undo_push_text_layer(image, NULL, layer, pspec);
	}

	src = G_OBJECT(text_tool->proxy);
	dest = G_OBJECT(text_tool->text);

	g_signal_handlers_block_by_func(dest, gimp_helper_tool_text_notify,
			text_tool);
	g_signal_handlers_block_by_func(dest, gimp_helper_tool_text_changed,
			text_tool);

	g_object_freeze_notify(dest);

	for (; list; list = g_list_next(list)) {
		GValue value = { 0, };

		/*  look ahead and compress changes  */
		if (list->next && list->next->data == list->data)
			continue;

		pspec = list->data;

		g_value_init(&value, pspec->value_type);

		g_object_get_property(src, pspec->name, &value);
		g_object_set_property(dest, pspec->name, &value);

		g_value_unset(&value);
	}

	g_list_free(text_tool->pending);
	text_tool->pending = NULL;

	g_object_thaw_notify(dest);

	g_signal_handlers_unblock_by_func(dest, gimp_helper_tool_text_notify,
			text_tool);
	g_signal_handlers_unblock_by_func(dest, gimp_helper_tool_text_changed,
			text_tool);

	if (push_undo) {
		g_object_set(layer, "modified", FALSE, NULL);

		if (undo_group)
			gimp_image_undo_group_end(image);
	}

	gimp_helper_tool_frame_item(text_tool);

	gimp_image_flush(image);

	gimp_helper_tool_unblock_drawing(text_tool);

	return FALSE;
}

static void gimp_helper_tool_create_layer(GimpHelperTool *text_tool,
		GimpText *text) {
	GimpRectangleTool *rect_tool = GIMP_RECTANGLE_TOOL(text_tool);
	GimpTool *tool = GIMP_TOOL(text_tool);

	/*  changes_isaiah  */
	GimpImage *image;
	if (gimp_display_get_image(tool->display)) {
		image = gimp_display_get_image(tool->display);
	} else {
		image = text_tool->image;
	}
	/*  end  */

	GimpLayer *layer;
	gint x1, y1;
	gint x2, y2;

	gimp_helper_tool_block_drawing(text_tool);

	if (text) {
		text = gimp_config_duplicate(GIMP_CONFIG(text));
	} else {
		gchar *string;

		if (gimp_text_buffer_has_markup(text_tool->buffer)) {
			string = gimp_text_buffer_get_markup(text_tool->buffer);

			g_object_set(text_tool->proxy, "markup", string, "box-mode",
					GIMP_TEXT_BOX_DYNAMIC, NULL);
		} else {
			string = gimp_text_buffer_get_text(text_tool->buffer);

			g_object_set(text_tool->proxy, "text", string, "box-mode",
					GIMP_TEXT_BOX_DYNAMIC, NULL);
		}

		g_free(string);

		text = gimp_config_duplicate(GIMP_CONFIG(text_tool->proxy));
	}

	layer = gimp_text_layer_new(image, text);

	g_object_unref(text);

	if (!layer) {
		gimp_helper_tool_unblock_drawing(text_tool);
		return;
	}

	gimp_helper_tool_connect(text_tool, GIMP_TEXT_LAYER(layer), text);

	gimp_image_undo_group_start(image, GIMP_UNDO_GROUP_TEXT,
			_("Add Text Layer"));

	if (gimp_image_get_floating_selection(image)) {
		g_signal_handlers_block_by_func(image, gimp_helper_tool_layer_changed,
				text_tool);

		floating_sel_anchor(gimp_image_get_floating_selection(image));

		g_signal_handlers_unblock_by_func(image, gimp_helper_tool_layer_changed,
				text_tool);
	}

	g_object_get(rect_tool, "x1", &x1, "y1", &y1, "x2", &x2, "y2", &y2, NULL);

	gimp_item_set_offset(GIMP_ITEM(layer), x1, y1);

	gimp_image_add_layer(image, layer, GIMP_IMAGE_ACTIVE_PARENT, -1, TRUE);

	if (text_tool->text_box_fixed) {
		GimpUnit box_unit = text_tool->proxy->box_unit;
		gdouble xres, yres;

		gimp_image_get_resolution(image, &xres, &yres);

		g_object_set(text_tool->proxy, "box-mode", GIMP_TEXT_BOX_FIXED,
				"box-width", gimp_pixels_to_units(x2 - x1, box_unit, xres),
				"box-height", gimp_pixels_to_units(y2 - y1, box_unit, yres),
				NULL);

		gimp_helper_tool_apply(text_tool, TRUE); /* unblocks drawing */
	} else {
		gimp_helper_tool_frame_item(text_tool);

		gimp_helper_tool_unblock_drawing(text_tool);
	}

	gimp_image_undo_group_end(image);

	gimp_image_flush(image);

	gimp_helper_tool_set_drawable(text_tool, GIMP_DRAWABLE(layer), FALSE);
}

#define  RESPONSE_NEW 1

static void gimp_helper_tool_confirm_response(GtkWidget *widget,
		gint response_id, GimpHelperTool *text_tool) {
	GimpTextLayer *layer = text_tool->layer;

	gtk_widget_destroy(widget);

	if (layer && layer->text) {
		switch (response_id) {
		case RESPONSE_NEW:
			gimp_helper_tool_create_layer(text_tool, layer->text);
			break;

		case GTK_RESPONSE_ACCEPT:
			gimp_helper_tool_connect(text_tool, layer, layer->text);

			/*  cause the text layer to be rerendered  */
			g_object_notify(G_OBJECT(text_tool->proxy), "markup");

			gimp_helper_tool_editor_start(text_tool);
			break;

		default:
			break;
		}
	}
}

static void gimp_helper_tool_confirm_dialog(GimpHelperTool *text_tool) {
	GimpTool *tool = GIMP_TOOL(text_tool);
	GimpDisplayShell *shell = gimp_display_get_shell(tool->display);
	GtkWidget *dialog;
	GtkWidget *vbox;
	GtkWidget *label;

	g_return_if_fail(text_tool->layer != NULL);

	if (text_tool->confirm_dialog) {
		gtk_window_present(GTK_WINDOW(text_tool->confirm_dialog));
		return;
	}

	dialog = gimp_viewable_dialog_new(GIMP_VIEWABLE(text_tool->layer),
			GIMP_CONTEXT(gimp_tool_get_options(tool)),
			_("Confirm Text Editing"), "gimp-text-tool-confirm",
			GIMP_STOCK_TEXT_LAYER, _("Confirm Text Editing"), GTK_WIDGET(shell),
			gimp_standard_help_func, NULL,

			_("Create _New Layer"), RESPONSE_NEW, GTK_STOCK_CANCEL,
			GTK_RESPONSE_CANCEL, GTK_STOCK_EDIT, GTK_RESPONSE_ACCEPT,

			NULL);

	gtk_dialog_set_alternative_button_order(GTK_DIALOG(dialog),
	RESPONSE_NEW, GTK_RESPONSE_ACCEPT, GTK_RESPONSE_CANCEL, -1);

	gtk_window_set_resizable(GTK_WINDOW(dialog), FALSE);

	g_signal_connect(dialog, "response",
			G_CALLBACK(gimp_helper_tool_confirm_response), text_tool);

	vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 6);
	gtk_container_set_border_width(GTK_CONTAINER(vbox), 12);
	gtk_box_pack_start(GTK_BOX(gtk_dialog_get_content_area(GTK_DIALOG(dialog))),
			vbox, FALSE, FALSE, 0);
	gtk_widget_show(vbox);

	label = gtk_label_new(_("The layer you selected is a text layer but "
			"it has been modified using other tools. "
			"Editing the layer with the text tool will "
			"discard these modifications."
			"\n\n"
			"You can edit the layer or create a new "
			"text layer from its text attributes."));
	gtk_misc_set_alignment(GTK_MISC(label), 0.0, 0.5);
	gtk_label_set_line_wrap(GTK_LABEL(label), TRUE);
	gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);
	gtk_widget_show(label);

	gtk_widget_show(dialog);

	text_tool->confirm_dialog = dialog;
	g_signal_connect_swapped(dialog, "destroy", G_CALLBACK(g_nullify_pointer),
			&text_tool->confirm_dialog);
}

static void gimp_helper_tool_layer_changed(GimpImage *image,
		GimpHelperTool *text_tool) {
	GimpLayer *layer = gimp_image_get_active_layer(image);

	if (layer == GIMP_LAYER(text_tool->layer))
		return;

	/* all this stuff doesn't work quite yet, but it's better than before
	 */

	gimp_draw_tool_pause(GIMP_DRAW_TOOL(text_tool));

	gimp_helper_tool_editor_halt(text_tool);
	gimp_helper_tool_clear_layout(text_tool);

	if (gimp_draw_tool_is_active(GIMP_DRAW_TOOL(text_tool)))
		gimp_draw_tool_stop(GIMP_DRAW_TOOL(text_tool));

	if (gimp_helper_tool_set_drawable(text_tool, GIMP_DRAWABLE(layer), FALSE)
			&& GIMP_LAYER(text_tool->layer) == layer) {
		gimp_draw_tool_start(GIMP_DRAW_TOOL(text_tool),
				GIMP_TOOL(text_tool)->display);

		gimp_helper_tool_frame_item(text_tool);
		gimp_helper_tool_editor_start(text_tool);
		gimp_helper_tool_editor_position(text_tool);
	} else {
		gimp_tool_control(GIMP_TOOL(text_tool), GIMP_TOOL_ACTION_HALT,
				GIMP_TOOL(text_tool)->display);
	}

	gimp_draw_tool_resume(GIMP_DRAW_TOOL(text_tool));
}

static void gimp_helper_tool_set_image(GimpHelperTool *text_tool,
		GimpImage *image) {
	if (text_tool->image == image)
		return;

	if (text_tool->image) {
		g_signal_handlers_disconnect_by_func(text_tool->image,
				gimp_helper_tool_layer_changed, text_tool);

		g_object_remove_weak_pointer(G_OBJECT(text_tool->image),
				(gpointer) & text_tool->image);
	}

	text_tool->image = image;

	if (image) {
		GimpHelperOptions *options = GIMP_HELPER_TOOL_GET_OPTIONS(text_tool);
		gdouble xres;
		gdouble yres;

		g_object_add_weak_pointer(G_OBJECT(text_tool->image),
				(gpointer) & text_tool->image);

		g_signal_connect_object(text_tool->image, "active-layer-changed",
				G_CALLBACK(gimp_helper_tool_layer_changed), text_tool, 0);

		gimp_image_get_resolution(image, &xres, &yres);
		gimp_size_entry_set_resolution(GIMP_SIZE_ENTRY(options->size_entry), 0,
				yres, FALSE);
	}
}

static gboolean gimp_helper_tool_set_drawable(GimpHelperTool *text_tool,
		GimpDrawable *drawable, gboolean confirm) {

//	printf("helper set drawable working \n");
//	fflush (stdout);

	GimpImage *image = NULL;

	if (text_tool->confirm_dialog)
		gtk_widget_destroy(text_tool->confirm_dialog);

	if (drawable)
		image = gimp_item_get_image(GIMP_ITEM(drawable));

	gimp_helper_tool_set_image(text_tool, image);

	if (GIMP_IS_TEXT_LAYER(drawable) && GIMP_TEXT_LAYER(drawable)->text) {
		GimpTextLayer *layer = GIMP_TEXT_LAYER(drawable);

		if (layer == text_tool->layer && layer->text == text_tool->text)
			return TRUE;

		if (layer->modified) {
			if (confirm) {
				gimp_helper_tool_connect(text_tool, layer, NULL);
				gimp_helper_tool_confirm_dialog(text_tool);
				return TRUE;
			}
		} else {
			gimp_helper_tool_connect(text_tool, layer, layer->text);
			return TRUE;
		}
	}

	gimp_helper_tool_connect(text_tool, NULL, NULL);

	return FALSE;
}

static void gimp_helper_tool_block_drawing(GimpHelperTool *text_tool) {
	if (!text_tool->drawing_blocked) {
		gimp_draw_tool_pause(GIMP_DRAW_TOOL(text_tool));

		gimp_helper_tool_clear_layout(text_tool);

		text_tool->drawing_blocked = TRUE;
	}
}

static void gimp_helper_tool_unblock_drawing(GimpHelperTool *text_tool) {
	g_return_if_fail(text_tool->drawing_blocked == TRUE);

	text_tool->drawing_blocked = FALSE;

	gimp_draw_tool_resume(GIMP_DRAW_TOOL(text_tool));
}

static void gimp_helper_tool_buffer_begin_edit(GimpTextBuffer *buffer,
		GimpHelperTool *text_tool) {
	gimp_helper_tool_block_drawing(text_tool);
}

static void gimp_helper_tool_buffer_end_edit(GimpTextBuffer *buffer,
		GimpHelperTool *text_tool) {
	if (text_tool->text) {
		gchar *string;

		if (gimp_text_buffer_has_markup(buffer)) {
			string = gimp_text_buffer_get_markup(buffer);

			g_object_set(text_tool->proxy, "markup", string, NULL);
		} else {
			string = gimp_text_buffer_get_text(buffer);

			g_object_set(text_tool->proxy, "text", string, NULL);
		}

		g_free(string);
	} else {
		gimp_helper_tool_create_layer(text_tool, NULL);
	}
}

/*  public functions  */

void gimp_helper_tool_clear_layout(GimpHelperTool *text_tool) {
	if (text_tool->layout) {
		g_object_unref(text_tool->layout);
		text_tool->layout = NULL;
	}
}

gboolean gimp_helper_tool_ensure_layout(GimpHelperTool *text_tool) {
	if (!text_tool->layout && text_tool->text) {
		GimpImage *image = gimp_item_get_image(GIMP_ITEM(text_tool->layer));
		gdouble xres;
		gdouble yres;
		GError *error = NULL;

		gimp_image_get_resolution(image, &xres, &yres);

		text_tool->layout = gimp_text_layout_new(text_tool->layer->text, xres,
				yres, &error);
		if (error) {
			gimp_message_literal(image->gimp, NULL, GIMP_MESSAGE_ERROR,
					error->message);
			g_error_free(error);
		}
	}

	return text_tool->layout != NULL;
}

void gimp_helper_tool_set_layer(GimpHelperTool *text_tool, GimpLayer *layer) {
	g_return_if_fail(GIMP_IS_HELPER_TOOL(text_tool));
	g_return_if_fail(layer == NULL || GIMP_IS_LAYER(layer));

	if (gimp_helper_tool_set_drawable(text_tool, GIMP_DRAWABLE(layer), TRUE)) {
		GimpTool *tool = GIMP_TOOL(text_tool);
		GimpItem *item = GIMP_ITEM(layer);
		GimpContext *context;
		GimpDisplay *display;

		context = gimp_get_user_context(tool->tool_info->gimp);
		display = gimp_context_get_display(context);

		if (!display
				|| gimp_display_get_image(display)
						!= gimp_item_get_image(item)) {
			GList *list;

			display = NULL;

			for (list = gimp_get_display_iter(tool->tool_info->gimp); list;
					list = g_list_next(list)) {
				display = list->data;

				if (gimp_display_get_image(display)
						== gimp_item_get_image(item)) {
					gimp_context_set_display(context, display);
					break;
				}

				display = NULL;
			}
		}

		tool->display = display;

		if (tool->display) {
			GimpDrawTool *draw_tool = GIMP_DRAW_TOOL(tool);

			tool->drawable = GIMP_DRAWABLE(layer);

			if (gimp_draw_tool_is_active(draw_tool))
				gimp_draw_tool_stop(draw_tool);

			gimp_draw_tool_start(draw_tool, display);

			gimp_helper_tool_frame_item(text_tool);

			gimp_helper_tool_editor_start(text_tool);
		}
	}
}

gboolean gimp_helper_tool_get_has_text_selection(GimpHelperTool *text_tool) {
	GtkTextBuffer *buffer = GTK_TEXT_BUFFER(text_tool->buffer);

	return gtk_text_buffer_get_has_selection(buffer);
}

void gimp_helper_tool_delete_selection(GimpHelperTool *text_tool) {
	GtkTextBuffer *buffer = GTK_TEXT_BUFFER(text_tool->buffer);

	if (gtk_text_buffer_get_has_selection(buffer)) {
		gtk_text_buffer_delete_selection(buffer, TRUE, TRUE);
	}
}

void gimp_helper_tool_cut_clipboard(GimpHelperTool *text_tool) {
	GimpDisplayShell *shell;
	GtkClipboard *clipboard;

	g_return_if_fail(GIMP_IS_HELPER_TOOL(text_tool));

	shell = gimp_display_get_shell(GIMP_TOOL(text_tool)->display);

	clipboard = gtk_widget_get_clipboard(GTK_WIDGET(shell),
			GDK_SELECTION_CLIPBOARD);

	gtk_text_buffer_cut_clipboard(GTK_TEXT_BUFFER(text_tool->buffer), clipboard,
			TRUE);
}

void gimp_helper_tool_copy_clipboard(GimpHelperTool *text_tool) {
	GimpDisplayShell *shell;
	GtkClipboard *clipboard;

	g_return_if_fail(GIMP_IS_HELPER_TOOL(text_tool));

	shell = gimp_display_get_shell(GIMP_TOOL(text_tool)->display);

	clipboard = gtk_widget_get_clipboard(GTK_WIDGET(shell),
			GDK_SELECTION_CLIPBOARD);

	/*  need to block "end-user-action" on the text buffer, because
	 *  GtkTextBuffer considers copying text to the clipboard an
	 *  undo-relevant user action, which is clearly a bug, but what
	 *  can we do...
	 */
	g_signal_handlers_block_by_func(text_tool->buffer,
			gimp_helper_tool_buffer_begin_edit, text_tool);
	g_signal_handlers_block_by_func(text_tool->buffer,
			gimp_helper_tool_buffer_end_edit, text_tool);

	gtk_text_buffer_copy_clipboard(GTK_TEXT_BUFFER(text_tool->buffer),
			clipboard);

	g_signal_handlers_unblock_by_func(text_tool->buffer,
			gimp_helper_tool_buffer_end_edit, text_tool);
	g_signal_handlers_unblock_by_func(text_tool->buffer,
			gimp_helper_tool_buffer_begin_edit, text_tool);
}

void gimp_helper_tool_paste_clipboard(GimpHelperTool *text_tool) {
	GimpDisplayShell *shell;
	GtkClipboard *clipboard;

	g_return_if_fail(GIMP_IS_HELPER_TOOL(text_tool));

	shell = gimp_display_get_shell(GIMP_TOOL(text_tool)->display);

	clipboard = gtk_widget_get_clipboard(GTK_WIDGET(shell),
			GDK_SELECTION_CLIPBOARD);

	gtk_text_buffer_paste_clipboard(GTK_TEXT_BUFFER(text_tool->buffer),
			clipboard, NULL, TRUE);
}

void gimp_helper_tool_create_vectors(GimpHelperTool *text_tool) {
	GimpVectors *vectors;

	g_return_if_fail(GIMP_IS_HELPER_TOOL(text_tool));

	if (!text_tool->text || !text_tool->image)
		return;

	vectors = gimp_text_vectors_new(text_tool->image, text_tool->text);

	if (text_tool->layer) {
		gint x, y;

		gimp_item_get_offset(GIMP_ITEM(text_tool->layer), &x, &y);
		gimp_item_translate(GIMP_ITEM(vectors), x, y, FALSE);
	}

	gimp_image_add_vectors(text_tool->image, vectors, GIMP_IMAGE_ACTIVE_PARENT,
			-1, TRUE);

	gimp_image_flush(text_tool->image);
}

void gimp_helper_tool_create_vectors_warped(GimpHelperTool *text_tool) {
	GimpVectors *vectors0;
	GimpVectors *vectors;
	gdouble box_height;

	g_return_if_fail(GIMP_IS_HELPER_TOOL(text_tool));

	if (!text_tool->text || !text_tool->image || !text_tool->layer)
		return;

	box_height = gimp_item_get_height(GIMP_ITEM(text_tool->layer));

	vectors0 = gimp_image_get_active_vectors(text_tool->image);
	if (!vectors0)
		return;

	vectors = gimp_text_vectors_new(text_tool->image, text_tool->text);

	gimp_vectors_warp_vectors(vectors0, vectors, 0.5 * box_height);

	gimp_item_set_visible(GIMP_ITEM(vectors), TRUE, FALSE);

	gimp_image_add_vectors(text_tool->image, vectors, GIMP_IMAGE_ACTIVE_PARENT,
			-1, TRUE);

	gimp_image_flush(text_tool->image);
}

gchar* read_file(char* name) {
	int _READFILE_GUESS = 1000;

	FILE* file;
	file = fopen(name, "r");

	// 1. the file does not exist: return null
	if (!file)
		return NULL;

	// allocate memory according to the initial guess
	// (+ 1) for trailing null byte
	char* result = malloc(sizeof(char) * _READFILE_GUESS + 1);

	// 2. memory allocation failed
	if (result == NULL)
		return NULL;

	// the position in the string to write the character to
	size_t pos = 0;

	// the amount of memory allocated for the string
	size_t capacity = _READFILE_GUESS;

	// character to hold the currently-read character from the file
	char ch;

	// until the character is the EOF character
	while ((ch = getc(file)) != EOF) {
		// update the character at position `pos` to `ch`
		result[pos++] = ch;

		// if the next position would exceed bounds
		if (pos >= capacity) {
			// add the guess to the capacity
			capacity += _READFILE_GUESS;

			// allocate memory accordingly
			// (+ 1) for trailing null byte
			result = realloc(result, sizeof(char) * capacity + 1);

			// 2. memory allocation failed
			if (result == NULL)
				return NULL;
		}
	}

	// close the file
	fclose(file);

	// remove extra memory
	result = realloc(result, sizeof(char) * pos);

	// 2. memory allocation failed
	if (result == NULL)
		return NULL;

	// `pos` now points to the index after the last character read
	result[pos] = '\0';

	return result;
}
