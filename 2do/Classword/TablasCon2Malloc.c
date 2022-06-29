#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr1, *ptr2, i, k , n1, n2,r; //Variables
    do{
 printf("Ingrese hasta que tabla quiere, desde el 1 hasta el ");
    scanf("%d", &n1); //De la tabla uno hasta la que dija el usuario
    ptr1 = (int *) malloc(n1 * sizeof(int));
 for(i = 1; i < n1+1; ++i){
        *(ptr1+i) = i; //Asigna valores de 1 hasta donde dija el usuario
 }
 printf("Ingrese hasta que multiplo de los numeros quiere: ");
	scanf("%d", &n2); //Da de donde a donde va
	ptr2 = (int *) malloc(n2 * sizeof(int));
	for(i=1; i<n2+1; ++i){
		*(ptr2+i) = i; //Asigna valores
}
	printf("Tablas de multiplicar\n");
	for(i=1; i<n1+1;++i){
		printf("Tabla de multiplicar del %i\n", *(ptr1+i));
		for(k=1; k<n2+1;++k){ 
			printf("%i x %i = %i\n", *(ptr1+i),*(ptr2+k), (*(ptr1+i))*(*(ptr2+k)));
		}
		printf("\n\n");
	}
 	printf("\n\n\tRepetir Programa (si=1 no= cualquiera distinto de 1) ?: ");
    scanf("%i", &r);
    } while (r == 1);
    free(ptr1); free(ptr2);
    return 0;
}
