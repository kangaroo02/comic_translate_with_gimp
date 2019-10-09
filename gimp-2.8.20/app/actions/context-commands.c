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

#include <string.h>

#include <gtk/gtk.h>

#include "libgimpbase/gimpbase.h"
#include "libgimpcolor/gimpcolor.h"
#include "libgimpwidgets/gimpwidgets.h"

#include "actions-types.h"

#include "core/gimp.h"
#include "core/gimpbrushgenerated.h"
#include "core/gimpcontext.h"
#include "core/gimpdatafactory.h"
#include "core/gimplist.h"
#include "core/gimptoolinfo.h"

#include "paint/gimppaintoptions.h"

#include "widgets/gimpdialogfactory.h"
#include "widgets/gimpsessioninfo.h"
#include "widgets/gimppaletteeditor.h"
#include "widgets/gimpcolormapeditor.h"

#include "actions.h"
#include "context-commands.h"

#include "gimp-intl.h"


static const GimpLayerModeEffects paint_modes[] =
{
  GIMP_NORMAL_MODE,
  GIMP_DISSOLVE_MODE,
  GIMP_BEHIND_MODE,
  GIMP_COLOR_ERASE_MODE,
  GIMP_MULTIPLY_MODE,
  GIMP_DIVIDE_MODE,
  GIMP_SCREEN_MODE,
  GIMP_OVERLAY_MODE,
  GIMP_DODGE_MODE,
  GIMP_BURN_MODE,
  GIMP_HARDLIGHT_MODE,
  GIMP_SOFTLIGHT_MODE,
  GIMP_GRAIN_EXTRACT_MODE,
  GIMP_GRAIN_MERGE_MODE,
  GIMP_DIFFERENCE_MODE,
  GIMP_ADDITION_MODE,
  GIMP_SUBTRACT_MODE,
  GIMP_DARKEN_ONLY_MODE,
  GIMP_LIGHTEN_ONLY_MODE,
  GIMP_HUE_MODE,
  GIMP_SATURATION_MODE,
  GIMP_COLOR_MODE,
  GIMP_VALUE_MODE
};


/*  local function prototypes  */

static void     context_select_object    (GimpActionSelectType  select_type,
                                          GimpContext          *context,
                                          GimpContainer        *container);
static gint     context_paint_mode_index (GimpLayerModeEffects  paint_mode);

static void     context_select_color     (GimpActionSelectType  select_type,
                                          GimpRGB              *color,
                                          gboolean              use_colormap,
                                          gboolean              use_palette);

static gint     context_get_color_index  (gboolean              use_colormap,
                                          gboolean              use_palette,
                                          const GimpRGB        *color);
static gint     context_max_color_index  (gboolean              use_colormap,
                                          gboolean              use_palette);
static gboolean context_set_color_index  (gint                  index,
                                          gboolean              use_colormap,
                                          gboolean              use_palette,
                                          GimpRGB              *color);

static GimpPaletteEditor  * context_get_palette_editor  (void);
static GimpColormapEditor * context_get_colormap_editor (void);


/*  public functions  */

void
context_colors_default_cmd_callback (GtkAction *action,
                                     gpointer   data)
{
  GimpContext *context;
  return_if_no_context (context, data);

  gimp_context_set_default_colors (context);
}

void
context_colors_swap_cmd_callback (GtkAction *action,
                                  gpointer   data)
{
  GimpContext *context;
  return_if_no_context (context, data);

  gimp_context_swap_colors (context);
}

#define SELECT_COLOR_CMD_CALLBACK(name, fgbg, use_colormap, use_palette) \
void \
context_##name##_##fgbg##ground_cmd_callback (GtkAction *action, \
                                              gint       value, \
                                              gpointer   data) \
{ \
  GimpContext *context; \
  GimpRGB      color; \
  return_if_no_context (context, data); \
\
  gimp_context_get_##fgbg##ground (context, &color); \
  context_select_color ((GimpActionSelectType) value, &color, \
                        use_colormap, use_palette); \
  gimp_context_set_##fgbg##ground (context, &color); \
}

SELECT_COLOR_CMD_CALLBACK (palette,  fore, FALSE, TRUE)
SELECT_COLOR_CMD_CALLBACK (palette,  back, FALSE, TRUE)
SELECT_COLOR_CMD_CALLBACK (colormap, fore, TRUE,  FALSE)
SELECT_COLOR_CMD_CALLBACK (colormap, back, TRUE,  FALSE)
SELECT_COLOR_CMD_CALLBACK (swatch,   fore, TRUE,  TRUE)
SELECT_COLOR_CMD_CALLBACK (swatch,   back, TRUE,  TRUE)

