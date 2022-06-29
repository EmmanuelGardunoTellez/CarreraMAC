#include <stdio.h>
 
int main () 
{
  int a;
  int b = 8; //1000

  printf("Introduzca un numero\n");
  scanf("%d",&a);

  printf("Comparamos con un binario para conocer el cuarto bit\n");
  printf("Los numeros son: a = %d & b = %d\n", a, b);
	
if(a & b){ // solo si paarace el 1000 marca que el bit es 1 de locontrario 0
  printf("El cuarto bit es 1 \n");
}else{
  printf("El cuarto bit es 0 \n");
}

  return 0;
}

