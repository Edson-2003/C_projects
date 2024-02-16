#include <stdio.h>

int fibonacci(int n)
{
	if(n == 1)
		return 0;
	else
	{
		if(n == 2)
			return 1;
		
		else
			return fibonacci(n - 1) + fibonacci(n - 2);
	}
	
}

int fibonacci_iterativo(int n)
{
	int n1 = 1, n2 = 0, temp, fn;
	if(n == 1)
		return 0;
	else
	{
		if(n == 2)
			return 1;
		else
		{
			for(int i = 3; i  <= n; i++)
			{
				temp = n1;
				n1 = n1 + n2;
				n2 = temp;
				
			}
			return n1;
		}
	}
}

void main()
{
	printf("%d\n", fibonacci(5));
	printf("%d\n", fibonacci_iterativo(5));
}
