#include <stdio.h>
#include <string.h>
#include <mpi.h>
const int MAX_STRING=100;
int main(void){
	int comm_sz; //numero de procesos
	int my_rank; //nombre del proceso
	int proceso0=10, proceso1,proceso2, proceso3; //variable para cada proceso
	MPI_Init(NULL,NULL); //iniciamos mpi
	MPI_Comm_size(MPI_COMM_WORLD,&comm_sz);
	MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);
	if(my_rank==0){	//si el rango es 0
		MPI_Send(&proceso0,1,MPI_INT,1,0,MPI_COMM_WORLD);//les damos acceso al esclavos 1 al valor n
		int resultado1; //creamos una variable para almacenar resultados
		printf("Valor n es %d\n",proceso0);//presentamos cuanto vale n
		MPI_Recv(&resultado1,1,MPI_INT,3,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE); //optennemos el resultado del inciso 3
		printf("Valor obtenido del proceso 3 es %d \n",resultado1);	//imprimimos el resultado obtenido
	}
	else if(my_rank==1){ //si el rango es 1
		MPI_Recv(&proceso0,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE); //tomamos el valor de n del maestro
		int proceso1=proceso0*proceso0;//operacion n*n
		MPI_Send(&proceso1,1,MPI_INT,2,0,MPI_COMM_WORLD); //enviamos el resultado al esclavo 2
	}
	else if(my_rank==2){ //si el rango es 2
		MPI_Recv(&proceso1,1,MPI_INT,1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE); //tomamos el valor del esclavo 1
		int proceso2=proceso1+2;//operacion n+2
		MPI_Send(&proceso2,1,MPI_INT,3,0,MPI_COMM_WORLD); //enviamos el resultado al esclavo 3
	}
	else if(my_rank==3){ //si el rango es 3
		MPI_Recv(&proceso2,1,MPI_INT,2,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE); //tomamos el valor del esclavo 2
		int proceso3=proceso2*8;//operacion n*8
		MPI_Send(&proceso3,1,MPI_INT,0,0,MPI_COMM_WORLD); //enviamos el resultado al maestro
	}
	MPI_Finalize();//finalizamos mpi
	return 0;
}
