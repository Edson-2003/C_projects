#include<stdio.h>
#include<stdlib.h>

int main() {
  int n, i, x, repetiu;
//elementos do vetor
  scanf("%d", &n);
  int v[n];

 for(i=0;i<n;i++)
 {
   printf("insira os valores do vetor: ");
   scanf("%d", &v[i]);

 }
 
 for(i=0;i<n;i++)
 {
  repetiu=0;

  for(x=0;x<i;x++)
  {
    if(v[i]==v[x])
    {
     repetiu=1;
     break;
    } 
  }
 
   if(repetiu == 0)
   printf("%d", v[i]);
 
 }
  printf("\n");
 
 return 0;
}