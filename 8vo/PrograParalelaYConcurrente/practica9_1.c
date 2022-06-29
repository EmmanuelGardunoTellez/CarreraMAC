#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
int main(int argc, char *argv []){
    int numeroDeHilos=strtol(argv[1],NULL,10);//recoje el nuero de hilos
    int i,k,n=500;//contadores para for y tamaño de n
    double a[n];//arreglo con los numeros
    for(i=0;i<500;i++){//rellenamos el array
        a[i]=i;
    }
    //iniciamos la programacion paralela con schedule y k privada y n y a publica
	#pragma omp parallel for num_threads(numeroDeHilos) default(none) private(k) shared(n,a) schedule(static,2)
        for(k=0; k<n;k++){
        	double resultado = 0;//resultado
        	resultado = a[k]*a[k];//cuadrado
        	printf("%f * %f = %f\n",a[k],a[k],resultado);//imprime el cuadrado    
        }
	return 0;
}
