/* ********************* TEXTO SIN ACENTOS *********************/
// Recuerda documentar tus codigos

#include <stdio.h>

const int MAX = 3;//Cosntante para todo el codigo similar a define

int main () { 

   int  var[] = {10, 100, 200};//Variable con arreglos vacia
   int  i, *ptr; //Contador y apuntador

   ptr = &var[MAX-1]; //Asignacion de los arreglos a un apuntador
	
   for ( i = MAX; i > 0; i--) {//Al repetir el ptr se pone a la ubicacion, y al repetir se pone la sigiente asignacion
      printf("Direccion de var[%d] = %p\n", i-1, ptr );
      printf("\t\t\tValor de var[%d] %d\n", i-1, *ptr );
      ptr--;
   }
	
   return 0;
}
