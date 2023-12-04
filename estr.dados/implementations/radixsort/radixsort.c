#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void
randonvalues(int *vector, int size)
{
	srand(time(NULL));
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


void
countingsort(int *vector, int size, int exp)
{
	int aux = exp;
	exp = 1;
	for(int a = aux; a > 0; a--)
	{
		exp = exp * 10;
	}

	
	int *countvector = NULL;
	countvector = (int*) malloc(10*sizeof(int));
	for(int i = 0; i < 10; i++)
	{
		countvector[i] = 0;
	}
	
	for(int i = 0; i < size; i++)
	{
    countvector[(vector[i]/exp)%10]++;
	}	

	for(int i = 1; i < 10; i++)
	{
		countvector[i] += countvector[i-1];
	}

	int *outputvector = NULL;
	outputvector = (int*) malloc(size*sizeof(int));
  
	
	for(int i = size - 1; i >= 0; i--)
	{
		outputvector[countvector[(vector[i]/exp)%10]] = vector[i];
		countvector[(vector[i]/exp)%10] -= 1;
	}	
	
	for(int i = 0; i < size; i++)
	{
		vector[i] = outputvector[i];
	}
	
	free(countvector);
	free(outputvector);	
}

void
radixsort(int *vector, int size, int d)
{
	for(int i = 0; i < d; i++)
	{
		countingsort(vector, size, i);
	}
}




int 
main()
{
  int *vector = (int*) malloc(100*sizeof(int));
  randonvalues(vector, 100);
  printf("the origin vector");
  show(vector,100);
  radixsort(vector, 100, 3);
  printf("the sorted vector");
  show(vector, 100);
  return 0;
}