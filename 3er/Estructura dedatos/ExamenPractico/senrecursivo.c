#include <stdio.h>

double potencia(double x, int n){
	if(n==0) return 1;
	else return x * potencia(x, n-1); 	
}

int factorial(int n){
	if(n<2) return 1;
	else return n * factorial(n-1); 	
}

double sen (int n, double x){
	if (n==0) return x;
	else return potencia(-1.0, n) * (potencia(x, 2*n+1)/factorial(2*n+1)) + sen (n-1,x);
}

int main(){
	
	double valor;
	int precision;
	printf("Hola, dame el valor de Seno que quieras optener: ");
	scanf("%lf", &valor);
	printf("Y la precision de este numero (entero): ");
	scanf("%d", &precision);

	printf("Resultado: %lf\n" , sen (precision , valor ));
	system("pause");
	return 0;
}
