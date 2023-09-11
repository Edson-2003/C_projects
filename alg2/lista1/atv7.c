#include <stdio.h>

void imprimev(int v[], int n)
{
    for (int i = 0; i<n; i++)
    {
        printf ("%d ", v[i]);
    }
}


void main()
{
    int n;
    scanf ("%d", &n);
    int v[n];
    
    for (int i = 0; i<n; i++)
    {
        scanf ("%d", &v[i]);
    }

    imprimev(v, n);
}


