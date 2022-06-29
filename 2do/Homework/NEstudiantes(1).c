#include<stdio.h>
#define n 3
// Declaracion de la estructura
struct estudiante
{
    char nombre[50];
    int matricula;
};

// Declaracion de la funcion
void display(struct estudiante estdnt[n]);


// Funcion principal
int main()
{
    struct estudiante std[n];
    int i;
for(i=0;i<n;i++){
    printf("Nombre del estudiante: ");
    scanf("%s", std[i].nombre);
    printf("Matricula: ");
    scanf("%d", &std[i].matricula);
}
// Paso de la variable de estructura como argumento
    display(std);
    return 0;
}

// Definicion de la funcion con argumento de tipo struc
void display(struct estudiante estdnt[n]){
	int i;
for(i=0;i<n;i++){
  printf("\nNombre del estudiante: %s", estdnt[i].nombre);
  printf("\nMatricula: %d\n", estdnt[i].matricula);
}
}

