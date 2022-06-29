#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<iostream>
#include"invertir.h"
using namespace std;
double f1(double x,double y){return x*x+x*y-10;}
double f2(double x,double y){return y+3*x*y*y-50;}
double g1(double x,double y){return x*x+y*y-9;}
double g2(double x,double y){return -1*exp(x)-2*y-3;}
double h1(double x,double y,double z){return 2*x*x-4*x+y*y+3*z*z+6*z+2;}
double h2(double x,double y,double z){return x*x+y*y-2*y+2*z*z-5;}
double h3(double x,double y,double z){return 3*x*x-12*x+y*y-3*z*z+8;}
double i1(double x,double y,double z){return x*x-4*x+y*y;}
double i2(double x,double y,double z){return x*x-x-12*y+1;}
double i3(double x,double y,double z){return 3*x*x-12*x+y*y-3*z*z+8;}


double f1x(double x,double y){return x*2+y;}
double f2x(double x,double y){return 3*y*y;}
double g1x(double x,double y){return x*2;}
double g2x(double x,double y){return -1*exp(x);}
double h1x(double x,double y,double z){return 4*x-4;}
double h2x(double x,double y,double z){return x*2;}
double h3x(double x,double y,double z){return 6*x-12;}
double i1x(double x,double y,double z){return x*2-4;}
double i2x(double x,double y,double z){return x*2-1;}
double i3x(double x,double y,double z){return 6*x-12;}

double f1y(double x,double y){return x;}
double f2y(double x,double y){return 1+6*x*y;}
double g1y(double x,double y){return y*2;}
double g2y(double x,double y){return -2;}
double h1y(double x,double y,double z){return 2*y;}
double h2y(double x,double y,double z){return y*2-2;}
double h3y(double x,double y,double z){return 2*y;}
double i1y(double x,double y,double z){return 2*y;}
double i2y(double x,double y,double z){return -12;}
double i3y(double x,double y,double z){return 2*y;}

double h1z(double x,double y,double z){return 3*z+6;}
double h2z(double x,double y,double z){return 4*z;}
double h3z(double x,double y,double z){return -6*z;}
double i1z(double x,double y,double z){return 0;}
double i2z(double x,double y,double z){return 0;}
double i3z(double x,double y,double z){return -6*z;}

void limpiar(double a[5][5]){
	int i,j;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			a[i][j] = 0;
		}
	}
}
void llenar(double a[5][5]){
	int i,j;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			a[i][j] = 5;
		}
	}
}
void resta(double a[5][5],double b[5][5],double res[5][5],int n=3,int m=3){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			res[i][j] = a[i][j] - b[i][j];
		}
	}
}
void imprime(double a[5][5],int n=3,int m=3){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cout<<a[i][j]<<"\t";
		}
		cout<<"\n";
	}
}
void mmul(double a[5][5],double b[5][5],double res[5][5],int n=3,int nm=3,int m=1){
	int i,j,k;
	double be;
	for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				be=0;
				for(k=0;k<nm;k++){
				be +=(a[i][k] * b[k][j]);	
				}
			res[i][j] = be;
					//	y.m[i][j].reducir();
		}
	}
}

void inversa(double mat[5][5],int tama,double inv[5][5]){
    int n=tama,m=tama;
    
    double cof[n][m],adj[n][m],cofaux[n][m],aux_inv[n][m];
    
    int i=0,j=0,d=0,k=0,e=0;
	double det=0,det2=0,det3=0,det4=0,aux_cof=1;
    float det5;
    
    //calculamos la matriz cofactor
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            for(d=0;d<n;d++){
            for(e=0;e<m;e++){
            for(k=0;k<m;k++){
                    if((i+k)%2==0){
                        aux_cof = 1;
                       }
                       else if((i+k)%2!=0){
                        aux_cof= -1;
                       }
                    if((d==k || d!=k) && (e==k || e==d)){
                        cofaux[i][j]= aux_cof*((mat[i][k]*mat[d][j])-(mat[i][k]*mat[e][j]));
                    }
            }
        }
    }
    }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cof[i][j]= cofaux[i][j];
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
                adj[i][j] = cof[j][i];
 
        }
    }
    //buscamos determinante
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            for(k=0;k<n;k++){
                for(e=0;e<n;e++){
                    det=0;
                    det2=0;
                    for(d=0;d<m;d++){
                        if((d!=k || d==k) && (e==k || e==d)&& i!=j){
                            if(i%2==0 && j%2==0 ){
                                det= det + ((mat[i][d]*mat[k][j])-(mat[i][e]*mat[d][j]));
                            }
                            else if(i%2!=0 && j%2!=0 ){
                                det2= det-((mat[i][d]*mat[k][j])-(mat[i][d]*mat[e][j]));
                            }
                        }
                        if(i==j){
                                det3= det3 +(mat[i][j]*det);
                                det4= det4 +(mat[i][j]*det2);
                        }
                    }
                }
            }
        }
    }
    det5 = det3 + det4;
    if(det5==0){
        cout<<"matriz no tiene inversa"<<endl;
    }
    else{
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                aux_inv[i][j]= (1/det5)*adj[i][j];
                inv[i][j] = aux_inv[i][j];
            }
        }
    }
}

