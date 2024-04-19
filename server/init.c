#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#include "server.h"



void
client_runtime(int *fd)
{
  struct client *me;
  me = prepare(*fd, id);
  if(me == NULL)
  {
    kill(*fd);
    return;
  }
  
  while(1)
  {
    int code;
    code = listenme(*fd);
    switch(code)
    {
      case ROOMS_INFO:
        sendrooms(*fd);
        break;
      case CONNECT_R:
        connect_room(me);
        break;
      case CREATE_R:
        create_room();
    }
  }
}





int main(int argc, char **argv)
{
  if(argc < 1)
  {
    return -1;
  }
  int port = atoi(argv[1]);
  int backlog = atoi(argv[2]);

  start(port, backlog);
  while(1)
  {
    int new = handle_conn();
    if(new != -1)
    {
      pthread_create();
    }
  }
  return 0;
}
