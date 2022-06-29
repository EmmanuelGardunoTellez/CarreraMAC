#include<stdio.h>
 void main(){
 	int a=100, *a_ptr; //Declaracion de la variable y apuntador que son enteros
 	char * nombre="Emmanuel Garduño Tellez", dates[]="Edad: 18 Nacionalidad: Mexicana Carrera: Mac"; //Declaracion de la variable y un apuntador ajeno de tipo caracter
	a_ptr=&a; //Se le asin}gna al apuntador la direcion de la variable
	printf("%s\n%s\n\n", nombre,dates);
	
	printf("La direccion de la variable var es: %x\n", &a  );
   	printf("La direccion guardada en la variable  ip es: %x\n", a_ptr );
	printf("Valor de la variable *ip: %d\n", *a_ptr );

 }
