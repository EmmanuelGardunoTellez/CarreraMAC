#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
//declaracion de variables globales
int main(int argc, char *argv[]){
    int count,Minicial,i,IndicePrimo,n,N,primo;
    /*contador de primos,primer multiplo inicial,i,
    primo actual,identificador de 2 ...a,
    criba de 2 a....n, 
    tamano de los limites del tamiz y bucle*/
    char *marked;

if (argc!= 2) {
    printf("Command line: %s <m>\n", argv[0]);
    exit(1);
    }
n= atoi(argv[1]);
N=n+1;
marked= (char*)malloc(N);
if(marked== NULL){
    printf("Cannot allocate enough memory\n");
    exit(1);
}
for(i=0; i<N;i++) marked[i]=1;
marked[0]=0;
marked[1]=0;
IndicePrimo=2;
primo=2;
do{
    
    Minicial= 2*primo;
//Iniciamos la programacion paralela
#pragma omp parallel for
    for (i=Minicial;i<N;i+=primo)marked[i]=0;
    while (!marked[++IndicePrimo]);
    primo=IndicePrimo;
    printf("  %d ",primo);

}while(primo*primo<=n);

count=0;
for(i=0; i<N;i++)
count += marked[i];
printf("\nExisten %d numeros primos<= %d\n\n", count,n);
return 0;
}