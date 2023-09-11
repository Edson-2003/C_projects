#include <stdio.h>

void levetor(int vet[],int *n)
{
    for(int i = 0; i < n; i++)
    {
        scanf("%d", vet[i]);
    }
}

int filtro_par(int n)
{
    return (n%2) ? 1 : 0;
}

int filtro_impar (int n)
{
    return ! filtro_par(n);
}

float media(int v[], int n, int(*pf)(int))
{
    float soma = 0;
    int cont = 0;
    for(int i = 0; i < n; i++)
    {
        if((*pf)(v[i]))
        {
            soma = soma + v[i];
            cont ++;
        }
    }

    if(cont == 0) return 0;

    return soma/cont;
}
void main()
{
    int n;
    scanf("%d", &n);
    int vet[n];

    levetor(vet, &n);

    float m = media(vet, n, filtro_par);


    m = media(vet, n, filtro_impar);


}