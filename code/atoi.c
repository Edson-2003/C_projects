#include <stdio.h>
#include <stdlib.h>


int
mylen(char *str)
{
  int i = 0; 
  while(str[i] != '\0')
  {
    i++;
  }

  return i - 1;
}

int
mypow(int base, int exponent)
{
  if(exponent == 1)
  {
    return base;
  }
  if(exponent == 0)
  {
    return 1;
  }

  int exp = base * base;
  int i = 2;
  while(i != exponent)
  {
    exp = exp * base;
    i++;
  }
  return exp;
};

int
myatoi(char *str)
{
  int len = mylen(str);
  int integer = 0;
  int i = 0;
  int multipler = mypow(10, len);
  while(str[i] != '\0')
  {
    integer = integer + ((str[i] - 48) * multipler);
    multipler = multipler / 10;
    i++;
  }
  printf("%d", integer);
  return integer;
}

int main(int argc, char **argv)
{

  int i = myatoi(argv[1]);
  return 0;
}
