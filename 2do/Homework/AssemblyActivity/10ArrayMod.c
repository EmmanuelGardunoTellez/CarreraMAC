#include <stdio.h>

int main() {

int grades[6]={[1]=10,[2]=105.3};  //Valores guardados en elarreglo
int count=4, i, sum=0;  //contadores y lugar donde se suma los valores
float average=0;  //contador que da el promedio de la suma


for(i = 0; i< count; ++i){ //Ciclo que permite contar los valores
printf("%d\t", i+1);  
scanf("%d", &grades[i]); //Recibe los valores
sum+=grades[i]; //Suma los valores
}
average=(float)sum/count; //Usa el contador y la suma para darte el promedio de ellos
printf("El promedio es: %f\n",average); //Imprime el promedio
//Nota los valores agregados se limpian y ya no se usan
return 0;
}
