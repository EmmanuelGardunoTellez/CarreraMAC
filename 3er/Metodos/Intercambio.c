#include <stdio.h>
#include <stdlib.h>

float** creaMatriz(int n){//Funcion que asigna la memoria para la matriz de nxn
	int i;
	float** A;
	
	do{	
		A = (float**)malloc(n*sizeof(float*));
	}while(A == NULL);
	
	for(i = 0; i < n; i++){
		do{
			A[i] = (float*)malloc(n*sizeof(float));
		}while(A[i] == NULL);
	}
	
	return A;
}

void ingresaMatriz(float** A,int n){//Funcion que hace la lectura de la Matriz
	int i,j;

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("A[%i][%i] : ",i,j);
			scanf("%f",&A[i][j]);
		}
		printf("\n");
	}
	
	printf("\n\n");
	
	system("pause");
	system("cls");
}

void imp_matriz(float** A, int n){
	int i,j;
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("[%.3f] ",A[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}

void imp_zero(int** A, int n){
	int i,j;
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("[%i] ",A[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
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

int cero(float *A,int n){//Booleana para saber si un renglon tiene puros ceros
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

int equal(float* A, float *B,int n){//Booleana para saber si dos renglones son iguales
	int flag = 1,i;
	
	for(i = 0; i < n; i++){
		if(A[i] != B[i]){
			flag = 0;
			break;
		}
	}
	
	return flag;
}

void inter(float **B, int r1, int r2,int n){//Funcion que intercambia dos renglones
	float aux;
	int i;
	
	for(i = 0; i < n; i++){
		aux = B[r1][i];
		B[r1][i] = B[r2][i];
		B[r2][i] = aux;
	}
}

void col_inter(float** B, int c1, int c2, int n){
	float aux = 0;
	int i,j;
	
	for(i = 0; i < n; i++){
		aux = B[i][c1];
		B[i][c1] = B[i][c2];
		B[i][c2] = aux;
	}
	
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

void lib(float **A,int n){//Funcion que libera la memoria del monticulo
	int i;
	system("pause");
	for(i = 0; i < n; i++){
		free(A[i]);
	}
	
	free(A);
}

float det(float** A,int n){//Funcion que retorna el determinante de una matriz
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
			inter(B,j,j+1,n);
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

void col_pivote(float** A, int r, int c, int n){
	float p = A[r][c];
	int i;
	
	for(i = 0; i < n; i++){
		if(i != r)
			A[i][c] /= p;
	}
	
}

void ren_pivote(float** A, int r, int c, int n){
	float p = A[r][c];
	int i;

	for(i = 0; i < n; i++){
		if(i != c)
			A[r][i] /= (-1*p);
	}
	
}

void vecinos(float** A, int r, int c, int n){
	int i,j;
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(i != r && j != c){
				A[i][j] += A[r][j]*A[i][c];
			}
		}
	}
}

void intercambio(float** A, int r, int c, int n){
	ren_pivote(A,r,c,n);
	vecinos(A,r,c,n);
	col_pivote(A,r,c,n);
	A[r][c] = 1/A[r][c];
}

void uno(int** zero, int r, int c, int n){
	int i,j;
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(i == r || j == c)
				zero[i][j] = 1;
		}
	}
}

float ABS(float x){
	if(x < 0)
		return -1*x;
	else
		return x;
}

int mayor(float* A, int* zero, int n){
	int i;
	int c = -1;
	float max = 0;
	
	for(i = 0; i < n; i++){
		if(!zero[i]){
			if(i == n-1)
				c = i;
			else{
				if(ABS(A[i]) > ABS(max)){
					max = A[i];
					c = i;
				}
			}
		}
	}
	
	return c;
}

void imp_vect(float* a, int n){
	int i;
	
	for(i = 0; i < n; i++){
		if(i == 0){
			if(a[0] != 0)
				printf("%.3f x%i ",a[i],i);
			else
				printf("\t");
		}
		else{
			if(a[i] < 0)
				printf("- %.3f ",ABS(a[i]));
			else if(a[i] > 0)
				printf("+ %.3f ",a[i]);
			else
				printf("\t");
				
			if(a[i] != 0)
				printf("x%i ",i);
		}
	}
}

void imp_SEL(float** A, float* b, int n){
	int i,j;
	
	for(i = 0; i < n; i++){
		imp_vect(A[i],n);
		printf("= %.3f\n",b[i]);
	}
	printf("\n\n");
}

float* sol_sistema(float** A, float* b, int n){
	int i,j;
	float* x;
	float sum = 0;
	
	do{
		x = (float*)calloc(n,sizeof(float));
	}while(x == NULL);
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			sum += A[i][j]*b[j];
		}
		x[i] = sum;
		sum = 0;
	}
	
	return x;
}

int main(){
	float** A;
	float** B;
	float* sol;
	int** zero;
	float* b;
	int* x;
	int* y;
	int n;
	int i,j;
	int pivote;
	int aux;
	
	printf("Introduce el numero de incognitas del sistema : "); scanf("%i",&n);
	system("cls");
	
	printf("Introduce los valores respectivos de la matriz de coeficientes: \n\n");
	
	A = creaMatriz(n);
	ingresaMatriz(A,n);
	
	if(!det(A,n)){
		printf("El determinante del sistema es cero, por lo que el sistema no es compatible determinado.\n\n");
		system("pause");
		system("cls");
	}
	else{
		B = igualar(A,n);
		
		do{
			b = (float*)calloc(n,sizeof(float));
		}while(b == NULL);
		
		system("cls");
		printf("Ahora introduce los valores del vector independiente.\n\n");
		for(i = 0; i < n; i++){
			printf("b%i = ",i);
			scanf("%f",&b[i]);
		}
		
		printf("\n\n");
		system("pause");
		system("cls");
		
		printf("La matriz original es: \n\n");
		
		imp_matriz(A,n);
		
		do{
			zero = (int**)malloc(n*sizeof(int*));
		}while(zero == NULL);
		
		for(i = 0; i < n; i++){
			do{
				zero[i] = (int*)calloc(n,sizeof(int));
			}while(zero[i] == NULL);
		}
		do{
			x = (int*)calloc(n,sizeof(int));
		}while(x == NULL);
		
		for(i = 1; i < n; i++){
			x[i] = i;
		}
		
		do{
			y = (int*)calloc(n,sizeof(int));
		}while(x == NULL);
		
		for(i = 1; i < n; i++){
			y[i] = i;
		}
		printf("Aplicando el metodo del intercambio: \n\n");
		
		for(i = 0; i < n; i++){
			printf("Iteracion %i\n\n",i+1);
			pivote = mayor(A[i],zero[i],n);
			x[i] = pivote;
			y[pivote] = i;
			intercambio(A,i,pivote,n);
			uno(zero,i,pivote,n);
			imp_matriz(A,n);
		}
		
		system("pause");
		system("cls");
		
		printf("Ordenando la matriz inversa de coeficientes con el orden normal:\n\n");
		
		for(i = 0; i < n; i++){
			for(j = 0; j < n-1; j++){
				if(x[j] > x[j+1]){
					aux = x[j];
					x[j] = x[j+1];
					x[j+1] = aux;
					inter(A,j,j+1,n);
				}
				if(y[j] > y[j+1]){
					aux = y[j];
					y[j] = y[j+1];
					y[j+1] = aux;
					col_inter(A,j,j+1,n);
				}
			}
		}
		
		imp_matriz(A,n);
		
		system("pause");
		system("cls");
		
		sol = sol_sistema(A,b,n);
		
		printf("Para el sistema de ecuaciones: \n\n");
		imp_SEL(B,b,n);
		
		printf("La solucion es: \n\n");
		for(i = 0; i < n; i++){
			printf("\tx%i = %.3f\n",i,sol[i]);
		}
		
		printf("\n\n");
		system("pause");
		system("cls");
		
		for(i = 0; i < n; i++){
			free(zero[i]);
		}
		free(zero);
		free(x);
		free(y);
		lib(B,n);
	}
	
	lib(A,n);
	return 0;
	
	
}
