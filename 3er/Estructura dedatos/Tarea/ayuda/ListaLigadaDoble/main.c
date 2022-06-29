//
//  main.c
//  LigadasDobles
//
//  Created by Jonathan Cordoba Luna on 10/17/19.
//  Copyright © 2019 Jonathan Cordoba Luna. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct nodo{
    int dato;
    struct nodo * siguiente;
    struct nodo * anterior;
} Nodo;

typedef struct lista{
    Nodo * cabecera;
    Nodo * final;
} ListaDoble;

//Nodo * cabecera = NULL, * final = NULL;

Nodo * crearNodo(int dato){
    Nodo * nuevo = (Nodo *) malloc(sizeof(Nodo));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;
    return nuevo;
}

ListaDoble * inicializarLista(){
    ListaDoble * lista = (ListaDoble *) malloc(sizeof(ListaDoble));
    lista->cabecera = NULL;
    lista->final = NULL;
    return lista;
}

void insertar_frente(ListaDoble * ld, int dato){
    Nodo * nuevo = crearNodo(dato);
    if(!nuevo){
        return;
    } else{
        if(ld->cabecera == NULL && ld->final == NULL){
            ld->cabecera = ld->final = nuevo;
        } else{
            nuevo->siguiente = ld->cabecera;
            ld->cabecera->anterior = nuevo;
            ld->cabecera = nuevo;
        }
    }
}

void insertar_final(ListaDoble * ld, int dato){
    Nodo * nuevo = crearNodo(dato);
    if(!nuevo){
        return;
    } else{
        if(ld->cabecera == NULL && ld->final == NULL){
            ld->cabecera = ld->final = nuevo;
        } else{
            nuevo->anterior = ld->final;
            ld->final->siguiente = nuevo;
            ld->final = nuevo;
        }
    }
}

void borrar_frente(ListaDoble * ld){
    if(ld->cabecera == NULL && ld->final == NULL){
        printf("\nLista Vacia");
    } else{
        Nodo * temp = ld->cabecera;
        if(ld->cabecera == ld->final){
            ld->cabecera = ld->final = NULL;
        } else{
            ld->cabecera = ld->cabecera->siguiente;
            ld->cabecera->anterior = NULL;
        }
        free(temp);
    }
}

void borrar_final(ListaDoble * ld){
    if(ld->cabecera == NULL && ld->final == NULL){
        printf("\nLista Vacia");
    } else{
        Nodo * temp = ld->final;
        if(ld->cabecera == ld->final){
            ld->cabecera = ld->final = NULL;
        } else{
            ld->final = ld->final->anterior;
            ld->final->siguiente = NULL;
        }
        free(temp);
    }
}

void desplegar(ListaDoble * ld){
    if(ld->cabecera == NULL && ld->final == NULL){
        printf("\nLista vacia");
    } else{
        Nodo * temp = ld->cabecera;
        while (temp != NULL) {
            printf("%d->", temp->dato);
            temp = temp->siguiente;
        }
        printf("NULL\n");
    }
}

void desplegar_inverso(ListaDoble * ld){
    if(ld->final == NULL && ld->cabecera == NULL){
        printf("\nLista vacia");
    } else{
        Nodo * temp = ld->final;
        while (temp != NULL) {
            printf("%d->", temp->dato);
            temp = temp->anterior;
        }
        printf("NULL");
    }
}


int main(int argc, const char * argv[]) {
    
    ListaDoble * ld = inicializarLista();
    
    insertar_frente(ld, 14);
    insertar_frente(ld, 22);
    insertar_final(ld, 91);
    insertar_final(ld, 73);
    insertar_final(ld, 41);
    insertar_final(ld, 93);
    insertar_final(ld, -17);
    insertar_final(ld, 5);
    desplegar(ld);
    printf("\n");
    desplegar_inverso(ld);
    printf("\n\n");
    
    borrar_frente(ld);
    borrar_final(ld);
    
    desplegar(ld);
    printf("\n");
    desplegar_inverso(ld);
    printf("\n\n");
        
    return 0;
}
