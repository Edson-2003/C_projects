#include<stdio.h>
#include<stdlib.h>

int eh_negativo(int n)
{
  return (n < 0) ? 1 : 0;
}

int eh_positivo(int n)
{
  return (n > 0) ? 1 : 0;
}

int busca_elementos(int *v,int n, int (*pont_f)())
{
  int numero = -1;
  for(int i=0;i<n;i++)
  {
    if((*pont_f)(v[i]))
    {
      numero = i;
      break;
    }
  }
  return (numero != -1) ? numero : -1;
}

int main()
{
 int (*pont_f)(), n;
 scanf("%d", &n);
 int *v = malloc(n * sizeof(int));
 
 for(int i=0;i<n;i++)
 {
  scanf("%d", &v[i]);
 }
 
 int retorno;

 pont_f = eh_negativo;
 retorno = busca_elementos(v, n, pont_f);
 printf("%d ", retorno);

 pont_f = eh_positivo;
 retorno = busca_elementos(v, n, pont_f);
 printf("%d\n", retorno);

return 0;
}
