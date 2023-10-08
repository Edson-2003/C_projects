#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int value;
	struct node *next;
}Node;

typedef struct
{
	Node *start;
	int size;
}List;

void insert_node(List *l, int n)
{
	Node *new = (Node*)malloc(sizeof(Node));
	new->value = n;
	new->next = l->start;
	l->start = new; 
	l->size++;

}

void insert_on_end(Node *node, int n)
{
	if(node->next != NULL)
	{
		insert_on_end(node->next, n);
	}
	else
	{
		Node *new = (Node*) malloc(sizeof(Node));
		new->value = n;
		new->next = NULL;
	 	node->next = &new;	
	}
}




void print_list(List *l)
{
	Node *start = l->start;
	while(start != NULL)
	{
		printf("%d ", start->value);
		start = start->next;
	}
	printf("\n\n");
}



void main()
{
	List *l;
	int option, value;
	l = (List*) malloc(sizeof(List));
	l->start = NULL;
	l->size = 0;
	scanf("%d", &value);
	
	insert_node(l,value);
	insert_node(l,value);
	insert_node(l,value);
	print_list(l);
}
