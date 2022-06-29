#include<stdio.h>
int main(){
    FILE *art, *art2;
    art = fopen ( "1datas.txt", "a"); //Abre los dos archivos
    art2 = fopen ( "2datos.txt", "a");
    fprintf(art, "Hola a todos"); //Escribe en los dos archivos
    fprintf(art2, "Adios a todos");
    return 0;
}
