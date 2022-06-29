#include <stdio.h> 
#include <stdlib.h>

int fibon (int n)
   {
   	int fibo[n];
   	int i;

   fibo[0]=1;
   fibo[1]=1;
 
     
     for(i=2;i<=n-1;i++){
     	fibo[i]=fibo[i-1]+fibo[i-2];
     
	 }
	 for(i=0;i<n;i++){
		printf("%i"",",fibo[i]);
	 }
	 system ("pause");
	return 0;
}
	 
 int main()
 {
 	int n,i;
 	printf("\t\tIntroduzca la cantidad de números que desea ver: \n");
    scanf("%d",&n);
    printf("Los números que pertenecen a la cantidad deseada son: \n\n");
   
   fibon(n);
	
	
    }
 
