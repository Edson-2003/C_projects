#include<stdio.h>

void main()
{
    // declaração de variaveis
    int somap=0, somas=0, m;

    // leitura da variavel m
    scanf("%d", &m);

    // declaração da matrix mxm
    int mat[m] [m];
    
    // atribuição dos valores de cada posição da matriz
    for(int i =0; i < m; i++)
    {
        for(int j=0; j < m; j++)
        {
            scanf("%d", &mat[i] [j]);
        }
    }
    
    // soma dos valores na diagonal principal
    for(int i = 0; i < m; i++)
    {
        somap = somap + mat [i] [i];
    }
    
    // soma dos elementos na diagonal secundaria
    int j=m-1;
    for(int i = 0; i < m; i++)
    {
        somas = somas + mat [i] [j];
        j--;
    }


    printf("%d ", somap);
    printf(" %d", somas);
    


    /*
    for(int i =0; i < m; i++)
    {
        for(int j=0; j < m; j++)
        {
            printf("%d", mat[i] [j]);
        }
    }
    */
    
}