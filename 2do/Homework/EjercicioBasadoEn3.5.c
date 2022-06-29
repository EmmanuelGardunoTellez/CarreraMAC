#include<stdio.h>
#include<math.h>
// Declaracion de la estructura
struct pto
{

	float x;
	float y;
};

// Declaracion de las funciones
void diagonal(struct pto p1, struct pto p2);
void PerimetroYArea(struct pto p1, struct pto p2,struct pto p3, struct pto p4);

int main(){

struct pto pto1, pto2, pto3, pto4; //Dicendo cuantas veces se usara la estructura
printf("Dame los puntos del 1 y 3 los otorso dos los hara la computadora como un espejo.\n");
printf("Se hara un rectangulo con esto\n");
/*El usuario dara los valores para del vectos 1 y 3, para hacer la diagonal, el area y perimetro*/
printf("Escriba el valor de x(1) ");
scanf("%f", &pto1.x);
printf("Escriba el valor de y(1) ");
scanf("%f", &pto1.y);
printf("Escriba el valor de x(3) ");
scanf("%f", &pto3.x);
printf("Escriba el valor de y(3) ");
scanf("%f", &pto3.y);
//Dando un valor cualquera, el p1=(a,b) y p3(c,d), son similares a p2=(c,b) p4=(a,d)
//Entonces se le asignas esos valores
pto2.x = pto3.x;
pto2.y = pto1.y;
pto4.x = pto1.x;
pto4.y = pto3.y;
diagonal(pto1,pto3);
PerimetroYArea(pto1,pto2,pto3,pto4);
return 0;
}

void diagonal(struct pto p1, struct pto p2) //Se toma el valor de p1 y p3
{
float ZZ,MagX,MagY;
MagX=(p2.x-p1.x); //Da la magnitud o distancia de los puntos
MagY=(p2.y-p1.y); //Lo mismo de arriba
ZZ = sqrt(MagX*MagX+MagY*MagY); //Se usa el teorema de pitagoras

printf("Daiagonal %.2f\n", ZZ);
}

void PerimetroYArea(struct pto p1, struct pto p2,struct pto p3, struct pto p4){
	float L1,L2,L3,L4,LT,A;
	//Se saca las magnitudes y el teorema de pitagoras para las distancias de cada lado, despues de ello se multiplican los lados como un rectangulo
	L2=sqrt((p3.x-p2.x)*(p3.x-p2.x)+(p3.y-p2.y)*(p3.y-p2.y)); 
	L1=sqrt((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y)); 
	L3=sqrt((p4.x-p3.x)*(p4.x-p3.x)+(p4.y-p3.y)*(p4.y-p3.y)); 
	L4=sqrt((p1.x-p4.x)*(p1.x-p4.x)+(p1.y-p4.y)*(p1.y-p4.y)); 
	LT=L1+L2+L3+L4;
	A=L1*L2;
	printf("Perimetro %.2f\n", LT);
	printf("Area %.2f\n", A);
}

