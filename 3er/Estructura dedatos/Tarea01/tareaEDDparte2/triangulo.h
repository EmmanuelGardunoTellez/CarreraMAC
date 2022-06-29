#ifndef __TRIANGULO_H__
#define __TRIANGULO_H__

typedef struct tri{
	Punto p1;
	Punto p2;
	Punto p3;
} Triangulo;

int esTriangulo(Triangulo r);
Triangulo capturar_tri();
void esUnTriangulo(Triangulo r);
int areaTriangulo(Triangulo r);
int perimetroTriangulo(Triangulo r);

#endif
