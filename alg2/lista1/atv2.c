#include<stdio.h>

int fatorial(int a)
{
    int n = a;
    for(int i = a - 1; i > 0; i--)
    {
        n = n * i;
    }
}

void main()
{
  int n;

  scanf("%d", &n);
  printf("%d\n", fatorial(n));
}