#ifndef llcd_h
#define llcd_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char buffer[64];

typedef struct zapateria{
	int codigo;
	char * marca;
	char * modelo;
	char * color;
	float talla;
} Zapateria;

Zapateria * crearZapato();
void desplegarZapato(Zapateria *);

struct nodo{
 Zapateria * dato;
 struct nodo * siguiente;
 struct nodo * previo;
};

typedef struct nodo Nodo;

struct lista{
 	Nodo * cabecera;
 	Nodo * final;
 	int cuenta;
};

typedef struct lista ListaCircularDoble;

Nodo * crearNodo(Zapateria *);
ListaCircularDoble * inicializarLista();
void insertar_frente(ListaCircularDoble *);
void insertar_final(ListaCircularDoble *);
void insertar_en_posicion(ListaCircularDoble *, int);
void borrar_frente(ListaCircularDoble *);
void borrar_final(ListaCircularDoble *);
void borrar_en_posicion(ListaCircularDoble *, int);
void desplegar_adelante(ListaCircularDoble *);
void desplegar_inverso(ListaCircularDoble *);
int numero_nodos(ListaCircularDoble *);
void buscar_codigo(ListaCircularDoble *, int);
void buscar_marca(ListaCircularDoble *, const char *);

#endif
