/* -- THIS FILE IS GENERATED - DO NOT EDIT *//* -*- Mode: C; c-basic-offset: 4 -*- */

#include <Python.h>



#line 3 "gimpthumb.override"
#include <Python.h>

#define NO_IMPORT_PYGOBJECT
#include <pygobject.h>

#include <gdk-pixbuf/gdk-pixbuf.h>

#include <libgimpthumb/gimpthumb.h>

/* TODO: Add a header for these */
void gimpthumb_register_classes(PyObject *d);
void gimpthumb_add_constants(PyObject *module, const gchar *strip_prefix);
#line 21 "gimpthumb.c"


/* ---------- types from other modules ---------- */
static PyTypeObject *_PyGObject_Type;
#define PyGObject_Type (*_PyGObject_Type)
static PyTypeObject *_PyGdkPixbuf_Type;
#define PyGdkPixbuf_Type (*_PyGdkPixbuf_Type)


/* ---------- forward type declarations ---------- */
PyTypeObject G_GNUC_INTERNAL PyGimpThumbnail_Type;

#line 34 "gimpthumb.c"



/* ----------- GimpThumbnail ----------- */

static int
_wrap_gimp_thumbnail_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char* kwlist[] = { NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     ":gimpthumb.Thumbnail.__init__",
                                     kwlist))
        return -1;

    pygobject_constructv(self, 0, NULL);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create gimpthumb.Thumbnail object");
        return -1;
    }
    return 0;
}

static PyObject *
_wrap_gimp_thumbnail_set_uri(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "uri", NULL };
    char *uri;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:Gimp.Thumbnail.set_uri", kwlist, &uri))
        return NULL;
    
    gimp_thumbnail_set_uri(GIMP_THUMBNAIL(self->obj), uri);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_thumbnail_set_filename(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "filename", NULL };
    char *filename;
    int ret;
    GError *error = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:Gimp.Thumbnail.set_filename", kwlist, &filename))
        return NULL;
    
    ret = gimp_thumbnail_set_filename(GIMP_THUMBNAIL(self->obj), filename, &error);
    
    if (pyg_error_check(&error))
        return NULL;
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_gimp_thumbnail_set_from_thumb(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "filename", NULL };
    char *filename;
    int ret;
    GError *error = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:Gimp.Thumbnail.set_from_thumb", kwlist, &filename))
        return NULL;
    
    ret = gimp_thumbnail_set_from_thumb(GIMP_THUMBNAIL(self->obj), filename, &error);
    
    if (pyg_error_check(&error))
        return NULL;
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_gimp_thumbnail_peek_image(PyGObject *self)
{
    gint ret;

    
    ret = gimp_thumbnail_peek_image(GIMP_THUMBNAIL(self->obj));
    
    return pyg_enum_from_gtype(GIMP_TYPE_THUMB_STATE, ret);
}

static PyObject *
_wrap_gimp_thumbnail_peek_thumb(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "size", NULL };
    PyObject *py_size = NULL;
    gint ret;
    GimpThumbSize size;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:Gimp.Thumbnail.peek_thumb", kwlist, &py_size))
        return NULL;
    if (pyg_enum_get_value(GIMP_TYPE_THUMB_SIZE, py_size, (gpointer)&size))
        return NULL;
    
    ret = gimp_thumbnail_peek_thumb(GIMP_THUMBNAIL(self->obj), size);
    
    return pyg_enum_from_gtype(GIMP_TYPE_THUMB_STATE, ret);
}

static PyObject *
_wrap_gimp_thumbnail_check_thumb(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "size", NULL };
    PyObject *py_size = NULL;
    gint ret;
    GimpThumbSize size;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:Gimp.Thumbnail.check_thumb", kwlist, &py_size))
        return NULL;
    if (pyg_enum_get_value(GIMP_TYPE_THUMB_SIZE, py_size, (gpointer)&size))
        return NULL;
    
    ret = gimp_thumbnail_check_thumb(GIMP_THUMBNAIL(self->obj), size);
    
    return pyg_enum_from_gtype(GIMP_TYPE_THUMB_STATE, ret);
}

