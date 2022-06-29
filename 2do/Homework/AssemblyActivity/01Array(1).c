#include <stdio.h>

void main ()
{
char nombre[40]; //Almacena un espacio especifico de la memoria para el programa, que se usara mas tarde

int a; //Un contador qeu se usara para buscar en la matriz para buscar cierta cosa de ella


printf("Como te gusta que te llamen (sin espacios)? ");
scanf("%[^\n]", nombre); //Recibe el texto de la matriz y lo almacena para usarlo mas tarde

printf ("\nDiga la posicion del caracter que quiere imprimir \n");
scanf("%i", &a);//Selecciona con un numero la letra que ocupa ese espacio

printf ("\nEl caracter que está en esa posición es: %c\n", nombre[a-1]); //Te muestra la letra que ocupa ese espacio

printf ("\n\tMucho gusto %s Diviértete mientras aprendes C.\n", nombre); //Regresa el nombre que diste hace rato al programa
printf("\tLograrás mucho.\n");

}
