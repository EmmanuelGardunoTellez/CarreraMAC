/* ********************* TEXTO SIN ACENTOS *********************/
// Recuerda documentar tus codigos

#include <stdio.h>
#include <string.h>

struct {
   unsigned int age : 4; //Solo permite almacenar hasta 4 valores en binario mas grande de 1111 ya no puede 
} Age;

int main( ) {

   Age.age = 4;
   printf( "Sizeof( Age ) : %d\n", (int)(sizeof(Age)) );

   printf( "Age.age : %d\n", Age.age );

   Age.age = 7;
   printf( "Age.age : %d\n", Age.age );

   Age.age = 8;
   printf( "Age.age : %d\n", Age.age );

   Age.age = 63;
   printf( "Age.age : %d\n", Age.age );

   return 0;
}
