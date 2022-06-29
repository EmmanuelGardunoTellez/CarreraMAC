/* ********************* TEXTO SIN ACENTOS *********************/
// Recuerda documentar tus codigos

#include<stdio.h>

int main(){
  FILE * fptr;
  char cr; //Solo alacena un caracter

  fptr = fopen("09-files.txt","r"); //Abre un archivo de texto solo lectura
  cr = fgetc(fptr);  //Garrda el texto en la variable
  fclose(fptr);

  printf("El caracter del archivo es...%c\n", cr);  //Imprime en consola

  return 0;
}
