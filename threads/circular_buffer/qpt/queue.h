#ifndef QUEUE_H
#define QUEUE_H

struct queue;

int init_Q(int size);

int isempty();
int isfull();

void enqueue(int value);
int dequeue();

#endif
