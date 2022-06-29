#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
/*
gcc -s -wall -fopenmp -o par1 participacion1.c
./par1.exe 4
*/
void Suma(int a, int b, int * resultado);
int sumaglobal=0;
int main(int argc, char *argv[]) {
    int nummeroDeHilos=strtol(argv[1], NULL, 10);
    int resultado=0;
    int a=10, b=20;
    #pragma omp parallel num_threads(nummeroDeHilos)
    Suma(a,b,&resultado);
    printf("El resultado de la operacion es %d",resultado);
    return 0;
}
void Suma(int a, int b, int * resultado) {
    int my_rank=omp_get_thread_num();
    int numeroDeHilos=omp_get_num_threads();
    int mi_suma = a+b;
    # pragma omp critical
    	*resultado+=mi_suma;
}
