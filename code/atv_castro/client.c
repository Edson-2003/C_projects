#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

void
options()
{
  printf("chose the option\n\n");
  printf(" 1- \t show the products\n");
  printf(" 2- \t show the categories\n");
  printf(" 3- \t insert new product\n");
  printf(" 4- \t delete product\n"); 
  printf(" 5- \t create new category\n");
  printf(" 6- \t delete categorie\n");
  printf(" 7- \t delete category from the list but not from the database\n"); 
  printf(" 0- \t exit\n");
}

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
  
  printf("waiting connection");
  sleep(1);
  //conect socket
  int status;
  status = connect(n_socket, (struct sockaddr*) &s_address, sizeof(s_address));
   
  if(status == -1)
  {
    printf("connection error \n\n");
  }
  
  printf("connected");

  int option = -1;

  while(option != 0)
  {
    system("clear");
    options();
    scanf("%d", &option);
    switch(option)
    {
      case 1:
        if(send(n_socket, "1", sizeof("1"), 0) == -1)
        {
          printf("comunication error");
          break;
        }
        char responsei[256];
        recv(n_socket, &response, sizeof(response), 0);
        if(response[0] == 0b00000001)
        {
          if(send(n_socket, "1", sizeof("1"), 0 == -1))
          {
            printf("comunication error");
            break;
          }
          while(response[0] != 0b00000100)
          {
              
          }
        }
        //recive data from the server
        recv(n_socket, &response, sizeof(response), 0);
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        break;
      case 5:
        break;
      case 6:
        break;
      case 7:
        break;
      case 0:
        option = 0
        break;
      default:
        printf("exiting bye \n");
        sleep(10);
        break;
    }
  }
  
  


  //recive data from the server
  char response[256];
  recv(n_socket, &response, sizeof(response), 0);


  printf("response: %s \n\n", response);

}
