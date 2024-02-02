#include<stdio.h>

int main()
{
  int l, c;
  scanf("%d %d", &c, &l);

  int v[l][c];

    //diagonal principal
    for(int i=0;i<l;i++)
    {
      v[i][i]=0;
      for(int j=i+1;j<c;j++)
      {
        v[i][j]=-1;
      }
      for(int m=i+1;m<l;m++)
      {
        v[m][i]=1;
      }
    }
    
    for(int i=0;i<c;i++)
    {
     for(int j=0;j<l;j++)
     {
      printf("%d ",v[j][i]);
     }
     printf("\n");
    }
return 0;
}