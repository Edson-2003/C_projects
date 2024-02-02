#include <stdio.h>

void main(){

    // declaração de vvariaveis

    int n;
    float melhorvolta, media, soma=0,a [n];

    // atribuição de valores para cada posição do vetor
    for(int i =0; i < n; i++)
    {
        scanf("%f", & a [i]);
    }

    // hipotese para verificação de melhor volta
    melhorvolta = a [ 0 ];

    // verificação de melhor volta e soma do total de cada volta
    for( int i = 0; i < n;i ++)
    {
        if( a [i] < melhorvolta)
        {
            melhorvolta = a [i];
        }

        soma = soma + a [i];
    }

    // média do tempo de volta
    media = soma/n;
    
    // impressão de valores
    printf("%2f %2f", melhorvolta, media);
}