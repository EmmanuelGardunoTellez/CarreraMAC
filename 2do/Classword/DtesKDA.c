#include<stdio.h>

struct corredor{
	char nombre[30]; //Se crea espacio para almacenar apodos
	char Server[5];  //Almacena nombre del servidor
	int Kills; //Almacena el numero de asesinatos hechos por el usuario en el juego
	int Death; //Almacena el numero de muertes hechos por el usuario en el juego
	int Assist; //Almacena el numero de aseistencias hechos por el usuario en el juego
}
 crrdr1={ //Almacena la primera tanda de datos
	"OsoPrroOso",
	"LAN",
	25,
	2,
	0,
	}, 
  crrdr2={ //Almacena la segunda tanda de datos
	"OvejaPretensiosa",
	"EUW",
	15,
	3,
	20,
	},
	crrdr3={ //Almacena la tercera tanda de datos
	"PeresosoCliche",
	"LAS",
	25,
	8,
	25,
	},
	crrdr4={ //Almacena la cuarta tanda de datos
	"NombreChino",
	"KOR",
	7,
	2,
	19,
	};


int main()
{
int prom; //Ayuda a almacenar el promedio de los 4 jugadores
printf("Formula de KDA Asesinatos + Asistencias entre Muertes");
printf("\n");
printf("Hola %s del servidor de %s, tienes %d Asesinatos, tienes %d Muertas y tienes %d Asistencias", crrdr1.nombre,crrdr1.Server, crrdr1.Kills, crrdr1.Death,crrdr1.Assist);
printf("\n");
printf("Tu KDA es de %i",(crrdr1.Kills+crrdr1.Assist)/crrdr1.Death);
printf("\n");
printf("Hola %s del servidor de %s, tienes %d Asesinatos, tienes %d Muertas y tienes %d Asistencias", crrdr2.nombre,crrdr2.Server, crrdr2.Kills, crrdr2.Death,crrdr2.Assist);
printf("\n");
printf("Tu KDA es de %i",(crrdr2.Kills+crrdr2.Assist)/crrdr2.Death);
printf("\n");
printf("Hola %s del servidor de %s, tienes %d Asesinatos, tienes %d Muertas y tienes %d Asistencias", crrdr3.nombre,crrdr3.Server, crrdr3.Kills, crrdr3.Death,crrdr3.Assist);
printf("\n");
printf("Tu KDA es de %i",(crrdr3.Kills+crrdr3.Assist)/crrdr3.Death);
printf("\n");
printf("Hola %s del servidor de %s, tienes %d Asesinatos, tienes %d Muertas y tienes %d Asistencias", crrdr4.nombre,crrdr4.Server, crrdr4.Kills, crrdr4.Death,crrdr4.Assist);
printf("\n");
printf("Tu KDA es de %i",(crrdr4.Kills+crrdr4.Assist)/crrdr4.Death);
prom= (((crrdr1.Kills+crrdr1.Assist)/crrdr1.Death)+((crrdr2.Kills+crrdr2.Assist)/crrdr2.Death)+((crrdr3.Kills+crrdr3.Assist)/crrdr3.Death)+((crrdr4.Kills+crrdr4.Assist)/crrdr4.Death))/4;
printf("El promedio de KDA de los 4 usuarios: %i",prom);

return 0;
}
