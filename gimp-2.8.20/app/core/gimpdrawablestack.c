/* GIMP - The GNU Image Manipulation Program
 * Copyright (C) 1995-1997 Spencer Kimball and Peter Mattis
 *
 * gimpdrawablestack.c
 * Copyright (C) 2008 Michael Natterer <mitch@gimp.org>
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

#include "gimpdrawable.h"
#include "gimpdrawablestack.h"
#include "gimpmarshal.h"


enum
{
  UPDATE,
  LAST_SIGNAL
};


/*  local function prototypes  */

static void   gimp_drawable_stack_constructed      (GObject           *object);
static void   gimp_drawable_stack_finalize         (GObject           *object);

static void   gimp_drawable_stack_add              (GimpContainer     *container,
                                                    GimpObject        *object);
static void   gimp_drawable_stack_remove           (GimpContainer     *container,
                                                    GimpObject        *object);
static void   gimp_drawable_stack_reorder          (GimpContainer     *container,
                                                    GimpObject        *object,
                                                    gint               new_index);

static void   gimp_drawable_stack_add_node         (GimpDrawableStack *stack,
                                                    GimpDrawable      *drawable);
static void   gimp_drawable_stack_remove_node      (GimpDrawableStack *stack,
                                                    GimpDrawable      *drawable);

static void   gimp_drawable_stack_update           (GimpDrawableStack *stack,
                                                    gint               x,
                                                    gint               y,
                                                    gint               width,
                                                    gint               height);
static void   gimp_drawable_stack_drawable_update  (GimpItem          *item,
                                                    gint               x,
                                                    gint               y,
                                                    gint               width,
                                                    gint               height,
                                                    GimpDrawableStack *stack);
static void   gimp_drawable_stack_drawable_visible (GimpItem          *item,
                                                    GimpDrawableStack *stack);


G_DEFINE_TYPE (GimpDrawableStack, gimp_drawable_stack, GIMP_TYPE_ITEM_STACK)

#define parent_class gimp_drawable_stack_parent_class

static guint stack_signals[LAST_SIGNAL] = { 0 };


static void
gimp_drawable_stack_class_init (GimpDrawableStackClass *klass)
{
  GObjectClass       *object_class    = G_OBJECT_CLASS (klass);
  GimpContainerClass *container_class = GIMP_CONTAINER_CLASS (klass);

  stack_signals[UPDATE] =
    g_signal_new ("update",
                  G_TYPE_FROM_CLASS (klass),
                  G_SIGNAL_RUN_FIRST,
                  G_STRUCT_OFFSET (GimpDrawableStackClass, update),
                  NULL, NULL,
                  gimp_marshal_VOID__INT_INT_INT_INT,
                  G_TYPE_NONE, 4,
                  G_TYPE_INT,
                  G_TYPE_INT,
                  G_TYPE_INT,
                  G_TYPE_INT);

  object_class->constructed = gimp_drawable_stack_constructed;
  object_class->finalize    = gimp_drawable_stack_finalize;

  container_class->add      = gimp_drawable_stack_add;
  container_class->remove   = gimp_drawable_stack_remove;
  container_class->reorder  = gimp_drawable_stack_reorder;
}

static void
gimp_drawable_stack_init (GimpDrawableStack *stack)
{
}

static void
gimp_drawable_stack_constructed (GObject *object)
{
  GimpContainer *container = GIMP_CONTAINER (object);

  if (G_OBJECT_CLASS (parent_class)->constructed)
    G_OBJECT_CLASS (parent_class)->constructed (object);

  g_assert (g_type_is_a (gimp_container_get_children_type (container),
                         GIMP_TYPE_DRAWABLE));

  gimp_container_add_handler (container, "update",
                              G_CALLBACK (gimp_drawable_stack_drawable_update),
                              container);
  gimp_container_add_handler (container, "visibility-changed",
                              G_CALLBACK (gimp_drawable_stack_drawable_visible),
                              container);
}

