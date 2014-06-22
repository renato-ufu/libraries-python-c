#include "include.h"

PyObject* some_function(PyObject *self, PyObject *args)
{
	int i;
	if (!PyArg_ParseTuple(args, "i", &i))
	{
		goto error;
	}
	return PyInt_FromLong(i+1);
error:
	return 0;
}


PyMethodDef MylibMethods[] =
{
	{"add_one", (PyCFunction)some_function, METH_VARARGS, 0},
	{0,0,0,0}
};

PyMODINIT_FUNC
initmylib(void)
{
    PyObject *m;

    m = Py_InitModule("mylib", MylibMethods);
    if (m == NULL)
        return;
}
