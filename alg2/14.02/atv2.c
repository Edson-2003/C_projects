#include <stdio.h>

int expo(int x, int n)
{
    for(int i = 1; i < n; i++)
    {
        x = x * x;
    }
    return x;
}

void main(){
    int n, x;
    scanf("%d%d", &x, &n);
    printf("o resultado é %d\n", expo(x,n));
}