static void
gimp_drawable_stack_finalize (GObject *object)
{
  GimpDrawableStack *stack = GIMP_DRAWABLE_STACK (object);

  if (stack->graph)
    {
      g_object_unref (stack->graph);
      stack->graph = NULL;
    }

  G_OBJECT_CLASS (parent_class)->finalize (object);
}

static void
gimp_drawable_stack_add (GimpContainer *container,
                         GimpObject    *object)
{
  GimpDrawableStack *stack = GIMP_DRAWABLE_STACK (container);

  GIMP_CONTAINER_CLASS (parent_class)->add (container, object);

  if (stack->graph)
    {
      gegl_node_add_child (stack->graph,
                           gimp_item_get_node (GIMP_ITEM (object)));

      gimp_drawable_stack_add_node (stack, GIMP_DRAWABLE (object));
    }

  if (gimp_item_get_visible (GIMP_ITEM (object)))
    gimp_drawable_stack_drawable_visible (GIMP_ITEM (object), stack);
}

static void
gimp_drawable_stack_remove (GimpContainer *container,
                            GimpObject    *object)
{
  GimpDrawableStack *stack = GIMP_DRAWABLE_STACK (container);

  if (stack->graph)
    {
      gimp_drawable_stack_remove_node (stack, GIMP_DRAWABLE (object));

      gegl_node_remove_child (stack->graph,
                              gimp_item_get_node (GIMP_ITEM (object)));
    }

  GIMP_CONTAINER_CLASS (parent_class)->remove (container, object);

  if (gimp_item_get_visible (GIMP_ITEM (object)))
    gimp_drawable_stack_drawable_visible (GIMP_ITEM (object), stack);
}

static void
gimp_drawable_stack_reorder (GimpContainer *container,
                             GimpObject    *object,
                             gint           new_index)
{
  GimpDrawableStack *stack = GIMP_DRAWABLE_STACK (container);

  if (stack->graph)
    gimp_drawable_stack_remove_node (stack, GIMP_DRAWABLE (object));

  GIMP_CONTAINER_CLASS (parent_class)->reorder (container, object, new_index);

  if (stack->graph)
    gimp_drawable_stack_add_node (stack, GIMP_DRAWABLE (object));

  if (gimp_item_get_visible (GIMP_ITEM (object)))
    gimp_drawable_stack_drawable_visible (GIMP_ITEM (object), stack);
}


/*  public functions  */

GimpContainer *
gimp_drawable_stack_new (GType drawable_type)
{
  g_return_val_if_fail (g_type_is_a (drawable_type, GIMP_TYPE_DRAWABLE), NULL);

  return g_object_new (GIMP_TYPE_DRAWABLE_STACK,
                       "name",          g_type_name (drawable_type),
                       "children-type", drawable_type,
                       "policy",        GIMP_CONTAINER_POLICY_STRONG,
                       NULL);
}

GeglNode *
gimp_drawable_stack_get_graph (GimpDrawableStack *stack)
{
  GList    *list;
  GList    *reverse_list = NULL;
  GeglNode *previous     = NULL;
  GeglNode *output;

  g_return_val_if_fail (GIMP_IS_DRAWABLE_STACK (stack), NULL);

  if (stack->graph)
    return stack->graph;

  for (list = GIMP_LIST (stack)->list;
       list;
       list = g_list_next (list))
    {
      GimpDrawable *drawable = list->data;

      reverse_list = g_list_prepend (reverse_list, drawable);
    }

  stack->graph = gegl_node_new ();

  for (list = reverse_list; list; list = g_list_next (list))
    {
      GimpDrawable *drawable = list->data;
      GeglNode     *node     = gimp_item_get_node (GIMP_ITEM (drawable));

      gegl_node_add_child (stack->graph, node);

      if (previous)
        gegl_node_connect_to (previous, "output",
                              node,     "input");

      previous = node;
    }

  g_list_free (reverse_list);

  output = gegl_node_get_output_proxy (stack->graph, "output");

  if (previous)
    gegl_node_connect_to (previous, "output",
                          output,   "input");

  return stack->graph;
}