void
context_foreground_red_cmd_callback (GtkAction *action,
                                     gint       value,
                                     gpointer   data)
{
  GimpContext *context;
  GimpRGB      color;
  return_if_no_context (context, data);

  gimp_context_get_foreground (context, &color);
  color.r = action_select_value ((GimpActionSelectType) value,
                                 color.r,
                                 0.0, 1.0, 1.0,
                                 1.0 / 255.0, 0.01, 0.1, 0.0, FALSE);
  gimp_context_set_foreground (context, &color);
}

void
context_foreground_green_cmd_callback (GtkAction *action,
                                       gint       value,
                                       gpointer   data)
{
  GimpContext *context;
  GimpRGB      color;
  return_if_no_context (context, data);

  gimp_context_get_foreground (context, &color);
  color.g = action_select_value ((GimpActionSelectType) value,
                                 color.g,
                                 0.0, 1.0, 1.0,
                                 1.0 / 255.0, 0.01, 0.1, 0.0, FALSE);
  gimp_context_set_foreground (context, &color);
}

void
context_foreground_blue_cmd_callback (GtkAction *action,
                                      gint       value,
                                      gpointer   data)
{
  GimpContext *context;
  GimpRGB      color;
  return_if_no_context (context, data);

  gimp_context_get_foreground (context, &color);
  color.b = action_select_value ((GimpActionSelectType) value,
                                 color.b,
                                 0.0, 1.0, 1.0,
                                 1.0 / 255.0, 0.01, 0.1, 0.0, FALSE);
  gimp_context_set_foreground (context, &color);
}

void
context_background_red_cmd_callback (GtkAction *action,
                                     gint       value,
                                     gpointer   data)
{
  GimpContext *context;
  GimpRGB      color;
  return_if_no_context (context, data);

  gimp_context_get_background (context, &color);
  color.r = action_select_value ((GimpActionSelectType) value,
                                 color.r,
                                 0.0, 1.0, 1.0,
                                 1.0 / 255.0, 0.01, 0.1, 0.0, FALSE);
  gimp_context_set_background (context, &color);
}

void
context_background_green_cmd_callback (GtkAction *action,
                                       gint       value,
                                       gpointer   data)
{
  GimpContext *context;
  GimpRGB      color;
  return_if_no_context (context, data);

  gimp_context_get_background (context, &color);
  color.g = action_select_value ((GimpActionSelectType) value,
                                 color.g,
                                 0.0, 1.0, 1.0,
                                 1.0 / 255.0, 0.01, 0.1, 0.0, FALSE);
  gimp_context_set_background (context, &color);
}

void
context_background_blue_cmd_callback (GtkAction *action,
                                      gint       value,
                                      gpointer   data)
{
  GimpContext *context;
  GimpRGB      color;
  return_if_no_context (context, data);

  gimp_context_get_background (context, &color);
  color.b = action_select_value ((GimpActionSelectType) value,
                                 color.b,
                                 0.0, 1.0, 1.0,
                                 1.0 / 255.0, 0.01, 0.1, 0.0, FALSE);
  gimp_context_set_background (context, &color);
}

void
context_foreground_hue_cmd_callback (GtkAction *action,
                                     gint       value,
                                     gpointer   data)
{
  GimpContext *context;
  GimpRGB      color;
  GimpHSV      hsv;
  return_if_no_context (context, data);

  gimp_context_get_foreground (context, &color);
  gimp_rgb_to_hsv (&color, &hsv);
  hsv.h = action_select_value ((GimpActionSelectType) value,
                               hsv.h,
                               0.0, 1.0, 1.0,
                               1.0 / 360.0, 0.01, 0.1, 0.0, FALSE);
  gimp_hsv_to_rgb (&hsv, &color);
  gimp_context_set_foreground (context, &color);
}

