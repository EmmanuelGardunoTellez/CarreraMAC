#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float** creaMatriz(int n){//Funcion que reserva la memoria para la matriz
	int i;
	float** A;
	
	do{	
		A = (float**)malloc(n*sizeof(float*));
	}while(A == NULL);
	
	for(i = 0; i < n; i++){
		do{
			A[i] = (float*)calloc(n,sizeof(float));
		}while(A[i] == NULL);
	}
	
	return A;
}

void ingresaMatriz(float** A,int n){//Funcion que hace la lectura de la matriz
	int i,j;
	
	system("cls");
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("A[%i][%i] : ",i,j);
			scanf("%f",&A[i][j]);
		}
	}
	
	printf("\n\n");
	
	system("pause");
	system("cls");
}

float** igualar(float** A,int n){//Funcion que iguala dos matrices
	float** B;
	int i,j;
	
	do{
		B = (float**)malloc(n*sizeof(float*));
	}while(B == NULL);
	
	for(i = 0; i < n; i++){
		B[i] = (float*)malloc(n*sizeof(float));
	}
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			B[i][j] = A[i][j];
		}
	}
	
	return B;
}

int cero(float *A,int n){//Booleana que determina si hay puros ceros en un vector
	int cont = 0,i;
	
	for(i = 0; i < n; i++){
		if(A[i] == 0)
			cont++;
	}
	
	if(cont == n)
		return 1; //Todos los elementos de ese vector son 0
	else
		return 0; //No todos los elementos o ninguno de ese vector son 0
}

int equal(float* A, float *B,int n){//Booleana que determina si dos matrices son iguales
	int flag = 1,i;
	
	for(i = 0; i < n; i++){
		if(A[i] != B[i]){
			flag = 0;
			break;
		}
	}
	
	return flag;
}

void intercambio(float **B, int r1, int r2){//Funcion que intercambia renglones
	float *aux;
	
	aux = B[r1];
	B[r2] = B[r1];
	B[r1] = aux;
	
	
}

void suma(float **A,float esc,int f, int d,int n){//Funcion que hace la suma de dos renglones
	float *C;
	int i;
	
	C = (float*)malloc(n*sizeof(float));
	
	for(i = 0; i < n; i++){
		C[i] = A[f][i];
		C[i] *= esc;
	}
	for(i = 0; i < n; i++){
		A[d][i] += C[i];
	}
	
	
	free(C);
}

void lib(float **A,int n){//Funcion que libera la memoria de la matriz
	int i;
	
	for(i = 0; i < n; i++){
		free(A[i]);
	}
	
	free(A);
}

float det(float** A,int n){//Funcion que retorna el determinante de la matriz
	float **B;
	float d = 1;
	float alfa;
	int j,i;
	
	B = igualar(A,n);
	
	for(j = 0; j < n-1; j++){
		if(cero(B[j],n) || equal(B[j],B[j+1],n)){
			d = 0;
			break;
		}
		else if(B[j][j] == 0){
			d *= -1;
			intercambio(B,j,j+1);
			j--;
		}
		else{
			for(i = j; i < n; i++){
				if(i != j){
					alfa = (-1)*(B[i][j])/B[j][j];
					suma(B,alfa,j,i,n);
				}
			}
			d *= B[j][j];
		}
	}
	d*= B[n-1][n-1];
	lib(B,n);
	
	return d;
}

void imp_mat(float** A,int n){//Funcion que imprime la matriz
	int i,j;

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("[%.6f] ",A[i][j]);
		}
		printf("\n");
	}
	
	printf("\n\n");

}

int sub_det(float** A, int n){//Booleana que determina si la matriz es definida positiva
	int i,k,l,flag = 1;
	float** C;
	
	for(i = 0; i < n && flag; i++){
		C = creaMatriz(i+1);
		for(k = 0; k < i+1; k++){
			for(l = 0; l < i+1; l++){
				C[k][l] = A[k][l];
			}
		}
		if(det(C,i+1) <= 0)
			flag = 0;
		lib(C,i+1);
	}
	
	return flag;
}

int simetrica(float** A, int n){//Booleana que determina si la matriz es simetrica
	int i,j;
	int flag = 1;
	
	for(i = 0; i < n && flag; i++){
		for(j = i; j < n; j++){
			if(j != i){
				if(A[i][j] != A[j][i])
					flag = 0;
			}
		}
	}
		
	return flag;
}

float** identidad(int n){//Funcion que asigna a una matriz la identidad de nxn
	int i,j;
	float** I;
	
	do{
		I = (float**)malloc(n*sizeof(float*));
	}while(I == NULL);
	
	for(i = 0; i < n; i++){
		do{
			I[i] = (float*)calloc(n,sizeof(float));
		}while(I[i] == NULL);
		I[i][i] = 1;
	}
	
	return I;
}

float sum_cuad(float** L,int i){//Funcion que retorna la suma de los cuadrados necesaria para los valores de L
	float r = 0;
	int j;
	
	for(j = 0; j<= i-1; j++){
		r += pow(L[i][j],2);
	}
	
	return r;
}

float suma_i_j_esima(float** L, int i, int j){//Funcion que calcula la suma necesaria para los valores de L
	float r = 0;
	int k;

	for(k = 0; k <= i-1; k++){
		r += L[i][k]*L[j][k];
	}
	return r;	
}
 	
void diagonal(float** L,float** A,int i,int n){//Funcion que calcula el elemento de la diagonal del renglon deseado
	L[i][i] = sqrt(A[i][i]-sum_cuad(L,i));
}

void elemento_iesimo(float** L, float** A, int i, int n){//Funcion que calcula cada elemento iesimo de L
	int j;
	
	for(j = i+1; j < n; j++){
		L[j][i] = (1/L[i][i])*(A[j][i] - suma_i_j_esima(L,j,i));
	}
}

void transponer(float** LT, float** L, int n){//Funcion que asgina a una matriz la transpuesta de otra
	int i,j;
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			LT[i][j] = L[j][i];
		}
	}
	
}

int main(){
	float** A;
	float** L;
	float** LT;
	int n;
	int i;
	
	printf("Introduce el orden de la Matriz: ");
	scanf("%i",&n);
	
	A = creaMatriz(n);
	ingresaMatriz(A,n);
	
	if(!sub_det(A,n)){
		printf("La matriz ingresada no puede ser factorizada por Cholseky ya que no es definida positiva.\n\n");
		system("pause");
		system("cls");
		lib(A,n);
	}
	else if(!simetrica(A,n)){
		printf("La matriz si es definida positiva pero no cumple con ser simetrica para este metodo.\n\n");
		system("pause");
		system("cls");
		lib(A,n);
	}
	else{
		L = identidad(n);
		LT = identidad(n);
		
		L[0][0] = sqrt(A[0][0]);
		
		for(i = 1; i < n; i++){
			L[i][0] = A[i][0]/L[0][0];
		}
		
		for(i = 1; i < n; i++){
			diagonal(L,A,i,n);
			elemento_iesimo(L,A,i,n);
		}
		
		transponer(LT,L,n);
		
		system("cls");
		
		printf("Matriz Original: \n\n");
		imp_mat(A,n);
		
		printf("Matriz L:\n\n");
		imp_mat(L,n);
		
		printf("Matriz L': \n\n");
		imp_mat(LT,n);
		
		lib(A,n);
		lib(L,n);
		lib(LT,n);
		
		system("pause");
	}
	
}
