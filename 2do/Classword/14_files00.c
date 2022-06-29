/* ********************* TEXTO SIN ACENTOS *********************/
// Recuerda documentar tus codigos


#include <stdio.h>

int main () {

   FILE * fp;

   fp = fopen("14-files00.txt","w+t"); //Abre un tecxto para escribir
   fputs("pokemon kimi ni kimi eta", fp); //Primera frase metida en el texto
  
   fseek( fp, 16, SEEK_SET); //Se mete el texto al archivo y despues e apunta al espacio no 16

   fputs("de programacion en C.", fp); //Se mete el otro texto

   fclose(fp); //Se cierra el texto
   
   return(0);
}
