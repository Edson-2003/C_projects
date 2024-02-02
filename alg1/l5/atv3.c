#include <stdio.h>

void main(){
    int m,n,maior,menor,posi,imaior,imenor;
    scanf("%d%d", &m, &n);
    int vet [m] [n];

    // atribuição de valor da matriz
    for(int i=0;i<m;i++){
        for(int x=0;x<n;x++)
        {
            scanf("%d", &vet [i] [x]);
        }
    }

    for(int i=0;i<m;i++)
    {    
        // hipoteses  
        maior = vet [i] [0];
        menor =vet [i] [0];
        imaior =0;
        imenor =0;

        // verificação do maior e menor
        for(int x=0;x<n;x++)
        {
            
            // verificação do maior
            if(vet [i] [x] > maior)
            {
                maior = vet [i] [x];
                imaior = x;
            }

            // verificação do menor

            if(vet [i] [x] < menor)
            {
                menor = vet [i] [x];
                imenor = x;
            }

        }

        //saida dos elementos de cada linha
        printf("%d (%d) %d (%d)", maior, imaior, menor, imenor);
   }
}