/* GIMP - The GNU Image Manipulation Program
 * Copyright (C) 1995 Spencer Kimball and Peter Mattis
 *
 * gimpprojectable.c
 * Copyright (C) 2008  Michael Natterer <mitch@gimp.org>
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

#include "core-types.h"

#include "gimpmarshal.h"
#include "gimpprojectable.h"
#include "gimpviewable.h"


enum
{
  INVALIDATE,
  FLUSH,
  STRUCTURE_CHANGED,
  LAST_SIGNAL
};


/*  local function prototypes  */

static void   gimp_projectable_iface_base_init (GimpProjectableInterface *iface);


static guint projectable_signals[LAST_SIGNAL] = { 0 };


GType
gimp_projectable_interface_get_type (void)
{
  static GType projectable_iface_type = 0;

  if (! projectable_iface_type)
    {
      const GTypeInfo projectable_iface_info =
      {
        sizeof (GimpProjectableInterface),
        (GBaseInitFunc)     gimp_projectable_iface_base_init,
        (GBaseFinalizeFunc) NULL,
      };

      projectable_iface_type = g_type_register_static (G_TYPE_INTERFACE,
                                                       "GimpProjectableInterface",
                                                       &projectable_iface_info,
                                                       0);

      g_type_interface_add_prerequisite (projectable_iface_type,
                                         GIMP_TYPE_VIEWABLE);
    }

  return projectable_iface_type;
}

static void
gimp_projectable_iface_base_init (GimpProjectableInterface *iface)
{
  static gboolean initialized = FALSE;

  if (! initialized)
    {
      projectable_signals[INVALIDATE] =
        g_signal_new ("invalidate",
                      G_TYPE_FROM_CLASS (iface),
                      G_SIGNAL_RUN_FIRST,
                      G_STRUCT_OFFSET (GimpProjectableInterface, invalidate),
                      NULL, NULL,
                      gimp_marshal_VOID__INT_INT_INT_INT,
                      G_TYPE_NONE, 4,
                      G_TYPE_INT,
                      G_TYPE_INT,
                      G_TYPE_INT,
                      G_TYPE_INT);

      projectable_signals[FLUSH] =
        g_signal_new ("flush",
                      G_TYPE_FROM_CLASS (iface),
                      G_SIGNAL_RUN_FIRST,
                      G_STRUCT_OFFSET (GimpProjectableInterface, flush),
                      NULL, NULL,
                      gimp_marshal_VOID__BOOLEAN,
                      G_TYPE_NONE, 1,
                      G_TYPE_BOOLEAN);

      projectable_signals[STRUCTURE_CHANGED] =
        g_signal_new ("structure-changed",
                      G_TYPE_FROM_CLASS (iface),
                      G_SIGNAL_RUN_FIRST,
                      G_STRUCT_OFFSET (GimpProjectableInterface, structure_changed),
                      NULL, NULL,
                      gimp_marshal_VOID__VOID,
                      G_TYPE_NONE, 0);

      initialized = TRUE;
    }
}


/*  public functions  */

void
gimp_projectable_invalidate (GimpProjectable *projectable,
                             gint             x,
                             gint             y,
                             gint             width,
                             gint             height)
{
  g_return_if_fail (GIMP_IS_PROJECTABLE (projectable));

  g_signal_emit (projectable, projectable_signals[INVALIDATE], 0,
                 x, y, width, height);
}

void
gimp_projectable_flush (GimpProjectable *projectable,
                        gboolean         preview_invalidated)
{
  g_return_if_fail (GIMP_IS_PROJECTABLE (projectable));

  g_signal_emit (projectable, projectable_signals[FLUSH], 0,
                 preview_invalidated);
}

void
gimp_projectable_structure_changed (GimpProjectable *projectable)
{
  g_return_if_fail (GIMP_IS_PROJECTABLE (projectable));

  g_signal_emit (projectable, projectable_signals[STRUCTURE_CHANGED], 0);
}

GimpImage *
gimp_projectable_get_image (GimpProjectable *projectable)
{
  GimpProjectableInterface *iface;

  g_return_val_if_fail (GIMP_IS_PROJECTABLE (projectable), NULL);

  iface = GIMP_PROJECTABLE_GET_INTERFACE (projectable);

  if (iface->get_image)
    return iface->get_image (projectable);

  return NULL;
}

GimpImageType
gimp_projectable_get_image_type (GimpProjectable *projectable)
{
  GimpProjectableInterface *iface;

  g_return_val_if_fail (GIMP_IS_PROJECTABLE (projectable), 0);

  iface = GIMP_PROJECTABLE_GET_INTERFACE (projectable);

  if (iface->get_image_type)
    return iface->get_image_type (projectable);

  return 0;
}

void
gimp_projectable_get_offset (GimpProjectable *projectable,
                             gint            *x,
                             gint            *y)
{
  GimpProjectableInterface *iface;

  g_return_if_fail (GIMP_IS_PROJECTABLE (projectable));
  g_return_if_fail (x != NULL);
  g_return_if_fail (y != NULL);

  iface = GIMP_PROJECTABLE_GET_INTERFACE (projectable);

  *x = 0;
  *y = 0;

  if (iface->get_offset)
    iface->get_offset (projectable, x, y);
}

void
gimp_projectable_get_size (GimpProjectable *projectable,
                           gint            *width,
                           gint            *height)
{
  GimpProjectableInterface *iface;

  g_return_if_fail (GIMP_IS_PROJECTABLE (projectable));
  g_return_if_fail (width  != NULL);
  g_return_if_fail (height != NULL);

  iface = GIMP_PROJECTABLE_GET_INTERFACE (projectable);

  *width  = 0;
  *height = 0;

  if (iface->get_size)
    iface->get_size (projectable, width, height);
}

GeglNode *
gimp_projectable_get_graph (GimpProjectable *projectable)
{
  GimpProjectableInterface *iface;

  g_return_val_if_fail (GIMP_IS_PROJECTABLE (projectable), NULL);

  iface = GIMP_PROJECTABLE_GET_INTERFACE (projectable);

  if (iface->get_graph)
    return iface->get_graph (projectable);

  return NULL;
}

void
gimp_projectable_invalidate_preview (GimpProjectable *projectable)
{
  GimpProjectableInterface *iface;

  g_return_if_fail (GIMP_IS_PROJECTABLE (projectable));

  iface = GIMP_PROJECTABLE_GET_INTERFACE (projectable);

  if (iface->invalidate_preview)
    iface->invalidate_preview (projectable);
}

GList *
gimp_projectable_get_layers (GimpProjectable *projectable)
{
  GimpProjectableInterface *iface;

  g_return_val_if_fail (GIMP_IS_PROJECTABLE (projectable), NULL);

  iface = GIMP_PROJECTABLE_GET_INTERFACE (projectable);

  if (iface->get_layers)
    return iface->get_layers (projectable);

  return NULL;
}

GList *
gimp_projectable_get_channels (GimpProjectable *projectable)
{
  GimpProjectableInterface *iface;

  g_return_val_if_fail (GIMP_IS_PROJECTABLE (projectable), NULL);

  iface = GIMP_PROJECTABLE_GET_INTERFACE (projectable);

  if (iface->get_channels)
    return iface->get_channels (projectable);

  return NULL;
}
