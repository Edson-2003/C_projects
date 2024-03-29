#include "commun.h"
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <pthread.h>

int
conect(int type)
{
  //create socket
  int s_sock;
  s_sock = socket(AF_INET, SOCK_STREAM, 0);


  //server address
  struct sockaddr_in s_address;
  s_address.sin_family = AF_INET;
  s_address.sin_port = htons(9002);
  s_address.sin_addr.s_addr = INADDR_ANY;
  if(type == 1)
  {
    //for the server
    //bind
    bind(s_sock, (struct sockaddr*) &s_address, sizeof(s_address));
    listen(s_sock, 5);
    
    return s_sock;
  }
  //for the client
  //conect socket
  int status;
  status = connect(s_sock, (struct sockaddr*) &s_address, sizeof(s_address));

  if(status == -1)
  {
    printf("error\n\n");
  }
  
  return s_sock;
}

struct client*
new_client(int id, int address)
{
  struct client *new;
  new = (struct client*) malloc(sizeof(struct client));
  new->id = id;
  new->address = address;

  return new;
}

void add_client()


