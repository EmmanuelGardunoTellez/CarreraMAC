#include<stdio.h>

struct corredor{
	char nickname[30]; //Se crea espacio para almacenar apodos
	char Server[4]; //Se crea espacio para almacenar el servidor
	int KDA; //Guarda el kda que hay en to
	float OroPorSegundo;//Guarda el oro por segundo que genera el usuario

} crrdr1={ //Almacena la primer tanda de datos
	"OsoPrroOso",
	"LAN",
	10,
	5.6,
	}, 
  crrdr2={  //Almacena la segunda tanda de datos
	"OvejaPretensiosa",
	"EUW",
	9,
	5.3,
	},
	crrdr3={ //Almacena la tercera tanda de datos
	"PeresosoCliche",
	"LAS",
	8,
	8.9,
	},
	crrdr4={  //Almacena la cuarta tanda de datos
	"NombreChino",
	"KOR",
	20,
	10.5,
	};


int main()
{	
printf("Hola invocador, ingresa tu nombre de Invocador:");
printf("\n");
printf("Hola %s del servidor de %s, tu KDA es: %i y tu oro por segundo es: %.1f ", crrdr1.nickname,crrdr1.Server, crrdr1.KDA, crrdr1.OroPorSegundo);
printf("\n\n");
printf("Hola %s del servidor de %s, tu KDA es: %i y tu oro por segundo es: %.1f ", crrdr2.nickname,crrdr2.Server, crrdr2.KDA, crrdr2.OroPorSegundo);
printf("\n\n");
printf("Hola %s del servidor de %s, tu KDA es: %i y tu oro por segundo es: %.1f ", crrdr3.nickname,crrdr3.Server, crrdr3.KDA, crrdr3.OroPorSegundo);


return 0;
}
