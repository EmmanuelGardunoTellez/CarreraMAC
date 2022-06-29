#include <stdio.h>
#include <stdlib.h>
#include "punto.h"
#include "rectangulo.h"
#define MAX 3

int main(int argc, char *argv[]) {
	// Capturando un solo punto
	Punto p1;
	p1 = capturar();
	desplegar(p1);
	printf("\n\nPresione un boton para continuar ...");
	getch();
	// Capturando varios punto
	system("cls");
	Punto p2[MAX];
	int i;
	printf("\nCapturando varios puntos ...\n");
	for(i=0; i<MAX; i++){
		p2[i] = capturar();
		desplegar(p2[i]);
		printf("\n");
	}
	printf("\n\nPresione un boton para continuar ...");
	getch();
	// Usando memoria dinámica para puntos
	system("cls");
	Punto * p3 = NULL;
	p3 = (Punto*) malloc(MAX * sizeof(Punto));
	printf("\nCapturando varios puntos usando memoria dinamica ...\n");
	for(i=0; i<MAX; i++){
		p3[i] = capturar();
		desplegar(p3[i]);
		printf("\n");
	}
	free(p3);
	printf("\n\nPresione un boton para continuar ...");
	getch();
	// Inicializando Puntos
	system("cls");
	printf("\nImprimiendo valores inicializados ...\n");
	Punto p4 = {2,3};
	desplegar(p4);
	printf("\n\nPresione un boton para continuar ...");
	getch();
	// Imprimiendo varios puntos inicializando
	system("cls");
	printf("\nImprimiendo valores inicializados ...\n");
	Punto p5[] = {{7,8},{-10,5},{12,9}}; 
	for(i=0; i<MAX; i++){
		desplegar(p5[i]);
		printf("\n");
	}
	printf("\n\nPresione un boton para continuar ...");
	getch();
	// Capturando un rectangulo
	system("cls");
	printf("\nCapturando un rectangulo ...\n");
	Rectangulo rect1;
	rect1 = capturar_rect();
	if(esRectangulo(rect1)){
		printf("\nLa figura es un rectangulo ...");
		// Si es rectangulo imprimir área y perímetro
	} else{
		printf("\nLa figura NO es un rectangulo ...");
	}
	
	


    return 0;

}

