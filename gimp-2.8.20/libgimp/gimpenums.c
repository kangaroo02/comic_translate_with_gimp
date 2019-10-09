
/* Generated data (by gimp-mkenums) */

#include "config.h"
#include <glib-object.h>
#undef GIMP_DISABLE_DEPRECATED
#include "libgimpbase/gimpbase.h"
#include "gimpenums.h"

/* enumerations from "./gimpenums.h" */
GType
gimp_brush_application_mode_get_type (void)
{
  static const GEnumValue values[] =
  {
    { GIMP_BRUSH_HARD, "GIMP_BRUSH_HARD", "hard" },
    { GIMP_BRUSH_SOFT, "GIMP_BRUSH_SOFT", "soft" },
    { 0, NULL, NULL }
  };

  static const GimpEnumDesc descs[] =
  {
    { GIMP_BRUSH_HARD, "GIMP_BRUSH_HARD", NULL },
    { GIMP_BRUSH_SOFT, "GIMP_BRUSH_SOFT", NULL },
    { 0, NULL, NULL }
  };

  static GType type = 0;

  if (G_UNLIKELY (! type))
    {
      type = g_enum_register_static ("GimpBrushApplicationMode", values);
      gimp_type_set_translation_domain (type, GETTEXT_PACKAGE "-libgimp");
      gimp_type_set_translation_context (type, "brush-application-mode");
      gimp_enum_set_value_descriptions (type, descs);
    }

  return type;
}

GType
gimp_brush_generated_shape_get_type (void)
{
  static const GEnumValue values[] =
  {
    { GIMP_BRUSH_GENERATED_CIRCLE, "GIMP_BRUSH_GENERATED_CIRCLE", "circle" },
    { GIMP_BRUSH_GENERATED_SQUARE, "GIMP_BRUSH_GENERATED_SQUARE", "square" },
    { GIMP_BRUSH_GENERATED_DIAMOND, "GIMP_BRUSH_GENERATED_DIAMOND", "diamond" },
    { 0, NULL, NULL }
  };

  static const GimpEnumDesc descs[] =
  {
    { GIMP_BRUSH_GENERATED_CIRCLE, "GIMP_BRUSH_GENERATED_CIRCLE", NULL },
    { GIMP_BRUSH_GENERATED_SQUARE, "GIMP_BRUSH_GENERATED_SQUARE", NULL },
    { GIMP_BRUSH_GENERATED_DIAMOND, "GIMP_BRUSH_GENERATED_DIAMOND", NULL },
    { 0, NULL, NULL }
  };

  static GType type = 0;

  if (G_UNLIKELY (! type))
    {
      type = g_enum_register_static ("GimpBrushGeneratedShape", values);
      gimp_type_set_translation_domain (type, GETTEXT_PACKAGE "-libgimp");
      gimp_type_set_translation_context (type, "brush-generated-shape");
      gimp_enum_set_value_descriptions (type, descs);
    }

  return type;
}

GType
gimp_convert_dither_type_get_type (void)
{
  static const GEnumValue values[] =
  {
    { GIMP_NO_DITHER, "GIMP_NO_DITHER", "no-dither" },
    { GIMP_FS_DITHER, "GIMP_FS_DITHER", "fs-dither" },
    { GIMP_FSLOWBLEED_DITHER, "GIMP_FSLOWBLEED_DITHER", "fslowbleed-dither" },
    { GIMP_FIXED_DITHER, "GIMP_FIXED_DITHER", "fixed-dither" },
    { 0, NULL, NULL }
  };

  static const GimpEnumDesc descs[] =
  {
    { GIMP_NO_DITHER, "GIMP_NO_DITHER", NULL },
    { GIMP_FS_DITHER, "GIMP_FS_DITHER", NULL },
    { GIMP_FSLOWBLEED_DITHER, "GIMP_FSLOWBLEED_DITHER", NULL },
    { GIMP_FIXED_DITHER, "GIMP_FIXED_DITHER", NULL },
    { 0, NULL, NULL }
  };

  static GType type = 0;

  if (G_UNLIKELY (! type))
    {
      type = g_enum_register_static ("GimpConvertDitherType", values);
      gimp_type_set_translation_domain (type, GETTEXT_PACKAGE "-libgimp");
      gimp_type_set_translation_context (type, "convert-dither-type");
      gimp_enum_set_value_descriptions (type, descs);
    }

  return type;
}

