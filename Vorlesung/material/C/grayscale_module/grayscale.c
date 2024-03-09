#include <Python.h>
/*Pull in the Python API. Note: You MUST include Python.h before any other standard headers.*/
/*"Python.h" includes a few standard header files: <stdio.h>, <string.h>, <errno.h>, and <stdlib.h>.*/

/* Grayscale Filter in C-Implementation
size: width*height of image
bytes: input image bytes in rgb format, will be overwritten*/
static void grayscale_filter(int size, unsigned char* bytes)
{
	for (int i =0; i < 3*size; i+=3)
	{
		unsigned char r = bytes[i];
		unsigned char g = bytes[i + 1];
		unsigned char b = bytes[i + 2];

		unsigned char avg = (r + g + b) / 3;

		bytes[i] = avg;
		bytes[i + 1] = avg;
		bytes[i + 2] = avg;
	}
}

/*Wrapper for our function*/
/*self points to the module object. */
/*args points to a Python tuple object containing the arguments.*/
PyObject* method_grayscale_filter(PyObject* self, PyObject* args)
{
    int size = 0;
    PyObject* python_bytes;

    /* 1. Parse arguments */
    /* https://docs.python.org/3/c-api/arg.html */
    if(!PyArg_ParseTuple(args, "iS", &size, &python_bytes))
    {
        return NULL; //NULL signals Error
    }

    unsigned char* bytes = PyBytes_AsString(python_bytes);

    /* 2. The Core Functionality */
    grayscale_filter(size, bytes);

    /* 3. Return correct Python type*/
    Py_RETURN_NONE;
}



/* Method Definitions
*********************
Array of PyMethod Definitions
PyMethodDef is a struct with four elements:
1. Name in Python
2. Implementing function
3. Flag (METH_VARARGS, METH_KEYWORDS, METH_NOARGS)
4. Docstring*/
static PyMethodDef grayscale_method_defs[] =
{
    {"grayscale", method_grayscale_filter, METH_VARARGS, "grayscale(size, bytes): Applies grayscale filter to bytes of an RGB-picture.\nsize: number of pixels\nbytes: Image bytes"},

    /*if we had more than one function: one struct for each function*/
    /*{...,...,...,...},*/

    {NULL, NULL, 0, NULL} /* Important: Sentinal value {NULL,NULL,0,NULL} marks end of the array*/
};

/* Module Definition
********************
A single struct that summarizes the whole module:
1. Flag PyModuleDef_HEAD_INIT
2. Module Name
3. Docstring
4. size of per-module (per-interpreter) state in bytes (-1: only one global state)
5. Method Definitions
*/
static struct PyModuleDef grayscale_module_def =
{
    PyModuleDef_HEAD_INIT,
    "grayscale_module",
    "Python-Interface to Grayscale Filter implemented in C",
    -1,
    grayscale_method_defs
};

/*Module Init Function:
- called once when the module is imported
- returns the module object with which we work in Python
Important: PyInit_MODULE_NAME */
PyMODINIT_FUNC PyInit_grayscale_module(void)
{
    return PyModule_Create(&grayscale_module_def);
}
