/* ********************* TEXTO SIN ACENTOS *********************/
// Recuerda documentar tus codigos

#include <stdio.h>
#include <stdlib.h>

int main () {

   char cad1[10], cad2[10], cad3[10]; //Para almacenar las palabras
   int gru; //almacenar el numero
   FILE * fp; 
   FILE * fp2;


   fp = fopen ("12-files.txt", "a+t"); //Crea un archovo de texto que no borra el contenido
   fp2 = fopen ("12-files200.txt", "a+t"); //Crea un archovo de texto que no borra el contenido
   fputs("Somos el grupo 2202", fp); //El carácter nulo no es escrito.
   rewind(fp);//Apunta a el inicio del texto
   fscanf(fp, "%s %s %s %d", cad1, cad2, cad3, &gru); //Recoge cada caracter

   //printf("Lee la cadena 1 |%s|\n", cad1 ); //Imprime cada palabra por separado
   //printf("Lee la cadena 2 |%s|\n", cad2 );
   fprintf(fp2,"Lee la cadena 3 |%s|\n", cad3 );
   //printf("Lee la cadena 4 |%d|\n", gru );

   fclose(fp);  //Cierra los textos
   fclose(fp2);
   
   return 0;
}

