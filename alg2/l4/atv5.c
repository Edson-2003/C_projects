#include<stdio.h>
#include<stdlib.h>

void levetor(int *v, int n)
{
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

}
int conta_ocorrencias(int *v, int n, int k)
{
 int cont = 0;
 for(int i=0;i<n;i++)
 {
  if(v[i] == k)
  {
   cont++;
  }
 }

return cont;
}

int *remove_ocorencias(int *v, int *n, int k)
{
    int n2;
    n2 = conta_ocorrencias(v,*n,k);
    int *v2 = malloc(n2 * sizeof(int));
    
    int j = 0;
    for(int i=0;i<*n;i++)
    {
        if(v[i] != k)
        {
            v2[j] = v[i];
            j++;
        }
    }
    *n = *n - n2;

    return v2;
}

void main()
{
    int n, k, *v2;
    scanf("%d", &n);

    int *v = malloc(n*sizeof(int));
    
    scanf("%d", &k);
    levetor(v, n);
    
    v2 = remove_ocorencias(v,&n,k);
    
    for(int i=0;i<n;i++)
    {
        ("%d ", v2[i]);
    }
}