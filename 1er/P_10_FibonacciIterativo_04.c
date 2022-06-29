#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include "biblioteca.h"

 int fibonacci (int n)
	{
	int C,A=1,B=1,i=1;
	
	if(n<=1)
	{
		printf("%i",A);	
	}
	else
	{
		printf("%i, ",A);
		printf("%i, ",B);
		while(i<n-1)
		{
    		C=A+B;
			A=B;
    		B=C;
    		printf("%d, ",C);
   			 i++;
  		}	
	}
	printf("\n\n");
}

 int main()
 {
 	ConfiguraIdioma();
	portada();
 	int n,Respuesta;
 	do{
 		system("cls");
 		printf("Introduzca la cantidad de números de fibonacci que desea ver (mayores a 0): \n");
    	do{
		scanf("%d",&n);
		}while(n<=0);
    	printf("Los números que pertenecen a la cantidad deseada son:\n\n");
    	fibonacci(n);
 		system ("pause");
		printf("¿Quieres repetir? (1=si 0=no): ");
		scanf("%d", &Respuesta);
}	while(Respuesta==1);
	return 0;
}