GType
gimp_convert_palette_type_get_type (void)
{
  static const GEnumValue values[] =
  {
    { GIMP_MAKE_PALETTE, "GIMP_MAKE_PALETTE", "make-palette" },
    { GIMP_REUSE_PALETTE, "GIMP_REUSE_PALETTE", "reuse-palette" },
    { GIMP_WEB_PALETTE, "GIMP_WEB_PALETTE", "web-palette" },
    { GIMP_MONO_PALETTE, "GIMP_MONO_PALETTE", "mono-palette" },
    { GIMP_CUSTOM_PALETTE, "GIMP_CUSTOM_PALETTE", "custom-palette" },
    { 0, NULL, NULL }
  };

  static const GimpEnumDesc descs[] =
  {
    { GIMP_MAKE_PALETTE, "GIMP_MAKE_PALETTE", NULL },
    { GIMP_REUSE_PALETTE, "GIMP_REUSE_PALETTE", NULL },
    { GIMP_WEB_PALETTE, "GIMP_WEB_PALETTE", NULL },
    { GIMP_MONO_PALETTE, "GIMP_MONO_PALETTE", NULL },
    { GIMP_CUSTOM_PALETTE, "GIMP_CUSTOM_PALETTE", NULL },
    { 0, NULL, NULL }
  };

  static GType type = 0;

  if (G_UNLIKELY (! type))
    {
      type = g_enum_register_static ("GimpConvertPaletteType", values);
      gimp_type_set_translation_domain (type, GETTEXT_PACKAGE "-libgimp");
      gimp_type_set_translation_context (type, "convert-palette-type");
      gimp_enum_set_value_descriptions (type, descs);
    }

  return type;
}

GType
gimp_convolution_type_get_type (void)
{
  static const GEnumValue values[] =
  {
    { GIMP_NORMAL_CONVOL, "GIMP_NORMAL_CONVOL", "normal-convol" },
    { GIMP_ABSOLUTE_CONVOL, "GIMP_ABSOLUTE_CONVOL", "absolute-convol" },
    { GIMP_NEGATIVE_CONVOL, "GIMP_NEGATIVE_CONVOL", "negative-convol" },
    { 0, NULL, NULL }
  };

  static const GimpEnumDesc descs[] =
  {
    { GIMP_NORMAL_CONVOL, "GIMP_NORMAL_CONVOL", NULL },
    { GIMP_ABSOLUTE_CONVOL, "GIMP_ABSOLUTE_CONVOL", NULL },
    { GIMP_NEGATIVE_CONVOL, "GIMP_NEGATIVE_CONVOL", NULL },
    { 0, NULL, NULL }
  };

  static GType type = 0;

  if (G_UNLIKELY (! type))
    {
      type = g_enum_register_static ("GimpConvolutionType", values);
      gimp_type_set_translation_domain (type, GETTEXT_PACKAGE "-libgimp");
      gimp_type_set_translation_context (type, "convolution-type");
      gimp_enum_set_value_descriptions (type, descs);
    }

  return type;
}

GType
gimp_convolve_type_get_type (void)
{
  static const GEnumValue values[] =
  {
    { GIMP_BLUR_CONVOLVE, "GIMP_BLUR_CONVOLVE", "blur-convolve" },
    { GIMP_SHARPEN_CONVOLVE, "GIMP_SHARPEN_CONVOLVE", "sharpen-convolve" },
    { 0, NULL, NULL }
  };

  static const GimpEnumDesc descs[] =
  {
    { GIMP_BLUR_CONVOLVE, "GIMP_BLUR_CONVOLVE", NULL },
    { GIMP_SHARPEN_CONVOLVE, "GIMP_SHARPEN_CONVOLVE", NULL },
    { 0, NULL, NULL }
  };

  static GType type = 0;

  if (G_UNLIKELY (! type))
    {
      type = g_enum_register_static ("GimpConvolveType", values);
      gimp_type_set_translation_domain (type, GETTEXT_PACKAGE "-libgimp");
      gimp_type_set_translation_context (type, "convolve-type");
      gimp_enum_set_value_descriptions (type, descs);
    }

  return type;
}

GType
gimp_fill_type_get_type (void)
{
  static const GEnumValue values[] =
  {
    { GIMP_FOREGROUND_FILL, "GIMP_FOREGROUND_FILL", "foreground-fill" },
    { GIMP_BACKGROUND_FILL, "GIMP_BACKGROUND_FILL", "background-fill" },
    { GIMP_WHITE_FILL, "GIMP_WHITE_FILL", "white-fill" },
    { GIMP_TRANSPARENT_FILL, "GIMP_TRANSPARENT_FILL", "transparent-fill" },
    { GIMP_PATTERN_FILL, "GIMP_PATTERN_FILL", "pattern-fill" },
    { 0, NULL, NULL }
  };

  static const GimpEnumDesc descs[] =
  {
    { GIMP_FOREGROUND_FILL, "GIMP_FOREGROUND_FILL", NULL },
    { GIMP_BACKGROUND_FILL, "GIMP_BACKGROUND_FILL", NULL },
    { GIMP_WHITE_FILL, "GIMP_WHITE_FILL", NULL },
    { GIMP_TRANSPARENT_FILL, "GIMP_TRANSPARENT_FILL", NULL },
    { GIMP_PATTERN_FILL, "GIMP_PATTERN_FILL", NULL },
    { 0, NULL, NULL }
  };

  static GType type = 0;

  if (G_UNLIKELY (! type))
    {
      type = g_enum_register_static ("GimpFillType", values);
      gimp_type_set_translation_domain (type, GETTEXT_PACKAGE "-libgimp");
      gimp_type_set_translation_context (type, "fill-type");
      gimp_enum_set_value_descriptions (type, descs);
    }

  return type;
}