double func(int ecuacion,int funcion,int derivada,double x,double y,double z){
	switch(ecuacion){
		case 1:
			if(funcion == 1){
			switch(derivada){
				case 0:
					return f1(x,y);
					break;
				case 1:
					return f1x(x,y);
					break;
				case 2:
					return f1y(x,y);
					break;
				}
			}else{
				switch(derivada){
				case 0:
					return f2(x,y);
					break;
				case 1:
					return f2x(x,y);
					break;
				case 2:
					return f2y(x,y);
					break;
			}
			}
			break;
		case 2:
			if(funcion == 1){
			switch(derivada){
				case 0:
					return g1(x,y);
					break;
				case 1:
					return g1x(x,y);
					break;
				case 2:
					return g1y(x,y);
					break;
				}
			}else{
				switch(derivada){
				case 0:
					return g2(x,y);
					break;
				case 1:
					return g2x(x,y);
					break;
				case 2:
					return g2y(x,y);
					break;
			}
			}
			break;
		case 3:
			if(funcion == 1){
			switch(derivada){
				case 0:
					return h1(x,y,z);
					break;
				case 1:
					return h1x(x,y,z);
					break;
				case 2:
					return h1y(x,y,z);
					break;
				case 3:
					return h1z(x,y,z);
					break;
					
				}
			}else if(funcion == 2){
				switch(derivada){
				case 0:
					return h2(x,y,z);
					break;
				case 1:
					return h2x(x,y,z);
					break;
				case 2:
					return h2y(x,y,z);
					break;
				case 3:
					return h2z(x,y,z);
					break;
					
				}
			}else{
				switch(derivada){
				case 0:
					return h3(x,y,z);
					break;
				case 1:
					return h3x(x,y,z);
					break;
				case 2:
					return h3y(x,y,z);
					break;
				case 3:
					return h3z(x,y,z);
					break;
					
				}
			}
			break;
		case 4:
			if(funcion == 1){
			switch(derivada){
				case 0:
					return i1(x,y,z);
					break;
				case 1:
					return i1x(x,y,z);
					break;
				case 2:
					return i1y(x,y,z);
					break;
				case 3:
					return i1z(x,y,z);
					break;
					
				}
			}else if(funcion == 2){
				switch(derivada){
				case 0:
					return i2(x,y,z);
					break;
				case 1:
					return i2x(x,y,z);
					break;
				case 2:
					return i2y(x,y,z);
					break;
				case 3:
					return i2z(x,y,z);
					break;
					
				}
			}else{
				switch(derivada){
				case 0:
					return i3(x,y,z);
					break;
				case 1:
					return i3x(x,y,z);
					break;
				case 2:
					return i3y(x,y,z);
					break;
				case 3:
					return i3z(x,y,z);
					break;
					
				}
			}
			break;
	}
}
//fin
void jaco(double jacobi[5][5],int sistema,double x,double y,double z){
	switch(sistema){
		case 1:
			jacobi[0][0] = func(1,1,1,x,y,z);
			jacobi[0][1] = func(1,1,2,x,y,z);
			jacobi[1][0] = func(1,2,1,x,y,z);
			jacobi[1][1] = func(1,2,2,x,y,z);
			
			break;
		case 2:
			jacobi[0][0] = func(2,1,1,x,y,z);
			jacobi[0][1] = func(2,1,2,x,y,z);
			jacobi[1][0] = func(2,2,1,x,y,z);
			jacobi[1][1] = func(2,2,2,x,y,z);
			
			break;
		case 3:
			jacobi[0][0] = func(3,1,1,x,y,z);
			jacobi[0][1] = func(3,1,2,x,y,z);
			jacobi[0][2] = func(3,1,3,x,y,z);
			jacobi[1][0] = func(3,2,1,x,y,z);
			jacobi[1][1] = func(3,2,2,x,y,z);
			jacobi[1][2] = func(3,2,3,x,y,z);
			jacobi[2][0] = func(3,3,1,x,y,z);
			jacobi[2][1] = func(3,3,2,x,y,z);
			jacobi[2][2] = func(3,3,3,x,y,z);
			
			break;
		case 4:
			jacobi[0][0] = func(4,1,1,x,y,z);
			jacobi[0][1] = func(4,1,2,x,y,z);
			jacobi[0][2] = func(4,1,3,x,y,z);
			jacobi[1][0] = func(4,2,1,x,y,z);
			jacobi[1][1] = func(4,2,2,x,y,z);
			jacobi[1][2] = func(4,2,3,x,y,z);
			jacobi[2][0] = func(4,3,1,x,y,z);
			jacobi[2][1] = func(4,3,2,x,y,z);
			jacobi[2][2] = func(4,3,3,x,y,z);
			break;
		
	}
}
void jaco(double jacobi[5][5],int sistema,double X[5][5]){
	double x,y,z;
	x= X[0][0];
	y= X[1][0];
	z= X[2][0];
	switch(sistema){
		case 1:
			jacobi[0][0] = func(1,1,1,x,y,z);
			jacobi[0][1] = func(1,1,2,x,y,z);
			jacobi[1][0] = func(1,2,1,x,y,z);
			jacobi[1][1] = func(1,2,2,x,y,z);
			
			break;
		case 2:
			jacobi[0][0] = func(2,1,1,x,y,z);
			jacobi[0][1] = func(2,1,2,x,y,z);
			jacobi[1][0] = func(2,2,1,x,y,z);
			jacobi[1][1] = func(2,2,2,x,y,z);
			
			break;
		case 3:
			jacobi[0][0] = func(3,1,1,x,y,z);
			jacobi[0][1] = func(3,1,2,x,y,z);
			jacobi[0][2] = func(3,1,3,x,y,z);
			jacobi[1][0] = func(3,2,1,x,y,z);
			jacobi[1][1] = func(3,2,2,x,y,z);
			jacobi[1][2] = func(3,2,3,x,y,z);
			jacobi[2][0] = func(3,3,1,x,y,z);
			jacobi[2][1] = func(3,3,2,x,y,z);
			jacobi[2][2] = func(3,3,3,x,y,z);
			
			break;
		case 4:
			jacobi[0][0] = func(4,1,1,x,y,z);
			jacobi[0][1] = func(4,1,2,x,y,z);
			jacobi[0][2] = func(4,1,3,x,y,z);
			jacobi[1][0] = func(4,2,1,x,y,z);
			jacobi[1][1] = func(4,2,2,x,y,z);
			jacobi[1][2] = func(4,2,3,x,y,z);
			jacobi[2][0] = func(4,3,1,x,y,z);
			jacobi[2][1] = func(4,3,2,x,y,z);
			jacobi[2][2] = func(4,3,3,x,y,z);
			break;
		
	}
}

