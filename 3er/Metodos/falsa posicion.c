#include <stdio.h>
#include <math.h>
#include <stdlib.h>


double raiz(double a){
	double x= pow(a,4) - 8*(pow(a, 3)) - 35* (pow(a, 2)) - 450 * a - 1001;
	return x;
}

double derivadaRaiz(double a){
	double x = 4 * pow(a,3) - 3*8*(pow(a, 2)) - 2*35* (pow(a, 1)) - 450 ;
	return x;
}

double f(double a, double b){
	double f = (b* raiz(a) - a * raiz(b))/(raiz(a) - raiz(b));
	return f;
}

 
 int main() {
	double a=0,b=0, x=0;
	double error=0, fIaI=0, fIbI= 0, DfIaI=0, DfIbI=0, fIxI=0;
	printf("Dame el intervalo a, b (nota, b debe ser mayor a a)\n");
	do{
 		printf("Dame el intervalo a: ");
 		scanf("%lf", &a);
 		printf("Dame el intervalo b: ");
 		scanf("%lf", &b);
	}while (a>b || a == b);
	 
	printf("Ingresa el error: ");
	scanf("%lf", &error);
	 //verifica que se pueda hacer el metodo
	fIaI= raiz(a);
	fIbI= raiz(b);
	printf("\n\nf(%.2lf)=%.2lf f(%.2lf)=%.2lf\n\n",a, fIaI,b, fIbI);
	 if(fIaI>0 && fIbI>0){
	 	printf("No se puede aplicar el metodo");
	 	return 0;
	}
	 if(fIaI<0 && fIbI<0){
	 	printf("No se puede aplicar el metodo");
	 	return 0;
	}
	DfIaI= derivadaRaiz(a);
	DfIbI= derivadaRaiz(b);
	printf("\n\nf(%.2lf)=%.2lf f(%.2lf)=%.2lf\n\n",a, DfIaI,b, DfIbI);
	if(DfIaI<0 && DfIbI>0){
		printf("No se puede aplicar el metodo");
		return 0;
	}
	 if(DfIaI>0 && DfIbI<0){
	 	printf("No se puede aplicar el metodo");
	 	return 0;
	 }
	 int intervalo =1;
	 printf("Intervalo  a      b     f(a)      f(b)      x      |f(x)|<e     f(x)*f(a)<0\n");
	 fIxI= raiz(x);
	 do{
	 	x=f(a, b);
	 	fIxI = raiz(x);
	 	if(intervalo<10){
	 		printf("    0%d    %.2lf  %.2lf  %.2lf  %.2lf  %.2lf  |%.4lf|  %.3lf\n", intervalo, a, b, fIaI, fIbI, x, fIxI, raiz(x)*raiz(a));
		 } else {
		 	printf("    %d    %.2lf  %.2lf  %.2lf  %.2lf  %.2lf  |%.4lf|  %.3lf\n", intervalo, a, b, fIaI, fIbI, x, fIxI, raiz(x)*raiz(a));
		 }
	 	
	 	if(fIxI*fIaI<0){
	 		b= x;
	 		fIbI= fIxI;
		 } else {
		 	a= x;
	 		fIaI= fIxI;
		 }
	 	intervalo++;
	 }while(fabs(raiz(x))>error);
return 0;
}
