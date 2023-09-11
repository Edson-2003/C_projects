#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[100];
}reg;

void levetor(reg vet[], int n)
{

    for(int i = 0; i < n; i++)
    {
        scanf("%s", vet[i].nome); 
    }

}

void escrevevetor(reg vet[], int n)
{

    for(int i = 0; i < n; i++)
    {
        printf("%s ", vet[i].nome);
    }
    printf("\n");
    
}

void troca(reg *x, reg *y)
{
    reg temp = *x;
    *x = *y;
    *y = temp;
}

void bubble(reg vet[], int n)
{

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n-1; j++)
        {
            if (strcmp(vet[j].nome, vet[j+1].nome) > 0)
            {
                troca(&vet[j], &vet[j+1]);
            }
        }
    }
}


void main()
{

    int n;

    scanf("%d", &n);

    reg vet[n];

    levetor(vet, n);
    escrevevetor(vet, n);
    bubble(vet, n);
    escrevevetor(vet, n);

}