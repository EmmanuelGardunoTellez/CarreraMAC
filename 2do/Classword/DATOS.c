#include<stdio.h>

int main(){
	FILE *datos = fopen("Datos.txt", "r"); //Abre el texto
	FILE *OraRam = fopen("Oracion ramdom.txt","w");//Crea un texto y escribbe en el
	int i, numero1, numero2, numero3;  //Declaracion de enteros
	char cad1[10][10], cad2[10][10], cad3[10][50]; //Matrices de char para almacenar datos
	for(i=0;i<10;i++){ //For para guardar cada palabra u oracion
	fscanf(datos, "%s %s %[^\n]%*c", cad1[i], cad2[i], cad3[i]); /*Nota para los primeros dos guarda solo una palabra y el resto una oracion*/
}
/*
for(i=0;i<10;i++){ //Muestra como se divirieron
	printf("%s \n", cad1[i]);
	printf("%s \n",cad2[i]);
	printf("%s \n\n",cad3[i]);
}
*/ //Es innesesario
numero1= rand()%10; //Saca los numeros random
numero2= rand()%10;
numero3= rand()%10;

fprintf(OraRam,"%s %s %s", cad1[numero1], cad2[numero2], cad3[numero3]); //Te garda la oracion generara al azar en un archivo externo

	fclose(datos); //Cierra los archivos de texto creados
	fclose(OraRam);
	return 0;
}
