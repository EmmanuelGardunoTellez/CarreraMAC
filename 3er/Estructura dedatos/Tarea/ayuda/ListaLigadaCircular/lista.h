//
//  lista.h
//  Practica04
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

Nodo * insertar_frente(Nodo *, int);
Nodo * insertar_final(Nodo *, int);
Nodo * borrar_frente(Nodo *);
Nodo * borrar_final(Nodo *);
int buscar(Nodo *, int);
void desplegar(Nodo *);

#endif /* lista_h */
