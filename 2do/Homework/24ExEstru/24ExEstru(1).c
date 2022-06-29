#include<stdio.h>
#include<string.h>
#define n 10
FILE *fd;

struct ParYImpar //Escructura para almacenar los numeros pares e impares
{
	int p, i;
};

struct Alfa //Escructura para almacenar letras mayusculas y minusculas
{
	int MA;
	int mi;
};
struct NumYLetras //Escructura para almacenar los numeros y letas
{
		//no supe como hacer esto
};
struct Datos //Escructura para almacenar los datos de unas personas
{
	char name[70], apellido[25], ciudad[20];
};
struct clima //Escructura para almacenar datos del clima
{
char month[40];
char day[3];
char year[5];
char clime[5];
};

int main()
{
	struct ParYImpar Number[n];
	struct Alfa AL[27]; //Numeros que almacena de los pares e impares
	int r, i;
	char ora[50];
	for(r=1;r<n;r++) //Da los nueros pares e impares
	{
		Number[r].p=(2*r);
		Number[r].i=(2*r)-1;
	}
	for(r=1;r<n;r++){ //Imprime los impares
		printf("%i, ",Number[r].i);
	}
	printf("\n");
	for(r=1;r<n;r++){ //Imprime los pares
		printf("%i, ",Number[r].p);
	}
	printf("\n");
	for(r=1;r<27;r++) //Imprime las las letras en mayusculas y minusculas
	{
		AL[r].MA=64+r;
		AL[r].mi=96+r;
	}
	printf("\n");
 	for(r=1;r<27;r++){
		printf("%c			%c\n",AL[r].MA, AL[r].mi);
		
	}
	
/*	printf("Como te gusta que te llamen (sin espacios)? ");
	scanf("%[^\n]", ora);*/

	struct Datos perso[10]; //Datos de personas
	
	strcpy(perso[0].name, "Mario");
	strcpy(perso[0].apellido, "Garcia");
	strcpy(perso[0].ciudad, "Mexico");
	strcpy(perso[1].name, "Hugo");
	strcpy(perso[1].apellido, "Perez");
	strcpy(perso[1].ciudad, "Mexico");
	strcpy(perso[2].name, "Luisa");
	strcpy(perso[2].apellido, "Gomez");
	strcpy(perso[2].ciudad, "Mexico");
	strcpy(perso[3].name, "Roberto");
	strcpy(perso[3].apellido, "Gomez");
	strcpy(perso[3].ciudad, "Mexico");
	strcpy(perso[4].name, "Orquidea");
	strcpy(perso[4].apellido, "Mirales");
	strcpy(perso[4].ciudad, "Mexico");
	strcpy(perso[5].name, "Luis");
	strcpy(perso[5].apellido, "Garcia");
	strcpy(perso[5].ciudad, "Mexico");
	strcpy(perso[6].name, "Omar");
	strcpy(perso[6].apellido, "Belmont");
	strcpy(perso[6].ciudad, "Mexico");
	strcpy(perso[7].name, "Peredo");
	strcpy(perso[7].apellido, "Lopez");
	strcpy(perso[7].ciudad, "Mexico");
	strcpy(perso[8].name, "Manuel");
	strcpy(perso[8].apellido, "Gutierres");
	strcpy(perso[8].ciudad, "Mexico");
	strcpy(perso[9].name, "Mario");
	strcpy(perso[9].apellido, "Colin");
	strcpy(perso[9].ciudad, "Mexico");
	
	for(r=0;r<10;r++) //Concatenacion de datos
	{
		strcat( perso[r].name, " ");
		strcat( perso[r].name, perso[r].apellido );
		strcat( perso[r].name, " vive en " );
		strcat( perso[r].name, perso[r].ciudad );
		strcat( perso[r].name, "\n");
	}
	FILE *archivo = fopen("datos.txt", "w"); //Para .doxc (word) y .xlsxc (excel) no loe lee y almacena la info en un blog de notas y w es para escribir
    for(r=0;r<10;r++){
	fprintf(archivo, perso[r].name);
}
    fclose(archivo);
    
    
    struct clima clm[2]; //Datos de clima
    
    strcpy(clm[0].month,"Enero,");
    strcpy(clm[0].day,"25");
    strcpy(clm[0].year,"2019");
    strcpy(clm[0].clime,"19");
    
    strcpy(clm[1].month,"Enero,");
    strcpy(clm[1].day,"26");
    strcpy(clm[1].year,"2019");
    strcpy(clm[1].clime,"21");
    
    strcpy(clm[2].month,"Enero,");
    strcpy(clm[2].day,"27");
    strcpy(clm[2].year,"2019");
    strcpy(clm[2].clime,"20");
    
    for(r=0;r<3;r++) //Concatenacion de los datos de clima
	{
		strcat( clm[r].month, " ");
		strcat( clm[r].month, clm[r].day);
		strcat( clm[r].month, " del ");
		strcat( clm[r].month, clm[r].year);
		strcat( clm[r].month, " con temperatura de ");
		strcat( clm[r].month, clm[r].clime);
		strcat( clm[r].month, "\n");
	}
    
    FILE *archivo2 = fopen("clima.txt", "w"); //Para .doxc (word) y .xlsxc (excel) no loe lee y w es escribir
    for(r=0;r<3;r++){
	fprintf(archivo2, clm[r].month);
}
    fclose(archivo2);
    
    printf("\n\nPor facor escriba los datos del  clima con este orden, Mes dia del año con temperatura de (temperatura)\n");
    printf("Nota leer los climas antes y presione 'Ctrl+z' para acabar de escribir\n");

    int c;
	char direccion[] = "C:\\Users\\EMANUEL\\Dropbox\\progra2\\Homework\\24ExEstru\\clima.txt"; //Busca el archivo para actualizarlo

	
	fd = fopen(direccion,"at"); //at = add texto - agregar texto;
	
	if(fd == NULL){
		printf("Error al tratar de crear el archivo"); //Por si no esta
		return 1;
	}
	
	while((c=getchar())!= EOF){ //Agregar tezto y se detiene con "Ctrl + z"
		fputc(c,fd);
	}
	
	
	fclose(fd);
    
    return 0;
}
	