void
context_foreground_saturation_cmd_callback (GtkAction *action,
                                            gint       value,
                                            gpointer   data)
{
  GimpContext *context;
  GimpRGB      color;
  GimpHSV      hsv;
  return_if_no_context (context, data);

  gimp_context_get_foreground (context, &color);
  gimp_rgb_to_hsv (&color, &hsv);
  hsv.s = action_select_value ((GimpActionSelectType) value,
                               hsv.s,
                               0.0, 1.0, 1.0,
                               0.01, 0.01, 0.1, 0.0, FALSE);
  gimp_hsv_to_rgb (&hsv, &color);
  gimp_context_set_foreground (context, &color);
}

void
context_foreground_value_cmd_callback (GtkAction *action,
                                       gint       value,
                                       gpointer   data)
{
  GimpContext *context;
  GimpRGB      color;
  GimpHSV      hsv;
  return_if_no_context (context, data);

  gimp_context_get_foreground (context, &color);
  gimp_rgb_to_hsv (&color, &hsv);
  hsv.v = action_select_value ((GimpActionSelectType) value,
                               hsv.v,
                               0.0, 1.0, 1.0,
                               0.01, 0.01, 0.1, 0.0, FALSE);
  gimp_hsv_to_rgb (&hsv, &color);
  gimp_context_set_foreground (context, &color);
}

void
context_background_hue_cmd_callback (GtkAction *action,
                                     gint       value,
                                     gpointer   data)
{
  GimpContext *context;
  GimpRGB      color;
  GimpHSV      hsv;
  return_if_no_context (context, data);

  gimp_context_get_background (context, &color);
  gimp_rgb_to_hsv (&color, &hsv);
  hsv.h = action_select_value ((GimpActionSelectType) value,
                               hsv.h,
                               0.0, 1.0, 1.0,
                               1.0 / 360.0, 0.01, 0.1, 0.0, FALSE);
  gimp_hsv_to_rgb (&hsv, &color);
  gimp_context_set_background (context, &color);
}

void
context_background_saturation_cmd_callback (GtkAction *action,
                                            gint       value,
                                            gpointer   data)
{
  GimpContext *context;
  GimpRGB      color;
  GimpHSV      hsv;
  return_if_no_context (context, data);

  gimp_context_get_background (context, &color);
  gimp_rgb_to_hsv (&color, &hsv);
  hsv.s = action_select_value ((GimpActionSelectType) value,
                               hsv.s,
                               0.0, 1.0, 1.0,
                               0.01, 0.01, 0.1, 0.0, FALSE);
  gimp_hsv_to_rgb (&hsv, &color);
  gimp_context_set_background (context, &color);
}

void
context_background_value_cmd_callback (GtkAction *action,
                                       gint       value,
                                       gpointer   data)
{
  GimpContext *context;
  GimpRGB      color;
  GimpHSV      hsv;
  return_if_no_context (context, data);

  gimp_context_get_background (context, &color);
  gimp_rgb_to_hsv (&color, &hsv);
  hsv.v = action_select_value ((GimpActionSelectType) value,
                               hsv.v,
                               0.0, 1.0, 1.0,
                               0.01, 0.01, 0.1, 0.0, FALSE);
  gimp_hsv_to_rgb (&hsv, &color);
  gimp_context_set_background (context, &color);
}

void
context_opacity_cmd_callback (GtkAction *action,
                              gint       value,
                              gpointer   data)
{
  GimpContext  *context;
  GimpToolInfo *tool_info;
  return_if_no_context (context, data);

  tool_info = gimp_context_get_tool (context);

  if (tool_info && GIMP_IS_TOOL_OPTIONS (tool_info->tool_options))
    {
      action_select_property ((GimpActionSelectType) value,
                              action_data_get_display (data),
                              G_OBJECT (tool_info->tool_options),
                              "opacity",
                              1.0 / 255.0, 0.01, 0.1, 0.1, FALSE);
    }
}

void
context_paint_mode_cmd_callback (GtkAction *action,
                                 gint       value,
                                 gpointer   data)
{
  GimpContext          *context;
  GimpToolInfo         *tool_info;
  GimpLayerModeEffects  paint_mode;
  gint                  index;
  return_if_no_context (context, data);

  paint_mode = gimp_context_get_paint_mode (context);

  index = action_select_value ((GimpActionSelectType) value,
                               context_paint_mode_index (paint_mode),
                               0, G_N_ELEMENTS (paint_modes) - 1, 0,
                               0.0, 1.0, 1.0, 0.0, FALSE);
  gimp_context_set_paint_mode (context, paint_modes[index]);

  tool_info = gimp_context_get_tool (context);

  if (tool_info && GIMP_IS_TOOL_OPTIONS (tool_info->tool_options))
    {
      GimpDisplay *display;
      const char  *value_desc;

      gimp_enum_get_value (GIMP_TYPE_LAYER_MODE_EFFECTS, index,
                           NULL, NULL, &value_desc, NULL);

      display = action_data_get_display (data);

      if (value_desc && display)
        {
          action_message (display, G_OBJECT (tool_info->tool_options),
                          _("Paint Mode: %s"), value_desc);
        }
    }
}

