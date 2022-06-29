#include <stdio.h>
#include <conio.h>
#define f 20
#define c 20

void NumPuntos( int *ru, int *cu)
{
	printf("Dime el numero de puntos:\n");
	printf("(Al momento de introducir las coordenadas del punto dar un espacio en lugar de la ,)\n");
		scanf("%d",ru);
		*cu=*ru+1;

}

void datos(double matriz[][c],int ren,int col)
{
	int i,j;
	
	for(j=0;j<f;j++)
	{
		for(i=0;i<c;i++)	
		{
			matriz[j][i] = 0;
		}
	}
	
 	for(j=0;j<ren;j++){
 		
 		printf("dime el punto %d: ",j);
		scanf("%lf %lf",&matriz[j][0], &matriz[j][1]);
 		/*
		for(i=0;i<2;i++)	
		{
			printf("introduce el valor de la matriz (%d, %d): ",j,i);
			scanf("%lf",&matriz[j][i]);
		}*/
	}
	
	
}





void interpolacion(double matriz[][c], int ren, int col){
	int i, j, j1=1;
	for(i=2;i<col;i++){
		ren= ren -1;
		for(j=0;j<ren;j++){
			matriz[j][i]=(matriz[j+1][i-1]-matriz[j][i-1])/(matriz[j+j1][0]-matriz[j][0]);
		}
		j1=j1+1;
	}
}


void spline(double matriz[][c], int ren, int col){
	int i, j, j1=1;
	for(i=0;i<ren-1;i++){
		matriz[i][2]= matriz[i+1][0]- matriz[i][0];  //hi
		matriz[i][3]= (matriz[i+1][1]- matriz[i][1])/(matriz[i+1][0]- matriz[i][0]); //f1
	}
	
	matriz[4][0]= 0;     //es la coluna
	for(i=1;i<col-2;i++){
		matriz[i][4]= 3;   //s
	}
	matriz[4][col-1]=20;

	for(i=0;i<col-2;i++){
		matriz[i][5]= (matriz[i+1][4]-matriz[i][4])/(6*matriz[i][2]);   //a
		matriz[i][6]= (matriz[i][4])/2;  //b
		matriz[i][7]= (matriz[i+1][1]-matriz[i][1])/matriz[i][2] - ((matriz[i+1][4]+2*matriz[i][4])/6)*matriz[i][2]; //c
		matriz[i][8]=  matriz[i][1];//d
	}
		
}

void resultado1(double matriza[][c], double matrizb[][c], int ren, int col){
	int i;
	
	for(i=0;i<col-2;i++){
		matrizb[i][0]= 6*(matriza[i+1][3]-matriza[i][3]);
	}
	}


void mostrarSpline(double matriz[][c], int ren, int col){
	int i;
	printf("\ntablas de datos: \n");
	for(i=0;i<ren-1;i++){
		printf("%lf(x-xi)^3+ %lf(x-xi)^2+ %lf(x-xi)+ %lf     %lf<=x<=%lf\n",
		matriz[i][5], matriz[i][6], matriz[i][7], matriz[i][8], matriz[i][0], matriz[i+1][0]);
	}
}


void imprimir(double matriz[][c], int ren, int col){
	int i,j;
	for(j=0;j<ren;j++)
	{
		printf("(");
		for(i=0;i<col;i++)	
		{
			printf("%lf ", matriz[j][i]);
		}
		printf(")\n");
	}
}

void imprimirDatos(double matriz[][c], int ren, int col){
	int i,j;
	printf("x\t \ty\n");
	for(j=0;j<ren;j++)
	{
		printf("\n");
		for(i=0;i<2;i++)	
		{
			printf("%lf\t", matriz[j][i]);
		}
		printf("\n");
	}
}


void desplegar(int * arr, int tam){
    int i;
    for(i=0; i<tam; i++){
        printf("%d ", arr[i]);
    }
}


