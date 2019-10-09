/* -- THIS FILE IS GENERATED - DO NOT EDIT *//* -*- Mode: C; c-basic-offset: 4 -*- */

#include <Python.h>



#line 2 "gimpui.override"
#include <Python.h>

#define NO_IMPORT_PYGOBJECT
#include <pygobject.h>

#include <libgimp/gimp.h>
#undef GIMP_DISABLE_DEPRECATED
#include <libgimp/gimpui.h>
#define GIMP_DISABLE_DEPRECATED

#define NO_IMPORT_PYGIMP
#include "pygimp-api.h"

#define NO_IMPORT_PYGIMPCOLOR
#include "pygimpcolor-api.h"

typedef struct {
    PyObject *constraint;
    PyObject *user_data;
} PyGimpConstraintData;

typedef struct {
    PyObject *sensitivity_func;
    PyObject *user_data;
} PyGimpIntSensitivityData;

/* TODO: Add a header for these */
void gimpui_register_classes(PyObject *d);
void gimpui_add_constants(PyObject *module, const gchar *strip_prefix);

static void
pygimp_decref_callback(PyObject* obj) {
    Py_XDECREF (obj);
}

#line 44 "gimpui.c"


/* ---------- types from other modules ---------- */
static PyTypeObject *_PyGObject_Type;
#define PyGObject_Type (*_PyGObject_Type)
static PyTypeObject *_PyGdkPixbuf_Type;
#define PyGdkPixbuf_Type (*_PyGdkPixbuf_Type)
static PyTypeObject *_PyGtkObject_Type;
#define PyGtkObject_Type (*_PyGtkObject_Type)
static PyTypeObject *_PyGtkWidget_Type;
#define PyGtkWidget_Type (*_PyGtkWidget_Type)
static PyTypeObject *_PyGtkDialog_Type;
#define PyGtkDialog_Type (*_PyGtkDialog_Type)
static PyTypeObject *_PyGtkWindow_Type;
#define PyGtkWindow_Type (*_PyGtkWindow_Type)
static PyTypeObject *_PyGtkLabel_Type;
#define PyGtkLabel_Type (*_PyGtkLabel_Type)
static PyTypeObject *_PyGtkButton_Type;
#define PyGtkButton_Type (*_PyGtkButton_Type)
static PyTypeObject *_PyGtkToggleButton_Type;
#define PyGtkToggleButton_Type (*_PyGtkToggleButton_Type)
static PyTypeObject *_PyGtkRadioButton_Type;
#define PyGtkRadioButton_Type (*_PyGtkRadioButton_Type)
static PyTypeObject *_PyGtkSpinButton_Type;
#define PyGtkSpinButton_Type (*_PyGtkSpinButton_Type)
static PyTypeObject *_PyGtkEntry_Type;
#define PyGtkEntry_Type (*_PyGtkEntry_Type)
static PyTypeObject *_PyGtkDrawingArea_Type;
#define PyGtkDrawingArea_Type (*_PyGtkDrawingArea_Type)
static PyTypeObject *_PyGtkTable_Type;
#define PyGtkTable_Type (*_PyGtkTable_Type)
static PyTypeObject *_PyGtkFrame_Type;
#define PyGtkFrame_Type (*_PyGtkFrame_Type)
static PyTypeObject *_PyGtkHBox_Type;
#define PyGtkHBox_Type (*_PyGtkHBox_Type)
static PyTypeObject *_PyGtkVBox_Type;
#define PyGtkVBox_Type (*_PyGtkVBox_Type)
static PyTypeObject *_PyGtkHPaned_Type;
#define PyGtkHPaned_Type (*_PyGtkHPaned_Type)
static PyTypeObject *_PyGtkVPaned_Type;
#define PyGtkVPaned_Type (*_PyGtkVPaned_Type)
static PyTypeObject *_PyGtkScale_Type;
#define PyGtkScale_Type (*_PyGtkScale_Type)
static PyTypeObject *_PyGtkProgressBar_Type;
#define PyGtkProgressBar_Type (*_PyGtkProgressBar_Type)
static PyTypeObject *_PyGtkOptionMenu_Type;
#define PyGtkOptionMenu_Type (*_PyGtkOptionMenu_Type)
static PyTypeObject *_PyGtkComboBox_Type;
#define PyGtkComboBox_Type (*_PyGtkComboBox_Type)
static PyTypeObject *_PyGtkListStore_Type;
#define PyGtkListStore_Type (*_PyGtkListStore_Type)
static PyTypeObject *_PyGtkTreeModel_Type;
#define PyGtkTreeModel_Type (*_PyGtkTreeModel_Type)
static PyTypeObject *_PyGtkCellRenderer_Type;
#define PyGtkCellRenderer_Type (*_PyGtkCellRenderer_Type)
static PyTypeObject *_PyGtkCellRendererToggle_Type;
#define PyGtkCellRendererToggle_Type (*_PyGtkCellRendererToggle_Type)
static PyTypeObject *_PyGimpParasite_Type;
#define PyGimpParasite_Type (*_PyGimpParasite_Type)


/* ---------- forward type declarations ---------- */
PyTypeObject G_GNUC_INTERNAL PyGimpBrowser_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpButton_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpCellRendererColor_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpCellRendererToggle_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpChainButton_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpColorArea_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpColorButton_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpColorDisplay_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpColorDisplayStack_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpColorHexEntry_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpColorProfileComboBox_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpColorProfileStore_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpColorScale_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpColorScales_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpColorSelection_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpColorSelector_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpColorNotebook_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpDialog_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpEnumLabel_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpFrame_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpHintBox_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpIntComboBox_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpImageComboBox_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpEnumComboBox_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpDrawableComboBox_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpChannelComboBox_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpIntStore_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpEnumStore_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpLayerComboBox_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpMemsizeEntry_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpNumberPairEntry_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpOffsetArea_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpPageSelector_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpPathEditor_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpPickButton_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpPreview_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpAspectPreview_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpPreviewArea_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpProcBrowserDialog_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpProgressBar_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpScrolledPreview_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpDrawablePreview_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpSelectButton_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpPatternSelectButton_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpPaletteSelectButton_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpGradientSelectButton_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpFontSelectButton_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpBrushSelectButton_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpRuler_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpSizeEntry_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpStringComboBox_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpUnitComboBox_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpUnitMenu_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpVectorsComboBox_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpZoomModel_Type;
PyTypeObject G_GNUC_INTERNAL PyGimpZoomPreview_Type;

#line 164 "gimpui.c"



/* ----------- GimpBrowser ----------- */

static int
_wrap_gimp_browser_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char* kwlist[] = { NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     ":gimpui.Browser.__init__",
                                     kwlist))
        return -1;

    pygobject_constructv(self, 0, NULL);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create gimpui.Browser object");
        return -1;
    }
    return 0;
}

#line 1371 "gimpui.override"
static PyObject *
_wrap_gimp_browser_add_search_types(PyGObject *self, PyObject *args)
{
    GimpBrowser *browser;
    int len, i;
    PyObject *element;
    gchar *label;
    gint id;

    browser = GIMP_BROWSER(self->obj);

    len = PyTuple_Size(args);

    for (i = 0; i < len; ++i) {
        element = PyTuple_GetItem(args, i);
        if (!PyTuple_Check(element)) {
            PyErr_SetString(PyExc_TypeError, "GimpBrowser.add_search_types: Arguments must be tuples");
            return NULL;
        }
        if (!PyArg_ParseTuple(element, "si",  &label, &id))
            return NULL;
        gimp_browser_add_search_types(browser, label, id, NULL);
    }

    Py_INCREF(Py_None);
    return Py_None;
}
#line 218 "gimpui.c"


static PyObject *
_wrap_gimp_browser_set_widget(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "widget", NULL };
    PyGObject *widget;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:Gimp.Browser.set_widget", kwlist, &PyGtkWidget_Type, &widget))
        return NULL;
    
    gimp_browser_set_widget(GIMP_BROWSER(self->obj), GTK_WIDGET(widget->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_browser_show_message(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "message", NULL };
    char *message;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:Gimp.Browser.show_message", kwlist, &message))
        return NULL;
    
    gimp_browser_show_message(GIMP_BROWSER(self->obj), message);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyGimpBrowser_methods[] = {
    { "add_search_types", (PyCFunction)_wrap_gimp_browser_add_search_types, METH_VARARGS,
      NULL },
    { "set_widget", (PyCFunction)_wrap_gimp_browser_set_widget, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "show_message", (PyCFunction)_wrap_gimp_browser_show_message, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpBrowser_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.Browser",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpBrowser_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_browser_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpButton ----------- */

static int
_wrap_gimp_button_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char* kwlist[] = { NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     ":gimpui.Button.__init__",
                                     kwlist))
        return -1;

    pygobject_constructv(self, 0, NULL);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create gimpui.Button object");
        return -1;
    }
    return 0;
}

static PyObject *
_wrap_gimp_button_extended_clicked(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "state", NULL };
    PyObject *py_state = NULL;
    GdkModifierType state;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:Gimp.Button.extended_clicked", kwlist, &py_state))
        return NULL;
    if (pyg_flags_get_value(GDK_TYPE_MODIFIER_TYPE, py_state, (gpointer)&state))
        return NULL;
    
    gimp_button_extended_clicked(GIMP_BUTTON(self->obj), state);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyGimpButton_methods[] = {
    { "extended_clicked", (PyCFunction)_wrap_gimp_button_extended_clicked, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpButton_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.Button",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpButton_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_button_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpCellRendererColor ----------- */

static int
_wrap_gimp_cell_renderer_color_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char* kwlist[] = { NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     ":gimpui.CellRendererColor.__init__",
                                     kwlist))
        return -1;

    pygobject_constructv(self, 0, NULL);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create gimpui.CellRendererColor object");
        return -1;
    }
    return 0;
}

PyTypeObject G_GNUC_INTERNAL PyGimpCellRendererColor_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.CellRendererColor",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_cell_renderer_color_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpCellRendererToggle ----------- */

static int
_wrap_gimp_cell_renderer_toggle_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    GType obj_type = pyg_type_from_object((PyObject *) self);
    GParameter params[1];
    PyObject *parsed_args[1] = {NULL, };
    char *arg_names[] = {"stock_id", NULL };
    char *prop_names[] = {"stock-id", NULL };
    guint nparams, i;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "|O:gimpui.CellRendererToggle.__init__" , arg_names , &parsed_args[0]))
        return -1;

    memset(params, 0, sizeof(GParameter)*1);
    if (!pyg_parse_constructor_args(obj_type, arg_names,
                                    prop_names, params, 
                                    &nparams, parsed_args))
        return -1;
    pygobject_constructv(self, nparams, params);
    for (i = 0; i < nparams; ++i)
        g_value_unset(&params[i].value);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create gimpui.CellRendererToggle object");
        return -1;
    }
    return 0;
}

static PyObject *
_wrap_gimp_cell_renderer_toggle_clicked(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "path", "state", NULL };
    char *path;
    PyObject *py_state = NULL;
    GdkModifierType state;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"sO:Gimp.CellRendererToggle.clicked", kwlist, &path, &py_state))
        return NULL;
    if (pyg_flags_get_value(GDK_TYPE_MODIFIER_TYPE, py_state, (gpointer)&state))
        return NULL;
    
    gimp_cell_renderer_toggle_clicked(GIMP_CELL_RENDERER_TOGGLE(self->obj), path, state);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyGimpCellRendererToggle_methods[] = {
    { "clicked", (PyCFunction)_wrap_gimp_cell_renderer_toggle_clicked, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpCellRendererToggle_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.CellRendererToggle",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpCellRendererToggle_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_cell_renderer_toggle_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpChainButton ----------- */

 static int
_wrap_gimp_chain_button_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    GType obj_type = pyg_type_from_object((PyObject *) self);
    GParameter params[1];
    PyObject *parsed_args[1] = {NULL, };
    char *arg_names[] = {"position", NULL };
    char *prop_names[] = {"position", NULL };
    guint nparams, i;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O:gimpui.ChainButton.__init__" , arg_names , &parsed_args[0]))
        return -1;

    memset(params, 0, sizeof(GParameter)*1);
    if (!pyg_parse_constructor_args(obj_type, arg_names,
                                    prop_names, params, 
                                    &nparams, parsed_args))
        return -1;
    pygobject_constructv(self, nparams, params);
    for (i = 0; i < nparams; ++i)
        g_value_unset(&params[i].value);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create gimpui.ChainButton object");
        return -1;
    }
    return 0;
}

static PyObject *
_wrap_gimp_chain_button_set_active(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "active", NULL };
    int active;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Gimp.ChainButton.set_active", kwlist, &active))
        return NULL;
    
    gimp_chain_button_set_active(GIMP_CHAIN_BUTTON(self->obj), active);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_chain_button_get_active(PyGObject *self)
{
    int ret;

    
    ret = gimp_chain_button_get_active(GIMP_CHAIN_BUTTON(self->obj));
    
    return PyBool_FromLong(ret);

}

static const PyMethodDef _PyGimpChainButton_methods[] = {
    { "set_active", (PyCFunction)_wrap_gimp_chain_button_set_active, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_active", (PyCFunction)_wrap_gimp_chain_button_get_active, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpChainButton_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.ChainButton",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpChainButton_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_chain_button_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpColorArea ----------- */

 static int
_wrap_gimp_color_area_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    GType obj_type = pyg_type_from_object((PyObject *) self);
    GParameter params[3];
    PyObject *parsed_args[3] = {NULL, };
    char *arg_names[] = {"color", "type", "drag_mask", NULL };
    char *prop_names[] = {"color", "type", "drag-mask", NULL };
    guint nparams, i;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "|OOO:gimpui.ColorArea.__init__" , arg_names , &parsed_args[0] , &parsed_args[1] , &parsed_args[2]))
        return -1;

    memset(params, 0, sizeof(GParameter)*3);
    if (!pyg_parse_constructor_args(obj_type, arg_names,
                                    prop_names, params, 
                                    &nparams, parsed_args))
        return -1;
    pygobject_constructv(self, nparams, params);
    for (i = 0; i < nparams; ++i)
        g_value_unset(&params[i].value);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create gimpui.ColorArea object");
        return -1;
    }
    return 0;
}

static PyObject *
_wrap_gimp_color_area_set_color(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "color", NULL };
    PyObject *py_color;
    GimpRGB *color = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:Gimp.ColorArea.set_color", kwlist, &py_color))
        return NULL;
    if (pyg_boxed_check(py_color, GIMP_TYPE_RGB))
        color = pyg_boxed_get(py_color, GimpRGB);
    else {
        PyErr_SetString(PyExc_TypeError, "color should be a GimpRGB");
        return NULL;
    }
    
    gimp_color_area_set_color(GIMP_COLOR_AREA(self->obj), color);
    
    Py_INCREF(Py_None);
    return Py_None;
}

#line 1788 "gimpui.override"
static PyObject *
_wrap_gimp_color_area_get_color(PyGObject *self)
{
    GimpRGB rgb;

    gimp_color_area_get_color(GIMP_COLOR_AREA(self->obj), &rgb);

    return pygimp_rgb_new(&rgb);
}
#line 752 "gimpui.c"


