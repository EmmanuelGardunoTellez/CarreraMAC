#include <stdio.h>

int main () {

   int  var = 20; //se agrega la variable var

   int  *ip; //Se crea apintador con deferencia

   ip = &var;  //se referencia en apuntador la direccion de var

   printf("La direccion de la variable var es: %x\n", &var  );

   printf("La direccion guardada en la variable  ip es: %x\n", ip );
   /*Deferencias (indireccion)*/
   printf("Valor de la variable *ip: %d\n", *ip );
   /*Cambio de * y &*/
   printf("Valor de la variable *ip: %x\n", &ip );
	/*Tamaño del apuntador*/
   printf("%d", sizeof(ip));

   return 0;
}
