
#ifndef zapaterias_h
#define zapaterias_h


typedef struct zapateria{
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
int numZapatos(Zapateria * zap);
int capacidadZapateria(Zapateria * zap);
void desplegarUno(Zapateria * bib);

#endif
