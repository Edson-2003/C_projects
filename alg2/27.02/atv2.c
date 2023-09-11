#include <stdio.h>

void negativa (int *a) 
{
    *a= *a*-1;
}

void main()
{
    int a;
    scanf("%d",&a);
    printf("%d\n", a);
    negativa(&a);
    printf("%d\n", a);
}