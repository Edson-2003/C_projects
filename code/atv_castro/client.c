#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    int n_socket;
    n_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in s_address;
    s_address.sin_family = AF_INET;
    s_address.sin_port = htons(9002);
    s_address.sin_addr.s_addr = INADDR_ANY; // IP address of the server

    int status;
    status = connect(n_socket, (struct sockaddr*) &s_address, sizeof(s_address));

    if (status == -1) {
        printf("error\n\n");
        return 1;
    }

    char buffer;
    recv(n_socket, &buffer, sizeof(buffer), 0);
    while (buffer != 5) {
        recv(n_socket, &buffer, sizeof(buffer), 0);
    }
    buffer = 5;
    send(n_socket, &buffer, sizeof(buffer), 0);
    while (buffer != 2) {
        recv(n_socket, &buffer, sizeof(buffer), 0);
    }

    while (buffer != 4) {
        recv(n_socket, &buffer, sizeof(buffer), 0);
        printf("%c", buffer);
    }
    close(n_socket);

    return 0;
}
