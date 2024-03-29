#ifdef SERVER_H
#define SERVER_H

struct myclients;
struct client;

struct client* new_client(int id, int address);
void add_client(struct myclients *clients, struct client *new);
int start(int address);
void send_products(int address);

void routine(struct client client);
void routine_creator(pthread_t thread, struct client *client);
void global(struct myclients *clients);


#endif

