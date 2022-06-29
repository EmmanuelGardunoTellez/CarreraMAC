#include <stdio.h>
#include <string.h>
#include <mpi.h>
const int MAX_STRING=100;
int main(void){
	int comm_sz; //numero de procesos
	int my_rank; //nombre del proceso
	int proceso0=10; //n
	MPI_Init(NULL,NULL); //iniciamos mpi
	MPI_Comm_size(MPI_COMM_WORLD,&comm_sz);
	MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);
	if(my_rank==0){	//si el rango es 0
		for(int q=1;q<comm_sz;q++){
			MPI_Send(&proceso0,1,MPI_INT,q,0,MPI_COMM_WORLD);//les damos acceso a los esclavos del valor n
		}
		int resultado1; //creamos una variable para almacenar resultados
		printf("Valor n  para todos los procesos es %d\n",proceso0);//presentamos cuanto vale n
		for(int q=1;q<comm_sz;q++){ //impromimos cada resultado obtenido
			MPI_Recv(&resultado1,1,MPI_INT,q,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
			printf("Valor obtenido del proceso %d es %d \n",q,resultado1);
		}		
	}
	else if(my_rank==1){ //si el rango es 0
		MPI_Recv(&proceso0,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE); //tomamos el valor de n del maestro
		int resultado1=proceso0*proceso0;//operacion
		MPI_Send(&resultado1,1,MPI_INT,0,0,MPI_COMM_WORLD); //enciamos el resultado al maestro
	//	printf("Valor obtenido del proceso %d es %d \n",my_rank,resultado1);
	}
	else if(my_rank==2){ //si el rango es 0
		MPI_Recv(&proceso0,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE); //tomamos el valor de n del maestro
		int resultado2=proceso0+proceso0;//operacion
		MPI_Send(&resultado2,1,MPI_INT,0,0,MPI_COMM_WORLD); //enciamos el resultado al maestro
	//	printf("Valor obtenido del proceso %d es %d \n",my_rank,resultado2);
	}
	else if(my_rank==3){ //si el rango es 0
		MPI_Recv(&proceso0,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE); //tomamos el valor de n del maestro
		int resultado3=proceso0+2;//operacion
		MPI_Send(&resultado3,1,MPI_INT,0,0,MPI_COMM_WORLD); //enciamos el resultado al maestro
	//	printf("Valor obtenido del proceso %d es %d \n",my_rank,resultado3);
	}
	MPI_Finalize();//finalizamos mpi
	return 0;
}