void
context_tool_select_cmd_callback (GtkAction *action,
                                  gint       value,
                                  gpointer   data)
{
  GimpContext *context;
  return_if_no_context (context, data);

  context_select_object ((GimpActionSelectType) value,
                         context, context->gimp->tool_info_list);
}

void
context_brush_select_cmd_callback (GtkAction *action,
                                   gint       value,
                                   gpointer   data)
{
  GimpContext *context;
  return_if_no_context (context, data);

  context_select_object ((GimpActionSelectType) value,
                         context, gimp_data_factory_get_container (context->gimp->brush_factory));
}

void
context_pattern_select_cmd_callback (GtkAction *action,
                                     gint       value,
                                     gpointer   data)
{
  GimpContext *context;
  return_if_no_context (context, data);

  context_select_object ((GimpActionSelectType) value,
                         context, gimp_data_factory_get_container (context->gimp->pattern_factory));
}

void
context_palette_select_cmd_callback (GtkAction *action,
                                     gint       value,
                                     gpointer   data)
{
  GimpContext *context;
  return_if_no_context (context, data);

  context_select_object ((GimpActionSelectType) value,
                         context, gimp_data_factory_get_container (context->gimp->palette_factory));
}

void
context_gradient_select_cmd_callback (GtkAction *action,
                                      gint       value,
                                      gpointer   data)
{
  GimpContext *context;
  return_if_no_context (context, data);

  context_select_object ((GimpActionSelectType) value,
                         context, gimp_data_factory_get_container (context->gimp->gradient_factory));
}

void
context_font_select_cmd_callback (GtkAction *action,
                                  gint       value,
                                  gpointer   data)
{
  GimpContext *context;
  return_if_no_context (context, data);

  context_select_object ((GimpActionSelectType) value,
                         context, context->gimp->fonts);
}

void
context_brush_spacing_cmd_callback (GtkAction *action,
                                    gint       value,
                                    gpointer   data)
{
  GimpContext *context;
  GimpBrush   *brush;
  return_if_no_context (context, data);

  brush = gimp_context_get_brush (context);

  if (GIMP_IS_BRUSH (brush) && gimp_data_is_writable (GIMP_DATA (brush)))
    {
      action_select_property ((GimpActionSelectType) value,
                              action_data_get_display (data),
                              G_OBJECT (brush),
                              "spacing",
                              1.0, 5.0, 20.0, 0.1, FALSE);
    }
}

void
context_brush_shape_cmd_callback (GtkAction *action,
                                  gint       value,
                                  gpointer   data)
{
  GimpContext *context;
  GimpBrush   *brush;
  return_if_no_context (context, data);

  brush = gimp_context_get_brush (context);

  if (GIMP_IS_BRUSH_GENERATED (brush) &&
      gimp_data_is_writable (GIMP_DATA (brush)))
    {
      GimpBrushGenerated *generated = GIMP_BRUSH_GENERATED (brush);
      GimpDisplay        *display;
      const char         *value_desc;

      gimp_brush_generated_set_shape (generated,
                                      (GimpBrushGeneratedShape) value);

      gimp_enum_get_value (GIMP_TYPE_BRUSH_GENERATED_SHAPE, value,
                           NULL, NULL, &value_desc, NULL);
      display = action_data_get_display (data);

      if (value_desc && display)
        {
          action_message (display, G_OBJECT (brush),
                          _("Brush Shape: %s"), value_desc);
        }
    }
}

