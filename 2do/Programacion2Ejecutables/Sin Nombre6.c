#include <stdio.h>

int main () {

   float  vari1 = 20, vari2 = 10,vari3 = 200; //se agrega la variable var
   float  *ip1, *ip2, *ip3; //Se crea apintador con deferencia

   ip1=&vari1;  ip2=&vari2;  ip3=&vari3; //Se asigna a los apuntadores las direcciones de memoria de cada una de ellas

   printf("Suma: %f\n",*ip1+*ip2+*ip3); //Suma con apuntadores
   printf("Resta: %f\n",*ip1-*ip2-*ip3); //Restas con apuntadores
   printf("Multiplicacion: %f\n",*ip1**ip2**ip3); //Multiplicacion con apuntadores
   printf("Division: %f\n",*ip2/(*ip1)); //Division con apuntadores
   
   printf("%f\n", *ip1);//Valores de cada variable
   printf("%f\n", *ip2);
   printf("%f\n", *ip3);
   
   printf("%f\n", vari1);//Lo mismo de arriba
   printf("%f\n", vari2);
   printf("%f\n", vari3);
   

   return 0;
}
