#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int*
init(int size)
{
	int *myvector = NULL;
	myvector = (int*) malloc(size * sizeof(int));

	return myvector;
}

void
randonvalues(int *vector, int size)
{
	srand(time(0));
	for(int i = 0; i < size; i++)
	{
		vector[i] = rand() % 1000;
	}
}

void
show(int *vector, int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("%d ", vector[i]);
	}
	printf("\n");
}

int 
findmax(int *vector, int size)
{
	int biggest;
	biggest = vector[0];
	for(int i = 0; i < size; i++)
	{
		if(vector[i] > biggest)
		{
			biggest = vector[i];
		}
	}	

	return biggest;
}


void
countingsort(int *vector, int size)
{
	int biggest;
	biggest = findmax(vector, size);
	
	int *countvector = NULL;
	countvector = init(biggest + 1);
	for(int i = 0; i < biggest + 1; i++)
	{
		countvector[i] = 0;
	}
	
	for(int i = 0; i < biggest + 1; i++)
	{
		for(int j = 0; j < size; j++)
		{
			if(vector[j] == i)
			{
				countvector[i] += 1;
			}
		}
	}	

	for(int i = 1; i < biggest + 1; i++)
	{
		countvector[i] += countvector[i-1];
	}

	int *outputvector = NULL;
	outputvector = init(size);
	
	for(int i = 0; i < size; i++)
	{
		outputvector[countvector[vector[i]] - 1] = vector[i];
		countvector[vector[i]] -= 1;
	}	
	
	for(int i = 0; i < size; i++)
	{
		vector[i] = outputvector[i];
	}
	
	free(countvector);
	free(outputvector);
}



int 
main()
{
	int size = 10;
	int *myvector = NULL;
	myvector = init(size);
	randonvalues(myvector, size);
	printf("the origin\n");
	show(myvector, size);
	countingsort(myvector, size);
	printf("the sorted vector\n");
	show(myvector, size);
	free(myvector);	




	return 0;
}
