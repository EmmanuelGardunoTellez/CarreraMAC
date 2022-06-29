/* ********************* TEXTO SIN ACENTOS *********************/
// Recuerda documentar tus codigos
 
#include<stdio.h>
#include<string.h>
// Declaracion de la estructura
struct estudiante
{
    char nombre[50];
    char apellidos[50];
    char carrera[50];
    int matricula;
    int semestre;
};
 
// Declaracion de la funcion
void display(struct estudiante estdnt);
 
 
// Funcion principal
int main()
{
    struct estudiante std;
 
    printf("Nombre del estudiante: ");
    fflush(stdin);
    scanf("%[^\n]%*c", std.nombre);
    printf("Apellidos del estudiante: ");
    fflush(stdin);
    scanf("%[^\n]%*c", std.apellidos);
    printf("Carrera del estudiante: ");
    fflush(stdin);
    scanf("%[^\n]%*c", std.carrera);
    printf("Matricula: ");
    scanf("%d", &std.matricula);
    printf("Semestre: ");
    scanf("%d", &std.semestre);
     
// Paso de la variable de estructura como argumento
    display(std);
    return 0;
}
 
// Definicion de la funcion con argumento de tipo struc
void display(struct estudiante estdnt){
	
	strcat(estdnt.nombre, estdnt.apellidos);
  printf("\nNombre del estudiante: %s", estdnt.nombre);
  printf("\nCarrera del estudiante: %s", estdnt.carrera);
  printf("\nMatricula: %d", estdnt.matricula);
  printf("\nSemestre: %d\n", estdnt.semestre);
}
