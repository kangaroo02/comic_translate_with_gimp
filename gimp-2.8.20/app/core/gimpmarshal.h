
#ifndef __gimp_marshal_MARSHAL_H__
#define __gimp_marshal_MARSHAL_H__

#include	<glib-object.h>

G_BEGIN_DECLS

/* BOOLEAN:BOOLEAN (./gimpmarshal.list:25) */
extern void gimp_marshal_BOOLEAN__BOOLEAN (GClosure     *closure,
                                           GValue       *return_value,
                                           guint         n_param_values,
                                           const GValue *param_values,
                                           gpointer      invocation_hint,
                                           gpointer      marshal_data);

/* BOOLEAN:ENUM,INT (./gimpmarshal.list:26) */
extern void gimp_marshal_BOOLEAN__ENUM_INT (GClosure     *closure,
                                            GValue       *return_value,
                                            guint         n_param_values,
                                            const GValue *param_values,
                                            gpointer      invocation_hint,
                                            gpointer      marshal_data);

/* BOOLEAN:OBJECT,POINTER (./gimpmarshal.list:27) */
extern void gimp_marshal_BOOLEAN__OBJECT_POINTER (GClosure     *closure,
                                                  GValue       *return_value,
                                                  guint         n_param_values,
                                                  const GValue *param_values,
                                                  gpointer      invocation_hint,
                                                  gpointer      marshal_data);

/* BOOLEAN:OBJECT,POINTER,STRING (./gimpmarshal.list:28) */
extern void gimp_marshal_BOOLEAN__OBJECT_POINTER_STRING (GClosure     *closure,
                                                         GValue       *return_value,
                                                         guint         n_param_values,
                                                         const GValue *param_values,
                                                         gpointer      invocation_hint,
                                                         gpointer      marshal_data);

/* BOOLEAN:STRING (./gimpmarshal.list:29) */
extern void gimp_marshal_BOOLEAN__STRING (GClosure     *closure,
                                          GValue       *return_value,
                                          guint         n_param_values,
                                          const GValue *param_values,
                                          gpointer      invocation_hint,
                                          gpointer      marshal_data);

/* BOOLEAN:STRING,FLAGS (./gimpmarshal.list:30) */
extern void gimp_marshal_BOOLEAN__STRING_FLAGS (GClosure     *closure,
                                                GValue       *return_value,
                                                guint         n_param_values,
                                                const GValue *param_values,
                                                gpointer      invocation_hint,
                                                gpointer      marshal_data);

/* VOID:BOOLEAN (./gimpmarshal.list:32) */
#define gimp_marshal_VOID__BOOLEAN	g_cclosure_marshal_VOID__BOOLEAN

/* VOID:BOOLEAN,INT,INT,INT,INT (./gimpmarshal.list:33) */
extern void gimp_marshal_VOID__BOOLEAN_INT_INT_INT_INT (GClosure     *closure,
                                                        GValue       *return_value,
                                                        guint         n_param_values,
                                                        const GValue *param_values,
                                                        gpointer      invocation_hint,
                                                        gpointer      marshal_data);

/* VOID:BOXED (./gimpmarshal.list:34) */
#define gimp_marshal_VOID__BOXED	g_cclosure_marshal_VOID__BOXED

/* VOID:BOXED,ENUM (./gimpmarshal.list:35) */
extern void gimp_marshal_VOID__BOXED_ENUM (GClosure     *closure,
                                           GValue       *return_value,
                                           guint         n_param_values,
                                           const GValue *param_values,
                                           gpointer      invocation_hint,
                                           gpointer      marshal_data);

/* VOID:DOUBLE (./gimpmarshal.list:36) */
#define gimp_marshal_VOID__DOUBLE	g_cclosure_marshal_VOID__DOUBLE

/* VOID:DOUBLE,DOUBLE (./gimpmarshal.list:37) */
extern void gimp_marshal_VOID__DOUBLE_DOUBLE (GClosure     *closure,
                                              GValue       *return_value,
                                              guint         n_param_values,
                                              const GValue *param_values,
                                              gpointer      invocation_hint,
                                              gpointer      marshal_data);

