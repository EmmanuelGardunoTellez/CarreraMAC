#include <stdio.h>
#include <math.h>

void swap(int * xp, int * yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int compMerge = 0;
int interQuick = 0;
int compQuick = 0;
int interDualQuick = 0;
int compDualQuick = 0;

void desplegar(int * arr, int tam){
    int i;
    for(i=0; i<tam; i++){
        printf("%d ", arr[i]);
    }
}

void burbuja(int arr[], int n){
    int i, j;
    int comp = 0;
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-1; j++){
            comp++;
            if (arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                
            }
        }
    }
    printf("\nNumero de Comparaciones: %d\n", comp);
}


void burbuja_mejorada(int arr[], int n){
    int i, j;
    int comp = 0;
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++){
            comp++;
            if (arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
    printf("\nNumero de Comparaciones: %d\n", comp);
}

void selectionSort(int arr[], int n){
    int i, j, min_item;
    int comp = 0;
    for(i = 0; i < n-1; i++){
        min_item = i;
        // El for interno encuentra el mìnimo
        // del subarreglo no ordenado
        for(j = i+1; j < n; j++){
            comp++;
            if(arr[j] < arr[min_item]){
                min_item = j;
            }
        }
        // Intercambiamos el mínimo con el primer elemento
        swap(&arr[min_item], &arr[i]);
    }
    printf("\nNumero de Comparaciones: %d\n", comp);
}

void insertionSort(int arr[], int n){
    int i, j;
    int comp = 0;
    for(i = 1; i < n; i++){
        j = i;
        while((j > 0) && (arr[j-1] > arr[j])){
            comp++;
            swap(&arr[j-1], &arr[j]);
            j--;
        }
    }
    printf("\nNumero de Comparaciones: %d\n", comp);
}

void merge(int arr[], int ind_izq, int medio, int ind_der){
    // Creamos un arreglo temporal
    int temp[ind_der - ind_izq + 1];
    // Establecemos intervalos para el arreglo temporal
    int i = ind_izq, j = medio + 1, k = 0;
    // Recorremos ambos arreglos y en cada iteración añadimos
    // el elemento más pequeño de ambos en el arreglo temporal
    while(i <= medio && j <= ind_der){
        if(arr[i] <= arr[j]){
            temp[k] = arr[i];
            k++;
            i++;
        } else{
            temp[k] = arr[j];
            k++;
            j++;
        }
        compMerge++;
    }
    
    // Copiamos elementos sobrantes del primer intervalo
    while(i <= medio){
        temp[k] = arr[i];
        k++;
        i++;
    }
    // Copiamos elementos sobrantes del segundo intervalo
    while(j <= ind_der){
        temp[k] = arr[j];
        k++;
        j++;
    }
    // Copiamos arreglo temporal a arreglo Original
    for(i=ind_izq; i<=ind_der; i++){
        arr[i] = temp[i-ind_izq];
    }
}

void mergeSort(int arr[], int ind_izq, int ind_der){
    if(ind_izq < ind_der){
        // Partimos el arreglo en 2
        int medio = (ind_izq + ind_der)/2;
        // Ordenamos la primera parte del Arreglo
        mergeSort(arr, ind_izq, medio);
        // Ordenamos la segunda parte del Arreglo
        mergeSort(arr, medio+1, ind_der);
        // Mezclamos ambas partes comparando los elementos
        // de ambas
        merge(arr, ind_izq, medio, ind_der);
    }
}

int particion(int arr[], int ind_izq, int ind_der){
    int pivote = arr[ind_der];
    int i = (ind_izq - 1), j;
    for(j = ind_izq; j <= ind_der-1; j++){
    	compQuick++;
        if(arr[j] <= pivote){
            i++;
            interQuick++;
			swap(&arr[i], &arr[j]);
        }
    }
    interQuick++; 
	swap(&arr[i+1], &arr[ind_der]);
    return (i+1);
}

void quickSort(int arr[], int ind_izq, int ind_der){
    if(ind_izq < ind_der){
        int pivote = particion(arr, ind_izq, ind_der);
        quickSort(arr, ind_izq, pivote-1);
        quickSort(arr, pivote+1, ind_der);
    }
}

void dualQuickSort(int arr[], int ind_izq, int ind_der){
    int i, j, pivote;
    
    if(ind_izq < ind_der){
        i = ind_izq;
        j = ind_der;
        pivote = (arr[i] + arr[j])/2;
        while(i < j){
            while((arr[i] <= arr[pivote]) && (i<ind_der)){
            	compDualQuick++;
            	i++;
			} 
			
            while (arr[j] > arr[pivote]){
            	compDualQuick++;
            	j--;
			} 
			
            if(i<=j){
            	interDualQuick++;
                swap(&arr[i], &arr[j]);
            }
        }
        interDualQuick++;
        swap(&arr[pivote], &arr[j]);
        dualQuickSort(arr, ind_izq, j-1);
        dualQuickSort(arr, j+1, ind_der);
    }
}

int main(){
	//Metodo de la Burbuja
	printf("==== Metodo de la Burbuja: =====\n");
	int a01[] = {99, 88, 55, 77, 1, 66};
    int tam01 = sizeof(a01)/sizeof(a01[0]);
    printf("\nDesplegar los valores antes del ordenamiento: \n");
    desplegar(a01, tam01);
    
    printf("\n\nDesplegar los valores despues del ordenamiento: \n");
    burbuja(a01, tam01);
    desplegar(a01, tam01);
    
    printf("\n");
    
    //Metodo de la Burbuja (Mejorado)
    printf("\n==== Metodo de la Burbuja (Mejorado): =====");
    int a02[] = {99, 88, 55, 77, 1, 66};
    int tam02 = sizeof(a02)/sizeof(a02[0]);
    printf("\n\nDesplegar los valores antes del ordenamiento: \n");
    desplegar(a02, tam02);
    
    printf("\n\nDesplegar los valores despues del ordenamiento(Mejorado): \n");
    burbuja_mejorada(a02, tam02);
    desplegar(a02, tam02);
    
    printf("\n");
    
    //Metodo de Selecci�n
    printf("\n==== Metodo de Seleccion: =====");
    int a03[] = {5, 2, 6, 7, 2, 1, 0, 3};
    int tam03 = sizeof(a03)/sizeof(a03[0]);
    printf("\n\nDesplegar los valores antes del ordenamiento: \n");
    desplegar(a03, tam03);
    
    printf("\n\nDesplegar los valores despues del ordenamiento: \n");
    selectionSort(a03, tam03);
    desplegar(a03, tam03);
    
    printf("\n");
    
    //Metodo de Inserci�n
    printf("\n==== Metodo de Insercion: =====");
    int a04[] = {23, 6, 8, 9, 10, -2, 7, 10};
    int tam04 = sizeof(a04)/sizeof(a04[0]);
    printf("\n\nDesplegar los valores antes del ordenamiento: \n");
    desplegar(a04, tam04);
    
    printf("\n\nDesplegar los valores despues del ordenamiento: \n");
    insertionSort(a04, tam04);
    desplegar(a04, tam04);
    
    printf("\n");
    
    //Metodo de Ordenamiento por Mezcla (Merge Sort)
    printf("\n==== Metodo Merge Sort: =====");
    int a05[] = {2, 124, 23, 5, 89, -1, 44, 643, 34};
    int tam05 = sizeof(a05)/sizeof(a05[0]);
    printf("\n\nDesplegar los valores antes del ordenamiento: \n");
    desplegar(a05, tam05);
    
    printf("\n\nDesplegar los valores despues del ordenamiento: \n");
    mergeSort(a05, 0, tam05-1);
    printf("\nNumero de comparaciones: %d\n", compMerge);
    desplegar(a05, tam05);
    
    printf("\n");
    
    //Metodo de Ordenamiento R�pido (Quick Sort)
    printf("\n==== Metodo Quick Sort: =====");
    int a06[] = {9, -3, 5, 2, 6, 8, -6, 1, 3};
    int tam06 = sizeof(a06)/sizeof(a06[0]);
    printf("\n\nDesplegar los valores antes del ordenamiento: \n");
    desplegar(a06, tam06);
    
    printf("\n\nDesplegar los valores despues del ordenamiento: \n");
    quickSort(a06, 0, tam06-1);
    desplegar(a06, tam06);
    printf("\n\nNumero de comparaciones: %d\n", compQuick);
    printf("Numero de intercambios: %d\n", interQuick);
    
    printf("\n");
    
    //Metodo de Ordenamiento R�pido con dos pivotes (Dual Quick Sort)
    printf("\n==== Metodo Dual Quick Sort: =====");
    int a07[] = {9, -3, 5, 2, 6, 8, -6, 1, 3};
    int tam07 = sizeof(a07)/sizeof(a07[0]);
    printf("\n\nDesplegar los valores antes del ordenamiento: \n");
    desplegar(a07, tam07);
    
    printf("\n\nDesplegar los valores despues del ordenamiento: \n");
    dualQuickSort(a07, 0, tam07-1);
    desplegar(a07, tam07);
    printf("\n\nNumero de comparaciones: %d\n", compDualQuick);
    printf("Numero de intercambios: %d\n", interDualQuick);
    
    printf("\n\n");
    
	return 0;
}

