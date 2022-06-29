#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "biblioteca.h"
#define P 150
#define C 20
#define CO 5


void listas(char productos[C][P],float precio[C],float descuento[C], char codigos[C][CO],int cantidad[C])
{
	int res, in,i,t,j=0,tutu,productoss;
	
	do
	{
		printf("¿Quiere comprar uno de nuestros productos?(1= si 0=no)" ); //Preguntar si quiere algun producto con 1 y 0
		scanf("%d",&res);
	}while(!(res>=0&&res<=1));
	if(res==1){
			do{ //selecciona el codigo que tiene
				printf("¿Cuál es el producto de su interes?\n(anote el final del codigo de la categoria del producto de interes) ");
				scanf("%i",&in);
			}while(in < 1 || in > 20);
			printf("¿Qué cantidad desea del producto de interes?  "); //Cuantos quieren
			do{
				scanf("%i", &tutu);   // AHB: Te faltaba el &
			}while(0>=tutu);
			cantidad[in-1]=cantidad[in-1]+tutu; //Suma en la cantidad de cosas que ha comprado de un producto en concreto
	}

    getch();
}



void comprados(int cantidad[C], float precio[C], float des[C], char codigo[C][CO]){
	int  i;
	for(i=0; i<20; i++)
	{
		if(cantidad[i]>0)  //Muestra cuantos productos compra por categoria
		{
 		printf("%s \t\t%i \t\t%.2f \t\t%.2f\n\n",codigo[i],cantidad[i], (precio[i]-des[i]),((precio[i]-des[i])*cantidad[i]));
		}
	}	
}

void quitar_productos(char productos[C][P],int cantidad[C],char codigos[C][CO], float precio[C],float des[C] ){
	//i contador, deja leer el final del codigo, cdeja cuantos deja y res desa retirar
	int  i, deja,cdeja,res;
	printf("\nProductos que puede quitar del carro de esta categoria:\n");
	printf("Codigo \t\tCantidad \tPrecio \t\tTotal\n\n");
	for(i=0; i<20; i++)
	{
		if(cantidad[i]>0)  //Muestra cuantos productos compra por categoria
		{
 		printf("%s \t\t%i \t\t%.2f \t\t%.2f\n\n",codigos[i],cantidad[i], (precio[i]-des[i]),((precio[i]-des[i])*cantidad[i]));
 		
		}
	}
	do{
	printf("Desea retirar algun producto: (1= si 0=no)" ); //Decir cual producto quitar
		scanf("%d",&res);
	}while(!(res>=0&&res<=1));
	if(res==1){
	do{ 
		printf("\nEscriba la ultima parte del código del producto a dejar: (números):"); //ver cuual va sacar
		scanf("%i",&deja);
	}while(deja < 1 || deja > 20); 
	printf("%i\n",cantidad[deja-1]);

	do{
		printf("Nota: Si selecciona otro diferente ponga 0.\n"); //Seleccioona cuantos deja y ve si esta permitido hacerlo
		printf("¿Qué cantidad del producto seleccionado quiere dejar?\n");
		scanf("%i",&cdeja);	
	}while(cdeja < 0 || cdeja > cantidad[deja-1]);
cantidad[deja-1]=cantidad[deja-1]-cdeja;
}
}

void VISA()
{
	int NTar, Aexp, codigo, Mexp;
	char nombre[20];
	char ApellidoPaterno[30];
	char ApellidoMaterno[30];
	printf("VISA\n");
	printf("Nombre del titular (solo primer nombre):\n");
	scanf("%s", &nombre);
	printf("Apellido paterno del titular:\n");
	scanf("%s", &ApellidoPaterno);
	printf("Apellido materno del titular:\n"); 
	scanf("%s", &ApellidoMaterno);
	printf("Nombre del titular completo: %s %s %s\n", nombre,ApellidoPaterno,ApellidoMaterno);
    printf("Numero de la tarjeta(16 digitos):\n");
	scanf("%d", &NTar);
	do{
	printf("Mes de expiracion (2 digitos)\n");
	scanf("%d", &Mexp);
	}while(Mexp <1 || Mexp >12 );
	do{
	printf("Año de expiracion (4 digitos)\n");
	scanf("%d",&Aexp);
	}while(Aexp <2019 || Aexp > 2035);
	printf("Codigo de Seguridad o CCV (3 digitos)\n ");
	scanf("%d",&codigo);
}
	void MasterCard()
{
	int NTar, Aexp, codigo, Mexp;
	char nombre[20];
	char ApellidoPaterno[30];
	char ApellidoMaterno[30];
	printf("MasterCard\n");
	printf("Nombre del titular(solo primer nombre):\n");
	scanf("%s", &nombre);
	printf("Apellido paterno del titular:\n");
	scanf("%s", &ApellidoPaterno);
	printf("Apellido materno del titular:\n");
	scanf("%s", &ApellidoMaterno);
	printf("Nombre del titular completo: %s %s %s\n", nombre,ApellidoPaterno,ApellidoMaterno);
	printf("Numero de la tarjeta(16 digitos):\n");
	scanf("%d", &NTar);
	do{
	printf("Mes de expiracion (2 digitos)\n");
	scanf("%d", &Mexp);
	}while(Mexp <01 || Mexp >12 );
	do{
	printf("Año de expiracion (4 digitos)\n");
	scanf("%d",&Aexp);
	}while(Aexp <2019 || Aexp > 2035);
	printf("Codigo de Seguridad o CCV (3 digitos)\n ");
	scanf("%d",&codigo);
}
void AmericanExpress()
{
	int NTar, Aexp, codigo, Mexp;
	char nombre[20];
	char ApellidoPaterno[30];
	char ApellidoMaterno[30];
	printf("American Express\n");
	printf("Nombre del titular(solo primer nombre):\n");
	scanf("%s", &nombre);
	printf("Apellido paterno del titular:\n");
	scanf("%s", &ApellidoPaterno);
	printf("Apellido materno del titular:\n");
	scanf("%s", &ApellidoMaterno);
	printf("Nombre del titular completo: %s %s %s\n", nombre,ApellidoPaterno,ApellidoMaterno);
	printf("Numero de la tarjeta(16 digitos):\n");
	scanf("%d", &NTar);
	do{
	printf("Mes de expiracion (2 digitos)\n");
	scanf("%d", &Mexp);
	}while(Mexp <01 || Mexp >12 );
	do{
	printf("Año de expiracion (4 digitos)\n");
	scanf("%d",&Aexp);
	}while(Aexp <2019 || Aexp > 2035);
	printf("Codigo de Seguridad o CCV (3 digitos)\n ");
	scanf("%d",&codigo);
}

