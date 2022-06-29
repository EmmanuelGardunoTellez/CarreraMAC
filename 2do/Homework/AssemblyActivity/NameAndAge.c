#include <stdio.h>

void main ()
{
char nombre[50]; //espacio para almacenar el nombre sin espacios
char edad[4]; //Espacio para anotar al edad, no mayor a 999 años

printf("Como te gusta que te llamen? ");
scanf("%[^\n]%*c", nombre); //Escribe el usuario el nombre qeu va a usar
printf("Cual es tu edad? ");
scanf("%[^\n]", edad); //Anota la edad del usuario

printf("\vHola %s tu edad es %s\n", nombre, edad); //Imprime los parametros qeu anoto en una oracion ya preparada
}
