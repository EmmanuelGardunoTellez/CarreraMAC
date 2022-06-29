#include <stdio.h>
 
int main () 
{
  int a= 23; //0010111
  int b = 90; //1011010
  int resultado;
  printf("a = %d y b = %d\n", a, b);
  resultado = a ^ b; //1001101 = 77
  printf("a ^ b = %d\n",resultado);
  return 0;
}

