#include <stdio.h>
#define n 100 //Es una cosntante global para la matrix 1xn donde n es la cosntante

void main ()
{
char name[n]; //Espacio para almacenar texto sin espacios
char LastName[n]; //Espacio para almacenar texto sin espacios
/*Si se escribe un espacio en este lo cortara y lo mandara a otro lado*/
printf("Como te gusta que te llamen? ");
scanf("%[^\n]%*c", name); //Almacena la palabra escrita
printf("Cual es tu apellido (sin espacios)? ");
scanf("%[^\n]", LastName);  //Almacena la palabra escrita

printf("\v\tHola %s tu apellido es %s\n", name, LastName); //Escribe las palabras almacenadas
}