GType
gimp_gradient_segment_color_get_type (void)
{
  static const GEnumValue values[] =
  {
    { GIMP_GRADIENT_SEGMENT_RGB, "GIMP_GRADIENT_SEGMENT_RGB", "rgb" },
    { GIMP_GRADIENT_SEGMENT_HSV_CCW, "GIMP_GRADIENT_SEGMENT_HSV_CCW", "hsv-ccw" },
    { GIMP_GRADIENT_SEGMENT_HSV_CW, "GIMP_GRADIENT_SEGMENT_HSV_CW", "hsv-cw" },
    { 0, NULL, NULL }
  };

  static const GimpEnumDesc descs[] =
  {
    { GIMP_GRADIENT_SEGMENT_RGB, "GIMP_GRADIENT_SEGMENT_RGB", NULL },
    { GIMP_GRADIENT_SEGMENT_HSV_CCW, "GIMP_GRADIENT_SEGMENT_HSV_CCW", NULL },
    { GIMP_GRADIENT_SEGMENT_HSV_CW, "GIMP_GRADIENT_SEGMENT_HSV_CW", NULL },
    { 0, NULL, NULL }
  };

  static GType type = 0;

  if (G_UNLIKELY (! type))
    {
      type = g_enum_register_static ("GimpGradientSegmentColor", values);
      gimp_type_set_translation_domain (type, GETTEXT_PACKAGE "-libgimp");
      gimp_type_set_translation_context (type, "gradient-segment-color");
      gimp_enum_set_value_descriptions (type, descs);
    }

  return type;
}

GType
gimp_gradient_segment_type_get_type (void)
{
  static const GEnumValue values[] =
  {
    { GIMP_GRADIENT_SEGMENT_LINEAR, "GIMP_GRADIENT_SEGMENT_LINEAR", "linear" },
    { GIMP_GRADIENT_SEGMENT_CURVED, "GIMP_GRADIENT_SEGMENT_CURVED", "curved" },
    { GIMP_GRADIENT_SEGMENT_SINE, "GIMP_GRADIENT_SEGMENT_SINE", "sine" },
    { GIMP_GRADIENT_SEGMENT_SPHERE_INCREASING, "GIMP_GRADIENT_SEGMENT_SPHERE_INCREASING", "sphere-increasing" },
    { GIMP_GRADIENT_SEGMENT_SPHERE_DECREASING, "GIMP_GRADIENT_SEGMENT_SPHERE_DECREASING", "sphere-decreasing" },
    { 0, NULL, NULL }
  };

  static const GimpEnumDesc descs[] =
  {
    { GIMP_GRADIENT_SEGMENT_LINEAR, "GIMP_GRADIENT_SEGMENT_LINEAR", NULL },
    { GIMP_GRADIENT_SEGMENT_CURVED, "GIMP_GRADIENT_SEGMENT_CURVED", NULL },
    { GIMP_GRADIENT_SEGMENT_SINE, "GIMP_GRADIENT_SEGMENT_SINE", NULL },
    { GIMP_GRADIENT_SEGMENT_SPHERE_INCREASING, "GIMP_GRADIENT_SEGMENT_SPHERE_INCREASING", NULL },
    { GIMP_GRADIENT_SEGMENT_SPHERE_DECREASING, "GIMP_GRADIENT_SEGMENT_SPHERE_DECREASING", NULL },
    { 0, NULL, NULL }
  };

  static GType type = 0;

  if (G_UNLIKELY (! type))
    {
      type = g_enum_register_static ("GimpGradientSegmentType", values);
      gimp_type_set_translation_domain (type, GETTEXT_PACKAGE "-libgimp");
      gimp_type_set_translation_context (type, "gradient-segment-type");
      gimp_enum_set_value_descriptions (type, descs);
    }

  return type;
}

