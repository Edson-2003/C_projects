#include<stdio.h>
#include<stdlib.h>

int *levetor(int n, int *v)
{
    for(int i=0;i<n;i++)
    {
        scanf("%d", &v[i]);
    }
return v;
}

void main()
{
 int n;
 scanf("%d", &n);
 int *v = malloc(n * sizeof(int));
 v = levetor(n, v);

 for(int i=0;i<n;i++)
 {
  printf("%d ", v[i]);
 }
}