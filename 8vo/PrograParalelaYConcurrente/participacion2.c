#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
/*
gcc -s -wall -fopenmp -o par2 participacion2.c
./par2.exe 4
*/
int main(int argc, char *argv[]){
	int numeroDeHilos=strtol(argv[1],NULL,10);
	int resultado=0;
	int a=10,b=20;
	#pragma omp parallel num_threads(numeroDeHilos)
	{
		int mi_resultado=0;
		mi_resultado=a+b;
		#pragma omp critical
		resultado += mi_resultado;
	}
	printf("El resultado de la operacion es %d", resultado);
    return 0;
}
