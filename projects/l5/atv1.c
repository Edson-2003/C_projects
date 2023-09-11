#include <stdio.h>

void main(){

    int n,i,a;
    scanf("%d", &n);
    int vet[n];

    for(i=0; i<n;i++)
    {
        scanf("%d", &vet[i]);
    }
    for(int x=0;x<n;x++)
    {
        a=0;
        if(x==0)
        {
            printf("%d", vet[x]);
        }
        if (x != 0)
        {
            for(i=0;i<x;i++)
            {
                if (vet[x] == vet[i])
                {
                    a=1;
                    break;
                }
            }
        }
        if ((a==0) && (x !=0))
        {
            printf("%d", vet[x]);
        }

    }
}