#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

# define EXTRACT_BIT(n , i ) (((n)&(1<<(i)))?1:0)
//Permite extraer el binario de un numero
void check_circuit (int proc_id ,int inputval); //proceso para checar el circuito 

int main(int argc, char *argv []){ //main con arreglos para recibir los datos
    int numHilos=strtol(argv[1], NULL, 10); //numero de hilos
    int i; //contador
    int n=65536; //2**16 A,B,...,O,P
    //Iniciamos la porgramacion arapelal con OpenMP, con i privado y n publico y gestionando dinamicamente los hilos
    #pragma omp parallel for num_threads(numHilos) private(i) shared(n) schedule(static,1)
    for ( i = 0 ; i < n; i++ ){  //for con todas las posibles combinaciones
        int my_rank=omp_get_thread_num(); // obtenemos el rank
        check_circuit( my_rank , i ); //mandamos el rank e i a la funcion
        fflush( stdout );//realizamos limpieza del buffer
    }

    return 0;
}

void check_circuit(int proc_id ,int inputval){ //proceso para checar el circuito
    short v [16]; // creamos un short para almacenar el valor en bits
    int i ; //creamosun contador

    for ( i = 0; i < 16; i ++ ){ //optenemos los 0 y 1
        v[i] = EXTRACT_BIT(inputval ,i );//Usamos la funcion EXTRACT_BIT
    }

    if ( ( (v[0] || v[1]) && (!v[1] || !v[3]) && (v[2] || v[3])
       && (!v[3] || !v[4]) && (v[4] || !v[5])
       && (v[5] || !v[6]) && (v[5] || v[6])
       && (v[6] || !v[15]) && (v[7] || !v[8])
       && (!v[7] || !v[13]) && (v[8] || v[9])
       && (v[8] || !v[9]) && (!v[9] || !v[10])
       && (v[9] || v[11]) && (v[10] || v[11])
       && (v[12] || v[13]) && (v[13] || !v[14])
       && (v[14] || v[15]) ) ) {//circuito y condicion de validez
        printf ("%d: %d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d \n ", proc_id,
        v[0] , v[1], v[2], v[3], v[4], v[5], v[6], v[7], v[8], v[9], v[10], v[11], v[12], v[13], v[14], v[15]); //si el circuito se activa imprime la combinación
        fflush ( stdout ) ;//realizams limpieza del buffer
    }
 }
