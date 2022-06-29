#include<stdio.h>
#include<string.h>
#define n 5

int menu() //Menu de opciones pera ver los productos
{
	system("cls"); 
	int opcion;
	printf("Seleccione que quiere ver:\n");
	printf("1.Figuras.\n");
	printf("2.Videojuegos.\n");
	printf("3.Salir.\n");
	do // Condicion do wlile para qeu el usuario solo teclee las occiones qeu aparecen
	{
		printf("Opcción: ");
		scanf("%d",&opcion);
	}while(!(opcion>=1&&opcion<=3));
	return opcion;
}

struct intentory              //Primera estructura la cual se usara en dos despues, para ahorrar datos repetidos
{
	int cant;
	int	cantal;
	int cost;
};

struct games
{
	char game[30];           //Segunda estructura que guarda informacion sobre juegos
	char emp[30];
	char type [25];
	int anio;
	struct intentory inv;    //anidamiento de las estructuras
};

struct fig
{                             //Tercera estructura que guarda informacioon sobre figuras
	char name[30];
	char gamess[50];
	int alt;
	struct intentory inv;    //anidamiento de las estructuras
};

struct employee
{					   		//Cuarta estructura qeu almacena datos del empleado
	char name[30];
	int age;
};

struct store
{							//Quinta estructura donde almacena todos los datos y los guarda en un solo lujar
	char loc[30];
	char address[50];
	struct employee an;     //anidamiento de las estructuras
	struct fig fgr[n];      //anidamiento de las estructuras
	struct games game[n];   //anidamiento de las estructuras
};

// Funcion principal
int main()
{
//Cariables libres
int i, opcion;
// Declaracion de una variable de estructura uqe lamacena las demas
struct store str;
/*Datos del personal*/
strcpy(str.loc, "Los Gamers");
strcpy(str.address, "Gral. Pedro Antonio de Los Santos 84, San Miguel Chcpultepec 1 Secc, 11850 Ciudad de Mexico, CDMX");
strcpy(str.an.name, "Fernanda Palacios");
str.an.age=25;
/*VideoJuegos*/
strcpy(str.game[0].game,"The World Ends With You Final Remix");
strcpy(str.game[0].emp, "Nintendo");
strcpy(str.game[0].type, "Rol de accion");
str.game[0].anio=2018;
str.game[0].inv.cant=10;
str.game[0].inv.cantal=10;
str.game[0].inv.cost=1199;

strcpy(str.game[1].game,"Super Smash Bros. Ultimate");
strcpy(str.game[1].emp, "Nintendo");
strcpy(str.game[1].type, "Lucha");
str.game[1].anio=2018;
str.game[1].inv.cant=50;
str.game[1].inv.cantal=100;
str.game[1].inv.cost=1399;

strcpy(str.game[2].game,"New Super Mario Bros. U Deluxe");
strcpy(str.game[2].emp, "Nintendo");
strcpy(str.game[2].type, "Plataforma");
str.game[2].anio=2019;
str.game[2].inv.cant=25;
str.game[2].inv.cantal=50;
str.game[2].inv.cost=1399;

strcpy(str.game[3].game,"The Legend of Zelda: Breath of the Wild");
strcpy(str.game[3].emp, "Nintendo");
strcpy(str.game[3].type, "Accion aventura");
str.game[3].anio=2017;
str.game[3].inv.cant=15;
str.game[3].inv.cantal=20;
str.game[3].inv.cost=1399;

strcpy(str.game[4].game,"Octopath Traveler");
strcpy(str.game[4].emp, "Nintendo");
strcpy(str.game[4].type, "Rol");
str.game[4].anio=2018;
str.game[4].inv.cant=10;
str.game[4].inv.cantal=10;
str.game[4].inv.cost=1399;

/*Figuras*/
strcpy(str.fgr[0].gamess, "The Legend of Zelda: The Wind Waker HD");
strcpy(str.fgr[0].name, "Link");
str.fgr[0].alt=15;
str.fgr[0].inv.cant=10;
str.fgr[0].inv.cantal=25;
str.fgr[0].inv.cost=999;

strcpy(str.fgr[1].gamess, "Legend of Zelda");
strcpy(str.fgr[1].name, "Trifuerza");
str.fgr[1].alt=15;
str.fgr[1].inv.cant=5;
str.fgr[1].inv.cantal=20;
str.fgr[1].inv.cost=600;

strcpy(str.fgr[2].gamess, "Super Mario Odisey");
strcpy(str.fgr[2].name, "Mario and Cappy");
str.fgr[2].alt=5;
str.fgr[2].inv.cant=25;
str.fgr[2].inv.cantal=5;
str.fgr[2].inv.cost=169;

strcpy(str.fgr[3].gamess, "Kirby");
strcpy(str.fgr[3].name, "Kirby");
str.fgr[3].alt=25;
str.fgr[3].inv.cant=15;
str.fgr[3].inv.cantal=5;
str.fgr[3].inv.cost=1400;

strcpy(str.fgr[4].gamess, "Donkey Kong");
strcpy(str.fgr[4].name, "Donkey Kong");
str.fgr[4].alt=5;
str.fgr[4].inv.cant=25;
str.fgr[4].inv.cantal=5;
str.fgr[4].inv.cost=169;


/*Datos del local*/
printf( "Local: %s\n", str.loc);
printf( "Ubicada en: %s\n", str.address);
printf( "Bibliotecaria encargada: %s\n", str.an.name);
printf("Tiene %d anios \n\n", str.an.age);
system("pause");
//Ciclo del menu, que permite ver las figuras o videojuegos
do {
		opcion=menu();
		if(opcion!=3) //Siclo que reoite si la ipcion no es 1 o 2 y con 3 sale de el
		{
			switch(opcion){
	
			case 1:
				system("cls");
				for(i=0;i<n;i++){
				printf("Personaje: %s de %s\n",str.fgr[i].name, str.fgr[i].gamess);
				printf("Altura: %icm			Costo:%i\n",str.fgr[i].alt, str.fgr[i].inv.cost);
				printf("Ejemplares: %i en local y %i en almacen.\n\n",str.fgr[i].inv.cant,str.fgr[i].inv.cantal);
				}
				system("pause"); //Pause, para que no se salte la informacion (valido solo en windos)
			break;
			case 2:
				system("cls");
				for(i=0;i<n;i++){
				printf("Juego: %s de %s\n",str.game[i].game, str.game[i].emp);
				printf("Genero principal: %s\n",str.game[i].type);
				printf("Año de salida: %i		costo: %i\n",str.game[i].anio,str.game[i].inv.cost);
				printf("Ejemplares: %i en local y %i en almacen.\n\n",str.game[i].inv.cant, str.game[i].inv.cantal);
				}
				system("pause"); //Pause, para que no se salte la informacion (valido solo en windos)
			break;
		}//fin del switch
		}
	}while(opcion!=3);
return 0;
}
