#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//Argumentos pasados al hilo
struct thrd_data{
  long id;
  long start;
  long end; /* el subrango es de principio a fin */
};
typedef struct {
  pthread_mutex_t     count_lock;     /* semaforo para seccion critica */
  pthread_cond_t      ok_to_proceed;  /* variable para parar seccion critica */
  long                count;      /* contador de hilos generados */
} mylib_barrier_t;

//variables globales
bool *GlobalList;//lsta de 0 a n
long Num_Threads;
mylib_barrier_t barrier;/* barrera de seccion critica */

void mylib_barrier_init(mylib_barrier_t *b){//semaforo para la seccion critica iniciador
  b -> count = 0;
  pthread_mutex_init(&(b -> count_lock), NULL);
  pthread_cond_init(&(b -> ok_to_proceed), NULL);
}

void mylib_barrier(mylib_barrier_t *b, long id){//barrera para seccion critica continuar
   pthread_mutex_lock(&(b -> count_lock));
   b -> count ++;
   if (b -> count == Num_Threads)
   {
     b -> count = 0; /* restableserse para futura continuacion */
     pthread_cond_broadcast(&(b -> ok_to_proceed));
   }
   else
   {
    while (pthread_cond_wait(&(b -> ok_to_proceed), &(b -> count_lock)) !=    0);

    }
    pthread_mutex_unlock(&(b -> count_lock));
}

void mylib_barrier_destroy(mylib_barrier_t *b) 
{
  pthread_mutex_destroy(&(b -> count_lock));
  pthread_cond_destroy(&(b -> ok_to_proceed));
}

void *DoSieve(void *thrd_arg)
{

  struct thrd_data *t_data;
  long i,start, end;
  long k=2;//Primer numero primo 
  long myid;

  /* Inicializar mi parte de la matriz global */
  t_data = (struct thrd_data *) thrd_arg;
  myid = t_data->id;
  start = t_data->start;
  end = t_data->end;

  printf ("Subproceso %ld haceindo busqueda %ld a %ld\n", myid,start,end);
  //Primer bucle: encuentra todos los números primos que son menores que sqrt(n)
  while (k*k<=end) 
  {
      int flag;
      if(k*k>=start)
        flag=0;
      else
        flag=1;
      //Segundo bucle: marcar todos los múltiplos del número primo actual
      for (i = !flag? k*k-1:start+k-start%k-1; i <= end; i += k)
        GlobalList[i] = 1;
      i=k;
      // esperar a que otros subprocesos terminen el segundo bucle para el número primo actual
      mylib_barrier(&barrier,myid);
      //busca el próximo número primo que sea mayor que el actual
      while (GlobalList[i] == 1)
            i++;
         k = i+1;

   }
  //disminuye el contador de hilos antes de salir
  pthread_mutex_lock (&barrier.count_lock);
  Num_Threads--;
  if (barrier.count == Num_Threads)
  {
    barrier.count = 0;  /* debe restablecerse para su futura reutilización */
    pthread_cond_broadcast(&(barrier.ok_to_proceed));
  }
  pthread_mutex_unlock (&barrier.count_lock);
  pthread_exit(NULL);
}


int main(int argc, char *argv[])
{
  long i, n,n_threads;
  long k, nq, nr;
  FILE *results;
  struct thrd_data *t_arg;
  pthread_t *thread_id;
  pthread_attr_t attr;

	/* Configuración de Pthreads: inicializa la barrera y crea explícitamente
    subprocesos en un estado unible (para portabilidad) */
  mylib_barrier_init(&barrier);
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

  /* pide ingresar n y n_threads del usuario */
  printf ("rango de n = ");
  scanf ("%ld", &n);
  printf ("numero de threads n_threads = ");
  scanf ("%ld", &n_threads);
  time_t start = time(0);// establecer la hora inicial
  //Inicializar lista global
  GlobalList=(bool *)malloc(sizeof(bool)*n);
  for(i=0;i<n;i++)
    GlobalList[i]=0;
  /* crear matrices de identificadores de subprocesos y argumentos de subprocesos */
  thread_id = (pthread_t *)malloc(sizeof(pthread_t)*n_threads);
  t_arg = (struct thrd_data *)malloc(sizeof(struct thrd_data)*n_threads);

  /* distribuir la carga y crear subprocesos para el cálculo */
  nq = n / n_threads;
  nr = n % n_threads;

  k = 1;
  Num_Threads=n_threads;
  for (i=0; i<n_threads; i++){
    t_arg[i].id = i;
    t_arg[i].start = k;
    if (i < nr)
        k = k + nq + 1;
    else
        k = k + nq;
    t_arg[i].end = k-1;
    pthread_create(&thread_id[i], &attr, DoSieve, (void *) &t_arg[i]);
  }

  /* Espere a que se completen todos los subprocesos y luego imprima todos los números primos */
  for (i=0; i<n_threads; i++) {
    pthread_join(thread_id[i], NULL);
  }
  int j=1;
  //Obtenga el tiempo dedicado a los trabajos de cálculo por todos los subprocesos participantesds
  time_t stop = time(0);
  printf("Tiempo para hacer todo menos imprimir = %lu seconds\n", (unsigned   long)    (stop-start));
  //imprime el resultado de los numeros primos
  printf("Los números primos se enumeran a continuación:\n");
  for (i = 1; i < n; i++){
    if (GlobalList[i] == 0)
    {
        printf("%ld ", i + 1);
        j++;
    }
    if (j% 15 == 0)
        printf("\n");
  }
  //printf("\n");
  // Clean up and exit 
  //free(GlobalList);
  //pthread_attr_destroy(&attr);
  //mylib_barrier_destroy(&barrier); // destroy barrier object
  //pthread_exit (NULL);
}
