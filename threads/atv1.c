#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <ctype.h>

#define size 5


struct thread
{
  int id;
  char name;
  pthread_t thread;
};

struct thread thread[size];
int yes = 1;
int no = 0;

void
tarefa(int *id)
{
  for(int i = 0; i < 5; i++)
  {
    sleep(10);
    printf("TAREFA %d : Descansou por 10 seguntos, repeticao %d", id + 1, i);
    sleep(1);
  }

  if(isupper(thread[id].name))
  {
    pthread_exit(&yes);
  }

  pthread_exit(&no);
}




int
main()
{
  for(int i = 0; i < size; i++)
  {
    thread[i].id = i;
    printf("repetição %d", i);

    scanf(" %c", &thread[i].name);
  }

  printf("saiu do for");
  for(int i = 0; i < size; i++)
  {
    pthread_create(&thread[i].thread, NULL, (void *) tarefa,(void **) &thread[i].id);
  }

  for(int i = 0; i < size; i++)
  {
    int exit_status;
    pthread_join(thread[i].thread, (void **) &exit_status);
    printf("%d \n ", exit_status);
  }

  return 0;
}
