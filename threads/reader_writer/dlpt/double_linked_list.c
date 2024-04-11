#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
//#include <errorno.h>


#include "double_linked_list.h"


struct node
{
  int value;
  struct node *next;
  struct node *prev;
};


struct list
{
  struct node *head;
};

// linked_list 
static struct list *list = NULL;

//mutex for lock readers
static pthread_mutex_t reader_lock = PTHREAD_MUTEX_INITIALIZER;

//rw mutex
static pthread_rwlock_t rw_mutex = PTHREAD_RWLOCK_INITIALIZER;

int 
init_list()
{
  pthread_mutex_lock(&reader_lock);
  pthread_rwlock_wrlock(&rw_mutex);
  pthread_mutex_unlock(&reader_lock);
  if(list == NULL)
  {
    list = (struct list *) malloc(sizeof(struct list));
    list->head = NULL;
    pthread_rwlock_unlock(&rw_mutex);
    return 1;
  }
  pthread_rwlock_unlock(&rw_mutex);
  return 0;
}

struct node*
reader(int value)
{
  pthread_mutex_lock(&reader_lock);
  pthread_mutex_unlock(&reader_lock);
  pthread_rwlock_wrlock(&rw_mutex);
  if(list->head == NULL)
  {
    pthread_rwlock_unlock(&rw_mutex);
    return NULL;
  }
  if(list->head->value == value)
  {
    struct node *temp = list->head;
    pthread_rwlock_unlock(&rw_mutex);
    return temp;
  }
  
  struct node *temp;
  temp = list->head;
  while(temp->next != NULL) 
  {
    if(temp->value == value)
    {
      pthread_rwlock_unlock(&rw_mutex);
      return temp;
    }
    temp = temp->next;
  }
  if(temp->value == value)
  {
    pthread_rwlock_unlock(&rw_mutex);
    return temp;
  }

  pthread_rwlock_unlock(&rw_mutex);
  return NULL;
}

struct node*
creator(int value)
{
  struct node *new;
  new = (struct node *) malloc(sizeof(struct node));
  if(new == NULL)
  {
    printf("error alocation");
    exit(EXIT_FAILURE);
  }
  new->value = value;
  new->next = new->prev = NULL;
  return new;
}

void
writer(struct node* node)
{
  pthread_mutex_lock(&reader_lock);
  pthread_rwlock_wrlock(&rw_mutex);
  pthread_mutex_unlock(&reader_lock);
  if(list->head == NULL)
  {
    list->head = node;
    pthread_rwlock_unlock(&rw_mutex);
    return;
  }
 
  node->next = list->head;
  list->head->prev = node;
  list->head = node;
  pthread_rwlock_unlock(&rw_mutex);
  return;
}

int
deleter(struct node* node)
{
  if(node == NULL) return -1;
  
  pthread_mutex_lock(&reader_lock);
  pthread_rwlock_wrlock(&rw_mutex);
  pthread_mutex_unlock(&reader_lock);
  
  if(node->next == NULL) 
  {
    node->prev->next == NULL;
    free(node);
    pthread_rwlock_unlock(&rw_mutex);
    return 0;
  }
  if(node->prev == NULL)
  {
    list->head = node->next;
    node->next->prev = NULL;
    free(node);
    pthread_rwlock_unlock(&rw_mutex);
    return 0;
  }

  node->next->prev = node->prev;
  node->prev->next = node->next;
  free(node);
  pthread_rwlock_unlock(&rw_mutex);
  return 0;
}


