#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<sys/stat.h>/**/
#include<math.h>
#include<fcntl.h>/**/
#include<unistd.h>/**/
int numeroDeHilos; //numero de hilos
int n = 4,m=4; //cantidad de elementos para calcular pi
int i,j; //nota solo funciona si el numero de hilos es igual a n
int **Ma;//gcc -g -Wall -o salida matrizpthread.c -lpthread
int **Mb;// ./salida n
int **Mc; //matrices


void* Thread_sum(void* rank); //funcion que hace los hilos
int main(int argc, char*  argv[]){
	int k,l;//cntadores
	Ma = malloc(n*sizeof(int*));//le ponemos las dimencionas a la matriz A 
    	for(i=0;i<m;i++)
    		Ma[i]=malloc(m*sizeof(int));

    Mb = malloc(n*sizeof(int*)); //le ponemos las dimencionas a la matriz B
    	for(i=0;i<m;i++)
        	Mb[i]=malloc(m*sizeof(int)); 
  
	Mc =  malloc(n*sizeof(int*)); //le ponemos las dimencionas a la matriz C
    	for(i=0;i<n;i++)
        Mc[i]=malloc(m*sizeof(int));
	for( i=0; i<n; i++ ){//generamos los numeros aeatorios
    for( j=0; j<m; j++ ){
        Ma[i][j] = rand()%10;
        Mb[i][j] = rand()%10;
		Mc[i][j] = 0;
	}
}
	long hilo;
	pthread_t* manejadorDeHilos; //manejador de hilos	
	numeroDeHilos=strtol(argv[1],NULL,10);//recuperamos el numero de hilos 
	manejadorDeHilos=malloc(numeroDeHilos*sizeof(pthread_t));//creamos espacio para los hilos
		for (hilo = 0; hilo < numeroDeHilos; hilo++){//creamos los hilos
			pthread_create(&manejadorDeHilos[hilo],NULL,Thread_sum,(void*)hilo);
		}		
		for (hilo = 0; hilo < numeroDeHilos; hilo++){//unimos los hilos
			pthread_join(manejadorDeHilos[hilo],NULL);
		}
    printf("Matriz A: \n"); //Imprime matriz A
    for( k=0; k<n; k++ ){
        for( l=0; l<n; l++ ){
            printf( " %i ", Ma[k][l] );
        } 
    printf( "\n");
    } 
    printf("Matriz B: \n"); //Imprime matriz B
    for( k=0; k<n; k++ ){
        for( l=0; l<n; l++ ){
            printf( " %i ", Mb[k][l] );
        } 
    printf( "\n");
    } 
    printf("Matriz C: \n"); //Imprime matriz C
    for( k=0; k<n; k++ ){
        for( l=0; l<n; l++ ){
            printf( " %i ", Mc[k][l] );
        } 
    printf( "\n");
    } 
    free(manejadorDeHilos);//liberamos hilos
    free(Ma);
  	free(Mb);
  	free(Mc);
	return 0;
}
void* Thread_sum(void* rank){  
	long my_rank = (long) rank;  //contador de rank
	int i, j,a;
	int local_m = m/numeroDeHilos;
	int my_first_row = my_rank*local_m;
	int my_last_row = (my_rank+1)*local_m - 1;
	
	for (a = my_first_row; a <= my_last_row; a++){
		for (i = 0; i < n; i++) {
			int suma = 0;// Y cada columna de la primera (A)
            for (j = 0; j < n; j++) {
                suma += Ma[i][j] * Mb[j][a];// Multiplicamos y sumamos resultado
            }
            Mc[i][a] = suma;// Lo acomodamos dentro del producto
        }
	}	



  	return NULL;
  }

