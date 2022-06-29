#include <stdio.h>
#include <stdlib.h>
#define C 6

main()
{
	int i;
	float numbers[C] = {[1]=10.00,[2]=105.30}; //numeros almacenados para ocuparse despues, los demas no estan asignados por ende pueden ser 0 o un numero qeu asigne la pc
	for(i=0;i<C;i++){
		printf("%f   ",numbers[i-1]); //muestra los numeros almacenados en el arreglo
	}	
}
