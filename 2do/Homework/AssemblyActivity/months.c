#include <stdio.h>
#include <stdlib.h>
#define C 12

main()
{
	int i;
	int months[C] = {[0]=31,[1]=28,[2]=31,[3]=0,[4]=31,[5]=0,[6]=31,[7]=30,[8]=30,[9]=31,[10]=30,[11]=0}; //Guarda los dias que hay en cada mes, exepto en los meses 4, 6,12
	//El mes es el numero del mes menos uno
	for(i=0;i<C;i++){
		printf("%i\n",months[i]); //Muestra los dias qeu hay en cada mes
	}	
}
