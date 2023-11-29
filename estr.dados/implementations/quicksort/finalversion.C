#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <chrono>
//the creator: Edson Augusto Pereira Ferreira

//fundamental functions


int*
int_init(int size)
{
	int *myvector = (int*) malloc(size * sizeof(int));

	return myvector;
}


double*
double_init(int mysize)
{
	double *myvector = (double*) malloc(mysize * sizeof(double));
	return myvector;
}


void
int_finish(int *myvector)
{
	free(myvector);
}


void
double_finish(double *myvector)
{
	free(myvector);
}


void
generatemyvector(int *myvector, int mysize)
{
	srand(time(0));
	for(int i = 0; i < mysize; i++)
	{
		myvector[i] = rand(); 
	}	
}

void
copyvector(int *origin, int *destyne, int size)
{
	for(int i = 0; i < size; i++)
	{
		destyne[i] = origin[i];
	}
}


//the first question


void
swap(int *a, int *b)
{		
	int temp = *a;
	*a = *b;
	*b = temp;
}


void
insertionsort(int *myvector, int low, int high)
{
	int key;
  for(int i = low-1; i < high; i++) 
	{
		key = myvector[i];
    int j = i - 1;
		while((j >= 0) && (myvector[j] > key)) 
		{
			swap(&myvector[j+1], &myvector[j]);
			j--;
		}
		myvector[j + 1] = key;
	}	
}


int
partition(int *myvector, int low, int high)
{
	int pivot = myvector[high];
	int i = low - 1;
	for(int j = low; j < high; j++)
	{
		if(myvector [j] < pivot)
		{
			i++;
			swap(&myvector[i], &myvector[j]);
		}
	}
	swap(&myvector[i + 1], &myvector[high]);
	return i+1;
}


int
randomized_partition(int *myvector, int low, int high)
{
	srand(time(0));
	int randon = low + rand() % high - low;
	swap(&myvector[randon], &myvector[low]);
	return partition(myvector, high, low);
}


void
randomized_quicksort_with_x(int *myvector, int low, int high, int x)
{	
	if(low < high)
	{
		if((high - low) <= x)
		{
			insertionsort(myvector, low, high);
		}
		else
		{
			int pivot = randomized_partition(myvector, low, high);
			randomized_quicksort_with_x(myvector, low, pivot - 1, x);
			randomized_quicksort_with_x(myvector, pivot + 1, high, x);
		}
	}
}


//the secund question


double*
measuring_time(int *myvector, int mysize)
{
	double *mytime = NULL;
	mytime = double_init(100);
	int *temporaryvector = NULL;
	temporaryvector = int_init(mysize);
	for(int i = 0; i <= 100; i++)
	{	
		copyvector(myvector, temporaryvector, mysize);
		auto start = std::chrono::high_resolution_clock::now();
		randomized_quicksort_with_x(temporaryvector, 0, mysize-1, i + 1);
		auto stop = std::chrono::high_resolution_clock::now();
		auto  duration = std::chrono::duration<double>(stop - start);
		mytime[i] = duration.count();	
	}

	return mytime;
}

// the function show the final result of measuring and the best time


void
showmyresults(double *myvector, int mysize)
{
	printf("my results in secund\n");
	printf("X | time\n");	
	double thebest = myvector[0];
	int index = 0;
	
	
	for(int i = 0; i < mysize; i++)
	{
		if(i > 0)
		{
			if(thebest > myvector[i])
			{
				thebest = myvector[i];
				index = i + 1;
			}	
		}
		printf("%d | %.9lf\n", i + 1, myvector[i]);
	
	}
	printf("x value %d, the best time %.9lf\n", index, thebest);
}


int 
main()
{
	int mysize = 1000;
	int *myvector = NULL;
	double *mytime = NULL;
	myvector = int_init(mysize);
	generatemyvector(myvector, mysize);
	mytime = measuring_time(myvector, mysize);
	showmyresults(mytime, 100);
	int_finish(myvector);
	double_finish(mytime);
	return 0;
}
