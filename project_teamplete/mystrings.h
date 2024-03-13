#pragma once

struct node
{
	char *value;
	struct node *next;
}

struct list
{
	struct node *head;
	int size; 
};

int *create_char(char *value);
int *create_string();
int mylen(char *str):
void insert_char(struct list *list, char *value);
char *concat(char *str1, char *str2);

