#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

void encriptacion (char *, int);

int main ()
{
	ConfiguraIdioma();
	portada ();
	int Respuesta, encri;
	char frase[25];		//reserva 25 chars juntos,  crea el puntero frase=&frase[0]
	do{
	printf("\nEl siguiente programa encripta las frases recorriendo su valor 10 números en el código ASCII\n\n");
	printf("Dame la frase a encriptar \n\n");
	fflush(stdin);
	gets(frase);	//Me guarda lo que escribí en el teclado y lo guarda en frase
	do{
	printf("\nEste codificador usa el codigo ascii para codificarlo, ingrese un numero de -10 a 10 para hacer la encriptacion: ");
	scanf("%d",&encri);
	}while(encri < -10 || encri > 10);
	encriptacion(frase, encri); // Encripta "frase" cuando le paso el puntero frase
	printf("\nLa frase encriptada es:\n\n%s\n\n", frase); // Imprime la frase encriptada
	printf("¿Quieres repetir? (1=si 0=no)");
	scanf("%d", &Respuesta);
}while(Respuesta==1);
	return 0;
}

void encriptacion(char *p,int despl)

{
	while(*p!='\0')
	{
		*p=*p+despl;
		p++; //p=p+1;
	}
	
}
