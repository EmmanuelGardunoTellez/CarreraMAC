#include<iostream>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include <ctime>
#include <sys/time.h>

using namespace std;

void Burbuja();
void Insercion();
void Seleccion();	
//mezcla
void Mezcla();
void mSort(float *A,float tam);
void merge(float *izq,float nIzq,float *der,float nDer,float *A);
//mezcla

int main(){
	char opc1 = '^';
	 cout<<"      ***METODOS DE ORDENAMIENTO Y EFICIENCIA***\n\n\n";
	 do{

	cout<<"Seleccione el metodo de ordenamiento:  ";
	

	cout<<" \n\n         **OPCIONES**\n\n";
	
	
	cout<<"   1.- Burbuja\n";
	cout<<"   2.- Insercion\n";	
	cout<<"   3.- Seleccion\n";	
	cout<<"   4.- Merge Sort\n";	
	cout<<"   5.- Quick Sort \n";	
	cout<<"   6.- Heap Sort\n";	

    cin>>opc1;
    
      
    switch (opc1){
	
	case '1':  system("CLS");Burbuja(); break;
	case '2':  system("CLS");Insercion(); break;
	case '3':  system("CLS");Seleccion();break;
	case '4':  system("CLS");Mezcla();break;
	case '5':  system("CLS");break;
	case '6':  system("CLS");break;


    default: 	cout<<"    !!Opcion no valida!! \n  digite cualquier tecla para continuar";opc1 = '^';	getch(); break;
    
}//limpia pantalla
	}while(opc1 == '^');
	getch();
	return 0;
}



