#include <stdio.h>
#include <stdlib.h>

typedef struct DatosPer{
	char *name;
	char *apellido;
	char *date1;
	char *date2;
	char *date3;
	char *celular;
	char *direccion; 
	char *correo;
} PER;

typedef struct DatosAca{
	char *prepa;
	char *uni;
} ACA;

typedef struct DatosExp{
	char *trabajo1;
	char *trabajo2;
}EXP;

typedef struct DatosIdi{
	char *idioma1;
	char *idioma2;
} IDI;

typedef struct DatosInfo{
	char *info1;
	char *info2;
	char *info3;
}INFO;

typedef struct DatosInt{
	char *int1;
	char *int2;
	char *int3;
} INTE;

typedef struct DatosRef{
	char *ref;
}REFE;

typedef struct DatosNTrabajo{
	char *trabajo;
	char *EmbresaNueva;
}NT;

typedef struct Datos{
	PER per;
	ACA aca;
	EXP exp;
	IDI idi;
	INFO info;
	REFE refe;
	INTE inte;
	NT nt;
} DATOS;

void main(){
	DATOS emmanuel;
	int respuesta;
	FILE *CV1 = fopen("CV1.txt", "w");
	FILE *CV2 = fopen("CV2.txt", "w");
	FILE *Carta = fopen("carta.txt", "w");
	emmanuel.per.name = (char *) malloc(25 * sizeof(char));
	emmanuel.per.apellido = (char *) malloc(25 * sizeof(char));
	emmanuel.per.date1 = (char *) malloc(3 * sizeof(char));
	emmanuel.per.date2 = (char *) malloc(15 * sizeof(char));
	emmanuel.per.date3 = (char *) malloc(5 * sizeof(char));
	emmanuel.per.celular = (char *) malloc(15 * sizeof(char));
	emmanuel.per.correo = (char *) malloc(25 * sizeof(char));
	emmanuel.per.direccion = (char *) malloc(100 * sizeof(char));
	emmanuel.aca.prepa = (char *) malloc(50 * sizeof(char));
	emmanuel.aca.uni = (char *) malloc(50 * sizeof(char));
	emmanuel.exp.trabajo1 = (char *) malloc(50 * sizeof(char));
	emmanuel.exp.trabajo2 = (char *) malloc(50 * sizeof(char));
	emmanuel.idi.idioma1 = (char *) malloc(20 * sizeof(char));
	emmanuel.idi.idioma2 = (char *) malloc(20 * sizeof(char));
	emmanuel.info.info1 = (char *) malloc(100 * sizeof(char));
	emmanuel.info.info2 = (char *) malloc(100 * sizeof(char));
	emmanuel.info.info3 = (char *) malloc(100 * sizeof(char));
	emmanuel.inte.int1 = (char *) malloc(100 * sizeof(char));
	emmanuel.inte.int2 = (char *) malloc(100 * sizeof(char));
	emmanuel.inte.int3 = (char *) malloc(100 * sizeof(char));
	emmanuel.refe.ref = (char *) malloc(100 * sizeof(char));
	emmanuel.nt.trabajo = (char *) malloc(100 * sizeof(char));
	emmanuel.nt.EmbresaNueva = (char *) malloc(100 * sizeof(char));
	
	//Recepcion de datos
	printf("Genedador de CV\n");
	printf("Dame tus datos personales:\n");
	printf("Nombre: ");
	scanf("%[^\n]%*c", emmanuel.per.name);
	printf("Apellido: ");
	scanf("%[^\n]%*c", emmanuel.per.apellido);
	printf("Fecha de nacimeinto (Dia): ");
	scanf("%[^\n]%*c", emmanuel.per.date1);
	printf("Fecha de nacimeinto (Mes): ");
	scanf("%[^\n]%*c", emmanuel.per.date2);
	printf("Fecha de nacimeinto (Anio): ");
	scanf("%[^\n]%*c", emmanuel.per.date3);
	printf("Numero celular: ");
	scanf("%[^\n]%*c", emmanuel.per.celular);
	printf("Direccion de su casa: ");
	scanf("%[^\n]%*c", emmanuel.per.direccion);
	printf("Correo electronico: ");
	scanf("%[^\n]%*c", emmanuel.per.correo);
	printf("Datos academicos:\n");
	printf("Preparatoria o equivalente en donde estudiaste: ");
	scanf("%[^\n]%*c", emmanuel.aca.prepa);
	printf("Universidad en donde estudias o obtuviste el titulo, decir cual has obtenido: ");
	scanf("%[^\n]%*c", emmanuel.aca.uni);
	printf("Datos de trabajos (en caso de no tener dejar un " "):\n");
	printf("Primer trabajo: ");
	scanf("%[^\n]%*c", emmanuel.exp.trabajo1);
	printf("Segundo trabajo: ");
	scanf("%[^\n]%*c", emmanuel.exp.trabajo2);
	printf("Datos de idiomas (en caso de no tener dejar un " "):\n");
	printf("Primer idioma 1: ");
	scanf("%[^\n]%*c", emmanuel.idi.idioma1);
	printf("Segundo idioma 2: ");
	scanf("%[^\n]%*c", emmanuel.idi.idioma2);
	printf("Datos de informatica (en caso de no tener dejar un " "):\n");
	printf("Primer informatica: ");
	scanf("%[^\n]%*c", emmanuel.info.info1);
	printf("Segundo informatica: ");
	scanf("%[^\n]%*c", emmanuel.info.info2);
	printf("Tercer informatica: ");
	scanf("%[^\n]%*c", emmanuel.info.info3);
	printf("Datos interesantes de ti (en caso de no tener dejar un " "):\n");
	printf("Primer dato: ");
	scanf("%[^\n]%*c", emmanuel.inte.int1);
	printf("Segundo dato: ");
	scanf("%[^\n]%*c", emmanuel.inte.int2);
	printf("Tercer dato: ");
	scanf("%[^\n]%*c", emmanuel.inte.int3);
	printf("Referencia:\n");
	printf("Alguna referencia: ");
	scanf("%[^\n]%*c", emmanuel.refe.ref);
	printf("Nuevo trabajo al que postulas: ");
	scanf("%[^\n]%*c", emmanuel.nt.trabajo);
	printf("Nombre de la nueva empresa: ");
	scanf("%[^\n]%*c", emmanuel.nt.EmbresaNueva);
	
	//CV uno con direccion y otra sin direccion
	fprintf(CV1, "\t\tCURRICULUM VITAE\n");
	fprintf(CV2, "\t\tCURRICULUM VITAE\n");
	
	fprintf(CV1, "DATOS PERSONALES\n");
	fprintf(CV2, "DATOS PERSONALES\n");
	
	fprintf(CV1,"Nombre y apellidos: %s %s\n", emmanuel.per.name , emmanuel.per.apellido);
	fprintf(CV2,"Nombre y apellidos: %s %s\n", emmanuel.per.name , emmanuel.per.apellido);
	
	fprintf(CV1, "\nFecha de nacimiento: %s de %s de %s\n", emmanuel.per.date1, emmanuel.per.date2, emmanuel.per.date3);
	fprintf(CV2, "\nFecha de nacimiento: %s de %s de %s\n", emmanuel.per.date1, emmanuel.per.date2, emmanuel.per.date3);
	
	fprintf(CV1, "Numero telefonico: %s\t", emmanuel.per.celular);
	fprintf(CV2, "Numero telefonico: %s\t", emmanuel.per.celular);
	
	fprintf(CV1, "Correo electronico: %s\n", emmanuel.per.celular);
	fprintf(CV2, "Correo electronico: %s\n", emmanuel.per.celular);
	
	fprintf(CV1, "Direccion de domicilio: %s\n", emmanuel.per.direccion);
	
	fprintf(CV1, "\n\nFORMACION ACADEMICA\n");
	fprintf(CV2, "\n\nFORMACION ACADEMICA\n");
	
	fprintf(CV1, "Preparatoria: %s\n", emmanuel.aca.prepa);
	fprintf(CV2, "Preparatoria: %s\n", emmanuel.aca.prepa);
	
	fprintf(CV1, "Universidad: %s\n", emmanuel.aca.uni);
	fprintf(CV2, "Universidad: %s\n", emmanuel.aca.uni);
	
	fprintf(CV1, "\n\nFORMACION LABORAL\n");
	fprintf(CV2, "\n\nFORMACION LABORAL\n");
	
	fprintf(CV1, "1.- %s\n", emmanuel.exp.trabajo1);
	fprintf(CV2, "1.- %s\n", emmanuel.exp.trabajo1);
	
	fprintf(CV1, "2.- %s\n", emmanuel.exp.trabajo2);
	fprintf(CV2, "2.- %s\n", emmanuel.exp.trabajo2);
	
	fprintf(CV1, "\n\nIDIOMAS\n");
	fprintf(CV2, "\n\nIDIOMAS\n");
	
	fprintf(CV1, "%s\n", emmanuel.idi.idioma1);
	fprintf(CV2, "%s\n", emmanuel.idi.idioma1);
	
	fprintf(CV1, "%s\n", emmanuel.idi.idioma2);
	fprintf(CV2, "%s\n", emmanuel.idi.idioma2);
	
	fprintf(CV1, "\n\nINFORMATICA\n");
	fprintf(CV2, "\n\nINFORMATICA\n");
	
	fprintf(CV1, "%s\n", emmanuel.info.info1);
	fprintf(CV2, "%s\n", emmanuel.info.info1);
	
	fprintf(CV1, "%s\n", emmanuel.info.info2);
	fprintf(CV2, "%s\n", emmanuel.info.info2);
	
	fprintf(CV1, "%s\n", emmanuel.info.info3);
	fprintf(CV2, "%s\n", emmanuel.info.info3);
	
	fprintf(CV1, "\n\nREFERENCIA\n");
	fprintf(CV2, "\n\nREFERENCIA\n");
	
	fprintf(CV1, "%s\n", emmanuel.refe.ref);
	fprintf(CV2, "%s\n", emmanuel.refe.ref);
	
	fprintf(Carta, "Asunto: Candidatura al puesto de %s\n\n", emmanuel.nt.trabajo);
	fprintf(Carta, "Estimada(o):\n");
	fprintf(Carta, "Mi nombre es:%s %s\n", emmanuel.per.name , emmanuel.per.apellido);
	fprintf(Carta, "A través de esta carta, me gustaría expresar mi interés por el puesto de %s, ya que este corresponde perfectamente a las misiones previas que he realizado y al sector dentro del cual me gustaría seguir evolucionando. De igual manera, quisiera mencionar que, gracias a mis experiencias y proyectos personales desarrollados, he podido desarrollar ciertas capacidades que hoy desearía poner a vuestra disposición:\n", emmanuel.nt.trabajo);
	fprintf(Carta, "Mis conocimientos y experiencias en el sector laboral\n");
	fprintf(Carta, "Mi manejo de idiomas como: %s, %s \n", emmanuel.idi.idioma1, emmanuel.idi.idioma2);
	fprintf(Carta, "Mi trabajo con equipos me han ayudado a desarrollar mis capacidades para el trabajo en equipo y a adaptarme rápidamente ante diferentes ecosistemas laborales.\n");
	fprintf(Carta, "Espero que mi perfil pueda ser útil para poder desempeñar el cargo propuesto y tener la oportunidad de discutir más acerca de la empresa y sus objetivos.\n");
	fprintf(Carta, "%s %s\n", emmanuel.per.name , emmanuel.per.apellido);
	fprintf(Carta, "Un cordial saludo.\n");
	
	
	free(emmanuel.per.name);free(emmanuel.per.apellido);
	free(emmanuel.per.date1);free(emmanuel.per.date2);
	free(emmanuel.per.date3);free(emmanuel.per.celular);
	free(emmanuel.per.correo);free(emmanuel.per.direccion);
	free(emmanuel.aca.prepa);free(emmanuel.aca.uni);
	free(emmanuel.exp.trabajo1);free(emmanuel.exp.trabajo2);
	free(emmanuel.idi.idioma1);free(emmanuel.idi.idioma2);
	free(emmanuel.info.info1);free(emmanuel.info.info2);
	free(emmanuel.info.info3);free(emmanuel.inte.int1);
	free(emmanuel.inte.int2);free(emmanuel.inte.int3);
	free(emmanuel.refe.ref);free(emmanuel.nt.trabajo);
	free(emmanuel.nt.EmbresaNueva);
}
