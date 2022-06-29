#include<stdio.h>
int main(){
FILE * archivo, *ar;
archivo = fopen (" prueba.txt", "a"); //crea un arcivo de texto terminacnion txt
ar= fopen ("pt.dat", "a"); //crea un arcivo de texto terminacion dat
fclose (archivo); //cierra albos
fclose(ar);
return 0;
}
