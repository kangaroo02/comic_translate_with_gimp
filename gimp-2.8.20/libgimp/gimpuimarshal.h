
#ifndef ___gimpui_marshal_MARSHAL_H__
#define ___gimpui_marshal_MARSHAL_H__

#include	<glib-object.h>

G_BEGIN_DECLS

/* VOID:STRING,BOOLEAN (./gimpuimarshal.list:25) */
extern void _gimpui_marshal_VOID__STRING_BOOLEAN (GClosure     *closure,
                                                  GValue       *return_value,
                                                  guint         n_param_values,
                                                  const GValue *param_values,
                                                  gpointer      invocation_hint,
                                                  gpointer      marshal_data);

/* VOID:STRING,INT,POINTER,BOOLEAN (./gimpuimarshal.list:26) */
extern void _gimpui_marshal_VOID__STRING_INT_POINTER_BOOLEAN (GClosure     *closure,
                                                              GValue       *return_value,
                                                              guint         n_param_values,
                                                              const GValue *param_values,
                                                              gpointer      invocation_hint,
                                                              gpointer      marshal_data);

/* VOID:STRING,INT,INT,INT,POINTER,BOOLEAN (./gimpuimarshal.list:27) */
extern void _gimpui_marshal_VOID__STRING_INT_INT_INT_POINTER_BOOLEAN (GClosure     *closure,
                                                                      GValue       *return_value,
                                                                      guint         n_param_values,
                                                                      const GValue *param_values,
                                                                      gpointer      invocation_hint,
                                                                      gpointer      marshal_data);

/* VOID:STRING,DOUBLE,INT,INT,INT,INT,POINTER,BOOLEAN (./gimpuimarshal.list:28) */
extern void _gimpui_marshal_VOID__STRING_DOUBLE_INT_INT_INT_INT_POINTER_BOOLEAN (GClosure     *closure,
                                                                                 GValue       *return_value,
                                                                                 guint         n_param_values,
                                                                                 const GValue *param_values,
                                                                                 gpointer      invocation_hint,
                                                                                 gpointer      marshal_data);

G_END_DECLS

#endif /* ___gimpui_marshal_MARSHAL_H__ */

