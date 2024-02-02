#include <stdio.h>

void main() {
    int m,n, maior, menor, imaior, imenor;
    scanf("%d%d", &m,&n);
    int vet [n];

    for(int j=0;j<m;j++)
    {
        for(int i =0; i < m; i++)
        {
        scanf("%d", &vet[i]);
        }

        menor = vet [0];
        imenor =0;
        imaior = 0;
        maior =vet [0];
        for(int i=0; i <n; i++)
        {
            if (vet[i] > maior)
            {
                maior = vet [i];
                imaior = i;
            }
            if (vet[i] < menor)
            {
                menor = vet [i];
                imenor = i;
            }
        }

        printf("%d(%d) %d(%d)", menor, imenor, maior, imaior);
    }
}