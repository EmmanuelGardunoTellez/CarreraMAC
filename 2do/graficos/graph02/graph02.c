/* ********************* TEXTO SIN ACENTOS *********************/
// Recuerda documentar tus codigos

#include<graphics.h>

int main()
{
 int gd = DETECT, gm;
 initgraph(&gd, &gm, NULL);                           //inicializador u abertura del graficador
      int left = 100, right = 200, top = 100, bottom = 200;   //medidas del rectangulo
      rectangle(left, top, right, bottom);          //con estas lineas de codigo se manda a graficar un rectangulo
 delay(5000);                               //tiempo en el cual se muestra la graficacion
  closegraph();               //cierre del graficador
    return 0;
}