static PyObject *
_wrap_gimp_color_area_has_alpha(PyGObject *self)
{
    int ret;

    
    ret = gimp_color_area_has_alpha(GIMP_COLOR_AREA(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_gimp_color_area_set_type(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "type", NULL };
    PyObject *py_type = NULL;
    GimpColorAreaType type;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:Gimp.ColorArea.set_type", kwlist, &py_type))
        return NULL;
    if (pyg_enum_get_value(GIMP_TYPE_COLOR_AREA_TYPE, py_type, (gpointer)&type))
        return NULL;
    
    gimp_color_area_set_type(GIMP_COLOR_AREA(self->obj), type);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_color_area_set_draw_border(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "draw_border", NULL };
    int draw_border;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Gimp.ColorArea.set_draw_border", kwlist, &draw_border))
        return NULL;
    
    gimp_color_area_set_draw_border(GIMP_COLOR_AREA(self->obj), draw_border);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyGimpColorArea_methods[] = {
    { "set_color", (PyCFunction)_wrap_gimp_color_area_set_color, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_color", (PyCFunction)_wrap_gimp_color_area_get_color, METH_NOARGS,
      NULL },
    { "has_alpha", (PyCFunction)_wrap_gimp_color_area_has_alpha, METH_NOARGS,
      NULL },
    { "set_type", (PyCFunction)_wrap_gimp_color_area_set_type, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_draw_border", (PyCFunction)_wrap_gimp_color_area_set_draw_border, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpColorArea_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.ColorArea",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpColorArea_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_color_area_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpColorButton ----------- */

#line 937 "gimpui.override"
static int
_wrap_gimp_color_button_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    gchar *title = NULL;
    gint width = -1, height = -1;
    PyObject *py_color = NULL, *py_type = NULL;
    GimpRGB *color, default_color = { 0.0, 0.0, 0.0, 100.0 };
    GimpColorAreaType type;
    
    static char *kwlist[] = { "title", "width", "height", "color", "type",
                              NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     "|ziiOO:gimpui.ColorButton.__init__",
                                     kwlist,
                                     &title, &width, &height,
                                     &py_color, &py_type))
        return -1;

    if (py_color == NULL || (PyObject*)py_color == Py_None)
        color = &default_color;
    else if (pyg_boxed_check(py_color, GIMP_TYPE_RGB))
        color = pyg_boxed_get(py_color, GimpRGB);
    else {
        PyErr_SetString(PyExc_TypeError, "color should be a GimpRGB or None");
        return -1;
    }

    if (py_type == NULL || (PyObject*)py_type == Py_None)
       type = GIMP_COLOR_AREA_FLAT;
    else if (pyg_enum_get_value(GIMP_TYPE_COLOR_AREA_TYPE, py_type,
                                (gint*)&type))
       return -1;

    if (pygobject_construct(self,
                            "title",       title,
                            "type",        type,
                            "color",       color,
                            "area-width",  width,
			    "area-height", height,
                            NULL))
        return -1;

    return 0;
}
#line 909 "gimpui.c"


static PyObject *
_wrap_gimp_color_button_set_color(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "color", NULL };
    PyObject *py_color;
    GimpRGB *color = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:Gimp.ColorButton.set_color", kwlist, &py_color))
        return NULL;
    if (pyg_boxed_check(py_color, GIMP_TYPE_RGB))
        color = pyg_boxed_get(py_color, GimpRGB);
    else {
        PyErr_SetString(PyExc_TypeError, "color should be a GimpRGB");
        return NULL;
    }
    
    gimp_color_button_set_color(GIMP_COLOR_BUTTON(self->obj), color);
    
    Py_INCREF(Py_None);
    return Py_None;
}

#line 899 "gimpui.override"
static PyObject *
_wrap_gimp_color_button_get_color(PyGObject *self)
{
    GimpRGB rgb;

    gimp_color_button_get_color(GIMP_COLOR_BUTTON(self->obj), &rgb);

    return pygimp_rgb_new(&rgb);
}
#line 944 "gimpui.c"


static PyObject *
_wrap_gimp_color_button_has_alpha(PyGObject *self)
{
    int ret;

    
    ret = gimp_color_button_has_alpha(GIMP_COLOR_BUTTON(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_gimp_color_button_set_type(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "type", NULL };
    PyObject *py_type = NULL;
    GimpColorAreaType type;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:Gimp.ColorButton.set_type", kwlist, &py_type))
        return NULL;
    if (pyg_enum_get_value(GIMP_TYPE_COLOR_AREA_TYPE, py_type, (gpointer)&type))
        return NULL;
    
    gimp_color_button_set_type(GIMP_COLOR_BUTTON(self->obj), type);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_color_button_get_update(PyGObject *self)
{
    int ret;

    
    ret = gimp_color_button_get_update(GIMP_COLOR_BUTTON(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_gimp_color_button_set_update(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "continuous", NULL };
    int continuous;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Gimp.ColorButton.set_update", kwlist, &continuous))
        return NULL;
    
    gimp_color_button_set_update(GIMP_COLOR_BUTTON(self->obj), continuous);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyGimpColorButton_methods[] = {
    { "set_color", (PyCFunction)_wrap_gimp_color_button_set_color, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_color", (PyCFunction)_wrap_gimp_color_button_get_color, METH_NOARGS,
      NULL },
    { "has_alpha", (PyCFunction)_wrap_gimp_color_button_has_alpha, METH_NOARGS,
      NULL },
    { "set_type", (PyCFunction)_wrap_gimp_color_button_set_type, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_update", (PyCFunction)_wrap_gimp_color_button_get_update, METH_NOARGS,
      NULL },
    { "set_update", (PyCFunction)_wrap_gimp_color_button_set_update, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpColorButton_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.ColorButton",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpColorButton_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_color_button_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpColorDisplay ----------- */

static PyObject *
_wrap_gimp_color_display_clone(PyGObject *self)
{
    GimpColorDisplay *ret;

    
    ret = gimp_color_display_clone(GIMP_COLOR_DISPLAY(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_gimp_color_display_convert(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "buf", "width", "height", "bpp", "bpl", NULL };
    int buf_len, width, height, bpp, bpl;
    guchar *buf;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s#iiii:Gimp.ColorDisplay.convert", kwlist, &buf, &buf_len, &width, &height, &bpp, &bpl))
        return NULL;
    if (PyErr_Warn(PyExc_DeprecationWarning, "use convert_surface(cairo_surface_t*) instead") < 0)
        return NULL;
    
    gimp_color_display_convert(GIMP_COLOR_DISPLAY(self->obj), buf, width, height, bpp, bpl);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_color_display_configure(PyGObject *self)
{
    GtkWidget *ret;

    
    ret = gimp_color_display_configure(GIMP_COLOR_DISPLAY(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_gimp_color_display_configure_reset(PyGObject *self)
{
    
    gimp_color_display_configure_reset(GIMP_COLOR_DISPLAY(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_color_display_changed(PyGObject *self)
{
    
    gimp_color_display_changed(GIMP_COLOR_DISPLAY(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_color_display_set_enabled(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "enabled", NULL };
    int enabled;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Gimp.ColorDisplay.set_enabled", kwlist, &enabled))
        return NULL;
    
    gimp_color_display_set_enabled(GIMP_COLOR_DISPLAY(self->obj), enabled);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_color_display_get_enabled(PyGObject *self)
{
    int ret;

    
    ret = gimp_color_display_get_enabled(GIMP_COLOR_DISPLAY(self->obj));
    
    return PyBool_FromLong(ret);

}

static const PyMethodDef _PyGimpColorDisplay_methods[] = {
    { "clone", (PyCFunction)_wrap_gimp_color_display_clone, METH_NOARGS,
      NULL },
    { "convert", (PyCFunction)_wrap_gimp_color_display_convert, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "configure", (PyCFunction)_wrap_gimp_color_display_configure, METH_NOARGS,
      NULL },
    { "configure_reset", (PyCFunction)_wrap_gimp_color_display_configure_reset, METH_NOARGS,
      NULL },
    { "changed", (PyCFunction)_wrap_gimp_color_display_changed, METH_NOARGS,
      NULL },
    { "set_enabled", (PyCFunction)_wrap_gimp_color_display_set_enabled, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_enabled", (PyCFunction)_wrap_gimp_color_display_get_enabled, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpColorDisplay_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.ColorDisplay",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpColorDisplay_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)0,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpColorDisplayStack ----------- */

 static int
_wrap_gimp_color_display_stack_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char* kwlist[] = { NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     ":gimpui.ColorDisplayStack.__init__",
                                     kwlist))
        return -1;

    pygobject_constructv(self, 0, NULL);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create gimpui.ColorDisplayStack object");
        return -1;
    }
    return 0;
}

static PyObject *
_wrap_gimp_color_display_stack_clone(PyGObject *self)
{
    GimpColorDisplayStack *ret;

    
    ret = gimp_color_display_stack_clone(GIMP_COLOR_DISPLAY_STACK(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_gimp_color_display_stack_changed(PyGObject *self)
{
    
    gimp_color_display_stack_changed(GIMP_COLOR_DISPLAY_STACK(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_color_display_stack_add(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "display", NULL };
    PyGObject *display;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:Gimp.ColorDisplayStack.add", kwlist, &PyGimpColorDisplay_Type, &display))
        return NULL;
    
    gimp_color_display_stack_add(GIMP_COLOR_DISPLAY_STACK(self->obj), GIMP_COLOR_DISPLAY(display->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_color_display_stack_remove(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "display", NULL };
    PyGObject *display;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:Gimp.ColorDisplayStack.remove", kwlist, &PyGimpColorDisplay_Type, &display))
        return NULL;
    
    gimp_color_display_stack_remove(GIMP_COLOR_DISPLAY_STACK(self->obj), GIMP_COLOR_DISPLAY(display->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_color_display_stack_reorder_up(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "display", NULL };
    PyGObject *display;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:Gimp.ColorDisplayStack.reorder_up", kwlist, &PyGimpColorDisplay_Type, &display))
        return NULL;
    
    gimp_color_display_stack_reorder_up(GIMP_COLOR_DISPLAY_STACK(self->obj), GIMP_COLOR_DISPLAY(display->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_color_display_stack_reorder_down(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "display", NULL };
    PyGObject *display;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:Gimp.ColorDisplayStack.reorder_down", kwlist, &PyGimpColorDisplay_Type, &display))
        return NULL;
    
    gimp_color_display_stack_reorder_down(GIMP_COLOR_DISPLAY_STACK(self->obj), GIMP_COLOR_DISPLAY(display->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_color_display_stack_convert(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "buf", "width", "height", "bpp", "bpl", NULL };
    int buf_len, width, height, bpp, bpl;
    guchar *buf;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s#iiii:Gimp.ColorDisplayStack.convert", kwlist, &buf, &buf_len, &width, &height, &bpp, &bpl))
        return NULL;
    if (PyErr_Warn(PyExc_DeprecationWarning, "use convert_surface(cairo_surface_t*) instead") < 0)
        return NULL;
    
    gimp_color_display_stack_convert(GIMP_COLOR_DISPLAY_STACK(self->obj), buf, width, height, bpp, bpl);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyGimpColorDisplayStack_methods[] = {
    { "clone", (PyCFunction)_wrap_gimp_color_display_stack_clone, METH_NOARGS,
      NULL },
    { "changed", (PyCFunction)_wrap_gimp_color_display_stack_changed, METH_NOARGS,
      NULL },
    { "add", (PyCFunction)_wrap_gimp_color_display_stack_add, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "remove", (PyCFunction)_wrap_gimp_color_display_stack_remove, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "reorder_up", (PyCFunction)_wrap_gimp_color_display_stack_reorder_up, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "reorder_down", (PyCFunction)_wrap_gimp_color_display_stack_reorder_down, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "convert", (PyCFunction)_wrap_gimp_color_display_stack_convert, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpColorDisplayStack_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.ColorDisplayStack",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpColorDisplayStack_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_color_display_stack_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpColorHexEntry ----------- */

static int
_wrap_gimp_color_hex_entry_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char* kwlist[] = { NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     ":gimpui.ColorHexEntry.__init__",
                                     kwlist))
        return -1;

    pygobject_constructv(self, 0, NULL);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create gimpui.ColorHexEntry object");
        return -1;
    }
    return 0;
}

static PyObject *
_wrap_gimp_color_hex_entry_set_color(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "color", NULL };
    PyObject *py_color;
    GimpRGB *color = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:Gimp.ColorHexEntry.set_color", kwlist, &py_color))
        return NULL;
    if (pyg_boxed_check(py_color, GIMP_TYPE_RGB))
        color = pyg_boxed_get(py_color, GimpRGB);
    else {
        PyErr_SetString(PyExc_TypeError, "color should be a GimpRGB");
        return NULL;
    }
    
    gimp_color_hex_entry_set_color(GIMP_COLOR_HEX_ENTRY(self->obj), color);
    
    Py_INCREF(Py_None);
    return Py_None;
}

#line 1799 "gimpui.override"
static PyObject *
_wrap_gimp_color_hex_entry_get_color(PyGObject *self)
{
    GimpRGB rgb;

    gimp_color_hex_entry_get_color(GIMP_COLOR_HEX_ENTRY(self->obj), &rgb);

    return pygimp_rgb_new(&rgb);
}
#line 1464 "gimpui.c"


static const PyMethodDef _PyGimpColorHexEntry_methods[] = {
    { "set_color", (PyCFunction)_wrap_gimp_color_hex_entry_set_color, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_color", (PyCFunction)_wrap_gimp_color_hex_entry_get_color, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpColorHexEntry_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.ColorHexEntry",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpColorHexEntry_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_color_hex_entry_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpColorProfileComboBox ----------- */

static int
_wrap_gimp_color_profile_combo_box_new_with_model(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    GType obj_type = pyg_type_from_object((PyObject *) self);
    GParameter params[2];
    PyObject *parsed_args[2] = {NULL, };
    char *arg_names[] = {"dialog", "model", NULL };
    char *prop_names[] = {"dialog", "model", NULL };
    guint nparams, i;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OO:gimpui.ColorProfileComboBox.__init__" , arg_names , &parsed_args[0] , &parsed_args[1]))
        return -1;

    memset(params, 0, sizeof(GParameter)*2);
    if (!pyg_parse_constructor_args(obj_type, arg_names,
                                    prop_names, params, 
                                    &nparams, parsed_args))
        return -1;
    pygobject_constructv(self, nparams, params);
    for (i = 0; i < nparams; ++i)
        g_value_unset(&params[i].value);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create gimpui.ColorProfileComboBox object");
        return -1;
    }
    return 0;
}

static PyObject *
_wrap_gimp_color_profile_combo_box_add(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "filename", "label", NULL };
    char *filename, *label;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"ss:Gimp.ColorProfileComboBox.add", kwlist, &filename, &label))
        return NULL;
    
    gimp_color_profile_combo_box_add(GIMP_COLOR_PROFILE_COMBO_BOX(self->obj), filename, label);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_color_profile_combo_box_set_active(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "filename", "label", NULL };
    char *filename, *label;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"ss:Gimp.ColorProfileComboBox.set_active", kwlist, &filename, &label))
        return NULL;
    
    gimp_color_profile_combo_box_set_active(GIMP_COLOR_PROFILE_COMBO_BOX(self->obj), filename, label);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_color_profile_combo_box_get_active(PyGObject *self)
{
    gchar *ret;

    
    ret = gimp_color_profile_combo_box_get_active(GIMP_COLOR_PROFILE_COMBO_BOX(self->obj));
    
    if (ret) {
        PyObject *py_ret = PyString_FromString(ret);
        g_free(ret);
        return py_ret;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyGimpColorProfileComboBox_methods[] = {
    { "add", (PyCFunction)_wrap_gimp_color_profile_combo_box_add, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_active", (PyCFunction)_wrap_gimp_color_profile_combo_box_set_active, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_active", (PyCFunction)_wrap_gimp_color_profile_combo_box_get_active, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpColorProfileComboBox_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.ColorProfileComboBox",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpColorProfileComboBox_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_color_profile_combo_box_new_with_model,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpColorProfileStore ----------- */

 static int
_wrap_gimp_color_profile_store_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    GType obj_type = pyg_type_from_object((PyObject *) self);
    GParameter params[1];
    PyObject *parsed_args[1] = {NULL, };
    char *arg_names[] = {"history", NULL };
    char *prop_names[] = {"history", NULL };
    guint nparams, i;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O:gimpui.ColorProfileStore.__init__" , arg_names , &parsed_args[0]))
        return -1;

    memset(params, 0, sizeof(GParameter)*1);
    if (!pyg_parse_constructor_args(obj_type, arg_names,
                                    prop_names, params, 
                                    &nparams, parsed_args))
        return -1;
    pygobject_constructv(self, nparams, params);
    for (i = 0; i < nparams; ++i)
        g_value_unset(&params[i].value);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create gimpui.ColorProfileStore object");
        return -1;
    }
    return 0;
}

static PyObject *
_wrap_gimp_color_profile_store_add(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "filename", "label", NULL };
    char *filename, *label;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"ss:Gimp.ColorProfileStore.add", kwlist, &filename, &label))
        return NULL;
    
    gimp_color_profile_store_add(GIMP_COLOR_PROFILE_STORE(self->obj), filename, label);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyGimpColorProfileStore_methods[] = {
    { "add", (PyCFunction)_wrap_gimp_color_profile_store_add, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpColorProfileStore_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.ColorProfileStore",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpColorProfileStore_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_color_profile_store_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpColorScale ----------- */

#line 986 "gimpui.override"
static int
_wrap_gimp_color_scale_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_orientation, *py_channel;
    GtkOrientation orientation;
    GimpColorSelectorChannel channel;

    static char *kwlist[] = { "orientation", "channel", NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     "OO:gimpui.ColorScale.__init__",
                                     kwlist,
                                     &py_orientation, &py_channel))
        return -1;

    if (pyg_enum_get_value(GTK_TYPE_ORIENTATION, py_orientation,
                           (gint*)&orientation))
        return -1;

    if (pyg_enum_get_value(GIMP_TYPE_COLOR_SELECTOR_CHANNEL, py_channel, 
                           (gint*)&channel))
        return -1;

    if (pygobject_construct(self,
                            "orientation", orientation,
                            "channel",     channel,
                            NULL));
        return -1;

    gtk_range_set_flippable (GTK_RANGE (self->obj),
                             orientation == GTK_ORIENTATION_HORIZONTAL);
    
    return 0;
}
#line 1795 "gimpui.c"


static PyObject *
_wrap_gimp_color_scale_set_channel(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "channel", NULL };
    GimpColorSelectorChannel channel;
    PyObject *py_channel = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:Gimp.ColorScale.set_channel", kwlist, &py_channel))
        return NULL;
    if (pyg_enum_get_value(GIMP_TYPE_COLOR_SELECTOR_CHANNEL, py_channel, (gpointer)&channel))
        return NULL;
    
    gimp_color_scale_set_channel(GIMP_COLOR_SCALE(self->obj), channel);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_color_scale_set_color(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "rgb", "hsv", NULL };
    PyObject *py_rgb, *py_hsv;
    GimpHSV *hsv = NULL;
    GimpRGB *rgb = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"OO:Gimp.ColorScale.set_color", kwlist, &py_rgb, &py_hsv))
        return NULL;
    if (pyg_boxed_check(py_rgb, GIMP_TYPE_RGB))
        rgb = pyg_boxed_get(py_rgb, GimpRGB);
    else {
        PyErr_SetString(PyExc_TypeError, "rgb should be a GimpRGB");
        return NULL;
    }
    if (pyg_boxed_check(py_hsv, GIMP_TYPE_HSV))
        hsv = pyg_boxed_get(py_hsv, GimpHSV);
    else {
        PyErr_SetString(PyExc_TypeError, "hsv should be a GimpHSV");
        return NULL;
    }
    
    gimp_color_scale_set_color(GIMP_COLOR_SCALE(self->obj), rgb, hsv);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyGimpColorScale_methods[] = {
    { "set_channel", (PyCFunction)_wrap_gimp_color_scale_set_channel, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_color", (PyCFunction)_wrap_gimp_color_scale_set_color, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpColorScale_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.ColorScale",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpColorScale_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_color_scale_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpColorSelector ----------- */

static int
_wrap_gimp_color_selector_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "selector_type", "rgb", "hsv", "channel", NULL };
    PyObject *py_selector_type = NULL, *py_rgb, *py_hsv, *py_channel = NULL;
    GimpHSV *hsv = NULL;
    GType selector_type;
    GimpColorSelectorChannel channel;
    GimpRGB *rgb = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"OOOO:Gimp.ColorSelector.__init__", kwlist, &py_selector_type, &py_rgb, &py_hsv, &py_channel))
        return -1;
    if ((selector_type = pyg_type_from_object(py_selector_type)) == 0)
        return -1;
    if (pyg_boxed_check(py_rgb, GIMP_TYPE_RGB))
        rgb = pyg_boxed_get(py_rgb, GimpRGB);
    else {
        PyErr_SetString(PyExc_TypeError, "rgb should be a GimpRGB");
        return -1;
    }
    if (pyg_boxed_check(py_hsv, GIMP_TYPE_HSV))
        hsv = pyg_boxed_get(py_hsv, GimpHSV);
    else {
        PyErr_SetString(PyExc_TypeError, "hsv should be a GimpHSV");
        return -1;
    }
    if (pyg_enum_get_value(GIMP_TYPE_COLOR_SELECTOR_CHANNEL, py_channel, (gpointer)&channel))
        return -1;
    self->obj = (GObject *)gimp_color_selector_new(selector_type, rgb, hsv, channel);

    if (!self->obj) {
        PyErr_SetString(PyExc_RuntimeError, "could not create GimpColorSelector object");
        return -1;
    }
    pygobject_register_wrapper((PyObject *)self);
    return 0;
}

static PyObject *
_wrap_gimp_color_selector_set_toggles_visible(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "visible", NULL };
    int visible;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Gimp.ColorSelector.set_toggles_visible", kwlist, &visible))
        return NULL;
    
    gimp_color_selector_set_toggles_visible(GIMP_COLOR_SELECTOR(self->obj), visible);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_color_selector_set_toggles_sensitive(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "sensitive", NULL };
    int sensitive;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Gimp.ColorSelector.set_toggles_sensitive", kwlist, &sensitive))
        return NULL;
    
    gimp_color_selector_set_toggles_sensitive(GIMP_COLOR_SELECTOR(self->obj), sensitive);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_color_selector_set_show_alpha(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "show_alpha", NULL };
    int show_alpha;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Gimp.ColorSelector.set_show_alpha", kwlist, &show_alpha))
        return NULL;
    
    gimp_color_selector_set_show_alpha(GIMP_COLOR_SELECTOR(self->obj), show_alpha);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_color_selector_set_color(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "rgb", "hsv", NULL };
    PyObject *py_rgb, *py_hsv;
    GimpHSV *hsv = NULL;
    GimpRGB *rgb = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"OO:Gimp.ColorSelector.set_color", kwlist, &py_rgb, &py_hsv))
        return NULL;
    if (pyg_boxed_check(py_rgb, GIMP_TYPE_RGB))
        rgb = pyg_boxed_get(py_rgb, GimpRGB);
    else {
        PyErr_SetString(PyExc_TypeError, "rgb should be a GimpRGB");
        return NULL;
    }
    if (pyg_boxed_check(py_hsv, GIMP_TYPE_HSV))
        hsv = pyg_boxed_get(py_hsv, GimpHSV);
    else {
        PyErr_SetString(PyExc_TypeError, "hsv should be a GimpHSV");
        return NULL;
    }
    
    gimp_color_selector_set_color(GIMP_COLOR_SELECTOR(self->obj), rgb, hsv);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_color_selector_set_channel(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "channel", NULL };
    GimpColorSelectorChannel channel;
    PyObject *py_channel = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:Gimp.ColorSelector.set_channel", kwlist, &py_channel))
        return NULL;
    if (pyg_enum_get_value(GIMP_TYPE_COLOR_SELECTOR_CHANNEL, py_channel, (gpointer)&channel))
        return NULL;
    
    gimp_color_selector_set_channel(GIMP_COLOR_SELECTOR(self->obj), channel);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_color_selector_color_changed(PyGObject *self)
{
    
    gimp_color_selector_color_changed(GIMP_COLOR_SELECTOR(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_color_selector_channel_changed(PyGObject *self)
{
    
    gimp_color_selector_channel_changed(GIMP_COLOR_SELECTOR(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyGimpColorSelector_methods[] = {
    { "set_toggles_visible", (PyCFunction)_wrap_gimp_color_selector_set_toggles_visible, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_toggles_sensitive", (PyCFunction)_wrap_gimp_color_selector_set_toggles_sensitive, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_show_alpha", (PyCFunction)_wrap_gimp_color_selector_set_show_alpha, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_color", (PyCFunction)_wrap_gimp_color_selector_set_color, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_channel", (PyCFunction)_wrap_gimp_color_selector_set_channel, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "color_changed", (PyCFunction)_wrap_gimp_color_selector_color_changed, METH_NOARGS,
      NULL },
    { "channel_changed", (PyCFunction)_wrap_gimp_color_selector_channel_changed, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpColorSelector_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.ColorSelector",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpColorSelector_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_color_selector_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpColorScales ----------- */

PyTypeObject G_GNUC_INTERNAL PyGimpColorScales_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.ColorScales",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)0,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpColorSelection ----------- */

 static int
_wrap_gimp_color_selection_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char* kwlist[] = { NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     ":gimpui.ColorSelection.__init__",
                                     kwlist))
        return -1;

    pygobject_constructv(self, 0, NULL);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create gimpui.ColorSelection object");
        return -1;
    }
    return 0;
}

static PyObject *
_wrap_gimp_color_selection_set_show_alpha(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "show_alpha", NULL };
    int show_alpha;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Gimp.ColorSelection.set_show_alpha", kwlist, &show_alpha))
        return NULL;
    
    gimp_color_selection_set_show_alpha(GIMP_COLOR_SELECTION(self->obj), show_alpha);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_color_selection_get_show_alpha(PyGObject *self)
{
    int ret;

    
    ret = gimp_color_selection_get_show_alpha(GIMP_COLOR_SELECTION(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_gimp_color_selection_set_color(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "color", NULL };
    PyObject *py_color;
    GimpRGB *color = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:Gimp.ColorSelection.set_color", kwlist, &py_color))
        return NULL;
    if (pyg_boxed_check(py_color, GIMP_TYPE_RGB))
        color = pyg_boxed_get(py_color, GimpRGB);
    else {
        PyErr_SetString(PyExc_TypeError, "color should be a GimpRGB");
        return NULL;
    }
    
    gimp_color_selection_set_color(GIMP_COLOR_SELECTION(self->obj), color);
    
    Py_INCREF(Py_None);
    return Py_None;
}

#line 1821 "gimpui.override"
static PyObject *
_wrap_gimp_color_selection_get_color(PyGObject *self)
{
    GimpRGB rgb;

    gimp_color_selection_get_color(GIMP_COLOR_SELECTION(self->obj), &rgb);

    return pygimp_rgb_new(&rgb);
}
#line 2247 "gimpui.c"


static PyObject *
_wrap_gimp_color_selection_set_old_color(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "color", NULL };
    PyObject *py_color;
    GimpRGB *color = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:Gimp.ColorSelection.set_old_color", kwlist, &py_color))
        return NULL;
    if (pyg_boxed_check(py_color, GIMP_TYPE_RGB))
        color = pyg_boxed_get(py_color, GimpRGB);
    else {
        PyErr_SetString(PyExc_TypeError, "color should be a GimpRGB");
        return NULL;
    }
    
    gimp_color_selection_set_old_color(GIMP_COLOR_SELECTION(self->obj), color);
    
    Py_INCREF(Py_None);
    return Py_None;
}

#line 1832 "gimpui.override"
static PyObject *
_wrap_gimp_color_selection_get_old_color(PyGObject *self)
{
    GimpRGB rgb;

    gimp_color_selection_get_old_color(GIMP_COLOR_SELECTION(self->obj), &rgb);

    return pygimp_rgb_new(&rgb);
}
#line 2282 "gimpui.c"


static PyObject *
_wrap_gimp_color_selection_reset(PyGObject *self)
{
    
    gimp_color_selection_reset(GIMP_COLOR_SELECTION(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_color_selection_color_changed(PyGObject *self)
{
    
    gimp_color_selection_color_changed(GIMP_COLOR_SELECTION(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyGimpColorSelection_methods[] = {
    { "set_show_alpha", (PyCFunction)_wrap_gimp_color_selection_set_show_alpha, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_show_alpha", (PyCFunction)_wrap_gimp_color_selection_get_show_alpha, METH_NOARGS,
      NULL },
    { "set_color", (PyCFunction)_wrap_gimp_color_selection_set_color, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_color", (PyCFunction)_wrap_gimp_color_selection_get_color, METH_NOARGS,
      NULL },
    { "set_old_color", (PyCFunction)_wrap_gimp_color_selection_set_old_color, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_old_color", (PyCFunction)_wrap_gimp_color_selection_get_old_color, METH_NOARGS,
      NULL },
    { "reset", (PyCFunction)_wrap_gimp_color_selection_reset, METH_NOARGS,
      NULL },
    { "color_changed", (PyCFunction)_wrap_gimp_color_selection_color_changed, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpColorSelection_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.ColorSelection",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpColorSelection_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_color_selection_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpColorNotebook ----------- */

static PyObject *
_wrap_gimp_color_notebook_set_has_page(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "page_type", "has_page", NULL };
    PyObject *py_page_type = NULL;
    int has_page;
    GType page_type;
    GtkWidget *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"Oi:Gimp.ColorNotebook.set_has_page", kwlist, &py_page_type, &has_page))
        return NULL;
    if ((page_type = pyg_type_from_object(py_page_type)) == 0)
        return NULL;
    
    ret = gimp_color_notebook_set_has_page(GIMP_COLOR_NOTEBOOK(self->obj), page_type, has_page);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static const PyMethodDef _PyGimpColorNotebook_methods[] = {
    { "set_has_page", (PyCFunction)_wrap_gimp_color_notebook_set_has_page, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpColorNotebook_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.ColorNotebook",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpColorNotebook_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)0,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpDialog ----------- */

#line 726 "gimpui.override"
static void
pygimp_help_func_marshal(const gchar *help_id, gpointer help_data)
{
    GObject *dialog = help_data;
    PyObject *py_dialog, *help_func, *ret;

    py_dialog = g_object_get_data(dialog, "pygimp-dialog-pyobject");
    help_func = g_object_get_data(dialog, "pygimp-dialog-help_func");

    ret = PyObject_CallFunction(help_func, "sO", help_id, py_dialog);

    if (ret)
        Py_DECREF(ret);
    else
        PyErr_Print();
}

static void
pygimp_help_func_destroy(gpointer data)
{
    PyObject *help_func = data;

    Py_DECREF(help_func);
}

static void
pygimp_dialog_close(GtkWidget *widget)
{
    /* Synthesize delete_event to close dialog. */

    if (gtk_widget_get_window (widget)) {
        GdkEvent *event = gdk_event_new(GDK_DELETE);

        event->any.window     = g_object_ref (gtk_widget_get_window (widget));
        event->any.send_event = TRUE;

        gtk_main_do_event(event);
        gdk_event_free(event);
    }
}

static int
_wrap_gimp_dialog_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    gchar *title, *role;
    PyGObject *py_window = NULL;
    PyObject *py_flags = NULL, *py_buttons = Py_None;
    PyObject *help_func = NULL;
    gchar *help_id = NULL;
    GtkDialogFlags flags = 0;
    int len, i;
    GtkWidget *parent;
    GimpHelpFunc func;

    static char *kwlist[] = { "title", "role", "parent", "flags",
                              "help_func", "help_id", "buttons", NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     "zz|OOOzO:gimpui.GimpDialog.__init__",
                                     kwlist,
                                     &title, &role, &py_window, &py_flags,
                                     &help_func, &help_id, &py_buttons))
        return -1;

    if (py_window == NULL || (PyObject*)py_window == Py_None)
        parent = NULL;
    else if (pygobject_check(py_window, &PyGtkWindow_Type))
        parent = GTK_WIDGET(py_window->obj);
    else {
        PyErr_SetString(PyExc_TypeError, "parent must be a GtkWindow or None");
        return -1;
    }

    if (pyg_flags_get_value(GTK_TYPE_DIALOG_FLAGS, py_flags, (gint *)&flags))
        return -1;

    if (py_buttons == Py_None)
        len = 0;
    else if (PyTuple_Check(py_buttons))
        len = PyTuple_Size(py_buttons);
    else {
        PyErr_SetString(PyExc_TypeError, "buttons must be a tuple containing text/response pairs or None");
        return -1;
    }

    if (len % 2) {
        PyErr_SetString(PyExc_RuntimeError,
                        "buttons tuple must contain text/response id pairs");
        return -1;
    }

    if (help_func) {
        if (help_func != Py_None) {
            if (!PyCallable_Check(help_func)) {
                PyErr_SetString(PyExc_TypeError, "help_func must be callable");
                return -1;
            }

            func = pygimp_help_func_marshal;

       } else {
            func = gimp_standard_help_func;
        }
    } else {
        func = gimp_standard_help_func;
    }

    pygobject_construct(self,
                        "title",     title,
                        "role",      role,
                        "modal",     (flags & GTK_DIALOG_MODAL),
                        "help-func", func,
                        "help-id",   help_id,
                        NULL);

    if (!self->obj) {
        PyErr_SetString(PyExc_RuntimeError,
                        "could not create GimpDialog object");
        return -1;
    }

   if (parent) {
        if (GTK_IS_WINDOW(parent))
            gtk_window_set_transient_for(GTK_WINDOW(self->obj),
                                         GTK_WINDOW(parent));
        else
            gtk_window_set_screen(GTK_WINDOW(self->obj),
                                  gtk_widget_get_screen(parent));

        if (flags & GTK_DIALOG_DESTROY_WITH_PARENT)
            g_signal_connect_object(parent, "destroy",
                                    G_CALLBACK(pygimp_dialog_close),
                                    self->obj, G_CONNECT_SWAPPED);
    }

    for (i = 0; i < len; i += 2) {
        PyObject *text = PyTuple_GetItem(py_buttons, i);
        PyObject *id = PyTuple_GetItem(py_buttons, i + 1);
        if (!PyString_Check(text) && !PyUnicode_Check(text)) {
            gtk_object_destroy(GTK_OBJECT(self->obj));
            self->obj = NULL;
            PyErr_SetString(PyExc_RuntimeError,
                            "first member of each text/response id pair "
                            "must be a string");
            return -1;
        }
        if (!PyInt_Check(id)) {
            gtk_object_destroy(GTK_OBJECT(self->obj));
            self->obj = NULL;
            PyErr_SetString(PyExc_RuntimeError,
                            "second member of each text/response id pair "
                            "must be a number");
            return -1;
        }

        gimp_dialog_add_button(GIMP_DIALOG(self->obj), PyString_AsString(text),
                               PyInt_AsLong(id));
    }

    if (help_func && help_func != Py_None) {
        g_object_set_data(self->obj, "pygimp-dialog-help-data", self);

        Py_INCREF(help_func);
        g_object_set_data_full(self->obj, "pygimp-dialog-help-func",
                               help_func, pygimp_help_func_destroy);
    }

    return 0;
}
#line 2619 "gimpui.c"


static PyObject *
_wrap_gimp_dialog_add_button(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "button_text", "response_id", NULL };
    char *button_text;
    int response_id;
    GtkWidget *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"si:Gimp.Dialog.add_button", kwlist, &button_text, &response_id))
        return NULL;
    
    ret = gimp_dialog_add_button(GIMP_DIALOG(self->obj), button_text, response_id);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_gimp_dialog_run(PyGObject *self)
{
    int ret;

    
    ret = gimp_dialog_run(GIMP_DIALOG(self->obj));
    
    return PyInt_FromLong(ret);
}

#line 928 "gimpui.override"
static PyObject *
_wrap_gimp_window_set_transient(PyGObject *self)
{
    gimp_window_set_transient(GTK_WINDOW(self->obj));
    Py_INCREF(Py_None);
    return Py_None;
}
#line 2658 "gimpui.c"


static const PyMethodDef _PyGimpDialog_methods[] = {
    { "add_button", (PyCFunction)_wrap_gimp_dialog_add_button, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "run", (PyCFunction)_wrap_gimp_dialog_run, METH_NOARGS,
      NULL },
    { "set_transient", (PyCFunction)_wrap_gimp_window_set_transient, METH_VARARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpDialog_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.Dialog",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpDialog_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_dialog_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpEnumLabel ----------- */

#line 1024 "gimpui.override"
static int
_wrap_gimp_enum_label_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_enum_type = NULL;
    GType enum_type;
    gint value;

    static char *kwlist[] = { "enum_type", "value", NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     "Oi:gimpui.GimpEnumLabel.__init__",
                                     kwlist,
                                     &py_enum_type, &value))
        return -1;

    if ((enum_type = pyg_type_from_object(py_enum_type)) == 0)
        return -1;

    if (pygobject_construct(self,
                            "enum-type",  enum_type,
                            "enum-value", value,
                            NULL))
        return -1;

    return 0; 
}
#line 2747 "gimpui.c"


static PyObject *
_wrap_gimp_enum_label_set_value(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "value", NULL };
    int value;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Gimp.EnumLabel.set_value", kwlist, &value))
        return NULL;
    
    gimp_enum_label_set_value(GIMP_ENUM_LABEL(self->obj), value);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyGimpEnumLabel_methods[] = {
    { "set_value", (PyCFunction)_wrap_gimp_enum_label_set_value, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpEnumLabel_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.EnumLabel",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpEnumLabel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_enum_label_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpFrame ----------- */

static int
_wrap_gimp_frame_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    GType obj_type = pyg_type_from_object((PyObject *) self);
    GParameter params[1];
    PyObject *parsed_args[1] = {NULL, };
    char *arg_names[] = {"label", NULL };
    char *prop_names[] = {"label", NULL };
    guint nparams, i;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O:gimpui.Frame.__init__" , arg_names , &parsed_args[0]))
        return -1;

    memset(params, 0, sizeof(GParameter)*1);
    if (!pyg_parse_constructor_args(obj_type, arg_names,
                                    prop_names, params, 
                                    &nparams, parsed_args))
        return -1;
    pygobject_constructv(self, nparams, params);
    for (i = 0; i < nparams; ++i)
        g_value_unset(&params[i].value);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create gimpui.Frame object");
        return -1;
    }
    return 0;
}

PyTypeObject G_GNUC_INTERNAL PyGimpFrame_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.Frame",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_frame_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpHintBox ----------- */

 static int
_wrap_gimp_hint_box_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    GType obj_type = pyg_type_from_object((PyObject *) self);
    GParameter params[2];
    PyObject *parsed_args[2] = {NULL, };
    char *arg_names[] = {"hint", "stock-id", NULL };
    char *prop_names[] = {"hint", "stock-id", NULL };
    guint nparams, i;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O|O:gimpui.HintBox.__init__" , arg_names , &parsed_args[0] , &parsed_args[1]))
        return -1;

    memset(params, 0, sizeof(GParameter)*2);
    if (!pyg_parse_constructor_args(obj_type, arg_names,
                                    prop_names, params, 
                                    &nparams, parsed_args))
        return -1;
    pygobject_constructv(self, nparams, params);
    for (i = 0; i < nparams; ++i)
        g_value_unset(&params[i].value);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create gimpui.HintBox object");
        return -1;
    }
    return 0;
}

PyTypeObject G_GNUC_INTERNAL PyGimpHintBox_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.HintBox",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_hint_box_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpIntComboBox ----------- */

#line 1054 "gimpui.override"
static int
_wrap_gimp_int_combo_box_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_items = NULL;
    int len, i;

    static char *kwlist[] = { "items", NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     "|O:gimpui.IntComboBox.__init__",
                                     kwlist,
                                     &py_items))
        return -1; 

    if (py_items == NULL || py_items == Py_None)
        len = 0;
    else if (PyTuple_Check(py_items))
        len = PyTuple_Size(py_items);
    else {
        PyErr_SetString(PyExc_TypeError,
                        "items must be a tuple containing label/value pairs "
                        "or None");
        return -1;
    }

    if (len % 2) {
        PyErr_SetString(PyExc_RuntimeError,
                        "items tuple must contain label/value pairs");
        return -1;
    }

    if (pygobject_construct(self, NULL))
        return -1;

    for (i = 0; i < len; i += 2) {
        PyObject *label = PyTuple_GetItem(py_items, i);
        PyObject *value = PyTuple_GetItem(py_items, i + 1);

        if (!PyString_Check(label)) {
            gtk_object_destroy(GTK_OBJECT(self->obj));
            self->obj = NULL;
            PyErr_SetString(PyExc_RuntimeError,
                            "first member of each label/value pair "
                            "must be a string");
            return -1;
        }

        if (!PyInt_Check(value)) {
            gtk_object_destroy(GTK_OBJECT(self->obj));
            self->obj = NULL;
            PyErr_SetString(PyExc_RuntimeError,
                            "second member of each label/value pair "
                            "must be a number");
            return -1;
        }

        gimp_int_combo_box_append(GIMP_INT_COMBO_BOX(self->obj),
                                  GIMP_INT_STORE_LABEL,
                                  PyString_AsString(label),
                                  GIMP_INT_STORE_VALUE,
                                  PyInt_AsLong(value),
                                  -1);
    }

    return 0;
}
#line 3045 "gimpui.c"


#line 1308 "gimpui.override"
static PyObject *
_wrap_gimp_int_combo_box_prepend(PyGObject *self, PyObject *args,
                                 PyObject *kwargs)
{
    PyObject *py_items;
    int i, len;

    static char *kwlist[] = { "items", NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     "O:gimpui.IntComboBox.prepend",
                                     kwlist,
                                     &py_items))
        return NULL; 

    if (py_items == NULL || py_items == Py_None)
        len = 0;
    else if (PyTuple_Check(py_items))
        len = PyTuple_Size(py_items);
    else {
        PyErr_SetString(PyExc_TypeError,
                        "items must be a tuple containing label/value pairs "
                        "or None");
        return NULL;
    }

    if (len % 2) {
        PyErr_SetString(PyExc_RuntimeError,
                        "items tuple must contain label/value pairs");
        return NULL;
    }

    for (i = 0; i < len; i += 2) {
        PyObject *label = PyTuple_GetItem(py_items, i);
        PyObject *value = PyTuple_GetItem(py_items, i + 1);

        if (!PyString_Check(label)) {
            PyErr_SetString(PyExc_RuntimeError,
                            "first member of each label/value pair "
                            "must be a string");
            return NULL;
        }

        if (!PyInt_Check(value)) {
            PyErr_SetString(PyExc_RuntimeError,
                            "second member of each label/value pair "
                            "must be a number");
            return NULL;
        }

        gimp_int_combo_box_prepend(GIMP_INT_COMBO_BOX(self->obj),
                                  GIMP_INT_STORE_LABEL,
                                  PyString_AsString(label),
                                  GIMP_INT_STORE_VALUE,
                                  PyInt_AsLong(value),
                                  -1);
    }
    
    Py_INCREF(Py_None);
    return Py_None;
}
#line 3110 "gimpui.c"


#line 1245 "gimpui.override"
static PyObject *
_wrap_gimp_int_combo_box_append(PyGObject *self, PyObject *args,
                                PyObject *kwargs)
{
    PyObject *py_items;
    int i, len;

    static char *kwlist[] = { "items", NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     "O:gimpui.IntComboBox.append",
                                     kwlist,
                                     &py_items))
        return NULL; 

    if (py_items == NULL || py_items == Py_None)
        len = 0;
    else if (PyTuple_Check(py_items))
        len = PyTuple_Size(py_items);
    else {
        PyErr_SetString(PyExc_TypeError,
                        "items must be a tuple containing label/value pairs "
                        "or None");
        return NULL;
    }

    if (len % 2) {
        PyErr_SetString(PyExc_RuntimeError,
                        "items tuple must contain label/value pairs");
        return NULL;
    }

    for (i = 0; i < len; i += 2) {
        PyObject *label = PyTuple_GetItem(py_items, i);
        PyObject *value = PyTuple_GetItem(py_items, i + 1);

        if (!PyString_Check(label)) {
            PyErr_SetString(PyExc_RuntimeError,
                            "first member of each label/value pair "
                            "must be a string");
            return NULL;
        }

        if (!PyInt_Check(value)) {
            PyErr_SetString(PyExc_RuntimeError,
                            "second member of each label/value pair "
                            "must be a number");
            return NULL;
        }

        gimp_int_combo_box_append(GIMP_INT_COMBO_BOX(self->obj),
                                  GIMP_INT_STORE_LABEL,
                                  PyString_AsString(label),
                                  GIMP_INT_STORE_VALUE,
                                  PyInt_AsLong(value),
                                  -1);
    }
    
    Py_INCREF(Py_None);
    return Py_None;
}
#line 3175 "gimpui.c"


#line 1220 "gimpui.override"
static PyObject *
_wrap_gimp_int_combo_box_set_active(PyGObject *self, PyObject *args,
                                    PyObject *kwargs)
{
    int value;

    static char *kwlist[] = { "value", NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, 
                                     "i:GimpIntComboBox.set_active", kwlist,
                                     &value))
        return NULL;

    if (!gimp_int_combo_box_set_active(GIMP_INT_COMBO_BOX(self->obj), value)) {
        PyErr_Format(pygimp_error,
                     "Value %d does not exist in GimpIntComboBox",
                     value);
        return NULL;
    }

    Py_INCREF(Py_None);
    return Py_None;
}
#line 3202 "gimpui.c"


#line 1207 "gimpui.override"
static PyObject *
_wrap_gimp_int_combo_box_get_active(PyGObject *self)
{
    int value;

    if (gimp_int_combo_box_get_active(GIMP_INT_COMBO_BOX(self->obj), &value))
        return PyLong_FromLong(value);

    Py_INCREF(Py_None);
    return Py_None;
}
#line 3217 "gimpui.c"


#line 1124 "gimpui.override"
static gboolean
pygimp_int_combo_box_sensitivity_marshal(gint value, gpointer user_data)
{
    PyObject *py_value;
    PyGimpIntSensitivityData *data;
    PyObject *ret;
    gboolean res;

    data = user_data;

    py_value = PyInt_FromLong(value);

    ret = PyObject_CallFunctionObjArgs(data->sensitivity_func, py_value,
                                       data->user_data, NULL);
    
    if (!ret) {
        PyErr_Print();
        res = FALSE;
    } else {
        res = PyObject_IsTrue(ret);
        Py_DECREF(ret);
    }

    Py_DECREF(py_value);

    return res;
}

static void
pygimp_int_combo_box_sensitivity_data_destroy(gpointer user_data)
{
    PyGimpIntSensitivityData *data;
    data = user_data;

    Py_DECREF(data->sensitivity_func);
    Py_XDECREF(data->user_data);

    g_free(data);
}

static PyObject *
_wrap_gimp_int_combo_box_set_sensitivity(PyGObject *self, PyObject *args,
                                         PyObject *kwargs)
{
    PyObject *py_sensitivity_func;
    PyObject *py_user_data = NULL;
    PyGimpIntSensitivityData *data;

    static char *kwlist[] = { "sensitivity_func", "user_data", NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, 
                                     "O|O:GimpIntComboBox.set_sensitivity",
                                     kwlist, &py_sensitivity_func,
                                     &py_user_data))
        return NULL;

    if (!PyCallable_Check(py_sensitivity_func)) {
        PyErr_SetString(PyExc_TypeError, "first argument must be callable.");
        return NULL;
    }

    data = g_new(PyGimpIntSensitivityData, 1);

    data->sensitivity_func = py_sensitivity_func;
    Py_INCREF(data->sensitivity_func);
    
   if (py_user_data == NULL || py_user_data == Py_None)
        data->user_data = NULL;
    else {
       data->user_data = py_user_data;
       Py_INCREF(data->user_data);
    }

    gimp_int_combo_box_set_sensitivity(GIMP_INT_COMBO_BOX(self->obj),
                                pygimp_int_combo_box_sensitivity_marshal,
                                data,
                                pygimp_int_combo_box_sensitivity_data_destroy);
    
    Py_INCREF(Py_None);
    return Py_None;
}
#line 3302 "gimpui.c"


static const PyMethodDef _PyGimpIntComboBox_methods[] = {
    { "prepend", (PyCFunction)_wrap_gimp_int_combo_box_prepend, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "append", (PyCFunction)_wrap_gimp_int_combo_box_append, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_active", (PyCFunction)_wrap_gimp_int_combo_box_set_active, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_active", (PyCFunction)_wrap_gimp_int_combo_box_get_active, METH_NOARGS,
      NULL },
    { "set_sensitivity", (PyCFunction)_wrap_gimp_int_combo_box_set_sensitivity, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpIntComboBox_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.IntComboBox",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpIntComboBox_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_int_combo_box_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpImageComboBox ----------- */

#line 605 "gimpui.override"
static gboolean
pygimp_image_constraint_marshal(gint32 image_id, gpointer user_data)
{
    PyObject *img, *ret;
    gboolean res;
    PyGimpConstraintData *data = user_data;

    img = pygimp_image_new(image_id);
    if (!img) {
        PyErr_Print();
        return FALSE;
    }

    if (data->user_data && data->user_data != Py_None)
        ret = PyObject_CallFunctionObjArgs(data->constraint, img,
                                           data->user_data, NULL);
    else
        ret = PyObject_CallFunctionObjArgs(data->constraint, img, NULL);

    if (!ret) {
        PyErr_Print();
        res = FALSE;
    } else {
        res = PyObject_IsTrue(ret);
        Py_DECREF(ret);
    }

    Py_DECREF(img);

    return res;
}

static int
_wrap_gimp_image_combo_box_new(PyGObject *self, PyObject *args,
                               PyObject *kwargs)
{
    PyObject *constraint = NULL, *user_data = NULL;
    GimpImageConstraintFunc func = NULL;
    PyGimpConstraintData *data = NULL;

    static char *kwlist[] = { "constraint", "data", NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     "|OO:gimpui.ImageComboBox.__init__",
                                     kwlist,
                                     &constraint, &user_data))
        return -1;

    if (constraint && constraint != Py_None) {
        if (!PyCallable_Check(constraint)) {
            PyErr_SetString(PyExc_TypeError, "first arg must be callable");
            return -1;
        }

        data = g_new(PyGimpConstraintData, 1);

        data->constraint = constraint;
        Py_INCREF(constraint);

        data->user_data = user_data;
        Py_XINCREF(user_data);

        func = pygimp_image_constraint_marshal;
    }

    self->obj = (GObject *)gimp_image_combo_box_new(func, data);

    Py_XDECREF(constraint);
    Py_XDECREF(user_data);
    g_free(data);

    if (pyg_type_from_object((PyObject *)self) != GIMP_TYPE_IMAGE_COMBO_BOX) {
        PyErr_SetString(PyExc_RuntimeError, "__gobject_init__ must be used "
                        "when subclassing gimpui.ImageComboBox");
        return -1;
    }

    pygobject_register_wrapper((PyObject *)self);
    return 0;
}
#line 3449 "gimpui.c"


#line 713 "gimpui.override"
static PyObject *
_wrap_gimp_image_combo_box_get_active_image(PyGObject *self)
{
    int value;

    if (gimp_int_combo_box_get_active(GIMP_INT_COMBO_BOX(self->obj), &value))
        return pygimp_image_new(value);

    Py_INCREF(Py_None);
    return Py_None;
}
#line 3464 "gimpui.c"


#line 687 "gimpui.override"
static PyObject *
_wrap_gimp_image_combo_box_set_active_image(PyGObject *self, PyObject *args,
                                            PyObject *kwargs)
{
    PyGimpImage *img;

    static char *kwlist[] = { "image", NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, 
                                     "O!:GimpImageComboBox.set_active_image",
                                     kwlist,
                                     PyGimpImage_Type, &img))
        return NULL;

    if (!gimp_int_combo_box_set_active(GIMP_INT_COMBO_BOX(self->obj), img->ID)) {
        PyErr_Format(pygimp_error,
                     "Image (ID %d) does not exist in GimpImageComboBox",
                     img->ID);
        return NULL;
    }

    Py_INCREF(Py_None);
    return Py_None;
}
#line 3492 "gimpui.c"


static const PyMethodDef _PyGimpImageComboBox_methods[] = {
    { "get_active_image", (PyCFunction)_wrap_gimp_image_combo_box_get_active_image, METH_NOARGS,
      NULL },
    { "set_active_image", (PyCFunction)_wrap_gimp_image_combo_box_set_active_image, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpImageComboBox_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.ImageComboBox",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpImageComboBox_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_image_combo_box_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpEnumComboBox ----------- */

static int
_wrap_gimp_enum_combo_box_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "enum_type", NULL };
    PyObject *py_enum_type = NULL;
    GType enum_type;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:Gimp.EnumComboBox.__init__", kwlist, &py_enum_type))
        return -1;
    if ((enum_type = pyg_type_from_object(py_enum_type)) == 0)
        return -1;
    self->obj = (GObject *)gimp_enum_combo_box_new(enum_type);

    if (!self->obj) {
        PyErr_SetString(PyExc_RuntimeError, "could not create GimpEnumComboBox object");
        return -1;
    }
    pygobject_register_wrapper((PyObject *)self);
    return 0;
}

static PyObject *
_wrap_gimp_enum_combo_box_set_stock_prefix(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "stock_prefix", NULL };
    char *stock_prefix;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:Gimp.EnumComboBox.set_stock_prefix", kwlist, &stock_prefix))
        return NULL;
    
    gimp_enum_combo_box_set_stock_prefix(GIMP_ENUM_COMBO_BOX(self->obj), stock_prefix);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyGimpEnumComboBox_methods[] = {
    { "set_stock_prefix", (PyCFunction)_wrap_gimp_enum_combo_box_set_stock_prefix, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpEnumComboBox_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.EnumComboBox",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpEnumComboBox_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_enum_combo_box_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpDrawableComboBox ----------- */

#line 85 "gimpui.override"
static gboolean
pygimp_drawable_constraint_marshal(gint32 image_id, gint32 drawable_id,
                                   gpointer user_data)
{
    PyObject *img, *drw, *ret;
    gboolean res;
    PyGimpConstraintData *data = user_data;

    img = pygimp_image_new(image_id);
    if (!img) {
        PyErr_Print();
        return FALSE;
    }

    drw = pygimp_drawable_new(NULL, drawable_id);
    if (!drw) {
        PyErr_Print();
        Py_DECREF(img);
        return FALSE;
    }

    if (data->user_data && data->user_data != Py_None)
        ret = PyObject_CallFunctionObjArgs(data->constraint, img, drw,
                                           data->user_data, NULL);
    else
        ret = PyObject_CallFunctionObjArgs(data->constraint, img, drw, NULL);

    if (!ret) {
        PyErr_Print();
        res = FALSE;
    } else {
        res = PyObject_IsTrue(ret);
        Py_DECREF(ret);
    }

    Py_DECREF(drw);
    Py_DECREF(img);

    return res;
}

static int
_wrap_gimp_drawable_combo_box_new(PyGObject *self, PyObject *args,
                                  PyObject *kwargs)
{
    PyObject *constraint = NULL, *user_data = NULL;
    GimpDrawableConstraintFunc func = NULL;
    PyGimpConstraintData *data = NULL;

    static char *kwlist[] = { "constraint", "data", NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     "|OO:gimpui.DrawableComboBox.__init__",
                                     kwlist,
                                     &constraint, &user_data))
        return -1;

    if (constraint && constraint != Py_None) {
        if (!PyCallable_Check(constraint)) {
            PyErr_SetString(PyExc_TypeError, "first arg must be callable");
            return -1;
        }

        data = g_new(PyGimpConstraintData, 1);

        data->constraint = constraint;
        Py_XINCREF(constraint);

        data->user_data = user_data;
        Py_XINCREF(user_data);

        func = pygimp_drawable_constraint_marshal;
    }

    self->obj = (GObject *)gimp_drawable_combo_box_new(func, data);

    Py_XDECREF(constraint);
    Py_XDECREF(user_data);
    g_free(data);

    if (pyg_type_from_object((PyObject *)self) != GIMP_TYPE_DRAWABLE_COMBO_BOX) {
        PyErr_SetString(PyExc_RuntimeError, "__gobject_init__ must be used "
                        "when subclassing gimpui.DrawableComboBox");
        return -1;
    }

    pygobject_register_wrapper((PyObject *)self);
    return 0;
}
#line 3733 "gimpui.c"


#line 176 "gimpui.override"
static PyObject *
_wrap_gimp_drawable_combo_box_set_active_drawable(PyGObject *self, PyObject *args,
                                                  PyObject *kwargs)
{
    PyGimpDrawable *drw;

    static char *kwlist[] = { "drawable", NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, 
                                     "O!:GimpDrawableComboBox.set_active_drawable",
                                     kwlist,
                                     PyGimpDrawable_Type, &drw))
        return NULL;

    if (!gimp_int_combo_box_set_active(GIMP_INT_COMBO_BOX(self->obj), drw->ID)) {
        PyErr_Format(pygimp_error,
                     "Drawable (ID %d) does not exist in GimpDrawableComboBox",
                     drw->ID);
        return NULL;
    }

    Py_INCREF(Py_None);
    return Py_None;
}
#line 3761 "gimpui.c"


#line 202 "gimpui.override"
static PyObject *
_wrap_gimp_drawable_combo_box_get_active_drawable(PyGObject *self)
{
    int value;

    if (gimp_int_combo_box_get_active(GIMP_INT_COMBO_BOX(self->obj), &value))
        return pygimp_drawable_new(NULL, value);

    Py_INCREF(Py_None);
    return Py_None;
}
#line 3776 "gimpui.c"


static const PyMethodDef _PyGimpDrawableComboBox_methods[] = {
    { "set_active_drawable", (PyCFunction)_wrap_gimp_drawable_combo_box_set_active_drawable, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_active_drawable", (PyCFunction)_wrap_gimp_drawable_combo_box_get_active_drawable, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpDrawableComboBox_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.DrawableComboBox",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpDrawableComboBox_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_drawable_combo_box_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpChannelComboBox ----------- */

#line 215 "gimpui.override"
static gboolean
pygimp_channel_constraint_marshal(gint32 image_id, gint32 channel_id,
                                  gpointer user_data)
{
    PyObject *img, *chn, *ret;
    gboolean res;
    PyGimpConstraintData *data = user_data;

    img = pygimp_image_new(image_id);
    if (!img) {
        PyErr_Print();
        return FALSE;
    }

    chn = pygimp_channel_new(channel_id);
    if (!chn) {
        PyErr_Print();
        Py_DECREF(img);
        return FALSE;
    }

    if (data->user_data && data->user_data != Py_None)
        ret = PyObject_CallFunctionObjArgs(data->constraint, img, chn,
                                           data->user_data, NULL);
    else
        ret = PyObject_CallFunctionObjArgs(data->constraint, img, chn, NULL);

    if (!ret) {
        PyErr_Print();
        res = FALSE;
    } else {
        res = PyObject_IsTrue(ret);
        Py_DECREF(ret);
    }

    Py_DECREF(chn);
    Py_DECREF(img);

    return res;
}

static int
_wrap_gimp_channel_combo_box_new(PyGObject *self, PyObject *args,
                                 PyObject *kwargs)
{
    PyObject *constraint = NULL, *user_data = NULL;
    GimpDrawableConstraintFunc func = NULL;
    PyGimpConstraintData *data = NULL;

    static char *kwlist[] = { "constraint", "data", NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     "|OO:gimpui.ChannelComboBox.__init__",
                                     kwlist,
                                     &constraint, &user_data))
        return -1;

    if (constraint && constraint != Py_None) {
        if (!PyCallable_Check(constraint)) {
            PyErr_SetString(PyExc_TypeError, "first arg must be callable");
            return -1;
        }

        data = g_new(PyGimpConstraintData, 1);

        data->constraint = constraint;
        Py_INCREF(constraint);

        data->user_data = user_data;
        Py_XINCREF(user_data);

        func = pygimp_channel_constraint_marshal;
    }

    self->obj = (GObject *)gimp_channel_combo_box_new(func, data);

    Py_XDECREF(constraint);
    Py_XDECREF(user_data);
    g_free(data);

    if (pyg_type_from_object((PyObject *)self) != GIMP_TYPE_CHANNEL_COMBO_BOX) {
        PyErr_SetString(PyExc_RuntimeError, "__gobject_init__ must be used "
                        "when subclassing gimpui.ChannelComboBox");
        return -1;
    }

    pygobject_register_wrapper((PyObject *)self);
    return 0;
}
#line 3926 "gimpui.c"


#line 306 "gimpui.override"
static PyObject *
_wrap_gimp_channel_combo_box_set_active_channel(PyGObject *self, PyObject *args,
                                                PyObject *kwargs)
{
    PyGimpChannel *chn;

    static char *kwlist[] = { "channel", NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, 
                                    "O!:GimpChannelComboBox.set_active_channel",
                                    kwlist,
                                    PyGimpChannel_Type, &chn))
        return NULL;

    if (!gimp_int_combo_box_set_active(GIMP_INT_COMBO_BOX(self->obj), chn->ID)) {
        PyErr_Format(pygimp_error,
                     "Channel (ID %d) does not exist in GimpChannelComboBox",
                     chn->ID);
        return NULL;
    }

    Py_INCREF(Py_None);
    return Py_None;
}
#line 3954 "gimpui.c"


#line 332 "gimpui.override"
static PyObject *
_wrap_gimp_channel_combo_box_get_active_channel(PyGObject *self)
{
    int value;

    if (gimp_int_combo_box_get_active(GIMP_INT_COMBO_BOX(self->obj), &value))
        return pygimp_channel_new(value);

    Py_INCREF(Py_None);
    return Py_None;
}
#line 3969 "gimpui.c"


static const PyMethodDef _PyGimpChannelComboBox_methods[] = {
    { "set_active_channel", (PyCFunction)_wrap_gimp_channel_combo_box_set_active_channel, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_active_channel", (PyCFunction)_wrap_gimp_channel_combo_box_get_active_channel, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpChannelComboBox_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.ChannelComboBox",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpChannelComboBox_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_channel_combo_box_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpIntStore ----------- */

 static int
_wrap_gimp_int_store_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char* kwlist[] = { NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     ":gimpui.IntStore.__init__",
                                     kwlist))
        return -1;

    pygobject_constructv(self, 0, NULL);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create gimpui.IntStore object");
        return -1;
    }
    return 0;
}

#line 1723 "gimpui.override"
static PyObject *
_wrap_gimp_int_store_lookup_by_value(PyGObject *self, PyObject *args,
                                     PyObject *kwargs)
{
    static char *kwlist[] = { "value", NULL };
    int value, ret;
    GtkTreeIter iter;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                               "i:GimpIntStore.gimp_int_store_lookup_by_value",
                               kwlist, &value))
        return NULL;

    ret = gimp_int_store_lookup_by_value(GTK_TREE_MODEL(self->obj), value,
                                         &iter);
    if (ret)
        pyg_boxed_new(GTK_TYPE_TREE_ITER, &iter, TRUE, TRUE);

    Py_INCREF(Py_None);
    return Py_None;
}
#line 4071 "gimpui.c"


static const PyMethodDef _PyGimpIntStore_methods[] = {
    { "lookup_by_value", (PyCFunction)_wrap_gimp_int_store_lookup_by_value, METH_VARARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpIntStore_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.IntStore",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpIntStore_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_int_store_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpEnumStore ----------- */

#line 1843 "gimpui.override"
static int
_wrap_gimp_enum_store_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "enum_type", "minimum", "maximum", NULL };
    PyObject *py_enum_type = NULL;
    PyObject *py_minimum = NULL;
    PyObject *py_maximum = NULL;
    GType enum_type;
    GEnumClass *enum_class;
    gint minimum, maximum;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     "O|O!O!:GimpEnumStore.__init__", kwlist,
                                      &py_enum_type, &PyInt_Type, &py_minimum,
                                      &PyInt_Type, &py_maximum))
        return -1;
    if ((enum_type = pyg_type_from_object(py_enum_type)) == 0)
        return -1;

    enum_class = g_type_class_ref(enum_type);

    if (py_minimum == NULL)
        minimum = enum_class->minimum;
    else
        minimum = PyInt_AsLong(py_minimum);
    
    if (py_maximum == NULL)
        maximum = enum_class->maximum;
    else
        maximum = PyInt_AsLong(py_maximum);
    
    g_type_class_unref(enum_class);

    self->obj = (GObject *)gimp_enum_store_new_with_range(enum_type, minimum, maximum);

    if (!self->obj) {
        PyErr_SetString(PyExc_RuntimeError, "could not create GimpEnumStore object");
        return -1;
    }
    pygobject_register_wrapper((PyObject *)self);
    return 0;
}
#line 4172 "gimpui.c"


static PyObject *
_wrap_gimp_enum_store_set_stock_prefix(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "stock_prefix", NULL };
    char *stock_prefix;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:Gimp.EnumStore.set_stock_prefix", kwlist, &stock_prefix))
        return NULL;
    
    gimp_enum_store_set_stock_prefix(GIMP_ENUM_STORE(self->obj), stock_prefix);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyGimpEnumStore_methods[] = {
    { "set_stock_prefix", (PyCFunction)_wrap_gimp_enum_store_set_stock_prefix, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpEnumStore_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.EnumStore",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpEnumStore_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_enum_store_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpLayerComboBox ----------- */

#line 345 "gimpui.override"
static gboolean
pygimp_layer_constraint_marshal(gint32 image_id, gint32 layer_id,
                                gpointer user_data)
{
    PyObject *img, *lay, *ret;
    gboolean res;
    PyGimpConstraintData *data = user_data;

    img = pygimp_image_new(image_id);
    if (!img) {
        PyErr_Print();
        return FALSE;
    }

    lay = pygimp_layer_new(layer_id);
    if (!lay) {
        PyErr_Print();
        Py_DECREF(img);
        return FALSE;
    }

    if (data->user_data && data->user_data != Py_None)
        ret = PyObject_CallFunctionObjArgs(data->constraint, img, lay,
                                           data->user_data, NULL);
    else
        ret = PyObject_CallFunctionObjArgs(data->constraint, img, lay, NULL);

    if (!ret) {
        PyErr_Print();
        res = FALSE;
    } else {
        res = PyObject_IsTrue(ret);
        Py_DECREF(ret);
    }

    Py_DECREF(lay);
    Py_DECREF(img);

    return res;
}

static int
_wrap_gimp_layer_combo_box_new(PyGObject *self, PyObject *args,
                               PyObject *kwargs)
{
    PyObject *constraint = NULL, *user_data = NULL;
    GimpDrawableConstraintFunc func = NULL;
    PyGimpConstraintData *data = NULL;

    static char *kwlist[] = { "constraint", "data", NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     "|OO:gimpui.LayerComboBox.__init__",
                                     kwlist,
                                     &constraint, &user_data))
        return -1;

    if (constraint && constraint != Py_None) {
        if (!PyCallable_Check(constraint)) {
            PyErr_SetString(PyExc_TypeError, "first arg must be callable");
            return -1;
        }

        data = g_new(PyGimpConstraintData, 1);

        data->constraint = constraint;
        Py_INCREF(constraint);

        data->user_data = user_data;
        Py_XINCREF(user_data);

        func = pygimp_layer_constraint_marshal;
    }

    self->obj = (GObject *)gimp_layer_combo_box_new(func, data);

    Py_XDECREF(constraint);
    Py_XDECREF(user_data);
    g_free(data);

    if (pyg_type_from_object((PyObject *)self) != GIMP_TYPE_LAYER_COMBO_BOX) {
        PyErr_SetString(PyExc_RuntimeError, "__gobject_init__ must be used "
                        "when subclassing gimpui.LayerComboBox");
        return -1;
    }

    pygobject_register_wrapper((PyObject *)self);
    return 0;
}
#line 4335 "gimpui.c"


#line 462 "gimpui.override"
static PyObject *
_wrap_gimp_layer_combo_box_get_active_layer(PyGObject *self)
{
    int value;

    if (gimp_int_combo_box_get_active(GIMP_INT_COMBO_BOX(self->obj), &value))
        return pygimp_layer_new(value);

    Py_INCREF(Py_None);
    return Py_None;
}
#line 4350 "gimpui.c"


#line 436 "gimpui.override"
static PyObject *
_wrap_gimp_layer_combo_box_set_active_layer(PyGObject *self, PyObject *args,
                                            PyObject *kwargs)
{
    PyGimpLayer *lay;

    static char *kwlist[] = { "layer", NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, 
                                     "O!:GimpLayerComboBox.set_active_layer",
                                     kwlist,
                                     PyGimpLayer_Type, &lay))
        return NULL;

    if (!gimp_int_combo_box_set_active(GIMP_INT_COMBO_BOX(self->obj), lay->ID)) {
        PyErr_Format(pygimp_error,
                     "Layer (ID %d) does not exist in GimpLayerComboBox",
                     lay->ID);
        return NULL;
    }

    Py_INCREF(Py_None);
    return Py_None;
}
#line 4378 "gimpui.c"


static const PyMethodDef _PyGimpLayerComboBox_methods[] = {
    { "get_active_layer", (PyCFunction)_wrap_gimp_layer_combo_box_get_active_layer, METH_NOARGS,
      NULL },
    { "set_active_layer", (PyCFunction)_wrap_gimp_layer_combo_box_set_active_layer, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpLayerComboBox_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.LayerComboBox",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpLayerComboBox_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_layer_combo_box_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpMemsizeEntry ----------- */

#line 1746 "gimpui.override"
static int
_wrap_gimp_memsize_entry_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "value", "lower", "upper", NULL };
    guint64 value, lower, upper;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     "LLL:GimpMemsizeEntry.__init__",
                                     kwlist, &value, &lower, &upper))
        return -1;
    
    self->obj = (GObject *)gimp_memsize_entry_new(value, lower, upper);

    if (!self->obj) {
        PyErr_SetString(PyExc_RuntimeError,
                        "could not create GimpMemsizeEntry object");
        return -1;
    }
    pygobject_register_wrapper((PyObject *)self);
    return 0;
}
#line 4460 "gimpui.c"


#line 1769 "gimpui.override"
static PyObject *
_wrap_gimp_memsize_entry_set_value(PyGObject *self, PyObject *args,
                                   PyObject *kwargs)
{
    static char *kwlist[] = { "value", NULL };
    guint64 value;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, 
                                     "L:GimpMemsizeEntry.set_value",
                                     kwlist, &value))
        return NULL;

    gimp_memsize_entry_set_value(GIMP_MEMSIZE_ENTRY(self->obj), value);

    Py_INCREF(Py_None);
    return Py_None;
}
#line 4481 "gimpui.c"


static PyObject *
_wrap_gimp_memsize_entry_get_value(PyGObject *self)
{
    guint64 ret;

    
    ret = gimp_memsize_entry_get_value(GIMP_MEMSIZE_ENTRY(self->obj));
    
    return PyLong_FromUnsignedLongLong(ret);
}

static const PyMethodDef _PyGimpMemsizeEntry_methods[] = {
    { "set_value", (PyCFunction)_wrap_gimp_memsize_entry_set_value, METH_VARARGS,
      NULL },
    { "get_value", (PyCFunction)_wrap_gimp_memsize_entry_get_value, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpMemsizeEntry_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.MemsizeEntry",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpMemsizeEntry_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_memsize_entry_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpNumberPairEntry ----------- */

static int
_wrap_gimp_number_pair_entry_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    GType obj_type = pyg_type_from_object((PyObject *) self);
    GParameter params[4];
    PyObject *parsed_args[4] = {NULL, };
    char *arg_names[] = {"separators", "allow_simplification", "min_valid_value", "max_valid_value", NULL };
    char *prop_names[] = {"separators", "allow-simplification", "min-valid-value", "max-valid-value", NULL };
    guint nparams, i;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OOOO:gimpui.NumberPairEntry.__init__" , arg_names , &parsed_args[0] , &parsed_args[1] , &parsed_args[2] , &parsed_args[3]))
        return -1;

    memset(params, 0, sizeof(GParameter)*4);
    if (!pyg_parse_constructor_args(obj_type, arg_names,
                                    prop_names, params, 
                                    &nparams, parsed_args))
        return -1;
    pygobject_constructv(self, nparams, params);
    for (i = 0; i < nparams; ++i)
        g_value_unset(&params[i].value);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create gimpui.NumberPairEntry object");
        return -1;
    }
    return 0;
}

static PyObject *
_wrap_gimp_number_pair_entry_set_default_values(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "left", "right", NULL };
    double left, right;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"dd:Gimp.NumberPairEntry.set_default_values", kwlist, &left, &right))
        return NULL;
    
    gimp_number_pair_entry_set_default_values(GIMP_NUMBER_PAIR_ENTRY(self->obj), left, right);
    
    Py_INCREF(Py_None);
    return Py_None;
}

#line 1519 "gimpui.override"
static PyObject *
_wrap_gimp_number_pair_entry_get_default_values(PyGObject *self)
{
    gdouble left, right;

    gimp_number_pair_entry_get_default_values(
                                             GIMP_NUMBER_PAIR_ENTRY(self->obj),
                                             &left, &right);

    return Py_BuildValue("(dd)", left, right);
}
#line 4609 "gimpui.c"


static PyObject *
_wrap_gimp_number_pair_entry_set_values(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "left", "right", NULL };
    double left, right;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"dd:Gimp.NumberPairEntry.set_values", kwlist, &left, &right))
        return NULL;
    
    gimp_number_pair_entry_set_values(GIMP_NUMBER_PAIR_ENTRY(self->obj), left, right);
    
    Py_INCREF(Py_None);
    return Py_None;
}

#line 1507 "gimpui.override"
static PyObject *
_wrap_gimp_number_pair_entry_get_values(PyGObject *self)
{
    gdouble left, right;

    gimp_number_pair_entry_get_values(GIMP_NUMBER_PAIR_ENTRY(self->obj),
                                      &left, &right);

    return Py_BuildValue("(dd)", left, right);   
}
#line 4638 "gimpui.c"


static PyObject *
_wrap_gimp_number_pair_entry_set_default_text(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "string", NULL };
    char *string;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:Gimp.NumberPairEntry.set_default_text", kwlist, &string))
        return NULL;
    
    gimp_number_pair_entry_set_default_text(GIMP_NUMBER_PAIR_ENTRY(self->obj), string);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_number_pair_entry_get_default_text(PyGObject *self)
{
    const gchar *ret;

    
    ret = gimp_number_pair_entry_get_default_text(GIMP_NUMBER_PAIR_ENTRY(self->obj));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_number_pair_entry_set_ratio(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "ratio", NULL };
    double ratio;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"d:Gimp.NumberPairEntry.set_ratio", kwlist, &ratio))
        return NULL;
    
    gimp_number_pair_entry_set_ratio(GIMP_NUMBER_PAIR_ENTRY(self->obj), ratio);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_number_pair_entry_get_ratio(PyGObject *self)
{
    double ret;

    
    ret = gimp_number_pair_entry_get_ratio(GIMP_NUMBER_PAIR_ENTRY(self->obj));
    
    return PyFloat_FromDouble(ret);
}

#line 1544 "gimpui.override"
static PyObject *
_wrap_gimp_number_pair_entry_set_aspect(PyGObject *self, PyObject *args,
                                        PyObject *kwargs)
{
    PyObject *py_aspect;
    GimpAspectType aspect;

    static char *kwlist[] = {"aspect", NULL};

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                    "O:GimpNumberPairEntry.set_aspect",
                                    kwlist, &py_aspect))
        return NULL;

    if (pyg_enum_get_value(GIMP_TYPE_ASPECT_TYPE, py_aspect, (gint*)&aspect))
    {
        Py_XDECREF(py_aspect);
        return NULL;
    }

    gimp_number_pair_entry_set_aspect(GIMP_NUMBER_PAIR_ENTRY(self->obj),
                                      aspect);

    Py_DECREF(py_aspect);

    Py_INCREF(Py_None);
    return Py_None;
}
#line 4725 "gimpui.c"


#line 1532 "gimpui.override"
static PyObject *
_wrap_gimp_number_pair_entry_get_aspect(PyGObject *self)
{
    GimpAspectType aspect;

    aspect =
          gimp_number_pair_entry_get_aspect(GIMP_NUMBER_PAIR_ENTRY(self->obj));

    return pyg_enum_from_gtype(GIMP_TYPE_ASPECT_TYPE, aspect);
}
#line 4739 "gimpui.c"


static PyObject *
_wrap_gimp_number_pair_entry_set_user_override(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "user_override", NULL };
    int user_override;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Gimp.NumberPairEntry.set_user_override", kwlist, &user_override))
        return NULL;
    
    gimp_number_pair_entry_set_user_override(GIMP_NUMBER_PAIR_ENTRY(self->obj), user_override);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_number_pair_entry_get_user_override(PyGObject *self)
{
    int ret;

    
    ret = gimp_number_pair_entry_get_user_override(GIMP_NUMBER_PAIR_ENTRY(self->obj));
    
    return PyBool_FromLong(ret);

}

static const PyMethodDef _PyGimpNumberPairEntry_methods[] = {
    { "set_default_values", (PyCFunction)_wrap_gimp_number_pair_entry_set_default_values, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_default_values", (PyCFunction)_wrap_gimp_number_pair_entry_get_default_values, METH_NOARGS,
      NULL },
    { "set_values", (PyCFunction)_wrap_gimp_number_pair_entry_set_values, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_values", (PyCFunction)_wrap_gimp_number_pair_entry_get_values, METH_NOARGS,
      NULL },
    { "set_default_text", (PyCFunction)_wrap_gimp_number_pair_entry_set_default_text, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_default_text", (PyCFunction)_wrap_gimp_number_pair_entry_get_default_text, METH_NOARGS,
      NULL },
    { "set_ratio", (PyCFunction)_wrap_gimp_number_pair_entry_set_ratio, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_ratio", (PyCFunction)_wrap_gimp_number_pair_entry_get_ratio, METH_NOARGS,
      NULL },
    { "set_aspect", (PyCFunction)_wrap_gimp_number_pair_entry_set_aspect, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_aspect", (PyCFunction)_wrap_gimp_number_pair_entry_get_aspect, METH_NOARGS,
      NULL },
    { "set_user_override", (PyCFunction)_wrap_gimp_number_pair_entry_set_user_override, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_user_override", (PyCFunction)_wrap_gimp_number_pair_entry_get_user_override, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpNumberPairEntry_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.NumberPairEntry",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpNumberPairEntry_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_number_pair_entry_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpOffsetArea ----------- */

static int
_wrap_gimp_offset_area_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "orig_width", "orig_height", NULL };
    int orig_width, orig_height;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"ii:Gimp.OffsetArea.__init__", kwlist, &orig_width, &orig_height))
        return -1;
    self->obj = (GObject *)gimp_offset_area_new(orig_width, orig_height);

    if (!self->obj) {
        PyErr_SetString(PyExc_RuntimeError, "could not create GimpOffsetArea object");
        return -1;
    }
    pygobject_register_wrapper((PyObject *)self);
    return 0;
}

static PyObject *
_wrap_gimp_offset_area_set_pixbuf(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "pixbuf", NULL };
    PyGObject *pixbuf;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:Gimp.OffsetArea.set_pixbuf", kwlist, &PyGdkPixbuf_Type, &pixbuf))
        return NULL;
    
    gimp_offset_area_set_pixbuf(GIMP_OFFSET_AREA(self->obj), GDK_PIXBUF(pixbuf->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_offset_area_set_size(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "width", "height", NULL };
    int width, height;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"ii:Gimp.OffsetArea.set_size", kwlist, &width, &height))
        return NULL;
    
    gimp_offset_area_set_size(GIMP_OFFSET_AREA(self->obj), width, height);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_offset_area_set_offsets(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "offset_x", "offset_y", NULL };
    int offset_x, offset_y;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"ii:Gimp.OffsetArea.set_offsets", kwlist, &offset_x, &offset_y))
        return NULL;
    
    gimp_offset_area_set_offsets(GIMP_OFFSET_AREA(self->obj), offset_x, offset_y);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyGimpOffsetArea_methods[] = {
    { "set_pixbuf", (PyCFunction)_wrap_gimp_offset_area_set_pixbuf, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_size", (PyCFunction)_wrap_gimp_offset_area_set_size, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_offsets", (PyCFunction)_wrap_gimp_offset_area_set_offsets, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpOffsetArea_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.OffsetArea",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpOffsetArea_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_offset_area_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpPageSelector ----------- */

 static int
_wrap_gimp_page_selector_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char* kwlist[] = { NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     ":gimpui.PageSelector.__init__",
                                     kwlist))
        return -1;

    pygobject_constructv(self, 0, NULL);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create gimpui.PageSelector object");
        return -1;
    }
    return 0;
}

static PyObject *
_wrap_gimp_page_selector_set_n_pages(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "n_pages", NULL };
    int n_pages;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Gimp.PageSelector.set_n_pages", kwlist, &n_pages))
        return NULL;
    
    gimp_page_selector_set_n_pages(GIMP_PAGE_SELECTOR(self->obj), n_pages);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_page_selector_get_n_pages(PyGObject *self)
{
    int ret;

    
    ret = gimp_page_selector_get_n_pages(GIMP_PAGE_SELECTOR(self->obj));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_gimp_page_selector_set_target(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "target", NULL };
    GimpPageSelectorTarget target;
    PyObject *py_target = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:Gimp.PageSelector.set_target", kwlist, &py_target))
        return NULL;
    if (pyg_enum_get_value(GIMP_TYPE_PAGE_SELECTOR_TARGET, py_target, (gpointer)&target))
        return NULL;
    
    gimp_page_selector_set_target(GIMP_PAGE_SELECTOR(self->obj), target);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_page_selector_get_target(PyGObject *self)
{
    gint ret;

    
    ret = gimp_page_selector_get_target(GIMP_PAGE_SELECTOR(self->obj));
    
    return pyg_enum_from_gtype(GIMP_TYPE_PAGE_SELECTOR_TARGET, ret);
}

static PyObject *
_wrap_gimp_page_selector_set_page_thumbnail(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "page_no", "thumbnail", NULL };
    int page_no;
    PyGObject *thumbnail;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"iO!:Gimp.PageSelector.set_page_thumbnail", kwlist, &page_no, &PyGdkPixbuf_Type, &thumbnail))
        return NULL;
    
    gimp_page_selector_set_page_thumbnail(GIMP_PAGE_SELECTOR(self->obj), page_no, GDK_PIXBUF(thumbnail->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_page_selector_get_page_thumbnail(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "page_no", NULL };
    int page_no;
    GdkPixbuf *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Gimp.PageSelector.get_page_thumbnail", kwlist, &page_no))
        return NULL;
    
    ret = gimp_page_selector_get_page_thumbnail(GIMP_PAGE_SELECTOR(self->obj), page_no);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_gimp_page_selector_set_page_label(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "page_no", "label", NULL };
    int page_no;
    char *label;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"is:Gimp.PageSelector.set_page_label", kwlist, &page_no, &label))
        return NULL;
    
    gimp_page_selector_set_page_label(GIMP_PAGE_SELECTOR(self->obj), page_no, label);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_page_selector_get_page_label(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "page_no", NULL };
    int page_no;
    gchar *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Gimp.PageSelector.get_page_label", kwlist, &page_no))
        return NULL;
    
    ret = gimp_page_selector_get_page_label(GIMP_PAGE_SELECTOR(self->obj), page_no);
    
    if (ret) {
        PyObject *py_ret = PyString_FromString(ret);
        g_free(ret);
        return py_ret;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_page_selector_select_all(PyGObject *self)
{
    
    gimp_page_selector_select_all(GIMP_PAGE_SELECTOR(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_page_selector_unselect_all(PyGObject *self)
{
    
    gimp_page_selector_unselect_all(GIMP_PAGE_SELECTOR(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_page_selector_select_page(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "page_no", NULL };
    int page_no;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Gimp.PageSelector.select_page", kwlist, &page_no))
        return NULL;
    
    gimp_page_selector_select_page(GIMP_PAGE_SELECTOR(self->obj), page_no);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_page_selector_unselect_page(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "page_no", NULL };
    int page_no;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Gimp.PageSelector.unselect_page", kwlist, &page_no))
        return NULL;
    
    gimp_page_selector_unselect_page(GIMP_PAGE_SELECTOR(self->obj), page_no);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_page_selector_page_is_selected(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "page_no", NULL };
    int page_no, ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Gimp.PageSelector.page_is_selected", kwlist, &page_no))
        return NULL;
    
    ret = gimp_page_selector_page_is_selected(GIMP_PAGE_SELECTOR(self->obj), page_no);
    
    return PyBool_FromLong(ret);

}

#line 1574 "gimpui.override"
static PyObject *
_wrap_gimp_page_selector_get_selected_pages(PyGObject *self)
{
    gint *selected_pages;
    gint n_selected_pages;
    PyObject *py_selected_pages;
    int i;

    selected_pages = gimp_page_selector_get_selected_pages(
                                                GIMP_PAGE_SELECTOR (self->obj),
                                                &n_selected_pages);
    
    py_selected_pages = PyTuple_New(n_selected_pages);
    for (i = 0; i < n_selected_pages; ++i)
        PyTuple_SetItem(py_selected_pages, i,
                        PyInt_FromLong(selected_pages[i]));

    g_free(selected_pages);

    return py_selected_pages;
}
#line 5199 "gimpui.c"


static PyObject *
_wrap_gimp_page_selector_select_range(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "range", NULL };
    char *range;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:Gimp.PageSelector.select_range", kwlist, &range))
        return NULL;
    
    gimp_page_selector_select_range(GIMP_PAGE_SELECTOR(self->obj), range);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_page_selector_get_selected_range(PyGObject *self)
{
    gchar *ret;

    
    ret = gimp_page_selector_get_selected_range(GIMP_PAGE_SELECTOR(self->obj));
    
    if (ret) {
        PyObject *py_ret = PyString_FromString(ret);
        g_free(ret);
        return py_ret;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyGimpPageSelector_methods[] = {
    { "set_n_pages", (PyCFunction)_wrap_gimp_page_selector_set_n_pages, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_n_pages", (PyCFunction)_wrap_gimp_page_selector_get_n_pages, METH_NOARGS,
      NULL },
    { "set_target", (PyCFunction)_wrap_gimp_page_selector_set_target, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_target", (PyCFunction)_wrap_gimp_page_selector_get_target, METH_NOARGS,
      NULL },
    { "set_page_thumbnail", (PyCFunction)_wrap_gimp_page_selector_set_page_thumbnail, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_page_thumbnail", (PyCFunction)_wrap_gimp_page_selector_get_page_thumbnail, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_page_label", (PyCFunction)_wrap_gimp_page_selector_set_page_label, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_page_label", (PyCFunction)_wrap_gimp_page_selector_get_page_label, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "select_all", (PyCFunction)_wrap_gimp_page_selector_select_all, METH_NOARGS,
      NULL },
    { "unselect_all", (PyCFunction)_wrap_gimp_page_selector_unselect_all, METH_NOARGS,
      NULL },
    { "select_page", (PyCFunction)_wrap_gimp_page_selector_select_page, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "unselect_page", (PyCFunction)_wrap_gimp_page_selector_unselect_page, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "page_is_selected", (PyCFunction)_wrap_gimp_page_selector_page_is_selected, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_selected_pages", (PyCFunction)_wrap_gimp_page_selector_get_selected_pages, METH_NOARGS,
      NULL },
    { "select_range", (PyCFunction)_wrap_gimp_page_selector_select_range, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_selected_range", (PyCFunction)_wrap_gimp_page_selector_get_selected_range, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpPageSelector_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.PageSelector",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpPageSelector_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_page_selector_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpPathEditor ----------- */

static int
_wrap_gimp_path_editor_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    GType obj_type = pyg_type_from_object((PyObject *) self);
    GParameter params[2];
    PyObject *parsed_args[2] = {NULL, };
    char *arg_names[] = {"title", "path", NULL };
    char *prop_names[] = {"title", "path", NULL };
    guint nparams, i;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O|O:gimpui.PathEditor.__init__" , arg_names , &parsed_args[0] , &parsed_args[1]))
        return -1;

    memset(params, 0, sizeof(GParameter)*2);
    if (!pyg_parse_constructor_args(obj_type, arg_names,
                                    prop_names, params, 
                                    &nparams, parsed_args))
        return -1;
    pygobject_constructv(self, nparams, params);
    for (i = 0; i < nparams; ++i)
        g_value_unset(&params[i].value);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create gimpui.PathEditor object");
        return -1;
    }
    return 0;
}

static PyObject *
_wrap_gimp_path_editor_get_path(PyGObject *self)
{
    gchar *ret;

    
    ret = gimp_path_editor_get_path(GIMP_PATH_EDITOR(self->obj));
    
    if (ret) {
        PyObject *py_ret = PyString_FromString(ret);
        g_free(ret);
        return py_ret;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_path_editor_set_path(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "path", NULL };
    char *path;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:Gimp.PathEditor.set_path", kwlist, &path))
        return NULL;
    
    gimp_path_editor_set_path(GIMP_PATH_EDITOR(self->obj), path);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_path_editor_get_writable_path(PyGObject *self)
{
    gchar *ret;

    
    ret = gimp_path_editor_get_writable_path(GIMP_PATH_EDITOR(self->obj));
    
    if (ret) {
        PyObject *py_ret = PyString_FromString(ret);
        g_free(ret);
        return py_ret;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_path_editor_set_writable_path(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "path", NULL };
    char *path;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:Gimp.PathEditor.set_writable_path", kwlist, &path))
        return NULL;
    
    gimp_path_editor_set_writable_path(GIMP_PATH_EDITOR(self->obj), path);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_path_editor_get_dir_writable(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "directory", NULL };
    char *directory;
    int ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:Gimp.PathEditor.get_dir_writable", kwlist, &directory))
        return NULL;
    
    ret = gimp_path_editor_get_dir_writable(GIMP_PATH_EDITOR(self->obj), directory);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_gimp_path_editor_set_dir_writable(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "directory", "writable", NULL };
    char *directory;
    int writable;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"si:Gimp.PathEditor.set_dir_writable", kwlist, &directory, &writable))
        return NULL;
    
    gimp_path_editor_set_dir_writable(GIMP_PATH_EDITOR(self->obj), directory, writable);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyGimpPathEditor_methods[] = {
    { "get_path", (PyCFunction)_wrap_gimp_path_editor_get_path, METH_NOARGS,
      NULL },
    { "set_path", (PyCFunction)_wrap_gimp_path_editor_set_path, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_writable_path", (PyCFunction)_wrap_gimp_path_editor_get_writable_path, METH_NOARGS,
      NULL },
    { "set_writable_path", (PyCFunction)_wrap_gimp_path_editor_set_writable_path, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_dir_writable", (PyCFunction)_wrap_gimp_path_editor_get_dir_writable, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_dir_writable", (PyCFunction)_wrap_gimp_path_editor_set_dir_writable, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpPathEditor_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.PathEditor",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpPathEditor_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_path_editor_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpPickButton ----------- */

 static int
_wrap_gimp_pick_button_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char* kwlist[] = { NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     ":gimpui.PickButton.__init__",
                                     kwlist))
        return -1;

    pygobject_constructv(self, 0, NULL);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create gimpui.PickButton object");
        return -1;
    }
    return 0;
}

PyTypeObject G_GNUC_INTERNAL PyGimpPickButton_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.PickButton",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_pick_button_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpPreview ----------- */

static PyObject *
_wrap_gimp_preview_set_update(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "update", NULL };
    int update;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Gimp.Preview.set_update", kwlist, &update))
        return NULL;
    
    gimp_preview_set_update(GIMP_PREVIEW(self->obj), update);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_preview_get_update(PyGObject *self)
{
    int ret;

    
    ret = gimp_preview_get_update(GIMP_PREVIEW(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_gimp_preview_set_bounds(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "xmin", "ymin", "xmax", "ymax", NULL };
    int xmin, ymin, xmax, ymax;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"iiii:Gimp.Preview.set_bounds", kwlist, &xmin, &ymin, &xmax, &ymax))
        return NULL;
    
    gimp_preview_set_bounds(GIMP_PREVIEW(self->obj), xmin, ymin, xmax, ymax);
    
    Py_INCREF(Py_None);
    return Py_None;
}

#line 1597 "gimpui.override"
static PyObject *
_wrap_gimp_preview_get_position(PyGObject *self)
{
    gint x;
    gint y;
  
    gimp_preview_get_position(GIMP_PREVIEW(self->obj), &x, &y);

    return Py_BuildValue("(ii)", x, y);
}
#line 5632 "gimpui.c"


#line 1609 "gimpui.override"
static PyObject *
_wrap_gimp_preview_get_size(PyGObject *self)
{
    gint width;
    gint height;
  
    gimp_preview_get_size(GIMP_PREVIEW(self->obj), &width, &height);

    return Py_BuildValue("(ii)", width, height);
}
#line 5646 "gimpui.c"


#line 1621 "gimpui.override"
static PyObject *
_wrap_gimp_preview_transform(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    gint src_x;
    gint src_y;
    gint dest_x;
    gint dest_y;

    static char *kwlist[] = {"x", "y", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "ii:GimpPreview.transform",
                                     kwlist, &src_x, &src_y))
        return NULL;

    gimp_preview_transform(GIMP_PREVIEW(self->obj), src_x, src_y, &dest_x,
                           &dest_y);

    return Py_BuildValue("(ii)", dest_x, dest_y);
}
#line 5669 "gimpui.c"


#line 1642 "gimpui.override"
static PyObject *
_wrap_gimp_preview_untransform(PyGObject *self, PyObject *args,
                               PyObject *kwargs)
{
    gint src_x;
    gint src_y;
    gint dest_x;
    gint dest_y;

    static char *kwlist[] = {"x", "y", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     "ii:GimpPreview.untransform",
                                     kwlist, &src_x, &src_y))
        return NULL;

    gimp_preview_untransform(GIMP_PREVIEW(self->obj), src_x, src_y, &dest_x,
                             &dest_y);

    return Py_BuildValue("(ii)", dest_x, dest_y);
}
#line 5694 "gimpui.c"


static PyObject *
_wrap_gimp_preview_get_area(PyGObject *self)
{
    GtkWidget *ret;

    
    ret = gimp_preview_get_area(GIMP_PREVIEW(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_gimp_preview_draw(PyGObject *self)
{
    
    gimp_preview_draw(GIMP_PREVIEW(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_preview_draw_buffer(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "buffer", "rowstride", NULL };
    int buffer_len, rowstride;
    guchar *buffer;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s#i:Gimp.Preview.draw_buffer", kwlist, &buffer, &buffer_len, &rowstride))
        return NULL;
    
    gimp_preview_draw_buffer(GIMP_PREVIEW(self->obj), buffer, rowstride);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_preview_invalidate(PyGObject *self)
{
    
    gimp_preview_invalidate(GIMP_PREVIEW(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_preview_set_default_cursor(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "cursor", NULL };
    PyObject *py_cursor;
    GdkCursor *cursor = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:Gimp.Preview.set_default_cursor", kwlist, &py_cursor))
        return NULL;
    if (pyg_boxed_check(py_cursor, GDK_TYPE_CURSOR))
        cursor = pyg_boxed_get(py_cursor, GdkCursor);
    else {
        PyErr_SetString(PyExc_TypeError, "cursor should be a GdkCursor");
        return NULL;
    }
    
    gimp_preview_set_default_cursor(GIMP_PREVIEW(self->obj), cursor);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_preview_get_controls(PyGObject *self)
{
    GtkWidget *ret;

    
    ret = gimp_preview_get_controls(GIMP_PREVIEW(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static const PyMethodDef _PyGimpPreview_methods[] = {
    { "set_update", (PyCFunction)_wrap_gimp_preview_set_update, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_update", (PyCFunction)_wrap_gimp_preview_get_update, METH_NOARGS,
      NULL },
    { "set_bounds", (PyCFunction)_wrap_gimp_preview_set_bounds, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_position", (PyCFunction)_wrap_gimp_preview_get_position, METH_NOARGS,
      NULL },
    { "get_size", (PyCFunction)_wrap_gimp_preview_get_size, METH_NOARGS,
      NULL },
    { "transform", (PyCFunction)_wrap_gimp_preview_transform, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "untransform", (PyCFunction)_wrap_gimp_preview_untransform, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_area", (PyCFunction)_wrap_gimp_preview_get_area, METH_NOARGS,
      NULL },
    { "draw", (PyCFunction)_wrap_gimp_preview_draw, METH_NOARGS,
      NULL },
    { "draw_buffer", (PyCFunction)_wrap_gimp_preview_draw_buffer, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "invalidate", (PyCFunction)_wrap_gimp_preview_invalidate, METH_NOARGS,
      NULL },
    { "set_default_cursor", (PyCFunction)_wrap_gimp_preview_set_default_cursor, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_controls", (PyCFunction)_wrap_gimp_preview_get_controls, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpPreview_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.Preview",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpPreview_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)0,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpAspectPreview ----------- */

#line 1924 "gimpui.override"
static int
_wrap_gimp_aspect_preview_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "drawable", NULL };
    PyGimpDrawable *py_drawable;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     "O!|:GimpAspectPreview.__init__", kwlist,
                                     PyGimpDrawable_Type, &py_drawable))
        return -1;

    if (!py_drawable->drawable)
        py_drawable->drawable = gimp_drawable_get(py_drawable->ID);
    
    if (pygobject_construct(self, "drawable", py_drawable->drawable, NULL))
        return -1;
    
    g_signal_connect_swapped(self->obj, "destroy",
                             (GCallback)pygimp_decref_callback, py_drawable);
    Py_INCREF(py_drawable);

    return 0;
}
#line 5882 "gimpui.c"


PyTypeObject G_GNUC_INTERNAL PyGimpAspectPreview_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.AspectPreview",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_aspect_preview_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpPreviewArea ----------- */

static int
_wrap_gimp_preview_area_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char* kwlist[] = { NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     ":gimpui.PreviewArea.__init__",
                                     kwlist))
        return -1;

    pygobject_constructv(self, 0, NULL);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create gimpui.PreviewArea object");
        return -1;
    }
    return 0;
}

static PyObject *
_wrap_gimp_preview_area_fill(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "x", "y", "width", "height", "red", "green", "blue", NULL };
    int x, y, width, height;
    char red, green, blue;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"iiiiccc:Gimp.PreviewArea.fill", kwlist, &x, &y, &width, &height, &red, &green, &blue))
        return NULL;
    
    gimp_preview_area_fill(GIMP_PREVIEW_AREA(self->obj), x, y, width, height, red, green, blue);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_preview_area_set_offsets(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "x", "y", NULL };
    int x, y;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"ii:Gimp.PreviewArea.set_offsets", kwlist, &x, &y))
        return NULL;
    
    gimp_preview_area_set_offsets(GIMP_PREVIEW_AREA(self->obj), x, y);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_preview_area_set_colormap(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "colormap", "num_colors", NULL };
    int colormap_len, num_colors;
    guchar *colormap;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s#i:Gimp.PreviewArea.set_colormap", kwlist, &colormap, &colormap_len, &num_colors))
        return NULL;
    
    gimp_preview_area_set_colormap(GIMP_PREVIEW_AREA(self->obj), colormap, num_colors);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_preview_area_set_max_size(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "width", "height", NULL };
    int width, height;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"ii:Gimp.PreviewArea.set_max_size", kwlist, &width, &height))
        return NULL;
    
    gimp_preview_area_set_max_size(GIMP_PREVIEW_AREA(self->obj), width, height);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_preview_area_menu_popup(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "event", NULL };
    GdkEvent *event = NULL;
    PyObject *py_event;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:Gimp.PreviewArea.menu_popup", kwlist, &py_event))
        return NULL;
    if (pyg_boxed_check(py_event, GDK_TYPE_EVENT))
        event = pyg_boxed_get(py_event, GdkEvent);
    else {
        PyErr_SetString(PyExc_TypeError, "event should be a GdkEvent");
        return NULL;
    }
    
    gimp_preview_area_menu_popup(GIMP_PREVIEW_AREA(self->obj), (GdkEventButton *)event);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyGimpPreviewArea_methods[] = {
    { "fill", (PyCFunction)_wrap_gimp_preview_area_fill, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_offsets", (PyCFunction)_wrap_gimp_preview_area_set_offsets, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_colormap", (PyCFunction)_wrap_gimp_preview_area_set_colormap, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_max_size", (PyCFunction)_wrap_gimp_preview_area_set_max_size, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "menu_popup", (PyCFunction)_wrap_gimp_preview_area_menu_popup, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpPreviewArea_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.PreviewArea",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpPreviewArea_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_preview_area_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpProcBrowserDialog ----------- */

#line 1400 "gimpui.override"
static int
_wrap_gimp_proc_browser_dialog_new(PyGObject *self, PyObject *args,
                                   PyObject *kwargs)
{
    gchar *title, *role;
    PyObject *py_buttons = Py_None;
    PyObject *help_func = NULL;
    gchar *help_id = NULL;
    int len, i;
    GimpHelpFunc func;

    static char *kwlist[] = { "title", "role", "help_func", "help_id",
                              "buttons", NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     "zz|OzO:gimpui.GimpProcBrowserDialog.__init__",
                                     kwlist,
                                     &title, &role, &help_func, &help_id,
                                     &py_buttons))
        return -1;

    if (py_buttons == Py_None)
        len = 0;
    else if (PyTuple_Check(py_buttons))
        len = PyTuple_Size(py_buttons);
    else {
        PyErr_SetString(PyExc_TypeError,
                        "buttons must be a tuple containing text/response "
                        "pairs or None");
        return -1;
    }

    if (len % 2) {
        PyErr_SetString(PyExc_RuntimeError,
                        "buttons tuple must contain text/response id pairs");
        return -1;
    }

    if (help_func) {
        if (help_func != Py_None) {
            if (!PyCallable_Check(help_func)) {
                PyErr_SetString(PyExc_TypeError, "help_func must be callable");
                return -1;
            }

            func = pygimp_help_func_marshal;

       } else {
            func = gimp_standard_help_func;
        }
    } else {
        func = gimp_standard_help_func;
    }

    pygobject_construct(self,
                        "title",     title,
                        "role",      role,
                        "help-func", func,
                        "help-id",   help_id,
                        NULL);

    if (!self->obj) {
        PyErr_SetString(PyExc_RuntimeError,
                        "could not create GimpProcBrowserDialog object");
        return -1;
    }

    for (i = 0; i < len; i += 2) {
        PyObject *text = PyTuple_GetItem(py_buttons, i);
        PyObject *id = PyTuple_GetItem(py_buttons, i + 1);
        if (!PyString_Check(text) && !PyUnicode_Check(text)) {
            gtk_object_destroy(GTK_OBJECT(self->obj));
            self->obj = NULL;
            PyErr_SetString(PyExc_RuntimeError,
                            "first member of each text/response id pair "
                            "must be a string");
            return -1;
        }
        if (!PyInt_Check(id)) {
            gtk_object_destroy(GTK_OBJECT(self->obj));
            self->obj = NULL;
            PyErr_SetString(PyExc_RuntimeError,
                            "second member of each text/response id pair "
                            "must be a number");
            return -1;
        }

        gimp_dialog_add_button(GIMP_DIALOG(self->obj), PyString_AsString(text),
                               PyInt_AsLong(id));
    }

    if (help_func && help_func != Py_None) {
        g_object_set_data(self->obj, "pygimp-dialog-help-data", self);

        Py_INCREF(help_func);
        g_object_set_data_full(self->obj, "pygimp-dialog-help-func",
                               help_func, pygimp_help_func_destroy);
    }

    g_signal_emit_by_name(GIMP_PROC_BROWSER_DIALOG(self->obj)->browser,
                          "search", "", 0, self->obj);
    return 0;
}
#line 6205 "gimpui.c"


static PyObject *
_wrap_gimp_proc_browser_dialog_get_selected(PyGObject *self)
{
    gchar *ret;

    
    ret = gimp_proc_browser_dialog_get_selected(GIMP_PROC_BROWSER_DIALOG(self->obj));
    
    if (ret) {
        PyObject *py_ret = PyString_FromString(ret);
        g_free(ret);
        return py_ret;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyGimpProcBrowserDialog_methods[] = {
    { "get_selected", (PyCFunction)_wrap_gimp_proc_browser_dialog_get_selected, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpProcBrowserDialog_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.ProcBrowserDialog",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpProcBrowserDialog_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_proc_browser_dialog_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpProgressBar ----------- */

static int
_wrap_gimp_progress_bar_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char* kwlist[] = { NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     ":gimpui.ProgressBar.__init__",
                                     kwlist))
        return -1;

    pygobject_constructv(self, 0, NULL);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create gimpui.ProgressBar object");
        return -1;
    }
    return 0;
}

PyTypeObject G_GNUC_INTERNAL PyGimpProgressBar_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.ProgressBar",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_progress_bar_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpScrolledPreview ----------- */

static PyObject *
_wrap_gimp_scrolled_preview_set_position(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "x", "y", NULL };
    int x, y;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"ii:Gimp.ScrolledPreview.set_position", kwlist, &x, &y))
        return NULL;
    
    gimp_scrolled_preview_set_position(GIMP_SCROLLED_PREVIEW(self->obj), x, y);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_scrolled_preview_set_policy(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "hscrollbar_policy", "vscrollbar_policy", NULL };
    PyObject *py_hscrollbar_policy = NULL, *py_vscrollbar_policy = NULL;
    GtkPolicyType hscrollbar_policy, vscrollbar_policy;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"OO:Gimp.ScrolledPreview.set_policy", kwlist, &py_hscrollbar_policy, &py_vscrollbar_policy))
        return NULL;
    if (pyg_enum_get_value(GTK_TYPE_POLICY_TYPE, py_hscrollbar_policy, (gpointer)&hscrollbar_policy))
        return NULL;
    if (pyg_enum_get_value(GTK_TYPE_POLICY_TYPE, py_vscrollbar_policy, (gpointer)&vscrollbar_policy))
        return NULL;
    
    gimp_scrolled_preview_set_policy(GIMP_SCROLLED_PREVIEW(self->obj), hscrollbar_policy, vscrollbar_policy);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_scrolled_preview_freeze(PyGObject *self)
{
    
    gimp_scrolled_preview_freeze(GIMP_SCROLLED_PREVIEW(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_scrolled_preview_thaw(PyGObject *self)
{
    
    gimp_scrolled_preview_thaw(GIMP_SCROLLED_PREVIEW(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyGimpScrolledPreview_methods[] = {
    { "set_position", (PyCFunction)_wrap_gimp_scrolled_preview_set_position, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_policy", (PyCFunction)_wrap_gimp_scrolled_preview_set_policy, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "freeze", (PyCFunction)_wrap_gimp_scrolled_preview_freeze, METH_NOARGS,
      NULL },
    { "thaw", (PyCFunction)_wrap_gimp_scrolled_preview_thaw, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpScrolledPreview_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.ScrolledPreview",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpScrolledPreview_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)0,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpDrawablePreview ----------- */

#line 1951 "gimpui.override"
static int
_wrap_gimp_drawable_preview_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "drawable", NULL };
    PyGimpDrawable *py_drawable;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     "O!|:GimpDrawablePreview.__init__", kwlist,
                                     PyGimpDrawable_Type, &py_drawable))
        return -1;

    if (!py_drawable->drawable)
        py_drawable->drawable = gimp_drawable_get(py_drawable->ID);
  
    if (pygobject_construct(self, "drawable", py_drawable->drawable, NULL))
        return -1;

    g_object_set_data_full(self->obj, "pygimp-drawable-preview-pydrawable",
                           py_drawable, 
                           (GDestroyNotify)pygimp_decref_callback);

    Py_INCREF(py_drawable);

    return 0;
}

#line 6492 "gimpui.c"


#line 1678 "gimpui.override"
static PyObject *
_wrap_gimp_drawable_preview_get_drawable(PyGObject *self)
{
    PyObject *drawable;
    
    drawable = g_object_get_data(self->obj, 
                                 "pygimp-drawable-preview-pydrawable");
    Py_INCREF(drawable);
    return drawable;
}
#line 6506 "gimpui.c"


#line 1702 "gimpui.override"
static PyObject *
_wrap_gimp_drawable_preview_draw_region(PyGObject *self, PyObject *args,
                                        PyObject *kwargs)
{
/*    PyGimpPixelRgn *pypixelrgn;

    static char *kwlist[] = {"drawable", NULL};

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                    "O!:GimpDrawablePreview.draw_region",
                                    kwlist, PyGimpPixelRgn_Type, &pypixelrgn))
        return NULL;

    gimp_drawable_preview_draw_region(GIMP_DRAWABLE_PREVIEW(self->obj),
                                      &pypixelrgn->pr);
*/
    Py_INCREF(Py_None);
    return Py_None;
}
#line 6529 "gimpui.c"


static const PyMethodDef _PyGimpDrawablePreview_methods[] = {
    { "get_drawable", (PyCFunction)_wrap_gimp_drawable_preview_get_drawable, METH_NOARGS,
      NULL },
    { "draw_region", (PyCFunction)_wrap_gimp_drawable_preview_draw_region, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpDrawablePreview_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.DrawablePreview",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpDrawablePreview_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_drawable_preview_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpSelectButton ----------- */

static PyObject *
_wrap_gimp_select_button_close_popup(PyGObject *self)
{
    
    gimp_select_button_close_popup(GIMP_SELECT_BUTTON(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyGimpSelectButton_methods[] = {
    { "close_popup", (PyCFunction)_wrap_gimp_select_button_close_popup, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpSelectButton_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.SelectButton",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpSelectButton_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)0,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpPatternSelectButton ----------- */

static int
_wrap_gimp_pattern_select_button_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    GType obj_type = pyg_type_from_object((PyObject *) self);
    GParameter params[2];
    PyObject *parsed_args[2] = {NULL, };
    char *arg_names[] = {"title", "pattern_name", NULL };
    char *prop_names[] = {"title", "pattern-name", NULL };
    guint nparams, i;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "|OO:gimpui.PatternSelectButton.__init__" , arg_names , &parsed_args[0] , &parsed_args[1]))
        return -1;

    memset(params, 0, sizeof(GParameter)*2);
    if (!pyg_parse_constructor_args(obj_type, arg_names,
                                    prop_names, params, 
                                    &nparams, parsed_args))
        return -1;
    pygobject_constructv(self, nparams, params);
    for (i = 0; i < nparams; ++i)
        g_value_unset(&params[i].value);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create gimpui.PatternSelectButton object");
        return -1;
    }
    return 0;
}

static PyObject *
_wrap_gimp_pattern_select_button_get_pattern(PyGObject *self)
{
    const gchar *ret;

    
    ret = gimp_pattern_select_button_get_pattern(GIMP_PATTERN_SELECT_BUTTON(self->obj));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_pattern_select_button_set_pattern(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "pattern_name", NULL };
    char *pattern_name;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:Gimp.PatternSelectButton.set_pattern", kwlist, &pattern_name))
        return NULL;
    
    gimp_pattern_select_button_set_pattern(GIMP_PATTERN_SELECT_BUTTON(self->obj), pattern_name);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyGimpPatternSelectButton_methods[] = {
    { "get_pattern", (PyCFunction)_wrap_gimp_pattern_select_button_get_pattern, METH_NOARGS,
      NULL },
    { "set_pattern", (PyCFunction)_wrap_gimp_pattern_select_button_set_pattern, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpPatternSelectButton_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.PatternSelectButton",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpPatternSelectButton_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_pattern_select_button_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpPaletteSelectButton ----------- */

 static int
_wrap_gimp_palette_select_button_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    GType obj_type = pyg_type_from_object((PyObject *) self);
    GParameter params[2];
    PyObject *parsed_args[2] = {NULL, };
    char *arg_names[] = {"title", "palette_name", NULL };
    char *prop_names[] = {"title", "palette-name", NULL };
    guint nparams, i;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "|OO:gimpui.PaletteSelectButton.__init__" , arg_names , &parsed_args[0] , &parsed_args[1]))
        return -1;

    memset(params, 0, sizeof(GParameter)*2);
    if (!pyg_parse_constructor_args(obj_type, arg_names,
                                    prop_names, params, 
                                    &nparams, parsed_args))
        return -1;
    pygobject_constructv(self, nparams, params);
    for (i = 0; i < nparams; ++i)
        g_value_unset(&params[i].value);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create gimpui.PaletteSelectButton object");
        return -1;
    }
    return 0;
}

static PyObject *
_wrap_gimp_palette_select_button_get_palette(PyGObject *self)
{
    const gchar *ret;

    
    ret = gimp_palette_select_button_get_palette(GIMP_PALETTE_SELECT_BUTTON(self->obj));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_palette_select_button_set_palette(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "palette_name", NULL };
    char *palette_name;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:Gimp.PaletteSelectButton.set_palette", kwlist, &palette_name))
        return NULL;
    
    gimp_palette_select_button_set_palette(GIMP_PALETTE_SELECT_BUTTON(self->obj), palette_name);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyGimpPaletteSelectButton_methods[] = {
    { "get_palette", (PyCFunction)_wrap_gimp_palette_select_button_get_palette, METH_NOARGS,
      NULL },
    { "set_palette", (PyCFunction)_wrap_gimp_palette_select_button_set_palette, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpPaletteSelectButton_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.PaletteSelectButton",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpPaletteSelectButton_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_palette_select_button_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpGradientSelectButton ----------- */

 static int
_wrap_gimp_gradient_select_button_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    GType obj_type = pyg_type_from_object((PyObject *) self);
    GParameter params[2];
    PyObject *parsed_args[2] = {NULL, };
    char *arg_names[] = {"title", "gradient_name", NULL };
    char *prop_names[] = {"title", "gradient-name", NULL };
    guint nparams, i;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "|OO:gimpui.GradientSelectButton.__init__" , arg_names , &parsed_args[0] , &parsed_args[1]))
        return -1;

    memset(params, 0, sizeof(GParameter)*2);
    if (!pyg_parse_constructor_args(obj_type, arg_names,
                                    prop_names, params, 
                                    &nparams, parsed_args))
        return -1;
    pygobject_constructv(self, nparams, params);
    for (i = 0; i < nparams; ++i)
        g_value_unset(&params[i].value);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create gimpui.GradientSelectButton object");
        return -1;
    }
    return 0;
}

static PyObject *
_wrap_gimp_gradient_select_button_get_gradient(PyGObject *self)
{
    const gchar *ret;

    
    ret = gimp_gradient_select_button_get_gradient(GIMP_GRADIENT_SELECT_BUTTON(self->obj));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_gradient_select_button_set_gradient(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "gradient_name", NULL };
    char *gradient_name;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:Gimp.GradientSelectButton.set_gradient", kwlist, &gradient_name))
        return NULL;
    
    gimp_gradient_select_button_set_gradient(GIMP_GRADIENT_SELECT_BUTTON(self->obj), gradient_name);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyGimpGradientSelectButton_methods[] = {
    { "get_gradient", (PyCFunction)_wrap_gimp_gradient_select_button_get_gradient, METH_NOARGS,
      NULL },
    { "set_gradient", (PyCFunction)_wrap_gimp_gradient_select_button_set_gradient, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpGradientSelectButton_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.GradientSelectButton",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpGradientSelectButton_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_gradient_select_button_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpFontSelectButton ----------- */

 static int
_wrap_gimp_font_select_button_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    GType obj_type = pyg_type_from_object((PyObject *) self);
    GParameter params[2];
    PyObject *parsed_args[2] = {NULL, };
    char *arg_names[] = {"title", "font_name", NULL };
    char *prop_names[] = {"title", "font-name", NULL };
    guint nparams, i;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "|OO:gimpui.FontSelectButton.__init__" , arg_names , &parsed_args[0] , &parsed_args[1]))
        return -1;

    memset(params, 0, sizeof(GParameter)*2);
    if (!pyg_parse_constructor_args(obj_type, arg_names,
                                    prop_names, params, 
                                    &nparams, parsed_args))
        return -1;
    pygobject_constructv(self, nparams, params);
    for (i = 0; i < nparams; ++i)
        g_value_unset(&params[i].value);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create gimpui.FontSelectButton object");
        return -1;
    }
    return 0;
}

static PyObject *
_wrap_gimp_font_select_button_get_font(PyGObject *self)
{
    const gchar *ret;

    
    ret = gimp_font_select_button_get_font(GIMP_FONT_SELECT_BUTTON(self->obj));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_font_select_button_set_font(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "font_name", NULL };
    char *font_name;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:Gimp.FontSelectButton.set_font", kwlist, &font_name))
        return NULL;
    
    gimp_font_select_button_set_font(GIMP_FONT_SELECT_BUTTON(self->obj), font_name);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyGimpFontSelectButton_methods[] = {
    { "get_font", (PyCFunction)_wrap_gimp_font_select_button_get_font, METH_NOARGS,
      NULL },
    { "set_font", (PyCFunction)_wrap_gimp_font_select_button_set_font, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpFontSelectButton_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.FontSelectButton",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpFontSelectButton_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_font_select_button_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpBrushSelectButton ----------- */

 static int
_wrap_gimp_brush_select_button_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    GType obj_type = pyg_type_from_object((PyObject *) self);
    GParameter params[5];
    PyObject *parsed_args[5] = {NULL, };
    char *arg_names[] = {"title", "brush_name", "opacity", "spacing", "paint_mode", NULL };
    char *prop_names[] = {"title", "brush-name", "brush-opacity", "brush-spacing", "brush-paint-mode", NULL };
    guint nparams, i;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "|OOOOO:gimpui.BrushSelectButton.__init__" , arg_names , &parsed_args[0] , &parsed_args[1] , &parsed_args[2] , &parsed_args[3] , &parsed_args[4]))
        return -1;

    memset(params, 0, sizeof(GParameter)*5);
    if (!pyg_parse_constructor_args(obj_type, arg_names,
                                    prop_names, params, 
                                    &nparams, parsed_args))
        return -1;
    pygobject_constructv(self, nparams, params);
    for (i = 0; i < nparams; ++i)
        g_value_unset(&params[i].value);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create gimpui.BrushSelectButton object");
        return -1;
    }
    return 0;
}

#line 910 "gimpui.override"
static PyObject *
_wrap_gimp_brush_select_button_get_brush(PyGObject *self)
{
    const gchar *brush_name;
    gdouble opacity;
    gint spacing;
    GimpLayerModeEffects paint_mode;

    brush_name =
        gimp_brush_select_button_get_brush(GIMP_BRUSH_SELECT_BUTTON(self->obj),
                                           &opacity, &spacing, &paint_mode);

    return Py_BuildValue("(sdiN)", brush_name, opacity, spacing,
                         pyg_enum_from_gtype(GIMP_TYPE_LAYER_MODE_EFFECTS,
                                             paint_mode));
}
#line 7165 "gimpui.c"


static PyObject *
_wrap_gimp_brush_select_button_set_brush(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "brush_name", "opacity", "spacing", "paint_mode", NULL };
    char *brush_name;
    double opacity;
    int spacing;
    PyObject *py_paint_mode = NULL;
    GimpLayerModeEffects paint_mode;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"sdiO:Gimp.BrushSelectButton.set_brush", kwlist, &brush_name, &opacity, &spacing, &py_paint_mode))
        return NULL;
    if (pyg_enum_get_value(GIMP_TYPE_LAYER_MODE_EFFECTS, py_paint_mode, (gpointer)&paint_mode))
        return NULL;
    
    gimp_brush_select_button_set_brush(GIMP_BRUSH_SELECT_BUTTON(self->obj), brush_name, opacity, spacing, paint_mode);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyGimpBrushSelectButton_methods[] = {
    { "get_brush", (PyCFunction)_wrap_gimp_brush_select_button_get_brush, METH_NOARGS,
      NULL },
    { "set_brush", (PyCFunction)_wrap_gimp_brush_select_button_set_brush, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpBrushSelectButton_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.BrushSelectButton",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpBrushSelectButton_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_brush_select_button_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpRuler ----------- */

 static int
_wrap_gimp_ruler_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    GType obj_type = pyg_type_from_object((PyObject *) self);
    GParameter params[4];
    PyObject *parsed_args[4] = {NULL, };
    char *arg_names[] = {"orientation", "lower", "upper", "max_size", NULL };
    char *prop_names[] = {"orientation", "lower", "upper", "max-size", NULL };
    guint nparams, i;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O|OOO:gimpui.Ruler.__init__" , arg_names , &parsed_args[0] , &parsed_args[1] , &parsed_args[2] , &parsed_args[3]))
        return -1;

    memset(params, 0, sizeof(GParameter)*4);
    if (!pyg_parse_constructor_args(obj_type, arg_names,
                                    prop_names, params, 
                                    &nparams, parsed_args))
        return -1;
    pygobject_constructv(self, nparams, params);
    for (i = 0; i < nparams; ++i)
        g_value_unset(&params[i].value);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create gimpui.Ruler object");
        return -1;
    }
    return 0;
}

static PyObject *
_wrap_gimp_ruler_set_unit(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "unit", NULL };
    int unit;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Gimp.Ruler.set_unit", kwlist, &unit))
        return NULL;
    
    gimp_ruler_set_unit(GIMP_RULER(self->obj), unit);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_ruler_get_unit(PyGObject *self)
{
    int ret;

    
    ret = gimp_ruler_get_unit(GIMP_RULER(self->obj));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_gimp_ruler_set_position(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "position", NULL };
    double position;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"d:Gimp.Ruler.set_position", kwlist, &position))
        return NULL;
    
    gimp_ruler_set_position(GIMP_RULER(self->obj), position);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_ruler_get_position(PyGObject *self)
{
    double ret;

    
    ret = gimp_ruler_get_position(GIMP_RULER(self->obj));
    
    return PyFloat_FromDouble(ret);
}

static PyObject *
_wrap_gimp_ruler_set_range(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "lower", "upper", "max_size", NULL };
    double lower, upper, max_size;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"ddd:Gimp.Ruler.set_range", kwlist, &lower, &upper, &max_size))
        return NULL;
    
    gimp_ruler_set_range(GIMP_RULER(self->obj), lower, upper, max_size);
    
    Py_INCREF(Py_None);
    return Py_None;
}

#line 1981 "gimpui.override"
static PyObject *
_wrap_gimp_ruler_get_range(PyGObject *self)
{
    gdouble lower, upper, max_size;

    gimp_ruler_get_range(GIMP_RULER(self->obj), &lower, &upper, &max_size);

    return Py_BuildValue("(ddd)", lower, upper, max_size);
}
#line 7353 "gimpui.c"


static const PyMethodDef _PyGimpRuler_methods[] = {
    { "set_unit", (PyCFunction)_wrap_gimp_ruler_set_unit, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_unit", (PyCFunction)_wrap_gimp_ruler_get_unit, METH_NOARGS,
      NULL },
    { "set_position", (PyCFunction)_wrap_gimp_ruler_set_position, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_position", (PyCFunction)_wrap_gimp_ruler_get_position, METH_NOARGS,
      NULL },
    { "set_range", (PyCFunction)_wrap_gimp_ruler_set_range, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_range", (PyCFunction)_wrap_gimp_ruler_get_range, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpRuler_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.Ruler",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpRuler_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_ruler_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpSizeEntry ----------- */

static int
_wrap_gimp_size_entry_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "number_of_fields", "unit", "unit_format", "menu_show_pixels", "menu_show_percent", "show_refval", "spinbutton_width", "update_policy", NULL };
    int number_of_fields, unit, menu_show_pixels, menu_show_percent, show_refval, spinbutton_width;
    char *unit_format;
    GimpSizeEntryUpdatePolicy update_policy;
    PyObject *py_update_policy = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"iisiiiiO:Gimp.SizeEntry.__init__", kwlist, &number_of_fields, &unit, &unit_format, &menu_show_pixels, &menu_show_percent, &show_refval, &spinbutton_width, &py_update_policy))
        return -1;
    if (pyg_enum_get_value(GIMP_TYPE_SIZE_ENTRY_UPDATE_POLICY, py_update_policy, (gpointer)&update_policy))
        return -1;
    self->obj = (GObject *)gimp_size_entry_new(number_of_fields, unit, unit_format, menu_show_pixels, menu_show_percent, show_refval, spinbutton_width, update_policy);

    if (!self->obj) {
        PyErr_SetString(PyExc_RuntimeError, "could not create GimpSizeEntry object");
        return -1;
    }
    pygobject_register_wrapper((PyObject *)self);
    return 0;
}

static PyObject *
_wrap_gimp_size_entry_add_field(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "value_spinbutton", "refval_spinbutton", NULL };
    PyGObject *value_spinbutton, *refval_spinbutton;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!O!:Gimp.SizeEntry.add_field", kwlist, &PyGtkSpinButton_Type, &value_spinbutton, &PyGtkSpinButton_Type, &refval_spinbutton))
        return NULL;
    
    gimp_size_entry_add_field(GIMP_SIZE_ENTRY(self->obj), GTK_SPIN_BUTTON(value_spinbutton->obj), GTK_SPIN_BUTTON(refval_spinbutton->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_size_entry_attach_label(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "text", "row", "column", "alignment", NULL };
    char *text;
    int row, column;
    GtkWidget *ret;
    double alignment;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"siid:Gimp.SizeEntry.attach_label", kwlist, &text, &row, &column, &alignment))
        return NULL;
    
    ret = gimp_size_entry_attach_label(GIMP_SIZE_ENTRY(self->obj), text, row, column, alignment);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_gimp_size_entry_set_resolution(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "field", "resolution", "keep_size", NULL };
    int field, keep_size;
    double resolution;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"idi:Gimp.SizeEntry.set_resolution", kwlist, &field, &resolution, &keep_size))
        return NULL;
    
    gimp_size_entry_set_resolution(GIMP_SIZE_ENTRY(self->obj), field, resolution, keep_size);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_size_entry_set_size(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "field", "lower", "upper", NULL };
    int field;
    double lower, upper;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"idd:Gimp.SizeEntry.set_size", kwlist, &field, &lower, &upper))
        return NULL;
    
    gimp_size_entry_set_size(GIMP_SIZE_ENTRY(self->obj), field, lower, upper);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_size_entry_set_value_boundaries(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "field", "lower", "upper", NULL };
    int field;
    double lower, upper;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"idd:Gimp.SizeEntry.set_value_boundaries", kwlist, &field, &lower, &upper))
        return NULL;
    
    gimp_size_entry_set_value_boundaries(GIMP_SIZE_ENTRY(self->obj), field, lower, upper);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_size_entry_get_value(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "field", NULL };
    int field;
    double ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Gimp.SizeEntry.get_value", kwlist, &field))
        return NULL;
    
    ret = gimp_size_entry_get_value(GIMP_SIZE_ENTRY(self->obj), field);
    
    return PyFloat_FromDouble(ret);
}

