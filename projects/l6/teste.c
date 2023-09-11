#include<stdio.h>
#include<stdlib.h>


int main()
{
  int n,j=0;
  scanf("%d", &n);
  int v[n], aux=n;
  int v2[aux];
for(int i=0;i<n;i++)//declara v1
 {
  printf("v[%d]=", i);
  scanf("%d", &v[i]);
 }
for(int i=0;i<n;i++)//declara v2
 {
  printf("v2[%d]=", i);
  scanf("%d", &v2[i]);
 }

for(int i=0;i<aux;i++)
{
 if(n>=aux)
 {
  v[n]=v2[j];
  j++;
 }
 n++;

}


for(int i=0;i<n;i++) printf("%d ",v[i]);



return 0;
}