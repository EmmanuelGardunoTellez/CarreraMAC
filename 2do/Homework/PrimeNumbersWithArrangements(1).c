#include <stdio.h>

void main() {
    int  PrimeNumbersToShow, Number, Divider, HeIsPrimeNumber, Cont; //Variables que se van a usar en el programa
	int primes[25]; //Arreglo de una dimension
	PrimeNumbersToShow=25; //Solo muestro los pimeros 25 numeros primos, que es del 1 al 100

    Number = 2;  //El numero por el qeu empieza a contar
    while (PrimeNumbersToShow> 0) { //Numeros qeu falta por encontrar

        HeIsPrimeNumber = 1;
        for (Divider = 2; Divider < Number; ++Divider) { //Contador para qeu divida cada numero
            if (Number % Divider == 0) { //Division
                HeIsPrimeNumber = 0; 
                break;
            }
        }

        if (HeIsPrimeNumber) { //Si el valor de "HeIsPrimeNumber" cambia a 0 no anota el numero, si es 1 lo anota en el arreglo
            primes[PrimeNumbersToShow-1]=Number; //Asigna el nuero si es primo
           PrimeNumbersToShow--; //Disminuye el nuemo de rpimos qeu faltan por encontar
        }
        Number++; //Aumenta los alsiguente numero
    }
    for(Cont=24;Cont>-1;Cont--){ //For para mostrar los primos
	printf("%i ",primes[Cont]); //Mostrar primos
}
}