GType
gimp_histogram_channel_get_type (void)
{
  static const GEnumValue values[] =
  {
    { GIMP_HISTOGRAM_VALUE, "GIMP_HISTOGRAM_VALUE", "value" },
    { GIMP_HISTOGRAM_RED, "GIMP_HISTOGRAM_RED", "red" },
    { GIMP_HISTOGRAM_GREEN, "GIMP_HISTOGRAM_GREEN", "green" },
    { GIMP_HISTOGRAM_BLUE, "GIMP_HISTOGRAM_BLUE", "blue" },
    { GIMP_HISTOGRAM_ALPHA, "GIMP_HISTOGRAM_ALPHA", "alpha" },
    { 0, NULL, NULL }
  };

  static const GimpEnumDesc descs[] =
  {
    { GIMP_HISTOGRAM_VALUE, "GIMP_HISTOGRAM_VALUE", NULL },
    { GIMP_HISTOGRAM_RED, "GIMP_HISTOGRAM_RED", NULL },
    { GIMP_HISTOGRAM_GREEN, "GIMP_HISTOGRAM_GREEN", NULL },
    { GIMP_HISTOGRAM_BLUE, "GIMP_HISTOGRAM_BLUE", NULL },
    { GIMP_HISTOGRAM_ALPHA, "GIMP_HISTOGRAM_ALPHA", NULL },
    { 0, NULL, NULL }
  };

  static GType type = 0;

  if (G_UNLIKELY (! type))
    {
      type = g_enum_register_static ("GimpHistogramChannel", values);
      gimp_type_set_translation_domain (type, GETTEXT_PACKAGE "-libgimp");
      gimp_type_set_translation_context (type, "histogram-channel");
      gimp_enum_set_value_descriptions (type, descs);
    }

  return type;
}

GType
gimp_hue_range_get_type (void)
{
  static const GEnumValue values[] =
  {
    { GIMP_ALL_HUES, "GIMP_ALL_HUES", "all-hues" },
    { GIMP_RED_HUES, "GIMP_RED_HUES", "red-hues" },
    { GIMP_YELLOW_HUES, "GIMP_YELLOW_HUES", "yellow-hues" },
    { GIMP_GREEN_HUES, "GIMP_GREEN_HUES", "green-hues" },
    { GIMP_CYAN_HUES, "GIMP_CYAN_HUES", "cyan-hues" },
    { GIMP_BLUE_HUES, "GIMP_BLUE_HUES", "blue-hues" },
    { GIMP_MAGENTA_HUES, "GIMP_MAGENTA_HUES", "magenta-hues" },
    { 0, NULL, NULL }
  };

  static const GimpEnumDesc descs[] =
  {
    { GIMP_ALL_HUES, "GIMP_ALL_HUES", NULL },
    { GIMP_RED_HUES, "GIMP_RED_HUES", NULL },
    { GIMP_YELLOW_HUES, "GIMP_YELLOW_HUES", NULL },
    { GIMP_GREEN_HUES, "GIMP_GREEN_HUES", NULL },
    { GIMP_CYAN_HUES, "GIMP_CYAN_HUES", NULL },
    { GIMP_BLUE_HUES, "GIMP_BLUE_HUES", NULL },
    { GIMP_MAGENTA_HUES, "GIMP_MAGENTA_HUES", NULL },
    { 0, NULL, NULL }
  };

  static GType type = 0;

  if (G_UNLIKELY (! type))
    {
      type = g_enum_register_static ("GimpHueRange", values);
      gimp_type_set_translation_domain (type, GETTEXT_PACKAGE "-libgimp");
      gimp_type_set_translation_context (type, "hue-range");
      gimp_enum_set_value_descriptions (type, descs);
    }

  return type;
}

GType
gimp_ink_blob_type_get_type (void)
{
  static const GEnumValue values[] =
  {
    { GIMP_INK_BLOB_TYPE_CIRCLE, "GIMP_INK_BLOB_TYPE_CIRCLE", "circle" },
    { GIMP_INK_BLOB_TYPE_SQUARE, "GIMP_INK_BLOB_TYPE_SQUARE", "square" },
    { GIMP_INK_BLOB_TYPE_DIAMOND, "GIMP_INK_BLOB_TYPE_DIAMOND", "diamond" },
    { 0, NULL, NULL }
  };

  static const GimpEnumDesc descs[] =
  {
    { GIMP_INK_BLOB_TYPE_CIRCLE, "GIMP_INK_BLOB_TYPE_CIRCLE", NULL },
    { GIMP_INK_BLOB_TYPE_SQUARE, "GIMP_INK_BLOB_TYPE_SQUARE", NULL },
    { GIMP_INK_BLOB_TYPE_DIAMOND, "GIMP_INK_BLOB_TYPE_DIAMOND", NULL },
    { 0, NULL, NULL }
  };

  static GType type = 0;

  if (G_UNLIKELY (! type))
    {
      type = g_enum_register_static ("GimpInkBlobType", values);
      gimp_type_set_translation_domain (type, GETTEXT_PACKAGE "-libgimp");
      gimp_type_set_translation_context (type, "ink-blob-type");
      gimp_enum_set_value_descriptions (type, descs);
    }

  return type;
}

