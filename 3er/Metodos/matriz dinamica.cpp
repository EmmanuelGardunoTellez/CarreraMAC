#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

int main(){
	

	double **matriz1, *matriz2, *xn1, *xn2, *rn, cont=0;
	int j,i,fila, columnas, iter;
	//tamaño de ma matriz
	cout<<"Dame el numero de filas y columas, de nxn:";
	cin>>fila;
	cout<<"maximo de iteracciones:";
	cin>>iter;
	
	matriz1 = new double*[fila];
	for(i=0; i<fila; i++){
		matriz1[i] = new double[fila];
	}
	
	matriz2 = new double[ fila];
	xn1 = new double[ fila];
	xn2 = new double[ fila];
	rn = new double[ fila];

	cout<<"Dijete elementos de la matriz\n\n";
	for(i=0; i<fila; i++){
		for(j=0; j<fila; j++){
			cout<<"Dame de la matriz 1 ["<<i+1<<"]["<<j+1<<"]: ";
			cin>>*(*(matriz1+i)+j);
		}
		cout<<"Dame el nuemro de resultados de la columna: ";
		cin >> *(matriz2+i);
		*(xn1+i) = 0;
		*(xn2+i) = 0;
		*(rn+i) = 0;
		cout<<"\n\n";
	}
	
	
	
	
  //imprime matriz
	cout<<"\n Imprimer matriz\n\n";
	for (i=0; i<fila ;i++){
		for(j=0; j<fila;j++){
			cout<<*(*(matriz1+i)+j)<<"\t";
		}
		cout<<"\t"<<*(matriz2+i);
		
		cout<<"\n";
	}
	
	
	
	//Comprobacion
	//Determinacion
	//diagonal superior
	
	
	
	//Metodo 
	cout<<"\n\n";
	//te da las x y r
	cout<<"inter"<<"\t"; 
	for(i=0;i<fila;i++){
		cout<<"x"<<i+1<<"\t"; 
	}
	for(i=0;i<fila;i++){
		cout<<"r"<<i+1<<"\t"; 
	}
		cout<<"\n";
		
		
	for(i=0;i<iter+1;i++){
		cout<<i<<"\t";
		double contador=0;
		for(j=0;j<fila;j++){
			*(xn1+i) = *(xn2+i);
			cout<<*(xn1+j)<<"\t";
		}
		
		for(j=0;j<fila;j++){
			if(i==j){
			contador= contador;	
			}else{
				contador += matriz1[i][j] * xn1[i];
				rn[j]= - xn1[j] + (1/matriz1[i][i])*(matriz2[i]-contador);
				contador=0;
			}
		}
		
		for(j=0;j<fila;j++){
			cout<< rn[j]<< "\t";
		}
		
		
		cout<<"\n";
	}
	
	
	//borrar memoria
	for(int i = 0;i<fila; i++){
		delete[] matriz1[i];
	}
	delete[] matriz1;
	delete[] matriz2;
	delete[] xn1;
	delete[] xn2;
	delete[] rn;
	getch();
	return 0;
}
