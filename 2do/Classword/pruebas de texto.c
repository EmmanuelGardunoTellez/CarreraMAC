#include <stdio.h>

int main ()
{
  FILE *archivo;

  char caracter;


  archivo = fopen ( "prueba.txt", "a" ); //Abre un archivo texto nuevo

  printf("\nIntroduce un texto: \n");


  while((caracter = getchar()) != '\n')
    {
	fputc(caracter, archivo); //Gardar texto en un archivo
    }


 fclose ( archivo ); //Cierra el archivo

  printf("\nRevisa el archivo prueba.txt\n");

  return 0;
}
