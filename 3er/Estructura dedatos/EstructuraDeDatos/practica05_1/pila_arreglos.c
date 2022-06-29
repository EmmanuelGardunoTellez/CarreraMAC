#include <stdio.h>
#include <stdlib.h>

typedef struct pila{
    int tope;
    int capacidad;
    int * array;
} Pila;

Pila * crearPila(int capacidad){
    Pila * pila = (Pila*) malloc(sizeof(Pila));
    pila->capacidad = capacidad;
    pila->tope = -1;
    pila->array = (int *) malloc(pila->capacidad * sizeof(int));
    return pila;
}

int esLlena(Pila * pila){
    if(pila->tope == pila->capacidad-1){
        return 1;
    } else{
        return 0;
    }
}

int esVacia(Pila * pila){
    if(pila->tope == -1){
        return 1;
    } else{
        return 0;
    }
}

void push(Pila * pila, int dato){
    if(esLlena(pila) == 1) return;
    pila->array[++pila->tope] = dato;
    printf("\nIngreso a la pila el valor: %d", dato);
}

int pop(Pila * pila){
    if(esVacia(pila) == 1) return 999999;
     printf("\nSalio de la pila el valor: %d", pila->array[pila->tope]);
    return pila->array[pila->tope--];
}

int peek(Pila * pila){
    if(esVacia(pila) == 1) return -999999;
    return pila->array[pila->tope];
}

void desplegar(Pila * pila){
    int i=0;
    for(i=0; i<=pila->tope; i++){
        printf("%d ", pila->array[i]);
    }
}

int main(int argc, const char * argv[]) {
    Pila * pila1 = crearPila(40);
    Pila * pila2 = crearPila(20);
    
    push(pila1, 2);
    push(pila1, 6);
    push(pila1, -3);
    push(pila1, 9);
    push(pila1, -12);
    
    push(pila2, 14);
    push(pila2, 23);
    push(pila2, -92);
    push(pila2, 64);
    push(pila2, -120);
    push(pila2, 34);
    push(pila2, -7);
    push(pila2, -456);
    
    printf("\nContenido Pila 1: \n");
    desplegar(pila1);
    printf("\n\nContenido Pila 2: \n");
    desplegar(pila2);
    
    int a = pop(pila1);
    if(a == 999999) printf("Pila Llena");
    int b = pop(pila1);
    if(b == 999999) printf("Pila Llena");
    
    printf("\nContenido Pila 1: \n");
    desplegar(pila1);
    
    return 0;
}
