#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int dato;
    struct nodo * siguiente;
} Nodo;

Nodo * nuevoNodo(int dato){
    Nodo * nuevo = (Nodo*) malloc(sizeof(Nodo));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    return nuevo;
}

int esVacia(Nodo * cabecera){
    if(cabecera == NULL){
        return 1;
    } else{
        return 0;
    }
}

void push(Nodo * cabecera, int dato){
    Nodo * nuevo = nuevoNodo(dato);
    nuevo->siguiente = cabecera;
    cabecera = nuevo;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
