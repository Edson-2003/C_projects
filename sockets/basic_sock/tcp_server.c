#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int
main()
{
  char message[256] = "hello word";

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
  socklen_t len = sizeof(struct sockaddr);
  c_sock = accept(s_sock,(struct sockaddr *)&s_address , &len);
  
  printf("%d \n", c_sock);
  char buffer[1024];
  recv(c_sock, buffer, 1024 * sizeof(char), 0);
  send(c_sock, buffer, 1024 * sizeof(char), 0);
  printf("%s \n", buffer);
  
  
  shutdown(s_sock, SHUT_RDWR);
  close(s_sock);
  return 0;
}