static PyObject *
_wrap_gimp_size_entry_set_value(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "field", "value", NULL };
    int field;
    double value;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"id:Gimp.SizeEntry.set_value", kwlist, &field, &value))
        return NULL;
    
    gimp_size_entry_set_value(GIMP_SIZE_ENTRY(self->obj), field, value);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_size_entry_set_refval_boundaries(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "field", "lower", "upper", NULL };
    int field;
    double lower, upper;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"idd:Gimp.SizeEntry.set_refval_boundaries", kwlist, &field, &lower, &upper))
        return NULL;
    
    gimp_size_entry_set_refval_boundaries(GIMP_SIZE_ENTRY(self->obj), field, lower, upper);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_size_entry_set_refval_digits(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "field", "digits", NULL };
    int field, digits;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"ii:Gimp.SizeEntry.set_refval_digits", kwlist, &field, &digits))
        return NULL;
    
    gimp_size_entry_set_refval_digits(GIMP_SIZE_ENTRY(self->obj), field, digits);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_size_entry_get_refval(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "field", NULL };
    int field;
    double ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Gimp.SizeEntry.get_refval", kwlist, &field))
        return NULL;
    
    ret = gimp_size_entry_get_refval(GIMP_SIZE_ENTRY(self->obj), field);
    
    return PyFloat_FromDouble(ret);
}

