
/* ********************* TEXTO SIN ACENTOS *********************/
// Recuerda documentar tus codigos

#include <stdio.h>

int main () {
  FILE * fptr;
  char cr[100];

  fptr = fopen("10-files00.txt","r"); //Abre un archivo de texto solo lectura
   if(fgets(cr, 100, fptr)!=NULL) {
      puts(cr); //Imprime todos los caracteres del texto
   }
fclose(fptr);
   
   return(0);
}
