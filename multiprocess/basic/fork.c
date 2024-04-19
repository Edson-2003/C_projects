#include <stdio.h>
#include <unistd.h>

int 
main()
{
  fork();
  printf("hello word\n");
  return 0;
}
