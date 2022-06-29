/* ********************* TEXTO SIN ACENTOS *********************/
// Recuerda documentar tus codigos

#include<stdio.h>
int main(){

  FILE * fptr1;
  char c1; //Solo alacena un caracter


  printf("Introduce un caracter \n"); //Escribe un caracter
  scanf("%c", &c1);

  fptr1 = fopen("08-files.txt","w"); //Abre docuemnto de texto para escribir
  fputc(c1, fptr1); //Guarda el caracter en el texto

  fclose(fptr1); //Cierra el archivo



return 0;
}
