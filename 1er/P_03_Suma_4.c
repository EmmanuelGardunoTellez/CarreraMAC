#include <stdio.h>
#include "biblioteca.h"

int main() {
    
    int valor_inicial, valor_final,i, contador, acumulador, Respuesta;
    ConfiguraIdioma();
portada();
do{
	system("cls");
    /* Se leen los límites. */
    printf("Ingrese los valores, recuerde que su valor inicial tiene que se mas chico que el valor final\n");
    printf( "Ingrese el valor inicial de la secuencia: " );
    scanf( "%d", &valor_inicial );
    printf( "Ingrese el valor final de la secuencia: " );
    scanf( "%d", &valor_final );
    acumulador=0;
    contador=0;
    
    if ( valor_inicial <= valor_final ) 
	{  /* Si esta condición se cumple, el orden no es inverso. */
        
        for ( i = valor_inicial; i <= valor_final; i++ )
		 {
		 	contador+=i;
		 	acumulador=acumulador+1 ;
		 	
            
        }
        printf("La suma es: %d \n", contador);
        printf("Y el numero de numeros contados es: %d\n", acumulador);
            
        
    } 
	else 
	{    /* Si la condición del if no se cumple, entonces el orden es inverso. */
        printf("Tu valor inicial es mas grande que el valor final");
		printf("No se puede hacer la suma");
	}
	system ("pause");
	printf("¿Quieres repetir? (1=si 0=no)");
	scanf("%d", &Respuesta);
}while(Respuesta==1);
    return 0;    
    }
