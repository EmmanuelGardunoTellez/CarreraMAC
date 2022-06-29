 #include <stdio.h>
 #include "biblioteca.h"

	main()
	{
	int anno,respuesta;
	ConfiguraIdioma();
	portada();
	do
	{
		
		printf("Programa que dice cuando un año es bisiesto o no es bisiesto.\n");
		printf("Dime el año el cual queres sabes si es o no bisiesto.\n");
		scanf("%d",&anno);
		if((anno%100)==0)
		{
			printf("El año %d es bisiesto.\n",anno);
		}
			else
		{
			if((anno%4)==0 || (anno%100)==0)
			{
				printf("El año %d es bisiesto.\n",anno);
			}
			else
			{
				printf("El año %d no es bisiesto.\n",anno);
			}	
		}
		printf("Deseas continuar? (1=si 0=no) \n");
		scanf("%d", &respuesta);
	}while(respuesta==1);
	system("pause");
	return 0;
	}
