
#include <stdio.h> 

float capi(int n)
{
    double suma;
    int i;
 
    suma=1.0;
 
    for (i=0; i<=n; i++)
    {
        if ((i=2)||((i%2)==0))
        {
            suma=suma+(1/(2*i+1));
        }
        else 
		{
		suma=suma-(1/(2*i+1));
		}
    }
    
 suma=4*suma;
return suma;
}
 
 
int main()
 
{

    float n;
    double pi;
 
    printf("Introduzca el numero de terminos que quiere del numero pi:");
    scanf ("%f",&n);
 
    printf ("El valor del numero PI es: %d \n\n",capi(n));
 
    system("pause");
 
    return 0;
}
