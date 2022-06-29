#include <mpi.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#define BLOCK_LOW(my_rank, p, n) ((my_rank)*(n)/(p))
#define BLOCK_SIZE(my_rank, p, n) (BLOCK_LOW((my_rank)+1, p, n)-BLOCK_LOW((my_rank), p, n))
#define BLOCK_OWNER(index, p, n) (((p)*((index)+1)-1)/(n))
#define MIN(a,b) ((a)<(b)?(a):(b))
//libro


int main(int argc, char *argv[]){
	int count;				
	// Contador de primos
	double time;	
	// tiempo de ejecucion 
	int primer_m;				
	// primer multiplo
	int global_count;		
	// total de primos
	int my_rank;			
	//NUMERO DE PROCESO
	int indice;				
	// NUMERO global de números primos
	int valor_bajo;			
	// Valor más bajo en este proceso
	char *marked;			
	// casillas marcadas 2, ..., n
	int n; 					
	// TAMIZ DE 2, ..., n
	int p;					
	// Numero de proceso
	int proc0_size;			
	// tamanio del subarreglo
	int primo;				
	//primo actual
	int size;				
	// elementos marcados

	MPI_Init(&argc, &argv);
	// temporizador
	MPI_Barrier(MPI_COMM_WORLD);
	//MPI_Barrier:Bloquea al proceso hasta que todos 
	//los procesos pertenecientes al comunicador especificado lo ejecuten.
	time = -MPI_Wtime();
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &p);
	if(argc!=2){
		if(!my_rank)
			printf("Command line: %s <m>\n", argv[0]);
		MPI_Finalize();
		exit(1);
	}	
	n=atoi(argv[1]);
	//atoi es una función que permite
	// convertir una cadena de caracteres (char) a una variable entera (int)
	valor_bajo=2+BLOCK_LOW(my_rank, p, n-1);
	size=BLOCK_SIZE(my_rank, p, n-1);

	proc0_size = (n-1)/p;

	if((2+proc0_size) < (int) sqrt((double) n)){
		if(!my_rank)
			printf("demasiados procesos\n");
		MPI_Finalize();
		exit(1);
	}
	// Alocate this process's share of the array
	marked = (char*) malloc (size);
	if(marked == NULL){
		printf("No se puede asignar suficiente memoria\n");
		MPI_Finalize();
		exit(1);
	}
	for(int i=0;i<size;i++)
		marked[i]=0;
	if(!my_rank)
		indice = 0;
	primo=2;
	do{
		if (primo * primo > valor_bajo)
			primer_m = primo * primo - valor_bajo;
		else
			if(!(valor_bajo%primo))
				primer_m =0;
			else
				primer_m = primo -(valor_bajo %primo);
		for(int i=primer_m;i<size;i+=primo)
			marked[i]=1;
		if(!my_rank){
			while(marked[++indice]);
			primo=indice+2;
		}
		MPI_Bcast(&primo, 1, MPI_INT, 0, MPI_COMM_WORLD);
	}while(primo*primo<=n);

	//conteo de primos
	count =0;
	for(int i=0;i<size;i++){
		if(!marked[i])
			count ++;
	}
	MPI_Reduce(&count, &global_count, 1, MPI_INT, MPI_SUM, 
		0, MPI_COMM_WORLD);
	// aqui se detiene el temporizador de la linea 41 
	time += MPI_Wtime();
	if(!my_rank){
		printf("hay %d numeros primos de 0 a  %d\n", 
			global_count, n);
		printf("Total tiempo de ejecucion: %10.6f\n",time);
	}
	MPI_Finalize();
	return 0;
}
// mpicc -g -Wall -std=c99 -o sieveMPI2 sieveMPI2.c -lm
// mpiexec -n 4 sieveMPI2 100