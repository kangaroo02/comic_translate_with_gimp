


/* This is a generated file, do not edit directly */

#include "config.h"
#include <glib-object.h>
#include "gegl-enums.h"

/* enumerations from "./gegl-enums.h" */
GType
gegl_sampler_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { GEGL_SAMPLER_NEAREST, "nearest", "nearest" },
      { GEGL_SAMPLER_LINEAR, "linear", "linear" },
      { GEGL_SAMPLER_CUBIC, "cubic", "cubic" },
      { GEGL_SAMPLER_LOHALO, "lohalo", "lohalo" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("GeglSamplerType", values);
  }
  return etype;
}

GType
gegl_abyss_policy_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { GEGL_ABYSS_NONE, "none", "none" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("GeglAbyssPolicy", values);
  }
  return etype;
}

GType
gegl_ripple_wave_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { GEGl_RIPPLE_WAVE_TYPE_SINE, "sine", "sine" },
      { GEGl_RIPPLE_WAVE_TYPE_SAWTOOTH, "sawtooth", "sawtooth" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("GeglRippleWaveType", values);
  }
  return etype;
}

GType
gegl_warp_behavior_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { GEGL_WARP_BEHAVIOR_MOVE, "move", "move" },
      { GEGL_WARP_BEHAVIOR_GROW, "grow", "grow" },
      { GEGL_WARP_BEHAVIOR_SHRINK, "shrink", "shrink" },
      { GEGL_WARP_BEHAVIOR_SWIRL_CW, "swirl-cw", "swirl-cw" },
      { GEGL_WARP_BEHAVIOR_SWIRL_CCW, "swirl-ccw", "swirl-ccw" },
      { GEGL_WARP_BEHAVIOR_ERASE, "erase", "erase" },
      { GEGL_WARP_BEHAVIOR_SMOOTH, "smooth", "smooth" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("GeglWarpBehavior", values);
  }
  return etype;
}




