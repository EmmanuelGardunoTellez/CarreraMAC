#include<stdio.h>
#include<stdbool.h>
#include<math.h>
double F(double);
double FP(double);
void INPUT(bool *, double *, double *, int *);

main() {
double TOL,P0,D,F0,FP0;
int I,NO;
bool OK;
INPUT(&OK, &P0, &TOL, &NO);
if (OK) {
F0 = F(P0);
I = 1;
OK = true;
while ((I<=NO) && OK) {
FP0 = FP(P0);
D = F0/FP0;
P0 = P0 - D;
F0 = F(P0);
printf("%3d %14.8e %14.7e\n",I,P0,F0);
if (abs(D) < TOL) {
printf("\nSolucion aproximada = %.10e\n",P0);
OK = false;
}
else I++;
}
if (OK) {
printf("\nLa iteracion %d",NO);
printf(" da la aproximacion %.10e\n",P0);
printf("fuera de la tolerancia aceptada\n");
}
}
getchar();
getchar();
}
double F(double X)
{
double f;
f = cos(X) - X;
return f;
}
double FP(double X)
{
double fp;
fp = -sin(X) - 1;
return fp;
}

void INPUT(bool *OK, double *P0, double *TOL, int *NO)
{
*OK = false;
printf("Dar aproximacion inicial\n");
scanf("%lf", P0);
while(!(*OK)) {
printf("Dar la tolerancia\n");
scanf("%lf", TOL);
if (*TOL <= 0.0) printf("La tolerancia debe ser positiva\n");
else *OK = true;
}
*OK = false;
while (!(*OK)) {
printf("Dar el numero de iteraciones maximo\n");
scanf("%d", NO);
if (*NO <= 0) printf("Debe ser un entero positivo\n");
else *OK = true;
}
}
