#include <stdio.h>
#include <stdlib.h>
#define P 150
#define C 11

main()
{
	int i, cant;
	char seguir;
	char productos[C][P] ={[0]="01    Galletas Oreo", [1]="02    Galletas empedador chocolate", [2]="03    Cafe americano",[3]="04    Capuchino", [4]="05    Chocolate caliente", [5]="06    Doritos nacho", [6]="07    Doritos pizzerola", [7]="08    Doritos infierno", [8]="09    Coca-Cola", [9]="10    Fanta", [10]="11    Fruzz tea"};
	//Nombre y codigo de cada producto en la tienda que se encuentra disponible
	float precios[C] = {[0]=12.00,[1]=12.00,[2]=18.00,[3]=25.00,[4]=10.00,[5]=11.00,[6]=11.00,[7]=12.00,[8]=18.00,[9]=14.00,[10]=15.00}; //Precio de cada producto en la tienda
	printf("Lista de productos disponibles en la tienda: \n");
	for(i=0; i<11; i++) //Muestra los productos disponibles
	{
 		printf("%s a solo: %.2f  \n", productos[i], precios[i]);
	}
	printf("¿Le interesa comprar alguno de nuestros productos?(s/n): ");
   	scanf( "%c", &seguir);//Le permite al usuario decidir si comprar con un s o n
   	if ( seguir != 'n' )
  	 	{
   			printf("Dija cual es el codigo del producto:");
   			scanf("%i", &i); //Recibe el codigo del porgucto
   			printf("Dija cuantos va a querer:");
   			scanf("%i", &cant); //Recibe cuantos va a querer
   			printf("\n\nCantidad  Producto                Total\n");
   			printf("    %s      %.2f  \n", productos[i-1], precios[i-1]*cant); //Muestra al usuario la cantidad de productos que compro y el precio total a pagar
		}
	   else
	   {
	   		printf("Vuelva pronto."); //Cuando el usuiario marca n
	   }
}
