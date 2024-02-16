#include <stdio.h>
#include <stdlib.h>

struct node
{
	int value;
	struct node *next;
};

struct list
{
	struct node *head;	
};

int
isempty(struct list *mylist)
{
	return mylist->head == NULL ? 1 : 0;
}

struct list*
createlist()
{
	struct list *mylist = (struct list*) malloc(sizeof(struct list));
	mylist->head = NULL;
	return mylist;
}

struct node*
createnode(int value)
{
	struct node *mynode = NULL;
	mynode = (struct node*) malloc(sizeof(struct node));
	mynode->value = value;
	mynode->next = NULL;
	
	return mynode;
}

void
insertnode(struct list *mylist, int value)
{
	if(isempty(mylist))
	{
		mylist->head = createnode(value);
	}
	else
	{
		struct node *temp =  mylist->head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		
		temp->next = createnode(value);
	}
}

void
show(struct list *mylist)
{
	if(isempty(mylist))
	{
		printf("your list is empty !");
	}
	else
	{
		printf("showing list elements\n");
		struct node *temp = mylist->head;
		while(temp != NULL)
		{
			printf("%d\n", temp->value);
			temp = temp->next;
		}
	}
}

int 
main()
{
	int i = 1;
	struct list *mylist = NULL;
	mylist = createlist();
	
	do{
		int value;
		scanf("%d", &value);
		insertnode(mylist, value);
		printf("Do you want to continue entering values?\n");
		scanf("%d", &i);
	}while(i == 1);
	
	show(mylist);
	return 0;
}
