#include <stdio.h>

void main()
{
    // declaração de variaveis
    int n, k,j1=0;
    
    // leitura de variaveis
    scanf("%d%d", &n, &k);

    // declaração do vetor de tamanho n
    int vet[n];

    // atribuição de valor aos elementos do vetor
    for( int i = 0; i < n; i++)
    {
        scanf("%d", &vet[i]);
    }

    // movimentação e remoção dos valores maiores ou iguais a k
    for(int i=0; i<n;i++)
    {
        // verificação do valor na posição i
        while( vet [i] >= k)
        {
            // movimentação do valor para o fim do vetor
            for(int j=i; j <= n; j++)
            {
                vet [j] = vet [j+1];
            }

            // redução do tamanho do vetor para excluir o valor menor ou igual a k
            n--;
        }
    }


    // impressão do vetor

    for(int i = 0; i < n; i++)
    {
        printf(" %d", vet [i]);
    }
    printf("\n");

}