/* ********************* TEXTO SIN ACENTOS *********************/
// Recuerda documentar tus codigos

#include <graphics.h>
#include <string.h>
#include <locale.h>         //biblioteca para poder poner acentos

#define n 200
int main()
{
//setlocale(LC_ALL, "en_US.UTF-8");

   int gd = DETECT,gm;
   initgraph(&gd,&gm,NULL);    //inicio del graficador

char name[n] = "Grupo de Programacion II. UNAM\n\t\t\tEstamos en la FES Acatlán"; //texto que se graficara

   outtextxy(100, 100, name);   //linea que manda a graficar el texto

   delay(8000);        //tiempo en que se muestra la graficacion
   closegraph();       //cierre de la graficacion
   return EXIT_SUCCESS;
}
