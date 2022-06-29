//
//  main.c
//  ListaLigada
//
//  Created by Jonathan Cordoba Luna on 9/13/19.
//  Copyright © 2019 Jonathan Cordoba Luna. All rights reserved.
//

#include <stdio.h>
#include "lista.h"

int main(){
    Nodo * cabecera = NULL;   
    int opcion, elemento;
    while(1){
    	system("cls");
        printf("\nMenu de Opciones: ");
        printf("\n[1]  Insertar Elemento Al Principio");
        printf("\n[2]  Insertar Elemento Al Final");
        printf("\n[3]  Desplegar Elementos");
        printf("\n[4] Salir");
        printf("\nIngrese la opcion seleccionada: ");
        scanf("%d",&opcion);
        if(opcion == 1){
            printf("\nIngrese el nuevo elemento: ");
            scanf("%d", &elemento);
            cabecera = insertar_primero(cabecera, elemento);
        } else if(opcion == 2){
        	printf("\nIngrese el nuevo elemento: ");
            scanf("%d", &elemento);
            cabecera = insertar_final(cabecera, elemento);
		} else if(opcion == 3){
			desplegar(cabecera);
			system("PAUSE");
		} else {
			return 0;
		}	
	}
    return 0;
}
