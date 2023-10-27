#include <stdio.h>


float
aloca(int m, int n)
{
	float **mat = (float**) malloc(n * sizeof(float*));
	
	for
	(int i = 0; i < m; i++)
	{
		mat[i] = (float*) malloc(m * sizeof(float));		
	}

	return mat;
}

void
destroi(float **mat)
{
	for
	(int i = 0; i < n; i++)
	{
		free(mat[i]);
	}

	free(mat);
}


void
zeramat(float **mat, int m, int n)
{
	for
	(int i = 0; i < n; i )
	{
		for
		(int j = 0; j < m; j++)
		{
			mat [i] [j] = 0;

		}
	}

}


void
imprime(float **mat, int m, int n)
{
	for
	(int i = 0; i < n; i++)
	{
		for
		(int j = 0; j < m; j++)
		{
			printf("%.2f", mat[i] [j]);
		}
	}
}



int
main()
{
	//le as dimensões da matriz
	int m, n;
	scanf("%d%d", &m, &n);
	
	//aloca a matriz
	float **mat = aloca(m, n);
	zeramat(mat, m, n);
	imprime(mat, m, n);



	return 0;
}
