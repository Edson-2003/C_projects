#ifndef SERVER_H_
#define SERVER_H_


enum code
{
  CONNECT_R = 0,
  CREATE_R,
  ROOMS_INFO,
  QUIT_R,
  QUIT_A,
  IMHERE,
};






struct client;
struct clients;
struct room;


void kill(int fd);
int start(int port, int backlog);
int handle_conn();
struct client *prepare(int id, int fd);

int listenme(int fd);

void sendrooms(int fd);
void connect_room(struct client *me);
void create_room(struct client *me);
int multicast(struct client *me, char *message);






#endif
