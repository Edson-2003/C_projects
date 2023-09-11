#include<stdio.h>

void par(int a)
{
  if((a % 2 == 0)&&(a >= 0))
  {
    printf("PAR");
  }
  if((a % 2 != 0)&&(a >= 0))
  {
    printf("IMPAR");
  }
}


void main()
{
  for(int i = 0; i >= 0; ){
    scanf("%d\n", &i);
    par(i);
  
  }

}