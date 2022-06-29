/* ********************* TEXTO SIN ACENTOS *********************/
// Recuerda documentar tus codigos

#include<graphics.h>

int main()
{
 int gd = DETECT, gm;   
initgraph(&gd, &gm, NULL);    //iniciador del graficador

bar(100, 150, 200, 350);     //crea una barra y lo rellena de color, son las medidas de la barra

 delay(1000);                //tiempo que se mantiene abierto la graficacion
  closegraph();              //cierre del graficador
    return 0;
}

