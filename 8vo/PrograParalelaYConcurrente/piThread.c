#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<sys/time.h>
#include<math.h>
#include<unistd.h>
int numeroDeHilos; //numero de hilos
int n = 10000; //cantidad de elementos para calcular pi
double sum = 0.0; //suma de los elementos
double get_time(void); //contador de tiempo 
void* Thread_sum(void* rank); //funcion que hace los hilos
int main(int argc, char*  argv[]){
	long hilo;
	pthread_t* manejadorDeHilos; //manejador de hilos	
	numeroDeHilos=strtol(argv[1],NULL,10);//recuperamos el numero de jilos 
    double time1 = get_time();//iniciamos el contador	
	manejadorDeHilos=malloc(numeroDeHilos*sizeof(pthread_t));//creamos espacio para los hilos
		for (hilo = 0; hilo < numeroDeHilos; hilo++){//creamos los hilos
			pthread_create(&manejadorDeHilos[hilo],NULL,Thread_sum,(void*)hilo);
		}		
		for (hilo = 0; hilo < numeroDeHilos; hilo++){//unimos los hilos
			pthread_join(manejadorDeHilos[hilo],NULL);
		}
		double pi=4*sum; //por 4 la suma
        double time2 = get_time(); //paro tiempo
		printf("Pi es: %f",pi);
		free(manejadorDeHilos);
		printf("\n \n Tiempo transcurido: %.10lf\n", time2 - time1);
		return 0;
}
void* Thread_sum(void* rank){  
	long my_rank = (long) rank;  //contador de rank
	double factor, my_sum=0.0;  //factor y suma local
	long long i;  //contador
	long long my_n = n/numeroDeHilos;//cantidad de i numeros  
	long long my_first_i = my_n*my_rank;  // numero donde inicia
	long long my_last_i = my_first_i + my_n;//numero donde para
	
  	if (my_first_i % 2 == 0)//decide si factor par o impar   
  		factor = 1.0;  
	else
        factor = -1.0;
	
   	for (i = my_first_i; i < my_last_i; i++, factor = -factor){    //serie donde se optien pi
  		   my_sum += factor / (2 * i + 1); // seccion critica
  		}
  		sum += my_sum;//simamos my_sum a la suma global
  	return NULL;
  }
double get_time(void)//contador de tiempo
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return t.tv_sec + t.tv_usec / 1000000.0;
}
