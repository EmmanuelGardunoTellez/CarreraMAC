#include "punto.h"
#include <stdio.h>
#include <math.h>

Punto capturar(){
	Punto pt_aux;
	printf("\nIngresa la coordenada X: ");
	scanf("%d", &pt_aux.x);
	printf("Ingresa la coordenada Y: ");
	scanf("%d", &pt_aux.y);
	return pt_aux;
}

void desplegar(Punto pt){
	printf("\nEl Punto esta en la coordenada (%d,%d)", pt.x, pt.y);
}

int esOrtogonal(Punto pt1, Punto pt2, Punto pt3){
	int res = ((pt2.x-pt1.x)*(pt2.x-pt3.x)) + ((pt2.y-pt1.y)*(pt2.y-pt3.y));
	if (res == 0) 
	return 1;
	else
	return 0;
}

