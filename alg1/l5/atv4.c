#include <stdio.h>

void main() {
    int n,k,p;
    scanf("%d", &n);
    int vet [n];

    for(int i=0; i<n;i++)
    {
        scanf("%d", &vet [i]);
    }

    scanf("%d", &k);

    for (int i=0;i <n; i++)
    {
        if(vet[i] == k)
        {
            p = i;
        }
    }
    printf("%d", p);
}