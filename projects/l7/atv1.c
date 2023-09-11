#include <stdio.h>

void main()
{   
    // declaração e leitura dos valores limite da matrix
    int m, n;
    scanf("%d%d", &m, &n);
    int aux=0;

    // declaração da matrix
    int mat [m] [n];
    
    // definição de valores da matrix
    for(int i=0; i < m;i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j)
            {
                mat [i] [j] = 0;
            }
            /*
            if(j != i)
            {
                mat [i] [j] = 1;
            }
            */
        }
    }

    aux=0;
    for(int i = 0; i < n;i++)
    {
        for(int j=0; j < n; j++)
        {
            if(mat [i] [j] == 0)
            {
                aux = 1;
            }
            if(aux == 0)
            {
                if( i != j)
                {
                    mat [i] [j] = -1;
                }
                
            }
            if(aux == 1)
            {
                mat [i] [j] = 1;
            }
        }
        aux = 0;
    }

    // impressão da matrix resultante
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf(" %d", mat [i] [j]);
        }
        printf("\n");
    }

}