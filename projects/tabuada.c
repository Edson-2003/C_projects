#include <stdio.h>

void main (){

    int res;
    for (int i=1; i <= 10; i++)
    {
        printf("tabuada do %d\n\n", i);
        for (int m=1; m <= 10; m++)
        {
            res = i * m;
            printf("%d * %d = %d\n", i, m, res);
            if (m == 10) 
            {
                printf ("\n");
            }
        }
    }

    printf("fim do laco\n");

}