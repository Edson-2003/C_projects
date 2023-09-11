#include <stdio.h>
#include <stdlib.h>

int* cria_vetor(int n)
{
    n = n*sizeof(int);
    int *v = malloc(n);
    return v;
}

void le_vetor(int *v, int n)
{
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
}

void imprime_vetor(int *v, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d", v[i]);
    }
}

void main()
{
    int n;
    scanf("%d", &n);
    int *vet = cria_vetor(n);

    le_vetor(vet, n);

    imprime_vetor(vet, n);

    free(vet);

}