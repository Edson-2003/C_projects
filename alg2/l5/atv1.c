#include<stdio.h>

void levetor(int *v, int n)
{
  for(int i=0;i<n;i++)
  {
    scanf("%d", &v[i]);
  }
}

int filtro_par(int n)
{
  return (n % 2) ? 0 : 1;
}
int filtro_impar(int n)
{
  return (n % 2) ? 1 : 0;
}

float media(int v[], int n, int (*funcao_filtro)())
{
  int media = 0, cont = 0;
  for(int i=0;i<n;i++)
  {
    if((*funcao_filtro)(v[i]))
    {
      media = media + v[i];
      cont++;
    }
  }

return ((cont != 0) ? (float)media/cont : 0);
}


void main()
{
  int n;
  scanf("%d", &n);
  int v[n];
  levetor(v, n);

  int (*fpf)(int);
 
  fpf = filtro_par;

  float resultado;
  resultado = media(v, n, fpf);
  printf("%.2f\n", resultado);

  fpf = filtro_impar;
  resultado = media(v, n, fpf);
  printf("%.2f", resultado);
}