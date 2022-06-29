#include <stdio.h>
#include <stdlib.h>
#include "zapateria.h"
#include "zapa.h"

Zapateria  * inicializar(int i){
    Zapateria * zap;
    zap = (Zapateria*) malloc(sizeof(Zapateria));
    if(zap == NULL){
    	printf("\nError de memoria");
    	return;
	}
    zap->coleccion = (Zapato *) malloc(i * sizeof(Zapato));
    if(zap->coleccion == NULL){
    	printf("\nError de memoria");
    	return;
	}
    zap->capacidad = i;
    zap->tam = 0;
    return zap;
}

int esLlena(Zapateria * zap){
    return zap->capacidad == zap->tam;
}

int esVacia(Zapateria * zap){
    return zap->tam == 0;
}

void insertar(Zapateria * zap){
    if(esLlena(zap)){
        printf("\nZapateria llena");
    } else{
        Zapato zp;
        zp = obtenerZapato();
        zap->coleccion[zap->tam] = zp;
        zap->tam++;
    }
}

void borrar(Zapateria * zap){
    if(esVacia(zap)){
        printf("\nZapateria vacia");
    } else{
        zap->tam--;
    }
}

void desplegar(Zapateria * zap){
	int i;
	for(i=0; i<zap->tam; i++){
		desplegarZapato(zap->coleccion[i]);
	}
}

int numZapatos(Zapateria * zap){
    return zap->tam;
}

int capacidadZapateria(Zapateria * zap){
    return zap->capacidad;
}

void desplegarUno(Zapateria * zap){
	int indice, i;
	printf("\nIngrese el id a buscar: ");
	scanf("%d", &indice);
	i = (zap, indice);
	if(i == -1){
		printf("\nEl zapato no existe");
	} else {
		printf("\nInformacion del zapato: ");
		desplegarZapato(zap->coleccion[i]);
	}
	
}
