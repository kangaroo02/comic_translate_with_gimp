/* GIMP - The GNU Image Manipulation Program
 * Copyright (C) 1995 Spencer Kimball and Peter Mattis
 *
 * gimpplugin-cleanup.c
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

#include "plug-in-types.h"

#include "core/gimp.h"
#include "core/gimpcontainer.h"
#include "core/gimpdrawable.h"
#include "core/gimpdrawable-shadow.h"
#include "core/gimpimage.h"
#include "core/gimpimage-undo.h"
#include "core/gimpundostack.h"

#include "gimpplugin.h"
#include "gimpplugin-cleanup.h"
#include "gimppluginmanager.h"
#include "gimppluginprocedure.h"

#include "gimp-log.h"


typedef struct _GimpPlugInCleanupImage GimpPlugInCleanupImage;

struct _GimpPlugInCleanupImage
{
  GimpImage *image;
  gint       image_ID;

  gint       undo_group_count;
};


typedef struct _GimpPlugInCleanupItem GimpPlugInCleanupItem;

struct _GimpPlugInCleanupItem
{
  GimpItem *item;
  gint      item_ID;

  gboolean  shadow_tiles;
};


/*  local function prototypes  */

static GimpPlugInCleanupImage *
              gimp_plug_in_cleanup_image_new  (GimpImage              *image);
static void   gimp_plug_in_cleanup_image_free (GimpPlugInCleanupImage *cleanup);
static GimpPlugInCleanupImage *
              gimp_plug_in_cleanup_image_get  (GimpPlugInProcFrame    *proc_frame,
                                               GimpImage              *image);
static void   gimp_plug_in_cleanup_image      (GimpPlugInProcFrame    *proc_frame,
                                               GimpPlugInCleanupImage *cleanup);

static GimpPlugInCleanupItem *
              gimp_plug_in_cleanup_item_new   (GimpItem               *item);
static void   gimp_plug_in_cleanup_item_free  (GimpPlugInCleanupItem  *cleanup);
static GimpPlugInCleanupItem *
              gimp_plug_in_cleanup_item_get   (GimpPlugInProcFrame    *proc_frame,
                                               GimpItem               *item);
static void   gimp_plug_in_cleanup_item       (GimpPlugInProcFrame    *proc_frame,
                                               GimpPlugInCleanupItem  *cleanup);


/*  public functions  */

gboolean
gimp_plug_in_cleanup_undo_group_start (GimpPlugIn *plug_in,
                                       GimpImage  *image)
{
  GimpPlugInProcFrame    *proc_frame;
  GimpPlugInCleanupImage *cleanup;

  g_return_val_if_fail (GIMP_IS_PLUG_IN (plug_in), FALSE);
  g_return_val_if_fail (GIMP_IS_IMAGE (image), FALSE);

  proc_frame = gimp_plug_in_get_proc_frame (plug_in);
  cleanup    = gimp_plug_in_cleanup_image_get (proc_frame, image);

  if (! cleanup)
    {
      cleanup = gimp_plug_in_cleanup_image_new (image);

      cleanup->undo_group_count = gimp_image_get_undo_group_count (image);

      proc_frame->image_cleanups = g_list_prepend (proc_frame->image_cleanups,
                                                   cleanup);
    }

  return TRUE;
}

gboolean
gimp_plug_in_cleanup_undo_group_end (GimpPlugIn *plug_in,
                                     GimpImage  *image)
{
  GimpPlugInProcFrame    *proc_frame;
  GimpPlugInCleanupImage *cleanup;

  g_return_val_if_fail (GIMP_IS_PLUG_IN (plug_in), FALSE);
  g_return_val_if_fail (GIMP_IS_IMAGE (image), FALSE);

  proc_frame = gimp_plug_in_get_proc_frame (plug_in);
  cleanup    = gimp_plug_in_cleanup_image_get (proc_frame, image);

  if (! cleanup)
    return FALSE;

  if (cleanup->undo_group_count == gimp_image_get_undo_group_count (image) - 1)
    {
      proc_frame->image_cleanups = g_list_remove (proc_frame->image_cleanups,
                                                  cleanup);
      gimp_plug_in_cleanup_image_free (cleanup);
    }

  return TRUE;
}

gboolean
gimp_plug_in_cleanup_add_shadow (GimpPlugIn   *plug_in,
                                 GimpDrawable *drawable)
{
  GimpPlugInProcFrame   *proc_frame;
  GimpPlugInCleanupItem *cleanup;

  g_return_val_if_fail (GIMP_IS_PLUG_IN (plug_in), FALSE);
  g_return_val_if_fail (GIMP_IS_DRAWABLE (drawable), FALSE);

  proc_frame = gimp_plug_in_get_proc_frame (plug_in);
  cleanup    = gimp_plug_in_cleanup_item_get (proc_frame, GIMP_ITEM (drawable));

  if (! cleanup)
    {
      cleanup = gimp_plug_in_cleanup_item_new (GIMP_ITEM (drawable));

      proc_frame->item_cleanups = g_list_prepend (proc_frame->item_cleanups,
                                                  cleanup);
    }

  cleanup->shadow_tiles = TRUE;

  return TRUE;
}

