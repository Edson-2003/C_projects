#include <stdio.h>

typedef struct 
{
    char nome[100];
    int matricula;
    float nota;
}aluno;

void levetor(aluno vet[], int n, float *soma)
{

    for(int i = 0; i < n; i++)
    {
        scanf("%s", vet[i].nome);
        scanf("%d", &vet[i].matricula);
        scanf("%f", &vet[i].nota);

        *soma = *soma + vet[i].nota;
    }

}

void escrevevetor(aluno vet[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%s ", vet[i].nome);
        printf("%d ", vet[i].matricula);
        printf("%.2f ", vet[i].nota);
    }
    printf("\n");
    
}

void main()
{
    int n;
    float soma=0;
    scanf("%d", &n);

    aluno vet[n];

    levetor(vet, n, &soma);

    printf("%.2f", soma/n);
}
