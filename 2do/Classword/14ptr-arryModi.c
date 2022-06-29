/* ********************* TEXTO SIN ACENTOS *********************/
// Recuerda documentar tus codigos

#include <stdio.h>
#include<string.h>
  
 struct Family //Almacena los datos en una estructura
{
 char name [30];
 char age [4];
 char date[25];
 char sit[10];
 char facebook [25];
 char twitter[15];
};

int main () {
   int r=0; //Cosntante para un for
   struct Family fam[3], fami; //Definicion de estructura
   
   
   FILE *archivo2 = fopen("Familia.txt", "w"); //Crea a .txt y con w ayuda a escribir
   
   for(r=0;r<3;r++){ //Lectura de datos
   	printf("Persona %i:\n",r+1);
   	printf("Dame el nombre de la persona: ");
   	gets(fam[r].name); //Almacena el texto en la cadena, asi con cada una de ellas
   	fprintf(archivo2,"Persona %i: %s\n",r+1 ,fam[r].name);
   	printf("Dame la edad: ");
   	gets(fam[r].age);
   	fprintf(archivo2,"Edad: %s\n",fam[r].age);
   	printf("Dame la fecha de nacimento (formato dd/mm/aaaa): ");
   	gets(fam[r].date);
   	fprintf(archivo2,"Fecha de nacimeinto: %s\n",fam[r].date);
   	printf("Dame el Facebook de la persona: ");
   	gets(fam[r].facebook);
   	fprintf(archivo2,"Edad: %s\n",fam[r].facebook);
   	printf("Dame el Twiter de la persona: ");
   	gets(fam[r].twitter);
   	fprintf(archivo2,"Edad: %s\n",fam[r].facebook);
   	printf("Dame el estado civil de la persona: ");
   	gets(fam[r].sit);
   	fprintf(archivo2,"Edad: %s\n",fam[r].sit);
   }
   //Se usa solo para datos ya dados
   /*strcpy(fam[0].name, "Garduño Tellez Emmanuel");
   strcpy(fam[0].age, "18");
   strcpy(fam[0].date, "01/11/2000");
   strcpy(fam[0].sit, "Soltero");
   strcpy(fam[0].facebook, "Emmanuel Garduño Téllez");
   strcpy(fam[0].twitter, "@emmaudi3");
   strcpy(fam[1].name, "Garduño Téllez Maria hipolita");
   strcpy(fam[1].age, "55");
   strcpy(fam[1].date, "14/08/1966");
   strcpy(fam[1].sit, "Soltera");
   strcpy(fam[1].facebook, "No tiene");
   strcpy(fam[1].twitter, "No tiene");
   strcpy(fam[2].name, "Abigail Gomez Garduño");
   strcpy(fam[2].age, "13");
   strcpy(fam[2].date, "02/02/2006");
   strcpy(fam[2].sit, "Soltera");
   strcpy(fam[2].facebook, "No tiene");
   strcpy(fam[2].twitter, "No tiene");
//Se usa para almacenar en una cadena todos los datos
   for(r=0;r<3;r++) //Concatenacion de los datos de clima
    {
        strcat( fam[r].name," ");
        strcat( fam[r].name , ", Edad:");
        strcat( fam[r].name , fam[r].age);
        strcat( fam[r].name , " Fecha de nacimiento:");
        strcat( fam[r].name , fam[r].date);
        strcat( fam[r].name , " \n Facebook:");
        strcat( fam[r].name , fam[r].facebook);
        strcat( fam[r].name , " Twiter:");
        strcat( fam[r].name , fam[r].twitter);
        strcat( fam[r].name , " Estado civil:");
        strcat( fam[r].name , fam[r].sit);
        strcat( fam[r].name , "\n\n");   
    }
    
    for(r=0;r<3;r++){
    	printf("%s", fam[r].name);
	}
    */
    
    fclose(archivo2);
   
   return 0;
}
