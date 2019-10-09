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

#include "config.h"

#include <gtk/gtk.h>

#include "libgimpwidgets/gimpwidgets.h"

#include "tools-types.h"

#include "paint/gimpairbrushoptions.h"

#include "widgets/gimphelp-ids.h"
#include "widgets/gimppropwidgets.h"

#include "gimpairbrushtool.h"
#include "gimppaintoptions-gui.h"
#include "gimptoolcontrol.h"

#include "gimp-intl.h"


static GtkWidget * gimp_airbrush_options_gui (GimpToolOptions *tool_options);


G_DEFINE_TYPE (GimpAirbrushTool, gimp_airbrush_tool, GIMP_TYPE_PAINTBRUSH_TOOL)


void
gimp_airbrush_tool_register (GimpToolRegisterCallback  callback,
                             gpointer                  data)
{
  (* callback) (GIMP_TYPE_AIRBRUSH_TOOL,
                GIMP_TYPE_AIRBRUSH_OPTIONS,
                gimp_airbrush_options_gui,
                GIMP_PAINT_OPTIONS_CONTEXT_MASK |
                GIMP_CONTEXT_GRADIENT_MASK,
                "gimp-airbrush-tool",
                _("Airbrush"),
                _("Airbrush Tool: Paint using a brush, with variable pressure"),
                N_("_Airbrush"), "A",
                NULL, GIMP_HELP_TOOL_AIRBRUSH,
                GIMP_STOCK_TOOL_AIRBRUSH,
                data);
}

static void
gimp_airbrush_tool_class_init (GimpAirbrushToolClass *klass)
{
}

static void
gimp_airbrush_tool_init (GimpAirbrushTool *airbrush)
{
  GimpTool *tool = GIMP_TOOL (airbrush);

  gimp_tool_control_set_tool_cursor (tool->control, GIMP_TOOL_CURSOR_AIRBRUSH);
}


/*  tool options stuff  */

static GtkWidget *
gimp_airbrush_options_gui (GimpToolOptions *tool_options)
{
  GObject   *config = G_OBJECT (tool_options);
  GtkWidget *vbox   = gimp_paint_options_gui (tool_options);
  GtkWidget *button;
  GtkWidget *scale;

  button = gimp_prop_check_button_new (config, "motion-only", _("Motion only"));
  gtk_box_pack_start (GTK_BOX (vbox), button, FALSE, FALSE, 0);
  gtk_widget_show (button);

  scale = gimp_prop_spin_scale_new (config, "rate",
                                    _("Rate"),
                                    1.0, 10.0, 1);
  gtk_box_pack_start (GTK_BOX (vbox), scale, FALSE, FALSE, 0);
  gtk_widget_show (scale);

  scale = gimp_prop_spin_scale_new (config, "flow",
                                    _("Flow"),
                                    1.0, 10.0, 1);
  gtk_box_pack_start (GTK_BOX (vbox), scale, FALSE, FALSE, 0);
  gtk_widget_show (scale);

  return vbox;
}
