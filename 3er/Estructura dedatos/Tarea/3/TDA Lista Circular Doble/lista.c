#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "lista.h"

Zapateria * crearZapato(){
	Zapateria * zap = (Zapateria*) malloc(sizeof(Zapateria));
	fflush(stdin);
	// Introduciendo Codigo
	printf("\nIntroduzca el Codigo de Articulo: ");
	if(fgets(buffer,64,stdin) == NULL) exit(0);
	zap->codigo = atoi(buffer);
 	// Introduciendo Marca
 	printf("Introduzca la Marca del Articulo: ");
	if(fgets(buffer,64,stdin) == NULL) exit(0);
 	zap->marca = (char *) malloc(strlen(buffer)+1);
 	strcpy(zap->marca, buffer);
 	// Introduciendo Modelo
 	printf("Introduzca el Modelo del Articulo: ");
 	if(fgets(buffer,64,stdin) == NULL) exit(0);
 	zap->modelo = (char *) malloc(strlen(buffer)+1);
 	strcpy(zap->modelo, buffer);
 	// Introduciendo Color
 	printf("Introduzca el Color del Articulo: ");
 	if(fgets(buffer,64,stdin) == NULL) exit(0);
 	zap->color = (char *) malloc(strlen(buffer)+1);
 	strcpy(zap->color, buffer);
 	// Introduciendo Talla
 	printf("Introduzca la Talla de Articulo: ");
 	if(fgets(buffer,64,stdin) == NULL) exit(0);
 	zap->talla = atof(buffer);

 	return zap;
}

void desplegarZapato(Zapateria * zap){
 	printf("\nCodigo: %d", zap->codigo);
 	printf("\nMarca: %s", zap->marca);
 	printf("Modelo: %s", zap->modelo);
 	printf("Color: %s", zap->color);
 	printf("Talla: %f", zap->talla);
 	printf("\n");
}

Nodo * crearNodo(Zapateria * x){
 	Nodo * nodo = (Nodo*) malloc(sizeof(Nodo));
 	nodo->dato = x;
 	nodo->siguiente = nodo;
 	nodo->previo = nodo;
 	return nodo;
}

ListaCircularDoble * inicializarLista(){
 	ListaCircularDoble * lista = (ListaCircularDoble*)
	malloc(sizeof(ListaCircularDoble));
 	lista->cabecera = NULL;
 	lista->final = NULL;
 	lista->cuenta = 0;
 	return lista;
}

void insertar_frente(ListaCircularDoble * lcd){
 	Zapateria * zap = crearZapato();
 	Nodo * nuevoNodo = crearNodo(zap);
 	if(lcd->cabecera == NULL){
 		lcd->cabecera = lcd->final = nuevoNodo;
 		nuevoNodo->previo = lcd->final;
 		nuevoNodo->siguiente = lcd->cabecera;
 		lcd->cuenta++;
 	}
	else{
 		nuevoNodo->siguiente = lcd->cabecera;
 		nuevoNodo->previo = lcd->final;
 		lcd->cabecera->previo = nuevoNodo;
 		lcd->final->siguiente = nuevoNodo;
 		lcd->cabecera = nuevoNodo;
 		lcd->cuenta++;
 	}
}

void insertar_final(ListaCircularDoble * lcd){
 	Zapateria * zap = crearZapato();
 	Nodo * nuevoNodo = crearNodo(zap);
 	if(lcd->cabecera == NULL){
 		lcd->cabecera = lcd->final = nuevoNodo;
 		nuevoNodo->previo = lcd->final;
 		nuevoNodo->siguiente = lcd->cabecera;
 		lcd->cuenta++;
 	}
	else{
 		lcd->final->siguiente = nuevoNodo;
 		nuevoNodo->siguiente = lcd->cabecera;
 		nuevoNodo->previo = lcd->final;
 		lcd->final = nuevoNodo;
 		lcd->cabecera->previo = lcd->final;
 		lcd->cuenta++;
 	}
}

void insertar_en_posicion(ListaCircularDoble * lcd, int pos){
 	if(pos == 1){
 		insertar_frente(lcd);
 	}
	else{
 		if(pos>1 && lcd->cabecera != NULL){
 		Nodo * temp = lcd->cabecera;
 		Nodo * previo = NULL;
 		int i;
 		for(i=1; i<=pos-1; i++){
 			previo = temp;
 			temp = temp->siguiente;
 		}
 		Zapateria * zap = crearZapato();
 		Nodo * nuevoNodo = crearNodo(zap);
 		previo->siguiente = nuevoNodo;
 		nuevoNodo->siguiente = temp;
 		nuevoNodo->previo = previo;
 		temp->previo = nuevoNodo;
 		lcd->cuenta++;
 		}
		else{
 			// Posicion Invalida
 			printf("\nPosicion Invalida");
 			return;
 		}
 	}
}

