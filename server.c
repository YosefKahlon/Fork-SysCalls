#include <unistd.h>
#include "stdio.h"
#include "stdlib.h"
#include <string.h>
#include "netinet/in.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <dirent.h>
#include <arpa/inet.h>

#define EQUAL 0
#define PORT 55006
#define IP "127.0.0.1"

struct sockaddr_in sockaddrIn, client;

int main() {
    printf("Hello world\n");
    int socketS = socket(AF_INET, SOCK_STREAM, 0);
    if (socketS == -1) {
        perror("dsd\n");
    }
    sockaddrIn.sin_family = AF_INET; // IPv4
    sockaddrIn.sin_addr.s_addr = htonl(INADDR_ANY);
    sockaddrIn.sin_port = htons(PORT); // host to network

    int bin = bind(socketS, (struct sockaddr *) &sockaddrIn, sizeof(sockaddrIn));
    if (bin == -1) {
        perror("Failed to bind server\n");
        exit(1);
    }

    int yes = 1;
    if (setsockopt(socketS, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof yes) == -1) {
        perror("setsockopt Error\n");
        exit(1);
    }

    int lis = listen(socketS, 1);
    if (lis == -1) {
        perror("Listen failed\n");
        exit(1);
    }

    for (;;) {
        int c_len = sizeof(client);
        int ac = accept(socketS, (struct sockaddr *) &client, (socklen_t *) &c_len);
        if (ac != -1) {
            printf("Successfully connected to the server\n");
//            ssize_t message = send(socketS, msg, strlen(msg), 0);
        } else {
            printf("Failed to connected to the server\n");
//            ssize_t message = send(socketS, msg, strlen(msg), 0);
            exit(1);
        }
        char client_msg[1024];
        while (read(socketS, client_msg, sizeof(client_msg))) {
//            printf("DAMN\n");
            client_msg[strlen(client_msg) - 1] = '\0';
            if (strcmp(client_msg, "close") == EQUAL) {
                close(socketS);
                exit(0);
            }
            if (strlen(client_msg) > 1) {
                printf("%s\n", client_msg);
            }
            bzero(client_msg, 1024);

        }
        close(socketS);
    }


}

