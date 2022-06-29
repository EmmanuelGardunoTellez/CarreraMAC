#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<mpi.h>
#define MAESTRO 0

const int MAX_STRING= 1000; //tamaño del arreglo

int main(void){ 
	
	int arreglo_enteros[MAX_STRING]; //arreglo de enteros
	int comm_sz; //numero del proceso
	int my_rank;//nombre del proceso
	for (int i=0;i<MAX_STRING;i++){ //asigna valores
		arreglo_enteros[i]=rand() % 100;
	}
	
	MPI_Init(NULL, NULL); //iniciamos MPI
	MPI_Comm_size(MPI_COMM_WORLD,&comm_sz);
	MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);

	
	int tareas= comm_sz%2; //dividimos entre 2 el tamaño y obtenemos la parte entera
	int tamanoDePedazos = (MAX_STRING/comm_sz); //vemos en cuantos pedazos lo vamos a dividir
	int recorrido=tamanoDePedazos; //ponemos cuantasveces va a recorrer
	
	if(tareas!=0){
		if(my_rank==MAESTRO){ //si el numero de tareas es impar
			printf("Saliendo del sistema. se necesita un numero par de tareas: numeros de tareas=%d\n",comm_sz);
		}
	} else { //si las tareas son pares
		if(my_rank==MAESTRO){ //el maestro
			int suma=0;
			for(int i=0;i<tamanoDePedazos;i++){
				suma+=arreglo_enteros[i];
			}
			printf("Suma del proceso maestro %d \n",suma);
			for(int q=1;q<comm_sz;q++){
				MPI_Send(&recorrido,1,MPI_INT,q,0,MPI_COMM_WORLD);
				MPI_Send(&arreglo_enteros[recorrido],tamanoDePedazos,MPI_INT,q,0,MPI_COMM_WORLD);
			}
			int resultados_de_las_tareas=0;
			for(int q=1;q<comm_sz;q++){
				MPI_Recv(&resultados_de_las_tareas,1,MPI_INT,q,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
				suma+=resultados_de_las_tareas;
			}
			printf("suma total %d \n", suma);
		}
		if(my_rank>MAESTRO){ //esclavos
			int suma=0; //definimos suma
			MPI_Recv(&recorrido,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE); //recibimos el recorrido
			//recibimos el arreglo con los numeros
			MPI_Recv(&arreglo_enteros[recorrido],tamanoDePedazos,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
			for(int i=0;i<tamanoDePedazos;i++){ //sumamos los valores asignados en el recorrido
				suma+=arreglo_enteros[recorrido+1];
			}
			int hola[]={1,2,3,4}; //definimos hola
			printf("Suma Parcial del Proceso del proceso %d es %d \n",my_rank,suma); 
			//imprimimos el valor obtenido del esclavo
			MPI_Send(&suma,1,MPI_INT,0,0,MPI_COMM_WORLD); //mandamos la suma del esclavo al maestro
		}
	}
	
	MPI_Finalize(); //acabamos MPI
	return 0;
}
