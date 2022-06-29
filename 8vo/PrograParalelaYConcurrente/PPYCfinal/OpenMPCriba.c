#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#define LIMITE 100 //Limite de la criba
int main(int argc, char *argv []){
    int numeroDeHilos=strtol(argv[1],NULL,10);//recoje el nuero de hilos
	int i,n,con=0; //contadores para for y cuantos numerso primos hay
	int numeros[LIMITE];//Numeros de 0 a LIMITE
	for(i=2;i<LIMITE;i++){//Obtener las lista de números a evaluar
		numeros[i]=1;
	}
	numeros[2]=1;//Hacer 2 el primer número primo
    //Iniciamos la programacion paralela, con i y n privaodos y numeros piblicos
	#pragma omp parallel for num_threads(numeroDeHilos) default(none) private(n,i) shared(numeros)   
    	for (n=2;n<LIMITE;n++){//Recorrer los números y para cada uno
	    	if (numeros[n]){//Si es primo recorrer los múltiplos y marcarlos como no primo
		    	for (i=n*n;i<LIMITE;i+=n){
		    		numeros[i] = 0;
		    	}
    		}
	    }	
	printf("Primos: "); //Muestro la lista de los primos
	for (n = 2; n < LIMITE; n++){
		if (numeros[n]){
			printf("%d  ",n);
            con+=1;
		}
	}
	printf("\n\nContador %d",con);
	return 0;
}
 
