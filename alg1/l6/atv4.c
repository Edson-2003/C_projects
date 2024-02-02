// vetor de n posições que deve não deve conter valores repetidos, durante a leitura verificação dos valores
// iguais e redimensionamento do vetor

#include <stdio.h>

void main(){
    
    // declaração da variavél n e leitura
    int n; 
    scanf("%d", &n);

    // delcaração do vetor
    int vet[n];


    // leitura das posições do vetor
    for(int i=0; i<n; i++)
    {
        scanf("%d", &vet[i]);

        // laço para verificação de valores iguais
        for(int j=0; j<i; j++)
        {
            // eliminação de valores iguais e redimensionamento do vetor
            if(vet[i] == vet[j])
            {
                n--;
                i--;
            }
        }

    }


    // impressão do vetor
    for(int i = 0; i < n; i++)
    {
        printf("%d", vet[i]);
    }
    

}