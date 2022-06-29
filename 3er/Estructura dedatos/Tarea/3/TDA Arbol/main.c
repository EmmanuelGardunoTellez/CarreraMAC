

#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

int main(int argc, char *argv[]) {
	
	Arbol * arbol = inicializarArbol();
    insertar_en_arbol(arbol, 6.5);
    insertar_en_arbol(arbol, 8.8);
    insertar_en_arbol(arbol, -3.4);
    insertar_en_arbol(arbol, 9.9);
    insertar_en_arbol(arbol, 23.2);
    insertar_en_arbol(arbol, 45.6);
    insertar_en_arbol(arbol, 27.6);
    printf("Recorrido en Preorden: \n");
    preorden_arbol(arbol);
    printf("\nRecorrido Inorden: \n");
    inorden_arbol(arbol);
    printf("\nRecorrido en Postorden: \n");
    postorden_arbol(arbol);
    printf("\n");
    borrar_en_arbol(arbol, 9.9);
    printf("\n");
    printf("\nRecorrido Inorden despues del Borrado: \n");
    inorden_arbol(arbol);
    printf("\n\nInformacion Adicional a la Practica: ");
    printf("\nNumero de Nodos: %d ", no_nodos_arbol(arbol));
    printf("\nNumero de Nodos Internos: %d ", no_hojas_arbol(arbol));
    printf("\nNumero de Nodos Hoja: %d ", no_nodos_arbol(arbol));
	
	return 0;
}
