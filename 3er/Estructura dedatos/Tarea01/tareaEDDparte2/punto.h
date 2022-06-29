#ifndef __PUNTO_H__
#define __PUNTO_H__

typedef struct pnt{
	int x;
	int y;
} Punto;

Punto capturar();
void desplegar(Punto pt);
int esOrtogonal(Punto pt1, Punto pt2, Punto pt3);


#endif