static PyObject *
_wrap_gimp_size_entry_set_refval(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "field", "refval", NULL };
    int field;
    double refval;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"id:Gimp.SizeEntry.set_refval", kwlist, &field, &refval))
        return NULL;
    
    gimp_size_entry_set_refval(GIMP_SIZE_ENTRY(self->obj), field, refval);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_size_entry_get_unit(PyGObject *self)
{
    int ret;

    
    ret = gimp_size_entry_get_unit(GIMP_SIZE_ENTRY(self->obj));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_gimp_size_entry_set_unit(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "unit", NULL };
    int unit;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Gimp.SizeEntry.set_unit", kwlist, &unit))
        return NULL;
    
    gimp_size_entry_set_unit(GIMP_SIZE_ENTRY(self->obj), unit);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_size_entry_show_unit_menu(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "show", NULL };
    int show;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Gimp.SizeEntry.show_unit_menu", kwlist, &show))
        return NULL;
    
    gimp_size_entry_show_unit_menu(GIMP_SIZE_ENTRY(self->obj), show);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_size_entry_set_pixel_digits(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "digits", NULL };
    int digits;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Gimp.SizeEntry.set_pixel_digits", kwlist, &digits))
        return NULL;
    
    gimp_size_entry_set_pixel_digits(GIMP_SIZE_ENTRY(self->obj), digits);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_size_entry_grab_focus(PyGObject *self)
{
    
    gimp_size_entry_grab_focus(GIMP_SIZE_ENTRY(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_size_entry_set_activates_default(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "setting", NULL };
    int setting;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Gimp.SizeEntry.set_activates_default", kwlist, &setting))
        return NULL;
    
    gimp_size_entry_set_activates_default(GIMP_SIZE_ENTRY(self->obj), setting);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_size_entry_get_help_widget(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "field", NULL };
    int field;
    GtkWidget *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Gimp.SizeEntry.get_help_widget", kwlist, &field))
        return NULL;
    
    ret = gimp_size_entry_get_help_widget(GIMP_SIZE_ENTRY(self->obj), field);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static const PyMethodDef _PyGimpSizeEntry_methods[] = {
    { "add_field", (PyCFunction)_wrap_gimp_size_entry_add_field, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "attach_label", (PyCFunction)_wrap_gimp_size_entry_attach_label, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_resolution", (PyCFunction)_wrap_gimp_size_entry_set_resolution, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_size", (PyCFunction)_wrap_gimp_size_entry_set_size, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_value_boundaries", (PyCFunction)_wrap_gimp_size_entry_set_value_boundaries, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_value", (PyCFunction)_wrap_gimp_size_entry_get_value, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_value", (PyCFunction)_wrap_gimp_size_entry_set_value, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_refval_boundaries", (PyCFunction)_wrap_gimp_size_entry_set_refval_boundaries, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_refval_digits", (PyCFunction)_wrap_gimp_size_entry_set_refval_digits, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_refval", (PyCFunction)_wrap_gimp_size_entry_get_refval, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_refval", (PyCFunction)_wrap_gimp_size_entry_set_refval, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_unit", (PyCFunction)_wrap_gimp_size_entry_get_unit, METH_NOARGS,
      NULL },
    { "set_unit", (PyCFunction)_wrap_gimp_size_entry_set_unit, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "show_unit_menu", (PyCFunction)_wrap_gimp_size_entry_show_unit_menu, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_pixel_digits", (PyCFunction)_wrap_gimp_size_entry_set_pixel_digits, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "grab_focus", (PyCFunction)_wrap_gimp_size_entry_grab_focus, METH_NOARGS,
      NULL },
    { "set_activates_default", (PyCFunction)_wrap_gimp_size_entry_set_activates_default, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_help_widget", (PyCFunction)_wrap_gimp_size_entry_get_help_widget, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpSizeEntry_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.SizeEntry",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpSizeEntry_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_size_entry_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpStringComboBox ----------- */

 static int
_wrap_gimp_string_combo_box_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    GType obj_type = pyg_type_from_object((PyObject *) self);
    GParameter params[3];
    PyObject *parsed_args[3] = {NULL, };
    char *arg_names[] = {"model", "id_column", "label_column", NULL };
    char *prop_names[] = {"model", "id-column", "label-column", NULL };
    guint nparams, i;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OOO:gimpui.StringComboBox.__init__" , arg_names , &parsed_args[0] , &parsed_args[1] , &parsed_args[2]))
        return -1;

    memset(params, 0, sizeof(GParameter)*3);
    if (!pyg_parse_constructor_args(obj_type, arg_names,
                                    prop_names, params, 
                                    &nparams, parsed_args))
        return -1;
    pygobject_constructv(self, nparams, params);
    for (i = 0; i < nparams; ++i)
        g_value_unset(&params[i].value);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create gimpui.StringComboBox object");
        return -1;
    }
    return 0;
}

static PyObject *
_wrap_gimp_string_combo_box_set_active(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "id", NULL };
    char *id;
    int ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:Gimp.StringComboBox.set_active", kwlist, &id))
        return NULL;
    
    ret = gimp_string_combo_box_set_active(GIMP_STRING_COMBO_BOX(self->obj), id);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_gimp_string_combo_box_get_active(PyGObject *self)
{
    gchar *ret;

    
    ret = gimp_string_combo_box_get_active(GIMP_STRING_COMBO_BOX(self->obj));
    
    if (ret) {
        PyObject *py_ret = PyString_FromString(ret);
        g_free(ret);
        return py_ret;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyGimpStringComboBox_methods[] = {
    { "set_active", (PyCFunction)_wrap_gimp_string_combo_box_set_active, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_active", (PyCFunction)_wrap_gimp_string_combo_box_get_active, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpStringComboBox_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.StringComboBox",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpStringComboBox_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_string_combo_box_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpUnitComboBox ----------- */

 static int
_wrap_gimp_unit_combo_box_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char* kwlist[] = { NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     ":gimpui.UnitComboBox.__init__",
                                     kwlist))
        return -1;

    pygobject_constructv(self, 0, NULL);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create gimpui.UnitComboBox object");
        return -1;
    }
    return 0;
}

static PyObject *
_wrap_gimp_unit_combo_box_get_active(PyGObject *self)
{
    int ret;

    
    ret = gimp_unit_combo_box_get_active(GIMP_UNIT_COMBO_BOX(self->obj));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_gimp_unit_combo_box_set_active(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "unit", NULL };
    int unit;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Gimp.UnitComboBox.set_active", kwlist, &unit))
        return NULL;
    
    gimp_unit_combo_box_set_active(GIMP_UNIT_COMBO_BOX(self->obj), unit);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyGimpUnitComboBox_methods[] = {
    { "get_active", (PyCFunction)_wrap_gimp_unit_combo_box_get_active, METH_NOARGS,
      NULL },
    { "set_active", (PyCFunction)_wrap_gimp_unit_combo_box_set_active, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpUnitComboBox_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.UnitComboBox",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpUnitComboBox_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_unit_combo_box_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpUnitMenu ----------- */

static int
_wrap_gimp_unit_menu_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "format", "unit", "show_pixels", "show_percent", "show_custom", NULL };
    char *format;
    int unit, show_pixels, show_percent, show_custom;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"siiii:Gimp.UnitMenu.__init__", kwlist, &format, &unit, &show_pixels, &show_percent, &show_custom))
        return -1;
    if (PyErr_Warn(PyExc_DeprecationWarning, "use gimpui.UnitComboBox instead") < 0)
        return -1;
    self->obj = (GObject *)gimp_unit_menu_new(format, unit, show_pixels, show_percent, show_custom);

    if (!self->obj) {
        PyErr_SetString(PyExc_RuntimeError, "could not create GimpUnitMenu object");
        return -1;
    }
    pygobject_register_wrapper((PyObject *)self);
    return 0;
}

static PyObject *
_wrap_gimp_unit_menu_set_unit(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "unit", NULL };
    int unit;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Gimp.UnitMenu.set_unit", kwlist, &unit))
        return NULL;
    if (PyErr_Warn(PyExc_DeprecationWarning, "use gimpui.UnitComboBox instead") < 0)
        return NULL;
    
    gimp_unit_menu_set_unit(GIMP_UNIT_MENU(self->obj), unit);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_unit_menu_get_unit(PyGObject *self)
{
    int ret;

    if (PyErr_Warn(PyExc_DeprecationWarning, "use gimpui.UnitComboBox instead") < 0)
        return NULL;
    
    ret = gimp_unit_menu_get_unit(GIMP_UNIT_MENU(self->obj));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_gimp_unit_menu_set_pixel_digits(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "digits", NULL };
    int digits;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Gimp.UnitMenu.set_pixel_digits", kwlist, &digits))
        return NULL;
    if (PyErr_Warn(PyExc_DeprecationWarning, "use gimpui.UnitComboBox instead") < 0)
        return NULL;
    
    gimp_unit_menu_set_pixel_digits(GIMP_UNIT_MENU(self->obj), digits);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_unit_menu_get_pixel_digits(PyGObject *self)
{
    int ret;

    if (PyErr_Warn(PyExc_DeprecationWarning, "use gimpui.UnitComboBox instead") < 0)
        return NULL;
    
    ret = gimp_unit_menu_get_pixel_digits(GIMP_UNIT_MENU(self->obj));
    
    return PyInt_FromLong(ret);
}

static const PyMethodDef _PyGimpUnitMenu_methods[] = {
    { "set_unit", (PyCFunction)_wrap_gimp_unit_menu_set_unit, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_unit", (PyCFunction)_wrap_gimp_unit_menu_get_unit, METH_NOARGS,
      NULL },
    { "set_pixel_digits", (PyCFunction)_wrap_gimp_unit_menu_set_pixel_digits, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_pixel_digits", (PyCFunction)_wrap_gimp_unit_menu_get_pixel_digits, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpUnitMenu_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.UnitMenu",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpUnitMenu_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_unit_menu_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpVectorsComboBox ----------- */

#line 475 "gimpui.override"
static gboolean
pygimp_vectors_constraint_marshal(gint32 image_id, gint32 vectors_id,
                                  gpointer user_data)
{
    PyObject *img, *vect, *ret;
    gboolean res;
    PyGimpConstraintData *data = user_data;

    img = pygimp_image_new(image_id);
    if (!img) {
        PyErr_Print();
        return FALSE;
    }

    vect = pygimp_vectors_new(vectors_id);
    if (!vect) {
        PyErr_Print();
        Py_DECREF(img);
        return FALSE;
    }

    if (data->user_data && data->user_data != Py_None)
        ret = PyObject_CallFunctionObjArgs(data->constraint, img, vect,
                                           data->user_data, NULL);
    else
        ret = PyObject_CallFunctionObjArgs(data->constraint, img, vect, NULL);

    if (!ret) {
        PyErr_Print();
        res = FALSE;
    } else {
        res = PyObject_IsTrue(ret);
        Py_DECREF(ret);
    }

    Py_DECREF(vect);
    Py_DECREF(img);

    return res;
}

static int
_wrap_gimp_vectors_combo_box_new(PyGObject *self, PyObject *args,
                                 PyObject *kwargs)
{
    PyObject *constraint = NULL, *user_data = NULL;
    GimpVectorsConstraintFunc func = NULL;
    PyGimpConstraintData *data = NULL;

    static char *kwlist[] = { "constraint", "data", NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     "|OO:gimpui.VectorsComboBox.__init__",
                                     kwlist,
                                     &constraint, &user_data))
        return -1;

    if (constraint && constraint != Py_None) {
        if (!PyCallable_Check(constraint)) {
            PyErr_SetString(PyExc_TypeError, "first arg must be callable");
            return -1;
        }

        data = g_new(PyGimpConstraintData, 1);

        data->constraint = constraint;
        Py_INCREF(constraint);

        data->user_data = user_data;
        Py_XINCREF(user_data);

        func = pygimp_vectors_constraint_marshal;
    }

    self->obj = (GObject *)gimp_vectors_combo_box_new(func, data);

    Py_XDECREF(constraint);
    Py_XDECREF(user_data);
    g_free(data);

    if (pyg_type_from_object((PyObject *)self) != GIMP_TYPE_VECTORS_COMBO_BOX) {
        PyErr_SetString(PyExc_RuntimeError, "__gobject_init__ must be used "
                        "when subclassing gimpui.VectorsComboBox");
        return -1;
    }

    pygobject_register_wrapper((PyObject *)self);
    return 0;
}
#line 8259 "gimpui.c"


#line 592 "gimpui.override"
static PyObject *
_wrap_gimp_vectors_combo_box_get_active_vectors(PyGObject *self)
{
    int value;

    if (gimp_int_combo_box_get_active(GIMP_INT_COMBO_BOX(self->obj), &value))
        return pygimp_vectors_new(value);

    Py_INCREF(Py_None);
    return Py_None;
}
#line 8274 "gimpui.c"


#line 566 "gimpui.override"
static PyObject *
_wrap_gimp_vectors_combo_box_set_active_vectors(PyGObject *self, PyObject *args,
                                                PyObject *kwargs)
{
    PyGimpVectors *vect;

    static char *kwlist[] = { "vectors", NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, 
                                   "O!:GimpVectorsComboBox.set_active_vectors",
                                   kwlist,
                                   PyGimpVectors_Type, &vect))
        return NULL;

    if (!gimp_int_combo_box_set_active(GIMP_INT_COMBO_BOX(self->obj), vect->ID)) {
        PyErr_Format(pygimp_error,
                     "Vectors (ID %d) does not exist in GimpVectorsComboBox",
                     vect->ID);
        return NULL;
    }

    Py_INCREF(Py_None);
    return Py_None;
}
#line 8302 "gimpui.c"


static const PyMethodDef _PyGimpVectorsComboBox_methods[] = {
    { "get_active_vectors", (PyCFunction)_wrap_gimp_vectors_combo_box_get_active_vectors, METH_NOARGS,
      NULL },
    { "set_active_vectors", (PyCFunction)_wrap_gimp_vectors_combo_box_set_active_vectors, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpVectorsComboBox_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.VectorsComboBox",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpVectorsComboBox_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_vectors_combo_box_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpZoomModel ----------- */

static int
_wrap_gimp_zoom_model_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char* kwlist[] = { NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     ":gimpui.ZoomModel.__init__",
                                     kwlist))
        return -1;

    pygobject_constructv(self, 0, NULL);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create gimpui.ZoomModel object");
        return -1;
    }
    return 0;
}

static PyObject *
_wrap_gimp_zoom_model_set_range(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "min", "max", NULL };
    double min, max;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"dd:Gimp.ZoomModel.set_range", kwlist, &min, &max))
        return NULL;
    
    gimp_zoom_model_set_range(GIMP_ZOOM_MODEL(self->obj), min, max);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_zoom_model_zoom(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "zoom_type", "scale", NULL };
    PyObject *py_zoom_type = NULL;
    double scale;
    GimpZoomType zoom_type;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"Od:Gimp.ZoomModel.zoom", kwlist, &py_zoom_type, &scale))
        return NULL;
    if (pyg_enum_get_value(GIMP_TYPE_ZOOM_TYPE, py_zoom_type, (gpointer)&zoom_type))
        return NULL;
    
    gimp_zoom_model_zoom(GIMP_ZOOM_MODEL(self->obj), zoom_type, scale);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_zoom_model_get_factor(PyGObject *self)
{
    double ret;

    
    ret = gimp_zoom_model_get_factor(GIMP_ZOOM_MODEL(self->obj));
    
    return PyFloat_FromDouble(ret);
}

