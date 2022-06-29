//
//  lista.c
//  ListaLigada
//
//  Created by Jonathan Cordoba Luna on 9/13/19.
//  Copyright © 2019 Jonathan Cordoba Luna. All rights reserved.
//

#include "lista.h"
#include <stdlib.h>

Nodo * crearNodo(int elemento){
	Nodo * nuevo = (Nodo*) malloc(sizeof(Nodo));
	if(nuevo == NULL){
        return NULL;
    }
	nuevo->dato = elemento;
	nuevo->siguiente = NULL;
	return nuevo;
}

Nodo * insertar_primero(Nodo * cabecera, int elemento){
    Nodo * nuevo;
	nuevo = crearNodo(elemento);        
    nuevo->siguiente = cabecera;         
    cabecera = nuevo;              
    return cabecera;
}

Nodo * insertar_final(Nodo * cabecera, int elemento){
    Nodo * nuevo, *temp;
    nuevo = crearNodo(elemento);
    if(nuevo == NULL){
        printf("Error de Asignacion.");
        return NULL;
    }
    else{
        temp = cabecera;
        while(temp->siguiente != NULL){
        	temp = temp->siguiente;	
		}
        temp->siguiente = nuevo;
        printf("\nDato Insertado Exitosamente\n");
    }
    return cabecera;
}

void desplegar(Nodo * cabecera){
    if(cabecera == NULL){
        printf("Lista Vacia\n");
        return;
    }
    Nodo * temp = cabecera;
    printf("\n");
    while(temp != NULL){
        printf("%d->", temp->dato);             
        temp = temp->siguiente;                
    }
    printf("NULL\n");
}


