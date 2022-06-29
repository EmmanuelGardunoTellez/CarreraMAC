#include "punto.h"
#include "rectangulo.h"
#include <math.h>

int esRectangulo(Rectangulo r){
	int o1 = esOrtogonal(r.p1, r.p2, r.p3);
	int o2 = esOrtogonal(r.p2, r.p3, r.p4);
	int o3 = esOrtogonal(r.p3, r.p4, r.p1);
	if((o1 == 1) && (o2 == 1) && (o3 == 1)) return 1;
	else
	return 0;
}

Rectangulo capturar_rect(){
	Rectangulo r;
	r.p1 = capturar();
	r.p2 = capturar();
	r.p3 = capturar();
	r.p4 = capturar();
	return r;
}

int areaRectangulo(Rectangulo r){
	int lado1 = sqrt(((r.p2.x-r.p1.x)*(r.p2.x-r.p1.x))+((r.p2.y-r.p1.y)*(r.p2.y-r.p1.y)));
	int lado2 = sqrt(((r.p3.x-r.p2.x)*(r.p3.x-r.p2.x))+((r.p3.y-r.p2.y)*(r.p3.y-r.p2.y)));
	int lado3 = sqrt(((r.p4.x-r.p3.x)*(r.p4.x-r.p3.x))+((r.p4.y-r.p3.y)*(r.p4.y-r.p3.y)));
	int lado4 = sqrt(((r.p1.x-r.p4.x)*(r.p1.x-r.p4.x))+((r.p1.y-r.p4.y)*(r.p1.y-r.p4.y)));
	int ladoTotal = lado1 + lado2 + lado3 + lado4;
	return ladoTotal;
}

int perimetroRectangulo(Rectangulo r){
	int lado1 = sqrt(((r.p2.x-r.p1.x)*(r.p2.x-r.p1.x))+((r.p2.y-r.p1.y)*(r.p2.y-r.p1.y)));
	int lado2 = sqrt(((r.p3.x-r.p2.x)*(r.p3.x-r.p2.x))+((r.p3.y-r.p2.y)*(r.p3.y-r.p2.y)));
	int ladoTotal = lado1 * lado2;
	return ladoTotal;
	}







