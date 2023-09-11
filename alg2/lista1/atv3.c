#include<stdio.h>

int contardigitos(int a)
{
  int result=0;
  while(a > 0)
  {
    a = a /10;
    result++;
  }


return result;
}

void main()
{
  int n;
  scanf("%d", &n);
  printf("%d\n", contardigitos(n));

}