#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <limits.h>

#include "queue.h"

#define M 4
#define N 10

pthread_t t_enqueue[M];
pthread_t t_dequeue[N];

void
enqueue_runtime(int *value)
{
  enqueue(*value);
  printf("the value %d is enqueue\n", *value);
}

void
dequeue_runtime()
{
  int value = dequeue();
  if(value == INT_MIN)
  {
    printf("the queue is empty\n");
    return;
  }
  printf("the value %d was in foot\n", value);
  return;
}


int 
main()
{
  init_Q(M);
  int i = 0;
  while(i < M)
  {
    pthread_create(&t_enqueue[i], NULL, (void *) enqueue_runtime,(void *) &i);
    i++;
  }
  printf("dequeue\n");
  for(int j = 0; j < N; j++)
  {
    pthread_create(&t_dequeue[j], NULL, (void *) dequeue_runtime, NULL);
  }
  for(int i = 0; i < M; i++)
  {
    pthread_join(t_enqueue[i], NULL);
  }
  for(int i = 0; i < N; i++)
  {
    pthread_join(t_dequeue[i], NULL);
  }
  return 0;
}
