/* GIMP - The GNU Image Manipulation Program
 * Copyright (C) 1995 Spencer Kimball and Peter Mattis
 *
 * plug-in-icc-profile.c
 * Copyright (C) 2006  Sven Neumann <sven@gimp.org>
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

#include <gegl.h>

#include "core/core-types.h"

#include "core/gimp.h"
#include "core/gimpcontext.h"
#include "core/gimpimage.h"
#include "core/gimpparamspecs.h"
#include "core/gimpprogress.h"

#include "pdb/gimppdb.h"
#include "pdb/gimpprocedure.h"

#include "gimppluginerror.h"
#include "plug-in-icc-profile.h"

#include "gimp-intl.h"


#define ICC_PROFILE_APPLY_RGB_PROC  "plug-in-icc-profile-apply-rgb"
#define ICC_PROFILE_INFO_PROC       "plug-in-icc-profile-info"
#define ICC_PROFILE_FILE_INFO_PROC  "plug-in-icc-profile-file-info"


static void
plug_in_icc_profile_info_return (GValueArray  *return_vals,
                                 gchar       **name,
                                 gchar       **desc,
                                 gchar       **info);


gboolean
plug_in_icc_profile_apply_rgb (GimpImage     *image,
                               GimpContext   *context,
                               GimpProgress  *progress,
                               GimpRunMode    run_mode,
                               GError       **error)
{
  Gimp          *gimp;
  GimpProcedure *procedure;

  g_return_val_if_fail (GIMP_IS_IMAGE (image), FALSE);
  g_return_val_if_fail (GIMP_IS_CONTEXT (context), FALSE);
  g_return_val_if_fail (progress == NULL || GIMP_IS_PROGRESS (progress), FALSE);
  g_return_val_if_fail (error == NULL || *error == NULL, FALSE);

  gimp = image->gimp;

  if (gimp_image_base_type (image) == GIMP_GRAY)
    {
      g_set_error (error, GIMP_PLUG_IN_ERROR, GIMP_PLUG_IN_EXECUTION_FAILED,
                   _("Can't apply color profile to grayscale image (%s)"),
                   ICC_PROFILE_APPLY_RGB_PROC);
      return FALSE;
    }

  procedure = gimp_pdb_lookup_procedure (gimp->pdb, ICC_PROFILE_APPLY_RGB_PROC);

  if (procedure &&
      procedure->num_args >= 2 &&
      GIMP_IS_PARAM_SPEC_INT32 (procedure->args[0]) &&
      GIMP_IS_PARAM_SPEC_IMAGE_ID (procedure->args[1]))
    {
      GValueArray            *return_vals;
      GimpPDBStatusType       status;
      GimpColorProfilePolicy  policy = GIMP_COLOR_PROFILE_POLICY_ASK;
      gboolean                success;

      return_vals =
        gimp_pdb_execute_procedure_by_name (gimp->pdb, context, progress, error,
                                            ICC_PROFILE_APPLY_RGB_PROC,
                                            GIMP_TYPE_INT32, run_mode,
                                            GIMP_TYPE_IMAGE_ID,
                                            gimp_image_get_ID (image),
                                            G_TYPE_NONE);

      status = g_value_get_enum (return_vals->values);

      switch (status)
        {
        case GIMP_PDB_SUCCESS:
          policy = GIMP_COLOR_PROFILE_POLICY_CONVERT;
          success = TRUE;
          break;

        case GIMP_PDB_CANCEL:
          policy = GIMP_COLOR_PROFILE_POLICY_KEEP;
          success = TRUE;
          break;

        default:
          if (error && *error == NULL)
            g_set_error (error,
                         GIMP_PLUG_IN_ERROR, GIMP_PLUG_IN_EXECUTION_FAILED,
                         _("Error running '%s'"), ICC_PROFILE_APPLY_RGB_PROC);
          success = FALSE;
          break;
        }

      if (success && return_vals->n_values > 1)
        {
          GValue *value = g_value_array_get_nth (return_vals, 1);

          if (GIMP_VALUE_HOLDS_INT32 (value) && g_value_get_int (value))
            {
              g_object_set (G_OBJECT (gimp->config),
                            "color-profile-policy", policy,
                            NULL);
            }
        }

      g_value_array_free (return_vals);

      return success;
    }

  g_set_error (error,
               GIMP_PLUG_IN_ERROR, GIMP_PLUG_IN_NOT_FOUND,
               _("Plug-In missing (%s)"), ICC_PROFILE_APPLY_RGB_PROC);

  return FALSE;
}

gboolean
plug_in_icc_profile_info (GimpImage     *image,
                          GimpContext   *context,
                          GimpProgress  *progress,
                          gchar        **name,
                          gchar        **desc,
                          gchar        **info,
                          GError       **error)
{
  Gimp          *gimp;
  GimpProcedure *procedure;

  g_return_val_if_fail (GIMP_IS_IMAGE (image), FALSE);
  g_return_val_if_fail (GIMP_IS_CONTEXT (context), FALSE);
  g_return_val_if_fail (progress == NULL || GIMP_IS_PROGRESS (progress), FALSE);
  g_return_val_if_fail (error == NULL || *error == NULL, FALSE);

  gimp = image->gimp;

  procedure = gimp_pdb_lookup_procedure (gimp->pdb, ICC_PROFILE_INFO_PROC);

  if (procedure &&
      procedure->num_args >= 1 &&
      GIMP_IS_PARAM_SPEC_IMAGE_ID (procedure->args[0]))
    {
      GValueArray       *return_vals;
      GimpPDBStatusType  status;

      return_vals =
        gimp_pdb_execute_procedure_by_name (gimp->pdb, context, progress, error,
                                            ICC_PROFILE_INFO_PROC,
                                            GIMP_TYPE_IMAGE_ID,
                                            gimp_image_get_ID (image),
                                            G_TYPE_NONE);

      status = g_value_get_enum (return_vals->values);

      switch (status)
        {
        case GIMP_PDB_SUCCESS:
          plug_in_icc_profile_info_return (return_vals, name, desc, info);
          break;

        default:
          if (error && *error == NULL)
            g_set_error (error, GIMP_PLUG_IN_ERROR, GIMP_PLUG_IN_FAILED,
                         _("Error running '%s'"), ICC_PROFILE_INFO_PROC);
          break;
        }

      g_value_array_free (return_vals);

      return (status == GIMP_PDB_SUCCESS);
    }

  g_set_error (error, GIMP_PLUG_IN_ERROR, GIMP_PLUG_IN_FAILED,
               _("Plug-In missing (%s)"), ICC_PROFILE_INFO_PROC);

  return FALSE;
}

gboolean
plug_in_icc_profile_file_info (Gimp          *gimp,
                               GimpContext   *context,
                               GimpProgress  *progress,
                               const gchar   *filename,
                               gchar        **name,
                               gchar        **desc,
                               gchar        **info,
                               GError       **error)
{
  GimpProcedure *procedure;

  g_return_val_if_fail (GIMP_IS_GIMP (gimp), FALSE);
  g_return_val_if_fail (GIMP_IS_CONTEXT (context), FALSE);
  g_return_val_if_fail (progress == NULL || GIMP_IS_PROGRESS (progress), FALSE);
  g_return_val_if_fail (filename != NULL, FALSE);
  g_return_val_if_fail (error == NULL || *error == NULL, FALSE);

  procedure = gimp_pdb_lookup_procedure (gimp->pdb, ICC_PROFILE_FILE_INFO_PROC);

  if (procedure &&
      procedure->num_args >= 1 &&
      GIMP_IS_PARAM_SPEC_STRING (procedure->args[0]))
    {
      GValueArray       *return_vals;
      GimpPDBStatusType  status;

      return_vals =
        gimp_pdb_execute_procedure_by_name (gimp->pdb, context, progress, error,
                                            ICC_PROFILE_FILE_INFO_PROC,
                                            G_TYPE_STRING, filename,
                                            G_TYPE_NONE);

      status = g_value_get_enum (return_vals->values);

      switch (status)
        {
        case GIMP_PDB_SUCCESS:
          plug_in_icc_profile_info_return (return_vals, name, desc, info);
          break;

        default:
          if (error && *error == NULL)
            g_set_error (error, GIMP_PLUG_IN_ERROR, GIMP_PLUG_IN_FAILED,
                         _("Error running '%s'"), ICC_PROFILE_FILE_INFO_PROC);
          break;
        }

      g_value_array_free (return_vals);

      return (status == GIMP_PDB_SUCCESS);
    }

  g_set_error (error, GIMP_PLUG_IN_ERROR, GIMP_PLUG_IN_FAILED,
               _("Plug-In missing (%s)"), ICC_PROFILE_FILE_INFO_PROC);

  return FALSE;
}

static void
plug_in_icc_profile_info_return (GValueArray  *return_vals,
                                 gchar       **name,
                                 gchar       **desc,
                                 gchar       **info)
{
  if (name)
    {
      GValue *value = g_value_array_get_nth (return_vals, 1);

      *name = G_VALUE_HOLDS_STRING (value) ? g_value_dup_string (value) : NULL;
    }

  if (desc)
    {
      GValue *value = g_value_array_get_nth (return_vals, 2);

      *desc = G_VALUE_HOLDS_STRING (value) ? g_value_dup_string (value) : NULL;
    }

  if (info)
    {
      GValue *value = g_value_array_get_nth (return_vals, 3);

      *info = G_VALUE_HOLDS_STRING (value) ? g_value_dup_string (value) : NULL;
    }
}