void swap(double * xp, double * yp){
    double temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void burbuja_mejorada(double arr[][c], int ren){
    int i, j;
    for (i = 0; i < ren-1; i++){
        for (j = 0; j < ren-i-1; j++){
            if (arr[j][0] > arr[j+1][0]){
                swap(&arr[j][0], &arr[j+1][0]);
                swap(&arr[j][1], &arr[j+1][1]);
            }
        }
    }
}

void grado(double matriz[][c], int ren,int col){
	int i;
	for (i = 0; i < col; i++){
		printf("%lf   ", matriz[ren][i]);
	}
}


int gradomax(double matriz[][c], int ren,int col){
/*	int i ,cont=0;
	for (i = 0; i < col; i++){
		if(matriz[ren][i]==0){
			
		}else{
			cont = cont +1;
		}
	}
	return cont-2;*/
	return col-2;
	
	//return 
}

/*void enDonde2(double matriz[][c], int ren,double inter){
	int i;
	for(i=0; i< ren; i++){
		printf("%lf   ", matriz[i][0]);
	}
	printf("\n%lf\n", inter);
}*/

/*int enDonde(double matriz[][c], int ren,double inter){
	int i, cont=0;
	for(i=0; i< ren; i++){
		if(matriz[ren][0]>inter){
			cont = cont+1;	
		} else {
			
		}
	}
	return  cont;
}*/

void puntoAInterpolar(double matriz[][c], int ren, int col,int grado, double inter){
	double resultado=0, resul=0;
	int i, j;
	
	printf("\n");
	for(i=0; i< grado+1; i++){
		for(j=0; j< i; j++){
			resul= inter-matriz[j][0];
			printf("%lf * ", resul);
			resul=0;	
		}
		printf("%lf + ", matriz[0][i+1]);
	}
}

double puntoAInterpolarNum(double matriz[][c], int ren, int col,int grado, double inter){
	double resultado=0, resul=0, valor =1;
	int i, j;
	
	printf("\n");
	for(i=0; i< grado+1; i++){
		for(j=0; j< i; j++){
			resul= inter-matriz[j][0];
			resultado= resultado * resul;
//			printf("%lf * ", resul);
			resul=0;	
		}
	//	printf("%lf + ", matriz[0][i+1]);
		resultado= resultado * matriz[0][i+1];
		valor =valor + resultado;
		resultado =1;
	}
	return valor;
}
	

int menu()
{
	
	int opcion; 
	system("cls");
	printf("Por que metodo se resolvera el problema:\n");
	printf("1.Interpolacion.\n");
	printf("2.Ajuste de curvas\n");
	printf("3.Salir\n");
	do
	{
		printf("Opcción: ");
		scanf("%d",&opcion);
	}while(!(opcion>=1&&opcion<=3));
	return opcion;
}

main()
{
	int opcion,n, ra, rb, ca, cb,Respuesta, gradop;
	double matriza[c][f], matrizb[c][f], matrizc[c][f], inter;


	printf("Garduño Téllez Emmanuel\n");
	printf("Garduño Baldazo Cristian\n");
	system("pause");
do{

	opcion=menu();
	switch(opcion){
		case 1:
			
			do{
				do{
					system("cls");
				
					NumPuntos(&ra,&ca);
					datos(matriza, ra,ca);	
					imprimirDatos(matriza, ra,ca);
				//	imprimir(matriza, ra,ca);
					system ("pause");
					printf("¿Quiere cambar los puntos? (1=si 0=no) ");
					scanf("%d", &Respuesta);
				}while(Respuesta==1);
				system("pause");
				system("cls");
			
			
				do{
					system("pause");
					printf("Interpolacion.\n");
					printf("Puntos ordenados");
				
					burbuja_mejorada(matriza, ra);
					imprimirDatos(matriza, ra,ca);
			
						
					interpolacion(matriza, ra, ca);
					imprimir(matriza, ra,ca);
					do{

						printf("El punto a interpolar: ");
						scanf("%lf",&inter);
					}while(!(inter>=matriza[0][0]&&inter<=matriza[ra-1][0]));
					system("cls");
			
					//printf("%lf\n", enDonde(matriza, ra, inter));
			
					do{
						printf("de que grado quiere su polinomio: ");
						scanf("%d", &gradop);
					}while(!(gradop>=0&&gradop<=gradomax(matriza,0, ca)));
			
					puntoAInterpolar(matriza, ra, ca, gradop, inter);
					printf("\nEl resultado de esto es: %lf\n", puntoAInterpolarNum(matriza, ra, ca, gradop, inter));
					system ("pause");
					printf("¿Quieres sacar otro punto con la misma tabla? (1=si 0=no)");
					scanf("%d", &Respuesta);
					}while(Respuesta==1);
					system("cls");
					system ("pause");
					printf("¿Quieres cambiar la tabla? (1=si 0=no)");
					scanf("%d", &Respuesta);
				}while(Respuesta==1);
				system("cls");
			
			break;
		case 2:
			printf("Ajuste de curvas\n");	
				do{
				do{
					system("cls");
				
					NumPuntos(&ra,&ca);
					datos(matriza, ra,ca);	
					imprimirDatos(matriza, ra,ca);
				//	imprimir(matriza, ra,ca);
					system ("pause");
					printf("¿Quiere cambar los puntos? (1=si 0=no) ");
					scanf("%d", &Respuesta);
				}while(Respuesta==1);
				system("pause");
				system("cls");
			
			
				do{
					system("pause");
					printf("Ajuste de curvas.\n");
					printf("Puntos ordenados");
				
					burbuja_mejorada(matriza, ra);
					imprimirDatos(matriza, ra,ca);
			
					spline(matriza,ra, ca);
					imprimir(matriza, ra,9);
					
					mostrarSpline(matriza, ra, ca);
					
					printf("\n\nEstos son los polinomios y sus intervalos");
					system ("pause");
					printf("¿Quieres sacar otro punto con la misma tabla? (1=si 0=no)");
					scanf("%d", &Respuesta);
					}while(Respuesta==1);
					system("cls");
					system ("pause");
					printf("¿Quieres cambiar la tabla? (1=si 0=no)");
					scanf("%d", &Respuesta);
				}while(Respuesta==1);
				system("cls");
				
			system("pause");
			system("cls");
			break;
			}
}while(opcion!=3);
			
	printf("\nBye\n");
	system("Pause");
}
