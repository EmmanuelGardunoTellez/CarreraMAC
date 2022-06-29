/* ********************* TEXTO SIN ACENTOS *********************/
// Recuerda documentar tus codigos
#include<stdio.h>
#include <stdlib.h>

int main(){
	
	FILE * fptr;
  char * cr;
  cr=(char*) malloc(50*sizeof(cr)); //similar a un arreglo de 50 caracteres
  
  char * cr1;
  cr1=(char*) malloc(50*sizeof(cr1)); //Lo mismo de arriba
	

fptr = fopen("11-fles00Ejer.txt","a"); //Abre un texto nuevo y borra lo anterios

puts("Escribe tus nombres \n");

scanf("%[^\n]%*c", cr); //Almacena nombre(s)

puts("Escribe tus apellidos \n"); 

scanf("%[^\n]%*c", cr1); //Almacena apellido(s)


fprintf(fptr,"%s %s\n", cr,cr1); //Garda los dos anteriores en texto

fclose(fptr); //Cierra el texto
free(cr1);
free(cr);
  return 0;
}

