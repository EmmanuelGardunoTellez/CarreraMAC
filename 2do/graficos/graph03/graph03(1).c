/* ********************* TEXTO SIN ACENTOS *********************/
// Recuerda documentar tus codigos

#include<graphics.h>

int main()
{
 int gd = DETECT, gm;
initgraph(&gd, &gm, NULL);           //se abre la graficacion

ellipse(100, 100, 0, 360, 50, 25); //medidas de la elipse y tambien por medio de esta linea se manda a graficar

 delay(5000);                    //tiempo que dura la pestaña de la graficacion
  closegraph();                  //se cierra el grafico
    return 0;
}
