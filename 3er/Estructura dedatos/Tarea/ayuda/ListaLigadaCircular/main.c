//
//  main.c
//  Lista Circular
//

#include <stdio.h>
#include "lista.h"

int main(int argc, const char * argv[]) {
    Nodo * cabecera = NULL;
    cabecera = insertar_frente(cabecera, 8);
    cabecera = insertar_frente(cabecera, 14);
    cabecera = insertar_frente(cabecera, 20);
    cabecera = insertar_frente(cabecera, 34);
    cabecera = insertar_final(cabecera, -6);
    cabecera = insertar_final(cabecera, 12);
    cabecera = insertar_final(cabecera, 56);
    cabecera = insertar_final(cabecera, 92);
    cabecera = borrar_frente(cabecera);
    cabecera = borrar_final(cabecera);
    
    desplegar(cabecera);
    
    if(buscar(cabecera, 34) == 1){
        printf("\n\nEl dato esta en la lista");
    } else{
       printf("\n\nDato No encontrado");
    }
    
    printf("\n\n");
    return 0;
}