#line 1665 "gimpui.override"
static PyObject *
_wrap_gimp_zoom_model_get_fraction(PyGObject *self)
{
    gint numerator;
    gint denominator;

    gimp_zoom_model_get_fraction(GIMP_ZOOM_MODEL(self->obj), &numerator,
                                 &denominator);

    return Py_BuildValue("(ii)", numerator, denominator);
}
#line 8439 "gimpui.c"


static const PyMethodDef _PyGimpZoomModel_methods[] = {
    { "set_range", (PyCFunction)_wrap_gimp_zoom_model_set_range, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "zoom", (PyCFunction)_wrap_gimp_zoom_model_zoom, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_factor", (PyCFunction)_wrap_gimp_zoom_model_get_factor, METH_NOARGS,
      NULL },
    { "get_fraction", (PyCFunction)_wrap_gimp_zoom_model_get_fraction, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpZoomModel_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.ZoomModel",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpZoomModel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_zoom_model_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- GimpZoomPreview ----------- */

#line 1887 "gimpui.override"
static int
_wrap_gimp_zoom_preview_new_with_model(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "drawable", "model", NULL };
    PyGimpDrawable *py_drawable;
    PyGObject *py_zoom_model = NULL;
    GimpZoomModel *zoom_model;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     "O!|O!:GimpZoomPreview.__init__", kwlist,
                                     PyGimpDrawable_Type, &py_drawable,
                                     &PyGimpZoomModel_Type, &py_zoom_model))
        return -1;

    if (py_zoom_model)
        zoom_model = (GimpZoomModel*)py_zoom_model->obj;
    else
        zoom_model = NULL;

    if (!py_drawable->drawable)
        py_drawable->drawable = gimp_drawable_get(py_drawable->ID);

    if (pygobject_construct(self, "drawable", py_drawable->drawable, "model", zoom_model, NULL))
        return -1;

    g_object_set_data_full(self->obj, "pygimp-zoom-preview-pydrawable",
                           py_drawable,
                           (GDestroyNotify)pygimp_decref_callback);

    Py_INCREF(py_drawable);

    return 0;
}
#line 8537 "gimpui.c"


