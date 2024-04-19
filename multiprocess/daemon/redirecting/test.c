#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
//#include <sys/process.h>


int main()
{
  int fd = open("/dev/tty2", O_RDONLY);
  if(fd <0)
  {
    return -1;
  }
  struct termios mytty;
  char *arr[] = 
  {
    "ls",
    NULL,
  };
  execvp("/dev/pts/0", arr);
  return 0;
}
