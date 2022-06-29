#include <stdio.h>
#include <stdlib.h>
#include "punto.h"
#include "rectangulo.h"
#include "triangulo.h"
#define MAX 3

int main(int argc, char *argv[]) {

	// Capturando un rectangulo
	system("cls");
	printf("\nCapturando un rectangulo ...\n");
	Rectangulo rect1;
	rect1 = capturar_rect();
	if(esRectangulo(rect1)){
		printf("\nLa figura es un rectangulo ...");
		printf("\nEl area del rectangulo es: %i", areaRectangulo(rect1));
		printf("\nEl perimetro del rectangulo es: %i", perimetroRectangulo(rect1));
	} else{
		printf("\nLa figura NO es un rectangulo ...\n");
	}
	system("pause");
	
	// Capturando un triangulo
	system("cls");
	printf("\nCapturando un triangulo ...\n");
	Triangulo tri1;
	tri1 = capturar_tri();
	if(esTriangulo(tri1)){
		printf("\nLa figura es un triangulo ...");
		printf("\nEl area del rectangulo es: %i", areaTriangulo(tri1));
		printf("\nEl perimetro del triangulo es: %i", perimetroTriangulo(tri1));
		esUnTriangulo(tri1);
	} else{
		printf("\nLa figura NO es un triangulo ...");
	}
	system("pause");

    return 0;

}
