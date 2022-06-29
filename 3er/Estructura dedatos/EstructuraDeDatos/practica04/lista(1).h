//
//  lista.h
//  ListaLigada
//
//  Created by Jonathan Cordoba Luna on 9/13/19.
//  Copyright © 2019 Jonathan Cordoba Luna. All rights reserved.
//

#ifndef lista_h
#define lista_h
#include <stdio.h>

typedef struct nodo{
    int dato;           
    struct nodo * siguiente;   
} Nodo;

Nodo * crearNodo(int dato);
Nodo * insertar_primero(Nodo * cabecera, int elemento);
Nodo * insertar_final(Nodo * cabecera, int elemento);
void desplegar(Nodo * cabecera);

#endif /* lista_h */