static PyObject *
_wrap_gimp_thumbnail_load_thumb(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "size", NULL };
    PyObject *py_size = NULL;
    GdkPixbuf *ret;
    GError *error = NULL;
    GimpThumbSize size;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:Gimp.Thumbnail.load_thumb", kwlist, &py_size))
        return NULL;
    if (pyg_enum_get_value(GIMP_TYPE_THUMB_SIZE, py_size, (gpointer)&size))
        return NULL;
    
    ret = gimp_thumbnail_load_thumb(GIMP_THUMBNAIL(self->obj), size, &error);
    
    if (pyg_error_check(&error))
        return NULL;
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_gimp_thumbnail_save_thumb(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "pixbuf", "software", NULL };
    PyGObject *pixbuf;
    char *software;
    int ret;
    GError *error = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!s:Gimp.Thumbnail.save_thumb", kwlist, &PyGdkPixbuf_Type, &pixbuf, &software))
        return NULL;
    
    ret = gimp_thumbnail_save_thumb(GIMP_THUMBNAIL(self->obj), GDK_PIXBUF(pixbuf->obj), software, &error);
    
    if (pyg_error_check(&error))
        return NULL;
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_gimp_thumbnail_save_thumb_local(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "pixbuf", "software", NULL };
    PyGObject *pixbuf;
    char *software;
    int ret;
    GError *error = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!s:Gimp.Thumbnail.save_thumb_local", kwlist, &PyGdkPixbuf_Type, &pixbuf, &software))
        return NULL;
    
    ret = gimp_thumbnail_save_thumb_local(GIMP_THUMBNAIL(self->obj), GDK_PIXBUF(pixbuf->obj), software, &error);
    
    if (pyg_error_check(&error))
        return NULL;
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_gimp_thumbnail_save_failure(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "software", NULL };
    char *software;
    int ret;
    GError *error = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:Gimp.Thumbnail.save_failure", kwlist, &software))
        return NULL;
    
    ret = gimp_thumbnail_save_failure(GIMP_THUMBNAIL(self->obj), software, &error);
    
    if (pyg_error_check(&error))
        return NULL;
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_gimp_thumbnail_delete_failure(PyGObject *self)
{
    
    gimp_thumbnail_delete_failure(GIMP_THUMBNAIL(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_thumbnail_delete_others(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "size", NULL };
    PyObject *py_size = NULL;
    GimpThumbSize size;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:Gimp.Thumbnail.delete_others", kwlist, &py_size))
        return NULL;
    if (pyg_enum_get_value(GIMP_TYPE_THUMB_SIZE, py_size, (gpointer)&size))
        return NULL;
    
    gimp_thumbnail_delete_others(GIMP_THUMBNAIL(self->obj), size);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_thumbnail_has_failed(PyGObject *self)
{
    int ret;

    
    ret = gimp_thumbnail_has_failed(GIMP_THUMBNAIL(self->obj));
    
    return PyBool_FromLong(ret);

}

static const PyMethodDef _PyGimpThumbnail_methods[] = {
    { "set_uri", (PyCFunction)_wrap_gimp_thumbnail_set_uri, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_filename", (PyCFunction)_wrap_gimp_thumbnail_set_filename, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_from_thumb", (PyCFunction)_wrap_gimp_thumbnail_set_from_thumb, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "peek_image", (PyCFunction)_wrap_gimp_thumbnail_peek_image, METH_NOARGS,
      NULL },
    { "peek_thumb", (PyCFunction)_wrap_gimp_thumbnail_peek_thumb, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "check_thumb", (PyCFunction)_wrap_gimp_thumbnail_check_thumb, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "load_thumb", (PyCFunction)_wrap_gimp_thumbnail_load_thumb, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "save_thumb", (PyCFunction)_wrap_gimp_thumbnail_save_thumb, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "save_thumb_local", (PyCFunction)_wrap_gimp_thumbnail_save_thumb_local, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "save_failure", (PyCFunction)_wrap_gimp_thumbnail_save_failure, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "delete_failure", (PyCFunction)_wrap_gimp_thumbnail_delete_failure, METH_NOARGS,
      NULL },
    { "delete_others", (PyCFunction)_wrap_gimp_thumbnail_delete_others, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "has_failed", (PyCFunction)_wrap_gimp_thumbnail_has_failed, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyGimpThumbnail_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "gimpthumb.Thumbnail",                   /* tp_name */
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
    (struct PyMethodDef*)_PyGimpThumbnail_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_gimp_thumbnail_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- functions ----------- */

#line 25 "gimpthumb.override"
static PyObject *
_wrap_gimp_thumb_init(PyObject *self, PyObject *args, PyObject *kwargs)
{
    char *creator, *thumb_basedir = NULL;

    static char *kwlist[] = { "creator", "thumb_basedir", NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     "s|z:init", kwlist,
                                     &creator, &thumb_basedir))
        return NULL;

    return PyBool_FromLong(gimp_thumb_init(creator, thumb_basedir));
}
#line 375 "gimpthumb.c"


#line 41 "gimpthumb.override"
static PyObject *
_wrap_gimp_thumb_find_thumb(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    gchar *uri, *ret;
    PyObject *py_size, *py_ret;
    GimpThumbSize size;

    static char *kwlist[] = { "uri", NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "sO:find_thumb", kwlist,
                                     &uri, &py_size))
        return NULL;

    if (pyg_enum_get_value(GIMP_TYPE_THUMB_SIZE, py_size, (gint *)&size))
        return NULL;

    ret = gimp_thumb_find_thumb(uri, &size);

    if (ret == NULL) {
        Py_INCREF(Py_None);
        return Py_None;
    }

    py_ret = Py_BuildValue("sN", ret,
                           pyg_enum_from_gtype(GIMP_TYPE_THUMB_SIZE, size));
    g_free(ret);
    return py_ret;
}
#line 407 "gimpthumb.c"


#line 71 "gimpthumb.override"
static PyObject *
_wrap_gimp_thumb_file_test(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    gchar *filename;
    GimpThumbFileType ret;
    gint64 mtime, size;
    gint err_no;

    static char *kwlist[] = { "filename", NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "s:file_test", kwlist,
                                     &filename))
        return NULL;

    ret = gimp_thumb_file_test(filename, &mtime, &size, &err_no);

    if (ret == GIMP_THUMB_FILE_TYPE_NONE) {
        PyObject *v = Py_BuildValue("iss",
                                    err_no, g_strerror(err_no), filename); 
        if (v != NULL) {
            PyErr_SetObject(PyExc_IOError, v);
            Py_DECREF(v);
        }

        return NULL;
    }

    return Py_BuildValue("NNN", 
                         pyg_enum_from_gtype(GIMP_TYPE_THUMB_FILE_TYPE, ret),
                         PyLong_FromLongLong(mtime),
                         PyLong_FromLongLong(size));
}
#line 443 "gimpthumb.c"


static PyObject *
_wrap_gimp_thumb_name_from_uri(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "uri", "size", NULL };
    char *uri;
    PyObject *py_size = NULL;
    gchar *ret;
    GimpThumbSize size;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"sO:name_from_uri", kwlist, &uri, &py_size))
        return NULL;
    if (pyg_enum_get_value(GIMP_TYPE_THUMB_SIZE, py_size, (gpointer)&size))
        return NULL;
    
    ret = gimp_thumb_name_from_uri(uri, size);
    
    if (ret) {
        PyObject *py_ret = PyString_FromString(ret);
        g_free(ret);
        return py_ret;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_thumb_get_thumb_dir(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "size", NULL };
    PyObject *py_size = NULL;
    const gchar *ret;
    GimpThumbSize size;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:get_thumb_dir", kwlist, &py_size))
        return NULL;
    if (pyg_enum_get_value(GIMP_TYPE_THUMB_SIZE, py_size, (gpointer)&size))
        return NULL;
    
    ret = gimp_thumb_get_thumb_dir(size);
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_thumb_ensure_thumb_dir(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "size", NULL };
    PyObject *py_size = NULL;
    int ret;
    GError *error = NULL;
    GimpThumbSize size;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:ensure_thumb_dir", kwlist, &py_size))
        return NULL;
    if (pyg_enum_get_value(GIMP_TYPE_THUMB_SIZE, py_size, (gpointer)&size))
        return NULL;
    
    ret = gimp_thumb_ensure_thumb_dir(size, &error);
    
    if (pyg_error_check(&error))
        return NULL;
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_gimp_thumbs_delete_for_uri(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "uri", NULL };
    char *uri;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:delete_for_uri", kwlist, &uri))
        return NULL;
    
    gimp_thumbs_delete_for_uri(uri);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_thumb_name_from_uri_local(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "uri", "size", NULL };
    char *uri;
    PyObject *py_size = NULL;
    gchar *ret;
    GimpThumbSize size;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"sO:name_from_uri_local", kwlist, &uri, &py_size))
        return NULL;
    if (pyg_enum_get_value(GIMP_TYPE_THUMB_SIZE, py_size, (gpointer)&size))
        return NULL;
    
    ret = gimp_thumb_name_from_uri_local(uri, size);
    
    if (ret) {
        PyObject *py_ret = PyString_FromString(ret);
        g_free(ret);
        return py_ret;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_thumb_get_thumb_dir_local(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "dirname", "size", NULL };
    char *dirname;
    PyObject *py_size = NULL;
    gchar *ret;
    GimpThumbSize size;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"sO:get_thumb_dir_local", kwlist, &dirname, &py_size))
        return NULL;
    if (pyg_enum_get_value(GIMP_TYPE_THUMB_SIZE, py_size, (gpointer)&size))
        return NULL;
    
    ret = gimp_thumb_get_thumb_dir_local(dirname, size);
    
    if (ret) {
        PyObject *py_ret = PyString_FromString(ret);
        g_free(ret);
        return py_ret;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_gimp_thumb_ensure_thumb_dir_local(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "dirname", "size", NULL };
    char *dirname;
    PyObject *py_size = NULL;
    int ret;
    GError *error = NULL;
    GimpThumbSize size;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"sO:ensure_thumb_dir_local", kwlist, &dirname, &py_size))
        return NULL;
    if (pyg_enum_get_value(GIMP_TYPE_THUMB_SIZE, py_size, (gpointer)&size))
        return NULL;
    
    ret = gimp_thumb_ensure_thumb_dir_local(dirname, size, &error);
    
    if (pyg_error_check(&error))
        return NULL;
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_gimp_thumbs_delete_for_uri_local(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "uri", NULL };
    char *uri;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:delete_for_uri_local", kwlist, &uri))
        return NULL;
    
    gimp_thumbs_delete_for_uri_local(uri);
    
    Py_INCREF(Py_None);
    return Py_None;
}

