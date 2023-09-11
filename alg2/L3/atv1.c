#include <stdio.h>

void levetor(int v[], int n)
{
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
}

void main()
{
    FILE *ptrarq;
    ptrarq = fopen("saida.txt", 'r');

}
