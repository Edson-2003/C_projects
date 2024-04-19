#ifndef CLIENT_H
#define CLIENT_H
#include <stdbool.h>

struct person;

struct person* create(int age, char name[]);
bool put(struct person *new);
void update(int age, char name[], struct person *update);
void delete(int age, char name[]);

#endif
