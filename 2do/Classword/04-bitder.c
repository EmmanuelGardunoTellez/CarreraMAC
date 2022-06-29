/* ********************* TEXTO SIN ACENTOS *********************/
// Recuerda documentar tus codigos

#include <stdio.h>
 
int main () 
{
  int a= 86;
  int resultado;
  printf("a = %d\n", a);
resultado = a>>1; //Recorre 1 numero
 printf("a>>1 =  %d\n",resultado); //Mustra el nuemro recorrido que sale

resultado = a>>2; //Recorre 2 numero
 printf("a>>2 =  %d\n",resultado); //Mustra el nuemro recorrido que sale

resultado = a>>3; //Recorre 3 numero
 printf("a>>3 =  %d\n",resultado); //Mustra el nuemro recorrido que sale

resultado = a>>4; //Recorre 4 numero
 printf("a>>4 =  %d\n",resultado); //Mustra el nuemro recorrido que sale
 
 resultado = a>>5; //Recorre 5 numero a la derecha
 printf("a>>5 =  %d\n",resultado); //Mustra el nuemro recorrido que sale
  return 0;
}
