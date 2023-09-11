#include <stdio.h>

void main()
{
    // declaração de variaveis
    int n, k1, k2, aux=0;

    // leitura das variaveis
    scanf("%d%d%d", &n, &k1, &k2);

    // declaração de um vetor de tamanho n
    int vet[n];

    // atribuição de valor para cada posição do vetor
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &vet[i]);

        // verificação se o valor lido esta no intervalo de k1 a k2
        if ((vet[i] >= k1) && (vet[i] <= k2))
        {
            aux++;
        }
    }

    // impressão da contagem de valores no intervalo de k1 a k2
    printf("%d", aux);

}