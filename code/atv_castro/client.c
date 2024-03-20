#include "client.h"

#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <pthread.h>


void show_menu()
{
  printf("\nMenu:\n");
  printf("1. Insert category\n");
  printf("2. Insert item\n");
  printf("3. update category\n");
  printf("4. update item\n");
  printf("5. delet category\n");
  printf("6. delet item\n");
  printf("7. show all items\n");
  printf("8. check-out\n");
}

void global(int address)
{
  show_menu();
  int option;
  scanf("%d", &option);
  char *buffer;
  int size = 256;
  buffer = (char *) malloc(size * sizeof(char));
  switch (buffer)
  {
    case 1:
      printf("write the id");
      getline(&buffer , sizeof(buffer), stdin);
      sts(address, buffer)
      break;
    case 2:
      insert_product();
      break;
    case 3:
      update_category();
      break;
    case 4:
      update_product();
      break;
    case 5:
      delet_category();
      break;
    case 6:
      delet_products();
      break;
    case 7:
      send_products(client->address);
      break;
    case 8:
      return;
      break;
  default:
    return;
  }
}
