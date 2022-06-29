#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//#include <Mi biblioteca.h> 

void div(int n);
void imp(int r);

int main ()
{
    int  n, r;
	printf("Dame un número del que quieras sus divisores");
	scanf ("%i",&n);   
	div(n);
	imp(r);
system("pause");	
} 
	
void div(int n)

{
	int d, r, i;
	for(i=1;i<=n;i++)
	{
		d=n/i;
		r=n%i;
    }

}

void imp(int r)

{
    int d;
	if (r==0)
		{
		printf ("Uno de sus divisores es:%i\n\n",d);
		printf("ERROR 404    ERROR 404    ERROR 404    ERROR 404   ERROR 404\n");
		//invoca div(web) en la funcion y ve poque sale mal, invoca la portada tambien y cambia el idioma :3 :v >:v :,(
	   	}
}


