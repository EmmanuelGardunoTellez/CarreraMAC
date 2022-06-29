#include <stdio.h>
#include <conio.h>
#define f 10
#define c 10

void versuma(int n, int *ru, int *cu)
{
	printf("Dime el numero de renglones de la matriz %d:", n);
	scanf("%d",ru);
	printf("Dime el numero de columnas de la matriz %d:", n);
	scanf("%d",cu);
}

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
	printf("1.Asignación de matrices.");
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
	//Portada;
	do {
		opcion=menu();
		if(opcion!=5)
		{
			switch(opcion){
				case 1:
					system("cls");
					n=1;
					versuma(n,&ra,&ca);
					datos(matriza,n, ca,ra);
					n=n+1;
					versuma(n,&cb,&rb);
					datos(matrizb,n, cb,rb);
					imprimir(matriza, ca,ra);
					printf("\n");
					imprimir(matrizb, cb,rb);
					system("pause");
					break;
					
				case 2:	
					system("cls");
					printf("Matriz 1:\n");
					imprimir(matriza, ca,ra);
					printf("Matriz 2:\n");
					imprimir(matrizb, cb,rb);
					printf("\n");
					if(ra==rb && ca==cb)
					{
						suma(matriza, matrizb, matrizc);
						imprimir(matrizc, ca, rb);	
					}
					else
					{
						printf("No se puede realizar la suma de marices");
					}	
					system("pause");	
					break;
					
				case 3:
					system("cls");
					if(ra==rb && ca==cb)
					{
						resta(matriza, matrizb, matrizc);
						imprimir(matrizc, ca, rb);	
					}
					else
					{
						printf("No se puede realizar la resta de marices");
					}	
					system("pause");
					break;
				case 4:
					system("cls");
					if(ca==rb)
					{
						multi(matriza, matrizb, matrizc,ra,cb,ca);
						imprimir(matrizc,cb,ra);
					}
					else
					{
						printf("No se puede realizar la multiplicacion de marices");
					}
					system("pause");
					break;
			}//fin del switch
		}
	}while(opcion!=5);

	printf("Bye\n");
	system("Pause");
}
