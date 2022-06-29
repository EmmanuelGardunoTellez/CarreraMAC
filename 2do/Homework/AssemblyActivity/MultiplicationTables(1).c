#include<stdlib.h>
#include<stdio.h>

int main()
{
	int tabla, numero, resultado;
	printf ("Tablas de multiplicar\n\n");
	for (tabla=1;tabla<=10;tabla=tabla+1)//Te da el numera para la tabla
	{
		printf ("\nTabla\n", tabla); //Para separar las tablas qeu hay
		for (numero=1;numero<=10;numero++)//Inicia el contador para multiplicar por el de la tabla
		{
			resultado=tabla*numero;
			printf ("%dx%d=%d\n", tabla, numero, resultado);  //Muestra lso numeros qeu  salen al multiplicar
		}
	}
	system ("pause");
}
