#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>

typedef float** MATRIZ;
typedef float* pentero;
typedef float* vectorConst;

MATRIZ generaMatriz(int dim);
void liberaMatrizR(MATRIZ A, int dim);
vectorConst generaVector(int dim);
void liberaVector(vectorConst V);
void ingresaMatriz(MATRIZ A, int dim);
void ingresaVector(vectorConst V, int dim);
void imprimeMatriz(MATRIZ A, int dim);
void imprimeVector(vectorConst V, int dim);
void transformaSistema(MATRIZ A, MATRIZ B, vectorConst V, vectorConst V2, int dim);
void obtieneRaiz(MATRIZ B, vectorConst V2, vectorConst vect, int dim);


MATRIZ generaMatriz(int dim){ //Genera la matriz NxN
    MATRIZ aux;
    int i=0;
    if((aux = (MATRIZ)malloc(dim*sizeof(pentero))) == NULL){
        return 0;
    }  
	for( i=0; i<dim; i++){
        if((aux[i] = (pentero)malloc(dim*sizeof(float))) == NULL){
            return 0;
        }
    }
    return aux;
}
void liberaMatriz(MATRIZ A, int dim){  //Libra matriz NxN
	int i=0;
    for( i=0; i<dim; i++){
        free(A[i]);
    }
    free(A);
}
vectorConst generaVector(int dim){ //Te da el vector cosntante
    vectorConst V;
    V = (vectorConst)malloc(dim*sizeof(float));
    return V;
}
void liberaVector(vectorConst V){ //Libera el vector cosntante
    free(V);
}
void ingresaMatriz(MATRIZ A, int dim){ //Ingresa los datos de la matriz
    int i=0, j=0;
	for(i=0; i<dim; i++){
        for(j=0; j<dim; j++){
            printf("\n [%d][%d] : ",i+1,j+1);
            scanf("%f",&A[i][j]);
        }
    }
}
void ingresaVector(vectorConst V, int dim){ //Ingresa los datos del vector
    int i=0;
	for( i=0; i<dim; i++){
        printf("\n [%i] : ",i+1);
        scanf("%f",&V[i]);
    }
}
void imprimeMatriz(MATRIZ A, int dim){ //Imprime la matriz
    printf("\n");
    int i=0, j=0;
    for(i=0; i<dim; i++){
        for(j=0; j<dim ; j++){
            printf(" %.4f ",A[i][j]);
        }
        printf("\n");
    }
}
void imprimeVector(vectorConst V, int dim){ //Imprime el vecor
    int i=0;
	for(i=0; i<dim; i++){
        printf("\n %.4f ",V[i]);
    }
}
void transformaSistema(MATRIZ A, MATRIZ B, vectorConst V, vectorConst V2, int dim){ // 
	int i=0, j=0;
    for(i=0; i<dim; i++){
        for( j=0; j<dim; j++){
            B[i][j] = (-1)*A[i][j]/A[i][i];
            if(j == dim-1){
                V2[i] = (-1)*V[i]/A[i][i];
            }
        }
    }
}
float product(MATRIZ B, vectorConst V2, vectorConst vect, int dim, int i); //Multiplica el metodo

void obtieneRaiz(MATRIZ B, vectorConst V2, vectorConst vect, int dim){ // MUESTRA LAS ITERACCIONES Y RESULTADO
    float raiz;
    float arreglo[dim];
    int itera=0, i=0;
    float error = 0.00001;
    for(i=0; i<dim; i++){
        vect[i] = 0;
        arreglo[i] = 0;
    }
    int indi = 0;
    printf("\n| Iteracion|");
    printf(" ");
    for(i=0; i<dim; i++){
        printf("   X%d    |",i+1);
    }
    printf("      |");
    for(i=0; i<dim; i++){
        printf("     R%d    |",i+1);
    }
    printf("       |  MAXIMO |");
    do{
        printf("\n\n|    %d     | ",indi);
        indi+=1;
        for(i=0; i<dim; i++){
            printf(" %.5f |",vect[i]);
        }
        printf("      |");
        float prod=0;
        for(i=0; i<dim; i++){
            arreglo[i] = product(B, V2, vect, dim, i);
        }
        for(i=0; i<dim; i++){
            printf("  %.5f  |",arreglo[i]);
        }
        float maxi = 0.0;
        for(i=0; i<dim; i++){
            if(fabs(arreglo[i]) > maxi){
                maxi = fabs(arreglo[i]);
            }
        }
        printf("       | %.5f |",maxi);
        for(i=0; i<dim; i++){
            if(fabs(arreglo[i]) == maxi){
                vect[i] = vect[i]+arreglo[i];
            }else{
                vect[i] = vect[i];
            }
        }
        indi=0;
        for( i=0; i<dim; i++){
            if(fabs(arreglo[i]) < error){
                indi+=1;
            }
        }
    }while(indi != dim);
    printf("\n Se detiene el metodo...");
}
float product(MATRIZ B, vectorConst V2, vectorConst vect, int dim, int i){
    float prod=0.0;
    int j=0;
    for( j=0; j<dim; j++){
        prod += B[i][j]*vect[j];
    }
    prod = prod-V2[i];
    return prod;
}

int main(){
    int dim;
    float raiz;
    MATRIZ A, B;  //Crea matriz
    vectorConst V, V2, vect; //Los vectores cosntantes
    printf("\n Ingresa el rango de la matriz: ");
    scanf("%d",&dim);
    //Genera las dimensiones de los vecotres y matrices
    A = generaMatriz(dim);
    B = generaMatriz(dim);
    V = generaVector(dim);
    V2 = generaVector(dim);
    vect = generaVector(dim);
    printf("\n Ingresa los datos de la matriz ");
    ingresaMatriz(A, dim);
    printf("\n Ingresa los datos del vector: ");
    ingresaVector(V, dim);
    printf("\n Matriz ingresada ");
    imprimeMatriz(A, dim);
    printf("\n Vector ingresado ");
    imprimeVector(V, dim);
    transformaSistema(A, B, V, V2, dim);
    printf("\n Matriz transformada. ");
    imprimeMatriz(B, dim);
    printf("\n Vector transformado. ");
    imprimeVector(V2, dim);
    obtieneRaiz(B, V2, vect, dim);


   //Se libera memoria de las matrices y vectores.
    liberaMatriz(A, dim);
    liberaMatriz(B, dim);
    liberaVector(V);
    liberaVector(V2);
    liberaVector(vect);
}
