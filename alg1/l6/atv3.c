//identificação e remoção de um elemento determinado em um vetor, a cada remoção o vetor é redimensionado

#include <stdio.h>

void main(){
   
    // declaração e leitura de variaveis n e k
    int n,k;
    scanf("%d%d", &n, &k);

    // declaração do vetor
    int vet[n];


    // leitura dos valores do veotr
    for(int i = 0;i<n;i++)
    {
        scanf("%d", &vet[i]);

        // a verificação se o valor lido o selecionado, remoção e redimensionamento do vetor
        if (vet [i] == k)
        {
            n--;
            i--;
        }
    }

    for(int i=0; i<n; i++)
    {
        printf("%d", vet[i]);
    }

}