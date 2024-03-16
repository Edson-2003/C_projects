#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

struct client
{
  int 
};




int
main()
{
  char message[256] = "hello form server";

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

  send(c_sock, message, sizeof(message), 0);

  close(s_sock);
  return 0;
}
