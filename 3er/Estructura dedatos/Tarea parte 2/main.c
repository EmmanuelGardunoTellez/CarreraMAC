#include <stdio.h>
#include <stdlib.h>
#include "punto.h"
#include "rectangulo.h"
#define MAX 3

int menu()
{
	int opcion;
	printf("Selecciona una accion a hacer en el programa \n");
	printf("1.Capturar un solo punto.");
	printf("2.Capturar dos puntos.\n");
	printf("3.Capturar dos puntos con memoria dinamica.\n");
	printf("4.Imprimer puntos inicializados.\n");
	printf("5.Capturar Rectanguo.\n");
	printf("6 Capturar triangulo.\n");
	printf("7.Salir.\n");
	do
	{
		printf("Opcción: ");
		scanf("%d",&opcion);
	}while(!(opcion>=1&&opcion<=7));
	system("cls");
	return opcion;
}

int main(int argc, char *argv[]) {
	
	int opcion, i;
	do {
		opcion=menu();
		if(opcion!=6)
		{
			switch(opcion){
				case 1:
					// Capturando un solo punto
					Punto p1;
					p1 = capturar();
					desplegar(p1);
					printf("\n\nPresione un boton para continuar ...");
					getch();
					system("cls");
					break;
				case 2:
					// Capturando varios punto
					Punto p2[MAX];
					printf("\nCapturando varios puntos ...\n");
					for(i=0; i<MAX; i++){
						p2[i] = capturar();
						desplegar(p2[i]);
						printf("\n");
						}
					printf("\n\nPresione un boton para continuar ...");
					getch();
					system("cls");
					break;
				case 3:
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
					system("cls");
					break;
				case 4:
					// Inicializando Puntos
					printf("\nImprimiendo valores inicializados ...\n");
					Punto p4 = {2,3};
					desplegar(p4);
					printf("\n\nPresione un boton para continuar ...");
					getch();
					// Imprimiendo varios puntos inicializando
					printf("\nImprimiendo valores inicializados ...\n");
					Punto p5[] = {{7,8},{-10,5},{12,9}}; 
					for(i=0; i<MAX; i++){
						desplegar(p5[i]);
						printf("\n");
					}
					printf("\n\nPresione un boton para continuar ...");
					getch();
					system("cls");
					break;
				case 5:
					// Capturando un rectangulo
					printf("\nCapturando un rectangulo ...\n");
					Rectangulo rect1;
					rect1 = capturar_rect();
					if(esRectangulo(rect1)){
						printf("\nLa figura es un rectangulo ...");
					// Si es rectangulo imprimir área y perímetro
					} else{
						printf("\nLa figura NO es un rectangulo ...");
					}
					system("cls");
					break;	
				case 6:
					system("cls");
					break;
			}//fin del switch
		}
	}while(opcion!=7);
	printf("Bye\n");
	system("Pause");


    return 0;

}

