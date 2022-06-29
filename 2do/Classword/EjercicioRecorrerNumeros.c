/* ********************* TEXTO SIN ACENTOS *********************/
// Recuerda documentar tus codigos

#include <stdio.h>
 void binario(int a) //Funcion recursiva
{ 
   int aux; 
   if(a==0) 
      return; 

   aux=a%2; 
   a=a/2; 
   binario( a); 
   
   printf("%d",aux); 
 
}
 
int main () 
{
  int a= 86;
  int resultado;
  printf("a = %d =", a); //un numero más
  binario(a); //Muestra el binario del numero
  printf("\n");
resultado = a<<1; //Recorre 1 numero a la izquerda
 printf("a>>1 =  %d =",resultado);
 binario(resultado); //Muestra el binario del numero
 printf("\n");

resultado = a<<2; //Recorre 2 numero a la izquerda
 printf("a>>2 =  %d =",resultado);
binario(resultado); //Muestra el binario del numero
printf("\n");
 
resultado = a<<3; //Recorre 3 numero a la izquerda
 printf("a>>3 =  %d =",resultado);
binario(resultado); //Muestra el binario del numero
printf("\n");

resultado = a<<4; //Recorre 4 numero a la izquerda
 printf("a>>4 =  %d =",resultado);
 binario(resultado);//Muestra el binario del numero
printf("\n");
 resultado = a<<5; //Recorre 5 numero a la izquerda
 printf("a>>5 =  %d =",resultado);
 binario(resultado); //Muestra el binario del numero
printf("\n");
  return 0;
}
