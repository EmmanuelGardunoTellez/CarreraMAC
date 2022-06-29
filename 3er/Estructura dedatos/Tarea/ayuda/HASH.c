//  main.c
//  PracticaUltima
//
// FES Acatlan
//

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct empleado{
    int id_empleado;
    char nombre_empleado[45];
    int edad_empleado;
} Empleado;

typedef struct nodo{
    Empleado dato;
    struct nodo * siguiente;
} Nodo;

int funcion_hash(int clave){
    return (clave % MAX);
}

int buscar(int clave, Nodo * tabla_hash[]){
    int h;
    Nodo * cabecera;
    h = funcion_hash(clave);
    cabecera = tabla_hash[h];
    while (cabecera != NULL) {
        if(cabecera->dato.id_empleado == clave){
            return h;
        }
        cabecera = cabecera->siguiente;
    }
    return -1;
}

void insertar(Empleado empleado, Nodo * tabla_hash[]){
    int clave, h;
    Nodo * temp;
    clave = empleado.id_empleado;
    if(buscar(clave, tabla_hash) != -1){
        printf("Clave Duplicada\n");
        return;
    }
    h = funcion_hash(clave);
    temp = (Nodo*) malloc(sizeof(Nodo));
    temp->dato = empleado;
    temp->siguiente = tabla_hash[h];
    tabla_hash[h] = temp;
}

void desplegar(Nodo * tabla_hash[]){
    int cont;
    Nodo * ptr;
    for(cont=0; cont<MAX; cont++){
        printf("\n[%3d]", cont);
        if(tabla_hash[cont] != NULL){
            ptr = tabla_hash[cont];
            while (ptr != NULL) {
                printf("%d %s %d\t", ptr->dato.id_empleado, ptr->dato.nombre_empleado, ptr->dato.edad_empleado);
                ptr = ptr->siguiente;
            }
        }
    }
    printf("\n");
}


int main(int argc, const char * argv[]) {
    
    int opcion;
    Nodo * tabla_hash[MAX];
    Empleado registro_empleado;
    int cont;
    for(cont=0; cont< MAX; cont++){
        tabla_hash[cont] = NULL;
    }
    
    while(1){
        printf("[1] Insertar Registro\n");
        printf("[2] Desplegar Informacion\n");
        printf("[3] Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                fflush(stdin);
                printf("Ingrese ID del Empleado:\t");
                scanf("%d", &registro_empleado.id_empleado);
                printf("Ingrese Nombre del Empleado:\t");
                scanf("%s", registro_empleado.nombre_empleado);
                printf("Ingrese Edad del Empleado:\t");
                scanf("%d", &registro_empleado.edad_empleado);
                insertar(registro_empleado, tabla_hash);
                break;
            case 2:
                desplegar(tabla_hash);
                break;
            case 3:
                exit(1);
            default:
                break;
        }
    }
    
    return 0;
}

