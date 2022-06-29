#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
float pivote;
void fila_pivote(int total, float matriz[total-2][total-2],float inversa[total-2][total-2], int i, int j)
{
    int m;
    for(m=0; m<total-2; m++)
        if(m != i)
            inversa[i][m]=matriz[i][m]/pivote;
}

void col_pivote(int total, float matriz[total-2][total-2],float inversa[total-2][total-2], int i, int j)
{
    int m;
    for(m=0; m<total-2; m++)
        if(m != j)
            inversa[m][j]=-matriz[m][j]/pivote;
}

void otros(int total, float matriz[total-2][total-2],float inversa[total-2][total-2], int i , int j)
{
    int x,y;
    for(x=0 ;x<total-2; x++)
        for(y=0; y<total-2; y++)
            if(x!=i && y!=j)
                inversa[x][y]=matriz[x][y]-(matriz[i][y]*matriz[x][j])/pivote;
}

void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }  
 
 float corrigeDatos(int n,float a[100], float b[100])
{
	int posicion, i, j;
	int resp;
	printf("1.-Corregir una posicion especifica\n ");
	printf("2.-Corregir toda la tabla");
	printf("Elija una opcion: ");
	scanf("%d",&resp);
	if(resp==1)
	{
		printf("Ingrese la posicion a corregir: ");
		scanf("%d",&posicion);
		printf("Ingrese el valor en x: "); scanf("%f",&a[posicion-1]);
		printf("Ingrese el valor en y: "); scanf("%f",&b[posicion-1]);
		
	}
	else
	{
		system("cls");
		printf("Ingrese los valores de la tabla: ");
		for(i=0;i<n;i++)
    	{   
			printf("Valores de X (%i): ", i+1);
	    	scanf("%f",&a[i]);
    	}
    	for(i=0;i<n;i++)
		{	
	        printf("Valores de Y (%i): ", i+1);
	    	scanf("%f",&b[i]);		
		}
	}
	
}
float ordena(int n,float a[100],float b[100])
{    
    int i,j;
    float paso, paso2;
    for(i=0; n>i;i++)
    {
    	for(j=i;n>j;j++)
    	{
    		if(a[i]>=a[j])
    		{
    			paso=a[i];  paso2=b[i];
    			a[i]=a[j];  b[i]=b[j];
    			a[j]=paso;  b[j]=paso2;
    			
			}
		}
	}
	
}
int revisa(int n, float a[100], float x)
{
	int regresa;
	if(a[0]<=x && a[n-1]>=x )
	{
		regresa=0;
	}
	else
	{
		regresa=1;
		printf("Hola2 %f",a[n-1]);
	}
	return regresa;
}

float leerPuntos(int total, float x[100], float y[100])
{
	int i;
	system("cls");
	printf("Ingrese los puntos: \n");
	for(i=0;total>i;i++)
	{
		gotoxy(0,3+2*i);
		printf("X[%d]",i+1);
		gotoxy(0,4+2*i);
		scanf("%f",&x[i]);
		gotoxy(6,3+2*i);
		printf("Y[%d]",i+1);
		gotoxy(6,4+2*i);
		scanf("%f",&y[i]);	
	}
	printf("Los datos ingresados son correctos?(0=no,1=si)");
	scanf("%d",&i);
	if(i==0)
	{
		corrigeDatos(total,x,y);
	}
	
}
int newtonp(int n, float a[100], float b[100])
{
	
	int i,j,k, resp;
	int verifica;
	if(n==0)
	{
		printf("Cuantos puntos va a ingresar?");
		scanf("%d",&n);
		leerPuntos(n,a,b);
	}
	else
	{
		printf("Desea usar la taba exixtente?(0=no ,1=si)");
		scanf("%d",&resp);
		if(resp==0)
		{
			printf("Cuantos puntos va a ingresar?");
	    	scanf("%d",&n);
			leerPuntos(n,a,b);
		}
		
	}
	ordena(n,a,b);
	
	system("cls");
	float copiab[n];
	float coef[n];
	printf(" xi        f[0]        f[1]      f[2]      f[3]      f[4]\n");
	for(i=0; n>i; i++)
	{
		printf("%f  %f\n",a[i],b[i]);
	}
	coef[0]=b[0];
	for(k=0;k<n;k++){
		for(j=0;j<n-(1+k);j++){
			
			if(k==(j+k)){
				for(i=0;i<n;i++)
				
				copiab[i]=b[i];
				
			}
			
			b[j]=(copiab[j+1]-copiab[j])/(a[j+(1+k)]-a[j]);
			gotoxy(10*k+22,j+1);
			printf("%f \n", b[j]);
			
			if(k==(j+k))
			coef[k+1]=b[j];
			
		}
		
		
		printf("\n");
	}
	
	printf("\n");
	float res, x, eval;
	gotoxy(20,20);
	do
	{
    	printf("En que punto desea evaluar ");
    	scanf("%f",&x);
      	verifica=revisa(n,a,x);
    	while(verifica==1)
      	{
    
     		printf("El punto no se encuentra dentro del intervalo");
       		printf("Ingrese el punto en que desea evaluar");
    		scanf("%f\t\n",&x);
    		verifica=revisa(n,a,x);
    	}
	
    	eval=coef[0];
    	for(i=1;i<n;i++)
		{
		
    		res=coef[i];
   		
    		for(j=0;j<i;j++)
		
     		res=res*(x-a[j]);
        		eval =eval+res;
    	}
 	    gotoxy(20,23);
	    printf("El valor de f(x) cuando x= %f es %f \t\n", x, eval);
	    printf("¿Desea interpolar otro punto con la misma tabla?(0=no,1=si)");
	    scanf("%d",&resp);
	}while(resp==1);

	return n;
}

