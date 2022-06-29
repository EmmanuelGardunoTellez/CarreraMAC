#include<stdio.h>
#include<math.h>
 #include "biblioteca.h"
/*void tamanno_matriz (){
	int matrizra, matrizca, i,j;
	float matrizA[matrizra][matrizca];
	Printf("Dime el numero de renglones de la matriz");
	scanf("%i",&mitrizra);
	Printf("Dime el numero de columnas de la matriz");
	scanf("%i",&mitrizca);
	
	for(i=0;i<matrizca;i++)
	{
		for(j=0,j<matrizra,j++)
		{
			printf("Elemento[%d][%d] = ",j,i);
			scanf("%f",&marizA[j][i]);
		}	
	}	
}

void Suma (){
	float matrizC[matrizrc][matrizcc];
	if(matrizra==matrizb && matrizca==matrizcb)
	{
		matrizrc=mareizra;
		matrizcc=mareizca;
		for(i=0;i<matrizca;i++)
		{
			for(j=0,j<matrizra,j++)
			{
				matrizC[j][i]= matriA[j][i]+matrizB[j][i]
			}	
		}	
	
	}
	else
	{
		printf("No se puede realizar la suma de marices")
	}
	
}

void Resta (){
	float matrizC[matrizrc][matrizcc];
	if(matrizra==matrizb && matrizca==matrizcb)
	{
		matrizrc=mareizra;
		matrizcc=mareizca;
		for(i=0;i<matrizca;i++)
		{
			for(j=0,j<matrizra,j++)
			{
				matrizC[j][i]= matriA[j][i]-matrizB[j][i]
			}	
		}	
	
	}
	else
	{
		printf("No se puede realizar la resta de marices")
	}
	
}

void Multi (){
	float matrizC[matrizrc][matrizcc];
	if(matrizb==matrizca)
	{
		for(i=0;i<matrizra;i++)
		{
			for(j=0,j<matrizca,j++)
			{
				suma=0;
				for (x=0,matrizca,x++){
					suma=suma+matriza[i][x]*matrizb[x][j];	
				}
				matrizc[i][j]=suma;
			}	
		}	
	
	}
	else
	{
		printf("No se puede realizar la multiplicación de marices")
	}
	
}*/

int menu()
{
	int opcion;
	prinrf("Por favor si la primera vez designa el tamaño de las matrices.");
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
	}while(!(opcion>=1&&opcion<=4));
	return opcion;
}

main()
{
	int opcion;
	float R1, R2, I1, I2;
	//Portada;
	do {
		opcion=menu();
		if(opcion!=6)
		{
			switch(opcion){
				case 1:
					//matriz valores
					break;
				case 2:
					//suma
					break;
				case 3:
					//resta
					break;
				case 4:
					//multiplicacion
					break;
			}//fin del switch
		}
	}while(opcion!=5);
	printf("Bye\n");
	system("Pause");
}