#line 1690 "gimpui.override"
static PyObject *
_wrap_gimp_zoom_preview_get_drawable(PyGObject *self)
{
    PyObject *drawable;
    
    drawable = g_object_get_data(self->obj,
                                 "pygimp-zoom-preview-pydrawable");
    Py_INCREF(drawable);
    return drawable;
}
#line 8551 "gimpui.c"


static PyObject *
_wrap_gimp_zoom_preview_get_model(PyGObject *self)
{
    GimpZoomModel *ret;

    
    ret = gimp_zoom_preview_get_model(GIMP_ZOOM_PREVIEW(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_gimp_zoom_preview_get_factor(PyGObject *self)
{
    double ret;

    
    ret = gimp_zoom_preview_get_factor(GIMP_ZOOM_PREVIEW(self->obj));
    
    return PyFloat_FromDouble(ret);
}

static const PyMethodDef _PyGimpZoomPreview_methods[] = {
    { "get_drawable", (PyCFunction)_wrap_gimp_zoom_preview_get_drawable, METH_NOARGS,
      NULL },
    { "get_model", (PyCFunction)_wrap_gimp_zoom_preview_get_model, METH_NOARGS,
      NULL },
    { "get_factor", (PyCFunction)_wrap_gimp_zoom_preview_get_factor, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpZoomPreview_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpui.ZoomPreview",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyGimpZoomPreview_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_zoom_preview_new_with_model,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- functions ----------- */

static PyObject *
_wrap_gimp_enum_combo_box_new_with_model(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "enum_store", NULL };
    PyGObject *enum_store;
    GtkWidget *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:gimp_enum_combo_box_new_with_model", kwlist, &PyGimpEnumStore_Type, &enum_store))
        return NULL;
    
    ret = gimp_enum_combo_box_new_with_model(GIMP_ENUM_STORE(enum_store->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_gimp_enum_store_new_with_range(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "enum_type", "minimum", "maximum", NULL };
    PyObject *py_enum_type = NULL;
    int minimum, maximum;
    GType enum_type;
    GtkListStore *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"Oii:gimp_enum_store_new_with_range", kwlist, &py_enum_type, &minimum, &maximum))
        return NULL;
    if ((enum_type = pyg_type_from_object(py_enum_type)) == 0)
        return NULL;
    
    ret = gimp_enum_store_new_with_range(enum_type, minimum, maximum);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_gimp_zoom_model_zoom_step(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "zoom_type", "scale", NULL };
    PyObject *py_zoom_type = NULL;
    double scale, ret;
    GimpZoomType zoom_type;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"Od:gimp_zoom_model_zoom_step", kwlist, &py_zoom_type, &scale))
        return NULL;
    if (pyg_enum_get_value(GIMP_TYPE_ZOOM_TYPE, py_zoom_type, (gpointer)&zoom_type))
        return NULL;
    
    ret = gimp_zoom_model_zoom_step(zoom_type, scale);
    
    return PyFloat_FromDouble(ret);
}

static PyObject *
_wrap_gimp_pattern_select_destroy(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "pattern_callback", NULL };
    char *pattern_callback;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:gimp_pattern_select_destroy", kwlist, &pattern_callback))
        return NULL;
    
    gimp_pattern_select_destroy(pattern_callback);
    
    Py_INCREF(Py_None);
    return Py_None;
}

const PyMethodDef gimpui_functions[] = {
    { "gimp_enum_combo_box_new_with_model", (PyCFunction)_wrap_gimp_enum_combo_box_new_with_model, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "gimp_enum_store_new_with_range", (PyCFunction)_wrap_gimp_enum_store_new_with_range, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "gimp_zoom_model_zoom_step", (PyCFunction)_wrap_gimp_zoom_model_zoom_step, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "gimp_pattern_select_destroy", (PyCFunction)_wrap_gimp_pattern_select_destroy, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};


/* ----------- enums and flags ----------- */

void
gimpui_add_constants(PyObject *module, const gchar *strip_prefix)
{
#ifdef VERSION
    PyModule_AddStringConstant(module, "__version__", VERSION);
#endif
  pyg_enum_add(module, "AspectType", strip_prefix, GIMP_TYPE_ASPECT_TYPE);
  pyg_enum_add(module, "ChainPosition", strip_prefix, GIMP_TYPE_CHAIN_POSITION);
  pyg_enum_add(module, "ColorAreaType", strip_prefix, GIMP_TYPE_COLOR_AREA_TYPE);
  pyg_enum_add(module, "ColorSelectorChannel", strip_prefix, GIMP_TYPE_COLOR_SELECTOR_CHANNEL);
  pyg_enum_add(module, "PageSelectorTarget", strip_prefix, GIMP_TYPE_PAGE_SELECTOR_TARGET);
  pyg_enum_add(module, "SizeEntryUpdatePolicy", strip_prefix, GIMP_TYPE_SIZE_ENTRY_UPDATE_POLICY);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GIMP_UNIT_PIXEL", strip_prefix), GIMP_UNIT_PIXEL);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GIMP_UNIT_INCH", strip_prefix), GIMP_UNIT_INCH);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GIMP_UNIT_MM", strip_prefix), GIMP_UNIT_MM);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GIMP_UNIT_POINT", strip_prefix), GIMP_UNIT_POINT);
    PyModule_AddIntConstant(module, (char *) pyg_constant_strip_prefix("GIMP_UNIT_PICA", strip_prefix), GIMP_UNIT_PICA);
  pyg_enum_add(module, "ZoomType", strip_prefix, GIMP_TYPE_ZOOM_TYPE);

  if (PyErr_Occurred())
    PyErr_Print();
}

