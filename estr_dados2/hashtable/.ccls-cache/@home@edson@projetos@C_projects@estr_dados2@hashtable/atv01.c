#include <stdio.h>
#include <stdlib.h>


#define days 365;

struct date
{
	int *day;
	int *month;
	int *year;
};

struct person
{
	int value;
	struct date *date;
};

struct node
{
	struct person *person;
	struct node *next;
};

struct table
{
	struct node *first;
};

struct date*
createdate(int day, int month, int year)
{
	struct date *new = NULL;
	new = (struct date*) malloc(sizeof(struct date));
	new->day = day;
	new->month = month;
	new->year = year;

	return new;
}

struct person*
createperson(struct date *date, int value)
{
	struct person *new = NULL;
	new = (struct person*) malloc(sizeof(struct person));
	new->value = value;
	new->date = date;

	return new;
}

struct node*
createnode(struct person *person)
{
	struct node *new = NULL;
	new = (struct node*) malloc(sizeof(struct node));
	new->person = person;
	new->next = NULL;

	return new;
}

int
tohash(int day, int month)
{
	switch (month) {
		case 1:
			return day - 1;
			break;
		case 2:
			return 31 + day - 1;
			break;
		case 3;
			return 31 + 28 + day - 1;
			break;
		case 4:
			return 31 + 28 + 31 + day - 1;
			break;
		case 5:	
			return 31 + 28 + 31 + 30 + day - 1;
			break;
		case 6:
			return 31 + 28 + 31 + 30 + 31 + day - 1;
			break;
		case 7:			
			return 31 + 28 + 31 + 30 + 31 + 30 + day - 1;
			break;
		case 8:			
			return 31 + 28 + 31 + 30 + 31 + 30 + 31 + day - 1;
			break;
		case 9:			
			return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + day - 1;
			break;
		case 10:			
			return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day - 1;
			break;
		case 11:			
			return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day - 1;
			break;
		case 12:			
			return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day - 1;
			break;

		default:
			printf("deu ruim");
			break;
	}
}


void 
insertontable(struct table *table, int day, int month, int year, int value)
{
	struct date *newdate = NULL;
	newdate = createdate(day, month, year);
	
	struct person *newperson = NULL;
	newperson = createperson(newdate, value);

	struct node *newnode = NULL;
	newnode = createnode(newperson);

	if(table[tohash(day, month)]->first == NULL)
	{
		table[tohash(day, month)]->first = newnode;
	}
	else
	{
		struct node *temp = table[tohash(day, month)]->first;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newnode;
	}
}

void
search(struct table *table, int day, int mount, int year)
{
	if(table[tohash(day,month)]->first == NULL)
	{
		printf("This date has not been registered yet");
	}
	else
	{
		struct node *temp = table[tohash(day,month)]->first;
		int i = 0;
		while(temp->next != NULL)
		{
			printf("\n (%d)  |day: %d  |mounth: %d  |year: %d  |value: %d", i, temp->person->date->day, temp->person->date->mount, temp->person->date->year, temp->person->value);
		}
	}
}

void
destroy_table(struct table *table)
{

}

void
showtable(struct table *table)
{
	for (i = 0; i < days; ++i)
	{
		if(table[i]->first == NULL)
		{
			printf("\n (%d)", i);
		}
		else
		{
			struct node *temp = table[i]->first;
			printf("\n (%d)  |day: %d  |mounth: %d  |year: %d  |value: %d", i, temp->person->date->day, temp->person->date->mount, temp->person->date->year, temp->person->value);
			while(temp->next != NULL)
			{
				temp = temp->next;
				printf("\n (%d)  |day: %d  |mounth: %d  |year: %d  |value: %d", i, temp->person->date->day, temp->person->date->mount, temp->person->date->year, temp->person->value);
			}
		}
	}
}

int int main(int argc, char *argv[])
{
	int option;
	struct table* table = NULL;
	table = (struct table *) malloc(days * sizeof(struct table));
	int index = 0;
	while(index < days)
	{
		table[index]->first = NULL;
	}

	do 
	{
		printf("\n select one of the options:\n (1) show all the records (2) serach record (3) insert people (4) search record (0) exit\n");
		scanf("%d", &option);
		switch (option)
	 	{
			case 0:
				printf("leaving");
				destroy_table(table);
				break;
			case 1:
				showtable(table);		
				break;
			case 2:
				int day, month, year;
				printf("\n write day");
				scanf("%d", &day)
				search(table, day, mounth, year);
				break;
			default:
				
		}
	}while (option != 0);	

	return 0;
}
