#include <stdio.h>
#define N 5
int main () {

   int  var1, i; //tipo de variable, definicion de variable
   char var2[N]; //tipo de variable, definicion de variable

   printf("Direccion de la variable var1: %X\n", &var1  ); //Uso de la variable, operador de dirrecions de memoria (&), acceder al valor esando apuntador, operador de referencia y de deferenca & y *
   printf("Direccion de la variable var2: %X\n", &var2  ); //Uso de la variable, operador de dirrecions de memoria (&), acceder al valor esando apuntador, operador de referencia y de deferenca & y *
for(i=0; i<N; i++){
   printf("Direccion de la variable var2[%i]: %X\n", i, &var2[i]  ); //acceder al valor usando un operador de asignacion de memoria, operador de referencia y de deferenca &
   }
   //declaracion una variable apuntador n hay, no existe
   //direccion guardada en la variable apuntador no esta declarada
   return 0;
}
/*
tipo de variable	int y char
direccion de variable var1 y var2
uso (llamada) de la variable N
operador de direcciones de memoria &vvvv
 "%X", &var2 


 &var1


*/
