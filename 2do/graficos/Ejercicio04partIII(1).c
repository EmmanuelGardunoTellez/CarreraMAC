#include <stdio.h>
#include <math.h>

typedef struct xpotencias //Gaurda el valor de por cuanto multiplicara a cada x^n donde n es la potencia
{
	int x5,x4,x3,x2,x1,x0;
} x;

float fx (x px, int val){ //Evaluador de la funcion
	float p;
	p= pow(val,5)*px.x5+pow(val,4)*px.x4+pow(val,3)*px.x3+pow(val,2)*px.x2+pow(val,1)*px.x1+px.x0;
	return p;
}

/*Funcion principal*/
void main(){
	int ves,ini,ter; //Declaracion de variables
	float num; 
	x px; //Estructura guardada con typedef, y mostrada de manera sencilla
	FILE *archivo2 = fopen("F(x).txt", "w"); //Abreo un archivo
	/*Guarda polinomio*/
	printf("\n\nDime un polinomio de quinto grado: \n");
	printf("Dame el valor que multiplicara a x^5: ");
	scanf("%i",&px.x5);
	printf("Dame el valor que multiplicara a x^4: ");
	scanf("%i",&px.x4);
	printf("Dame el valor que multiplicara a x^3: ");
	scanf("%i",&px.x3);
	printf("Dame el valor que multiplicara a x^2: ");
	scanf("%i",&px.x2);
	printf("Dame el valor que multiplicara a x^1: ");
	scanf("%i",&px.x1);
	printf("Dame el valor que multiplicara a x^0: ");
	scanf("%i",&px.x0);
	printf("\n\nEl polinomio es f(x)=(%i)x^5+(%i)x^4+(%i)x^3+(%i)x^2+(%i)x^1+(%i)\n",px.x5,px.x4,px.x3,px.x2,px.x1,px.x0);
	printf("Dime de que valor a que valor se evaluara px:\n");
	//Almacena de donde a donde va a ir, si el numero  donde termina es mayor qeu al que inicia, no te va adejar seguir hasta que sea correcto
	do{
		printf("Inicia: ");
		scanf("%i", &ini);
		printf("Termnina: ");
		scanf("%i", &ter);
	}while(ini>ter);
	
	fprintf(archivo2, "set xr[%i:%i]\n",ini, ter);
	fprintf(archivo2, "set yr[%f:%f]\n",fx(px,ini), fx(px,ter));
	fprintf(archivo2,"\n");
	fprintf(archivo2,"f(m, n) = m*(%i*n*n*n*n*n)+m*(%i*n*n*n*n)+m*(%i*n*n*n)+m*(%i*n*n)+m*(%i*n)+%i\n", px.x5, px.x4, px.x3, px.x2, px.x1, px.x0);
	fprintf(archivo2,"g(m, n) = m*(5*%i*n*n*n*n)+m*(4*%i*n*n*n)+m*(3*%i*n*n)+m*(2*%i*n)+m*(1*%i)\n", px.x5, px.x4, px.x3, px.x2, px.x1);
	fprintf(archivo2,"h(m, n) = m*(4*5*%i*n*n*n)+m*(3*4*%i*n*n)+m*(2*3*%i*n)+m*(1*2*%i)\n",px.x5, px.x4, px.x3, px.x2);
	fprintf(archivo2,"\n");
	fprintf(archivo2,"set style line 1 lc rgb 'red90'\n");
	fprintf(archivo2,"set style line 2 lc rgb 'green60'\n");
	fprintf(archivo2,"set style line 3 lc rgb 'blue30'\n");
	fprintf(archivo2,"\n");
	fprintf(archivo2,"plot f(1, x) ls 1, g(1, x) ls 2, h(1, x) ls 3\n");

	
}

