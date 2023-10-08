#include <stdio.h>
#include <stdlib.h>

typedef srtuct node{
	int value;
	struct node *next
}Node;

typedef struct{
	Node *start;
	int size;
}List;

void insert_on_k(Node *node, int k, Node *x)
{
	if(k == 1)
	{
		x->next = node->next;
		node->next = 
	}
}




void main()
{
	
}

