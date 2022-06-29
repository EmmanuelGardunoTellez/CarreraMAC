#include<stdio.h>
#include<string.h>
#define n 10

// Declaracion de un arreglo de estructuras 
// de 100 elementos denominado libros
struct Todos_Libros //Estructura para almacenamiento de informacion
{
char titulo[30]; //Almacena el titulo
char autor[30];  //Almacena  el autor
char editorial[30]; //Almacena la editorial
int anio; //Almacena el año
};


// Funcion principal
int main()
{

int i,k; //Variables
// Declaracion de una variable de estructura
struct Todos_Libros libros[n];
/*Variables ya estableciadas previamente en el arreglo*/
strcpy(libros[0].titulo,"Programacion I");
strcpy(libros[0].autor,"Orduz, J.");
strcpy(libros[0].editorial,"Patito-Hill");
libros[0].anio = 2018;

strcpy(libros[1].titulo,"Programacion II");
strcpy(libros[1].autor,"Ducuara, A.");
strcpy(libros[1].editorial,"Patito-Hill");
libros[1].anio = 2019;

// Inicializacion (Definicion) de los miembros
printf("Este almacenador de libros, viene con dos ya preestablecidos.\n");
printf("Dija cuantos libros va a agregar: ");
	scanf("%i",&k);

for(i=2;i<(k+2); i++){ //Arreglo for paraleer los datos, tambien serviria while
	fflush(stdin); //Limpia las entradas de texto
	printf("Libro %d\n", i+1);
	printf("Nombre del libro: ");
    scanf("%[^\n]%*c", libros[i].titulo);
    printf("Nombre del autor: ");
    scanf("%[^\n]%*c", libros[i].autor);
    printf("Nombre del editorial: ");
    scanf("%[^\n]%*c", libros[i].editorial);
    printf("Anio: ", i+1);
    scanf("%i", &libros[i].anio);  
}
 //Lector de libros disponibles
	for(i=0; i<(k+2); i++){
printf("Este libro es: %s %s %s %d\n",libros[i].titulo,libros[i].autor, libros[i].editorial, libros[i].anio);
}

return 0;
}
