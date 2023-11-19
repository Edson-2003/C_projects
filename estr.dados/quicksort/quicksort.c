#include <stdio.h>
#include <stdlib.h>

	int 
*_myinit(int size)
{
	int *vector = malloc(size * sizeof(int));
	return vector;
}

void
_myfinish(int *myvector)
{
	free(myvector);
}

void
_getmyvector(int *myvector, int size)
{
	for(int i = 0; i < size; i++)
	{
		scanf("%d", &myvector[i]);	
	}
}

void
_printmyvector(int *myvector, int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("%d", myvector[i]);
	}
}

void
_swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int
_partition(int *myvector, int low, int high)
{
	int pivot =  myvector[high];
	int i = (low - 1);
	int j;
	for(j = low; j < high; j++)
	{
		if(myvector[j] < pivot)
		{
			i++;
			_swap(&myvector[i], &myvector[j]);
		}
	}
	_swap(&myvector[i+1], &myvector[high]);
	return i ++;
}


void
_quicksort(int *myvector, int low, int high)
{
	if(low < high)
	{
		int pivot = _partition(myvector, low, high);
		
		_quicksort(myvector, low, pivot - 1);
		_quicksort(myvector, pivot + 1, high);
	}
}



int
main()
{
	int mysize;
	scanf("%d", &mysize);
	int *myvector = NULL;
	myvector = _myinit(mysize);
	_getmyvector(myvector, mysize);
	_printmyvector(myvector, mysize);
	_quicksort(myvector, 0, mysize -1);
	printf("the sorted vector");
	_printmyvector(myvector, mysize);



	return 0;
}