gboolean
gimp_plug_in_cleanup_remove_shadow (GimpPlugIn   *plug_in,
                                    GimpDrawable *drawable)
{
  GimpPlugInProcFrame   *proc_frame;
  GimpPlugInCleanupItem *cleanup;

  g_return_val_if_fail (GIMP_IS_PLUG_IN (plug_in), FALSE);
  g_return_val_if_fail (GIMP_IS_DRAWABLE (drawable), FALSE);

  proc_frame = gimp_plug_in_get_proc_frame (plug_in);
  cleanup    = gimp_plug_in_cleanup_item_get (proc_frame, GIMP_ITEM (drawable));

  if (! cleanup)
    return FALSE;

  if (! cleanup->shadow_tiles)
    return FALSE;

  proc_frame->item_cleanups = g_list_remove (proc_frame->item_cleanups,
                                             cleanup);
  gimp_plug_in_cleanup_item_free (cleanup);

  return TRUE;
}

void
gimp_plug_in_cleanup (GimpPlugIn          *plug_in,
                      GimpPlugInProcFrame *proc_frame)
{
  GList *list;

  g_return_if_fail (GIMP_IS_PLUG_IN (plug_in));
  g_return_if_fail (proc_frame != NULL);

  for (list = proc_frame->image_cleanups; list; list = g_list_next (list))
    {
      GimpPlugInCleanupImage *cleanup = list->data;

      if (gimp_image_get_by_ID (plug_in->manager->gimp,
                                cleanup->image_ID) == cleanup->image)
        {
          gimp_plug_in_cleanup_image (proc_frame, cleanup);
        }

      gimp_plug_in_cleanup_image_free (cleanup);
    }

  g_list_free (proc_frame->image_cleanups);
  proc_frame->image_cleanups = NULL;

  for (list = proc_frame->item_cleanups; list; list = g_list_next (list))
    {
      GimpPlugInCleanupItem *cleanup = list->data;

      if (gimp_item_get_by_ID (plug_in->manager->gimp,
                               cleanup->item_ID) == cleanup->item)
        {
          gimp_plug_in_cleanup_item (proc_frame, cleanup);
        }

      gimp_plug_in_cleanup_item_free (cleanup);
    }

  g_list_free (proc_frame->item_cleanups);
  proc_frame->item_cleanups = NULL;
}


/*  private functions  */

static GimpPlugInCleanupImage *
gimp_plug_in_cleanup_image_new (GimpImage *image)
{
  GimpPlugInCleanupImage *cleanup = g_slice_new0 (GimpPlugInCleanupImage);

  cleanup->image    = image;
  cleanup->image_ID = gimp_image_get_ID (image);

  return cleanup;
}

static void
gimp_plug_in_cleanup_image_free (GimpPlugInCleanupImage *cleanup)
{
  g_slice_free (GimpPlugInCleanupImage, cleanup);
}

static GimpPlugInCleanupImage *
gimp_plug_in_cleanup_image_get (GimpPlugInProcFrame *proc_frame,
                                GimpImage           *image)
{
  GList *list;

  for (list = proc_frame->image_cleanups; list; list = g_list_next (list))
    {
      GimpPlugInCleanupImage *cleanup = list->data;

      if (cleanup->image == image)
        return cleanup;
    }

  return NULL;
}

static void
gimp_plug_in_cleanup_image (GimpPlugInProcFrame    *proc_frame,
                            GimpPlugInCleanupImage *cleanup)
{
  GimpImage *image = cleanup->image;

  if (gimp_image_get_undo_group_count (image) == 0)
    return;

  if (cleanup->undo_group_count != gimp_image_get_undo_group_count (image))
    {
      GimpProcedure *proc = proc_frame->procedure;

      g_message ("Plug-In '%s' left image undo in inconsistent state, "
                 "closing open undo groups.",
                 gimp_plug_in_procedure_get_label (GIMP_PLUG_IN_PROCEDURE (proc)));

      while (cleanup->undo_group_count < gimp_image_get_undo_group_count (image))
        {
          if (! gimp_image_undo_group_end (image))
            break;
        }
    }
}

static GimpPlugInCleanupItem *
gimp_plug_in_cleanup_item_new (GimpItem *item)
{
  GimpPlugInCleanupItem *cleanup = g_slice_new0 (GimpPlugInCleanupItem);

  cleanup->item    = item;
  cleanup->item_ID = gimp_item_get_ID (item);

  return cleanup;
}

static void
gimp_plug_in_cleanup_item_free (GimpPlugInCleanupItem *cleanup)
{
  g_slice_free (GimpPlugInCleanupItem, cleanup);
}

static GimpPlugInCleanupItem *
gimp_plug_in_cleanup_item_get (GimpPlugInProcFrame *proc_frame,
                               GimpItem            *item)
{
  GList *list;

  for (list = proc_frame->item_cleanups; list; list = g_list_next (list))
    {
      GimpPlugInCleanupItem *cleanup = list->data;

      if (cleanup->item == item)
        return cleanup;
    }

  return NULL;
}

static void
gimp_plug_in_cleanup_item (GimpPlugInProcFrame   *proc_frame,
                           GimpPlugInCleanupItem *cleanup)
{
  GimpItem *item = cleanup->item;

  if (cleanup->shadow_tiles)
    {
      GimpProcedure *proc = proc_frame->procedure;

      GIMP_LOG (SHADOW_TILES,
                "Freeing shadow tiles of drawable '%s' on behalf of '%s'.",
                gimp_object_get_name (item),
                gimp_plug_in_procedure_get_label (GIMP_PLUG_IN_PROCEDURE (proc)));

      gimp_drawable_free_shadow_tiles (GIMP_DRAWABLE (item));
    }
}
