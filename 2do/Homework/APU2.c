#include <stdio.h>

int main(){
    int var1=6, var2=4; //Tipo de variable, direccion de variable
    int * var1_ap, * var2_ap; //Tipo de variable, declaracion una variable apuntador, direccion guardada en la variable apuntador

    var1_ap = &var1; //operador de direcciones de memoria, acceder al valor usando un operador de asignacion de memoria
    var2_ap = &var2; //operador de direcciones de memoria, acceder al valor usando un operador de asignacion de memoria

    printf("%p %d\n", var1_ap, var1); //Uso de la variable, acceder al valor usando apuntador
    printf("%p %d\n", var2_ap, var2); //Uso de la variable, acceder al valor usando apuntador.
    // operador de referencia y de deferenca no hay
return 0;
}
