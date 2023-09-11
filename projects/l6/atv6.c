#include <stdio.h>

void main() {
    // declaração n e auxiliar, onde n vai reger o tamamho do vetor e aux realinhar o vetor auxiliar
    
    int n, aux;
    scanf("%d", &n);
    int n2 = n*2;
    int vet1[n], vet2[n], vet3[n2];

    for(int i=0; i < n; i++)
    {
        scanf("%d", &vet1[i]);
    }

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &vet2[i]);
    }

    // copiado o primeiro vetor para a primeira parte do vet3
    for (int i = 0; i < n; i++)
    {
        vet3[i] = vet1[i];
    }
    for (int i = 0; i < n; i++)
    {
        vet3[i+n] = vet2[i];
    }

    //eliminando repetições
    for( int i = 0; i < n2; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if( vet3 [j] == vet3 [i]) 
            {
                for(int k = i+1; k < n2; k++)
                {
                    vet3 [k-1] = vet3 [k];
                    
                }
                n2--;
            }
        }
    }
        
    
    // ordenando vetor resultante
    for(int i=0; i< n2; i++)
    {
        for(int j=0; j < n-1; j++)
        {
            if(vet3[j] > vet3[j+1])
            {
                aux = vet3[j];
                vet3[j] = vet3[j+1];
                vet3[j+1] = aux;
            }
        }
    }


    // printando resultado
    for(int i = 0; i < n2; i++)
    {
        printf("%d", vet3[i]);
    }
}