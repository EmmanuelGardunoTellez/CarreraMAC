#include <stdio.h>
#include <stdlib.h>


int main ()
{
int i,j, 	Respuesta1, Respuesta2,constantes;
char frase1[10][5], frase2[10][5], frase3[10][5];
printf("De las valores despues de decir cunatos son\n");
printf("Indique cuantos argumentos de una variable va a usar: ");
do{
		scanf("%i", &Respuesta1);
	}while(0>Respuesta1);
for(i=0;i<Respuesta1;i=i+1){
	scanf("%s",frase1[i]);
}
printf("Indique cuantos argumentos de dos variables va a usar: ");
do{
		scanf("%i", &Respuesta2);
	}while(0>Respuesta2);

for(i=0;i<Respuesta2;i=i+1){
	scanf("%s",frase2[i]);
}
printf("Indique cuantas contantes va a usar (maximo 2): ");
do{
		scanf("%i", &constantes);
	}while(constantes < 0 || constantes > 2);
for(i=0;i<constantes;i=i+1){
	scanf("%s",frase3[i]);
}

printf("La BASE DE HERBRAD para el lenguaje especifico es: \n");
if(constantes>0)
{
	printf("se puede\n");
	if(Respuesta1>0){
		for(i=0;i<Respuesta1;i=i+1){
			for(j=0;j<constantes;j=j+1){
				printf("%s(%s)    ",&frase1[i],&frase3[j]);
			}
			printf("\n");
		}
	}
		switch(constantes){
				case 1:
					for(i=0;i<Respuesta2;i=i+1){
						printf("%s(%s,%s)  \n",&frase2[i],frase3[0], frase3[0]);
						}
					break;
				case 2:
			for(i=0;i<Respuesta2;i=i+1){
			printf("%s(%s,%s)  ",&frase2[i],frase3[0], frase3[0]);
			printf("%s(%s,%s)  ",&frase2[i],frase3[1], frase3[0]);
			printf("%s(%s,%s)  ",&frase2[i],frase3[0], frase3[1]);
			printf("%s(%s,%s)  \n",&frase2[i],frase3[1], frase3[1]);
						}
					break;	
}
}
else
{
	printf("no se puede realizar La BASE DE HERBRAD, ya que no hay constantes. ");
}

return 0;
}

