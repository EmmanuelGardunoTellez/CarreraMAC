/* ********************* TEXTO SIN ACENTOS *********************/
// Recuerda documentar tus codigos

#include<stdio.h>
int main(){
int ret;
FILE * fptr1, *fptr2;
char c[25];


fptr1 = fopen("07-files01.txt","r"); //Abre docuemnto de texto para escribir

 if(fptr1 == NULL) //Detecta si se creo o no el archivo
   {
     printf("Error al abrir el archivo original");
}

fptr2 = fopen("07-files02.txt","w"); //Abre docuemnto de texto para leer

ret = rename(fptr1, &c); //Almacena el texto an un arreglo
 
 //fscanf(fptr1,"%[^\n]%*c", &c);

 fprintf(fptr2, "%s",c); //Imprime el arreglo
fclose(fptr1); //Ciarra los dos archos de texto
fclose(fptr2);


return 0;
}