GType
gimp_layer_mode_effects_get_type (void)
{
  static const GEnumValue values[] =
  {
    { GIMP_NORMAL_MODE, "GIMP_NORMAL_MODE", "normal-mode" },
    { GIMP_DISSOLVE_MODE, "GIMP_DISSOLVE_MODE", "dissolve-mode" },
    { GIMP_BEHIND_MODE, "GIMP_BEHIND_MODE", "behind-mode" },
    { GIMP_MULTIPLY_MODE, "GIMP_MULTIPLY_MODE", "multiply-mode" },
    { GIMP_SCREEN_MODE, "GIMP_SCREEN_MODE", "screen-mode" },
    { GIMP_OVERLAY_MODE, "GIMP_OVERLAY_MODE", "overlay-mode" },
    { GIMP_DIFFERENCE_MODE, "GIMP_DIFFERENCE_MODE", "difference-mode" },
    { GIMP_ADDITION_MODE, "GIMP_ADDITION_MODE", "addition-mode" },
    { GIMP_SUBTRACT_MODE, "GIMP_SUBTRACT_MODE", "subtract-mode" },
    { GIMP_DARKEN_ONLY_MODE, "GIMP_DARKEN_ONLY_MODE", "darken-only-mode" },
    { GIMP_LIGHTEN_ONLY_MODE, "GIMP_LIGHTEN_ONLY_MODE", "lighten-only-mode" },
    { GIMP_HUE_MODE, "GIMP_HUE_MODE", "hue-mode" },
    { GIMP_SATURATION_MODE, "GIMP_SATURATION_MODE", "saturation-mode" },
    { GIMP_COLOR_MODE, "GIMP_COLOR_MODE", "color-mode" },
    { GIMP_VALUE_MODE, "GIMP_VALUE_MODE", "value-mode" },
    { GIMP_DIVIDE_MODE, "GIMP_DIVIDE_MODE", "divide-mode" },
    { GIMP_DODGE_MODE, "GIMP_DODGE_MODE", "dodge-mode" },
    { GIMP_BURN_MODE, "GIMP_BURN_MODE", "burn-mode" },
    { GIMP_HARDLIGHT_MODE, "GIMP_HARDLIGHT_MODE", "hardlight-mode" },
    { GIMP_SOFTLIGHT_MODE, "GIMP_SOFTLIGHT_MODE", "softlight-mode" },
    { GIMP_GRAIN_EXTRACT_MODE, "GIMP_GRAIN_EXTRACT_MODE", "grain-extract-mode" },
    { GIMP_GRAIN_MERGE_MODE, "GIMP_GRAIN_MERGE_MODE", "grain-merge-mode" },
    { GIMP_COLOR_ERASE_MODE, "GIMP_COLOR_ERASE_MODE", "color-erase-mode" },
    { 0, NULL, NULL }
  };

  static const GimpEnumDesc descs[] =
  {
    { GIMP_NORMAL_MODE, "GIMP_NORMAL_MODE", NULL },
    { GIMP_DISSOLVE_MODE, "GIMP_DISSOLVE_MODE", NULL },
    { GIMP_BEHIND_MODE, "GIMP_BEHIND_MODE", NULL },
    { GIMP_MULTIPLY_MODE, "GIMP_MULTIPLY_MODE", NULL },
    { GIMP_SCREEN_MODE, "GIMP_SCREEN_MODE", NULL },
    { GIMP_OVERLAY_MODE, "GIMP_OVERLAY_MODE", NULL },
    { GIMP_DIFFERENCE_MODE, "GIMP_DIFFERENCE_MODE", NULL },
    { GIMP_ADDITION_MODE, "GIMP_ADDITION_MODE", NULL },
    { GIMP_SUBTRACT_MODE, "GIMP_SUBTRACT_MODE", NULL },
    { GIMP_DARKEN_ONLY_MODE, "GIMP_DARKEN_ONLY_MODE", NULL },
    { GIMP_LIGHTEN_ONLY_MODE, "GIMP_LIGHTEN_ONLY_MODE", NULL },
    { GIMP_HUE_MODE, "GIMP_HUE_MODE", NULL },
    { GIMP_SATURATION_MODE, "GIMP_SATURATION_MODE", NULL },
    { GIMP_COLOR_MODE, "GIMP_COLOR_MODE", NULL },
    { GIMP_VALUE_MODE, "GIMP_VALUE_MODE", NULL },
    { GIMP_DIVIDE_MODE, "GIMP_DIVIDE_MODE", NULL },
    { GIMP_DODGE_MODE, "GIMP_DODGE_MODE", NULL },
    { GIMP_BURN_MODE, "GIMP_BURN_MODE", NULL },
    { GIMP_HARDLIGHT_MODE, "GIMP_HARDLIGHT_MODE", NULL },
    { GIMP_SOFTLIGHT_MODE, "GIMP_SOFTLIGHT_MODE", NULL },
    { GIMP_GRAIN_EXTRACT_MODE, "GIMP_GRAIN_EXTRACT_MODE", NULL },
    { GIMP_GRAIN_MERGE_MODE, "GIMP_GRAIN_MERGE_MODE", NULL },
    { GIMP_COLOR_ERASE_MODE, "GIMP_COLOR_ERASE_MODE", NULL },
    { 0, NULL, NULL }
  };

  static GType type = 0;

  if (G_UNLIKELY (! type))
    {
      type = g_enum_register_static ("GimpLayerModeEffects", values);
      gimp_type_set_translation_domain (type, GETTEXT_PACKAGE "-libgimp");
      gimp_type_set_translation_context (type, "layer-mode-effects");
      gimp_enum_set_value_descriptions (type, descs);
    }

  return type;
}

