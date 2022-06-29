#include <stdio.h>
#include <string.h>
#include <mpi.h>
#define MAESTRO		0

const int MAX_STRING=10000;

int main(void){
	int arrreglo_enteros[MAX_STRING];
	int comm_sz;
	int my_rank;
	int sumaResultado=0;
    int prodResultado=0;
    int todosProdResultado=0;
		for(int i=0; i<MAX_STRING; i++){
			arrreglo_enteros[i]=i;
		}
	
	MPI_Init(NULL,NULL);
	MPI_Comm_size(MPI_COMM_WORLD,&comm_sz);
	MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);
	
	int tareas=MAX_STRING%2;
	int tamanioDePedazos=(MAX_STRING/comm_sz);
	int recorrido=tamanioDePedazos;
	
	if(tareas!=0){
		if(my_rank == MAESTRO){
			printf("saliendo del sistema. se necesita un numero par de tareas: numero de tareas= %d\n", comm_sz);
		}
	} else {
		if(my_rank==MAESTRO){
			int suma=0;
            int producto=0;
			//realizamos las operaciones que le corresponde
			for(int i=1;i<comm_sz;i++){
				suma+=arrreglo_enteros[i];				
			}
			printf("suma  de porcesos maestro %d \n", suma);
			
			for(int q=1;q<comm_sz;q++){
				MPI_Send(&recorrido,1,MPI_INT,q,0,MPI_COMM_WORLD);
				MPI_Send(&arrreglo_enteros[recorrido],tamanioDePedazos,MPI_INT,q,0,MPI_COMM_WORLD);
				recorrido=recorrido+tamanioDePedazos;
			}
			
			/*int resultado_de_las_tareas=0;
			for(int q=1;q<comm_sz;q++){
				MPI_Recv(&resultado_de_las_tareas,1,MPI_INT,q,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
				suma+=resultado_de_las_tareas;
			}*/

			MPI_Reduce(&suma,&sumaResultado,1,MPI_INT,MPI_SUM,MAESTRO,MPI_COMM_WORLD);
			
			printf("suma total desde el proceso maestro %d \n",sumaResultado);
            MPI_Reduce(&suma,&prodResultado,1,MPI_INT,MPI_PROD,MAESTRO,MPI_COMM_WORLD);
            printf("Producto de la suma desde el proceso maestro %d \n",prodResultado);

            MPI_Allreduce(&suma,&todosProdResultado,1,MPI_INT,MPI_PROD,MPI_COMM_WORLD);
            printf("Producto de la suma segun el proceso: %d es: %d \n",my_rank, prodResultado);

            MPI_Bcast(&arrreglo_enteros, 10000, MPI_INT, MAESTRO, MPI_COMM_WORLD);
            printf("\n Segun el rank: %d, El valor 1 del arreglo de 10000 datos es: %d \n", my_rank, arrreglo_enteros[0]);
		}
		if(my_rank>MAESTRO){
            int arreglo_local[MAX_STRING];
			int suma_local=0;
			MPI_Recv(&recorrido,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
			MPI_Recv(&arrreglo_enteros[recorrido],tamanioDePedazos,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
				for(int i=0;i<tamanioDePedazos;i++){
					suma_local+=arrreglo_enteros[recorrido+i];
				}
			printf("suma parcial de proceso %d es %d \n", my_rank,suma_local);
			MPI_Reduce(&suma_local,&sumaResultado,1,MPI_INT,MPI_SUM,MAESTRO,MPI_COMM_WORLD);
            MPI_Reduce(&suma_local,&prodResultado,1,MPI_INT,MPI_PROD,MAESTRO,MPI_COMM_WORLD);

            MPI_Allreduce(&suma_local,&todosProdResultado,1,MPI_INT,MPI_PROD,MPI_COMM_WORLD);
            printf("Producto de la suma segun el proceso: %d es: %d \n",my_rank, todosProdResultado);

            MPI_Bcast(&arreglo_local, 10000, MPI_INT, MAESTRO, MPI_COMM_WORLD);
            printf("\n Segun el rank: %d, El valor 1 del arreglo de 10000 datos es: %d \n", my_rank, arreglo_local[0]);
		}
	}
	
	MPI_Finalize();
	return 0;
}
