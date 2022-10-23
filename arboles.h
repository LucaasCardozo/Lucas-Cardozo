#ifndef ARBOLES_H_INCLUDED
#define ARBOLES_H_INCLUDED

struct Arbol;

typedef struct Arbol * ArbolP;

void leerArbol (ArbolP a[]);

ArbolP transformarTextoAArbol(char d[100]);

void mostrarArbol (ArbolP a);

void mostrarArboles (ArbolP a[], int t);

ArbolP cargarArbolVacio ();

void cargarArbolesVacio(ArbolP a[]);

int buscarArbolVacio(ArbolP a[]);

void agregarArbol(ArbolP a[], char es[20], int ed, float al);

int busquedaPorNombre (ArbolP a[], char loQBusco[40]);

void modificarArbol(ArbolP a[], char nomAModificar[40]);

void eliminarArbol(ArbolP a[], char nomAEliminar[40]);

void guardarArbol (ArbolP a[]);

#endif // ARBOLES_H_INCLUDED
