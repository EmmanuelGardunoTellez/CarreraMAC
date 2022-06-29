#include <stdio.h>

int main ()
{
  FILE *archivo;
  archivo = fopen ( "pruebaHOLA.txt", "a" ); //crea y abre el documento
  fprintf(archivo, "HOLA MUNDO"); //Mete el texto en el archivo creado
  fclose ( archivo ); //Cierra el archivo

  return 0;
}
