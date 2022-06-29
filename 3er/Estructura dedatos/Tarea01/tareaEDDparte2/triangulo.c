#include "punto.h"
#include <stdio.h>
#include "triangulo.h"
#include <math.h>

int esTriangulo(Triangulo r){
	int lado1 = sqrt(((r.p2.x-r.p1.x)*(r.p2.x-r.p1.x))+((r.p2.y-r.p1.y)*(r.p2.y-r.p1.y)));
	int lado2 = sqrt(((r.p3.x-r.p2.x)*(r.p3.x-r.p2.x))+((r.p3.y-r.p2.y)*(r.p3.y-r.p2.y)));
	int lado3 = sqrt(((r.p1.x-r.p3.x)*(r.p1.x-r.p3.x))+((r.p1.y-r.p3.y)*(r.p1.y-r.p3.y)));
	if((lado2 + lado3 > lado1) && (lado1 + lado3 > lado2) && (lado1 + lado2 > lado3)) return 1;
	else
	return 0;
}

Triangulo capturar_tri(){
	Triangulo r;
	r.p1 = capturar();
	r.p2 = capturar();
	r.p3 = capturar();
	return r;
}

int perimetroTriangulo(Triangulo r){
	int lado1 = sqrt(((r.p2.x-r.p1.x)*(r.p2.x-r.p1.x))+((r.p2.y-r.p1.y)*(r.p2.y-r.p1.y)));
	int lado2 = sqrt(((r.p3.x-r.p2.x)*(r.p3.x-r.p2.x))+((r.p3.y-r.p2.y)*(r.p3.y-r.p2.y)));
	int lado3 = sqrt(((r.p1.x-r.p3.x)*(r.p1.x-r.p3.x))+((r.p1.y-r.p3.y)*(r.p1.y-r.p3.y)));
	int ladoTotal = lado1 + lado2 + lado3;
	return ladoTotal;
}


void esUnTriangulo(Triangulo r){
	int lado1 = sqrt(((r.p2.x-r.p1.x)*(r.p2.x-r.p1.x))+((r.p2.y-r.p1.y)*(r.p2.y-r.p1.y)));
	int lado2 = sqrt(((r.p3.x-r.p2.x)*(r.p3.x-r.p2.x))+((r.p3.y-r.p2.y)*(r.p3.y-r.p2.y)));
	int lado3 = sqrt(((r.p1.x-r.p3.x)*(r.p1.x-r.p3.x))+((r.p1.y-r.p3.y)*(r.p1.y-r.p3.y)));
	if (lado1 == lado2 && lado2 == lado3)
	{
		printf("\nEl triangulo es Equilatero\n");
	}
	else
	{
		if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3)
		{
			printf("\nEl triangulo es uno Isoseles\n");
		}
		else
		{
			if( lado1 != lado2 && lado1 != lado3 && lado3 != lado2)
			{
				printf("\nEl triangulo es Escaleno\n");
			}
		}
	}
}

int areaTriangulo(Triangulo r){
	int area = 0;
	int altura = 0;
	int ladoEsp = 0;
	int lado1 = sqrt(((r.p2.x-r.p1.x)*(r.p2.x-r.p1.x))+((r.p2.y-r.p1.y)*(r.p2.y-r.p1.y)));
	int lado2 = sqrt(((r.p3.x-r.p2.x)*(r.p3.x-r.p2.x))+((r.p3.y-r.p2.y)*(r.p3.y-r.p2.y)));
	int lado3 = sqrt(((r.p1.x-r.p3.x)*(r.p1.x-r.p3.x))+((r.p1.y-r.p3.y)*(r.p1.y-r.p3.y)));
	if (lado1 == lado2 && lado2 == lado3)
	{
		ladoEsp = lado1/2;
		altura = sqrt( (ladoEsp * ladoEsp) + (lado2 * lado2) );
		area = (lado1 * altura)/2;
	}
	else
	{
		if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3)
		{
			if(lado1 == lado2){
				ladoEsp = lado3/2;
				altura = sqrt( (ladoEsp * ladoEsp) + (lado2 * lado2) );
				area = (lado3 * altura)/2;
			}
			else
			{
				if(lado1 == lado3){
					ladoEsp = lado2/2;
					altura = sqrt( (ladoEsp * ladoEsp) + (lado1 * lado1) );
					area = (lado2 * altura)/2;
				}
				else
				{
					ladoEsp = lado1/2;
					altura = sqrt( (ladoEsp * ladoEsp) + (lado3 * lado3) );
					area = (lado1 * altura)/2;
				}
			}
		}
		else
		{
			if( lado1 != lado2 && lado1 != lado3 && lado3 != lado2)
			{
    			int menor, mayor;
    			lado1 = menor;
    			lado1 = mayor;
    			
    			if(lado2 > mayor)
      			mayor = lado2;
 
			    if(lado2 < menor)
    		    menor = lado2;
    		    
    		    if(lado3 > mayor)
       			mayor = lado3;
 
			    if(lado3 < menor)
    		    menor = lado3;
    		    
    		    area= (menor * mayor)/2;
			}
		}
	}
	return area;
}


