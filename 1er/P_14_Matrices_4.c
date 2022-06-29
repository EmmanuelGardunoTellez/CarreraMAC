#include <stdio.h>
#include <conio.h>
#include "biblioteca.h"
#define f 10
#define c 10

void datos(int matriz[][c], int n,int ren,int col)
{
	int i,j;
 	for(j=0;j<ren;j++)
	{
		for(i=0;i<col;i++)	
		{
			printf("introduce el valor de la matriz %d (%d, %d): ",n,i+1,j+1);
			scanf("%d",&matriz[i][j]);
		}
	}
}

void imprimir(int matriz[][c], int ren, int col){
	int i,j;
	for(j=0;j<col;j++)
	{
		printf("(");
		for(i=0;i<ren;i++)	
		{
			printf("%d ", matriz[j][i]);
		}
		printf(")\n");
	}
}

void suma (int matriza[][c], int matrizb[][c], int matrizc[][c]){
	int i,j;
	for(i=0;i<f;i++)
	{
		for(j=0;j<c;j++)
		{
			matrizc[i][j]= matriza[i][j]+matrizb[i][j];
		}	
	}	
}

void resta (int matriza[][c], int matrizb[][c], int matrizc[][c]){
	int i,j;
	for(i=0;i<f;i++)
	{
		for(j=0;j<c;j++)
		{
			matrizc[i][j]= matriza[i][j]-matrizb[i][j];
		}	
	}	
}
void multi (int matriza[][c], int matrizb[][c], int matrizc[][c], int ra, int cb, int ca)
{
	int i,j,x,suma=0;	
	for(i=0;i<ra;i++)
	{
		for(j=0;j<cb;j++)
		{
			suma=0;
			for (x=0;x<ca;x++)
			{
				suma=suma+(matriza[i][x]*matrizb[x][j]);	
			}
			matrizc[i][j]=suma;
		}	
	}	
}


int menu()
{
	system("cls");
	int opcion;
	printf("Por favor si la primera vez designa el tamaño de las matrices.");
	printf("Operaciones matriciales \n");
	printf("1.Asignación de matrices.\n");
	printf("2.Suma\n");
	printf("3.Resta\n");
	printf("4.Miltiplicación\n");
	printf("5.Salir\n");
	do
	{
		printf("Opcción: ");
		scanf("%d",&opcion);
	}while(!(opcion>=1&&opcion<=5));
	return opcion;
}

main()
{
	int opcion, matriza[c][f], matrizb[c][f], matrizc[c][f],n, ra, rb, ca, cb;
	ConfiguraIdioma();
	portada();
	do {
		opcion=menu();
		if(opcion!=5)
		{
			switch(opcion){
				case 1:
					n=1;
					printf("Dime el numero de renglones de la matriz %d:", n);
					scanf("%d",&ra);
					printf("Dime el numero de columnas de la matriz %d:", n);
					scanf("%d",&ca);
					datos(matriza,n, ca,ra);
					n=n+1;
					printf("Dime el numero de renglones de la matriz %d:",n);
					scanf("%d",&rb);
					printf("Dime el numero de columnas de la matriz %d:",n);
					scanf("%d",&cb);
					datos(matrizb,n, cb,rb);
					printf("Matriz 1\n");
					imprimir(matriza, ca,ra);
					printf("\n");
					printf("Matriz 2\n");
					imprimir(matrizb, cb,rb);
					system("pause");
					break;
					
				case 2:	
					if(ra==rb && ca==cb)
					{
						suma(matriza, matrizb, matrizc);
						printf("Matriz 1\n");
						imprimir(matriza,ca,ra);
						printf("Matriz 2\n");
						imprimir(matrizb,cb,rb);
						printf("Matriz suma\n");
						imprimir(matrizc, ca, rb);	
					}
					else
					{
						printf("No se puede realizar la suma de marices\n");
					}		
					system("pause");
					break;
					
				case 3:
					if(ra==rb && ca==cb)
					{
						resta(matriza, matrizb, matrizc);
						printf("Matriz 1\n");
						imprimir(matriza,ca,ra);
						printf("Matriz 2\n");
						imprimir(matrizb,cb,rb);
						printf("Matriz resta\n");
						imprimir(matrizc, ca, rb);	
					}
					else
					{
						printf("No se puede realizar la resta de marices\n");
					}	
					system("pause");
					break;
				case 4:
					if(ca==rb)
					{
						multi(matriza, matrizb, matrizc,ra,cb,ca);
						printf("Matriz 1\n");
						imprimir(matriza,ca,ra);
						printf("Matriz 2\n");
						imprimir(matrizb,cb,rb);
						printf("Matriz multiplicación\n");
						imprimir(matrizc, ca, rb);	
					}
					else
					{
						printf("No se puede realizar la multiplicacion de marices\n");
					}
					system("pause");
					break;
			}//fin del switch
		}
	}while(opcion!=5);

	printf("Fin de menú, adiós.\n");
	system("Pause");
}