GType
gimp_mask_apply_mode_get_type (void)
{
  static const GEnumValue values[] =
  {
    { GIMP_MASK_APPLY, "GIMP_MASK_APPLY", "apply" },
    { GIMP_MASK_DISCARD, "GIMP_MASK_DISCARD", "discard" },
    { 0, NULL, NULL }
  };

  static const GimpEnumDesc descs[] =
  {
    { GIMP_MASK_APPLY, "GIMP_MASK_APPLY", NULL },
    { GIMP_MASK_DISCARD, "GIMP_MASK_DISCARD", NULL },
    { 0, NULL, NULL }
  };

  static GType type = 0;

  if (G_UNLIKELY (! type))
    {
      type = g_enum_register_static ("GimpMaskApplyMode", values);
      gimp_type_set_translation_domain (type, GETTEXT_PACKAGE "-libgimp");
      gimp_type_set_translation_context (type, "mask-apply-mode");
      gimp_enum_set_value_descriptions (type, descs);
    }

  return type;
}

GType
gimp_merge_type_get_type (void)
{
  static const GEnumValue values[] =
  {
    { GIMP_EXPAND_AS_NECESSARY, "GIMP_EXPAND_AS_NECESSARY", "expand-as-necessary" },
    { GIMP_CLIP_TO_IMAGE, "GIMP_CLIP_TO_IMAGE", "clip-to-image" },
    { GIMP_CLIP_TO_BOTTOM_LAYER, "GIMP_CLIP_TO_BOTTOM_LAYER", "clip-to-bottom-layer" },
    { GIMP_FLATTEN_IMAGE, "GIMP_FLATTEN_IMAGE", "flatten-image" },
    { 0, NULL, NULL }
  };

  static const GimpEnumDesc descs[] =
  {
    { GIMP_EXPAND_AS_NECESSARY, "GIMP_EXPAND_AS_NECESSARY", NULL },
    { GIMP_CLIP_TO_IMAGE, "GIMP_CLIP_TO_IMAGE", NULL },
    { GIMP_CLIP_TO_BOTTOM_LAYER, "GIMP_CLIP_TO_BOTTOM_LAYER", NULL },
    { GIMP_FLATTEN_IMAGE, "GIMP_FLATTEN_IMAGE", NULL },
    { 0, NULL, NULL }
  };

  static GType type = 0;

  if (G_UNLIKELY (! type))
    {
      type = g_enum_register_static ("GimpMergeType", values);
      gimp_type_set_translation_domain (type, GETTEXT_PACKAGE "-libgimp");
      gimp_type_set_translation_context (type, "merge-type");
      gimp_enum_set_value_descriptions (type, descs);
    }

  return type;
}

GType
gimp_offset_type_get_type (void)
{
  static const GEnumValue values[] =
  {
    { GIMP_OFFSET_BACKGROUND, "GIMP_OFFSET_BACKGROUND", "background" },
    { GIMP_OFFSET_TRANSPARENT, "GIMP_OFFSET_TRANSPARENT", "transparent" },
    { 0, NULL, NULL }
  };

  static const GimpEnumDesc descs[] =
  {
    { GIMP_OFFSET_BACKGROUND, "GIMP_OFFSET_BACKGROUND", NULL },
    { GIMP_OFFSET_TRANSPARENT, "GIMP_OFFSET_TRANSPARENT", NULL },
    { 0, NULL, NULL }
  };

  static GType type = 0;

  if (G_UNLIKELY (! type))
    {
      type = g_enum_register_static ("GimpOffsetType", values);
      gimp_type_set_translation_domain (type, GETTEXT_PACKAGE "-libgimp");
      gimp_type_set_translation_context (type, "offset-type");
      gimp_enum_set_value_descriptions (type, descs);
    }

  return type;
}

