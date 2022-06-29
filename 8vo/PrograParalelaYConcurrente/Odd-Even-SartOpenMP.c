#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
int main(int argc, char *argv []){
    int numeroDeHilos=strtol(argv[1],NULL,10);//recoje el nuero de hilos
    int n=20;//tamaño de la matriz
    int a[n];//arreglo
    int i, tmp=0, phase=0;//contadores y temporal
    for( i=0; i<n; i++ ){//generamos los numeros aeatorios
        a[i]=rand()%10;
    }
    for( i=0; i<n;i++){//muestra de los numeros originales
        printf("%d, ", a[i]);
    }
    //empezamos paralelismo con OpenMP, con n, a como publicas y privadas a i,tmp,phase
    #pragma omp parallel for num_threads(numeroDeHilos) default(none) shared(a,n) private(i,tmp,phase)
        for(phase=0; phase<n; phase++){
            if(phase % 2 == 0){//fase par se compara con el elemento a su izquerda y si estan fuera de orden se intercambian
                #pragma omp parallel for
                for( i=1; i<n;i += 1){//recorre la cadena de elementos
                    if (a[i-1]>a[i]){//si a[i-1] es mayor a a[i] se intercambian
                        tmp = a[i-1];
                        a[i-1] = a[i];
                        a[i]=tmp;
                    }
                }
            }else{//fase par se compara con el elemento de su derecha y si estan fuera de orden se intercambian
                #pragma omp parallel for
                for( i=0; i<n-1; i += 1 ){//recorre la cadena de elementos
                    if (a[i]>a[i+1]){//si a[i] es mayor a a[i-1] se intercambian
                        tmp = a[i+1];
                        a[i+1]=a[i];
                        a[i]=tmp;
                }
            }    
        }
    }
    printf("\n");
    for( i=0; i<n;i++){//imprime la cadena en orden
        printf("%d, ", a[i]);
    }
	return 0;
}
