 #include <stdio.h>
 #include "biblioteca.h"
 long int factorial (int x) {
int i;
long int fac = 1;
for (i=2; i<=x; i=i+1) 
{
fac=fac*i;
}
 return (fac);
 }
 long int  combinacion (int n, int m){
 long int comb;
 comb=(factorial(n))/(factorial(m)*factorial(n-m));
 return (comb);
 }
 
 int main (){
int a,b,Respuesta;
ConfiguraIdioma();
portada();
do{
	printf("Dame un par de números para obtener la combinacion n!/(m!(n-m)!)\n");
	printf("Ingrese el valor de n: ");
	scanf("%i", &a);
	printf("Ingrese el valor de m: ");
	scanf("%i", &b);
	printf("%i \n",combinacion(a,b));
	system ("pause");
	printf("¿Quieres repetir? (1=si 0=no)");
	scanf("%d", &Respuesta);
}while(Respuesta==1);
return 0;
}
