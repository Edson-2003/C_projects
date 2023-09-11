#include <stdio.h>
#include <string.h>

typedef struct
{
    char titulo[100];
    char autor[100];
    int ano;
}livro;

void levetor(livro vet[], int n)
{

    for(int i = 0; i < n; i++)
    {
        scanf(" %[^\n]s", &vet[i].titulo);
        scanf(" %[^\n]s", &vet[i].autor);
        scanf("%d", &vet[i].ano); 
    }

}

void escrevevetor(livro vet[], int n)
{

    for(int i = 0; i < n; i++)
    {
        printf("%s", vet[i].titulo);
        printf("%s", vet[i].autor);
        printf("%d", vet[i].ano);
    }
    printf("\n");
    
}

void troca(livro *x, livro *y)
{
    livro temp = *x;
    *x = *y;
    *y = temp;
}

void bubble(livro vet[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n-1; j++)
        {
            if (strcmp(vet[j].titulo, vet[j+1].titulo) > 0)
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

    livro vet[n];

    levetor(vet, n);
    bubble(vet, n);
    escrevevetor(vet, n);
    printf("\n");

}