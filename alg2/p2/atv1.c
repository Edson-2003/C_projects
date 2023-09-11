#include <stdio.h>
#include <stdlib.h>

//ok
void le_matriz(int** matriz, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &matriz [i] [j]);
        }
    }
}

// ok
int** aloca_matriz(int n)
{
    int** matriz = (int**) malloc(n * sizeof(int*));
    
    for(int i = 0; i < n; i++)
    {
        matriz[i] = (int*) malloc(n * sizeof(int));
    }

 return matriz;
}

// ok
int diagonal_principal(int i, int j, int n)
{
    if(i == j)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// ok
int diagonal_secundaria(int i, int j, int n)
{
    if((i + j) == (n + 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//ok
int maior_diagonal(int** matriz, int n, int (*diagonal)(int, int, int))
{
    int maior = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(diagonal(i, j, n) == 1)
            {
                if(matriz [i] [j] > maior)
                {
                    maior = matriz [i] [j];
                }
            }

        }
    }

    return maior;
}




void main()
{
    int n;
    scanf("%d", &n);

    int** matriz = aloca_matriz(n);

    le_matriz(matriz, n);

    void *fp;
    fp = diagonal_principal;
    int maior_p = maior_diagonal(matriz, n, fp);
    printf("%d", maior_p);

    void *fs;
    fs = diagonal_secundaria;
    int maior_s = maior_diagonal(matriz, n, fs);
    printf("%d", maior_s);

    free(matriz);

}
