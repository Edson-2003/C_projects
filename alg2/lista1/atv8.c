
#include <stdio.h>

float operacoes (char caractere, int n, int v[])
{
  float result;

  for (int i=0; i<n; i++)
  {
    scanf("%d", &v[i]);
  }

    
  float soma = 0;

  if (caractere == '+')
  {
    for (int i=0; i<n; i++)
    {
      soma = soma + v[i];
    }
    result = soma;
  }

  float subtracao = v[0];

  if (caractere == '-')
  {
    for (int i=0; i<n-1; i++)
    {
     subtracao = subtracao - v[i+1];
    }
    result = subtracao;
  }


  float divisao = v[0];
  if (caractere == '/')
  {
    for (int i=0; i<n-1; i++)
    {
      divisao = divisao / v[i+1];
    }
    result = divisao;
  }

  float multiplicacao = 1;

  if (caractere == '*')
  {
    for (int i=0; i<n; i++)
    {
      multiplicacao = multiplicacao * v[i];
    }
    result = multiplicacao;
  }

  printf ("%.2f", result);
  return 0;
}

int main ()
{
  char operacao;
  scanf (" %c", &operacao);
  int n;
  scanf ("%d", &n);
  int v[n];
  operacoes (operacao, n, v);

  return 0;
}

