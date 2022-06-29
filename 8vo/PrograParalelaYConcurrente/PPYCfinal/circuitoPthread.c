#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

# define EXTRACT_BIT(n , i ) (((n)&(1<<(i)))?1:0)
//Permite extraer el binario de un numero
int numeroDeHilos;//numero de hilos

void check_circuit (int proc_id ,int inputval);//proceso para checar el circuito 
void* Hilos(void* rank); //Funcion del Hilo

int main(int argc, char*  argv[]){

	long hilo;
	pthread_t* manejadorDeHilos;
	
	/*obten el numero de hilos d ela linea de comandos*/
	
	numeroDeHilos=strtol(argv[1],NULL,10);//obtiene el numero de hilos
	
	manejadorDeHilos=malloc(numeroDeHilos*sizeof(pthread_t));//creamos espacio para los hilos
	
		for (hilo = 0; hilo < numeroDeHilos; hilo++){//creamos los hilos
			pthread_create(&manejadorDeHilos[hilo],NULL,Hilos,(void*)hilo);//lo mandamos a la funcion HILOS
		}
		
		for (hilo = 0; hilo < numeroDeHilos; hilo++){//unimos los hilos
			pthread_join(manejadorDeHilos[hilo],NULL);
		}
		
		free(manejadorDeHilos);//liberamos los hilos
		
		return 0;
}

void* Hilos(void* rank)
{
	long my_rank=(long)rank;//obtenemos el rango
    int i ;//contador
    for ( i = my_rank ; i < 65536; i += numeroDeHilos ){//for con todas las posibles combinaciones
        check_circuit( my_rank , i );//mandamos el rank e i a la funcion
    }
    printf ("Proceso %ld termino\n " , my_rank );
    fflush ( stdout );//realizamos limpieza del buffer
	return NULL;
}

void check_circuit(int proc_id ,int inputval){
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
        v[0] , v[1], v[2], v[3], v[4], v[5], v[6], v[7], v[8], v[9], v[10], v[11], v[12], v[13], v[14], v[15]);
        fflush ( stdout ) ;//realizams limpieza del buffer
    }
 }
