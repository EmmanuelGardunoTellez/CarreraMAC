#include <stdio.h>
#include <locale.h> 
#include <stdlib.h>

int portada ();                 //declaracion de funciones
int ConfiguraIdioma();

int ConfiguraIdioma(){
	struct lconv *lcPtr;
	setlocale(LC_ALL, "spanish");
	lcPtr = localeconv();
	
	lcPtr->decimal_point = ".";
	lcPtr->thousands_sep = ",";
	lcPtr->grouping = "3";	
} 
int portada (){
	printf("Universidad Nacional Autonoma de Mexico\n");
	printf("Facultad de Estudios Superiores Acatlan\n");
	printf("Programacion I\n");
	printf("Integrantes:\n");
	printf("Gamboa Francisco Gerardo.\t# Cuenta: 316355036\n");
	printf("Garduño Tellez Emmanuel.\t# Cuenta: 316212249\n");
	printf("Juarez Gallardo Isaac.\t# Cuenta: 316211091\n");
	printf("Maya Santa Rita Yuani.\t# Cuenta: 419079794\n");
	printf("Serrano Velazquez Carmen Ariana.\t# Cuenta: 419084125\n");
	printf("Grupo: 1104\n\n");
	system("pause");
}
//guardar en archivo Mibiblioteca.h
//guardarlo en una de las siguientes: a) Carpeta include del IDE   b)Otra carpeta
