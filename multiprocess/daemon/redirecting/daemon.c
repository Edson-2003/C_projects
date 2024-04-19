#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <syslog.h>
#include <unistd.h>

void
logger(FILE * fp, char c)
{
  //openlog("daemon", LOG_PID | LOG_CONS, LOG_USER);
  //syslog(LOG_INFO, "Counter %c", id);
  //closelog();i
    putc((int )c, fp);
}


int main()
{
  int i = 0;
  FILE * fp;
  fp = fopen("teste.txt", "a+");
  daemon(1,1);

  while(1)
  {
    sleep(1);
    char d = getc(stdin);
    logger(fp, d);
  }
  return 0;
}
