#include<stdio.h>

int main(){
  int array_values[10]={0,1,4,9,16}; //Arreglo y valores agregados antes de las operaciones
  int i;

  for(i=5;i<10;++i){ //Inicia el conteo de los numeros
    array_values[i]=i*i; //Saca el cuadrado de un numero que vale i
  }

  for(i = 0; i<10;++i){
    printf("array_values[%i]=%i\n", i, array_values[i]); //Muestar los valores sacados en la operacion de arriba
}

  return 0;
}
