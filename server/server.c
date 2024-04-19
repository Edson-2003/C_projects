#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <pthread.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

#include "server.h"


static struct client
{
  int id;
  int fd;
  struct room *room;
  struct client *next;
  struct client *prev;
};

struct clients
{
  struct client *first;
};

struct room
{
  char name[50];
  int code;
  struct clients *users;
  struct room *prev;
  struct room *next;
};

static struct rooms
{
  struct room *first;
};








static struct server
{
  int fd;
  int port;
  int backlog;
  struct sockaddr_in *addr;

  struct clients *clients;
  struct rooms *rooms;
};


static pthread_mutex_t mt = PTHREAD_MUTEX_INITIALIZER;
static pthread_rwlock_t rw = PTHREAD_RWLOCK_INITIALIZER;


static struct server *server = NULL


static struct room*
search(int code)
{
  pthread_mutex_lock(&mt);
  pthread_mutex_unlock(&mt);
  pthread_rwlock_rdlock(&rw);

  struct room *temp = server->rooms->first;

  while((temp->code != code) && temp != NULL) temp = temp->next;

  if(temp->code == code) 
  {
    pthread_rwlock_unlock(&rw);
    return temp;
  }

  pthread_rwlock_unlock(&rw);
  return NULL;


}



void 
kill(int fd)
{
  shutdown(fd, SHUT_RDWR);
  close(fd);
  return;
}



int 
start(int port, int backlog)
{
  int s_sock;
  s_sock = socket(AF_INET, SOCK_STREAM, 0);


  //server address
  struct sockaddr_in s_address;
  s_address.sin_family = AF_INET;
  s_address.sin_port = htons(port);
  s_address.sin_addr.s_addr = INADDR_ANY;

  //bind
  bind(s_sock, (struct sockaddr*) &s_address, sizeof(s_address));
  listen(s_sock, backlog);
  
  struct server new;
  
  new.fd = s_sock;
  new.port = port;
  new.backlog = backlog;
  new.addr = &s_address;

  pthread_mutex_lock(&mt);
  pthread_rwlock_wrlock(&rw);
  pthread_mutex_unlock(&mt);
  
  if(server != NULL)
  {
    shutdown(s_sock, SHUT_RDWR);
    close(s_sock);
    pthread_rwlock_unlock(&rw);
    return -1;
  }

  server = &new;
  pthread_rwlock_unlock(&rw);
  return 0;
}


int
handle_conn()
{
  int fd;
  struct sockaddr_in *addr;
 
  pthread_mutex_lock(&mt);
  pthread_mutex_unlock(&mt);
  pthread_rwlock_rdlock(&rw);
  
  fd = server->fd;
  addr = &server->addr;

  pthread_rwlock_unlock(&rw);
  socklen_t len = sizeof(struct sockaddr);

  int new = accept(fd, (struct sockaddr *), addr, &len)
  if(new == -1)
  {
    return -1;  
  }

  return new;
}

int
prepare(int id, int fd)
{
  struct client *new;
  new = (struct client *) malloc(sizeof(struct client));
  if(new == -1)
  {
    return NULL;
  }

  new->id = id;
  new->fd = fd;
  new->next = new->prev = new->room = NULL;

  pthread_mutex_lock(&mt);
  pthread_rwlock_wrlock(&rw);
  pthread_mutex_unlock(&mt);
  
  new->next = server->clients->first;
  server->clients->first->prev = new;
  server->clients->first = new;

  pthread_rwlock_unlock(&rw);

  return new; 
}


int
listenme(int fd)
{
  char buffer[50];
  
  if(recv(fd, &buffer, 50 * sizeof(char), 0) == -1) return -1;
  int code = atoi(buffer);
  switch(code)
  {
    case 0:
      return CONNECT_R;
      break;
    case 1:
      return CREATE_R;
      break;
    case 2:
      return ROOMS_INFO;
      break;
    case 3:
      return QUIT_R;
      break;
    case 4:
      return QUIT_A;
      break;
  }

  return -1;
}


void
sendrooms(int fd)
{
  char buffer[50];
  buffer[0] = 0x06;

  send(fd, &buffer, sizeof(buffer), 0);
  
  pthread_mutex_lock(&mt);
  pthread_mutex_unlock(&mt);
  pthread_rwlock_rdlock(&rw);
  
  struct room *temp = server->rooms->first;
  while(temp != NULL)
  {
    send(fd, &temp->id, sizeof(int), 0);
    send(fd, &temp->name, 50 * sizeof(char), 0);
    temp = temp->next;
  } 
  :wq
  :wq
  :qw
  :q
  :q
  pthread_rwlock_unlock(&rw);
  buffer[0] = 0x00;
  send(fd, &buffer[0], sizeof(char), 0);
  return;
}



void
connect_room(struct client *me)
{
  char buffer[50] = 0x06;
  send(me->fd, &buffer, 50 * sizeof(char), 0);
  recv(me->fd, &buffer, 50 *sizeof(char), 0);
  
  int code = atoi(buffer);
  room = search(code);
  if(room != NULL)
  {
    pthread_mutex_lock(&mt);
    pthread_rwlock_wrlock(&rw);
    pthread_mutex_unlock(&mt);
    
    me->next = room->clients->first;
    room->clients->first->prev = me;
    room->clients->first = me;

    pthread_rwlock_unlock(&rw);
    buffer[0] = 0x06;
    send(me->fd, &buffer[0], sizeof(char), 0);
    return;
  }
}


void
create_room(struct client *me)
{

}



int
multicast(struct client *me, char *message)
{
  pthread_mutex_lock(&mt);
  pthread_mutex_unlock(&mt);
  pthread_rwlock_rdlock(&rw);
  
  int id = me->id;
  
  struct client *temp = me->room->users->first;
  
  while(temp->next != NULL)
  {
    
    if(temp->id != id)
    {
      send(temp->fd, message, sizeof(message), 0);
    }
  }
  
  pthread_rwlock_unlock(&rw);
}
