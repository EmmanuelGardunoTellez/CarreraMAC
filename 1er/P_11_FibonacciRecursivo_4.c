#include<stdio.h>
#include <math.h>
#include "biblioteca.h"


int fibonacci(int a){
   int b,c;
   if(a==1 || a==2){
      b=1;
      return b;
   }
   if(a>2){
      b=fibonacci(a-1)+fibonacci(a-2);
      return b;
   }
}
 
int main(){
int n,i,respuesta;
	ConfiguraIdioma();
	portada();
do{
	system("cls");
do{
	printf("ingrese el numero natural: ");
	scanf("%d",&n);
}while(n<1);

for(i=1;i<=n;i++)
{
	printf("%d ",fibonacci(i));
}
printf("\n");
printf("Deseas continuar? (1=si 0=no) \n");
scanf("%d", &respuesta);
}while(respuesta==1);
   return 0;
}
