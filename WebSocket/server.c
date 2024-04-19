#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>

#include <sys/socket.h>
#include <netinet/in.h>


char *http_response(char *filepath)
{
  FILE *file = fopen(filepath, "r");

  if(file == NULL)
  {
    return(NULL);
  }

  fseek(file, 0, SEEK_END);
  size_t size = ftell(file); 
  rewind(file);

  char *response_content = "HTTP/1.1 200 OK\nServer: Lighting 0.1 Alpha\nContent-Type: text/html; charset=UTF-8";
  char *file_content = calloc(size, sizeof(char));
  fread(file_content, sizeof(char), size, file); 
  char *output = calloc(size + strlen(response_content) + 3, sizeof(char));
  sprintf(output, "%s\n\n%s", response_content, file_content);
  free(file_content);
  return(output);
}


int main()
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

  while(true)
  {
    int c_sock;
    socklen_t len = sizeof(struct sockaddr);
    c_sock = accept(s_sock,(struct sockaddr *)&s_address , &len);
    if(c_sock == -1)
    {
      shutdown(c_sock, SHUT_RDWR);
      close(c_sock);
      continue;
    } 
    printf("%d \n", c_sock);
    char buffer[1024];
    recv(c_sock, buffer, 1024 * sizeof(char), 0);
    //send(c_sock);
    printf("%s \n", buffer);
    char *response = http_response("index.html");
    send(c_sock, response, strlen(response), 0);
  } 
    shutdown(s_sock, SHUT_RDWR);
    close(s_sock);
  

  return 0;
}