void
context_brush_radius_cmd_callback (GtkAction *action,
                                   gint       value,
                                   gpointer   data)
{
  GimpContext *context;
  GimpBrush   *brush;
  return_if_no_context (context, data);

  brush = gimp_context_get_brush (context);

  if (GIMP_IS_BRUSH_GENERATED (brush) &&
      gimp_data_is_writable (GIMP_DATA (brush)))
    {
      GimpBrushGenerated *generated = GIMP_BRUSH_GENERATED (brush);
      GimpDisplay        *display;
      gdouble             radius;
      gdouble             min_radius;

      radius = gimp_brush_generated_get_radius (generated);

      /* If the user uses a high precision radius adjustment command
       * then we allow a minimum radius of 0.1 px, otherwise we set the
       * minimum radius to 1.0 px and adjust the radius to 1.0 px if it
       * is less than 1.0 px. This prevents irritating 0.1, 1.1, 2.1 etc
       * radius sequences when 1.0 px steps are used.
       */
      switch ((GimpActionSelectType) value)
        {
        case GIMP_ACTION_SELECT_SMALL_PREVIOUS:
        case GIMP_ACTION_SELECT_SMALL_NEXT:
        case GIMP_ACTION_SELECT_PERCENT_PREVIOUS:
        case GIMP_ACTION_SELECT_PERCENT_NEXT:
          min_radius = 0.1;
          break;

        default:
          min_radius = 1.0;

          if (radius < 1.0)
            radius = 1.0;
          break;
        }

      radius = action_select_value ((GimpActionSelectType) value,
                                    radius,
                                    min_radius, 4000.0, min_radius,
                                    0.1, 1.0, 10.0, 0.05, FALSE);
      gimp_brush_generated_set_radius (generated, radius);

      display = action_data_get_display (data);

      if (display)
        {
          action_message (action_data_get_display (data), G_OBJECT (brush),
                          _("Brush Radius: %2.2f"), radius);
        }
    }
}

void
context_brush_spikes_cmd_callback (GtkAction *action,
                                   gint       value,
                                   gpointer   data)
{
  GimpContext *context;
  GimpBrush   *brush;
  return_if_no_context (context, data);

  brush = gimp_context_get_brush (context);

  if (GIMP_IS_BRUSH_GENERATED (brush) &&
      gimp_data_is_writable (GIMP_DATA (brush)))
    {
      action_select_property ((GimpActionSelectType) value,
                              action_data_get_display (data),
                              G_OBJECT (brush),
                              "spikes",
                              0.0, 1.0, 4.0, 0.1, FALSE);
    }
}

void
context_brush_hardness_cmd_callback (GtkAction *action,
                                     gint       value,
                                     gpointer   data)
{
  GimpContext *context;
  GimpBrush   *brush;
  return_if_no_context (context, data);

  brush = gimp_context_get_brush (context);

  if (GIMP_IS_BRUSH_GENERATED (brush) &&
      gimp_data_is_writable (GIMP_DATA (brush)))
    {
      action_select_property ((GimpActionSelectType) value,
                              action_data_get_display (data),
                              G_OBJECT (brush),
                              "hardness",
                              0.001, 0.01, 0.1, 0.1, FALSE);
    }
}

void
context_brush_aspect_cmd_callback (GtkAction *action,
                                   gint       value,
                                   gpointer   data)
{
  GimpContext *context;
  GimpBrush   *brush;
  return_if_no_context (context, data);

  brush = gimp_context_get_brush (context);

  if (GIMP_IS_BRUSH_GENERATED (brush) &&
      gimp_data_is_writable (GIMP_DATA (brush)))
    {
      action_select_property ((GimpActionSelectType) value,
                              action_data_get_display (data),
                              G_OBJECT (brush),
                              "aspect-ratio",
                              0.1, 1.0, 4.0, 0.1, FALSE);
    }
}

void
context_brush_angle_cmd_callback (GtkAction *action,
                                  gint       value,
                                  gpointer   data)
{
  GimpContext *context;
  GimpBrush   *brush;
  return_if_no_context (context, data);

  brush = gimp_context_get_brush (context);

  if (GIMP_IS_BRUSH_GENERATED (brush) &&
      gimp_data_is_writable (GIMP_DATA (brush)))
    {
      GimpBrushGenerated *generated = GIMP_BRUSH_GENERATED (brush);
      GimpDisplay        *display;
      gdouble             angle;

      angle = gimp_brush_generated_get_angle (generated);

      if (value == GIMP_ACTION_SELECT_FIRST)
        angle = 0.0;
      else if (value == GIMP_ACTION_SELECT_LAST)
        angle = 90.0;
      else
        angle = action_select_value ((GimpActionSelectType) value,
                                     angle,
                                     0.0, 180.0, 0.0,
                                     0.1, 1.0, 15.0, 0.1, TRUE);

      gimp_brush_generated_set_angle (generated, angle);

      display = action_data_get_display (data);

      if (display)
        {
          action_message (action_data_get_display (data), G_OBJECT (brush),
                          _("Brush Angle: %2.2f"), angle);
        }
    }
}


