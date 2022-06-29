/* ********************* TEXTO SIN ACENTOS *********************/
// Recuerda documentar tus codigos
#include <stdio.h>
void intercambio(int *a, int *b){ //Intercambion con arreglos
int aux=*a;
*a=*b; 
*b=aux;
}

int main(){
int i=3, j=50, aux; 
printf("i=%d y j=%d\n", i,j); 
printf("i=%p y j=%p\n", &i,&j); 
//intercambio(&i, &j); 
aux=j; //Intercambio sisn arreglos
j=i;
i=aux;
printf("i=%d y j=%d\n", i,j);
return 0; 
}
