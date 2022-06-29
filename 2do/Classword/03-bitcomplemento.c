#include <stdio.h>
 
int main () 
{
  int a= 4; //100
  int resultado;
  printf("a = %d\n", a);
  resultado = ~a; //-(4+1) =0101
  printf("~a = %d\n",resultado);
  return 0;
}

