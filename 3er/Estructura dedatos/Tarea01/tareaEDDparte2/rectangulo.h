#ifndef __RECTANGULO_H__
#define __RECTANGULO_H__

typedef struct rect{
	Punto p1;
	Punto p2;
	Punto p3;
	Punto p4;
} Rectangulo;

int esRectangulo(Rectangulo r);
Rectangulo capturar_rect();
int areaRectangulo(Rectangulo r);
int perimetroRectangulo(Rectangulo r);

#endif
