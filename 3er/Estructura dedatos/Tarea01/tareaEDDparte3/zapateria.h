

#ifndef biblioteca_h
#define biblioteca_h
#include "zapa.h"

typedef struct biblio{
    Zapato * coleccion;
    int capacidad;
    int tam;
} Zapateria;

Zapateria * inicializar(int i);
int esLlena(Zapateria * zap);
int esVacia(Zapateria * zap);
void insertar(Zapateria * zap);
void borrar(Zapateria * zap);
void desplegar(Zapateria * zap);
int numLibros(Zapateria * zap);
int capacidadBiblio(Zapateria * zap);

#endif 
