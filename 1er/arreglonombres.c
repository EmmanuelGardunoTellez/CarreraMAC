#include <stdio.h>
#include <stdlib.h>
#define P 100
#define C 20
#define CO 5
int pregunta()
{
	int res;
	do
	{
		printf("Te intereso algun producto? (1= si 0=no)" );
		scanf("%d",&res);
	}while(!(res>=0&&res<=1));
	return res;
}

void Imprimirproductos(char producto[C][P], float precio[C], float descuento[C],char codigos[C][CO])
{
	int i;
	for(i=0; i<20; i++)
	{
 		printf("Producto: %s codigo: %s\n",producto[i], codigos[i]);
		printf("Precio de $%.2f con descuento de $%.2f precio total $%.2f\n \n",precio[i], descuento[i],precio[i]-descuento[i]);
	}
}

float JM(float total)
{
	int res;
    char productos1[C][P] = { "Games Pictionary Encuadre Juego de Mesa para Bebés", "Hasbro Gaming Game Monopoly Stranger Things.", "Hasbro Gaming Juego de Mesa Baño Loco. ", "Hasbro Gaming Juego de Mesa Adivina Quién.", "Hasbro Gaming Juego de Mesa Súper Gimnasta.", "Hasbro Adult Games HG ¡A Ver Si Adivinas! Juego de Mesa para Niños.", "Hasbro Connect 4 Game.", "Kids Games HG Desafío De Canciones Juego de Mesa para Niños.", "Hasbro Gaming Juego Clue.", "Monopoly Gamer Mario Kart.", "Monopoly Legend of Zelda Edition.", "Mattel Card Game UNO Corns.", "Hasbro Bop It! Micro Series Game.", "Pirañas Chifladas Juego.", "Uno Spin.", "Hasbro Battleship.", "Hasbro Gaming Juego Twister.", "UNO Card Game Super Mario.", "Hasbro Games Yahtzee Classic."," Hasbro Jenga: Disney Frozen Edition Game."  };
    float precio1[C]= { 350, 600, 400, 400, 290, 600, 180, 500, 300, 450, 500, 100, 250, 600, 350, 600, 350, 175, 190, 250 };
    float des1[C]= { 0,100,0,0, 0, 50, 0, 60, 0, 25, 100, 0, 0, 100, 0, 50, 50, 0, 0, 100  };
    char codigos1[C][CO] = {"MJ01", "MJ02", "MJ03","MJ04","MJ05","MJ06","MJ07","MJ08","MJ09","MJ10","MJ11","MJ12","MJ13","MJ14","MJ15","MJ16","MJ17","MJ18","MJ19","MJ20"};
	printf("Departamento de Juegos de mesa:\n\n");
	Imprimirproductos(productos1, precio1, des1, codigos1);
	res=pregunta();

    getch();
    return 0;
}



int menu()
{
	system("cls");
	int opcion;
	printf("Categorias de porductos.");
	printf("1.\n");
	printf("2.\n");
	printf("3.\n");
	printf("4.\n");
	printf("5.\n");
	printf("6.\n");
	printf("7.\n");
	printf("8.\n");		
	printf("9.\n");
	printf("10.\n");
	printf("11.\n");
	do
	{
		printf("Opcción: ");
		scanf("%d",&opcion);
	}while(!(opcion>=1&&opcion<=11));
	return opcion;
}

main()
{
	float total;
	int opcion;
	//ConfiguraIdioma();
	//portada();
	total=0;
	do {
		opcion=menu();
		if(opcion!=11)
		{
			switch(opcion){
				case 1:
					system("cls");
					JM(total);
				break;
				case 2:	
			
				break;
				case 3:
				
				break;
				case 4:
				
				break;
				case 5:
				
				break;
				case 6:
				
				break;
				case 7:
				
				break;
				case 8:
				
				break;
				case 9:
				
				break;	
				case 10:
				
				break;																		
				
			}//fin del switch
		}
	}while(opcion!=11);

	printf("%.2f \n", total);
	printf("Seleccion de metodo de pago.\n");
	system("Pause");
}