void vincog(double v[5][5],double x,double y,double z=0){
		v[0][0] = x;
		v[1][0] = y;
		v[2][0] = z;
}
void vfuncion(double v[5][5],int sistema,double x,double y,double z=0){
	switch(sistema){
		case 1:
			v[0][0] = func(1,1,0,x,y,z);
			v[1][0] = func(1,2,0,x,y,z);
			v[2][0] = 0;
			break;
		case 2:
			v[0][0] = func(2,1,0,x,y,z);
			v[1][0] = func(2,2,0,x,y,z);
			v[2][0] = 0;
			break;
		case 3:
			v[0][0] = func(3,1,0,x,y,z);
			v[1][0] = func(3,2,0,x,y,z);
			v[2][0] = func(3,3,0,x,y,z);
			break;
		case 4:
			v[0][0] = func(4,1,0,x,y,z);
			v[1][0] = func(4,2,0,x,y,z);
			v[2][0] = func(4,3,0,x,y,z);
			
			break;
		
	}
}
void vfuncion(double v[5][5],int sistema,double X[5][5]){
	double x,y,z;
	x= X[0][0];
	y= X[1][0];
	z= X[2][0];
	switch(sistema){
		case 1:
			v[0][0] = func(1,1,0,x,y,z);
			v[1][0] = func(1,2,0,x,y,z);
			v[2][0] = 0;
			break;
		case 2:
			v[0][0] = func(2,1,0,x,y,z);
			v[1][0] = func(2,2,0,x,y,z);
			v[2][0] = 0;
			break;
		case 3:
			v[0][0] = func(3,1,0,x,y,z);
			v[1][0] = func(3,2,0,x,y,z);
			v[2][0] = func(3,3,0,x,y,z);
			break;
		case 4:
			v[0][0] = func(4,1,0,x,y,z);
			v[1][0] = func(4,2,0,x,y,z);
			v[2][0] = func(4,3,0,x,y,z);
			
			break;
		
	}
}

