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
    //printf("I'm a child process\n");
    char *list[] = {"./message", NULL};
    execvp(list[0], list);
  }
  sleep(5);
  return 0;
}
