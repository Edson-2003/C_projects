#include<stdio.h>
#include<stdlib.h>

int quadrado(int n)
{
 return (n*n);
}

int cubo(int n)
{
 return (n*n*n);
}

int *atualiza_vetor(int *v,int n,int (*qtf)())
{
  if(v[0] > 0)
  {
    qtf = cubo;
    for(int i=0;i<n;i++)
    {
     v[i] = (*qtf)(v[i]); 
    }
  }
  
  if(v[0] < 0)
  {
    qtf = quadrado;
    for(int i=0;i<n;i++)
    {        
     v[i] = (*qtf)(v[i]);
    }
  }
return v;
}

int main()
{
 int n, (*qtf)();
 scanf("%d", &n);
 int *v = malloc(n*sizeof(int));
 
 for(int i=0;i<n;i++)
 {
  scanf("%d", &v[i]);
 }
 
 v = atualiza_vetor(v,n,qtf);

 for(int i=0;i<n;i++)
 {
  printf("%d ", v[i]);
 }
 printf("\n");

return 0;
}
