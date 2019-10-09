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

#include <stdlib.h>
#include <string.h>

#include <gegl.h>

#include "libgimpmath/gimpmath.h"

#include "core-types.h"

#include "gimperror.h"
#include "gimpimage.h"
#include "gimpimage-undo-push.h"
#include "gimplayer.h"
#include "gimplayermask.h"
#include "gimpmarshal.h"

#include "gimp-intl.h"


enum
{
  APPLY_CHANGED,
  EDIT_CHANGED,
  SHOW_CHANGED,
  LAST_SIGNAL
};


static gboolean        gimp_layer_mask_is_attached       (const GimpItem *item);
static gboolean        gimp_layer_mask_is_content_locked (const GimpItem *item);
static GimpItemTree  * gimp_layer_mask_get_tree          (GimpItem       *item);
static GimpItem      * gimp_layer_mask_duplicate         (GimpItem       *item,
                                                          GType           new_type);
static gboolean        gimp_layer_mask_rename            (GimpItem       *item,
                                                          const gchar    *new_name,
                                                          const gchar    *undo_desc,
                                                          GError        **error);


G_DEFINE_TYPE (GimpLayerMask, gimp_layer_mask, GIMP_TYPE_CHANNEL)

#define parent_class gimp_layer_mask_parent_class

static guint layer_mask_signals[LAST_SIGNAL] = { 0 };


static void
gimp_layer_mask_class_init (GimpLayerMaskClass *klass)
{
  GimpViewableClass *viewable_class = GIMP_VIEWABLE_CLASS (klass);
  GimpItemClass     *item_class     = GIMP_ITEM_CLASS (klass);

  layer_mask_signals[APPLY_CHANGED] =
    g_signal_new ("apply-changed",
                  G_TYPE_FROM_CLASS (klass),
                  G_SIGNAL_RUN_FIRST,
                  G_STRUCT_OFFSET (GimpLayerMaskClass, apply_changed),
                  NULL, NULL,
                  gimp_marshal_VOID__VOID,
                  G_TYPE_NONE, 0);

  layer_mask_signals[EDIT_CHANGED] =
    g_signal_new ("edit-changed",
                  G_TYPE_FROM_CLASS (klass),
                  G_SIGNAL_RUN_FIRST,
                  G_STRUCT_OFFSET (GimpLayerMaskClass, edit_changed),
                  NULL, NULL,
                  gimp_marshal_VOID__VOID,
                  G_TYPE_NONE, 0);

  layer_mask_signals[SHOW_CHANGED] =
    g_signal_new ("show-changed",
                  G_TYPE_FROM_CLASS (klass),
                  G_SIGNAL_RUN_FIRST,
                  G_STRUCT_OFFSET (GimpLayerMaskClass, show_changed),
                  NULL, NULL,
                  gimp_marshal_VOID__VOID,
                  G_TYPE_NONE, 0);

  viewable_class->default_stock_id = "gimp-layer-mask";

  klass->edit_changed           = NULL;

  item_class->is_attached       = gimp_layer_mask_is_attached;
  item_class->is_content_locked = gimp_layer_mask_is_content_locked;
  item_class->get_tree          = gimp_layer_mask_get_tree;
  item_class->duplicate         = gimp_layer_mask_duplicate;
  item_class->rename            = gimp_layer_mask_rename;
  item_class->translate_desc    = C_("undo-type", "Move Layer Mask");
  item_class->to_selection_desc = C_("undo-type", "Layer Mask to Selection");
}

static void
gimp_layer_mask_init (GimpLayerMask *layer_mask)
{
  layer_mask->layer      = NULL;
  layer_mask->apply_mask = TRUE;
  layer_mask->edit_mask  = TRUE;
  layer_mask->show_mask  = FALSE;
}

static gboolean
gimp_layer_mask_is_content_locked (const GimpItem *item)
{
  GimpLayerMask *mask  = GIMP_LAYER_MASK (item);
  GimpLayer     *layer = gimp_layer_mask_get_layer (mask);

  if (layer)
    return gimp_item_is_content_locked (GIMP_ITEM (layer));

  return FALSE;
}

static gboolean
gimp_layer_mask_is_attached (const GimpItem *item)
{
  GimpLayerMask *mask  = GIMP_LAYER_MASK (item);
  GimpLayer     *layer = gimp_layer_mask_get_layer (mask);

  return (GIMP_IS_IMAGE (gimp_item_get_image (item)) &&
          GIMP_IS_LAYER (layer)                      &&
          gimp_layer_get_mask (layer) == mask        &&
          gimp_item_is_attached (GIMP_ITEM (layer)));
}

static GimpItemTree *
gimp_layer_mask_get_tree (GimpItem *item)
{
  return NULL;
}

static GimpItem *
gimp_layer_mask_duplicate (GimpItem *item,
                           GType     new_type)
{
  GimpItem *new_item;

  g_return_val_if_fail (g_type_is_a (new_type, GIMP_TYPE_DRAWABLE), NULL);

  new_item = GIMP_ITEM_CLASS (parent_class)->duplicate (item, new_type);

  if (GIMP_IS_LAYER_MASK (new_item))
    {
      GimpLayerMask *layer_mask     = GIMP_LAYER_MASK (item);
      GimpLayerMask *new_layer_mask = GIMP_LAYER_MASK (new_item);

      new_layer_mask->apply_mask = layer_mask->apply_mask;
      new_layer_mask->edit_mask  = layer_mask->edit_mask;
      new_layer_mask->show_mask  = layer_mask->show_mask;
    }

  return new_item;
}

static gboolean
gimp_layer_mask_rename (GimpItem     *item,
                        const gchar  *new_name,
                        const gchar  *undo_desc,
                        GError      **error)
{
  /* reject renaming, layer masks are always named "<layer name> mask"  */

  g_set_error (error, GIMP_ERROR, GIMP_FAILED,
	       _("Cannot rename layer masks."));

  return FALSE;
}

