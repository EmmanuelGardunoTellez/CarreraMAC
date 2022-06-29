#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>
#define MAESTRO 0
#include<string.h>

int distribuye(float a);
void imprime (int arreglo[]);

 int main(void){
    float arreglo_flotantes[10000];
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
        	inicio = MPI_Wtime();
            //operaciones relacionadas con el master
            for (int i = 0; i < tamanioDePedazos; i++){
                elementos[distribuye(arreglo_flotantes[i])]+=1;
            }
            for (int q = 1; q < comm_sz; q++){
                MPI_Send(&recorrido,1,MPI_INT,q,0,MPI_COMM_WORLD);
                MPI_Send(&arreglo_flotantes[recorrido],tamanioDePedazos,MPI_INT,q,0,MPI_COMM_WORLD);
                recorrido=recorrido+tamanioDePedazos;
            }
            MPI_Reduce(&elementos,&elementos_final,5,MPI_INT,MPI_SUM,MAESTRO,MPI_COMM_WORLD);
            printf("esstos son los elementos de rank:\n 0->%d \n 1->%d \n 2->%d \n 3->%d \n 4->%d \n",
            elementos_final[0],elementos_final[1],elementos_final[2],elementos_final[3],elementos_final[4]);
            imprime(elementos_final);
            fin = MPI_Wtime();
            printf("El tiempo que transcurio fue de: %1.4f\n", fin-inicio);
        }
        if (my_rank>MAESTRO){
            int elementos_locales[5]={0,0,0,0,0};
            MPI_Recv(&recorrido,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
            MPI_Recv(&arreglo_flotantes[recorrido],tamanioDePedazos,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
            for (int i = 0; i < tamanioDePedazos; i++){
                elementos_locales[distribuye(arreglo_flotantes[recorrido+i])]+=1;
            }
            MPI_Reduce(&elementos_locales,&elementos_final,5,MPI_INT,MPI_SUM,MAESTRO,MPI_COMM_WORLD);
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
