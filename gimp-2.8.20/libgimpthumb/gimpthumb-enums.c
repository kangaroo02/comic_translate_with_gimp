
/* Generated data (by gimp-mkenums) */

#include "config.h"
#include <glib-object.h>
#include "gimpthumb-enums.h"

/* enumerations from "./gimpthumb-enums.h" */
GType
gimp_thumb_file_type_get_type (void)
{
  static const GEnumValue values[] =
  {
    { GIMP_THUMB_FILE_TYPE_NONE, "GIMP_THUMB_FILE_TYPE_NONE", "none" },
    { GIMP_THUMB_FILE_TYPE_REGULAR, "GIMP_THUMB_FILE_TYPE_REGULAR", "regular" },
    { GIMP_THUMB_FILE_TYPE_FOLDER, "GIMP_THUMB_FILE_TYPE_FOLDER", "folder" },
    { GIMP_THUMB_FILE_TYPE_SPECIAL, "GIMP_THUMB_FILE_TYPE_SPECIAL", "special" },
    { 0, NULL, NULL }
  };

  static GType type = 0;

  if (G_UNLIKELY (! type))
    type = g_enum_register_static ("GimpThumbFileType", values);

  return type;
}

GType
gimp_thumb_size_get_type (void)
{
  static const GEnumValue values[] =
  {
    { GIMP_THUMB_SIZE_FAIL, "GIMP_THUMB_SIZE_FAIL", "fail" },
    { GIMP_THUMB_SIZE_NORMAL, "GIMP_THUMB_SIZE_NORMAL", "normal" },
    { GIMP_THUMB_SIZE_LARGE, "GIMP_THUMB_SIZE_LARGE", "large" },
    { 0, NULL, NULL }
  };

  static GType type = 0;

  if (G_UNLIKELY (! type))
    type = g_enum_register_static ("GimpThumbSize", values);

  return type;
}

GType
gimp_thumb_state_get_type (void)
{
  static const GEnumValue values[] =
  {
    { GIMP_THUMB_STATE_UNKNOWN, "GIMP_THUMB_STATE_UNKNOWN", "unknown" },
    { GIMP_THUMB_STATE_REMOTE, "GIMP_THUMB_STATE_REMOTE", "remote" },
    { GIMP_THUMB_STATE_FOLDER, "GIMP_THUMB_STATE_FOLDER", "folder" },
    { GIMP_THUMB_STATE_SPECIAL, "GIMP_THUMB_STATE_SPECIAL", "special" },
    { GIMP_THUMB_STATE_NOT_FOUND, "GIMP_THUMB_STATE_NOT_FOUND", "not-found" },
    { GIMP_THUMB_STATE_EXISTS, "GIMP_THUMB_STATE_EXISTS", "exists" },
    { GIMP_THUMB_STATE_OLD, "GIMP_THUMB_STATE_OLD", "old" },
    { GIMP_THUMB_STATE_FAILED, "GIMP_THUMB_STATE_FAILED", "failed" },
    { GIMP_THUMB_STATE_OK, "GIMP_THUMB_STATE_OK", "ok" },
    { 0, NULL, NULL }
  };

  static GType type = 0;

  if (G_UNLIKELY (! type))
    type = g_enum_register_static ("GimpThumbState", values);

  return type;
}


/* Generated data ends here */

