#include <Python.h>
#include <ctype.h>

void encrypt(char* plain, int len, int key, char* result)
{
    // Encrypt each character in the message
    for (int i = 0; i < len; i++)
    {
        char c = plain[i];

        if (isalpha(c) && c <=127)
        {
            char base = islower(c) ? 'a' : 'A';
            result[i] = (c - base + key) % 26 + base;
        }
        else
        {
            result[i] = c;  // Non-alphabetic characters remain unchanged
        }
    }
}

void decrypt(char* ciphertext, int len, int key, char* result)
{
    // Decrypt each character in the ciphertext
    for (int i = 0; i < len; i++)
    {
        char c = ciphertext[i];

        if (isalpha(c))
        {
            char base = islower(c) ? 'a' : 'A';
            result[i] = (c - base - key + 26) % 26 + base;
        }
        else
        {
            result[i] = c;  // Non-alphabetic characters remain unchanged
        }
    }
}

static PyObject* caesar_encrypt(PyObject* self, PyObject* args)
{
    char* plain_text;
    int key;

    //TASK 1
    //Ersetzen Sie XX im Aufruf von PyArg_ParseTuple durch das korrekte Format für Argumente vom Typ String und int.
    //Hinweis: https://docs.python.org/3/c-api/arg.html
    if (!PyArg_ParseTuple(args, "XX", &plain_text,&key))
    {
        return NULL;
    }

    int len = (int)strlen(plain_text);

    char* encrypted = malloc(len+1);

    encrypt(plain_text, len, key, encrypted);

    encrypted[len] ='\0';

    //Task 2
    //Ersetzen Sie X im Aufruf von Py_BuildValue durch das korrekte Format
    //Hinweis: Verwenden Sie erneut die Dokumentation
    PyObject* result = Py_BuildValue("X",encrypted);

    free(encrypted); //Zusatzfrage: Warum können und sollen wir den Speicher an dieser Stelle freigeben?

    return result;
}

//
//Task 3
//Führen Sie die Tasks 1 und 2 auch für die folgende decrypt-Funktion aus.
//
static PyObject* caesar_decrypt(PyObject * self, PyObject* args)
{
    char* encrypted_text;
    int key;

    if (!PyArg_ParseTuple(args, "XX", &encrypted_text, &key))
    {
        return NULL;
    }

    int len = (int)strlen(encrypted_text);

    char* decrypted = malloc(len+1);

    decrypt(encrypted_text, len, key, decrypted);

    decrypted[len] ='\0';
    PyObject* result = Py_BuildValue("X",decrypted);

    free(decrypted);

    return result;
}

//
//Task 4
//Füllen Sie die Method Definitions für die beiden Funktionen encrypt und decrypt aus
//
static PyMethodDef caesar_method_defs[]=
{
    {"encrypt", ... },
    {"decrypt", ... },
    {NULL, NULL, 0, NULL} //Zusatzfrage: Erinnern Sie sich an die Bedeutung dieses Eintrags?
};
//
//Task 5
//Füllen Sie die Module Definition aus. Das Modul soll "caesar_module" heißen.
//
static PyModuleDef caesar_module_def =
{
 //...
};

//Zusatzfrage: Erinnern Sie sich an die Bedeutung der folgenden Init Function?
PyMODINIT_FUNC PyInit_caesar_module(void)
{
    return PyModule_Create(&caesar_module_def);
}
//
//Task 6: Installieren Sie das Modul, indem Sie "pip install ./" im Quellcodeverzeichnis aufrufen. Testen Sie es in Jupyter Notebooks.
//
// End of File
