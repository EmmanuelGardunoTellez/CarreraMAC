#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

#define MAESTRO 0 //hilo maestro
#define n 5 //tamaño de las matrices

int main(int argv, char* argc[]){
	int comm_sz; //numero de hilos
    int rank;// rank
	int num_ren;//numero de renglones
	int i, j, k;//contadores
	int Ma[n][n], Mb[n][n], Mc[n][n];//matrices 
	MPI_Init(NULL,NULL);//iniciamos MPI
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&comm_sz);
	num_ren = n/comm_sz;//le damos el numero de renglones por hilos
	for(i=0;i<n;i++){//generamos numeros aleatorios
		for (j=0;j<n;j++){
			Ma[i][j]= rand()%10;
			Mb[i][j]= rand()%10;
		}
	}
	for (k=0;k<n;k++)//multiplicacion de matrices
		for(i=0;i<n;i++){
			Mc[i][k]= 0;
			for(j=0;j<n;j++)
				Mc[i][k] += Ma[i][j]*Mb[j][k];
		}
	if(rank>MAESTRO){
		int ren= rank*num_ren;//obtenemos el renglon
		MPI_Send(&Mc[ren][0],num_ren*n,MPI_INT,MAESTRO,0,MPI_COMM_WORLD);//se lo enviamos al maestro
	}
	if(rank==MAESTRO){
		printf("Matriz A: \n");//Imprime matriz A
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf(" %d ",Ma[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		printf("Matriz B: \n"); //Imprime matrizB
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf(" %d ",Mb[i][j]);
			}
			printf("\n");
		}
		printf("\n");

		for(i=comm_sz-1;i>=1;i--){//recibe lo que le amndan los esclavos
			int ren= i*num_ren;
			MPI_Recv(&Mc[ren][0],num_ren*n,MPI_INT,i,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		}
		printf("Matriz C: \n"); //Imprime matriz C
		for(i=0;i<n;i++){
			for(k=0;k<n;k++)
				printf(" %d ",Mc[i][k]);
			printf("\n");
		}
	}
    MPI_Finalize();
    return 0;
}
