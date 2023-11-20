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

struct list
_create_mylist()
{
	struct list mylist = (struct list*) malloc(sizeof(struct list));
	if(mylist->head != NULL)
	{
		mylist->head = NULL;
		
	}

}



struct list
_init(struct list *mylist)
{
	if(mylist->head != NULL)
	{
		
	}

}




int 
main()
{


	return 0;
}
