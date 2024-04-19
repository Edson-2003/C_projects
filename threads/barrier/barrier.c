/**		Rômulo Silva de Oliveira

		Programação Concorrente com Pthreads e Linguagem C

		s07-a35-tarefa.c
		
		Altere o programa s07-a34-variasbarreiras.c colocando um campo a mais na
		estrutura param_t, onde cada thread calculadora deverá depositar o maior
		valor que ela encontrou.

		Faça a thread que recebe PTHREAD_BARRIER_SERIAL_THREAD ao final dos cálculos
		comparar os valores obtidos por todas as threads e colocar o maior de todos
		na tela.
*/


#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>


// Número de tarefas calculadoras
#define	N_CALCULADORAS	8

// Número de elementos no vetor de dados
#define	N_ELEMENTOS		10000



// Usado para passar parâmetros na criação de threads
struct param_t {
	int id;		// Identificação da thread
	int inicio;	// Posição inicial a ser pesquisada
	int fim;	// Posição final a ser pesquisada
	double resultado;	// Maior valor encontrado
	};

struct param_t thparam[N_CALCULADORAS];


// Vetor com dados imaginários
static double *vetorDados;


// Identificadores das threads que calculam
static pthread_t th_calculadora[N_CALCULADORAS];	


// Barreira para sincronização
static pthread_barrier_t barreira_para_iniciar;
static pthread_barrier_t barreira_para_terminar;




/****************************************************
*		THREADS										*
*													*	
****************************************************/


/** Calcula o maior valor dentro de um segmento do vetorDados
*/
static void codigo_tarefa_calculadora( struct param_t *param) {
	double meumax = -DBL_MAX;
	int bret1, bret2;
	double todosmax = -DBL_MAX;
	
	printf("Thread %d\n", param->id);

	// Dorme por alguns segundos aleatórios
	sleep(1 + rand()%2); 

	bret1 = pthread_barrier_wait(&barreira_para_iniciar); 


	// Calcula
	for( int i=param->inicio; i<param->fim; ++i) {
		if( meumax < vetorDados[i] )
			if( meumax < vetorDados[i] )
				meumax = vetorDados[i];
	}

	// Dorme por alguns segundos aleatórios
	sleep(1 + rand()%2); 

	param->resultado = meumax;

	bret2 = pthread_barrier_wait(&barreira_para_terminar); 


	printf("Thread %d pesquisou de %d ateh %d, achou %lf, bret1 %d, bret2 %d\n",
		 param->id, param->inicio, param->fim-1, meumax, bret1, bret2);
		 
	if( bret2 == PTHREAD_BARRIER_SERIAL_THREAD ) {
		for( int i=0; i<N_CALCULADORAS; ++i)
			if( todosmax < thparam[i].resultado )
				todosmax = thparam[i].resultado;
		printf("Thread %d é especial !!! e o valor maior de todos é %lf\n", param->id, todosmax);
	}
	
}



/****************************************************
*		MAIN										*
*													*	
****************************************************/

/** Função principal, cria as threads */
int main(void){
	printf("Inicio\n");

	// Inicializa gerador de números aleatórios
	srand( time(NULL) );
	
	// Cria o vetor de dados
	vetorDados = (double *) calloc( N_ELEMENTOS, sizeof(double));
	if( vetorDados == NULL ) {
		printf("Falha na alocação de memória\n");
		exit(1);
	}
	for( int i=0; i<N_ELEMENTOS; ++i)
		vetorDados[i] = i;

	// Prepara os parâmetros para as threads
	for( int i=0; i<N_CALCULADORAS; ++i) {
		thparam[i].id = i;
		thparam[i].inicio = i * (N_ELEMENTOS/N_CALCULADORAS);
		thparam[i].fim = (i+1) * (N_ELEMENTOS/N_CALCULADORAS);
	}

	// Inicializa as barreiras
	pthread_barrier_init(&barreira_para_iniciar, NULL, N_CALCULADORAS);
	pthread_barrier_init(&barreira_para_terminar, NULL, N_CALCULADORAS);

	// Cria as threads que calculam
	for( int i=0; i<N_CALCULADORAS; ++i)
		pthread_create(&th_calculadora[i], NULL, (void *) codigo_tarefa_calculadora, (void *) &thparam[i]);

	// Espera por todas as threads que calculam
	for( int i=0; i<N_CALCULADORAS; ++i)
		pthread_join(th_calculadora[i], NULL);

	// Destroi as barreiras
	pthread_barrier_destroy(&barreira_para_iniciar);
	pthread_barrier_destroy(&barreira_para_terminar);

	printf("Fim\n");
	return(0);
}



