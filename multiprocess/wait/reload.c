#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

struct process_control_t
{
  const char *name;
  const char *args;
  pid_t pid;
};

static struct process_control_t processes[] = 
{
  {.name = "./message", .args = "process child one", .pid = -1},
  {.name = "./message", .args = "procces child two", .pid = -1},
};

static int process_amount = sizeof(processes) / sizeof(processes [0]);

pid_t
process_control_launch(int index)
{
  pid_t pid = fork();
  if(pid == 0)
  {
    char *list[] = {processes[index].name, processes[index].args, NULL};
    execvp(list[0], list);
  }
  return pid;
}

void
process_control_scan(pid_t pid)
{
  for(int i = 0; i < process_amount; i++)
  {
    if(pid == processes[i]. pid)
    {
      printf("relaunchind %s / %s \n", processes[i].name, processes[i].args);
      processes[i].pid = process_control_launch(i);
      break;
    }
  }
}

int 
main()
{
  int state;
  pid_t pid;
  for(int i = 0; i <process_amount; i++)
  {
    processes[i].pid = process_control_launch(i);
  }

  while(1)
  {
    pid = wait(&state);
    process_control_scan(pid);
  }
  return 0;
}
