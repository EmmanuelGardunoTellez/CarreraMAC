

#include "avl.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

Arbol * inicializarArbol(){
    Arbol * arbol = (Arbol *) malloc(sizeof(Arbol));
    arbol->raiz = NULL;
    return arbol;
}

Nodo * crearNodo(double x){
    Nodo * nodo = (Nodo *) malloc(sizeof(Nodo));
    nodo->dato = x;
    nodo->hi = NULL;
    nodo->hd = NULL;
    return nodo;
}

int altura(Nodo * raiz){
    if(raiz == NULL){
        return 0;
    } else{
        int altura_i, altura_d;
        altura_i = altura(raiz->hi);
        altura_d = altura(raiz->hd);
        if(altura_i > altura_d) return (1+altura_i);
        else return (1+altura_d);
    }
}

int altura_arbol(Arbol * arbol){
    return altura(arbol->raiz);
}

bool esBalanceado(Nodo * raiz){
    int altura_izq;
    int altura_der;
    
    // Si el arbol esta vacio se considera balanceado
    if(raiz == NULL) return true;
    
    altura_izq = altura(raiz->hi);
    altura_der = altura(raiz->hd);
    
    if(abs(altura_izq-altura_der) <= 1 && esBalanceado(raiz->hi) && esBalanceado(raiz->hd)) return true;
    
    return false;
}

bool es_balanceado_arbol(Arbol * arbol){
    return esBalanceado(arbol->raiz);
}

int factor_balance(Nodo * raiz){
    int fb = 0;
    
    if(raiz->hi) fb += altura(raiz->hi);
    if(raiz->hd) fb -= altura(raiz->hd);
    
    return fb;
}

// Caso Derecho-Derecho
// Rotacion a la izquierda
Nodo * rotacion_der_der(Nodo * raiz){
    Nodo * y = raiz;
    Nodo * x = y->hd;
    // Cambios
    y->hd = x->hi;
    x->hi = y;
    
    return x;
}

// Caso Izquierdo-Izquierdo
// Rotacion a la derecha
Nodo * rotacion_izq_izq(Nodo * raiz){
    Nodo * y = raiz;
    Nodo * x = y->hi;
    // Cambios
    y->hi = x->hd;
    x->hd = y;
    
    return x;
}

// Caso Izquierdo-Derecho
// Rotacion izquierda-derecha
Nodo * rotacion_izq_der(Nodo * raiz){
    Nodo * z = raiz;
    Nodo * y = z->hi;
    Nodo * x = y->hd;
    // Cambios
    y->hd = x->hi;
    z->hi = x->hd;
    x->hi = y;
    x->hd = z;
    
    return x;
}

// Caso Derecho-Izquierda
// Rotacion derecha izquierda
Nodo * rotacion_der_izq(Nodo * raiz){
    Nodo * z = raiz;
    Nodo * y = z->hd;
    Nodo * x = y->hi;
    // Cambios
    y->hi = x->hd;
    z->hd = x->hi;
    x->hi = z;
    x->hd = y;
    
    return x;
}

Nodo * insertar(Nodo * raiz, double x){
    if(raiz == NULL){
        raiz = crearNodo(x);
    } else if(x < raiz->dato){
        raiz->hi = insertar(raiz->hi, x);
    } else if(x > raiz->dato){
        raiz->hd = insertar(raiz->hd, x);
    }
    
    return raiz;
}

void insertar_en_arbol(Arbol * arbol, double x){
    arbol->raiz = insertar(arbol->raiz, x);
}

void preorden(Nodo * raiz){
    if(raiz != NULL){
        printf("%lf ", raiz->dato);
        preorden(raiz->hi);
        preorden(raiz->hd);
    }
}

void preorden_arbol(Arbol * arbol){
    preorden(arbol->raiz);
}

void inorden(Nodo * raiz){
    if(raiz != NULL){
        inorden(raiz->hi);
        printf("%lf ", raiz->dato);
        inorden(raiz->hd);
    }
}

void inorden_arbol(Arbol * arbol){
    inorden(arbol->raiz);
}

void postorden(Nodo * raiz){
    if(raiz != NULL){
        postorden(raiz->hi);
        postorden(raiz->hd);
        printf("%lf ", raiz->dato);
    }
}

void postorden_arbol(Arbol * arbol){
    postorden(arbol->raiz);
}

// Informacion Adicional a la Practica:

// Contar Nodos
int no_nodos(Nodo * enlace){
    if(enlace == NULL) return 0;
    else return (1 + no_nodos(enlace->hi) + no_nodos(enlace->hd));
}

int no_nodos_arbol(Arbol * bt){
    return no_nodos(bt->raiz);
}

// Contar Numero de Hojas
int no_hojas(Nodo * enlace){
    if(enlace == NULL) return 0;
    if(enlace->hi == NULL && enlace->hd == NULL) return 1;
    else return no_hojas(enlace->hi) + no_hojas(enlace->hd);
}

int no_hojas_arbol(Arbol * bt){
    int noHojas = no_hojas(bt->raiz);
    return noHojas;
}

// Contar Numero de Nodos Internos
int nodos_internos(Nodo * enlace){
    int cont = 0;
    if(enlace->hi != NULL || enlace->hd != NULL){
        cont = 1;
        if(enlace->hi != NULL){
            cont += nodos_internos(enlace->hi);
        }
        if(enlace->hd != NULL){
            cont += nodos_internos(enlace->hd);
        }
    }
    return cont;
}

int nodos_internos_arbol(Arbol * bt){
    int cont = 0;
    if(bt->raiz != NULL){
        cont = nodos_internos(bt->raiz);
    }
    return cont;
}

Nodo * valorMenor(Nodo * raiz){
    if(raiz == NULL) return raiz;
    else if(raiz->hi == NULL) return raiz;
    else return valorMenor(raiz->hi);
}

Nodo * borrar(Nodo * raiz, double x);

Nodo * borrar_nodo(Nodo * raiz){
    Nodo * temp;
    // Caso 1: El nodo no tiene hijos
    if((raiz->hi == NULL) && (raiz->hd == NULL)){
        free(raiz);
        return NULL;
    }
    // Caso 2a: El nodo solo tiene hijo derecho
    else if((raiz->hi == NULL) && (raiz->hd != NULL)){
        temp = raiz->hd;
        free(raiz);
        return temp;
    }
    // Caso 2b: El nodo solo tiene hijo izquierdo
    else if((raiz->hi != NULL) && (raiz->hd == NULL)){
        temp = raiz->hi;
        free(raiz);
        return temp;
    }
    // Caso 3: El nodo tiene sus dos hijos
    else{
        Nodo * sucesor = valorMenor(raiz->hd);
        int valorSucesivo = sucesor->dato;
        raiz = borrar(raiz, valorSucesivo);
        raiz->dato = valorSucesivo;
        return raiz;
    }
}

Nodo * borrar(Nodo * raiz, double x){
    if(raiz == NULL) return NULL;
    if(x == raiz->dato) raiz = borrar_nodo(raiz);
    if(x < raiz->dato) raiz->hi = borrar(raiz->hi, x);
    else raiz->hd = borrar(raiz->hd, x);
    return raiz;
}

void borrar_en_arbol(Arbol * arbol, double x){
    arbol->raiz = borrar(arbol->raiz, x);
}

