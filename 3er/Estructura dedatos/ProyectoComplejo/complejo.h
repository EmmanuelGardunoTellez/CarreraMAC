#include <stdio.h>
#include <stdlib.h>

typedef struct Complejos{
	int a;
	int b;
} complejo;

complejo suma(complejo1,complejo2);
complejo resta(complejo1,complejo2);
complejo multiplicacion(complejo1,complejo2);

	complejo suma(complejo1,complejo2){
	complejo z;
	z.a= complejo1.a + complejo2.a;
	z.a= complejo1.b + complejo2.b;
	return z;
	}
	
	complejo resta(complejo1,complejo2){
	complejo z;
	z.a= complejo1.a - complejo2.a;
	z.a= complejo1.b - complejo2.b;
	return z;
	}

complejo multiplicacion(complejo1,complejo2){
	complejo z;
	z.a= (complejo1.a * complejo2.a) - (complejo1.b * complejo2.b);
	z.a= (complejo1.a * complejo2.b) + (complejo2.a * complejo1.b);
	return z;
	}
