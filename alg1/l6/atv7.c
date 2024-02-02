#include<stdio.h>

void main(){
    //declaração e leitura da variavél de limite do vetor
    int n;
    scanf("%d", &n);
    //declaração do vetor
    int vet[n];
    
    //leitura dos valores do vetor com for, a cada laço é feita a verificação
    //do valor do vetor se é negativo ou não3
    for(int i=0; i< n; i++)
    {
        scanf("%d", &vet[i]);
    }

    for(int i = 0; i < n; i++)
    {
        while(vet [i] < 0)
        {
            for(int j=i+1;j<n; j++)
            {
                vet[j - 1] = vet[ j ];
            }
            n--;
        }
    }
    for(int i=0; i< n; i++)
    {
        printf("%d", vet[i]);
    }
}