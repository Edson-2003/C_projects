#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <pthread.h>

#define MAX_CLIENTS 20

int table[MAX_CLIENTS / 2];

struct client
{
  int id;
  int socket;
  int status;
  int key;
};

pthread_t client[MAX_CLIENTS];
struct client clients[MAX_CLIENTS];


void
initialize_table()
{
  for(int i = 0; i < MAX_CLIENTS / 2, i++)
  {
    table[i] = 0;
  }
}

int
hashing(int key)
{
  return hash % 1000;
}


void
verify(struct client client)
{
  char menssage = 0b00000101;
  char response;
  send(client.socket, message, sizeof(message), 0);
  recv(client.socket, &response, sizeof(response), 0);
  if(response == 0b00000110)
  {
    return;
  }

}

void
routine(struct client client)
{ 
  srand(time(NULL));
  client.key = rand();
  while(table[hashing(key)] != 0)
  {
    client.key = rand();
  }

  table[hashing(client.key)] = client.id

  char response[255];
  send(client.socket, client.key, sizeof(client.key), 0)
  while(true)
  {
    recv(client.socket, &response, sizeof(response), 0);
    if()
    {
      
    }
  }
}





int 
main()
{
  initialize_table();

  //create socket
  int s_sock;
  s_sock = socket(AF_INET, SOCK_STREAM, 0);

  //server address
  struct sockaddr_in s_address;
  s_address.sin_family = AF_INET;
  s_address.sin_port = htons(9002);
  s_address.sin_addr.s_addr = INADDR_ANY;
  //bind
  bind(s_sock, (struct sockaddr*) &s_address, sizeof(s_address));

  listen(s_sock, 2);
  int client_coneccted = 0;
  
  while( client_coneccted < 10)
  {
    int c_sock;
    c_sock = accept(s_sock, NULL, NULL);
    if(c_sock < 0)
    {
      continue;
    }
    clients[client_coneccted].id = client_coneccted;
    clients[client_coneccted].socket = c_sock;
    clients[client_coneccted].status = c_sock;
    pthread_create(&thread[client_coneccted], NULL, (void *) routine,(void **) &clients[client_coneccted]);
    client_coneccted ++;
  }

  while()
  return 0;
}
