#include<stdlib.h>
#include<pthread.h>
#include<stdio.h>
#define LIMITE 100

//Criba de Erat�stenes
int numeroDeHilos; //numero de hilos
int *numeros;
void* Thread_sum(void* rank);
int main(int argc, char** argv){
	numeros = malloc(LIMITE*sizeof(int));
	//Obtener las lista de n�meros a evaluar
	int i;
	int j,n,con=0;
	for(i=2;i<LIMITE;i++){
		numeros[i]=1;
	}
	//Hacer 2 el primer n�mero primo
	numeros[2]=1;
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

	//Muestro la lista de los primos	
	printf("Primos: ");
	for (n = 2; n < LIMITE; n++){
		if (numeros[n]){
			printf("%d  ",n);
			con++;
		}
	}
	printf("Contador %d",con);
    free(numeros);
	return 0;
}
void* Thread_sum(void* rank){  
	long my_rank = (long) rank;  //contador de rank
//	double factor, my_sum=0.0;  
	long long i;  
	long long my_n = LIMITE/numeroDeHilos;  
	long long my_first_i = my_n*my_rank;  
	long long my_last_i = my_first_i + my_n;
	long long n;
	//Recorrer los n�meros y para cada uno
	for (n=my_first_i;n<my_last_i;n++){
//Si es primo recorrer los m�ltiplos y marcarlos como no primo
		if (numeros[n]){
			for (i=n*n;i<my_last_i;i+=n){
				numeros[i] = 0;
				printf("%lld: %d\n",i,numeros[i]);
			}
			printf("\n=========================\n");
		}
	}


  	return NULL;
  }