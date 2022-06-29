#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void burbuja(int *item, int cont) {
    int i, j, ordenado = 0;
    int temp;

    for (i = 1; i < cont; i++) {
        for (j = cont-1; j >= i; j--) {
            ordenado = 0;
            if (item[j-1] > item[j]) {
                temp = item[j-1];
                item[j-1] = item[j];
                item[j] = temp;
                ordenado++;
            }
        }

        /*cuando la variable ordenado sea igual a 0
          significara que el arreglo este ordenado
          y no sera necesario seguir recorriendo el
          arreglo para hacer comparaciones*/
        if (ordenado == 0)
        break;
    }
}

int main(int argc, char *argv[])
{
	
	int numeroElementos;
	int* vector;

	printf ("¿Cuántos elementos quieres? ");
	scanf ("%d", &numeroElementos);

	vector = (int*)malloc(numeroElementos*sizeof(int));
	if (vector==NULL)
	{
	printf("Problemas reservando memoria");
	return 1;
}
int i=0;
	for(i=0;i<numeroElementos;i++){
		vector[i] = rand();
	}

  clock_t t_ini, t_fin;
  double secs;
  t_ini = clock();
	

// trabajamos con el vector

// lo liberamos

burbuja(vector, numeroElementos);
  				
  				
  t_fin = clock();

  secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
  printf("%.16g milisegundos\n", secs * 1000.0);
  
  free (vector);
  return 0;
}