const PyMethodDef gimpthumb_functions[] = {
    { "init", (PyCFunction)_wrap_gimp_thumb_init, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "find_thumb", (PyCFunction)_wrap_gimp_thumb_find_thumb, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "file_test", (PyCFunction)_wrap_gimp_thumb_file_test, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "name_from_uri", (PyCFunction)_wrap_gimp_thumb_name_from_uri, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_thumb_dir", (PyCFunction)_wrap_gimp_thumb_get_thumb_dir, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "ensure_thumb_dir", (PyCFunction)_wrap_gimp_thumb_ensure_thumb_dir, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "delete_for_uri", (PyCFunction)_wrap_gimp_thumbs_delete_for_uri, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "name_from_uri_local", (PyCFunction)_wrap_gimp_thumb_name_from_uri_local, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_thumb_dir_local", (PyCFunction)_wrap_gimp_thumb_get_thumb_dir_local, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "ensure_thumb_dir_local", (PyCFunction)_wrap_gimp_thumb_ensure_thumb_dir_local, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "delete_for_uri_local", (PyCFunction)_wrap_gimp_thumbs_delete_for_uri_local, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};


/* ----------- enums and flags ----------- */

void
gimpthumb_add_constants(PyObject *module, const gchar *strip_prefix)
{
#ifdef VERSION
    PyModule_AddStringConstant(module, "__version__", VERSION);
#endif
  pyg_enum_add(module, "ThumbFileType", strip_prefix, GIMP_TYPE_THUMB_FILE_TYPE);
  pyg_enum_add(module, "ThumbSize", strip_prefix, GIMP_TYPE_THUMB_SIZE);
  pyg_enum_add(module, "ThumbState", strip_prefix, GIMP_TYPE_THUMB_STATE);

  if (PyErr_Occurred())
    PyErr_Print();
}

/* initialise stuff extension classes */
void
gimpthumb_register_classes(PyObject *d)
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


#line 692 "gimpthumb.c"
    pygobject_register_class(d, "GimpThumbnail", GIMP_TYPE_THUMBNAIL, &PyGimpThumbnail_Type, Py_BuildValue("(O)", &PyGObject_Type));
    pyg_set_object_has_new_constructor(GIMP_TYPE_THUMBNAIL);
}
