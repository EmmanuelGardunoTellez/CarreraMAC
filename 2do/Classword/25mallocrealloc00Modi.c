/* ********************* TEXTO SIN ACENTOS *********************/
// Recuerda documentar tus codigos

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr, i , n1, n2; //Valores enteros y apuntador (arreglo)
 printf("Ingrese el tamanio del arreglo: \n");
    scanf("%d", &n1); //Cuantos espacios para arreglo
    ptr = (int *) malloc(n1 * sizeof(int)); //Cambio de tama�o del arreglo
printf("Direccion de memoria asignada previamente: \n");
 for(i = 0; i < n1; ++i){
         printf("%p\t", ptr + i);//Imprimir direccion
 }

printf("\nIngrese el nuevo tamanio del arreglo: \n");
    scanf("%d", &n2); //Nuevo cambio de tama�o de arreglo
    ptr = realloc(ptr, n2); //Cambia tama�o
    for(i = 0; i < n2; ++i){
      printf("%p\t", ptr + i); //Imprime tama�o
      printf("\n");
    }

    free(ptr);
    return 0;
}