double norma(double v[5][5]){
	return sqrt(v[0][0]*v[0][0]+ v[1][0]*v[1][0]+ v[2][0]*v[2][0]);
}
void sistemas(){
	//cout<<"Sistemas.txt\t";
	/*
	double f1(double x,double y){return x*x+x*y-10;}
double f2(double x,double y){return y+3*x*y*y-50;}

double g1(double x,double y){return x*x+y*y-9;}
double g2(double x,double y){return -1*exp(x)-2*y-3;}

double h1(double x,double y,double z){return 2*x*x-4*x+y*y+3*z*z+6*z+2;}
double h2(double x,double y,double z){return x*x+y*y-2*y+2*z*z-5;}
double h3(double x,double y,double z){return 3*x*x-12*x+y*y-3*z*z+8;}

double i1(double x,double y,double z){return x*x-4*x+y*y;}
double i2(double x,double y,double z){return x*x-x-12*y+1;}
double i3(double x,double y,double z){return 3*x*x-12*x+y*y-3*z*z+8;}
	*/
	cout<<"\tSistema 1:\n";
	cout<<"f1(x,y,z) = \
	x*x+x*y-10 			\n";
	cout<<"f2(x,y,z) = \
	y+3*x*y*y-50		\n";
	
	cout<<"\tSistema 2:\n";
	cout<<"f1(x,y,z) = \
	x*x+y*y-9 			\n";
	cout<<"f2(x,y,z) = \
	-1*exp(x)-2*y-3		\n";
	
	cout<<"\tSistema 3:\n";
	cout<<"f1(x,y,z) = \
	2*x*x-4*x+y*y+3*z*z+6*z+2			\n";
	cout<<"f2(x,y,z) = \
	x*x+y*y-2*y+2*z*z-5		\n";
	cout<<"f3(x,y,z) = \
	3*x*x-12*x+y*y-3*z*z+8		\n";
	
	cout<<"\tSistema 4:\n";
	cout<<"f1(x,y,z) = \
	x*x-4*x+y*y			\n";
	cout<<"f2(x,y,z) = \
	x*x-x-12*y+1		\n";
	cout<<"f3(x,y,z) = \
	3*x*x-12*x+y*y-3*z*z+8		\n";
	
	
	
}
void newton(){
	int sistema,i=0,tama;
	double tolerancia;
	double x,y,z,X[5][5],J[5][5],F[5][5],R[5][5],C[5][5];
	limpiar(X);
	limpiar(J);
	limpiar(F);
	limpiar(R);
	limpiar(C);
	cout<<"Selecciona el sistema a solucionar: \n";
	sistemas();
	cin>>sistema;
	if(sistema == 1 or sistema == 2){
		tama = 2;
	}else{
		tama = 3;
	}
	//cout<<tama<<"\n";
	cout<<"Ingresa x inicial: ";
	cin>>x;
	cout<<"Ingresa y inicial: ";
	cin>>y;
	if(tama != 2){
	cout<<"Ingresa z inicial: ";
	cin>>z;
	}else{
		z = 0;
	}
	cout<<"Ingresa la tolerancia deceada: ";
	cin>>tolerancia;
	
	vincog(X,x,y,z);
	vfuncion(F,sistema,x,y,z);
	jaco(J,sistema,x,y,z);
	cout<<"\n\n";
	do{
		limpiar(R);
		//dejar en 0 R
		cout<<"\nIteracion: "<<i<<"\n";
		cout<<"\nX: \n";
		imprime(X,tama,1);
		cout<<"\nF(X): \n";
		imprime(F,tama,1);
		cout<<"\nJ(F(X)): \n";
		imprime(J,tama,tama);
		cout<<"\nError: "<<norma(F)<<"\n";
		//inversa(J,tama,R);
		inver(J,R,tama);
		//invertir J guardando en R
		limpiar(C);
		//dejar en 0 C
		resta(R,C,J,tama,tama);
		//pasar los valores de R a J, restandole 0
		limpiar(R);
		mmul(J,F,R,tama,tama,1);
		//multiplicar la inversa de la J, por F, se guarda en R, y sera de tamaño tamax1
		resta(X,R,X,tama,1);
		//a x se le resta r, y se guarda en x
		jaco(J,sistema,X);
		vfuncion(F,sistema,X);
		
		//getch();
		i++;
	}while(norma(F) > tolerancia);
		cout<<"\nIteracion: "<<i<<"\n";
		cout<<"\nX: \n";
		imprime(X,tama,1);
		cout<<"\nF(X): \n";
		imprime(F,tama,1);
		cout<<"\nJ(F(X)): \n";
		imprime(J,tama,tama);
		cout<<"\nError: "<<norma(F)<<"\n";
		cout<<"El vector solucion es:";
		cout<<"\nX: \n";
		imprime(X,tama,1);
}
int main(){
	newton();
	return 0;
}
