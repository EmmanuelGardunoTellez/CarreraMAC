#include <stdio.h>
#include <stdlib.h>
#include "Zapateria.h"

int main(int argc, char *argv[]) {
	int op, resp;
	Zapateria * b1;
	b1 = inicializar(30);
	do{
		system("cls");
		printf("Seleccione una operacion: ");
		printf("\n[1] Agregar Zapato");
		printf("\n[2] Borrar Zapato");
		printf("\n[3] Listar Zapato");
		printf("\n[4] Capacidad de la Zapateria");
		printf("\n[5] Zapatos en existencia");
		printf("\n[6] Buscar zapato");
		printf("\n[7] Salir");
		printf("\nOpcion: ");
		scanf("%d", &op);
		switch(op){
			case 1:  insertar(b1);
					 printf("\nZapato agregado correctamente ...");
					 break;
			case 2:  borrar(b1);
					 printf("\nZapato borrado correctamente ...");
					 break;
			case 3:  printf("\nTotal de zapatos: %d\n", numZapatos(b1));
				     desplegar(b1);
					 break;
			case 4:  printf("\nCupo maximo: %d", capacidadZapateria(b1));
					 break;
			case 5:  printf("\nTotal de Zapatos: %d", numZapatos(b1));
					 break;
			case 7:  printf("\nHasta luego vuelva pronto!!");
					 printf("\n\nPresione un boton para terminar ...\n");
					 getch();
					 exit(0);
					 break;
			case 6:  desplegarUno(b1);	
			         break;
			default: printf("\nOpcion Invalida ...");
		}
		printf("\n\nDesea realizar otra operacion: ");
		printf("\n[1] Si  [2] No");
		printf("\nOpcion: ");
		scanf("%d", &resp);
	} while(resp == 1);
	return 0;
}
