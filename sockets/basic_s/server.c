#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <stdbool.h>
#include <unistd.h>
#include <stdarg.h>
#include <pthread.h>
#include <limits.h>

#define max_client 10
#define max_backlog 5

struct clients
{
  int address;
  int id;
  bool isOnline;
  pthread_t client;
}

struct Queue
{
  int front, rear, size;
  unsigned capacity;
  int* array;
};
 
struct server
{
  struct clients *clients;
  struct Queue *avaliable_to_connect;
  int address;
  int backlog;
  pthread_mutex_t mutex;
};

void 
error(char *error)
{
  perror(error);
  exit(1);
}

// function to create a queue
// of given capacity.
// It initializes size of queue as 0
struct Queue* 
create_q(unsigned capacity)
{
  struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
  queue->capacity = capacity;
  queue->front = queue->size = 0;
 
  // This is important, see the enqueue
  queue->rear = capacity - 1;
  queue->array = (int*)malloc(queue->capacity * sizeof(int));
  return queue;
}
 
// Queue is full when size becomes
// equal to the capacity
int isFull(struct Queue* queue)
{
  return (queue->size == queue->capacity);
}
 
// Queue is empty when size is 0
int isEmpty(struct Queue* queue)
{
  return (queue->size == 0);
}
 
// Function to add an item to the queue.
// It changes rear and size
void enqueue(struct Queue* queue, int item)
{
  if (isFull(queue))
    return;
  queue->rear = (queue->rear + 1) % queue->capacity;
  queue->array[queue->rear] = item;
  queue->size = queue->size + 1;
  //printf("%d enqueued to queue\n", item);
}
 
// Function to remove an item from queue.
// It changes front and size
int dequeue(struct Queue* queue)
{
  if (isEmpty(queue))
    return INT_MIN;
  int item = queue->array[queue->front];
  queue->front = (queue->front + 1) % queue->capacity;
  queue->size = queue->size - 1;
  return item;
}
 
// Function to get front of queue
int front(struct Queue* queue)
{
  if (isEmpty(queue))
    return INT_MIN;
  return queue->array[queue->front];
}
 
// Function to get rear of queue
int rear(struct Queue* queue)
{
  if (isEmpty(queue))
    return INT_MIN;
  return queue->array[queue->rear];
}
 
int
start_s(int backlog)
{
  int s_sock;
  s_sock = socket(AF_INET, SOCK_STREAM, 0);


  //server address
  struct sockaddr_in s_address;
  s_address.sin_family = AF_INET;
  
  s_address.sin_port = htons(9002);
  s_address.sin_addr.s_addr = INADDR_ANY;

  //bind
  bind(s_sock, (struct sockaddr*) &s_address, sizeof(s_address));

  listen(s_sock, 5);
  return s_sock;
};

struct server*
create_s(int size)
{
  struct server *new;
  new = (struct server *) malloc(sizeof(struct server));
  new->clients = (struct clients *) malloc(size * sizeof(struct client));
  for(int i = 0; i < max_client; i++)
    new->clients[i]->isOnline = false;
  new->avaliable_to_connect = creaute_q(size);
  new->backlog = max_backlog;
  new->address = start_s(backlog);
  new->mutex = PTHREAD_MUTEX_INITIALIZER;
}

int
register_new_client(struct server *this, int address)
{
  if(isEmpty(this->avaliable_to_connect))
  {
    sleep(1);
    return register_new_client(this, address);
  }
  
  pthread_mutex_lock(&this->mutex);
  id = dequeue(this->avaliable_to_connect);
  pthread_mutex_unlock(&this->mutex);
  
  this->clients[id]->address = address;
  this->clients[id]->id = id;
  this->clients[id]->isonline = true;
  return id;
}
int
handle_c(struct server *this, int address)
{
  return register_new_client(this, address);
}

void
init_c(struct server *this)
{
  thin->address = start_s(this->backlog);
  for(int i = 0; i < max_client, i++)
  {
    enqueue(this->avaliable_to_connect, i);
  };
}

void
brodcast(int id, char *buffer)
{
  printf("[%d] %s", id, buffer);
  for(int i = 0; i < max_client, i++)
  {
    if((i != id) && (server->clients[id]->isOnline))
      send(server->clients[i]->address, &buffer, sizeof(buffer), 0);
  }
}

char*
format( char* fmt, ...)
{
  char *buffer;     // this should really be sized appropriately
                       // possibly in response to a call to vsnprintf()
  va_list vl;
  va_start(vl, fmt);
  vsnprintf(buffer, sizeof( buffer), fmt, vl);
  va_end( vl);
  
  return buffer;
}


void
client_routine(int *id)
{
  char buffer[256] = "connected";
  send(server->clients[id]->address, &buffer, sizeof(buffer),0); 
  while(true)
  {
    recv(server->clients[id]->address, buffer, sizeof(buffer), 0);
    if(buffer != ":q")
    {
      brodcast(id, &buffer);
      continue;
    }
    printf("[%d] has disconnected");
    buffer = format("the %d client is disconnected", id);
    brodcast(id, buffer);
    free(buffer);
    server->clients[id]->isOnline = false;
    pthread_mutex_lock(&server->mutex);
    enqueue(server->avaliable_to_connect, id);
    pthread_mutex_unlock(server->mutex);
    close(server->clients[id]->address);
    break;
  }
}



void
server_routine()
{
  server = create_s();
  init_c(server);
  printf("the server started, waiting for new connections");
  while(true)
  {
    id = handle_c(accept(server->address);
    pthread_create(&server->clients[id], NULL, (void *) client_routine, (void **) &id); 
  }
}

struct server *server;


int
main()
{
  
}