/* VOID:DOUBLE,DOUBLE,DOUBLE,DOUBLE (./gimpmarshal.list:38) */
extern void gimp_marshal_VOID__DOUBLE_DOUBLE_DOUBLE_DOUBLE (GClosure     *closure,
                                                            GValue       *return_value,
                                                            guint         n_param_values,
                                                            const GValue *param_values,
                                                            gpointer      invocation_hint,
                                                            gpointer      marshal_data);

/* VOID:ENUM (./gimpmarshal.list:39) */
#define gimp_marshal_VOID__ENUM	g_cclosure_marshal_VOID__ENUM

/* VOID:ENUM,ENUM,BOXED,INT (./gimpmarshal.list:40) */
extern void gimp_marshal_VOID__ENUM_ENUM_BOXED_INT (GClosure     *closure,
                                                    GValue       *return_value,
                                                    guint         n_param_values,
                                                    const GValue *param_values,
                                                    gpointer      invocation_hint,
                                                    gpointer      marshal_data);

/* VOID:ENUM,INT (./gimpmarshal.list:41) */
extern void gimp_marshal_VOID__ENUM_INT (GClosure     *closure,
                                         GValue       *return_value,
                                         guint         n_param_values,
                                         const GValue *param_values,
                                         gpointer      invocation_hint,
                                         gpointer      marshal_data);

/* VOID:ENUM,INT,BOOLEAN (./gimpmarshal.list:42) */
extern void gimp_marshal_VOID__ENUM_INT_BOOLEAN (GClosure     *closure,
                                                 GValue       *return_value,
                                                 guint         n_param_values,
                                                 const GValue *param_values,
                                                 gpointer      invocation_hint,
                                                 gpointer      marshal_data);

/* VOID:ENUM,OBJECT (./gimpmarshal.list:43) */
extern void gimp_marshal_VOID__ENUM_OBJECT (GClosure     *closure,
                                            GValue       *return_value,
                                            guint         n_param_values,
                                            const GValue *param_values,
                                            gpointer      invocation_hint,
                                            gpointer      marshal_data);

/* VOID:ENUM,POINTER (./gimpmarshal.list:44) */
extern void gimp_marshal_VOID__ENUM_POINTER (GClosure     *closure,
                                             GValue       *return_value,
                                             guint         n_param_values,
                                             const GValue *param_values,
                                             gpointer      invocation_hint,
                                             gpointer      marshal_data);

/* VOID:FLAGS (./gimpmarshal.list:45) */
#define gimp_marshal_VOID__FLAGS	g_cclosure_marshal_VOID__FLAGS

/* VOID:INT (./gimpmarshal.list:46) */
#define gimp_marshal_VOID__INT	g_cclosure_marshal_VOID__INT

/* VOID:INT,INT (./gimpmarshal.list:47) */
extern void gimp_marshal_VOID__INT_INT (GClosure     *closure,
                                        GValue       *return_value,
                                        guint         n_param_values,
                                        const GValue *param_values,
                                        gpointer      invocation_hint,
                                        gpointer      marshal_data);

/* VOID:INT,INT,INT,INT (./gimpmarshal.list:48) */
extern void gimp_marshal_VOID__INT_INT_INT_INT (GClosure     *closure,
                                                GValue       *return_value,
                                                guint         n_param_values,
                                                const GValue *param_values,
                                                gpointer      invocation_hint,
                                                gpointer      marshal_data);

/* VOID:OBJECT (./gimpmarshal.list:49) */
#define gimp_marshal_VOID__OBJECT	g_cclosure_marshal_VOID__OBJECT

/* VOID:OBJECT,BOOLEAN (./gimpmarshal.list:50) */
extern void gimp_marshal_VOID__OBJECT_BOOLEAN (GClosure     *closure,
                                               GValue       *return_value,
                                               guint         n_param_values,
                                               const GValue *param_values,
                                               gpointer      invocation_hint,
                                               gpointer      marshal_data);

