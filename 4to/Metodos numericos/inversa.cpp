#include <stdio.h>

int const Tam=100;
void PideDatos(int *Dim, float Sist[][Tam]);
void EscribeDatos(int Dim, float Sist[][Tam]);
void Invierte(int Dim, float Sist[][Tam], float Inv[][Tam]);


int main(void)
{
 int C,Dimension;
 float Sistema[Tam][Tam],Inversa[Tam][Tam];
 PideDatos(&Dimension,Sistema);
 printf("\n\n\nLa matriz introducida es la siguiente: \n\n");
 EscribeDatos(Dimension,Sistema);
 Invierte(Dimension,Sistema,Inversa);
 printf("\n\n\nLa inversa de la matriz es: \n\n");
 EscribeDatos(Dimension,Inversa);
 
 scanf("%d");
 return(0);
}


void PideDatos(int *Dim,float Sist[][Tam])
{
 int A,B, x=1 ,y=2, z=4; 
     printf("\n\n ||CALCULA INVERSA||");
 printf("\n\n\n Introduce el tamano de la matriz:");
 *Dim=3;
 Sist[0][0]= (4*x)-4;
	Sist[0][1]= 2*y;
	Sist[0][2]= 0;
	
	Sist[1][0]= (2*x)-1;
	Sist[1][1]= -12;
	Sist[1][2]= 0;
	
	Sist[2][0]= (6*x)-12;
	Sist[2][1]= 2*y;
	Sist[2][2]= (-6*z);
 }
 

void EscribeDatos(int Dim, float Sist[][Tam])
{
 int A,B;
 for(A=1;A<=Dim;A++){
  for(B=1;B<=(Dim);B++) printf("%7.2f",Sist[A][B]);
  printf("\n");
 }}

void Invierte(int Dim, float Sist[][Tam], float Inv[][Tam])
{
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


