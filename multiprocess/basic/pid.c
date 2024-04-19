#include <stdio.h>
#include <unistd.h>

int 
main()
{
  pid_t pid = fork();
  if(pid > 0)
  {
    printf("I'm parent process\n");
  }
  else
  {
    printf("I'm a child process\n");
  }
  return 0;
}
