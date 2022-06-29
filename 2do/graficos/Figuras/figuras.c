/* ********************* TEXTO SIN ACENTOS *********************/
// Recuerda documentar tus codigos

#include<graphics.h>

void circulo(){
	cleardevice();
	char name[25] = "Un circulo"; //texto que se graficara
	char area[30] = "Area = Pi*r^2";
	char perimetro[30] = "Perimetro = 2*Pi*r";
	outtextxy(200, 100, name);   //linea que manda a graficar el texto
	outtextxy(200, 150, area); 
	outtextxy(200, 200, perimetro); 
	circle(100, 150, 80);                 //medidas del circulo y tambien se manda a graficar en esta linea
	
};

void elipse(){
	cleardevice();
	char name[25] = "Elipse"; //texto que se graficara
	char area[30] = "Area = Pi(r1)(r2)";
	char perimetro[30] = "Perimetro = Pi(r1+r2)";
	outtextxy(200, 100, name);   //linea que manda a graficar el texto
	outtextxy(200, 150, area); 
	outtextxy(200, 200, perimetro); 
	ellipse(320, 240, 0, 360, 50, 100);                //medidas de la elipse y tambien se manda a graficar en esta linea
	
};

void rectangulo(){
	cleardevice();
	char name[25] = "Un rectangulo"; //texto que se graficara
	char area[30] = "Area = b*a";
	char perimetro[30] = "Perimetro = 2*b+2*a";
	outtextxy(200, 100, name);   //linea que manda a graficar el texto
	outtextxy(200, 150, area); 
	outtextxy(200, 200, perimetro); 
	rectangle(50, 50, 150, 250);           //medidas del rectangulo y tambien se manda a graficar en esta linea
	
};

void triangulo(){
	cleardevice();
	char name[25] = "Un circulo"; //texto que se graficara
	char area[30] = "Area = (b*a)/2";
	char perimetro[30] = "Perimetro = b+b+b";
	outtextxy(200, 100, name);   //linea que manda a graficar el texto
	outtextxy(200, 150, area); 
	outtextxy(200, 200, perimetro); 
	line(20,200,170,200);         //medidas del rectangulo y tambien se manda a graficar en esta linea
	line(75,150,170,200);
	line(20,200,75,150);
};


void cuadrado(){
	cleardevice();
	char name[25] = "Un circulo"; //texto que se graficara
	char area[30] = "Area = b*b";
	char perimetro[30] = "Perimetro = 4*b";
	outtextxy(200, 100, name);   //linea que manda a graficar el texto
	outtextxy(200, 150, area); 
	outtextxy(200, 200, perimetro); 
	rectangle(100, 100, 200, 200);           //medidas del rectangulo y tambien se manda a graficar en esta linea
	
};



int menu()
{
	//Menu para ver lo que grafica
	system("cls");
	int opcion;
	printf("Figuras. \n");
	printf("1. Circulo.\n");
	printf("2. Elipse.\n");
	printf("3. Rectangulo.\n");
	printf("4. Cuadrado\n");
	printf("5. Triangulo\n");
	printf("6. Salir\n");
	do
	{
		printf("Escriba la opción que desea ver: ");
		scanf("%d",&opcion);
	}while(!(opcion>=1&&opcion<=6)); //ver que no pase del 12
	return opcion;
}

int main()
{
	int gd = DETECT, gm, opcion;
	initgraph(&gd, &gm, NULL); //inicio de la graficacion o abertura de la graficacion

	do {
		opcion=menu();
		if(opcion!=6)
		{
			switch(opcion){
				case 1: 
					circulo();
					delay(5000);
				break;
				case 2:
					elipse();
					delay(5000);
				break;
				case 3:
					rectangulo();
					delay(5000);
				break;
				case 4:
					cuadrado();
					delay(5000);
				break;
				case 5:
					triangulo();
					delay(5000);
				break;
				
			}
		}
	}while(opcion!=6);

 	closegraph();                          //cierre de la graficacion
	
    return 0;
}
