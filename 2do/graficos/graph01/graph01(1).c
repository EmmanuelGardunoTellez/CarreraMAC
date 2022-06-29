/* ********************* TEXTO SIN ACENTOS *********************/
// Recuerda documentar tus codigos

#include<graphics.h>

int main()
{
 int gd = DETECT, gm;
initgraph(&gd, &gm, NULL);               //inicio de la graficacion o abertura de la graficacion
// circle(int xc, int yc, int radius);
    circle(50, 50, 30);                 //medidas del circulo y tambien se manda a graficar en esta linea

 delay(5000);                           //tiempo que durara la graficacion visible
  closegraph();                         //cierre de la graficacion
    return 0;
}