/* initialise stuff extension classes */
void
gimpui_register_classes(PyObject *d)
{
    PyObject *module;

    if ((module = PyImport_ImportModule("gobject")) != NULL) {
        _PyGObject_Type = (PyTypeObject *)PyObject_GetAttrString(module, "GObject");
        if (_PyGObject_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name GObject from gobject");
            return ;
        }
    } else {
        PyErr_SetString(PyExc_ImportError,
            "could not import gobject");
        return ;
    }
    if ((module = PyImport_ImportModule("gtk")) != NULL) {
        _PyGtkObject_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Object");
        if (_PyGtkObject_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Object from gtk");
            return ;
        }
        _PyGtkWidget_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Widget");
        if (_PyGtkWidget_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Widget from gtk");
            return ;
        }
        _PyGtkDialog_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Dialog");
        if (_PyGtkDialog_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Dialog from gtk");
            return ;
        }
        _PyGtkWindow_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Window");
        if (_PyGtkWindow_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Window from gtk");
            return ;
        }
        _PyGtkLabel_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Label");
        if (_PyGtkLabel_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Label from gtk");
            return ;
        }
        _PyGtkButton_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Button");
        if (_PyGtkButton_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Button from gtk");
            return ;
        }
        _PyGtkToggleButton_Type = (PyTypeObject *)PyObject_GetAttrString(module, "ToggleButton");
        if (_PyGtkToggleButton_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name ToggleButton from gtk");
            return ;
        }
        _PyGtkRadioButton_Type = (PyTypeObject *)PyObject_GetAttrString(module, "RadioButton");
        if (_PyGtkRadioButton_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name RadioButton from gtk");
            return ;
        }
        _PyGtkSpinButton_Type = (PyTypeObject *)PyObject_GetAttrString(module, "SpinButton");
        if (_PyGtkSpinButton_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name SpinButton from gtk");
            return ;
        }
        _PyGtkEntry_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Entry");
        if (_PyGtkEntry_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Entry from gtk");
            return ;
        }
        _PyGtkDrawingArea_Type = (PyTypeObject *)PyObject_GetAttrString(module, "DrawingArea");
        if (_PyGtkDrawingArea_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name DrawingArea from gtk");
            return ;
        }
        _PyGtkTable_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Table");
        if (_PyGtkTable_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Table from gtk");
            return ;
        }
        _PyGtkFrame_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Frame");
        if (_PyGtkFrame_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Frame from gtk");
            return ;
        }
        _PyGtkHBox_Type = (PyTypeObject *)PyObject_GetAttrString(module, "HBox");
        if (_PyGtkHBox_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name HBox from gtk");
            return ;
        }
        _PyGtkVBox_Type = (PyTypeObject *)PyObject_GetAttrString(module, "VBox");
        if (_PyGtkVBox_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name VBox from gtk");
            return ;
        }
        _PyGtkHPaned_Type = (PyTypeObject *)PyObject_GetAttrString(module, "HPaned");
        if (_PyGtkHPaned_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name HPaned from gtk");
            return ;
        }
        _PyGtkVPaned_Type = (PyTypeObject *)PyObject_GetAttrString(module, "VPaned");
        if (_PyGtkVPaned_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name VPaned from gtk");
            return ;
        }
        _PyGtkScale_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Scale");
        if (_PyGtkScale_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Scale from gtk");
            return ;
        }
        _PyGtkProgressBar_Type = (PyTypeObject *)PyObject_GetAttrString(module, "ProgressBar");
        if (_PyGtkProgressBar_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name ProgressBar from gtk");
            return ;
        }
        _PyGtkOptionMenu_Type = (PyTypeObject *)PyObject_GetAttrString(module, "OptionMenu");
        if (_PyGtkOptionMenu_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name OptionMenu from gtk");
            return ;
        }
        _PyGtkComboBox_Type = (PyTypeObject *)PyObject_GetAttrString(module, "ComboBox");
        if (_PyGtkComboBox_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name ComboBox from gtk");
            return ;
        }
        _PyGtkListStore_Type = (PyTypeObject *)PyObject_GetAttrString(module, "ListStore");
        if (_PyGtkListStore_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name ListStore from gtk");
            return ;
        }
        _PyGtkTreeModel_Type = (PyTypeObject *)PyObject_GetAttrString(module, "TreeModel");
        if (_PyGtkTreeModel_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name TreeModel from gtk");
            return ;
        }
        _PyGtkCellRenderer_Type = (PyTypeObject *)PyObject_GetAttrString(module, "CellRenderer");
        if (_PyGtkCellRenderer_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name CellRenderer from gtk");
            return ;
        }
        _PyGtkCellRendererToggle_Type = (PyTypeObject *)PyObject_GetAttrString(module, "CellRendererToggle");
        if (_PyGtkCellRendererToggle_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name CellRendererToggle from gtk");
            return ;
        }
    } else {
        PyErr_SetString(PyExc_ImportError,
            "could not import gtk");
        return ;
    }
    if ((module = PyImport_ImportModule("gtk.gdk")) != NULL) {
        _PyGdkPixbuf_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Pixbuf");
        if (_PyGdkPixbuf_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Pixbuf from gtk.gdk");
            return ;
        }
    } else {
        PyErr_SetString(PyExc_ImportError,
            "could not import gtk.gdk");
        return ;
    }
    if ((module = PyImport_ImportModule("gimp")) != NULL) {
        _PyGimpParasite_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Parasite");
        if (_PyGimpParasite_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Parasite from gimp");
            return ;
        }
    } else {
        PyErr_SetString(PyExc_ImportError,
            "could not import gimp");
        return ;
    }


#line 8943 "gimpui.c"
    pygobject_register_class(d, "GimpBrowser", GIMP_TYPE_BROWSER, &PyGimpBrowser_Type, Py_BuildValue("(O)", &PyGtkHPaned_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_BROWSER);
    pygobject_register_class(d, "GimpButton", GIMP_TYPE_BUTTON, &PyGimpButton_Type, Py_BuildValue("(O)", &PyGtkButton_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_BUTTON);
    pygobject_register_class(d, "GimpCellRendererColor", GIMP_TYPE_CELL_RENDERER_COLOR, &PyGimpCellRendererColor_Type, Py_BuildValue("(O)", &PyGtkCellRenderer_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_CELL_RENDERER_COLOR);
    pygobject_register_class(d, "GimpCellRendererToggle", GIMP_TYPE_CELL_RENDERER_TOGGLE, &PyGimpCellRendererToggle_Type, Py_BuildValue("(O)", &PyGtkCellRendererToggle_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_CELL_RENDERER_TOGGLE);
    pygobject_register_class(d, "GimpChainButton", GIMP_TYPE_CHAIN_BUTTON, &PyGimpChainButton_Type, Py_BuildValue("(O)", &PyGtkTable_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_CHAIN_BUTTON);
    pygobject_register_class(d, "GimpColorArea", GIMP_TYPE_COLOR_AREA, &PyGimpColorArea_Type, Py_BuildValue("(O)", &PyGtkDrawingArea_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_COLOR_AREA);
    pygobject_register_class(d, "GimpColorButton", GIMP_TYPE_COLOR_BUTTON, &PyGimpColorButton_Type, Py_BuildValue("(O)", &PyGimpButton_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_COLOR_BUTTON);
    pygobject_register_class(d, "GimpColorDisplay", GIMP_TYPE_COLOR_DISPLAY, &PyGimpColorDisplay_Type, Py_BuildValue("(O)", &PyGObject_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_COLOR_DISPLAY);
    pygobject_register_class(d, "GimpColorDisplayStack", GIMP_TYPE_COLOR_DISPLAY_STACK, &PyGimpColorDisplayStack_Type, Py_BuildValue("(O)", &PyGObject_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_COLOR_DISPLAY_STACK);
    pygobject_register_class(d, "GimpColorHexEntry", GIMP_TYPE_COLOR_HEX_ENTRY, &PyGimpColorHexEntry_Type, Py_BuildValue("(O)", &PyGtkEntry_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_COLOR_HEX_ENTRY);
    pygobject_register_class(d, "GimpColorProfileComboBox", GIMP_TYPE_COLOR_PROFILE_COMBO_BOX, &PyGimpColorProfileComboBox_Type, Py_BuildValue("(O)", &PyGtkComboBox_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_COLOR_PROFILE_COMBO_BOX);
    pygobject_register_class(d, "GimpColorProfileStore", GIMP_TYPE_COLOR_PROFILE_STORE, &PyGimpColorProfileStore_Type, Py_BuildValue("(O)", &PyGtkListStore_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_COLOR_PROFILE_STORE);
    pygobject_register_class(d, "GimpColorScale", GIMP_TYPE_COLOR_SCALE, &PyGimpColorScale_Type, Py_BuildValue("(O)", &PyGtkScale_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_COLOR_SCALE);
    pygobject_register_class(d, "GimpColorSelection", GIMP_TYPE_COLOR_SELECTION, &PyGimpColorSelection_Type, Py_BuildValue("(O)", &PyGtkVBox_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_COLOR_SELECTION);
    pygobject_register_class(d, "GimpColorSelector", GIMP_TYPE_COLOR_SELECTOR, &PyGimpColorSelector_Type, Py_BuildValue("(O)", &PyGtkVBox_Type));
    pygobject_register_class(d, "GimpColorScales", GIMP_TYPE_COLOR_SCALES, &PyGimpColorScales_Type, Py_BuildValue("(O)", &PyGimpColorSelector_Type));
    pygobject_register_class(d, "GimpColorNotebook", GIMP_TYPE_COLOR_NOTEBOOK, &PyGimpColorNotebook_Type, Py_BuildValue("(O)", &PyGimpColorSelector_Type));
    pygobject_register_class(d, "GimpDialog", GIMP_TYPE_DIALOG, &PyGimpDialog_Type, Py_BuildValue("(O)", &PyGtkDialog_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_DIALOG);
    pygobject_register_class(d, "GimpEnumLabel", GIMP_TYPE_ENUM_LABEL, &PyGimpEnumLabel_Type, Py_BuildValue("(O)", &PyGtkLabel_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_ENUM_LABEL);
    pygobject_register_class(d, "GimpFrame", GIMP_TYPE_FRAME, &PyGimpFrame_Type, Py_BuildValue("(O)", &PyGtkFrame_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_FRAME);
    pygobject_register_class(d, "GimpHintBox", GIMP_TYPE_HINT_BOX, &PyGimpHintBox_Type, Py_BuildValue("(O)", &PyGtkHBox_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_HINT_BOX);
    pygobject_register_class(d, "GimpIntComboBox", GIMP_TYPE_INT_COMBO_BOX, &PyGimpIntComboBox_Type, Py_BuildValue("(O)", &PyGtkComboBox_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_INT_COMBO_BOX);
    pygobject_register_class(d, "GimpImageComboBox", GIMP_TYPE_IMAGE_COMBO_BOX, &PyGimpImageComboBox_Type, Py_BuildValue("(O)", &PyGimpIntComboBox_Type));
    pygobject_register_class(d, "GimpEnumComboBox", GIMP_TYPE_ENUM_COMBO_BOX, &PyGimpEnumComboBox_Type, Py_BuildValue("(O)", &PyGimpIntComboBox_Type));
    pygobject_register_class(d, "GimpDrawableComboBox", GIMP_TYPE_DRAWABLE_COMBO_BOX, &PyGimpDrawableComboBox_Type, Py_BuildValue("(O)", &PyGimpIntComboBox_Type));
    pygobject_register_class(d, "GimpChannelComboBox", GIMP_TYPE_CHANNEL_COMBO_BOX, &PyGimpChannelComboBox_Type, Py_BuildValue("(O)", &PyGimpIntComboBox_Type));
    pygobject_register_class(d, "GimpIntStore", GIMP_TYPE_INT_STORE, &PyGimpIntStore_Type, Py_BuildValue("(O)", &PyGtkListStore_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_INT_STORE);
    pygobject_register_class(d, "GimpEnumStore", GIMP_TYPE_ENUM_STORE, &PyGimpEnumStore_Type, Py_BuildValue("(O)", &PyGimpIntStore_Type));
    pygobject_register_class(d, "GimpLayerComboBox", GIMP_TYPE_LAYER_COMBO_BOX, &PyGimpLayerComboBox_Type, Py_BuildValue("(O)", &PyGimpIntComboBox_Type));
    pygobject_register_class(d, "GimpMemsizeEntry", GIMP_TYPE_MEMSIZE_ENTRY, &PyGimpMemsizeEntry_Type, Py_BuildValue("(O)", &PyGtkHBox_Type));
    pygobject_register_class(d, "GimpNumberPairEntry", GIMP_TYPE_NUMBER_PAIR_ENTRY, &PyGimpNumberPairEntry_Type, Py_BuildValue("(O)", &PyGtkEntry_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_NUMBER_PAIR_ENTRY);
    pygobject_register_class(d, "GimpOffsetArea", GIMP_TYPE_OFFSET_AREA, &PyGimpOffsetArea_Type, Py_BuildValue("(O)", &PyGtkDrawingArea_Type));
    pygobject_register_class(d, "GimpPageSelector", GIMP_TYPE_PAGE_SELECTOR, &PyGimpPageSelector_Type, Py_BuildValue("(O)", &PyGtkVBox_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_PAGE_SELECTOR);
    pygobject_register_class(d, "GimpPathEditor", GIMP_TYPE_PATH_EDITOR, &PyGimpPathEditor_Type, Py_BuildValue("(O)", &PyGtkVBox_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_PATH_EDITOR);
    pygobject_register_class(d, "GimpPickButton", GIMP_TYPE_PICK_BUTTON, &PyGimpPickButton_Type, Py_BuildValue("(O)", &PyGtkButton_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_PICK_BUTTON);
    pygobject_register_class(d, "GimpPreview", GIMP_TYPE_PREVIEW, &PyGimpPreview_Type, Py_BuildValue("(O)", &PyGtkVBox_Type));
    pygobject_register_class(d, "GimpAspectPreview", GIMP_TYPE_ASPECT_PREVIEW, &PyGimpAspectPreview_Type, Py_BuildValue("(O)", &PyGimpPreview_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_ASPECT_PREVIEW);
    pygobject_register_class(d, "GimpPreviewArea", GIMP_TYPE_PREVIEW_AREA, &PyGimpPreviewArea_Type, Py_BuildValue("(O)", &PyGtkDrawingArea_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_PREVIEW_AREA);
    pygobject_register_class(d, "GimpProcBrowserDialog", GIMP_TYPE_PROC_BROWSER_DIALOG, &PyGimpProcBrowserDialog_Type, Py_BuildValue("(O)", &PyGimpDialog_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_PROC_BROWSER_DIALOG);
    pygobject_register_class(d, "GimpProgressBar", GIMP_TYPE_PROGRESS_BAR, &PyGimpProgressBar_Type, Py_BuildValue("(O)", &PyGtkProgressBar_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_PROGRESS_BAR);
    pygobject_register_class(d, "GimpScrolledPreview", GIMP_TYPE_SCROLLED_PREVIEW, &PyGimpScrolledPreview_Type, Py_BuildValue("(O)", &PyGimpPreview_Type));
    pygobject_register_class(d, "GimpDrawablePreview", GIMP_TYPE_DRAWABLE_PREVIEW, &PyGimpDrawablePreview_Type, Py_BuildValue("(O)", &PyGimpScrolledPreview_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_DRAWABLE_PREVIEW);
    pygobject_register_class(d, "GimpSelectButton", GIMP_TYPE_SELECT_BUTTON, &PyGimpSelectButton_Type, Py_BuildValue("(O)", &PyGtkHBox_Type));
    pygobject_register_class(d, "GimpPatternSelectButton", GIMP_TYPE_PATTERN_SELECT_BUTTON, &PyGimpPatternSelectButton_Type, Py_BuildValue("(O)", &PyGimpSelectButton_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_PATTERN_SELECT_BUTTON);
    pygobject_register_class(d, "GimpPaletteSelectButton", GIMP_TYPE_PALETTE_SELECT_BUTTON, &PyGimpPaletteSelectButton_Type, Py_BuildValue("(O)", &PyGimpSelectButton_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_PALETTE_SELECT_BUTTON);
    pygobject_register_class(d, "GimpGradientSelectButton", GIMP_TYPE_GRADIENT_SELECT_BUTTON, &PyGimpGradientSelectButton_Type, Py_BuildValue("(O)", &PyGimpSelectButton_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_GRADIENT_SELECT_BUTTON);
    pygobject_register_class(d, "GimpFontSelectButton", GIMP_TYPE_FONT_SELECT_BUTTON, &PyGimpFontSelectButton_Type, Py_BuildValue("(O)", &PyGimpSelectButton_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_FONT_SELECT_BUTTON);
    pygobject_register_class(d, "GimpBrushSelectButton", GIMP_TYPE_BRUSH_SELECT_BUTTON, &PyGimpBrushSelectButton_Type, Py_BuildValue("(O)", &PyGimpSelectButton_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_BRUSH_SELECT_BUTTON);
    pygobject_register_class(d, "GimpRuler", GIMP_TYPE_RULER, &PyGimpRuler_Type, Py_BuildValue("(O)", &PyGtkWidget_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_RULER);
    pygobject_register_class(d, "GimpSizeEntry", GIMP_TYPE_SIZE_ENTRY, &PyGimpSizeEntry_Type, Py_BuildValue("(O)", &PyGtkTable_Type));
    pygobject_register_class(d, "GimpStringComboBox", GIMP_TYPE_STRING_COMBO_BOX, &PyGimpStringComboBox_Type, Py_BuildValue("(O)", &PyGtkComboBox_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_STRING_COMBO_BOX);
    pygobject_register_class(d, "GimpUnitComboBox", GIMP_TYPE_UNIT_COMBO_BOX, &PyGimpUnitComboBox_Type, Py_BuildValue("(O)", &PyGtkComboBox_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_UNIT_COMBO_BOX);
    pygobject_register_class(d, "GimpUnitMenu", GIMP_TYPE_UNIT_MENU, &PyGimpUnitMenu_Type, Py_BuildValue("(O)", &PyGtkOptionMenu_Type));
    pygobject_register_class(d, "GimpVectorsComboBox", GIMP_TYPE_VECTORS_COMBO_BOX, &PyGimpVectorsComboBox_Type, Py_BuildValue("(O)", &PyGimpIntComboBox_Type));
    pygobject_register_class(d, "GimpZoomModel", GIMP_TYPE_ZOOM_MODEL, &PyGimpZoomModel_Type, Py_BuildValue("(O)", &PyGObject_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_ZOOM_MODEL);
    pygobject_register_class(d, "GimpZoomPreview", GIMP_TYPE_ZOOM_PREVIEW, &PyGimpZoomPreview_Type, Py_BuildValue("(O)", &PyGimpScrolledPreview_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_ZOOM_PREVIEW);
}
