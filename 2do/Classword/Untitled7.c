#include<stdio.h>

int main(){
  FILE * fptr;
char cr[50];  //Espacio para almacenar caracteres
  char cad[160] = "Bienvenidos al curso de programacion estudiantes de MAC"; //Texto almacenado en un arreglo

  fptr = fopen("10-files20.txt","w"); //Abrir un docuemento txt
  fputs(cad, fptr);  //Almaceena los caracteres en el texto
  
   if(fgets(cr, 50, fptr)!=NULL) { 
      puts(cr); 
   }
fclose(fptr);

fclose(fptr);
  return 0;
}

