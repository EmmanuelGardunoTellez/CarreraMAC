#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>
#define MAESTRO 0
#include<string.h>

const int MAX_STRING=10000;

int distribuye(float a);
void imprime (int arreglo[]);

 int main(void){
    float arreglo_flotantes[10000];
    float arreglo_resultado[10000];
    int elementos[5]={0,0,0,0,0};
    int elementos_final[5]={0,0,0,0,0};
    int comm_sz;
    int my_rank;
    int i;
    int resultado=0;
    double inicio, fin;
    for (i = 0; i < 10000; i++){
        arreglo_flotantes[i]= (rand()%5000)/1000.0f;
    }
	
    MPI_Init(NULL,NULL);
    MPI_Comm_size(MPI_COMM_WORLD,&comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);
    int tareas=20%comm_sz;
    int tamanioDePedazos=(10000/comm_sz);
    int recorrido=tamanioDePedazos;

    if (tareas!=0){
        if (my_rank==MAESTRO){
            printf("Saliendo del sistema, Se necesita un numero par detareas");
        }
    } 
    else {
        if (my_rank==MAESTRO){
            float arreglo_local[recorrido];

            MPI_Scatter(arreglo_flotantes, recorrido, MPI_FLOAT, arreglo_local, recorrido, MPI_FLOAT, MAESTRO, MPI_COMM_WORLD);
        	inicio = MPI_Wtime();
            //operaciones relacionadas con el master
            for (int i = 0; i < recorrido; i++){
                arreglo_local[i] = arreglo_local[i]+1;
            }
            for (int i = 0; i < tamanioDePedazos; i++){
                elementos[distribuye(arreglo_flotantes[i])]+=1;
            }
            MPI_Gather(arreglo_local, recorrido, MPI_FLOAT, elementos, recorrido, MPI_FLOAT, MAESTRO, MPI_COMM_WORLD);

            for (int i = 0; i < tareas; i++)
            {
                printf("\n Proceso %d El valor de proceso %f \n",i, elementos[i]);
            }
            
        }
        if (my_rank>MAESTRO){
            float arreglo_local[recorrido];
            int elementos_locales[5]={0,0,0,0,0};
            MPI_Scatter(arreglo_flotantes, recorrido, MPI_FLOAT, arreglo_local, recorrido, MPI_FLOAT, MAESTRO, MPI_COMM_WORLD);

            for (int i = 0; i < recorrido; i++)
            {
                arreglo_local[i]=arreglo_local[i]+1;
            }
            for (int i = 0; i < tamanioDePedazos; i++){
                elementos[distribuye(arreglo_flotantes[recorrido+i])]+=1;
            }

            MPI_Gather(arreglo_local, recorrido, MPI_FLOAT, elementos, MAX_STRING, MPI_FLOAT, MAESTRO, MPI_COMM_WORLD);
            
        }
        
        
    }
 	MPI_Finalize();
	return 0;   
 }
 int distribuye(float a){
    if(a<1){
        return 0;
    }
    if((a<2)&&(a>=1)){
        return 1;
    }
    if((a<3)&&(a>=2)){
        return 2;
    }
    if((a<4)&&(a>=3)){
        return 3;
    }
    if((a<5)&&(a>=4)){
        return 4;
    }
 }
 void imprime(int arreglo[]){
    for (int i = 0; i < 5; i++){
        printf("%d|",i);
        for(int j = 0; j < arreglo[i]/100; j++){
        	printf("*");
        }
        printf("\n"); 
    }
 }