GimpLayerMask *
gimp_layer_mask_new (GimpImage     *image,
                     gint           width,
                     gint           height,
                     const gchar   *name,
                     const GimpRGB *color)
{
  GimpLayerMask *layer_mask;

  g_return_val_if_fail (GIMP_IS_IMAGE (image), NULL);
  g_return_val_if_fail (width > 0, NULL);
  g_return_val_if_fail (height > 0, NULL);
  g_return_val_if_fail (color != NULL, NULL);

  layer_mask = GIMP_LAYER_MASK (gimp_drawable_new (GIMP_TYPE_LAYER_MASK,
                                                   image, name,
                                                   0, 0, width, height,
                                                   GIMP_GRAY_IMAGE));

  /*  set the layer_mask color and opacity  */
  gimp_channel_set_color (GIMP_CHANNEL (layer_mask), color, FALSE);
  gimp_channel_set_show_masked (GIMP_CHANNEL (layer_mask), TRUE);

  /*  selection mask variables  */
  GIMP_CHANNEL (layer_mask)->x2 = width;
  GIMP_CHANNEL (layer_mask)->y2 = height;

  return layer_mask;
}

void
gimp_layer_mask_set_layer (GimpLayerMask *layer_mask,
                           GimpLayer     *layer)
{
  g_return_if_fail (GIMP_IS_LAYER_MASK (layer_mask));
  g_return_if_fail (layer == NULL || GIMP_IS_LAYER (layer));

  layer_mask->layer = layer;

  if (layer)
    {
      gchar *mask_name;
      gint   offset_x;
      gint   offset_y;

      gimp_item_get_offset (GIMP_ITEM (layer), &offset_x, &offset_y);
      gimp_item_set_offset (GIMP_ITEM (layer_mask), offset_x, offset_y);

      mask_name = g_strdup_printf (_("%s mask"), gimp_object_get_name (layer));

      gimp_object_take_name (GIMP_OBJECT (layer_mask), mask_name);
    }
}

GimpLayer *
gimp_layer_mask_get_layer (const GimpLayerMask *layer_mask)
{
  g_return_val_if_fail (GIMP_IS_LAYER_MASK (layer_mask), NULL);

  return layer_mask->layer;
}

void
gimp_layer_mask_set_apply (GimpLayerMask *layer_mask,
                           gboolean       apply,
                           gboolean       push_undo)
{
  g_return_if_fail (GIMP_IS_LAYER_MASK (layer_mask));

  if (layer_mask->apply_mask != apply)
    {
      GimpImage *image = gimp_item_get_image (GIMP_ITEM (layer_mask));

      if (push_undo)
        gimp_image_undo_push_layer_mask_apply (image,
                                               apply ?
                                               C_("undo-type", "Enable Layer Mask") :
                                               C_("undo-type", "Disable Layer Mask"),
                                               layer_mask);

      layer_mask->apply_mask = apply ? TRUE : FALSE;

      if (layer_mask->layer)
        {
          GimpDrawable *drawable = GIMP_DRAWABLE (layer_mask->layer);

          gimp_drawable_update (drawable,
                                0, 0,
                                gimp_item_get_width  (GIMP_ITEM (drawable)),
                                gimp_item_get_height (GIMP_ITEM (drawable)));
        }

      g_signal_emit (layer_mask, layer_mask_signals[APPLY_CHANGED], 0);
    }
}

gboolean
gimp_layer_mask_get_apply (const GimpLayerMask *layer_mask)
{
  g_return_val_if_fail (GIMP_IS_LAYER_MASK (layer_mask), FALSE);

  return layer_mask->apply_mask;
}

void
gimp_layer_mask_set_edit (GimpLayerMask *layer_mask,
                          gboolean       edit)
{
  g_return_if_fail (GIMP_IS_LAYER_MASK (layer_mask));

  if (layer_mask->edit_mask != edit)
    {
      layer_mask->edit_mask = edit ? TRUE : FALSE;

      g_signal_emit (layer_mask, layer_mask_signals[EDIT_CHANGED], 0);
    }
}

gboolean
gimp_layer_mask_get_edit (const GimpLayerMask *layer_mask)
{
  g_return_val_if_fail (GIMP_IS_LAYER_MASK (layer_mask), FALSE);

  return layer_mask->edit_mask;
}

void
gimp_layer_mask_set_show (GimpLayerMask *layer_mask,
                          gboolean       show,
                          gboolean       push_undo)
{
  g_return_if_fail (GIMP_IS_LAYER_MASK (layer_mask));

  if (layer_mask->show_mask != show)
    {
      GimpImage *image = gimp_item_get_image (GIMP_ITEM (layer_mask));

      if (push_undo)
        gimp_image_undo_push_layer_mask_show (image,
                                              C_("undo-type", "Show Layer Mask"),
                                              layer_mask);

      layer_mask->show_mask = show ? TRUE : FALSE;

      if (layer_mask->layer)
        {
          GimpDrawable *drawable = GIMP_DRAWABLE (layer_mask->layer);

          gimp_drawable_update (drawable,
                                0, 0,
                                gimp_item_get_width  (GIMP_ITEM (drawable)),
                                gimp_item_get_height (GIMP_ITEM (drawable)));
        }

      g_signal_emit (layer_mask, layer_mask_signals[SHOW_CHANGED], 0);
    }
}

gboolean
gimp_layer_mask_get_show (const GimpLayerMask *layer_mask)
{
  g_return_val_if_fail (GIMP_IS_LAYER_MASK (layer_mask), FALSE);

  return layer_mask->show_mask;
}
