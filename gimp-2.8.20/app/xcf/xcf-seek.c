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

#include <stdio.h>
#include <errno.h>

#include <glib-object.h>

#include "core/core-types.h"

#include "xcf-private.h"
#include "xcf-seek.h"

#include "gimp-intl.h"

/**
 * SECTION:xcf-seek
 * @Short_description:XCF file seeker functions
 *
 * Functions to change the file position in the XCF file
 */

/**
 * xcf_seek_pos:
 * @info:  #XcfInfo structure of the file under work
 * @pos:   new position, relative to the beginning of the file
 * @error: Return location for errors
 *
 * Changes the file position in the input or output stream to the given
 * position.
 *
 * Returns: %TRUE in case of success; %FALSE otherwise
 */
gboolean
xcf_seek_pos (XcfInfo  *info,
              guint     pos,
              GError  **error)
{
  if (info->cp != pos)
    {
      info->cp = pos;
      if (fseek (info->fp, info->cp, SEEK_SET) == -1)
        {
          g_set_error (error, G_FILE_ERROR, g_file_error_from_errno (errno),
                       _("Could not seek in XCF file: %s"),
                       g_strerror (errno));

          return FALSE;
        }
    }

  return TRUE;
}
