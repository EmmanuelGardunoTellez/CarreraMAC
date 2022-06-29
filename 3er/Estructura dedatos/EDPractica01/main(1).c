#include <stdio.h>
#include <stdlib.h>

void info_apuntadores(){
	int valor = 9;
	int * ptr = NULL;
	printf("Valor: %d", valor);
	printf("\nDireccion: %p", &valor);
	ptr = &valor;
	printf("\n\nValor de ptr: %d", *ptr);
	printf("\nDireccion de ptr: %p", ptr);
	*ptr = *ptr * 3;
	printf("\n\nValor de ptr: %d", *ptr);
	printf("\nValor de variable valor: %d", valor);	
}

void arreglo_apuntadores(){
	int arr[] = {12,45,78,89,-56};
	int i;
	printf("\n\nValor: %p", arr);
	
	for(i=0; i<5; i++){
		printf("\nDireccion de arr[%d]: %p", i, &arr[i]);
	}
	
	printf("\n\nTam. de un entero: %d bytes", sizeof(int));
	printf("\n\nTam. de un entero: %d bytes", sizeof(long long int));
	
	printf("\n\nValor indice 2: %d", arr[2]);
	printf("\n\nValor indice 2: %d", *(arr+2));
	
	printf("\n\nDireccion indice 2: %p", &arr[2]);
	printf("\n\nDireccion indice 2: %p", arr+2);
}

void paso_valor(int a, int b){
	printf("\n\nDirecciones dentro de la funcion: ");
	printf("\nDireccion de a: %p", &a);
	printf("\nDireccion de b: %p", &b);
	a = 2*a;
	b = 3*b;
	printf("\n\nValores dentro de la funcion: ");
	printf("\nValor de a: %d", a);
	printf("\nValor de b: %d", b);
}

void paso_referencia(int * a, int * b){
	printf("\n\nDirecciones dentro de la funcion: ");
	printf("\nDireccion de a: %p", a);
	printf("\nDireccion de b: %p", b);
	*a = 2* (*a);
	*b = 3* (*b);
	printf("\n\nValores dentro de la funcion (por referencia): ");
	printf("\nValor de a: %d", *a);
	printf("\nValor de b: %d", *b);
}

void funciones_apuntadores(){
	int a = 7, b = 19;
	printf("\n\nDirecciones fuera de la funcion: ");
	printf("\nDireccion de a: %p", &a);
	printf("\nDireccion de b: %p", &b);
	paso_valor(a, b);
	printf("\n\nValores fuera de la funcion: ");
	printf("\nValor de a: %d", a);
	printf("\nValor de b: %d", b);
	paso_referencia(&a, &b);
	printf("\n\nValores fuera de la funcion (por referencia): ");
	printf("\nValor de a: %d", a);
	printf("\nValor de b: %d", b);	
}

void arreglo_de_apuntadores(){
	int arreglo[10], i;
	for(i=0; i<10; i++){
		arreglo[i] = i+2;
	}
	
	int * ptr[10];
	
	for(i=0; i<10; i++){
		ptr[i] = &arreglo[i];
	}
	
	for(i=0; i<10; i++){
		printf("\nValor ptr[%d] = %d", i, *ptr[i]);
	}
	
	char * arr_char[5] = {"Uno", "Dos", "Tres", "Cuatro", "Cinco"};
	
	printf("\n\nCadena de caracteres: ");
	for(i=0; i<5; i++){
		printf("\n%s", arr_char[i]);
	}
}

int main(int argc, char *argv[]) {
	//info_apuntadores();
	//arreglo_apuntadores();
	//funciones_apuntadores();
	arreglo_de_apuntadores();
	return 0;
}
