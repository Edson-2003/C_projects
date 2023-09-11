#include <stdio.h>
#include <stdlib.h>

int** alocamat(int n, int m)
{
	int** mat = (int**) malloc(n * sizeof(int*));
	for(int i = 0; i < m; i++)
	{
		mat[i] = (int*) malloc(m * sizeof(int));
	}
	return mat;
}

void main()
{
	FILE *arq;
	arq = fopen("a.txt", "r");
	

	int m, n;
	fscanf(arq,"%d%d", &n, &m);
	
	int** mat = alocamat(n, m);
	
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			fscanf(arq, "%d", &mat [i] [j]);
		}
	}
	

	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
			printf("%d ", mat [i] [j]);
		printf("\n");
	}
		
	for(int i = 0; i < n; i++)
		free(mat[i]);
	free(mat);
	fclose(arq);
}
