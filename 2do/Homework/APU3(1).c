#include <stdio.h>

int main(){
    int var1=6, var2=4, var3=0; // Tipo de vcariable int, definicion de variables
    int * var1_ap, * var2_ap; //declaracion una variable apuntador

var1_ap = &var3; //Operador de direcciones de memoria, acceder al valor usando un operador de asignacion de memoria, acceder al valor esando apuntador 

var3 = var1 + var2;
printf("var1_ap=%p, var3= %d y * var1_ap=%d\n",var1_ap,var3,*var1_ap); //Llamada de la variable, operador de referencia y de deferenca 
return 0;
}
