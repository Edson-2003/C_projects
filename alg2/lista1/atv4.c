#include<stdio.h>
#include<stdbool.h>

int primo(int n)
{
  bool result = true;
  for(int i = 2; i < n; i++)
  {
    if(n % i == 0)
    {
      result = false;
    }
  }
  return result;
}

void main()
{
  for(int i = 0; i != -1; )
  { 
    scanf("%d", &i);

    if(i != -1)
    {
      printf("%d\n", primo(i));
    }
  }

}