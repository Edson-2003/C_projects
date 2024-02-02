#include <stdio.h>

void main (){

    int res;
    int numerador, multiplicador;

    scanf("%d",numerador);
    scanf("%d",multiplicador);



    for (int i=1; i <= numerador; i++)
    {
        printf("tabuada do %d\n\n", i);
        for (int m=1; m <= multiplicador; m++)
        {
            res = i * m;
            printf("%d * %d = %d\n", i, m, res);
            if (m == multiplicador) 
            {
                printf ("\n");
            }
        }
    }

    printf("fim do laco\n");

}