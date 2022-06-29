#include <stdio.h>
#include <stdlib.h>

int main()
{
    int  *ptr2, i, k , n2,n1,r; //Variables
    do{ //Ciclo repetir
 printf("Ingrese la tabla ");
    scanf("%d", &n1); //Que tabla es
 printf("Ingrese hasta que multiplo de los numeros quiere: ");
	scanf("%d", &n2); //De donde a donde multiplica
	ptr2 = (int *) malloc(n2 * sizeof(int)); //Cambio de la tamaño del arreglo
	for(i=1; i<n2+1; ++i){
		*(ptr2+i) = i; //Asignacion de valores por los que va a multiplicar
}
		printf("Tabla de multiplicar del %i\n", n1);
		for(k=1; k<n2+1;++k){
			printf("%i x %i = %i\n", n1,*(ptr2+k), n1*(*(ptr2+k))); //Imprime tabla
		}
 	printf("\n\n\tRepetir Programa (si=1 no= cualquiera distinto de 1) ?: ");
    scanf("%i", &r); //Si quiere o no repetir
    } while (r == 1);
    free(ptr2); //Liberar memoria adiccional
    return 0;
}
