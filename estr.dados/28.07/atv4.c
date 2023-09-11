#include <stdio.h>

int buscar(int v[], int n, int x)
{
	int indice = NULL;
	for(int i = 0; i < n; i++)
	{
		if(v[i] == x)
		{
			indice = i;
			break;
		}
	}
	
	return indice;
}

void ler(int v[], int n)
{
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &v[i]);
	}
}

void main()
{

	int n;
	scanf("%d", &n);

	int v[n];
	ler(v, n);
	
	int x;
	scanf("%d", &x);
	int indice;	
	indice = buscar(v, n, x);
	printf("%d", indice);
}
