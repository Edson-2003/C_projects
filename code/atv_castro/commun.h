#ifdef COMMUN_H
#define COMMUN_H

struct myclients;
struct client;



int conncet(int type);
struct client* new_client(int id, int address);
void add_client(struct myclients *clients, struct client *new);
void global();


#endif
