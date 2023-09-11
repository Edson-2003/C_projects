#include<stdio.h>
#include<stdlib.h>

int* obtemPares(int *vetor, int tamanho, int *tamNovo)
{
 int cont = 0;
 for(int i=0;i<tamanho;i++)
 {
  if(vetor[i] % 2 == 0)
  {
   vetor[cont] = vetor[i];
   cont++;
  }
 }
 *tamNovo = cont;
 int *vf = malloc(cont * sizeof(int));
 
 for(int i=0;i<cont;i++)
 {
  vf[i] = vetor[i];
 }

return vf;
}

int main()
{
 int n, tamNovo;
 scanf("%d", &n);
 int original[n], *novo;
 for(int i=0;i<n;i++)
 {
  scanf("%d", &original[i]);
 }

 novo = obtemPares(original, n, &tamNovo);
 
 for(int i=0;i<tamNovo;i++)
 {
  printf("%d ", novo[i]);
 }
printf("\n");

return 0;
}