GType
gimp_orientation_type_get_type (void)
{
  static const GEnumValue values[] =
  {
    { GIMP_ORIENTATION_HORIZONTAL, "GIMP_ORIENTATION_HORIZONTAL", "horizontal" },
    { GIMP_ORIENTATION_VERTICAL, "GIMP_ORIENTATION_VERTICAL", "vertical" },
    { GIMP_ORIENTATION_UNKNOWN, "GIMP_ORIENTATION_UNKNOWN", "unknown" },
    { 0, NULL, NULL }
  };

  static const GimpEnumDesc descs[] =
  {
    { GIMP_ORIENTATION_HORIZONTAL, "GIMP_ORIENTATION_HORIZONTAL", NULL },
    { GIMP_ORIENTATION_VERTICAL, "GIMP_ORIENTATION_VERTICAL", NULL },
    { GIMP_ORIENTATION_UNKNOWN, "GIMP_ORIENTATION_UNKNOWN", NULL },
    { 0, NULL, NULL }
  };

  static GType type = 0;

  if (G_UNLIKELY (! type))
    {
      type = g_enum_register_static ("GimpOrientationType", values);
      gimp_type_set_translation_domain (type, GETTEXT_PACKAGE "-libgimp");
      gimp_type_set_translation_context (type, "orientation-type");
      gimp_enum_set_value_descriptions (type, descs);
    }

  return type;
}

GType
gimp_rotation_type_get_type (void)
{
  static const GEnumValue values[] =
  {
    { GIMP_ROTATE_90, "GIMP_ROTATE_90", "90" },
    { GIMP_ROTATE_180, "GIMP_ROTATE_180", "180" },
    { GIMP_ROTATE_270, "GIMP_ROTATE_270", "270" },
    { 0, NULL, NULL }
  };

  static const GimpEnumDesc descs[] =
  {
    { GIMP_ROTATE_90, "GIMP_ROTATE_90", NULL },
    { GIMP_ROTATE_180, "GIMP_ROTATE_180", NULL },
    { GIMP_ROTATE_270, "GIMP_ROTATE_270", NULL },
    { 0, NULL, NULL }
  };

  static GType type = 0;

  if (G_UNLIKELY (! type))
    {
      type = g_enum_register_static ("GimpRotationType", values);
      gimp_type_set_translation_domain (type, GETTEXT_PACKAGE "-libgimp");
      gimp_type_set_translation_context (type, "rotation-type");
      gimp_enum_set_value_descriptions (type, descs);
    }

  return type;
}

GType
gimp_select_criterion_get_type (void)
{
  static const GEnumValue values[] =
  {
    { GIMP_SELECT_CRITERION_COMPOSITE, "GIMP_SELECT_CRITERION_COMPOSITE", "composite" },
    { GIMP_SELECT_CRITERION_R, "GIMP_SELECT_CRITERION_R", "r" },
    { GIMP_SELECT_CRITERION_G, "GIMP_SELECT_CRITERION_G", "g" },
    { GIMP_SELECT_CRITERION_B, "GIMP_SELECT_CRITERION_B", "b" },
    { GIMP_SELECT_CRITERION_H, "GIMP_SELECT_CRITERION_H", "h" },
    { GIMP_SELECT_CRITERION_S, "GIMP_SELECT_CRITERION_S", "s" },
    { GIMP_SELECT_CRITERION_V, "GIMP_SELECT_CRITERION_V", "v" },
    { 0, NULL, NULL }
  };

  static const GimpEnumDesc descs[] =
  {
    { GIMP_SELECT_CRITERION_COMPOSITE, "GIMP_SELECT_CRITERION_COMPOSITE", NULL },
    { GIMP_SELECT_CRITERION_R, "GIMP_SELECT_CRITERION_R", NULL },
    { GIMP_SELECT_CRITERION_G, "GIMP_SELECT_CRITERION_G", NULL },
    { GIMP_SELECT_CRITERION_B, "GIMP_SELECT_CRITERION_B", NULL },
    { GIMP_SELECT_CRITERION_H, "GIMP_SELECT_CRITERION_H", NULL },
    { GIMP_SELECT_CRITERION_S, "GIMP_SELECT_CRITERION_S", NULL },
    { GIMP_SELECT_CRITERION_V, "GIMP_SELECT_CRITERION_V", NULL },
    { 0, NULL, NULL }
  };

  static GType type = 0;

  if (G_UNLIKELY (! type))
    {
      type = g_enum_register_static ("GimpSelectCriterion", values);
      gimp_type_set_translation_domain (type, GETTEXT_PACKAGE "-libgimp");
      gimp_type_set_translation_context (type, "select-criterion");
      gimp_enum_set_value_descriptions (type, descs);
    }

  return type;
}


/* Generated data ends here */


typedef GType (* GimpGetTypeFunc) (void);

