//
//  lista.c
//  Practica04
//
//  Created by Jonathan Cordoba Luna on 9/13/19.
//  Copyright © 2019 Jonathan Cordoba Luna. All rights reserved.
//

#include "lista.h"
#include <stdlib.h>

Nodo * crearNodo(int dato){
    Nodo * nuevo = (Nodo*) malloc(sizeof(Nodo));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    return nuevo;
}

Nodo * insertar_frente(Nodo * cabecera, int elemento){
    Nodo * nuevo;
    nuevo = crearNodo(elemento);
    if(cabecera == NULL){
        cabecera = nuevo;
        nuevo->siguiente = cabecera;
    } else{
        Nodo * temp = cabecera;
        while(temp->siguiente != cabecera){
            temp = temp->siguiente;
        }
        nuevo->siguiente = cabecera;
        cabecera = nuevo;
        temp->siguiente = cabecera;
    }

    return cabecera;
}

Nodo * insertar_final(Nodo * cabecera, int elemento){
    Nodo * nuevo;
    nuevo = crearNodo(elemento);
    if(cabecera == NULL){
        cabecera = nuevo;
        nuevo->siguiente = cabecera;
    } else{
        Nodo * temp = cabecera;
        while(temp->siguiente != cabecera){
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
        nuevo->siguiente = cabecera;
    }
    return cabecera;
}

Nodo * borrar_frente(Nodo * cabecera){
    if(cabecera == NULL){
        printf("Lista Vacia\n");
        return NULL;
    } else{
        Nodo * temp = cabecera;
        Nodo * aux = cabecera;
        while(temp->siguiente != cabecera){
            temp = temp->siguiente;
        }
        
        if(temp->siguiente == temp){
            cabecera = NULL;
        } else{
            cabecera = cabecera->siguiente;
            temp->siguiente = cabecera;
            free(aux);
        }
        
        return cabecera;
    }
}

Nodo * borrar_final(Nodo * cabecera){
    if(cabecera == NULL){
        printf("Lista Vacia\n");
        return NULL;
    } else{
        Nodo * temp = cabecera;
        Nodo * previo = NULL;

        while (temp->siguiente != cabecera) {
            previo = temp;
            temp = temp->siguiente;
        }
        
        if(temp->siguiente == temp){
          cabecera = NULL;
        } else{
            previo->siguiente = cabecera;
        }
        
        free(temp);
    }
    
    return cabecera;
}

int buscar(Nodo * cabecera, int valor_buscado){
    int buscado = 0;
    if(cabecera == NULL){
        buscado = 0;
    } else{
        Nodo * temp = cabecera;
        do{
            if(temp->dato == valor_buscado){
                buscado = 1;
            }
            temp = temp->siguiente;
        } while(temp != cabecera);
    }
    return buscado;
}

void desplegar(Nodo * cabecera){
    if(cabecera == NULL){
        printf("\nLa lista esta vacia");
        return;
    } else{
        Nodo * temp = cabecera;
        do{
            printf("%d->", temp->dato);
            temp = temp->siguiente;
        } while(temp != cabecera);
        printf("CABECERA");
    }
}
