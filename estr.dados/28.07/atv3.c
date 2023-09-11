#include <stdio.h>

void ler(int v[], int n)
{
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &v[i]);
	}
}

void imprimir(int v[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%d ", v[i]);
	}
}

void insertion_decrescente(int v[], int n)
{
	int key;
	for(int i = 1; i < n; i++)
	{
		key = v[i];
		for(int j = i -1; j >= 0 && v[j] < key; j--)
		{
			v[j+1] = v[j];
			v[j] = key;
		}
	}
}

void main()
{
	int n;
	scanf("%d", &n);
		
	int v[n];
	ler(v,n);
	insertion_decrescente(v,n);
	printf("insertion\n");
	imprimir(v,n);
}
