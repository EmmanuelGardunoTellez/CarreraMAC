#include <stdio.h>
#include <stdlib.h>

//Garduño Téllez Emmanuel
//Estructura de datos
//1304
//No. de Cuenta 316212249

typedef struct nodo{
	double dato;
	struct nodo *hi;
	struct nodo *hd;
}Nodo;

typedef struct arbol{
	Nodo * raiz;
}Arbol;

Arbol * inicializarArbol (){
	Arbol * arbol = (Arbol *) malloc (sizeof(Arbol));
	arbol->raiz = NULL;
	return arbol;
}

Nodo * crearNodo (double x){
	Nodo * nodo = (Nodo *) malloc (sizeof(Nodo));
	nodo-> dato = x;
	nodo->hi= NULL;
	nodo->hd = NULL;
	return nodo;
}

Nodo * insertar( Nodo * raiz , double x){
	if(raiz ==  NULL){
		raiz = crearNodo(x);
	} else if(x< raiz->dato ){
		raiz->hi = insertar(raiz->hi, x);
	} else if(x > raiz->dato){
		raiz->hd = insertar(raiz->hd, x);
	}
	return raiz;
}

void insertar_en_el_arbol(Arbol * arbol, double x){
	arbol->raiz = insertar(arbol->raiz, x);
}

void preorden(Nodo * raiz){
	if(raiz != NULL){
		printf("%.2lf ", raiz->dato);
		preorden(raiz->hi);
		preorden(raiz->hd);
	}
}
void preorden_arbol(Arbol * arbol){
	preorden(arbol->raiz);
}

void inorden(Nodo * raiz){
	if(raiz != NULL){
		inorden(raiz->hi);
		printf("%.2lf ", raiz->dato);
		inorden(raiz->hd);
	}
}
void inorden_arbol(Arbol * arbol){
	inorden(arbol->raiz);
}

void posorden(Nodo * raiz){
	if(raiz != NULL){
		posorden(raiz->hi);
		posorden(raiz->hd);
		printf("%.2lf ", raiz->dato);
	}
}
void posorden_arbol(Arbol * arbol){
	posorden(arbol->raiz);
}

Nodo * valorMenor(Nodo * raiz){
	if(raiz ==NULL) return raiz;
	else if(raiz->hi == NULL) return raiz;
	else return valorMenor(raiz->hi);
}
Nodo * borrar(Nodo * raiz, double x);
Nodo * borrar_nodo (Nodo * raiz){
	Nodo * temp;
	//Caso 1
	if((raiz->hi == NULL) && (raiz->hd ==NULL)){
		free(raiz);
		return NULL;
	}
	//Caso 2
	else if((raiz->hi == NULL) && (raiz->hd !=NULL)){
		temp = raiz->hd;
		free(raiz);
		return temp;
	}
	else if((raiz->hi != NULL) && (raiz->hd ==NULL)){
		temp = raiz->hi;
		free(raiz);
		return temp;
	}
	//Caso 3
	else {
		Nodo * sucesor = valorMenor(raiz->hd);
		double valorSucesor = sucesor->dato;
		
		raiz = borrar(raiz, valorSucesor);
		raiz->dato = valorSucesor;
		return raiz;
	}
	
}

Nodo * borrar(Nodo * raiz, double x){
	if(raiz == NULL) return NULL;
	if(x == raiz->dato) raiz = borrar_nodo(raiz);
	if(x < raiz->dato) raiz->hi = borrar(raiz->hi, x);
	else raiz->hd = borrar(raiz->hd, x);
	return raiz;
	
}

void borrar_en_arbol(Arbol * arbol, double x){
	arbol->raiz = borrar (arbol->raiz, x);
}

int main(int argc, char *argv[]) {
	
	Arbol * arbol = inicializarArbol();
	insertar_en_el_arbol(arbol, 6.0);
	insertar_en_el_arbol(arbol, 1.0);
	insertar_en_el_arbol(arbol, 2.0);
	insertar_en_el_arbol(arbol, 4.0);
	insertar_en_el_arbol(arbol, 3.0);
	insertar_en_el_arbol(arbol, 7.0);
	insertar_en_el_arbol(arbol, -5.8);
	
	printf("\nrecorrido en preorden: \n");
	preorden_arbol(arbol);
	
	printf("\nrecorrido en inorden: \n");
	inorden_arbol(arbol);
	
	printf("\nrecorrido en posorden: \n");
	posorden_arbol(arbol);
	
	borrar_en_arbol( arbol, 1.0);
	
	printf("\nrecorrido en preorden: \n");
	preorden_arbol(arbol);
	
	printf("\nrecorrido en inorden: \n");
	inorden_arbol(arbol);
	
	printf("\nrecorrido en posorden: \n");
	posorden_arbol(arbol);
	
	printf("\n");

	return 0;
}
