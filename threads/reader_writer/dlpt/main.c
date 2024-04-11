#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


#include "double_linked_list.h"
#define N 10
#define M 3

pthread_t writer_t[M];
pthread_t reader_t[N];


void
read(int *value)
{
  struct node *node = reader(*value);
  if(node == NULL)
  {
    printf(" the value %d is not in list\n", *value);
    return;
  }
  printf("the value %d was found pointer: %x\n", *value, node);
}

void
write(int *value)
{
  writer(creator(*value));
  return;
}



int main()
{
  if(!init_list()) return 1;

  for(int i = 0; i < M; i++)
  {
    pthread_create(&writer_t[i], NULL, (void *) write, (void *) &i);
  }

  for(int i = 0; i < N; i++)
  {
    pthread_create(&reader_t[i], NULL, (void *) read, (void *) &i);
  }

  for(int i = 0; i < N; i++)
  {
    pthread_join(reader_t[i], NULL);
  }

  for(int i = 0; i < M; i++)
  {
    pthread_join(writer_t[i], NULL);
  }
  return 0;
}