/*  private functions  */

static void
gimp_drawable_stack_add_node (GimpDrawableStack *stack,
                              GimpDrawable      *drawable)
{
  GimpDrawable *drawable_below;
  GeglNode     *node_above;
  GeglNode     *node;
  gint          index;

  node = gimp_item_get_node (GIMP_ITEM (drawable));

  index = gimp_container_get_child_index (GIMP_CONTAINER (stack),
                                          GIMP_OBJECT (drawable));

  if (index == 0)
    {
      node_above = gegl_node_get_output_proxy (stack->graph, "output");
    }
  else
    {
      GimpDrawable *drawable_above;

      drawable_above = (GimpDrawable *)
        gimp_container_get_child_by_index (GIMP_CONTAINER (stack), index - 1);

      node_above = gimp_item_get_node (GIMP_ITEM (drawable_above));
    }

  gegl_node_connect_to (node,       "output",
                        node_above, "input");

  drawable_below = (GimpDrawable *)
    gimp_container_get_child_by_index (GIMP_CONTAINER (stack), index + 1);

  if (drawable_below)
    {
      GeglNode *node_below = gimp_item_get_node (GIMP_ITEM (drawable_below));

      gegl_node_connect_to (node_below, "output",
                            node,       "input");
    }
}

static void
gimp_drawable_stack_remove_node (GimpDrawableStack *stack,
                                 GimpDrawable      *drawable)
{
  GimpDrawable *drawable_below;
  GeglNode     *node_above;
  GeglNode     *node;
  gint          index;

  node = gimp_item_get_node (GIMP_ITEM (drawable));

  index = gimp_container_get_child_index (GIMP_CONTAINER (stack),
                                          GIMP_OBJECT (drawable));

  if (index == 0)
    {
      node_above = gegl_node_get_output_proxy (stack->graph, "output");
    }
  else
    {
      GimpDrawable *drawable_above;

      drawable_above = (GimpDrawable *)
        gimp_container_get_child_by_index (GIMP_CONTAINER (stack), index - 1);

      node_above = gimp_item_get_node (GIMP_ITEM (drawable_above));
    }

  drawable_below = (GimpDrawable *)
    gimp_container_get_child_by_index (GIMP_CONTAINER (stack), index + 1);

  if (drawable_below)
    {
      GeglNode *node_below = gimp_item_get_node (GIMP_ITEM (drawable_below));

      gegl_node_disconnect (node,       "input");
      gegl_node_connect_to (node_below, "output",
                            node_above, "input");
    }
  else
    {
      gegl_node_disconnect (node_above, "input");
    }
}

static void
gimp_drawable_stack_update (GimpDrawableStack *stack,
                            gint               x,
                            gint               y,
                            gint               width,
                            gint               height)
{
  g_signal_emit (stack, stack_signals[UPDATE], 0,
                 x, y, width, height);
}

static void
gimp_drawable_stack_drawable_update (GimpItem          *item,
                                     gint               x,
                                     gint               y,
                                     gint               width,
                                     gint               height,
                                     GimpDrawableStack *stack)
{
  if (gimp_item_get_visible (item))
    {
      gint offset_x;
      gint offset_y;

      gimp_item_get_offset (item, &offset_x, &offset_y);

      gimp_drawable_stack_update (stack,
                                  x + offset_x, y + offset_y,
                                  width, height);
    }
}

static void
gimp_drawable_stack_drawable_visible (GimpItem          *item,
                                      GimpDrawableStack *stack)
{
  gint offset_x;
  gint offset_y;

  gimp_item_get_offset (item, &offset_x, &offset_y);

  gimp_drawable_stack_update (stack,
                              offset_x, offset_y,
                              gimp_item_get_width  (item),
                              gimp_item_get_height (item));
}
