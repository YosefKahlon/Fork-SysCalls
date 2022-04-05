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
#define PORT 54321
#define IP "127.0.0.1"

struct sockaddr_in sockaddrIn, client;

int main(int argc, char *argv[]) {
    printf("Hello world\n");
    int sockaddlen = sizeof(sockaddrIn);
    char client_msg[1024] = {0}; // '\0'
    int socketS = socket(AF_INET, SOCK_STREAM, 0);
    if (socketS == -1) {
        perror("dsd\n");
    }
    sockaddrIn.sin_family = AF_INET; // IPv4
    sockaddrIn.sin_addr.s_addr = INADDR_ANY;
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

    while (1) {

        int lis = listen(socketS, 3);
        if (lis == -1) {
            perror("Listen failed\n");
            exit(1);
        }

        int c_len = sizeof(client);
        int c_sock = accept(socketS, (struct sockaddr *) &sockaddrIn, (socklen_t *) &sockaddlen);
        if (c_sock != -1) {
            printf("Successfully connected to the server\n");
//            ssize_t message = send(socketS, msg, strlen(msg), 0);
        } else {
            printf("Failed to connected to the server\n");
//            ssize_t message = send(socketS, msg, strlen(msg), 0);
            exit(1);
        }

        while (1) {
//            printf("DAMN\n");
            memset(client_msg, 0, 1024);
            size_t r = read(c_sock, client_msg, sizeof(client_msg));
            if (r != 0) {
                printf("%s\n", client_msg);
            } else {
                break;
            }
        }
    }
//    close(socketS);

}

