/* ********************* TEXTO SIN ACENTOS *********************/
// Recuerda documentar tus codigos

#include<stdio.h>

int main(){

char nombre[]="Javier Orduz"; //Arreglo que guarda una cadena de caracteres
char * puntero=nombre; //El arreglo es asignado a un apuntador, solo con su nombre

printf("Nombre almacenado %s \n", puntero); //Se usa al apuntador para invocarlo

return 0;
}
