#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct date
{
	int day;
	int month;
	int year;
};

struct person
{
	struct date *dateofbirth;
	int age;
};

struct table
{
	struct person *people;
};


int
agecalc(struct date *dateofbirth)
{
	struct tm *mytime;
	time_t seconds;
	time(&seconds);
	mytime = localtime(&seconds);

	int age;
	age = dateofbirth->year - (mytime->tm_year + 1900);
	return age;		
}
	
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
createperson(struct date *dateofbirth)
{
	struct person *new = NULL;
	new = (struct person*) malloc(sizeof(struct person));
	
	new->dateofbirth = dateofbirth;
	new->age = agecalc(dateofbirth);
	
	return new;
}

int
hash(int day, int month)
{
	switch (month) 
	{
		case 1:
			return day - 1;
			break;
		case 2:
			return 31 + day - 1;
			break;
		case 3:
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
			printf("this date is invalid");
			break;
	}
}

void
insert(struct table *table, struct date *dateofbirth)
{
	if(&table->people[hash(dateofbirth->day, dateofbirth->month)] == NULL)
	{
		table->people[hash(dateofbirth->day, dateofbirth->month)] = createperson(dateofbirth);
		return;
	}
	if(dateofbirth->year < table->people[hash(dateofbirth->day, dateofbirth->month)]->dateofbirth->year)
	{
		table->people[hash(dateofbirth->day, dateofbirth->month)] = createperson(dateofbirth);
		return;
	}
	if(dateofbirth->month > table->people[hash(dateofbirth->day, dateofbirth->month)]->dateofbirth->month)
	{
		table->people[hash(dateofbirth->day, dateofbirth->month)] = createperson(dateofbirth);
		return;
	}
	if(dateofbirth->day > table->people[hash(dateofbirth->day, dateofbirth->month)]->dateofbirth->day)
	{
		table->people[hash(dateofbirth->day, dateofbirth->month)] = createperson(dateofbirth);
		return;
	}
}

void
delete(struct table *table, int day, int month)
{
	if(&table->people[hash(day, month)] != NULL)
	{
		free(table->people[hash(day, month)]->dateofbirth);
		free(table->person[hash(day, month)]);
	}
}

struct person*
search(struct table *table, int day, int month)
{
	if(&table->people[hash(day, month)] != NULL)
	{
		return table->people[hash(day, month)];
	}
	return NULL;
}


int main(int argc, char *argv[])
{
	
	return 0;
}
