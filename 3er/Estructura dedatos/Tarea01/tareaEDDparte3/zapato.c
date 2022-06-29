
#include "zapa.h"
#include <stdio.h>

Zapato obtenerZapato(void){
    Zapato zap;
    fflush(stdin);
    printf("Dame marca: ");
    fgets(zap.marca, 50, stdin);
    strtok(zap.marca,"\n");
    printf("Dame modelo: ");
    fgets(zap.modelo, 50, stdin);
    strtok(zap.modelo,"\n");
    printf("Dame color: ");
    fgets(zap.color, 50, stdin);
    strtok(zap.color,"\n");
    printf("Dame codigo: ");
    scanf("%d", &zap.codigo);
    printf("Dame talla: ");
    scanf("%d", &zap.talla);
    return zap;
}

void desplegarZapato(Zapato zap){
    printf("\nMarca: %s", zap.marca);
    printf("\nModelo: %s", zap.modelo);
    printf("\nColor: %s", zap.color);
    printf("\nCodigo: %d\n", zap.codigo);
    printf("\nTalla: %d\n", zap.talla);
}


