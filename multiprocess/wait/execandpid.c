#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int 
main()
{
  int state;
  pid_t pid = fork();
  if(pid > 0)
  {
    printf("I'm parent process\n");
    wait(&state);
  }
  else
  {
    //printf("I'm a child process\n");
    char *list[] = {"./message", NULL};
    execvp(list[0], list);
  }
  //sleep(5);
  return 0;
}
