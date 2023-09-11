#include <stdio.h>

void verificamaiormedia(int v[], int a)
{

    int contagem = 0;
    for(int i = 0; i < 20; i++)
    {
        if(v [i] > a)
        {
            contagem++;
        }
    }

    printf("%d\n", contagem);

}

void main()
{
    int v[20];
    int media = 0;

    for(int i = 0; i < 20; i++)
    {
        scanf("%d", &v[i]);
        media = media + v[i];
    }

    media = media/20;

    verificamaiormedia(v, media);
}