void Burbuja(){


char opc1 = '^';
long tam = 0;
	do{

	cout<<"De el numero de la opcion para tamaño del arregolo de numeros aleatoreos a ordenar: ";
	

	cout<<" \n\n         **OPCIONES**\n\n";
	
	
	cout<<"   1.- 100\n";
	cout<<"   2.- 500\n";	
	cout<<"   3.- 1,000\n";	
	cout<<"   4.- 5,000\n";	
	cout<<"   5.- 10,000\n";	
	cout<<"   6.- 50,000\n";	
	cout<<"   7.- 100,000\n";
	cout<<"   8.- 500,000\n";
	cout<<"   9.- 1,000,000\n";	
    cin>>opc1;
    
      
	 
    switch (opc1){
	
	case '1':   tam =  100;break;
	case '2':   tam =  500;break;
	case '3':   tam =  1000;break;
	case '4':   tam =  5000;break;
	case '5':   tam =  10000;break;
	case '6':   tam =  50000;break;
	case '7':   tam =  100000;break;
	case '8':   tam =  500000;break;
	case '9':   tam =  1000000;break;

    default: 	cout<<"    !!Opcion no valida!! \n  digite cualquier tecla para continuar";opc1 = '^';	getch(); break;
    	fflush;
}//limpia pantalla
system("CLS");	}while(opc1 == '^');

long vec[tam];
	
	
	long auxs = 0;
 
    srand(time(0));
    cout<<"generando numeros...\n";
 
    for(int i=0;i<tam;i++){
        auxs=(1+rand() % tam);
 
        int auxs2 = 0;
 
        while(auxs2 < i){
 
            if(auxs != vec[auxs2])
                auxs2++;
 
            else{
                    auxs = (1 + rand() % tam);
                    auxs2 = 0;
 
                }
        }
 
        vec[i] = auxs;
 
    
    }

system("CLS");


cout<<"se han generado los numeros aleatoreos sin repetir, precione cualquier tecla para continuar: ";
getch();
system("CLS");

cout<<"Se comienzara con el metodo de ordenamiento y el tiempo sera medido despues de precionar  una tecla: \n";
getch();
	 struct timeval ti, tf;
    double tiempo;
    gettimeofday(&ti, NULL);   // Instante inicial


long aux =0;

// metodo de ordenamiento

	for(int i=0;i<tam;i++){
		for(int j=0;j<tam;j++){
			if(vec[j]<vec[j+1]){
	        aux = vec[j];
	        vec[j]=vec[j+1];
	        vec[j+1]=aux;
			}
		}
      } 
	
	

 
    getchar();
    gettimeofday(&tf, NULL);   // Instante final
    tiempo= (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000.0;
    printf("Has tardado: %g milisegundos\n", tiempo);
    	getch(); 
	
}



void Insercion(){
	
char opc1 = '^';
long tam = 0;
	do{

	cout<<"De el numero de la opcion para tamaño del arregolo de numeros aleatoreos a ordenar: ";
	

	cout<<" \n\n         **OPCIONES**\n\n";
	
	
	cout<<"   1.- 100\n";
	cout<<"   2.- 500\n";	
	cout<<"   3.- 1,000\n";	
	cout<<"   4.- 5,000\n";	
	cout<<"   5.- 10,000\n";	
	cout<<"   6.- 50,000\n";	
	cout<<"   7.- 100,000\n";
	cout<<"   8.- 500,000\n";
	cout<<"   9.- 1,000,000\n";	
    cin>>opc1;
    
      
	 
    switch (opc1){
	
	case '1':   tam =  100;break;
	case '2':   tam =  500;break;
	case '3':   tam =  1000;break;
	case '4':   tam =  5000;break;
	case '5':   tam =  10000;break;
	case '6':   tam =  50000;break;
	case '7':   tam =  100000;break;
	case '8':   tam =  500000;break;
	case '9':   tam =  1000000;break;

    default: 	cout<<"    !!Opcion no valida!! \n  digite cualquier tecla para continuar";opc1 = '^';	getch(); break;
    	fflush;
}//limpia pantalla
system("CLS");	}while(opc1 == '^');

long vec[tam];
	
	
	long auxs = 0;
 
    srand(time(0));
    cout<<"generando numeros...\n";
 
    for(int i=0;i<tam;i++){
        auxs=(1+rand() % tam);
 
        int auxs2 = 0;
 
        while(auxs2 < i){
 
            if(auxs != vec[auxs2])
                auxs2++;
 
            else{
                    auxs = (1 + rand() % tam);
                    auxs2 = 0;
 
                }
        }
 
        vec[i] = auxs;
 
    
    }

system("CLS");


cout<<"se han generado los numeros aleatoreos sin repetir, precione cualquier tecla para continuar: ";
getch();
system("CLS");

cout<<"Se comienzara con el metodo de ordenamiento y el tiempo sera medido despues de precionar  una tecla: \n";
getch();
	 struct timeval ti, tf;
    double tiempo;
    gettimeofday(&ti, NULL);   // Instante inicial



//metodo de ordenamiento
long aux =0;
long pos =0;
	  for(int i=0;i<tam;i++){
    	pos = i;
    	aux = vec[i];
    	
    	while((pos>0)&&(vec[pos-1]<aux)){
    		vec[pos] = vec[pos-1];
    		pos--;
    		vec[pos] = aux;
    		
		}
    	
    }	

 
    getchar();
    gettimeofday(&tf, NULL);   // Instante final
    tiempo= (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000.0;
    printf("Has tardado: %g milisegundos\n", tiempo);
    	getch(); 
	
}


void Seleccion(){
	
char opc1 = '^';
long tam = 0;
	do{

	cout<<"De el numero de la opcion para tamaño del arregolo de numeros aleatoreos a ordenar: ";
	

	cout<<" \n\n         **OPCIONES**\n\n";
	
	
    cout<<"   1.- 100\n";
	cout<<"   2.- 500\n";	
	cout<<"   3.- 1,000\n";	
	cout<<"   4.- 5,000\n";	
	cout<<"   5.- 10,000\n";	
	cout<<"   6.- 50,000\n";	
	cout<<"   7.- 100,000\n";
	cout<<"   8.- 500,000\n";
	cout<<"   9.- 1,000,000\n";	
    cin>>opc1;
    
      
	 
    switch (opc1){
	
	case '1':   tam =  100;break;
	case '2':   tam =  500;break;
	case '3':   tam =  1000;break;
	case '4':   tam =  5000;break;
	case '5':   tam =  10000;break;
	case '6':   tam =  50000;break;
	case '7':   tam =  100000;break;
	case '8':   tam =  500000;break;
	case '9':   tam =  1000000;break;

    default: 	cout<<"    !!Opcion no valida!! \n  digite cualquier tecla para continuar";opc1 = '^';	getch(); break;
    	fflush;
}//limpia pantalla
system("CLS");	}while(opc1 == '^');

long vec[tam];
	
	
	long auxs = 0;
 
    srand(time(0));
    cout<<"generando numeros...\n";
 
    for(int i=0;i<tam;i++){
        auxs=(1+rand() % tam);
 
        int auxs2 = 0;
 
        while(auxs2 < i){
 
            if(auxs != vec[auxs2])
                auxs2++;
 
            else{
                    auxs = (1 + rand() % tam);
                    auxs2 = 0;
 
                }
        }
 
        vec[i] = auxs;
 
    
    }

system("CLS");


cout<<"se han generado los numeros aleatoreos sin repetir, precione cualquier tecla para continuar: ";
getch();
system("CLS");

cout<<"Se comienzara con el metodo de ordenamiento y el tiempo sera medido despues de precionar  una tecla: \n";
getch();
	 struct timeval ti, tf;
    double tiempo;
    gettimeofday(&ti, NULL);   // Instante inicial



//metodo de ordenamiento
long aux =0;
long pos =0;



 
    getchar();
    gettimeofday(&tf, NULL);   // Instante final
    tiempo= (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000.0;
    printf("Has tardado: %g milisegundos\n", tiempo);
    	getch(); 
	
}
//mezcla
//**********
//**********
//**********
//**********
//**********
void Mezcla(){
	
char opc1 = '^';
long tam = 0;
	do{

	cout<<"De el numero de la opcion para tamaño del arregolo de numeros aleatoreos a ordenar: ";
	

	cout<<" \n\n         **OPCIONES**\n\n";
	
	
	cout<<"   1.- 100\n";
	cout<<"   2.- 500\n";	
	cout<<"   3.- 1,000\n";	
	cout<<"   4.- 5,000\n";	
	cout<<"   5.- 10,000\n";	
	cout<<"   6.- 50,000\n";	
	cout<<"   7.- 100,000\n";
	cout<<"   8.- 500,000\n";
	cout<<"   9.- 1,000,000\n";	
    cin>>opc1;
    
      
	 
    switch (opc1){
	
	case '1':   tam =  100;break;
	case '2':   tam =  500;break;
	case '3':   tam =  1000;break;
	case '4':   tam =  5000;break;
	case '5':   tam =  10000;break;
	case '6':   tam =  50000;break;
	case '7':   tam =  100000;break;
	case '8':   tam =  500000;break;
	case '9':   tam =  1000000;break;

    default: 	cout<<"    !!Opcion no valida!! \n  digite cualquier tecla para continuar";opc1 = '^';	getch(); break;
    	fflush;
}//limpia pantalla
system("CLS");	}while(opc1 == '^');

long vec[tam];
	
	
	long auxs = 0;
 
    srand(time(0));
    cout<<"generando numeros...\n";
 
    for(int i=0;i<tam;i++){
        auxs=(1+rand() % tam);
 
        int auxs2 = 0;
 
        while(auxs2 < i){
 
            if(auxs != vec[auxs2])
                auxs2++;
 
            else{
                    auxs = (1 + rand() % tam);
                    auxs2 = 0;
 
                }
        }
 
        vec[i] = auxs;
 
    
    }

system("CLS");


cout<<"se han generado los numeros aleatoreos sin repetir, precione cualquier tecla para continuar: ";
getch();
system("CLS");

cout<<"Se comienzara con el metodo de ordenamiento y el tiempo sera medido despues de precionar  una tecla: \n";
getch();
	 struct timeval ti, tf;
    double tiempo;
    gettimeofday(&ti, NULL);   // Instante inicial
  
  tam = sizeof(vec) / sizeof(int);
 
 
 

}


//**********
//**********
//**********
//**********
//**********
//mezcla