/*  private functions  */

static void
context_select_object (GimpActionSelectType  select_type,
                       GimpContext          *context,
                       GimpContainer        *container)
{
  GimpObject *current;

  current = gimp_context_get_by_type (context,
                                      gimp_container_get_children_type (container));

  current = action_select_object (select_type, container, current);

  if (current)
    gimp_context_set_by_type (context,
                              gimp_container_get_children_type (container), current);
}

static gint
context_paint_mode_index (GimpLayerModeEffects paint_mode)
{
  gint i = 0;

  while (i < (G_N_ELEMENTS (paint_modes) - 1) && paint_modes[i] != paint_mode)
    i++;

  return i;
}

static void
context_select_color (GimpActionSelectType  select_type,
                      GimpRGB              *color,
                      gboolean              use_colormap,
                      gboolean              use_palette)
{
  gint index;
  gint max;

  index = context_get_color_index (use_colormap, use_palette, color);
  max   = context_max_color_index (use_colormap, use_palette);

  index = action_select_value (select_type,
                               index,
                               0, max, 0,
                               0, 1, 4, 0, FALSE);

  context_set_color_index (index, use_colormap, use_palette, color);
}

static gint
context_get_color_index (gboolean       use_colormap,
                         gboolean       use_palette,
                         const GimpRGB *color)
{
  if (use_colormap)
    {
      GimpColormapEditor *editor = context_get_colormap_editor ();

      if (editor)
        {
          gint index = gimp_colormap_editor_get_index (editor, color);

          if (index != -1)
            return index;
        }
    }

  if (use_palette)
    {
      GimpPaletteEditor *editor = context_get_palette_editor ();

      if (editor)
        {
          gint index = gimp_palette_editor_get_index (editor, color);

          if (index != -1)
            return index;
        }
    }

  return 0;
}

static gint
context_max_color_index (gboolean use_colormap,
                         gboolean use_palette)
{
  if (use_colormap)
    {
      GimpColormapEditor *editor = context_get_colormap_editor ();

      if (editor)
        {
          gint index = gimp_colormap_editor_max_index (editor);

          if (index != -1)
            return index;
        }
    }

  if (use_palette)
    {
      GimpPaletteEditor *editor = context_get_palette_editor ();

      if (editor)
        {
          gint index = gimp_palette_editor_max_index (editor);

          if (index != -1)
            return index;
        }
    }

  return 0;
}

static gboolean
context_set_color_index (gint      index,
                         gboolean  use_colormap,
                         gboolean  use_palette,
                         GimpRGB  *color)
{
  if (use_colormap)
    {
      GimpColormapEditor *editor = context_get_colormap_editor ();

      if (editor && gimp_colormap_editor_set_index (editor, index, color))
        return TRUE;
    }

  if (use_palette)
    {
      GimpPaletteEditor *editor = context_get_palette_editor ();

      if (editor && gimp_palette_editor_set_index (editor, index, color))
        return TRUE;
    }

  return FALSE;
}

static GimpPaletteEditor *
context_get_palette_editor (void)
{
  GtkWidget *widget;

  g_return_val_if_fail (GIMP_IS_DIALOG_FACTORY (gimp_dialog_factory_get_singleton ()), NULL);

  widget = gimp_dialog_factory_find_widget (gimp_dialog_factory_get_singleton (),
                                            "gimp-palette-editor");
  if (widget)
    return GIMP_PALETTE_EDITOR (gtk_bin_get_child (GTK_BIN (widget)));

  return NULL;
}

static GimpColormapEditor *
context_get_colormap_editor (void)
{
  GtkWidget *widget;

  g_return_val_if_fail (GIMP_IS_DIALOG_FACTORY (gimp_dialog_factory_get_singleton ()), NULL);

  widget = gimp_dialog_factory_find_widget (gimp_dialog_factory_get_singleton (),
                                            "gimp-indexed-palette");
  if (widget)
    return GIMP_COLORMAP_EDITOR (gtk_bin_get_child (GTK_BIN (widget)));

  return NULL;
}
