#include <stdio.h> 
#include <stdlib.h>
#include "biblioteca.h"
int fibon (int n)
   {
   	int fibo[50];
   	int i;
   	
	if(n>=2){

   fibo[0]=1;
   fibo[1]=1;
   printf("%i, ",fibo[0]);
     printf("%i, ",fibo[1]);
     
     for(i=2;i<=n-1;i++){
     	fibo[i]=fibo[i-1]+fibo[i-2];
     	printf("%i ,",fibo[i]);
     }
 }
   	else
	{ 
	 printf("1"",""");
     
	 }
	printf("\n\n");
	 system ("pause");
	return 0;
}
	 
 int main()
 {
 	int n,i,respuesta;
	ConfiguraIdioma();
	portada();
do{
	system("cls");
 	printf("Introduzca la cantidad de números de Fibonacci que desea ver: ");
    scanf("%d",&n);
    printf("Los números que pertenecen a la cantidad deseada son: \n\n");   
	fibon(n);
	printf("\n");
	printf("Deseas continuar? (1=si 0=no) \n");
	scanf("%d", &respuesta);
}while(respuesta==1);
   return 0;	
}
 
