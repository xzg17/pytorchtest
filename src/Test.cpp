#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "Test.hpp"

typedef struct {
    
    PyObject_HEAD
    /* Type-specific fields go here. */
        Test_Class *test_class;
} Py_Test_Class;


static PyObject *test_func(Py_Test_Class *self);

static int *test_init(Py_Test_Class *self, PyObject *args);

static PyMethodDef Py_Class_Board_methods[] = {
    {"test", (PyCFunction)test_func, METH_VARARGS, "(ToT)"},
    {NULL} /* Sentinel */
};


static PyTypeObject CustomType = {
    PyVarObject_HEAD_INIT(NULL, 0) "custom.Custom", /* tp_name */
    sizeof(Py_Test_Class),                           /* tp_basicsize */
    0,                                              /* tp_itemsize */
    /* methods */
    0, /* tp_dealloc */
    0,                        /* tp_print */
    0,                        /* tp_getattr */
    0,                        /* tp_setattr */
    0,                        /* tp_reserved */
    0,                        /* tp_repr */
    0,                        /* tp_as_number */
    0,                        /* tp_as_sequence */
    0,                        /* tp_as_mapping */
    0,                        /* tp_hash */
    0,                        /* tp_call */
    (reprfunc)*Board_str,     /* tp_str */
    0,                        /* tp_getattro */
    0,                        /* tp_setattro */
    0,                        /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,       /* tp_flags */
    PyDoc_STR("Custom objects"),/* tp_doc */
    0,                        /* tp_traverse */
    0,                        /* tp_clear */
    0,                        /* tp_richcompare */
    0,                        /* tp_weaklistoffset */
    0,                        /* tp_iter */
    0,                        /* tp_iternext */
    Py_Class_Board_methods,     /* tp_methods */
    0,                        /* tp_members */
    0,                        /* tp_getset */
    0,                        /* tp_base */
    0,                        /* tp_dict */
    0,                        /* tp_descr_get */
    0,                        /* tp_descr_set */
    0,                        /* tp_dictoffset */
    (initproc)test_init,     /* tp_init */
    0,                        /* tp_alloc */
    PyType_GenericNew,        /* tp_new */
};

static PyObject *test_func(Py_Test_Class *self){
    return Py_BuildValue("i", self->test_class->num);
};

static int *test_init(Py_Test_Class *self, PyObject *args){
    int num;
    if (PyArg_ParseTuple(args, "i", &num)) {
        self->test_class = new Test_Class(num);        
    } else {
        PyErr_SetString(PyExc_ValueError, "Invalid arguments.");        
    }
    return 0;
};