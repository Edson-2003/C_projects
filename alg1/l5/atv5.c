#include <stdio.h>

void main() {
    int resultado [6];
    int apostas [6];
    int contagem = 0;

    for(int i=0; i < 6;i++)
    {
        scanf("%d", &resultado [i]);
    }

    for(int i=0; i < 6; i++)
    {
        scanf("%d", &apostas [i]);
        for (int j=0; j < 6; j++)
        {
            if (apostas [i] == resultado [j])
            {
                contagem ++;
            }
        }
    }

    printf("\n");

    for (int i=0; i < 6; i++)
    {
        printf (" %d ", apostas [i]);
    }

    printf("\n");

    for (int i=0; i < 6; i++)
    {
        printf (" %d ", resultado [i]);
    }
    printf("\n%d", contagem);
}