void nota_parcial_de_compra(char productos[C][P],int cantidad[C], float precio[C], float descuento[C]) //Agrega a la tabla de la nota de compra los productos cuya cantidad no es 0
{
	int  i;
	for(i=0; i<20; i++)
	{
		if(cantidad[i]>0)  //Muestra cuantos productos compra por categoria
		{
 		printf("%-29.29s %8i %18.2f %12.2f %10.2f\n", productos[i],cantidad[i],precio[i],descuento[i],(precio[i]-descuento[i])*cantidad[i]);	//Le dal el formato a las filas de las tablas
		}
	}	
}

int verificarcuenta(char *cuen) //verifica si la cuenta paypal introducida es válida, es decir , si tiene espacios la cuenta y/o diferente de un arroba el correo, osea que sea de la forma nombre@dominio.algo
{
	int espacios=0;
	int arrobas=0;
	int i;
	int posicion_arroba;
	int puntos_en_el_dominio;
	
	for (i=0; *(cuen+i)!='\0'; i++)	//recorre el correo para saber si tiene espacios
	{
		if (*(cuen+i)==' ') 
			espacios++;
	}
	
	if (espacios!=0)	//Si tiene espacios termina la función
	{
		printf("La cuenta no es válida");
		return 1;
	}
	
	for (i=0; *(cuen+i)!='\0'; i++)	//recorre el correo para saber si tiene arrobas
	{
		if (*(cuen+i)=='@') 
		{
			arrobas++;	//Si las tiene las cuenta  //arrobas++ es igual a arrobas=arrobas+1
			posicion_arroba=i; //Guarda en que posición está la ultima arroba
		}
		
	}
	
	if (arrobas==0||arrobas>1)	//Si no tiene, o tiene más de una arroba termina la función
	{
		printf("La cuenta no es válida");
		return 2;
	}
	
	for (i=posicion_arroba; *(cuen+i)!='\0'; i++)	//recorre el correo despues de la arroba para saber si tiene puntos en el dominio
	{
		if (*(cuen+i)=='.') 
			puntos_en_el_dominio++;
	}
	if (puntos_en_el_dominio!=1)	//Si tiene más de un punto termina la función
	{
		printf("La cuenta no es válida");
		return 3;
	}
	
	return 0;	//Si cumple con todos los parametros entonces regresa un cero.
}

int pagar_con_paypal()
{
	char cuenta[50];	//Espacio para guardar la cuenta paypal, max 49 caracteres
	char contrasena[20];	//Espacio para guardar la contraseña max 19 caaracteres
	int valorcuenta=1;	//la inicializamos para que el while se ejecute al menos una vez
	
	while(valorcuenta)
	{
		printf("\nEscriba su cuenta Paypal\n");
		fflush(stdin);	//limpia la caché del teclado para que no funcione mal gets
		gets(cuenta);	//get string, guarda lo que le introduzcas en el teclado hasta que presionas enter
		valorcuenta=verificarcuenta(cuenta);	//Cambia el valor de valorcuenta, sí es correcta pone un 0 y el while termina
		//printf("Valor de la cuenta %i",valorcuenta);	//Permite saber en que es invalida la cuenta
	}
	
	printf("\nEscriba su contrasena Paypal\n");
	gets(contrasena);
	printf("procesando . . .\n");	// lo hace más bonito : )
	
	printf("Su pago ha sido exitoso.");//Siempre lo va a aceptar
	system("pause");
}

void pago_oxxo(){
	printf("Número de serie con el cualpuedes efectuar el pago en OXXO: \n\n");
	int i,numero;
	srand(time(NULL));
	for(i=1;i<=10;i++){
	numero=1+rand()%((10)-1);// crea un numero a lazar como codigo del oxxo
	printf("%i"" ",numero);	
	}
	printf("\n");
	system("pause");
} 


