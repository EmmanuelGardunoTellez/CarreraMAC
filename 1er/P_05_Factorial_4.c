#include<stdio.h>
#include<math.h>
#include<stdlib.h>
 #include "biblioteca.h"

void fac(int a)
{
int r,i;
r=1;
   
if(a==0)
{
printf("El factorial es 1\n");
}
else
{
for(i=1;i<=a;i++)
{
r=r*i; 
}
printf("El factorial es %i \n",r);
system("pause");
}

}


int main ()

{
int a,Respuesta;
ConfiguraIdioma();
portada();
do{
	printf("Dame un número para obtener su factorial: ");
	scanf("%i", &a); 
	fac(a);
	printf("¿Quieres repetir? (1=si 0=no): ");
	scanf("%d", &Respuesta);
}while(Respuesta==1);
return 0;
}

