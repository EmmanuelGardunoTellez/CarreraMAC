#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
int numeroDeHilos;
int n = 100;
int *numeros;
pthread_mutex_t count_mutex;
long long count;

void
increment_count()
{
	    pthread_mutex_lock(&count_mutex);
    count = count + 1;
	    pthread_mutex_unlock(&count_mutex);
}
void* Thread_sum(void* rank);
int main(int argc, char*  argv[]){
	long hilo;
	pthread_t* manejadorDeHilos;
	numeros = malloc(n*sizeof(int));
	/*obten el numero de hilos d ela linea de comandos*/
	int i, con=0;
	for(i=0;i<n;i++){
		numeros[i]=1;
	}
	numeroDeHilos=strtol(argv[1],NULL,10);
	
	manejadorDeHilos=malloc(numeroDeHilos*sizeof(pthread_t));
	
		for (hilo = 0; hilo < numeroDeHilos; hilo++){
			pthread_create(&manejadorDeHilos[hilo],NULL,Thread_sum,(void*)hilo);
		}
		
		
		for (hilo = 0; hilo < numeroDeHilos; hilo++){
			pthread_join(manejadorDeHilos[hilo],NULL);
		}
		
	printf("Primos: ");
	for (i = 0; i < n; i++){
		if (numeros[i]){
			printf("%d  ",i);
			con++;
		}
	}
	printf("Contador %d",con);
		
		free(numeros);
		free(manejadorDeHilos);
		
		return 0;
}
void* Thread_sum(void* rank){  
	long my_rank = (long) rank;    
	long long i;  
	long long my_n = n/numeroDeHilos;  
	long long my_first_i = my_n*my_rank;  
	long long my_last_i = my_first_i + my_n;
	
	pthread_mutex_lock(&count_mutex);
   	for (i = my_first_i; i < my_last_i; i++){   
   			if(numeros[n]==1){
   				for(i=n*n;i<n;i+=n){
   					numeros[i]=0;
   					printf("%lld: %d --%ld\n",i, numeros[i],my_rank);
				   }
			   }
  		    printf("%lld: %d --%ld\n",i, numeros[i],my_rank);
  		}
    pthread_mutex_unlock(&count_mutex);
  	return NULL;
  }
