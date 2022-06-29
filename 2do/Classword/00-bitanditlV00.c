#include <stdio.h>
 
int main () 
{
   int a= 23; //0010111
  int b = 90; //1011010
  int resultado;
  printf("a = %d y b = %d\n", a, b); // & solo si es 1 y 1 es 1 lo demas es 0
  resultado = a & b; //0010010
  printf("a & b  = %d\n",resultado);
  return 0;
}
