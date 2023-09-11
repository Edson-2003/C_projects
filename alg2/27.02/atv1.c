#include <stdio.h>

void zera (int *a) 
{
    *a=0;
}

void main()
{
    int a;
    scanf("%d",&a);
    printf("%d\n", a);
    zera(&a);
    printf("%d\n", a);
}