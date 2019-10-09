
/* Generated data (by gimp-mkenums) */

#include "config.h"
#include <glib-object.h>
#include "libgimpbase/gimpbase.h"
#include "plug-in-enums.h"
#include "gimp-intl.h"

/* enumerations from "./plug-in-enums.h" */
GType
gimp_plug_in_image_type_get_type (void)
{
  static const GFlagsValue values[] =
  {
    { GIMP_PLUG_IN_RGB_IMAGE, "GIMP_PLUG_IN_RGB_IMAGE", "rgb-image" },
    { GIMP_PLUG_IN_GRAY_IMAGE, "GIMP_PLUG_IN_GRAY_IMAGE", "gray-image" },
    { GIMP_PLUG_IN_INDEXED_IMAGE, "GIMP_PLUG_IN_INDEXED_IMAGE", "indexed-image" },
    { GIMP_PLUG_IN_RGBA_IMAGE, "GIMP_PLUG_IN_RGBA_IMAGE", "rgba-image" },
    { GIMP_PLUG_IN_GRAYA_IMAGE, "GIMP_PLUG_IN_GRAYA_IMAGE", "graya-image" },
    { GIMP_PLUG_IN_INDEXEDA_IMAGE, "GIMP_PLUG_IN_INDEXEDA_IMAGE", "indexeda-image" },
    { 0, NULL, NULL }
  };

  static const GimpFlagsDesc descs[] =
  {
    { GIMP_PLUG_IN_RGB_IMAGE, "GIMP_PLUG_IN_RGB_IMAGE", NULL },
    { GIMP_PLUG_IN_GRAY_IMAGE, "GIMP_PLUG_IN_GRAY_IMAGE", NULL },
    { GIMP_PLUG_IN_INDEXED_IMAGE, "GIMP_PLUG_IN_INDEXED_IMAGE", NULL },
    { GIMP_PLUG_IN_RGBA_IMAGE, "GIMP_PLUG_IN_RGBA_IMAGE", NULL },
    { GIMP_PLUG_IN_GRAYA_IMAGE, "GIMP_PLUG_IN_GRAYA_IMAGE", NULL },
    { GIMP_PLUG_IN_INDEXEDA_IMAGE, "GIMP_PLUG_IN_INDEXEDA_IMAGE", NULL },
    { 0, NULL, NULL }
  };

  static GType type = 0;

  if (G_UNLIKELY (! type))
    {
      type = g_flags_register_static ("GimpPlugInImageType", values);
      gimp_type_set_translation_context (type, "plug-in-image-type");
      gimp_flags_set_value_descriptions (type, descs);
    }

  return type;
}

GType
gimp_plug_in_call_mode_get_type (void)
{
  static const GEnumValue values[] =
  {
    { GIMP_PLUG_IN_CALL_NONE, "GIMP_PLUG_IN_CALL_NONE", "none" },
    { GIMP_PLUG_IN_CALL_RUN, "GIMP_PLUG_IN_CALL_RUN", "run" },
    { GIMP_PLUG_IN_CALL_QUERY, "GIMP_PLUG_IN_CALL_QUERY", "query" },
    { GIMP_PLUG_IN_CALL_INIT, "GIMP_PLUG_IN_CALL_INIT", "init" },
    { 0, NULL, NULL }
  };

  static const GimpEnumDesc descs[] =
  {
    { GIMP_PLUG_IN_CALL_NONE, "GIMP_PLUG_IN_CALL_NONE", NULL },
    { GIMP_PLUG_IN_CALL_RUN, "GIMP_PLUG_IN_CALL_RUN", NULL },
    { GIMP_PLUG_IN_CALL_QUERY, "GIMP_PLUG_IN_CALL_QUERY", NULL },
    { GIMP_PLUG_IN_CALL_INIT, "GIMP_PLUG_IN_CALL_INIT", NULL },
    { 0, NULL, NULL }
  };

  static GType type = 0;

  if (G_UNLIKELY (! type))
    {
      type = g_enum_register_static ("GimpPlugInCallMode", values);
      gimp_type_set_translation_context (type, "plug-in-call-mode");
      gimp_enum_set_value_descriptions (type, descs);
    }

  return type;
}


/* Generated data ends here */

