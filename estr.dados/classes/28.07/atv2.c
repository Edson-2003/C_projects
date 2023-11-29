#include <stdio.h>

int sumarray(int v[], int n)
{
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		sum = sum + v[i];
	}
	return sum;
}

void ler(int v[], int n)
{
	for(int i =0; i < n; i++)
	{
		scanf("%d", &v[i]);
	}
}

void main()
{
	int n;
	int soma;
	scanf("%d", &n);

	int v[n];
	ler(v, n);
	soma = sumarray(v, n);
	printf("%d", soma);

}
