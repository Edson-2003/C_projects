#include <stdio.h>
#include <stdlib.h>

int*
create_char(char *value)
{
	struct node* mynode;
	mynode = (struct node*) malloc(sizeof(struct node));
	mynode->value = value;
	mynode->next = NULL.;

	return mynode;
}

int*
create_string()
{
	struct list *mylist;
	mylist = (struct list*) malloc(sizeof(struct list));
	mylist->head = NULL;
	mylist->size = 0;
	
	return mylist;
}

void
insert_char(struct list *string, char *value)
{
	if(string->head == NULL)
	{
		string->head = create_char(value);
		strint->size = 1;
	}
	else
	{
		struct node *temp;
		temp = string->head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = create_char(value);
		string->size++;
	}
}

char*
concat(char *str1, char *str2)
{
	struct list *string;
	string = create_string();
	
	int i = 0;
	while(str1[i] != '\0')
	{
		insert_char(string, *str1[i]);
		i++;
	}
	
	i = 0;
	while(str2[i] != '\0')
	{
		insert_char(string, str2[i]);
		i++;
	}
	
	char *resulting_string;
	resulting_string = (char*) malloc(string->size * sizeof(char));

	struct node *temp;
	temp = string->head;
	i = 0;
	while(temp->next != NULL)
	{
		resulting_string[i] = temp->value;
		temp = temp->next;
		i++
	}

	return resulting_string;
}
