/* ********************* TEXTO SIN ACENTOS *********************/
// Recuerda documentar tus codigos

#include<graphics.h>

int main()
{
 int gd = DETECT, gm;
initgraph(&gd, &gm, NULL);    //inicializador de la graficacion

bar3d(100, 150, 200, 350, 20, 2);  //medidas de una barra en 3ra dimension, la manda a graficar

 delay(5000);                //tiempo que se muestra la graficacion
  closegraph();              //cierre de la graficacion
    return 0;
}
