#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "biblioteca.h"

void chicharronera (float a, float b, float c)
{
	float d, raizd;
	
	d=(b*b)-(4*a*c);
	
	if (d>0)
	{
		raizd=sqrt(d);
		printf("x1 = %f \t x2 = %f" , (-b + raizd)/(2*a),(-b - raizd)/(2*a));
	}
	else if (d==0)
	{
		printf("x = %f " , (-b/(2*a)));
	}
	else
	{
		raizd=sqrt(-d);
		printf("x1 = %f  %+f i \t x2 = %f  %+f i \n" , -b/(2*a), raizd/(2*a),-b/(2*a), -raizd/(2*a));
	}
}

int main ()
{
	float a, b, c;
	int Respuesta;
	ConfiguraIdioma();
	portada();
	do{
		system("cls");
		printf("Dame los coeficientes de la ecuación cuadrática general a x^2 + b x +c = 0  \n");
		printf("Dame a:");
		scanf("%f",&a);
		printf("Dame b:");
		scanf("%f",&b);
		printf("Dame c:");
		scanf("%f",&c);
		printf("La solución de la ecuación es:\n");
		chicharronera(a,b,c);
		system ("pause");
		printf("¿Quieres repetir? (1=si 0=no): ");
		scanf("%d", &Respuesta);
}	while(Respuesta==1);
	return 0;
}



