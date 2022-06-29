#include<stdio.h>
#include<string.h>
#include<mpi.h>
#define MAESTRO 0
#include<stdlib.h>

const int MAX_STRING = 1000;

int main(void) {



int arreglo_enteros[MAX_STRING];
int comm_sz;//numero de proceso
int my_rank; 
int resultado=0;
double inicio, fin;
for (int i = 0; i < MAX_STRING; i++){
    arreglo_enteros[i]=i;
}


MPI_Init(NULL,NULL);
MPI_Comm_Size(MPI_COMM_WORLD,&comm_sz);
MPI_Comm_Rank(MPI_COMM_WORLD,&my_rank);
int tareas = comm_sz%2;
int tamanioDePedazos=(MAX_STRING/comm_sz);
int recorrido = tamanioDePedazos;

if(tareas!=0) {
    if (my_rank==MAESTRO){
        printf("Saliendo del sistema, se necesita un nummero par de instrucciones");
    }
}
else{
    MPI_Barrier(MPI_COMM_WORLD);
        if (my_rank==MAESTRO){

            inicio=MPI_Wtime();
            int suma=0;
            //operaciones relacionada al master
            for (int i = 0; i < tamanioDePedazos; i++){
                suma+=arreglo_enteros[i];
            }
            printf("suma del proceso maestro %d \n",suma);

            for (int q = 0; q < count; q++){
                MPI_Send(&recorrido,1,MPI_Int,q,0,MPI_COMM_WORLD);
                MPI_Send(&arreglo_enteros,tamanioDePedazos,MPI_Int,q,0,MPI_COMM_WORLD);
                recorrido=recorrido+tamanioDePedazos;
            }







            MPI_Reduce(&suma,&resultado)



        }
        if (my_rank>MAESTRO){
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
            MPI_Reduce(&suma,&resultado,1,MPI_INT,MPI_SUM,MPI_COMM_WORLD);
        }
    }
	MPI_Finalize(); //acabamos MPI
	return 0;
}