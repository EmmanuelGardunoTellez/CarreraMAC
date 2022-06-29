#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "biblioteca.h"

	
int divi(int n)
{
	int d, r, i;
	for(i=1;i<=n;i++)
	{
		
		r=n%i;
		if (r==0)
			printf ("Uno de sus divisores es: %i\n\n",i);
	}
}

int main ()
{
	ConfiguraIdioma();
	portada();
    int  n, r, Respuesta;
    do 
	{
		system("cls");
		printf("Dame un número del que quieras sus divisores: ");
		scanf ("%i",&n); 
		divi(n);
		system("pause");
		printf("¿Quieres repetir?(1=si 0=no):");
		scanf("%d", &Respuesta);
    } while(Respuesta==1);
    return 0;
} 




