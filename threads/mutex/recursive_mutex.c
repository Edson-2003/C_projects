#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>



pthread_t deposita[4];
pthread_t retira[4];

int saldo = 0;
pthread_mutex_t mutex_saldo;

/** Faz 10 depositos de 20 reais a cada 1 segundo */
void codigo_tarefa_deposita(void)
{
	for( int ns=0; ns < 10; ++ns) 
  {
		sleep(1);
		printf("Vai depositar 20.00 reais\n");
		pthread_mutex_lock(&mutex_saldo);	
		saldo += 20;
		pthread_mutex_unlock(&mutex_saldo);	
		printf("Depositou 20.00 reais\n");
	}
}


/** Faz 10 retiradas de 20 reais a cada 1 segundo */
void codigo_tarefa_retira(void)
{
	double retirou;
	for( int ns=0; ns < 10; ++ns) 
  {
		sleep(1);
		printf("Vai tentar retirar 20.00 reais\n");
		pthread_mutex_lock(&mutex_saldo);
		if( saldo >= 20.0 )
			retirou = 20.0;
		else
			retirou = saldo;
		saldo -= retirou;
		pthread_mutex_unlock(&mutex_saldo);	
		printf("Retirou %0.2lf reais\n", retirou);
	}
}

int main()
{
  pthread_mutexattr_t mat;
  pthread_mutexattr_init(&mat);
  pthread_mutexattr_settype(&mat, PTHREAD_MUTEX_RECURSIVE);
  pthread_mutex_init(&mutex_saldo, &mat);
  for(int i = 0; i < 4; i++)
  {
    pthread_create(&retira[i], NULL, (void *) codigo_tarefa_retira, NULL);
    pthread_create(&deposita[i], NULL, (void *) codigo_tarefa_deposita, NULL);
  }
  for(int i = 0;i < 4; i++)
  {
    pthread_join(deposita[i], NULL);
    pthread_join(retira[i], NULL);
  }
  printf("Saldo final ficou %0.2lf\n", saldo);
  

  return 0;
}
