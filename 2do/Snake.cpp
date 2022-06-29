
#include<windows.h>
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80
#define ESC 27

int cuerpo[200][2]; //En una linea almacena x, y en otra y
void imprimir();

int n=1;
int tam=2; //Tamaño inicial
int dir =3; //Hacia a donde va

int x=1; //Donde inicia la serpiente
int y=1; 

int comidax =30;//Primera comida pocisicon
int comiday =15;
char tecla; //variable golbal
void marcador();

void gotoxy (int x, int y){ //Funcion creada a partir de gotox que se ve en otros legunajes de porgramacion
	HANDLE hCon;
	COORD dwPos;
	
	dwPos.X = x;
	dwPos.Y = y;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon,dwPos);
}


void guardar_posicion(){//Guarda el cuerpo de la serpiente en una matriz
	cuerpo[n][0]=x;
	cuerpo[n][1]=y;
	n++;
	
	if(n == tam)//Si mede 1 la serpiente, se le agrega un 1 en automatico
	n=1;
}



void dibujar_cuerpo(){ //Crea el cuerpo de la serpiente, soloo que con un cuadro blanco
	for(int i =1; i<tam; i++){
		gotoxy(cuerpo[i][0], cuerpo[i][1]); //La dibura a partir de gotoxy agregado
		printf("%c",219);
		
	}
}



void teclear(){ //Permite teclear la direccion, y con el menu te ayuda a poner una direccion, prohibiendo el hacerlo a sentido contrario
	if(kbhit()){
		tecla = getch();
		switch(tecla){
			case ARRIBA : if(dir !=2) dir=1; break;
			case ABAJO : if(dir !=1) dir=2; break;
			case DERECHA : if(dir !=4) dir=3; break;
			case IZQUIERDA : if(dir !=3) dir=4; break;
		}
	}
}

void comida(){
	if(x == comidax && y == comiday){
		comidax= rand()%49; //Numeros ramdom
		comiday= rand()%49;
		
		if(comidax==0)
		comidax++;
		if(comiday==0)
		comiday++;
		
		tam++;
		gotoxy(comidax, comiday);
		printf("%c", 4);
		
		marcador();
	}
}

void borrar_cuerpo(){
	gotoxy(cuerpo[n][0], cuerpo[n][1]);
	printf("-");
	comida();
}

bool game_over(){ //Solo si choca contra si misma significa que pierdes.
for(int j= tam -1; j>0; j--){
	if(cuerpo[j][0] == x && cuerpo[j][1] == y)
	return false;
}
return true;
}



int main(){
	
	imprimir(); //Imprime el campo de juego
	
	 gotoxy(comidax, comiday); //Da las comidas en cierta psosicion
	 printf("%c",4);
	 
		while(tecla!= ESC && game_over()){
			borrar_cuerpo();
			guardar_posicion();
			dibujar_cuerpo();
			comida();
			teclear();
			teclear();
			
					
			if(dir == 1){ //Permite avanzar hacia da direccion, y si llega al limite del campo, lo manda al punto inical de el
				y--;
				if(y==0)
				y=49;	
			}


			if(dir == 2){//Permite avanzar hacia da direccion, y si llega al limite del campo, lo manda al punto inical de el
				y++;
				if(y == 50)
				y=1;
			}

			if(dir == 3){//Permite avanzar hacia da direccion, y si llega al limite del campo, lo manda al punto inical de el
				x++;
				if(x == 50)
				x=1;
			}


			if(dir == 4){//Permite avanzar hacia da direccion, y si llega al limite del campo, lo manda al punto inical de el
				x--;
				if(x == 0)
				x=49;
			}

			Sleep(50);
		}
		
		//Aqui se acaba el juego
		system("cls");
		gotoxy(25, 25);
		printf("Game Over");
				
	return 0;
}

void imprimir(){//Campo de juego
	for(int i=1;i<50;i++){
		for(int j=1;j<50;j++){
			gotoxy(i,j);
			printf("-");
		}
	}
}


void marcador(){
	int pum=tam;
	pum=pum-2;
	gotoxy(60,5);
	printf("Puntaje %i",pum);
}
