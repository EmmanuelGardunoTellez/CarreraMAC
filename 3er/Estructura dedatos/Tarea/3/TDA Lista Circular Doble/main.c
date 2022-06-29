#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "lista.h"

int main(int argc, const char * argv[]) {

 	ListaCircularDoble * lcd = inicializarLista();
 	int opcion, opcion_ingreso, opcion_borrado, opcion_listado, posicion, existencia, res = 1, codigo;
 	char * marca;
 	while(res == 1){
 		system("cls");
 		printf("***** Zapateria MAC FES Acatlan ******\n\n");
 		printf("Seleccione una Opcion: ");
 		printf("\n[1] Ingresar Articulo");
 		printf("\n[2] Remover Articulo");
 		printf("\n[3] Listar Articulos");
 		printf("\n[4] Articulos en Existencia");
 		printf("\n[5] Buscar por Codigo");
 		printf("\n[6] Buscar por Marca");
		printf("\n[7] Salir del Programa");
 		printf("\nOpcion: ");
 		scanf("%d", &opcion);
 		switch(opcion){
 			case 1: system("cls");
 				printf("\n\nSeleccione una Operacion: ");
 				printf("\n[1] Ingresar al Principio");
 				printf("\n[2] Ingresar al Final");
 				printf("\n[3] Ingresar en Alguna Posicion");
 				printf("\nOpcion: ");
 				scanf("%d", &opcion_ingreso);
 				switch (opcion_ingreso) {
 					case 1: insertar_frente(lcd);
 						printf("\nSe ingreso informacion correctamente\n");
 						break;
 					case 2: insertar_final(lcd);
 						printf("\nSe ingreso informacion correctamente\n");
 						break;
 					case 3: printf("\nIngrese posicion: ");
 						scanf("%d", &posicion);
 						insertar_en_posicion(lcd, posicion);
 						printf("\nSe ingreso informacion correctamente\n");
 						break;
 					default: printf("\nOpcion Invalida");
 						break;
 				}
 				break;
 			case 2: system("cls");
 				printf("\n\nSeleccione una Operacion: ");
 				printf("\n[1] Remover al Principio");
 				printf("\n[2] Remover al Final");
 				printf("\n[3] Remover en Alguna Posicion");
 				printf("\nOpcion: ");
 				scanf("%d", &opcion_borrado);
 				switch (opcion_borrado) {
 					case 1: borrar_frente(lcd);
 						printf("\nSe removio informacion correctamente\n");
 						break;
 					case 2: borrar_final(lcd);
 						printf("\nSe removio informacion correctamente\n");
 						break;
 					case 3: printf("\nIngrese posicion: ");
 						scanf("%d", &posicion);
 						borrar_en_posicion(lcd, posicion);
 						printf("\nSe removio informacion correctamente\n");
 						break;
 					default: printf("\nOpcion Invalida");
 						break;
 				}
 				break;
 			case 3: system("cls");
 				printf("\n\nSeleccione una Operacion: ");
 				printf("\n[1] Listar Ascendente");
 				printf("\n[2] Listar Descendente");
 				printf("\nOpcion: ");
 				scanf("%d", &opcion_listado);
 				switch (opcion_listado) {
 					case 1: desplegar_adelante(lcd);
 						break;
 					case 2: desplegar_inverso(lcd);
 						break;
 					default: printf("\nOpcion Invalida");
 						break;
 				}
 				break;
 			case 4: system("cls");
 				existencia = numero_nodos(lcd);
 				if(existencia == 1){
 					printf("\nHay %d articulo en existencia\n", existencia);
 				}
				else{
 					printf("\nHay %d articulos en existencia\n", existencia);
 				}
 				break;
 			case 5: system("cls");
 				printf("\nIngrese Codigo: ");
 				scanf("%d", &codigo);
 				buscar_codigo(lcd, codigo);
 				printf("\n");
 				break;
 			case 6: system("cls");
 				fflush(stdin);
 				printf("\nIngrese Marca: ");
 				if(fgets(buffer,64,stdin) == NULL) exit(0);
 				marca = (char *) malloc(strlen(buffer)+1);
 				strcpy(marca, buffer);
 				buscar_marca(lcd, marca);
 				printf("\n");
 				break;
 			case 7: system("cls");
 				printf("\nGoodbye!!!\n\n");
 				system("PAUSE");
 				exit(0);
 				break;
 			default: printf("\nOpcion Invalida");
 				break;
		}
 		printf("\nDesea Realizar Otra Operacion: ");
 		printf("\n[1] Si, [Otra Valor] No");
 		printf("\nOpcion: ");
 		scanf("%d", &res);
 	}

 	printf("\n");

 	return 0;
}