float construyeTabla(int total, float x[100], float y[100], float hi[100], float fi[100], float sol[100])
{
	int i;
	for(i=1; total-1>=i; i++)
	{
		hi[i-1]=x[i]-x[i-1];
	}
	for(i=1; total-1>=i;i++)
	{
		fi[i-1]=(y[i]-y[i-1])/hi[i-1];
	}
	for(i=1;total-1>=i;i++)
	{
		sol[i]=6*(fi[i]-fi[i-1]);
	}
}
void imprime(int total, float x[100], float y[100], float hi[100], float fi[100], float si[100],float ai[100],float  bi[100],float  ci[100])
{
	system("cls");
	int i ;
	printf("Los polinomios y sus intervalos son:   \n");
	printf("X[i]       Y[i]       S[i]        a[i]         b[i]        c[i]         d[i]\n");
	for(i=0;total>i;i++) 
	{
		printf("%f   %f   %f   %f   %f   %f   %f\n ",x[i], y[i], si[i], ai[i],bi[i],ci[i], y[i]);
	}
	printf("\n\nPolinomios: \n");
	for(i=0; total-1>i;i++)
	{
		printf("g[%f]=%f(x-%f)^3+%f(x-%f)^2+%f(x-%f)+%f    %f<=x<=%f\n",i,ai[i],x[i],bi[i],x[i],ci[i],x[i],y[i], x[i],x[i+1]);
	}
	
	system("pause");
}
void calculaCoeficientes(int total, float y[100], float hi[100], float si[100],float ai[100],float bi[100],float ci[100])
{
	int i;
	for(i=0; total-1>i;i++)
	{
		ai[i]=(si[i+1]-si[i])/(6*hi[i]);
		bi[i]=si[i]/2;
		ci[i]=((y[i+1]-y[i])/hi[i])-hi[i]*((si[i+1]+2*si[i])/6);
		
	}
	
}
int ajusteCurvas(int total, float x[100], float y[100])
{
	int i, j,k,l, resp ;
	printf("%f",x[0]);
	if(total==0)
	{
		printf("Cuantos puntos va a ingresar?");
		scanf("%d",&total);
		leerPuntos(total, x, y);
	}
	else
	{
		printf("Desea usar la taba exixtente?(0=no ,1=si)");
		scanf("%d",&resp);
		if(resp==0)
		{
			printf("Cuantos puntos va a ingresar?");
	    	scanf("%d",&total);
			leerPuntos(total,x,y);
		}
		
	}
	system("cls");
	float hi[100], fi[100], si[100];
    float matriz[100-2][100-2];
	float inversa[100-2][100-2];
	float sol[100];
	float ai[100], bi[100], ci[100];
	construyeTabla(total, x, y, hi, fi,sol);
	for(i=0;total-2>i;i++)
	{
		for(j=0;total-2>j;j++)
		{
			if(i==j)
			{
				matriz[i][j]=2*(hi[i]+hi[i+1]);
			}
			else
			{
				if(i-j==1 || i-j==-1)
				{
					if(i-j==-1)
					{
				    	matriz[i][j]=hi[i+1];	
					}
					else
					{
						matriz[i][j]=matriz[j][i];
					}
					
				}
				else
				{
					matriz[i][j]=0;
				}
			}
		}
	}
	for(i=0; i<total-2; i++)
    {
        j=i;
        pivote=matriz[i][j];
        inversa[i][j]=1/pivote;
        fila_pivote(total, matriz, inversa,i,j);
        col_pivote(total, matriz, inversa,i,j);
        otros(total, matriz, inversa,i,j);
        for(k=0; k<total-2; k++)
            for(l=0; l<total-2; l++)
                matriz[k][l]=inversa[k][l];
    }
    si[0]=0; si[total]=0;
    for(i=0;total-2>i;i++)
    {
    	si[i+1]=0;
    	for(j=0;total-2>j;j++)
    	{
    		si[i+1]=si[i+1]+sol[j+1]*matriz[i][j];
		}
	}
	calculaCoeficientes(total, y, hi, si, ai, bi, ci);
	imprime(total, x, y, hi, fi,si, ai, bi, ci);
	return total;
}
void impDif(int total,float x[100],float y[100], int p1, int p2, float h, int val[100], int opc)
{
	int i;
	float der;
	if(opc==1)
	{
		system("cls");
	for(i=p1;p2>i;i++)
	{
		der=(y[i+1]-y[i-1])/(2*h);
		printf("%d   %f   %f    %f\n",i,x[i],y[i], der);
	}
	}
	
	if(opc==2)
	{
		float sum, area;
	area=0;
	for(i=0; total>i;i++)
	{
		printf("%d   %f   %f   %d   %f\n",i,x[i],y[i],val[i],val[i]*y[i]);
		area=area+val[i]*y[i];
	}
	printf("El area total es: %f",area*(h/3));
	}
	if(opc==3)
	{
		int i;
	float sum, area, area2;
	area=0;area2=0;
	for(i=0; total-3>i;i++)
	{
		printf("%d   %f   %f   %d   %f\n",i,x[i],y[i],val[i],val[i]*y[i]);
		area=area+val[i]*y[i];
	}
	for(i=total-4;total>i;i++)
	{
			printf("%d   %f   %f   %d   %f\n",i,x[i],y[i],val[i],val[i]*y[i]);
		area2=area2+val[i]*y[i];
	}
	printf("El area total es: %f",area*(h/3)+area2*(3*h/8));
	}
	
}
float verificaEqui(int total, float x[100], float y[100], float h)
{
	int i, verifica;
	float dis;
	verifica=0;
	for(i=0;total-1>i;i++)
	{
    	if(dis!=h)
    		{
       			verifica=1;
    		}
    		else
	    	{
    			printf("Los datos ingresados no son equidistantes. Por favor corrija la tabla");
    			system("pause");
    			corrigeDatos(total, x, y);
    			verifica=1;
    			break;
    		}
    		
	}
	return verifica;
}
void diferenciacion(int total, float x[100], float y[100], float h)
{
	int verifica, i, p1, p2, val[total], opc;
	opc=1;
	do
	{
	    verifica=verificaEqui(total, x, y, h);	
	}while(verifica!=1);
	for(i=0;total>i;i++)
	{
		printf("%d   %f   %f\n",i,x[i],y[i]);
	}
	printf("Entre que puntos desea conocer las derivadas?");

	scanf("%d",&p1); printf(" y "); scanf("%d",&p2);
	impDif(total, x, y, p1, p2, h, val,opc);
	
	
}

