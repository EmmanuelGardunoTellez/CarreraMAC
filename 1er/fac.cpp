#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//#include<Mi biblioteca.h>

void fac(int a)
{
int r,i;
r=1;
   
if(a==0)
{
printf("El factorial es 1");
}
else
{
for(i=1;i<=a;i++)
{
r=r*i; 
}
printf("El factorial es %i",r);
system("pause");
}

}


int main ()

{
int a;
printf("Dame un número para obtener su factorial");
scanf("%i", &a); 
fac(a);
return 0;
}

