#include "punto.h"
#include "rectangulo.h"

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