/* VOID:OBJECT,INT (./gimpmarshal.list:51) */
extern void gimp_marshal_VOID__OBJECT_INT (GClosure     *closure,
                                           GValue       *return_value,
                                           guint         n_param_values,
                                           const GValue *param_values,
                                           gpointer      invocation_hint,
                                           gpointer      marshal_data);

/* VOID:OBJECT,OBJECT (./gimpmarshal.list:52) */
extern void gimp_marshal_VOID__OBJECT_OBJECT (GClosure     *closure,
                                              GValue       *return_value,
                                              guint         n_param_values,
                                              const GValue *param_values,
                                              gpointer      invocation_hint,
                                              gpointer      marshal_data);

/* VOID:OBJECT,POINTER (./gimpmarshal.list:53) */
extern void gimp_marshal_VOID__OBJECT_POINTER (GClosure     *closure,
                                               GValue       *return_value,
                                               guint         n_param_values,
                                               const GValue *param_values,
                                               gpointer      invocation_hint,
                                               gpointer      marshal_data);

/* VOID:POINTER (./gimpmarshal.list:54) */
#define gimp_marshal_VOID__POINTER	g_cclosure_marshal_VOID__POINTER

/* VOID:POINTER,BOXED (./gimpmarshal.list:55) */
extern void gimp_marshal_VOID__POINTER_BOXED (GClosure     *closure,
                                              GValue       *return_value,
                                              guint         n_param_values,
                                              const GValue *param_values,
                                              gpointer      invocation_hint,
                                              gpointer      marshal_data);

/* VOID:POINTER,ENUM (./gimpmarshal.list:56) */
extern void gimp_marshal_VOID__POINTER_ENUM (GClosure     *closure,
                                             GValue       *return_value,
                                             guint         n_param_values,
                                             const GValue *param_values,
                                             gpointer      invocation_hint,
                                             gpointer      marshal_data);

/* VOID:POINTER,FLAGS,BOOLEAN (./gimpmarshal.list:57) */
extern void gimp_marshal_VOID__POINTER_FLAGS_BOOLEAN (GClosure     *closure,
                                                      GValue       *return_value,
                                                      guint         n_param_values,
                                                      const GValue *param_values,
                                                      gpointer      invocation_hint,
                                                      gpointer      marshal_data);

/* VOID:POINTER,UINT,FLAGS (./gimpmarshal.list:58) */
extern void gimp_marshal_VOID__POINTER_UINT_FLAGS (GClosure     *closure,
                                                   GValue       *return_value,
                                                   guint         n_param_values,
                                                   const GValue *param_values,
                                                   gpointer      invocation_hint,
                                                   gpointer      marshal_data);

/* VOID:STRING (./gimpmarshal.list:59) */
#define gimp_marshal_VOID__STRING	g_cclosure_marshal_VOID__STRING

/* VOID:STRING,BOOLEAN,UINT,FLAGS (./gimpmarshal.list:60) */
extern void gimp_marshal_VOID__STRING_BOOLEAN_UINT_FLAGS (GClosure     *closure,
                                                          GValue       *return_value,
                                                          guint         n_param_values,
                                                          const GValue *param_values,
                                                          gpointer      invocation_hint,
                                                          gpointer      marshal_data);

/* VOID:STRING,FLAGS (./gimpmarshal.list:61) */
extern void gimp_marshal_VOID__STRING_FLAGS (GClosure     *closure,
                                             GValue       *return_value,
                                             guint         n_param_values,
                                             const GValue *param_values,
                                             gpointer      invocation_hint,
                                             gpointer      marshal_data);

/* VOID:STRING,STRING,STRING (./gimpmarshal.list:62) */
extern void gimp_marshal_VOID__STRING_STRING_STRING (GClosure     *closure,
                                                     GValue       *return_value,
                                                     guint         n_param_values,
                                                     const GValue *param_values,
                                                     gpointer      invocation_hint,
                                                     gpointer      marshal_data);

/* VOID:VOID (./gimpmarshal.list:63) */
#define gimp_marshal_VOID__VOID	g_cclosure_marshal_VOID__VOID

G_END_DECLS

#endif /* __gimp_marshal_MARSHAL_H__ */

