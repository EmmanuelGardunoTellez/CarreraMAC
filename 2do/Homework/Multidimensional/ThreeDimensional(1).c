#include <stdio.h>
#include <stdlib.h>
#define P 4 //Cosntante para todas las P

main()
{

	int matriz[2][P][P] = {{ {50,20,50,20},{50,20,50,20},{20,50,20,50},{50,20,50,20}},{{10,20,30,40},{50,60,70,80},{90,100,110,120}}};
	//Numeros almacenados en las matrix 4x4
	int i,j,k;
	for(k=0;k<2;k++) //Sirve para mostrar en orden las matrices
	{
	for(j=0;j<P;j++)
	{
		printf("(");
		for(i=0;i<P;i++)	//Ordena las matriz de forma vertical
		{
			printf("%d ", matriz[k][j][i]);  //Ordena las matriz de forma horisontal
		}
		printf(")\n");
	}
printf("\n\n"); //Da espacio a las matrices
}
}
