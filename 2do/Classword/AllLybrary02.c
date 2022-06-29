#include<stdio.h>
#include<string.h>


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

int i;

// Declaracion de un arreglo de estructuras 
// de 100 elementos denominado libros

struct Todos_Libros libros[100];

// Inicializacion (Definicion) de los miembros
strcpy(libros[0].titulo,"Programacion I");
strcpy(libros[0].autor,"Orduz, J.");
strcpy(libros[0].editorial,"Patito-Hill");
libros[0].anio = 2018;

//Escribe el unico titulo de la obra que esta almacenado, no hace falta un for o while proque solo hay uno
printf("Este libro es: %s %s %s %d\n",libros[0].titulo,libros[0].autor, libros[0].editorial, libros[0].anio);

return 0;
}
