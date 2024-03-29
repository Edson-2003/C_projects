#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <pthread.h>
#define size 10

int stack[size];
int top = 0;



int
start(int address)
{
  char buffer;
  buffer = 5;
  send(address, buffer, sizeof(buffer), 0);
  recv(address, &buffer, sizeof(buffer), 0);
  while(buffer != 6)
  {
    recv(address, &buffer, sizeof(buffer), 0);
    printf("waitingh connections");
  }
  buffer = 2;
  send(address, buffer, sizeof(buffer), 0);
  return 1;
}

void
send_products(int address)
{
  FILE *fp;
  char file = "products.txt";
  fp = fopen(file, "r");
  //printf("Content-type: text/html");  
  if(start(address))
  {
    char buffer;
    while((buffer = fgetc(fp)) != EOF )
    {
      if(buffer == ";")
      {
        buffer = "\t";
        send(address, buffer, sizeof(buffer),0);
        buffer = 31;
      }
      //buffer = fgetc(fp);
      send(address, buffer, sizeof(buffer),0);
    }
    buffer = 4;
    send(address, buffer, sizeof(buffer),0);
  }
  fclose(fp);
  return;
}
int
main()
{

  //create socket
  int s_sock;
  s_sock = socket(AF_INET, SOCK_STREAM, 0);


  //server address
  struct sockaddr_in s_address;
  s_address.sin_family = AF_INET;
  s_address.sin_port = htons(9002);
  s_address.sin_addr.s_addr = INADDR_ANY;

  //bind
  bind(s_sock, (struct sockaddr*) &s_address, sizeof(s_address));

  listen(s_sock, 5);
  int c_sock;
  c_sock = accept(s_sock, NULL, NULL);

  send_products(c_sock);

  close(s_sock);
  return 0;
}