int menu()
{
	//Menu de datos compras
	system("cls");
	int opcion;
	printf("Categorias de productos. \n");
	printf("1. Juegos de mesa.\n");
	printf("2. Libros.\n");
	printf("3. Muebles.\n");
	printf("4. Zapatos\n");
	printf("5. Coleccionables.\n");
	printf("6. Accesorios.\n");
	printf("7. Ropa deportiva.\n");
	printf("8. Maquillajes.\n");		
	printf("9. Videojuegos.\n");
	printf("10. Electronicos\n");
	printf("11. Ver objetos del carrito.\n");
	printf("12. Dejar de ver los productos\n");
	do
	{
		printf("Escriba la opción que desea ver: ");
		scanf("%d",&opcion);
	}while(!(opcion>=1&&opcion<=12)); //ver que no pase del 12
	return opcion;
}

int menu2()
{
	//Menu de datos compras
	int opcion;
	printf("Seleccion de metodo de pago. \n");
	printf("1. Pago en oxxo.\n");
	printf("2. Pago con tarjeta.\n");
	printf("3. Paypal\n");
	printf("4. Efectivo\n");
	do
	{
		printf("Escriba el metodo de pago: ");
		scanf("%d",&opcion);
	}while(!(opcion>=1&&opcion<=4)); //ver que no pase del 4
	return opcion;
}

int menu3()
{
	//Menu de datos compras
	system("cls");
	int opcion;
	printf("Metodo de pago por tarjeta de credito\n");
	printf("Seleccione el tipo de tarjeta con el que pagara\n"); 
	printf("1. VISA\n");
	printf("2. MasterCard\n");
	printf("3.American Express\n");
	do
	{
		printf("Escriba el metodo de pago: ");
		scanf("%d",&opcion);
	}while(!(opcion>=1&&opcion<=3)); //ver que no pase del 3
	return opcion;
}

