#include <stdio.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{

  char *message = "default";
  if(argc > 1)
  {
    message = argv[1];
  }

  printf("%s\n", message);
  return 0;
}
