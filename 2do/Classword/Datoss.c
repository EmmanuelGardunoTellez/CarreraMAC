/* ********************* TEXTO SIN ACENTOS *********************/
// Recuerda documentar tus codigos

#include<stdio.h>

struct dates{ //Estructura que lamacena el nombre y caracter

	char name[25], age[10];
};

int main(){

FILE * fptr; 

fptr = fopen("Dates.txt","w"); //Abre docuemento txt
struct dates d; //invoco la escructura
printf("Dame tu nombre "); 
scanf("%[^\n]%*c",d.name); //Guardo el texto
printf("Dame tu nombre ");
scanf("%[^\n]%*c",d.age); ////Gaurdo el txto tambien se puede en numeros

fprintf(fptr,"Hola %s tu edad es %s",d.name,d.age); //Lo almaceno en el docuemnto

fclose(fptr);
return 0;
}