main()
{
	/*Departamento de juegos de mesa*/
	//Nombres de los juegos de mesa
	char productosJM[C][P] = { "Games Pictionary Encuadre Juego de Mesa para Bebés", "Hasbro Gaming Game Monopoly Stranger Things.", "Hasbro Gaming Juego de Mesa Baño Loco. ", "Hasbro Gaming Juego de Mesa Adivina Quién.", "Hasbro Gaming Juego de Mesa Súper Gimnasta.", "Hasbro Adult Games HG ¡A Ver Si Adivinas! Juego de Mesa para Niños.", "Hasbro Connect 4 Game.", "Kids Games HG Desafío De Canciones Juego de Mesa para Niños.", "Hasbro Gaming Juego Clue.", "Monopoly Gamer Mario Kart.", "Monopoly Legend of Zelda Edition.", "Mattel Card Game UNO Corns.", "Hasbro Bop It! Micro Series Game.", "Pirañas Chifladas Juego.", "Uno Spin.", "Hasbro Battleship.", "Hasbro Gaming Juego Twister.", "UNO Card Game Super Mario.", "Hasbro Games Yahtzee Classic."," Hasbro Jenga: Disney Frozen Edition Game."  };
   	//Precio juegos de mesa
    float precioJM[C]= { 350, 600, 400, 400, 290, 600, 180, 500, 300, 450, 500, 100, 250, 600, 350, 600, 350, 175, 190, 250 };
   	//Descuento de juegos de mesa
    float desJM[C]= { 0,100,0,0, 0, 50, 0, 60, 0, 25, 100, 0, 0, 100, 0, 50, 50, 0, 0, 100  };
    //Codigo de jueogs de mesa
	char codigosJM[C][CO] = {"MJ01", "MJ02", "MJ03","MJ04","MJ05","MJ06","MJ07","MJ08","MJ09","MJ10","MJ11","MJ12","MJ13","MJ14","MJ15","MJ16","MJ17","MJ18","MJ19","MJ20"};
    //Cantidad de productos que pide el usiario de juegos de mesa
	static int cantidadJM[C] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	
	/*Departamento de libros*/
	//Nombres de Libros
	char productosLI[C][P] = {"Over the Garden Wall, Volume 1.", "Over the Garden Wall, Volume 2.", "The Legend of Zelda Encyclopedia.", "The Art of Splatoon.", "Super Mario Encyclopedia: The Official Guide to the First 30 Years.", "The Art of Rick and Morty.", "It (Eso).", "Oswald the Lucky Rabbit: The Search for the Lost Disney Cartoons.", "La historia de la república." , "Almanaque chavorruco.", "VALLE DE LA CALMA.", "Festival de la blasfemia." ,"Luna de Plutón.", "La guerra de Ysaak.", "Imouto sae Ireba ii.", "Your name (kimi no nawa)(light novel).", "5 Centimeters Per Second.", "Batman: The Killing Joke, Deluxe Edition.", "Cartas De Amor A Los Muertos.", "Naruto: Itachi's Story, Volume 1 & 2."};
   	//Precio Libros
    float precioLI[C]= { 220, 220, 570, 550, 500, 800, 400, 770, 250, 250, 280, 190, 140, 300, 350, 375, 360, 365, 220, 400};
   	//Descuento de Libros
    float desLI[C]= { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    //Codigo de Libros
	char codigosLI[C][CO] = {"LI01", "LI02", "LI03", "LI04", "LI05", "LI06", "LI07", "LI08", "LI09", "LI10", "LI11", "LI12", "LI13", "LI14", "LI15", "LI16", "LI17", "LI18", "LI19", "LI20"};
    //Cantidad de productos que pide el usuario de Libros
	static int cantidadLI[C] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

	/*Departamento de juegos de Muebles*/
	//Nombres de los Muebles
	char productosMU[C][P] ={"Sala Modular Lyberty Azul", "Sala Olga Cofee", "Sala Modular Nuria Gris Oxford", "Sala Barri Rojo", "Sala Lindsay Olivo", "Odisey Gris Comedor", "Zen Tabaco Comedor", "Luxor Comedor", "Monroe Gris Comedor", "Odisey Comedor Floter Café", "Recamara King Size Picasso Chocolate", "Recamara King Size Picasso Blanco con Negro", "Recamara King Size Odisey Velvet Claro", "Recamara King Size Odisey Velvet Oscuro", "Recamara King Size Nappa Vino", "Colchon Mimo Individual Fernan", "Colchon Spring Air Individual Opportunity", "Colchon Sealy Individual Shira", "Colchon America Individual Denver", "Colchon America Matrimonial Berlin"};
   	//Precio Muebles
    float precioMU[C]= {6699, 8998, 7799, 9898, 8598, 12294, 10994, 14993, 8395, 13693, 2997, 7997, 5997, 5997, 6997, 1799, 2999, 3399, 3399, 4999 };
   	//Descuento de Muebles
    float desMU[C]= { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    //Código de Muebles 
	char codigosMU[C][CO] = {"MU01", "MU02", "MU03", "MU04", "MU05", "MU06", "MU07", "MU08", "MU09", "MU10", "MU11", "MU12", "MU13", "MU14", "MU15", "MU16", "MU17", "MU18", "MU19", "MU20"};
    //Cantidad de productos que pide el usuario de Muebles
	static int cantidadMU[C] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

	/*Departamento de juegos de Zapatos*/
	//Nombres de los Zapatos
	char productosZA[C][P] ={"Zapato Casual Uomo Di Ferro 322", "Zapato Casual Flexi 2402", "Zapato Casual Kafe 2501", "Bota Corta Kebo 3000", "Bota Corta Goodyear Y453", "Zapato Casual Mirage 3001", "Zapato Casual Kafe 3601", "Zapato Casual Uomo Di Ferro 9235", "Bota Tipo Hiker Kebo Kids 182", "Zapato Casual Bambino 1062", "Bota Corta Goodyear 7611", "Ballerina Vivis Shoes Kids 800", "Ballerina Casual Vivis Shoes Kids 267N", "Balerina Vivis Shoes Kids 7001", "Zapato Casual Vavito 1131", "Bota Tipo Militar Tierra Bendita R745", "Botin Heavy HPC Polo 7701", "Botin Heavy HPC Polo 7702", "Bota de Montar Tierra Bendita 963", "Bota de Vestir Yaeli 4710"};
   	//Precio Zapato
    float precioZA[C]={ 465, 899, 549, 449, 999, 489, 426, 467, 369, 379, 955, 461, 489, 419, 384, 519, 535, 536, 509, 564};
   	//Descuento de Zapato
    float desZA[C]= { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    //Código de Muebles 
	char codigosZA[C][CO] = {"ZA01",  "ZA02", "ZA03", "ZA04", "ZA05", "ZA06", "ZA07", "ZA08", "ZA09", "ZA10", "ZA11", "ZA12", "ZA13", "ZA14", "ZA15", "ZA16", "ZA17", "ZA18", "ZA19", "ZA20"};
    //Cantidad de productos que pide el usuario de Muebles
	static int cantidadZA[C] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

	/*Departamento de Coleccionables*/
	//Nombres de los Coleccionables
	char productosCO[C][P]={ "Coleccion De Articulos De Harry Potter 9 3/4 Felix Snitch", "Coleccion de cartas de yugioh (baraja de Kaiba, Yugi y Joey)", "Coleccion de comics de Spider-Man", "Manga: Boku no piko. 1era edicion", "Figura de Eva-01 y Shinji Ikari Evangelion", "Figura de Eva-00 y Rei Ayanami. Evangelion", "Coleccion de vinilo de albumes de The Beatles", "Coleccion completa de mangas de Tokyo Ghoul", "Figua de Eva-02 y Asuka Langley Soryu. Evangelion", "Coleccion de comics de Batman (5 comics)", "Coleccion de Mangas Yaoi (15 mangas)", "Coleccion de Mangas Yuri (20 mangas)", "Coleccion de Mangas de One Piece (Del 1 al 500)", "Coleccion de Mangas de Boku no Hero (Del 1 al 200)", "Coleccion One Piece Figuras Articuladas 10 Figuras", "Yugioh Collar 8 Artículos Sortija Milenio Yu Gi Oh Llavero", "Coeccion de figuras de Mario Bros Completa", "Coleccion de figuras de Star Wars completa", "Coleccion de videojuegos de pokemon (De la 1er hasta la 6ta generacion)", "Coleccion de libros de Harry Potter"};
   	//Precio Coleccionables
    float precioCO[C]={ 1000, 8000, 4500, 900, 3200, 3500, 12000, 9000, 3800, 2600, 1600, 1580, 13000, 5000, 7000, 900, 7600, 18000, 6500, 6300};
   	//Descuento de Coleccionables
    float desCO[C]= { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    //Código de Coleccionables
	char codigosCO[C][CO] = {"CO01",  "CO02", "CO03", "CO04", "CO05", "CO06", "CO07", "CO08", "CO09", "CO10", "CO11", "CO12", "CO13", "CO14"," CO15", "CO16", "CO17", "CO18", "CO19", "CO20"};
    //Cantidad de productos que pide el usuario de Coleccionables
	static int cantidadCO[C] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

	/*Departamento de Accesorios */
	//Nombres de los Accesorios
	char productosAC [C][P]={ "Audífonos Bluetooth con micrófono, color negro", "Collar de diamantes", "Manos libres", "Reloj plateado, Marca Rolex", "WebCam", "Bocinas de computadora", "Mouse Bluetooth", "Collar de perlas", "Anillo Cristal Negro Cuadrado", "Pulsera Circulo De Cristal", "Modulo Inalambrico Wifi Powerlite EPSON (V12H418P12)", "Maletín Portafolio Manhattan 17 EMPIRE 421560", "Mini Teclado Techzone Bluetooth 2 en 1 con touch pad Techzone", "Diadema Acteck AF-540 Con Micrófono Para PC Y Smartphone ACTECK", "Teclado Multidispositivo Logitech K480, Bluetooth LOGITECH", "Anillo de diamantes", "Collar de zafiro", "Lentes de sol color negro", "Collar de cuarzo, diferentes colores", "Reloj de Oro, Marca Omega" };
   	//Precio Accesorios
    float precioAC[C]={ 1500, 12000, 100, 4500, 3000, 1800, 2300, 8000, 490, 500, 2450, 320, 2500, 430, 700, 15000, 7500, 320, 100, 3500};
   	//Descuento de Accesorios
    float desAC[C]= { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    //Código de Accesorios
	char codigosAC[C][CO] = {"AC01",  "AC02", "AC03", "AC04", "AC05", "AC06", "AC07", "AC08", "AC09", "AC10", "AC11", "AC12", "AC13", "AC14", "AC15", "AC16", "AC17", "AC18", "AC19", "AC20"};
    //Cantidad de productos que pide el usuario de Accesorios
	static int cantidadAC[C] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	
	/*Departamento de Ropa deportiva */
	//Nombres de Ropa deportiva
	char productosRP[C][P]= { "Mallas de running de 7/8 y tiro medio para mujer Nike Speed", "Sudadera con capucha de running de cierre completo para mujer Nike Element", "Chamarra de running de cuello redondo para mujer Nike Repel", "Top de running de manga corta para mujer Nike Medalist", "Top de running de manga corta para mujer Nike Dri-FIT Miler", "Shorts de básquetbol tejidos para hombre Nike Elite", "Camiseta de fútbol para hombre Alternativa Stadium del Tottenham Hotspur", "Chamarra de running para hombre Nike Shield Flash", "Sudadera con capucha de running de cierre completo para hombre Nike Element", "Sudadera para hombre Hurley One And Only Dolman Fleece", "Playera sin mangas Seasonal", "Vestido barricade adidas by stella mccartney", "Swimsuit fit 1pc lin", "Top deportivo all me", "Sudadera essentials 3 franjas con doble capa", "Jersey de local atlas fútbol club", "Jersey de visitante real Madrid", "Playera freelift climacool", "Shorts de natación colorblock", "Mallas alphaskin 360 long"};
   	//Precio Ropa deportiva
    float precioRP[C]={ 1299, 1000, 1200, 999, 549, 749, 1499, 2100, 1000, 1299, 1000, 2000, 899, 899, 1099, 1300, 1499, 799, 799, 2900 };
   	//Descuento de Ropa deportiva
    float desRP[C]= { 0, 200, 149, 0, 0, 0, 0, 99, 200, 0,  99, 199, 0, 0, 0 , 199, 0, 0, 0, 99};
    //Código de Ropa deportiva
	char codigosRP[C][CO] = {"RP01",  "RP02", "RP03", "RP04", "RP05", "RP06", "RP07", "RP08", "RP09", "RP10", "RP11", "RP12", "RP13", "RP14", "RP15", "RP16", "RP17", "RP18", "RP19", "RP20"};
    //Cantidad de productos que pide el usuario de Ropa deportiva
	static int cantidadRP[C] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	
	/*Departamento de Maquillaje */
	//Nombres de los Maquillaje
	char productosMA [C][P]={ "Pretty things", "Shiny pretty eye shadow", "Studio fix perfecting powder", "Satin lipstick", "Retro matte liquid lipcolour metallics", "huggable lipcolour", "Retro matte lipstick", "prep + prime highlighter", "prep + prime pore refiner stick", "prep + prime skin smoother", "Yuya set de maquillaje maquinita por yuya", "Yuya delineador en gel para ojos"," Yuya mascara para pestanas", "Yuya set de sombras enamórate", "Yuya labial liquido mate mi amor", "Rubor 3 tonos me quiero", "Set (baila conmigo) 3 esmaltes + 3 labiales + 2 pads + cosmetiquera", "Set 1 esmalte + 1 labial + 1 pad modelo 1 (la sirena)", "Set de sombras (chiquita)", "Yuya labial liquido mate 8la sirena)"};
   	//Precio Maquillaje
    float precioMA[C]={ 399, 400, 489, 200,250, 250, 300, 200, 450,450, 345, 165, 159, 200, 95, 225, 595, 185, 250, 95 };
   	//Descuento de Maquillaje
    float desMA[C]= { 199, 50 ,0,0,0,0,0,0,0,129, 55,0,0,50,0,0,0,0,40,0};
    //Código de Maquillaje
	char codigosMA[C][CO] = {"MA01",  "MA02", "MA03", "MA04", "MA05", "MA06", "MA07", "MA08", "MA09", "MA10", "MA11", "MA12", "MA13", "MA14", "MA15", "MA16", "MA17", "MA18", "MA19", "MA20"};
    //Cantidad de productos que pide el usuario de Maquillaje
	static int cantidadMA[C] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

	
	/*Departamento de Videojuegos */
	//Nombres de los Videojuegos
	char productosVI[C][P]={ "Consola Xbox ONE", "Consola Xbox ONE S. ", "Consola Playstation 2.","Consola Playstatio 4 Plus.", "Video juego God of War. ", "Video juego Red Dead Redeption 2.", "Video juego Horizon Zero Dawn." , "Video juego Jumanji.", "Control de Xbox 360.", "Control de Playstation 2.", "Control de Xbox ONE.", "Control de Xbox ONE Special edition.", "Control de Playstation 4.", "Control de Playstation 4 Plus.", "Consola NESS. ", "Videojuego Life is Strange episode 1.", "Videojuego Life is Strange episode 2.", "Videojuego Life is Strange episode 3.", "Videojuego Life is Strange episode 4.", "Videojuego Life is Strange complete edition." };
   	//Precio Videojuegos
    float precioVI[C]={ 7500, 8900, 1500, 9999, 1097, 1050, 950, 5000, 600, 10425, 800, 900, 700, 800, 12000, 165, 120, 190, 800, 1200 };
   	//Descuento de Videojuegos
    float desVI[C]= {0,0,0,500,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,200};
    //Código de Videojuegos
	char codigosVI[C][CO] = {"VI01",  "VI02", "VI03", "VI04", "VI05", "VI06", "VI07", "VI08", "VI09", "VI10", "VI11", "VI12", "VI13", "VI14", "VI15", "VI16", "VI17", "VI18", "VI19", "VI20"};
    //Cantidad de productos que pide el usuario de Videojuegos
	static int cantidadVI[C] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

	/*Departamento de Electrónicos  */
	//Nombres de los Electrónicos 
	char productosEL[C][P]={ "Audífonos SONY.", "Estéreo SONY.", "Bocinas para fiestas.", "Karaoke.", "Juego de Microfonos.", "Pantalla Smart Tv Hisense 50h5c 2k Full HD.", "Pantalla Sceptre 32 Led 1366 X 768 60Hz HD.", "Pantalla Smart Tv 4k 50'' Hisense 50h6e Led Ultra Hd.", "Pantalla Spectra Led 32 Pulgadas.", "Pantalla 65 Smart Tv Sharp Aquos 4k Uhd Led.", "Celular Apple Iphone 5 16GB.", "Celular Lg Phoenix 3 Nuevo 4g Lte 16GB 1.5GB Ram.", "Celular Samsung Galaxy S6 32GB 4G Lte 16mp Demo.", "Gaming Mouse Gamer Led 7 Botones 5500 Dpi.", "Redlemon Mouse Gamer Usb Optico 7 Botones Plug And Play.", "Computadora Pc Cpu Gamer Barata Amd A6 8GB 500GB Radeon 2GB.", "Computadora Gaming A10-9700 8GB 500GB Gtx1050ti 4 GB 21 Led.", "Teclado Led Gamer Motospeed K70 Gaming.", "Hyper X Teclado Mecánico Gamer Alloy Elite Rgb Led.", "Pc Gamer Amd A10 Quad Core 8GB 1tb Video Radeon Hd 7620g." };
   	//Precio Electrónicos 
    float precioEL[C]={ 420, 2200, 5700, 5050, 500, 8700, 4500, 7700, 2550, 15000, 2800, 1900, 3040, 300, 3050, 3750, 13060, 565,3200, 4000 };
   	//Descuento de Electrónicos 
    float desEL[C]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    //Código de Electrónicos 
	char codigosEL[C][CO] = {"EL01",  "EL02", "EL03", "EL04", "EL05", "EL06", "EL07", "EL08", "EL09", "EL10", "EL11", "EL12", "EL13", "EL14", "EL15", "EL16", "EL17", " EL18", "EL19", "EL20"};
    //Cantidad de productos que pide el usuario de Electrónicos 
	static int cantidadEL [C] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	float total=0;
	int i,res;	
	int opcion, opcion2, opcion3;
	char datos;
	ConfiguraIdioma();
//	portada();
		do {
		opcion=menu();
		if(opcion!=12)
		{
			switch(opcion){
				case 1: 
					system("cls");
					printf("Departamento de Juegos de mesa:\n\n");
					listas(productosJM,precioJM,desJM,codigosJM, cantidadJM); //muestra productos
					system("cls");
					do{
						printf("Desea ver los productos y/o retirar alguno de esta categoria (1= si 0=no): "); 
						scanf("%d",&res);
					}while(!(res>=0&&res<=1));
					if (res==1){
					printf("Articulos comprados del departamento de Juegos de Mesa: \n");
					quitar_productos(productosJM,cantidadJM,codigosJM,precioJM,desJM); //muestra productos que ha comprado
					}
				break;
				case 2:	
					system("cls");
					printf("Departamento de Libros:\n\n");
					listas(productosLI,precioLI,desLI,codigosLI, cantidadLI); //muestra producto
					system("cls");
					do{
						printf("Desea ver los productos y/o retirar alguno de esta categoria (1= si 0=no)" ); 
						scanf("%d",&res);
					}while(!(res>=0&&res<=1));
					if (res==1){
					printf("Articulos comprados del departamento de Libros: \n");
					quitar_productos(productosLI,cantidadLI,codigosLI,precioLI,desLI); //muestra productos que ha comprado
					}	
				break;
				case 3:
					system("cls");
					printf("Departamento de Muebles:\n\n");
					listas(productosMU,precioMU,desMU,codigosMU, cantidadMU); //muestra producto
					system("cls");
					do{
						printf("Desea ver los productos y/o retirar alguno de esta categoria (1= si 0=no)" ); 
						scanf("%d",&res);
					}while(!(res>=0&&res<=1));
					if (res==1){
					printf("Articulos comprados del depatamento de Muebles: \n");
					quitar_productos(productosMU,cantidadMU,codigosMU,precioMU,desMU); //muestra productos que ha comprado
					}
				break;
				case 4:
					system("cls");
					printf("Departamento de Zapatos:\n\n");
					listas(productosZA,precioZA,desZA,codigosZA, cantidadZA); //muestra producto
					system("cls");
					do{
						printf("Desea ver los productos y/o retirar alguno de esta categoria (1= si 0=no)" ); 
						scanf("%d",&res);
					}while(!(res>=0&&res<=1));
					if (res==1){
					printf("Articulos comprados del departamento de Zapatos: \n");
					quitar_productos(productosZA,cantidadZA,codigosZA,precioZA,desZA); //muestra productos que ha comprado
					}
				break;
				case 5:
					system("cls");
					printf("Departamento de Coleccionables:\n\n");
					listas(productosCO,precioCO,desCO,codigosCO, cantidadCO);//muestra producto
					system("cls");
					do{
						printf("Desea ver los productos y/o retirar alguno de esta categoria (1= si 0=no)" ); 
						scanf("%d",&res);
					}while(!(res>=0&&res<=1));
					if (res==1){
					printf("Articulos comprados del departamento de Coleccionables: \n");
					quitar_productos(productosCO,cantidadCO,codigosCO,precioZA,desZA); //muestra productos que ha comprado
					}
				break;
				case 6:
					system("cls");
					printf("Departamento de Accesorios:\n\n");
					listas(productosAC,precioAC,desAC,codigosAC, cantidadAC);//muestra producto
					system("cls");
					do{
						printf("Desea ver los productos y/o retirar alguno de esta categoria (1= si 0=no)" ); 
						scanf("%d",&res);
					}while(!(res>=0&&res<=1));
					if (res==1){
					printf("Articulos comprados del departamento de Accesorios: \n");
					quitar_productos(productosAC,cantidadAC,codigosAC,precioZA,desZA); //muestra productos que ha comprado
					}
				break;
				case 7:
					system("cls");
					printf("Departamento de Ropa deportiva:\n\n");
					listas(productosRP,precioRP,desRP,codigosRP, cantidadRP);//muestra producto
					system("cls");
					do{
						printf("Desea ver los productos y/o retirar alguno de esta categoria (1= si 0=no)" ); 
						scanf("%d",&res);
					}while(!(res>=0&&res<=1));
					if (res==1){
					printf("Articulos comprados del departamento de Ropa deportiva: \n");
					quitar_productos(productosRP,cantidadRP,codigosRP,precioRP,desRP); //muestra productos que ha comprado
					}
				break;
				case 8:
					system("cls");
					printf("Departamento de Maquillaje:\n\n");
					listas(productosMA,precioMA,desMA,codigosMA, cantidadMA);//muestra producto
					system("cls");
					do{
						printf("Desea ver los productos y/o retirar alguno de esta categoria (1= si 0=no)" ); 
						scanf("%d",&res);
					}while(!(res>=0&&res<=1));
					if (res==1){
					printf("Articulos comprados del departamento de Maquillaje: \n");
					quitar_productos(productosMA,cantidadMA,codigosMA,precioMA,desMA); //muestra productos que ha comprado
					}
				break;
				case 9:
					system("cls");
					printf("Departamento de Videojuegos:\n\n");
					listas(productosVI,precioVI,desVI,codigosVI, cantidadVI);//muestra producto
					system("cls");
					do{
						printf("Desea ver los productos y/o retirar alguno de esta categoria (1= si 0=no)" ); 
						scanf("%d",&res);
					}while(!(res>=0&&res<=1));
					if (res==1){
					printf("Articulos comprados del departamento de Videojuegos: \n");
					quitar_productos(productosVI,cantidadVI,codigosVI,precioVI,desVI); //muestra productos que ha comprado
					} 
				break;	
				case 10:
					system("cls");
					printf("Departamento de Electronica:\n\n");
					listas(productosEL,precioEL,desEL,codigosEL, cantidadEL);//muestra producto
					system("cls");
					do{
						printf("Desea ver los productos y/o retirar alguno de esta categoria (1= si 0=no)" ); 
						scanf("%d",&res);
					}while(!(res>=0&&res<=1));
					if (res==1){
					printf("Articulos comprados del departamento de Electronica: \n");
					quitar_productos(productosEL,cantidadEL,codigosEL,precioVI,desVI); //muestra productos que ha comprado
					}
				break;															
				case 11:
					system("cls");
					printf("Articulos comprados en todos los departamentos: \n"); //muestra producto comprados
					printf("Producto                      Cantidad    Precio unitario    Descuento   Subtotal\n");
					nota_parcial_de_compra(productosJM,cantidadJM,precioJM,desJM);
					nota_parcial_de_compra(productosLI,cantidadLI,precioLI,desLI);		
					nota_parcial_de_compra(productosMU,cantidadMU,precioMU,desMU);
					nota_parcial_de_compra(productosZA,cantidadZA,precioZA,desZA);
					nota_parcial_de_compra(productosCO,cantidadCO,precioCO,desCO);
					nota_parcial_de_compra(productosAC,cantidadAC,precioAC,desAC);
					nota_parcial_de_compra(productosRP,cantidadRP,precioRP,desRP);
					nota_parcial_de_compra(productosMA,cantidadMA,precioMA,desMA);
					nota_parcial_de_compra(productosVI,cantidadVI,precioVI,desVI);
					nota_parcial_de_compra(productosEL,cantidadEL,precioEL,desEL);
					printf("Nota: si quiere regresar algun producto,hacerlo en su categoria correspondiente.\n");
					system("pause");
				break;
				
			}//fin del switch
		}
	}while(opcion!=12);
	//Sumado de precios
	for(i=0; i<20; i++) 
	{
		total=total+((precioJM[i]-desJM[i])*cantidadJM[i]);
		total=total+((precioLI[i]-desLI[i])*cantidadLI[i]);
		total=total+((precioMU[i]-desMU[i])*cantidadMU[i]);
		total=total+((precioZA[i]-desZA[i])*cantidadZA[i]);
		total=total+((precioCO[i]-desCO[i])*cantidadCO[i]);
		total=total+((precioAC[i]-desAC[i])*cantidadAC[i]);
		total=total+((precioRP[i]-desRP[i])*cantidadRP[i]);
		total=total+((precioMA[i]-desMA[i])*cantidadMA[i]);
		total=total+((precioVI[i]-desVI[i])*cantidadVI[i]);
		total=total+((precioEL[i]-desEL[i])*cantidadEL[i]);
	}
	printf("%.2f \n", total);
	system("pause");
	//agregar lo de direccion
	//agrregar condicion de + de 10000
	if(total>0){
	system("cls");
		opcion2=menu2();
			switch(opcion2){
				case 1: //pago en oxxo
					printf("Pago de %.2f\n", total);
					pago_oxxo();
				break;
				case 2: // pago con targeta
					opcion3=menu3();	 
					 switch(opcion3){
						case 1:
							VISA();
						break;
						case 2:
							MasterCard();
						break;
						case 3:
							AmericanExpress();
						break;
						} //fin de seleccion de pago
				break;
				case 3: //pago con paypal
					pagar_con_paypal();
				break;
				case 4: //pago en efectivo
					printf("cuando llege el paquete, page el monto al cartero, gracias \n");
					printf("El monto es %.2f\n", total);
					system("pause");
				break;
			} //fin de segundo swich
	
	
	
	system("cls");
	
	printf("Producto                      Cantidad    Precio unitario    Descuento   Subtotal\n");
	nota_parcial_de_compra(productosJM,cantidadJM,precioJM,desJM);
	nota_parcial_de_compra(productosLI,cantidadLI,precioLI,desLI);		
	nota_parcial_de_compra(productosMU,cantidadMU,precioMU,desMU);
	nota_parcial_de_compra(productosZA,cantidadZA,precioZA,desZA);
	nota_parcial_de_compra(productosCO,cantidadCO,precioCO,desCO);
	nota_parcial_de_compra(productosAC,cantidadAC,precioAC,desAC);
	nota_parcial_de_compra(productosRP,cantidadRP,precioRP,desRP);
	nota_parcial_de_compra(productosMA,cantidadMA,precioMA,desMA);
	nota_parcial_de_compra(productosVI,cantidadVI,precioVI,desVI);
	nota_parcial_de_compra(productosEL,cantidadEL,precioEL,desEL);
	printf("%.2f \n", total);
	}
	else
	{
		printf("Vuelva pronto.\n");
	}
	system("Pause");
}
