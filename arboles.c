#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arboles.h"
#define TAM 10

struct Arbol{

    char especie[40];
    int edad;
    float altura;

};

void leerArbol (ArbolP a[]){

    FILE * archivo = fopen("arboles.txt", "r");

    int i = 0;

    while(!feof(archivo)){
        char datos[100] = "";
        fgets(datos, 100, archivo);

        a[i] = transformarTextoAArbol(datos);
        i++;

    }

    fclose(archivo);

}

ArbolP transformarTextoAArbol(char d[100]){

    ArbolP a = malloc(sizeof(struct Arbol));

    int poscPrimerDelimitador = -1;

    for (int i=0; i<100; i++){
        if (d[i] == '+'){
            poscPrimerDelimitador = i;
            i = 200;
        }
    }

    int poscSegundoDelimitador = -1;

    for (int i=poscPrimerDelimitador+1; i<100; i++){
        if (d[i] == '+'){
            poscSegundoDelimitador = i;
            i = 200;
        }
    }

    char especieAux[40] = "";
    char edadAux[4] = "";
    char alturaAux[5] = "";

    for (int i=0; i<poscPrimerDelimitador; i++){
        especieAux[i] = d[i];
    }

    for (int i=poscPrimerDelimitador+1; i<poscSegundoDelimitador; i++){
        edadAux[i-poscPrimerDelimitador-1] = d[i];
    }

    for (int i=poscSegundoDelimitador+1; i<strlen(d)-1; i++){
        alturaAux[i-poscSegundoDelimitador-1] = d[i];
    }

    strcpy(a->especie, especieAux);
    a->edad = atoi(edadAux);
    a->altura = atof(alturaAux);

    return a;

}

void mostrarArbol (ArbolP a){

    printf("\nEspecie: %s\nEdad: %d\nAltura: %.2f\n", a->especie, a->edad, a->altura);

}

void mostrarArboles (ArbolP a[], int t){

    for (int i=0; i<t; i++){
        if (a[i]->edad != -1){
        mostrarArbol(a[i]);
        printf("\n---------------------\n");
        }
    }

}

ArbolP cargarArbolVacio (){

    ArbolP a = malloc(sizeof(struct Arbol));

        strcpy(a->especie, "VACIO");
        a->edad = -1;
        a->altura = -1.00;

    return a;

}

void cargarArbolesVacio(ArbolP a[]){

    for (int i=3; i<TAM; i++){
        a[i] = cargarArbolVacio();
    }

}

int buscarArbolVacio(ArbolP a[]){

    int poscVacio = -1;

    for (int i=0; i<TAM; i++){
        if (a[i]->edad == -1){
            poscVacio = i;
            i = TAM+1;
        }
    }

    return poscVacio;

}

void agregarArbol(ArbolP a[], char es[40], int ed, float al){

    int poscVacio = buscarArbolVacio(a);

    if(poscVacio != -1){
    strcpy(a[poscVacio]->especie, es);
    a[poscVacio]->edad = ed;
    a[poscVacio]->altura = al;
    }

}

int busquedaPorNombre (ArbolP a[], char loQBusco[40]){

    int posc = -1;

    for (int i=0; i<TAM; i++){
        int comparacion = strcmp(a[i]->especie, loQBusco);
        if (comparacion == 0){
            posc = i;
            i = TAM+1;
        }
    }

    return posc;

}

void modificarArbol(ArbolP a[], char nomAModificar[40]){

    int poscAModificar = busquedaPorNombre(a, nomAModificar);

    if (poscAModificar != -1){
    printf("\nPor favor ingrese la nueva edad de %s\n", nomAModificar);
    scanf("%d", &(a[poscAModificar]->edad));

    printf("\nPor favor ingrese la nueva altura de %s\n", nomAModificar);
    scanf("%f", &(a[poscAModificar]->altura));
    }

}

void eliminarArbol(ArbolP a[], char nomAEliminar[40]){

    int poscAEliminar = busquedaPorNombre(a, nomAEliminar);

    if (poscAEliminar != -1){
        strcpy(a[poscAEliminar]->especie, "NADIE");
        a[poscAEliminar]->edad = -1;
        a[poscAEliminar]->altura = -1.00;
    }

}

void guardarArbol (ArbolP a[]){

    FILE * archivo = fopen("arboles.txt", "w");

    for (int i=0; i<TAM; i++){
        if (a[i]->edad != -1)
        fprintf(archivo, "%s+%d+%.2f\n", a[i]->especie, a[i]->edad, a[i]->altura);
    }
    fclose(archivo);
}

