#include <stdio.h>
#include <math.h>

int min(int a, int b) {
    return a<b ? a:b;
}

int busqueda_lineal(int arr[], int tam, int elemento){
    int index = -1, i;
    for(i=0; i<tam; i++){
        if(arr[i] == elemento){
            index = i;
        }
    }
    return index;
}

int busqueda_binaria(int arr[], int tam, int elemento){
    int index = 0, primero = 0, ultimo = tam-1, medio;
    while(primero<=ultimo){
        medio = (primero+ultimo)/2;
        if(arr[medio] == elemento){
            index = medio;
            break;
        }
        else if(arr[medio] < elemento) primero = medio+1;
        else ultimo = medio-1;
    }
    
    if(primero > ultimo) index = -1;
    
    return index;
}

int busqueda_binaria_recursiva(int arr[], int primero, int ultimo, int elemento){
    if(ultimo >= primero){
        int medio = (primero+ultimo)/2;
        // Si elemento esta en la posicion de en medio
        if (arr[medio] == elemento) return medio;
        // Si elemento es mÃ¡s pequeÃ±o que el medio, buscamos en el subarreglo izquierdo
        if(arr[medio]>elemento)
            return busqueda_binaria_recursiva(arr, primero, medio-1, elemento);
        // Si no, elemento es mÃ s grande que el medio, buscamos en el subarreglo derecho
            return busqueda_binaria_recursiva(arr, medio+1, ultimo, elemento);
        
    }
    // El elemento no esta presente en el arreglo
    return -1;
}

int jumpSearch(int arr[], int elemento, int tam){
    // 1. Determinamos tamaño del salto
    int m = sqrt(tam);
    //Buscando el bloque donde el elemento esta presente
    int prev = 0;
    while(arr[min(m, tam)-1] < elemento){
        prev = m;
        m += sqrt(tam);
        if (prev >= tam) return -1;
    }
    // Haciendo busqueda lineal para el bloque x
    // empezando con prev
    while(arr[prev] < elemento){
        prev++;
        // Si llegamos al siguiente bloque o se termina
        // el arreglo, el elemento no está presente
        if(prev == min(m, tam)) return -1;
    }
    // Si elemento es encontrado
    if(arr[prev] == elemento) return prev;
    
    return -1; 
}

int main(){
	int a[50], i;
	
    for(i=0; i<50; i++){
        a[i] = i+1;
    }
	// Busqueda Lineal
	int posicion_lineal = busqueda_lineal(a, 50, 7);
    if(posicion_lineal == -1){
        printf("\n\nNo se encuetra el elemento en la lista");
    } else{
        printf("\n\nSe encuentra el elemento en la lista");
        printf(" en la posicion: %d", posicion_lineal);
    }
    // Busqueda Binaria
	int posicion_busqueda = busqueda_binaria(a, 50, 31);
    if(posicion_busqueda == -1){
        printf("\n\nNo se encuetra el elemento en la lista");
    } else{
        printf("\n\nSe encuentra el elemento en la lista");
        printf(" en la posicion: %d", posicion_busqueda);
    }
    // Busqueda Binaria Recursiva
    int posicion_elemento = busqueda_binaria_recursiva(a, 0, 50, 36);
    if(posicion_elemento == -1){
        printf("\n\nNo se encuetra el elemento en la lista");
    } else{
        printf("\n\nSe encuentra el elemento en la lista");
        printf(" en la posicion: %d", posicion_elemento);
    }
    // Busqueda por Salto
    int posicion_jump = jumpSearch(a, 45, 50);
    if(posicion_jump == -1){
        printf("\n\nNo se encuetra el elemento en la lista");
    } else{
        printf("\n\nSe encuentra el elemento en la lista");
        printf(" en la posicion: %d\n", posicion_jump);
    }
    
	return 0;
}