void borrar_frente(ListaCircularDoble * lcd){
 	if(lcd->cabecera == NULL){
 		return;
 	}
	else if(lcd->cabecera == lcd->final){
 		lcd->cabecera = lcd->final = NULL;
 		free(lcd->cabecera);
 		lcd->cuenta--;
 	}
 	else{
 		Nodo * temp = lcd->cabecera;
 		lcd->final->siguiente = lcd->cabecera->siguiente;
 		lcd->cabecera = lcd->cabecera->siguiente;
 		lcd->cabecera->previo = lcd->final;
 		lcd->cuenta--;
 		free(temp);
 	}
}

void borrar_final(ListaCircularDoble * lcd){
 	if(lcd->cabecera == NULL){
 		return;
 	}
	else if(lcd->cabecera == lcd->final){
 		lcd->cabecera = lcd->final = NULL;
 		free(lcd->cabecera);
 		lcd->cuenta--;
 	}
	else{
 		Nodo * temp = lcd->cabecera;
 		Nodo * previo = lcd->cabecera;

 		while(temp->siguiente != lcd->cabecera){
 		previo = temp;
 		temp = temp->siguiente;
 		}

 		previo->siguiente = lcd->cabecera;
 		lcd->final = previo;
 		lcd->cabecera->previo = lcd->final;
 		free(temp);
 		lcd->cuenta--;
 	}
}

void borrar_en_posicion(ListaCircularDoble * lcd, int pos){
	 if(lcd->cabecera == lcd->final && lcd->cabecera == NULL){
 		return;
 	}
	else{
 		if(lcd->cuenta < pos){
 			// Posición Inválida
 			printf("\nPosicion Invalida");
 			return;
 		}
		else if(pos == 1){
 			borrar_frente(lcd);
 			return;
 		}
		else{
 			Nodo * temp = lcd->cabecera;
 			Nodo * previo = NULL;
 			int i;
 			for(i=0; i<pos-1; i++){
 				temp = temp->siguiente;
 				previo = temp->previo;
 			}
 			previo->siguiente = temp->siguiente;
 			temp->siguiente->previo = previo;
 			if(pos == lcd->cuenta){
 				lcd->final = previo;
 			}
 			lcd->cuenta--;
 			free(temp);
 		}
 	}
}

void desplegar_adelante(ListaCircularDoble * lcd){
	 if(lcd->cabecera == lcd->final && lcd->cabecera == NULL){
 		printf("\nLista Vacia\n");
 		return;
 	}
	else{
 		printf("\nLista de Articulos en Existencia: \n");
 		Nodo * temp = lcd->cabecera;
 		do{
 			desplegarZapato(temp->dato);
 			temp = temp->siguiente;
 		}while (temp != lcd->cabecera);
 	}
}

void desplegar_inverso(ListaCircularDoble * lcd){
 	if(lcd->cabecera == lcd->final && lcd->final == NULL){
 		printf("\nLista Vacia\n");
 		return;
 	}
	else{
		Nodo * temp = lcd->final;
 		do{
 			desplegarZapato(temp->dato);
 			temp = temp->previo;
 		}while (temp != lcd->final);
 	}
}

int numero_nodos(ListaCircularDoble * lcd){
 	return lcd->cuenta;
}

void buscar_codigo(ListaCircularDoble * lcd, int cod){
 	Nodo * encontrado = NULL;
 	bool buscado = false;
 	if(lcd->cabecera == NULL){
 		buscado = false;
 	}
	else{
 		Nodo * temp = lcd->cabecera;
 		do {
 			if(temp->dato->codigo == cod){
 				encontrado = temp;
 				buscado = true;
 			}
 			temp = temp->siguiente;
 		}while(temp != lcd->cabecera);
 	}

 	if(buscado == true){
 		printf("\nDetalles del Producto: \n");
 		desplegarZapato(encontrado->dato);
 	}
	else{
 		printf("\nNo existe el Articulo");
 	}
}

void buscar_marca(ListaCircularDoble * lcd, const char * marca){
 	if(lcd->cabecera == NULL){
 		printf("\nNo hay productos en existencia");
 	}
	else{
 		Nodo * temp = lcd->cabecera;
 		int cont_aux = 0;
 		do {
 			if(strcmp(temp->dato->marca, marca) == 0){
 				cont_aux++;
 				desplegarZapato(temp->dato);
 			}
 			temp = temp->siguiente;
 		}while(temp != lcd->cabecera);

 		if(cont_aux == 0){
 			printf("\n\nNo hay productos en existencia");
 		}
		else{
 			printf("\n\nSe encontraron %d articulo(s) en existencia.", cont_aux);
 		}
 	}
}