float simpson1_3(int total, float x[100], float y[100], float h, int val[100])
{
	int i;
	for(i=0;total>i;i++)
	{
		if(i==0 || i==total-1)
		{
			val[i]=1;
		}
		else
		{
			if(i%2==1)
			{
				val[i]=4;
			}
			else
			{
				val[i]=2;
			}
		}
	}
}
float simpson3_8(int total, float x[100], float y[100], float h, int val[100])
{
	int i;
	printf("HoliCompi");
	for(i=total-4;total>i;i++)
	{
		if(i==total-1 || i==total-4)
		{
			val[i]=1;
		}
		else
		{
			if(i%3!=0)
			{
				val[i]=3;
			}
			else
			{
				val[i]=2;
			}
		}
	}
	
}

float integracion(int total, float x[100], float y[100], float h)
{
	int verifica, val[total], opc, p1,p2;
	float area1, area2;
	do
	{
	    verifica=verificaEqui(total, x, y, h);	
	}while(verifica!=1);
	if((total%2==1))
	{
		opc=2;
		area1=simpson1_3(total, x, y, h, val);
		impDif(total, x, y, p1, p2, h, val, opc);
	}
	else
	{
		printf("holicompi");
		opc=3;
		area1=simpson1_3(total, x, y, h, val);
		area2=simpson3_8(total, x, y, h, val);
		impDif(total, x, y, p1, p2, h, val,opc);
	}
	
}
int dif_Inte(int total, float x[100], float y[100])
{
	int resp, p1, p2 ,val[100],opc;
    float h;
		if(total==0)
	{
		printf("Cuantos puntos va a ingresar?");
		scanf("%d",&total);
		leerPuntos(total, x, y);
	}
	else
	{
		printf("Desea usar la taba exixtente?(0=no ,1=si)");
		scanf("%d",&resp);
		if(resp==0)
		{
			printf("Cuantos puntos va a ingresar?");
	    	scanf("%d",&total);
			leerPuntos(total,x,y);
		}
	}
	ordena(total,x,y);
	printf("Ingrese el valor de h: ");
	scanf("%f",&h);
	
	system("cls");
	do
	{
			printf("1.-Diferenciacion numerica");
	printf("2.- Integracion numerica");
	printf("Que proceso desea realizar?\n");
	scanf("%d",&resp);
	switch(resp)
	{
		case 1:
			system("cls");
			do
			{
				diferenciacion(total, x, y, h);
				printf("Hacer cambios en la tabla?(0=no, 1=si)");
				scanf("%d",&resp);
				if(resp==1)
				{
					corrigeDatos(total,x,y);
				}
				else
				{
					printf("Desea cambiar el intervalo?(0=no,1=si)");
					scanf("%d",&resp);
					if(resp==1)
					{
						printf("Entre los puntos: "); scanf("%d",&p1); printf("y "); scanf("%d",&p2);
						opc=1;
							impDif(total, x, y, p1, p2, h, val, opc);
					}
					
				}
				printf("Desea ejecutar esta opcion de nuevo?");
				scanf("%d",&resp);
			}while(resp!=0);
			
		break;
		case 2: 
		system("cls");
	    	do
	    	{
	    	    integracion(total, x, y, h);
	    		printf("Desea ejecutar esta opcion de nuevo?");
	   			scanf("%d",&resp);
	   			if(resp==1)
	   			{
	   				integracion(total, x, y, h);
				}
	    	}while(resp!=0);
		break;
	}
	printf("Desea regresar al menu principal?(0=no, 1=si)");
	scanf("%d",&resp);
	}while(resp!=0);

	return total;
	
}
int main()
{
	int opcion, total, paso;
	total=0;
	float x[100], y[100];
	do
	{
		printf("***Para detener la ejecucion presione 0***");
		printf("Cual opcion desea realizar?\n\n");
    	printf("1.- Ajuste de Curvas\n");
    	printf("2.- Interpolacion de datos\n");
	    printf("3.- Diferenciacion e Integracion numerica\n");
    	scanf("%d",&opcion);
    	switch(opcion)
    	{
    		case 1: 
    		do
    		{
    			paso=ajusteCurvas(total, x, y);
    			printf("Desea cambiar la tabla?(0=no,1=si)");
    			scanf("%d",&opcion);
			}while(opcion!=0);
    	    	
    		break;
    		case 2:
    			do
    		    {
    		       	newtonp(total, x, y);
    		       	paso=printf("Desea cambiar la tabla?(0=no,1=si)");
    		       	scanf("%d",&opcion);
		      	}while(opcion!=0);
    		break;
    		case 3:
    			paso=dif_Inte(total, x, y);
      		break;
    	}
    	total=paso;
       printf("Desea realizar otro procedimiento?(0=no,1=si)");
       scanf("%d",&opcion);
	}while(opcion!=0);
	
	return 0;
}



