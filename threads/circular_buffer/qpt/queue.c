#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <limits.h>

#include "queue.h"

struct queue
{
  int size;
  int head;
  int foot;
  int *queue;
};

static struct queue *myqueue = NULL;
static pthread_rwlock_t rw = PTHREAD_RWLOCK_INITIALIZER;
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;




int
init_Q(int size)
{

  pthread_mutex_lock(&mutex);
  pthread_rwlock_wrlock(&rw);
  pthread_mutex_unlock(&mutex);
  if(myqueue == NULL)
  {
    myqueue = (struct queue *) malloc(sizeof(struct queue));
    myqueue->queue = (int *) malloc(size * sizeof(int));
    if((myqueue == NULL) || myqueue->queue == NULL)
    {
      exit(EXIT_FAILURE);
    }
    myqueue->size = size;
    myqueue->foot = myqueue->head = -1;
    printf("%d, %d, %d\n", myqueue->size, myqueue->head, myqueue->foot);
    pthread_rwlock_unlock(&rw);
    return 0;
  }
  pthread_rwlock_unlock(&rw);
  return -1;
}

int
isempty()
{
  if(myqueue->size == 0)
  {
    return 1;
  }
  return 0;
}

int 
isfull()
{
  if(myqueue->size == myqueue->head)
  {
    printf("the queue is full\n");
    return 1;
  }
  return 0;
}

void
enqueue(int value)
{
  pthread_mutex_lock(&mutex);
  pthread_rwlock_wrlock(&rw);
  pthread_mutex_unlock(&mutex);
  if(isfull())
  {
    printf("the queue is full, the value %d is'nt enqueue\n", value);
    pthread_rwlock_unlock(&rw);
    return;
  }
  myqueue->head++;
  if(myqueue->head > myqueue->size)
  {
    if(myqueue->foot > 0)
    {
      myqueue->head = 0;
      myqueue->queue[myqueue->head] = value;
      pthread_rwlock_unlock(&rw);
      return;
    }
    pthread_rwlock_unlock(&rw);
    return;
  }
  myqueue->queue[myqueue->head] = value;
  pthread_rwlock_unlock(&rw);
  return;
}

int 
dequeue()
{
  pthread_mutex_lock(&mutex);
  pthread_rwlock_wrlock(&rw);
  pthread_mutex_unlock(&mutex);
  if(isempty())
  {
    pthread_rwlock_unlock(&rw);
    return INT_MIN;
  }
  myqueue->foot++;
  int value = myqueue->queue[myqueue->foot]; 
  pthread_rwlock_unlock(&rw);
  return value;
}
