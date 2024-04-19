#include "client.h"
#include <string.h>

struct person
{
  int *age;
  char *name;
};

struct person* create(int *age, char *name)
{
  struct person *new;
  new = (struct person*) malloc(sizeof(struct person));
  new->age = age;
  new->name = (char *) malloc(strlen(name) * sizeof(char));
  strcpy(new->name, name);

  return new;
}
bool put(struct person *new);
void update(int age, char name[], struct person *update);
void delete(int age, char name[]);

