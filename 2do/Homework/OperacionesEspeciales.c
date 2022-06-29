#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int menu()
{
	system("cls");
	int opcion;
	printf("Operaciones disponibles\n");
	printf("1.Asignación de matrices.\n");
	printf("2.Suma\n");
	printf("3.Salir\n");
	do
	{
		printf("Opcción: ");
		scanf("%d",&opcion);
	}while(!(opcion>=1&&opcion<=3));
	return opcion;
}

/*Funcion principal*/
void main(){
	int  *ptr, n, i, opcion; //Variables
	FILE *archivo = fopen("Datos a calculadora.txt", "w");
	do {
		opcion=menu();
		if(opcion!=5)
		{
			switch(opcion){
				case 1:
					printf("Ingrese el tamaño de la funcion: ");
					scanf("%d", &n); //De donde a donde multiplica
					ptr = (int *) malloc(n * sizeof(int)); //Cambio de la tamaño del arreglo
					for(i=n+1;i>0;--i){ //Guarda el tamaño del arreglo
						printf("Dame el valor de x^%i: ",i-1);
						scanf("%i",ptr+i);
					}
					for(i=n+1;i>0;--i){
					fprintf(archivo," + %ix^%i",*(ptr+i), i-1);
					}
					fprintf(archivo,"\n");
					for(i=n+1;i>1;--i){
					fprintf(archivo," + %ix^%i",*(ptr+i)*(i-1), i-1-1);
					}
				break;
				case 2:
					printf("Ingrese el tamaño de la funcion: ");
					scanf("%d", &n); //De donde a donde multiplica
					ptr = (int *) malloc(n * sizeof(int)); //Cambio de la tamaño del arreglo
					for(i=n+1;i>0;--i){  //Guarda el tamaño del arreglo
					printf("Dame el valor de x^%i: ",i-1);
					scanf("%i",ptr+i);
					}
					for(i=n+1;i>0;--i){
					fprintf(archivo," + %ix^%i",*(ptr+i), i-1);
					}
					fprintf(archivo,"\n");
					for(i=n+1;i>0;--i){
					fprintf(archivo," + %i(x^%i)/%i",*(ptr+i),i,i);
					}
				break;
			}//fin del switch
		}
	}while(opcion!=3);
	
	free(ptr); //Liberar memoria adiccional
	fclose(archivo); //Cierra ar archivo
	
}
