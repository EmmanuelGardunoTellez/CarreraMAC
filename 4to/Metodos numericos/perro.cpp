#include <stdio.h>
#include <conio.h>
#define f 20
#define c 20

void NumPuntos( int *ru, int *cu)
{
	printf("Dime el numero de renglones de la matriz:");
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
	
 	for(j=0;j<ren;j++)
	{
		for(i=0;i<2;i++)	
		{
			printf("introduce el valor de la matriz (%d, %d): ",j,i);
			scanf("%lf",&matriz[j][i]);
		}
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
	int i ,cont=0;
	for (i = 0; i < col; i++){
		if(matriz[ren][i]==0){
			
		}else{
			cont = cont +1;
		}
	}
	return cont-2;
}

/*void enDonde2(double matriz[][c], int ren,double inter){
	int i;
	for(i=0; i< ren; i++){
		printf("%lf   ", matriz[i][0]);
	}
	printf("\n%lf\n", inter);
}
/*
int enDonde(double matriz[][c], int ren,double inter){
	int i, cont=0;
	for(i=0; i< ren; i++){
		if(matriz[ren][0]>inter){
			cont = cont+1;	
		} else {
			
		}
	}
	return  cont;
}*/

int menu()
{
	
	int opcion; 
	system("cls");
	printf("Por que metodo se resolvera el problema:\n");
	printf("1.Interpolacion.\n");
	printf("2.Ajuste de curvas\n");
	do
	{
		printf("Opcci�n: ");
		scanf("%d",&opcion);
	}while(!(opcion>=1&&opcion<=2));
	return opcion;
}

main()
{
	int opcion,n, ra, rb, ca, cb,Respuesta, gradop;
	double matriza[c][f], matrizb[c][f], matrizc[c][f], inter;
	do{
		system("cls");
		NumPuntos(&ra,&ca);
		datos(matriza, ra,ca);	
		imprimirDatos(matriza, ra,ca);
	//	imprimir(matriza, ra,ca);
		system ("pause");
		printf("�Quieres repetir? (1=si 0=no)");
		scanf("%d", &Respuesta);
	}while(Respuesta==1);
	system("pause");
	system("cls");
	

	opcion=menu();
	switch(opcion){
		case 1:
			printf("Interpolacion.\n");
			printf("Puntos ordenados");
			
			burbuja_mejorada(matriza, ra);
			imprimirDatos(matriza, ra,ca);
			
						
			interpolacion(matriza, ra, ca);
//			imprimir(matriza, ra,ca);
			do{

				printf("El punto a interpolar: ");
				scanf("%lf",&inter);
			}while(!(inter>=matriza[0][0]&&inter<=matriza[ra-1][0]));
			
		//	enDonde2(matriza, ra, inter);
			
			do{
				printf("de que grado quiere su polinomio: ");
				scanf("%d", &gradop);
			}while(!(gradop>=0&&gradop<=gradomax(matriza,0, ca)));
			
			
			
			break;
		case 2:
			printf("Ajuste de curvas\n");
			printf("En proceso\n");
			break;
			}
			
			
	printf("Bye\n");
	system("Pause");
}
