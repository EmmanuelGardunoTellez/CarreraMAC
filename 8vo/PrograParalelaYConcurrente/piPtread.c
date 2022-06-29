#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
int numeroDeHilos;
int n = 10000;
double sum = 0.0;
void* Thread_sum(void* rank);
int main(int argc, char*  argv[]){
	long hilo;
	pthread_t* manejadorDeHilos;
	
	/*obten el numero de hilos d ela linea de comandos*/
	
	numeroDeHilos=strtol(argv[1],NULL,10);
	
	manejadorDeHilos=malloc(numeroDeHilos*sizeof(pthread_t));
	
		for (hilo = 0; hilo < numeroDeHilos; hilo++){
			pthread_create(&manejadorDeHilos[hilo],NULL,Thread_sum,(void*)hilo);
		}
		
		printf("Hola del hilo principal\n");
		
		for (hilo = 0; hilo < numeroDeHilos; hilo++){
			pthread_join(manejadorDeHilos[hilo],NULL);
		}
		double pi=4*sum;
		printf("Pi es: %f",pi);
		free(manejadorDeHilos);
		
		return 0;
}
void* Thread_sum(void* rank){  
	long my_rank = (long) rank;  
	double factor, my_sum=0.0;  
	long long i;  
	long long my_n = n/numeroDeHilos;  
	long long my_first_i = my_n*my_rank;  
	long long my_last_i = my_first_i + my_n;
	
  	if (my_first_i % 2 == 0)   
  		factor = 1.0;  
	else
        factor = -1.0;
	
   	for (i = my_first_i; i < my_last_i; i++, factor = -factor){    
  		   my_sum += factor / (2 * i + 1); // sección crítica    
  		}
  		sum += my_sum;
  	return NULL;
  }
