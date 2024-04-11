#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

struct node;
struct list;

int init_list();

struct node* reader(int value);
struct node* creator(int value);
void writer(struct node *node);
int deleter(struct node *node);






#endif
