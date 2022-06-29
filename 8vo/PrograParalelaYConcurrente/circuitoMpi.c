#include <stdio.h>
#include <mpi.h>

# define EXTRACT_BIT(n , i ) (((n)&(1<<(i)))?1:0)
//Permite extraer el binario de un numero

void check_circuit (int proc_id ,int inputval); //proceso para checar el circuito 

int main(void){
    
	int comm_sz; //numero d procesos
	int my_rank; //nombre del proceso
	int i ; //contador

	MPI_Init(NULL,NULL); //iniciamos MPI
	MPI_Comm_size(MPI_COMM_WORLD,&comm_sz);
	MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);
	
	for ( i = my_rank ; i < 65536; i += comm_sz ){//creamos un for que empieza con el rango y va aumentando por el numero de procesos
        check_circuit( my_rank , i ); //mandamos a la funcion el numero de proceso y el numero de elemenntos a contar 
    }
    printf ("Proceso %d termino\n " , my_rank ); //Decimos si el proceso i ha terminado
    fflush ( stdout ); //realizams limpieza del buffer
	MPI_Finalize(); //finalizamos MPI
	return 0;
}


void check_circuit(int proc_id ,int inputval){ //proceso para checar el circuito
    short v [16]; //creamos un short para almacenar el valor de los bits
    int i ; //creamos un contador

    for ( i = 0; i < 16; i ++ ){//optenemos los valores de 0 y 1
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
        v[0] , v[1], v[2], v[3], v[4], v[5], v[6], v[7], v[8], v[9], v[10], v[11], v[12], v[13], v[14], v[15]);
        fflush ( stdout ) ; //realizams limpieza del buffer
    }
 }
