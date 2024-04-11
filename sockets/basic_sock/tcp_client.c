#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>


int
main()
{

  //creating a socket
  int n_socket;
  n_socket = socket(AF_INET, SOCK_STREAM, 0);

  //spacefy address for the socket
  struct sockaddr_in s_address;
  s_address.sin_family = AF_INET;
  s_address.sin_port = htons(9002);
  s_address.sin_addr.s_addr = INADDR_ANY;
  
  //conect socket
  int status;
  status = connect(n_socket, (struct sockaddr*) &s_address, sizeof(s_address));
  
  if(status == -1)
  {
    printf("error\n\n");
  }
  
  //recive data from the server
  char response[256] = "teste";
  send(n_socket, &response, sizeof(response), 0);


  printf("response: %s \n\n", response);


  close(n_socket); 

  return 0;
}
