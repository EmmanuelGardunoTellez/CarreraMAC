#include <stdio.h>

int const Tam=10;

void Invierte(int Dim, float Sist[][Tam], float Inv[][Tam]){
 int NoCero,Col,C1,C2,A;
 float Pivote,V1,V2;
 
 /*Se inicializa la matriz inversa, como la matriz identidad:*/
 for(C1=1;C1<=Dim;C1++) for(C2=1;C2<=Dim;C2++)
     if (C1==C2) Inv[C1][C2]=1; else Inv[C1][C2]=0;
 
 for(Col=1;Col<=Dim;Col++){
  NoCero=0;A=Col;
  while(NoCero==0){
   if((Sist[A][Col]>0.0000001)||((Sist[A][Col]<-0.0000001))){
    NoCero=1;}
   else A++;}
  Pivote=Sist[A][Col];
  for(C1=1;C1<=Dim;C1++){
   V1=Sist[A][C1];
   Sist[A][C1]=Sist[Col][C1];
   Sist[Col][C1]=V1/Pivote;
   V2=Inv[A][C1];
   Inv[A][C1]=Inv[Col][C1];
   Inv[Col][C1]=V2/Pivote;
            }
  for(C2=Col+1;C2<=Dim;C2++){
   V1=Sist[C2][Col];
   for(C1=1;C1<=Dim;C1++){
    Sist[C2][C1]=Sist[C2][C1]-V1*Sist[Col][C1];
                Inv[C2][C1]=Inv[C2][C1]-V1*Inv[Col][C1];}
 }}
 
 /*Aqui ya esta triangularizada, con 1s en diagonal, ahora se diagonaliza*/
 for(Col=Dim;Col>=1;Col--) for(C1=(Col-1);C1>=1;C1--)
    {
        V1=Sist[C1][Col]; 
        for(C2=1;C2<=Dim;C2++){
      Sist[C1][C2]=Sist[C1][C2]-V1*Sist[Col][C2];
      Inv[C1][C2]=Inv[C1][C2]-V1*Inv[Col][C2];
     }}
}


void multi (float matriza[][Tam], float matrizb[][Tam], float matrizc[Tam], int ra, int cb, int ca)
{
	int i,j,x;
	float suma=0;	
	for(i=0;i<ra;i++)
	{
		for(j=0;j<cb;j++)
		{
			suma=0;
			for (x=0;x<ca;x++)
			{
				suma=suma+(matriza[i][x]*matrizb[x][j]);	
			}
			matrizc[i]=suma;
		}	
	}	
}

void resta (float matriza[Tam], float matrizb[Tam], float matrizc[Tam]){
	int i,j;
	for(i=0;i<Tam;i++)
	{
		for(j=0;j<Tam;j++)
		{
			matrizc[i]= matriza[i]-matrizb[i];
		}	
	}	
}

void imprimir(float matriz[Tam], int ren){
	int j;
	for(j=0;j<ren;j++)
	{
		printf("%d ", matriz[j]);
		printf(")\n");
	}
}

int menu()
{
	system("cls");
	int opcion;
	printf("Garduno Baldazo Cristian\n");
	printf("Garduno Tellez Emmanuel\n\n");
	printf("Seleccione las matrices \n");
	printf("1. f(1)(x,y)= \n f(2)(x,y)=\n");
	printf("2. f(1)(x,y)= \n f(2)(x,y)=\n");
	printf("3. f(1)(x,y,z)= \n f(2)(x,y,z)= \n f(3)(x,y,z)= \n");
	printf("4. f(1)(x,y,z)= \n f(2)(x,y,z)= \n f(3)(x,y,z)= \n");
	printf("5.Salir\n");
	do
	{
		printf("Opcción: ");
		scanf("%d",&opcion);
	}while(!(opcion>=1&&opcion<=5));
	return opcion;
}


main()
{
	
	int opcion, dimension, max, tol;
	float Sistema[Tam][Tam],Inversa[Tam][Tam], x=0, y=0;
	float ValoresIniciales[Tam], f[Tam], df[Tam][Tam], Jinv[Tam][Tam], MJF[Tam], NuevosFX[Tam] ;
	do {
		opcion=menu();
		if(opcion!=5)
		{
			switch(opcion){
				case 1:
					system("cls");
					
					printf("Introduce el valor inicial del punto:\nx=");
					scanf("%f", &ValoresIniciales[0]);
					printf("y=");
					scanf("%f", &ValoresIniciales[1]);
					printf("Maximo de iterraciones, en caso de que no converga:");
					scanf("%d",max);
					printf("Introduce la tolerancia:\n");
					scanf("%f", tol);
					dimension = 2;
					
					x = ValoresIniciales[0];
					y = ValoresIniciales[1];
					f[0] =  (x*x)+ (x*y)-10;
					f[1] =  y + (3*x*y*y)-50;
					df[0][0]= (2*x) + y;
					df[0][1]= x;
					df[1][0]= 3*y*y;
					df[1][1]= 1+(3*2*x*y);

					Sistema[0][0] = df[0][0];
					Sistema[0][1] = df[0][0];
					Sistema[1][0] = df[0][0];
					Sistema[1][1] = df[0][0];
					
					Invierte(dimension,Sistema,Jinv);
					multi (Jinv, f , MJF , 2 , 1 , 2 );
					resta (ValoresIniciales, MJF, NuevosFX);
					
					imprimir(NuevosFX,  dimension);
					
					
					break;
					
				case 2:	
					system("cls");
						
					break;
				case 3:
					system("cls");
					
					break;
				case 4:
					system("cls");
					
					break;
			}//fin del switch
		}
	}while(opcion!=5);

	printf("Bye\n");
	system("Pause");
}







