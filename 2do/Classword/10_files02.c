/* ********************* TEXTO SIN ACENTOS *********************/
// Recuerda documentar tus codigos

#include <stdio.h>
#include <stdlib.h>
#define n 10
int main () {
  FILE * fptr;
  char * cr; //Apuntador para texto
  cr=(char*) malloc(n*sizeof(cr)); //Se limita a tanto el texto

  fptr = fopen("10-files00.txt","r"); //Abre docuemnto de texto para escribir
   if(fgets(cr,n*sizeof(cr), fptr)!=NULL) {
      puts(cr); //Imprime todos los caracteres del texto
   }

fclose(fptr); //Cierra el archivo de texto
   
   return(0);
}
