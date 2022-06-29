/* ********************* TEXTO SIN ACENTOS *********************/
// Recuerda documentar tus codigos

#include<stdio.h>

int main(){
  FILE * fptr;

  char cad[200] = "Este es un nuevo mundo, una forma de vivir, un lugar mejor con una nueva actitud"; //Texto almacenado en un arreglo

  fptr = fopen("10-files00.txt","w"); //Abre docuemnto de texto para escribir
  fputs(cad, fptr); //Se mete el texto en el archivo

fclose(fptr); //Se cierra el archivo de texto
  return 0;
}
