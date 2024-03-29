#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <pthread.h>

struct client()
{
  int id;
  int address;
}

struct myclients
{
  int max;
  int top;
  struct client *clients;
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

void add_client(struct myclients *clients, struct client *new)
{
  clients->clients[top] = new;
  top++
}

int start(int address)
{
  char buffer = 5;
  send(address, &buffer, sizeof(buffer), 0);
  reciv(address, &buffer, sizeof(buffer), 0)
  if(buffer == 6)
  {
    return 1;
  }
  return 0;
}

void send_products(int address)
{
  FILE *fp;
  char file = "products.csv"
  fp = fopen(file, "r");
  //printf("Content-type: text/html");  
  if(start(address))
  {
    char buffer;
    while((buffer = fgetc(fp)) != EOF )
    {
      if(buffer == ";")
      {
        buffer = "\t"
        send(address, buffer, sizeof(buffer),0);
        buffer = 31;
        while(!start(address))
        {}
      }
      //buffer = fgetc(fp);
      send(address, buffer, sizeof(buffer),0);
      //printf("%c" , buffer);
      while(!start(address))
      {}
    }
  }
  fclose(fp);
  return;
}


void routine(struct client *client)
{
  while(true)
  {
    int buffer = 8;
    recv(client->address, &buffer, sizeof(buffer), 0);
    switch (buffer)
    {
    case 1:
      insert_category();
      break;
    case 2:
      insert_product();
      break;
    case 3:
      update_category();
      break;
    case 4:
      update_product();
      break;
    case 5:
      delet_category();
      break;
    case 6:
      delet_products();
      break;
    case 7:
      send_products(client->address);
      break;
    case 8:
      return;
      break;
  default:
    }
  }
}



void routine_creator(pthread_t *thread, struct client *client)
{
  pthread_create(&thread, NULL, (void *) routine, client);
}

void global(struct myclients *clients)
{
  while(true)
  {
    int new;
    new = accept(s_sock, NULL, NULL);
    add_client(clients, new_client(clients->top, new));
    routine(&threads[clients->top - 1], clients->clients[clients->top - 1]);    
  }
}


