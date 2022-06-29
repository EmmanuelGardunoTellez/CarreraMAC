#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
int main(int argc, char *argv []){
    int numeroDeHilos=strtol(argv[1],NULL,10);//recoje el nuero de hilos
    int n=10;//tamaño de la matriz
    int Ma[n][n], Mb[n][n], Mc[n][n]; //matrices
    int i,j,k,l;//contadores para los for
    for( i=0; i<n; i++ ){//generamos los numeros aeatorios
        for( j=0; j<n; j++ ){
            Ma[i][j] = rand()%10;
            Mb[i][j] = rand()%10;
        }
    }
    //Iniciamos la programacion paralela, con i y j privaods y n y las matrices piblicas
	#pragma omp parallel for num_threads(numeroDeHilos) default(none) private(i,j) shared(n,Ma,Mb,Mc)   
        for( i=0; i<n; i++ ){
            for( j=0; j<n; j++ ){
                Mc[i][j] = Ma[i][j] + Mb[i][j];//Sumamos matrices
            } 
        } 
    printf("Matriz A: \n"); //Imprime matriz A
    for( k=0; k<n; k++ ){
        for( l=0; l<n; l++ ){
            printf( " %i ", Ma[k][l] );
        } 
    printf( "\n");
    } 
    printf("Matriz B: \n"); //Imprime matriz B
    for( k=0; k<n; k++ ){
        for( l=0; l<n; l++ ){
            printf( " %i ", Mb[k][l] );
        } 
    printf( "\n");
    } 
    printf("Matriz C: \n"); //Imprime matriz C
    for( k=0; k<n; k++ ){
        for( l=0; l<n; l++ ){
            printf( " %i ", Mc[k][l] );
        } 
    printf( "\n");
    } 
	return 0;
}
 
 
