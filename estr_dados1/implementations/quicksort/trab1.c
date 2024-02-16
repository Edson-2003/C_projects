#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <chrono>
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
showmyresults(double *myvector, int mysize)
{
	printf("my results\n");
	
	printf("X | time\n");	
	for(int i = 0; i < mysize; i++)
	{
		printf("%d | %.15lf\n", i + 1, myvector[i]);
	}
}


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
	

	//inverter low,high
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


double*
measuring_time(int *myvector, int mysize, double *total_time)
{
	clock_t start_measuring, end_measuring;
	double *mytime = NULL;
	mytime = double_init(100);
	
	start_measuring = clock();
	for(int i = 1; i <= 100; i++)
	{	
		clock_t start_function, end_function;
		start_function = clock();
		randomized_quicksort_with_x(myvector, 0, mysize-1, i + 1);
		end_function = clock();
		mytime[i] = ((double) (end_function - start_function)) / CLOCKS_PER_SEC;
	}

	end_measuring = clock();
	*total_time = ((double) (end_measuring - start_measuring)) / CLOCKS_PER_SEC;
	return mytime;
}
/*

double*
measuring_time(int *myvector, int mysize)
{
	
	double *mytime = NULL;
	mytime = double_init(100);
	for(int i = 1; i <= 100; i++)
	{	
		auto start = high_resolution_clock::now();
		randomized_quicksort_with_x(myvector, 0, mysize-1, i + 1);
		auto stop = high_resolution_clock::now();
		mytime[i] = ((double) (end_function - start_function)) / CLOCKS_PER_SEC;
	}

	return mytime;
}
*/
int 
main()
{
	int mysize = 1000;
	//scanf("%d", &mysize);
	int *myvector = NULL;
	double *mytime = NULL;
	myvector = int_init(mysize);
	generatemyvector(myvector, mysize);
	//randomized_quicksort_with_x(myvector, 0, mysize-1, 10);
	mytime = measuring_time(myvector, mysize, &total_time);
	showmyresults(mytime, 100);
	int_finish(myvector);
	double_finish(mytime);
	return 0;
}
