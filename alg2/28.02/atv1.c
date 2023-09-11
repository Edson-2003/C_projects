#include <stdio.h>

void le_vetor(int v[], int *n)
{
    for(int i = 0; i < *n; i++)
    {
        scanf("%d", &v[i]);
    }
}

void imprime_vetor(int v[], int *n)
{
    for(int i = 0; i < *n; i++)
    {
        printf("%d\n", v[i]);
    }
}

void main(){
    int n;

    scanf("%d",&n);

    int v[n];

    le_vetor(v, &n);
    imprime_vetor(v, &n);




}