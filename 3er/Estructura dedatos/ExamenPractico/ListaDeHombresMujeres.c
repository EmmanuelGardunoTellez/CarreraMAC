#include<stdio.h>
#include <string.h>

typedef struct Persona{
	char persona[20];
	char genero[10];
	int edad;
}Per;

int genero()
{
	int opcion;
	printf("1 si es mujer o 2 si es hombre\n");
	do
	{
		printf("Opccion: ");
		scanf("%d",&opcion);
	}while(!(opcion>=1&&opcion<=2));
	return opcion;
}

int main(){
	Per perso[10];
	int opcion, i;
	int hombres = 0, mujeres = 0;
	int mayores = 0, menores = 0;
	
	for(i=0;i<10;i++){
		perso[i].edad=-1;
	}
	printf("Arreglo de 10 personas, rrellena lo que se solicita:\n");
	system("pause");
	system("cls");
	for(i=0;i<10;i++){
		printf("Dame el genero de la persona numero %d:\n", i+1);
		opcion = genero();
		switch(opcion){
				case 1:
					strcpy(perso[i].genero, "Mujer");
					mujeres++;
					break;
				case 2:
					strcpy(perso[i].genero, "Hombre");
					hombres++;
					break;
				}
				
				fflush(stdin);
				printf("Ingresa tu nombre: ");
				scanf("%s",perso[i].persona);
    	
    	printf("\n\nTu edad se negara si no es mayor o igual a 0)");
    	do{
    		printf("\n\nDime tu edad: ");
    		scanf("%d", &perso[i].edad);
		}while(perso[i].edad < 0);
    
    	
    	system("cls");
	}
	
	for(i=0;i<10;i++){
		if(perso[i].edad <= 10){
			menores++;
		}
		else
		if(perso[i].edad >= 60){
			mayores++;
		}
	}
	
	
	for(i=0;i<10;i++){
		printf("\nPersona numero : %d",i+1);
		printf("\nPersona: %s",perso[i].persona);
		printf("\nGenero: %s",perso[i].genero);
		printf("\nEdad: %d\n",perso[i].edad);
	}
	printf("\n\nNumero de hombres: %d       Numero de mujeres: %d",hombres,mujeres);
	printf("\nMayores de edad: %d       Menores de edad: %d\n",mayores,menores);
	system("pause");
	
	return 1;
}
