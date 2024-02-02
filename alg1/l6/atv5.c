// leitura de dois vetores diferentes e a criação de um terceiro vetor que armazena os valores que os dois anteriores
// tem em comun


#include <stdio.h>

void main(){
    // declaração das variaveis: a, responsável pela limitação do terceiro vetor
    // variavél auxiliar e n que limita o vetor a e b e leitura da variavél n 
    int n, a=0, aux=0;
    scanf("%d", &n);

    // declaração dos vetores: veta; vetb e veti; que contem os elementos presentes 
    int veta[n];
    int vetb[n];
    int veti[a];

    // leitura dos valores do primeiro vetor
    for(int i=0; i<n; i++)
    {
        scanf("%d", &veta[i]);
    }

    // leitura dos valores do primeiro vetor
    for(int i=0; i < n; i++)
    {
        scanf("%d", &vetb[i]);

        // verificação de valores comuns e alocação no vetor resultante
        for(int j=0; j<n; j++)
        {

                if( veta[j] == vetb[i])
                {
                    a++;
                    veti[aux] = veta[j];
                    aux++;
                }
            
        }
    }

    // ordenação pelo metódo bubble sort
    for( int i=0; i<a; i++)
    {
        for(int j=0; j<a-1; j++)
        {
            if (veti[j] > veti[j+1])
            {
                aux = veti[j];
                veti[j] = veti[j+1];
                veti[j+1] = aux;
            }
        }
    }



    for(int i=0; i < a; i++)
    {
        printf("%d", veti[i]);
    }
}