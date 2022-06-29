/* ********************* TEXTO SIN ACENTOS *********************/
// Recuerda documentar tus codigos

#include <stdlib.h>
#include <conio.h>
# include <stdio.h>

int num;


void binario()         //aqui se hace la transformacion a binario
{ 
	FILE *archivo1;
   int aux; 
   if(num==0) 
      return; 

   aux=num%2; 
   num=num/2; 
   binario(); 
   
   printf(" %d",aux); 
   
  archivo1 = fopen ( " Bin1.txt " , " a " ); 
  fprintf(archivo1, "%d", aux);
  fclose(archivo1);
 
}
int main() 
{ 
printf("\n Introduce un numero: \n");  //se introduce el numero en decimal
scanf("%d",&num);   
binario();                            //el numero se manda a la funcion binario

return 0;
}
