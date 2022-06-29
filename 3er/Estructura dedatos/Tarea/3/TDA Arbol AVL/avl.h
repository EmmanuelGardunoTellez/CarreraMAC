//Alan Fernando Díaz López

#ifndef avl_h
#define avl_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nodo{
    double dato;
    struct nodo * hi;
    struct nodo * hd;
} Nodo;

typedef struct arbol{
    Nodo * raiz;
} Arbol;

Arbol * inicializarArbol();
Nodo * crearNodo(double);
int altura(Nodo *);
int altura_arbol(Arbol *);
bool esBalanceado(Nodo *);
bool es_balanceado_arbol(Arbol *);
int factor_balance(Nodo *);
Nodo * rotacion_der_der(Nodo *);
Nodo * rotacion_izq_izq(Nodo *);
Nodo * rotacion_izq_der(Nodo *);
Nodo * rotacion_der_izq(Nodo *);
Nodo * insertar(Nodo *, double);
void insertar_en_arbol(Arbol *, double);
void preorden(Nodo *);
void preorden_arbol(Arbol *);
void inorden(Nodo *);
void inorden_arbol(Arbol *);
void postorden(Nodo *);
void postorden_arbol(Arbol *);
int no_nodos(Nodo *);
int no_nodos_arbol(Arbol *);
int no_hojas(Nodo *);
int no_hojas_arbol(Arbol *);
int nodos_internos(Nodo *);
int nodos_internos_arbol(Arbol *);
Nodo * valorMenor(Nodo *);
Nodo * borrar(Nodo *, double);
Nodo * borrar_nodo(Nodo *);
Nodo * borrar(Nodo *, double);
void borrar_en_arbol(Arbol *, double);

#endif
