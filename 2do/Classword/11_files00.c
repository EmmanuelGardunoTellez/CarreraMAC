/* ********************* TEXTO SIN ACENTOS *********************/
// Recuerda documentar tus codigos
#include<stdio.h>

int main(){
  FILE * fptr;
	char cadr;


fptr = fopen("11-fles00.txt","a"); //Crea un archivo

puts("Escribe algo (un caracter)\n"); //Escribe un caracter

scanf("%c", &cadr);

fprintf(fptr,"El caracter es...%c\n", cadr); //Guarda un caracter

fclose(fptr);
  return 0;
}