static const GimpGetTypeFunc get_type_funcs[] =
{
  gimp_add_mask_type_get_type,
  gimp_blend_mode_get_type,
  gimp_brush_application_mode_get_type,
  gimp_brush_generated_shape_get_type,
  gimp_bucket_fill_mode_get_type,
  gimp_channel_ops_get_type,
  gimp_channel_type_get_type,
  gimp_clone_type_get_type,
  gimp_convert_dither_type_get_type,
  gimp_convert_palette_type_get_type,
  gimp_convolution_type_get_type,
  gimp_convolve_type_get_type,
  gimp_desaturate_mode_get_type,
  gimp_dodge_burn_type_get_type,
  gimp_fill_type_get_type,
  gimp_foreground_extract_mode_get_type,
  gimp_gradient_segment_color_get_type,
  gimp_gradient_segment_type_get_type,
  gimp_gradient_type_get_type,
  gimp_grid_style_get_type,
  gimp_histogram_channel_get_type,
  gimp_hue_range_get_type,
  gimp_icon_type_get_type,
  gimp_image_base_type_get_type,
  gimp_image_type_get_type,
  gimp_ink_blob_type_get_type,
  gimp_interpolation_type_get_type,
  gimp_layer_mode_effects_get_type,
  gimp_mask_apply_mode_get_type,
  gimp_merge_type_get_type,
  gimp_message_handler_type_get_type,
  gimp_offset_type_get_type,
  gimp_orientation_type_get_type,
  gimp_pdb_arg_type_get_type,
  gimp_pdb_error_handler_get_type,
  gimp_pdb_proc_type_get_type,
  gimp_pdb_status_type_get_type,
  gimp_paint_application_mode_get_type,
  gimp_progress_command_get_type,
  gimp_repeat_mode_get_type,
  gimp_rotation_type_get_type,
  gimp_run_mode_get_type,
  gimp_select_criterion_get_type,
  gimp_size_type_get_type,
  gimp_stack_trace_mode_get_type,
  gimp_text_direction_get_type,
  gimp_text_hint_style_get_type,
  gimp_text_justification_get_type,
  gimp_transfer_mode_get_type,
  gimp_transform_direction_get_type,
  gimp_transform_resize_get_type,
  gimp_user_directory_get_type,
  gimp_vectors_stroke_type_get_type
};

static const gchar * const type_names[] =
{
  "GimpAddMaskType",
  "GimpBlendMode",
  "GimpBrushApplicationMode",
  "GimpBrushGeneratedShape",
  "GimpBucketFillMode",
  "GimpChannelOps",
  "GimpChannelType",
  "GimpCloneType",
  "GimpConvertDitherType",
  "GimpConvertPaletteType",
  "GimpConvolutionType",
  "GimpConvolveType",
  "GimpDesaturateMode",
  "GimpDodgeBurnType",
  "GimpFillType",
  "GimpForegroundExtractMode",
  "GimpGradientSegmentColor",
  "GimpGradientSegmentType",
  "GimpGradientType",
  "GimpGridStyle",
  "GimpHistogramChannel",
  "GimpHueRange",
  "GimpIconType",
  "GimpImageBaseType",
  "GimpImageType",
  "GimpInkBlobType",
  "GimpInterpolationType",
  "GimpLayerModeEffects",
  "GimpMaskApplyMode",
  "GimpMergeType",
  "GimpMessageHandlerType",
  "GimpOffsetType",
  "GimpOrientationType",
  "GimpPDBArgType",
  "GimpPDBErrorHandler",
  "GimpPDBProcType",
  "GimpPDBStatusType",
  "GimpPaintApplicationMode",
  "GimpProgressCommand",
  "GimpRepeatMode",
  "GimpRotationType",
  "GimpRunMode",
  "GimpSelectCriterion",
  "GimpSizeType",
  "GimpStackTraceMode",
  "GimpTextDirection",
  "GimpTextHintStyle",
  "GimpTextJustification",
  "GimpTransferMode",
  "GimpTransformDirection",
  "GimpTransformResize",
  "GimpUserDirectory",
  "GimpVectorsStrokeType"
};

static gboolean enums_initialized = FALSE;

/**
 * gimp_enums_init:
 *
 * This function makes sure all the enum types are registered
 * with the #GType system. This is intended for use by language
 * bindings that need the symbols early, before gimp_main is run.
 * It's not necessary for plug-ins to call this directly, because
 * the normal plug-in initialization code will handle it implicitly.
 *
 * Since: GIMP 2.4
 **/
void
gimp_enums_init (void)
{
  const GimpGetTypeFunc *funcs = get_type_funcs;
  gint                   i;

  if (enums_initialized)
    return;

  for (i = 0; i < G_N_ELEMENTS (get_type_funcs); i++, funcs++)
    {
      GType type = (*funcs) ();

      g_type_class_ref (type);
    }

  enums_initialized = TRUE;
}

/**
 * gimp_enums_get_type_names:
 * @n_type_names: return location for the number of names
 *
 * This function gives access to the list of enums registered by libgimp.
 * The returned array is static and must not be modified.
 *
 * Return value: an array with type names
 *
 * Since: GIMP 2.2
 **/
const gchar **
gimp_enums_get_type_names (gint *n_type_names)
{
  g_return_val_if_fail (n_type_names != NULL, NULL);

  *n_type_names = G_N_ELEMENTS (type_names);

  return (const gchar **) type_names;
}
