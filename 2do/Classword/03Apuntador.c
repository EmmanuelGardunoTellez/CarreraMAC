/* ********************* TEXTO SIN ACENTOS *********************/
// Recuerda documentar tus codigos

 #include <stdio.h>

const int MAX = 3; //Cosntante para todo el codigo similar a define

int main () {

   int  var[3] = {10, 100, 200}; //Variables en un  arreglo
   int  i, *ptr; //Contador y apuntador

   ptr = var; //El apuntador se le asigna todo el arreglo

   for ( i = 0; i < MAX; i++) { //Al repetir el ptr se pone a la ubicacion, y al repetir se pone la sigiente asignacion
      printf("Direccion de var[%d] = %p\n", i, ptr );
      printf("\t\t\tValor de var[%d] = %d\n", i, *ptr );
      ptr++;
   }
	
   return 0;
}
