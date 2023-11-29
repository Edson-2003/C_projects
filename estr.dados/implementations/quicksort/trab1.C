#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <chrono>


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

// the function show the final result of measuring and the best time
void
showmyresults(double *myvector, int mysize)
{
	printf("my results in microsecunds\n");
	double the_besttime = myvector[0];
	int id = 0;	
	printf("X | time\n");	
	for(int i = 0; i < mysize; i++)
	{
		if(i >= 0)
		{
			if(myvector[i] >= the_besttime)
			{
				the_besttime = myvector[i];
				id = i;
			}
		}
		printf("%d | %.9lf\n", i + 1, myvector[i]);
	}
	printf("the x for the best time %d, the time is %.9lf\n", id, the_besttime);
}

//the start of first question

void
swap(int *a, int *b)
{		
	int temp = *a;
	*a = *b;
	*b = temp;
}


void
insertionsort(int *myvector, int size)
{
	int key;
  for(int i = 1; i < size; i++) 
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

	return i++;
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
			insertionsort(myvector, high + 1);
		}
		else
		{
			int pivot = randomized_partition(myvector, low, high);
			
			randomized_quicksort_with_x(myvector, low, pivot - 1, x);
			randomized_quicksort_with_x(myvector, pivot + 1, high, x);
		}
	}
}

//the end of the first question

/*
double*
measuring_time(int *myvector, int mysize)
{
	clock_t start_measuring, end_measuring;
	double *mytime = NULL;
	mytime = double_init(100);

	for(int i = 1; i <= 100; i++)
	{	
		clock_t start_function, end_function;
		start_function = clock();
		randomized_quicksort_with_x(myvector, 0, mysize-1, i + 1);
		end_function = clock();
		mytime[i] = ((double) (end_function - start_function)) / CLOCKS_PER_SEC;
	}

	return mytime;
}
*/

//the start of the secund question
double*
measuring_time(int *myvector, int mysize)
{
	
	double *mytime = NULL;
	mytime = double_init(100);
	for(int i = 1; i <= 100; i++)
	{	
		auto start = std::chrono::high_resolution_clock::now();
		randomized_quicksort_with_x(myvector, 0, mysize-1, i + 1);
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		mytime[i - 1] = duration.count();	
	}

	return mytime;
}
//in this metodh

int 
main()
{
	int mysize = 1000;
	//scanf("%d", &mysize);
	int *myvector = NULL;
	double *mytime = NULL;
	myvector = int_init(mysize);
	generatemyvector(myvector, mysize);
	double *total_time;
	//randomized_quicksort_with_x(myvector, 0, mysize-1, 10);
	mytime = measuring_time(myvector, mysize);
	showmyresults(mytime, 100);
	int_finish(myvector);
	double_finish(mytime);
	return 0;
}
