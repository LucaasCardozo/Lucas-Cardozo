#include <stdio.h>
#include <stdlib.h>
#include "arboles.h"
#define TAM 10

int main()
{
    ArbolP arboles[TAM];

    leerArbol(arboles);

    cargarArbolesVacio(arboles);

    agregarArbol(arboles, "Laurel", 210, 2.55);
    agregarArbol(arboles, "Secuoya Caucho", 150, 1.99);
    agregarArbol(arboles, "Gikgo biloba", 90, 1.88);

    mostrarArboles(arboles, TAM);

    modificarArbol(arboles, "Laurel");

    mostrarArboles(arboles, TAM);

    eliminarArbol(arboles, "Cocotero");
    eliminarArbol(arboles, "Falsa Acacia");

    printf("\n\n\n////////////////////////////////////////////////////////////\n");
    printf("\tELIMINAMOS 'COCOTERO' Y 'FALSA ACACIA'\n");
    printf("////////////////////////////////////////////////////////////\n");

    mostrarArboles(arboles, TAM);

    guardarArbol(arboles);

    return 0;
}
