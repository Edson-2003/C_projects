#include <stdio.h>
#include <stdlib.h>

void levetor(int *v, int n)
{
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
}

void imprimevetor(int *v, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d", v[i]);
    }
    
}


int *uniao(int *v1, int *v2, int n1, int n2, int *qat)
{
    int repete = 0;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (v1[i] == v2[j])
            {
                repete++;
            }
        }
    }

    repete = (n2 + n1) - repete;
    int *v3 = malloc(repete * sizeof(int));
    *qat = repete;
    int i;

    for (i = 0; i < n1; i++)
    {
        v3[i] = v1[i];
    }
    for (int j = 0; j < n2; j++)
    {
        int repetiu = 0;
        for (int n = 0; n < i; n++)
        {
            if (v3[n] == v2[j])
            {
                repetiu = 1;
            }
        }
        if (repetiu != 1)
        {
            v3[i] = v2[j];
            i++;
        }
    }

    return v3;
}

int main()
{
    int n1, n2, *v3, qtd;
    scanf("%d %d", &n1, &n2);
    int v1[n1], v2[n2];

    levetor(v1, n1);
    levetor(v2, n2);
    
    int *v3;
    v3 = uniao(v1, v2, n1, n2, &qtd);
}