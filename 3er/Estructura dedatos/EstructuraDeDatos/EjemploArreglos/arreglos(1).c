#include <stdio.h>
#include <stdlib.h>


void insertar(int arr [] , int tam, int valor, int posicion){
    int i;
    for(i=tam-1; i>=posicion-1; i--){
        arr[i+1] = arr[i];
    }
    arr[posicion-1] = valor;
}

void borrado(int arr [] , int tam, int posicion){
    int i;
    for(i=posicion; i<tam; i++){
        arr[i-1] = arr[i];
    }
}

void desplegar(int * arr, int tam){
    int i;
    for(i=0; i<tam; i++){
        printf("%d ", arr[i]);
    }
}

void modificar(int * arr, int tam, int valor){
    printf("Direccion del arreglo dentro de la funcion: %p\n", arr);
    int i;
    for(i=0; i<tam; i++)
        arr[i] = valor;
}

void modificar_dinamico(int ** arr, int length){
    int i;
    int * tmp = calloc(length, sizeof(int));
    for(i=0; i<length; i++)
        *(tmp+i) = 5;
    free(*arr);
    *arr = tmp;
}

void prueba_cambio(){
    int tam = 3;
    int prueba[3] = {1, 2, 3};
    printf("Antes del Cambio: \n");
    desplegar(prueba, tam);
    printf("\n\nDireccion base del arreglo antes del cambio: %p\n", prueba);
    modificar(prueba, 3, 7);
    printf("Direccion base del arreglo despues del cambio: %p\n", prueba);
    printf("\nDespues del Cambio: \n");
    desplegar(prueba, tam);
}

void prueba_cambio_dinamico(){
    int length = 3, nuevo_length = 5, tam, tam1;
    int * prueba = calloc(length, sizeof(int));
    int prueba2[] = {1,2,3};
    prueba[0] = 1;
    prueba[1] = 2;
    prueba[2] = 3;
    printf("\n\nAntes del Cambio: \n");
    desplegar(prueba, length);
    printf("\n\nDireccion base del arreglo antes del cambio: %p\n", prueba);
    modificar_dinamico(&prueba, nuevo_length);
    printf("\nDespues del Cambio: \n");
    desplegar(prueba, nuevo_length);
    printf("\n\nDireccion base del arreglo despues del cambio: %p\n", prueba);
}

int main(){
	int a01[20] = {0};
	// Insercion de elementos
	printf("\n==== Operacion de Insercion: =====\n");
	printf("\nValores antes de insercion: \n\n");
    desplegar(a01, 20);
    printf("\n\nValores despues de la insercion: \n\n");
    insertar(a01, 20, 2, 4);
    insertar(a01, 20, 7, 4);
    desplegar(a01, 20);
    
    printf("\n");
    
    // Borrado de elementos
    int a02[20] = {[4 ... 9] = 2, [14 ... 18] = 6};
    printf("\n==== Operacion de Borrado: =====");
    printf("\n\nValores antes de borrado: \n\n");
    desplegar(a02, 20);
    
    printf("\n\nValores despues de borrado: \n\n");
    borrado(a02, 20, 6);
    borrado(a02, 20, 17);
    desplegar(a02, 20);
    
    printf("\n");
    
    int a03[20], i;
    for(i=0; i<20; i++){
        a03[i] = i+1;
    }
    
    printf("\n==== Operacion de Modificacion: =====\n\n");
    prueba_cambio();
    
    printf("\n");
    
    printf("\n==== Operacion de Modificacion: ");
    printf(" Cambiando Estructura del Arreglo ====");
    prueba_cambio_dinamico();
	
	return 0;
}
