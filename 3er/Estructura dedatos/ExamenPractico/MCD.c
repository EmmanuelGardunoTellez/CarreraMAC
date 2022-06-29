#include <stdio.h>
#include <conio.h>

int mcdr(int numero1, int numero2){
	if(numero1<numero2)
		return mcdr (numero2, numero1);
	else if(numero2==0)
		return numero1;
		else return mcdr(numero2, numero1%numero2);
}

int mcdi(int numero1, int numero2 ){
	int residuo, mcd;
	
	if(numero2==0){
		return numero1;
	}
	
	if (numero1 == 0 & numero2 ==0){
		return 0;
	}
	else
	{
    do {
        residuo = numero1 % numero2;
 
        if (residuo != 0) {
            numero1 = numero2;
            numero2 = residuo;
 
        } else {
            mcd = numero2;
        }
 
    } while (residuo != 0);
	return mcd;
}
}

int main(){
	
	int numero1, numero2;
	printf("Los numeros deben de ser matores o iguales a 0\n");
	do{
		printf("Dame un numero: ");
		scanf("%d", &numero1);
	}while(numero1 <0);
	do{
		printf("Dame otro numero: ");
		scanf("%d", &numero2);
	}while(numero2 <0);
	
	
	printf("\nEl maximo comun denomidador: ");
	printf("\nEl maximo comun denomidador por recursividad: %d", mcdr(numero1, numero2));
	printf("\nEl maximo comun denomidador por iterativo: %d\n", mcdi(numero1, numero2));
 	system("pause");
   return 0;

}
