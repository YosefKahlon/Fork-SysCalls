//
// Created by kahlon on 04/04/2022.
//
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
#define PORT 3490
#define IP "127.0.0.1"
//
//
//

struct sockaddr_in sockaddrIn;

int open_socket() {

    int socketF = socket(AF_INET, SOCK_STREAM, 0);
    if (socketF == -1) {
        perror("dsd");
    }
    sockaddrIn.sin_family = AF_INET; // IPv4
    sockaddrIn.sin_addr.s_addr = inet_addr(IP);
    sockaddrIn.sin_port = htons(PORT); // host to network
    int con = connect(socketF, (struct sockaddr *) &sockaddrIn, sizeof(sockaddrIn));
    if (con != 0) {
        perror("Connection failed\n");
        close(socketF);
        exit(1);
    }
    printf("Client has Successfully connected with the server\n");


    dup2(socketF, 1);
    struct sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));

    return socketF;


}

int main() {
    char path[256];
    if (getcwd(path, sizeof path) != NULL) {
        printf("Current working directory is: %s \n", getcwd(path, sizeof path));
    } else {
        perror("getcwd()  error\n");
    }
    printf("~~Welcome master \n");
    printf("~~I'm ready to serve you .  \n");

    int sok = -1;
    int status = 1;
    int desc = dup(1); // close stout
    while (1) {
        int valid_cmd = 0;

        char *command = NULL;


        size_t size = 0;

        //s-size_t type to be able to receive value -1 // size of the input  line
        ssize_t line_size = getline(&command, &size, stdin);
        command[line_size - 1] = '\0';


        if (strcmp("EXIT", command) == EQUAL) {
            exit(1);
        } else if (strncmp("ECHO", command, 4) == EQUAL) {
            char *echo;
            echo = (char *) malloc((line_size - 4) * (sizeof(char)));
            for (int i = 5; i < line_size; i++) {
                echo[i - 5] = command[i];
            }
            echo[line_size - 1] = '\0';

            printf("%s\n", echo);
            free(echo);
            valid_cmd = 1;
        } else if (strcmp("DIR", command) == EQUAL) {
            DIR *directory = opendir(path);
            if (directory != NULL) {
                struct dirent *files;
                while ((files = readdir(directory)) != NULL) {
                    printf("%s\n", files->d_name);
                }
                closedir(directory);
            } else {
                perror("Failed at open the directory");
            }
            valid_cmd = 1;
        } else if (strncmp("CD", command, 2) == EQUAL) {
            int chd;
            char *new_path;
            new_path = (char *) malloc(sizeof(path) + sizeof(char) * (strlen(command) - 2));
            for (int i = 0; i < strlen(path); ++i) {
                new_path[i] = path[i];
            }
            new_path[strlen(path)] = '/';
            for (size_t i = strlen(path) + 1, j = 3; j < strlen(command); ++i, ++j) {
                new_path[i] = command[j];
            }
            new_path[strlen(new_path)] = '\0';

            if ((chd = chdir(new_path)) == -1) {

                perror("Error on change directory\n");

            } else {

                printf("the new path is: %s", getcwd(path, sizeof path));
            }

            free(new_path);
            valid_cmd = 1;
        } else if (strcmp("TCP PORT", command) == EQUAL) {
            sok = open_socket();

            if (sok == -1) {

                perror("connection failed  !");
            }
            valid_cmd = 1;
        } else if (strcmp("LOCAL", command) == EQUAL) {
            status = 1;
            printf("Close Connection");
            close(sok);
            dup2(desc, 1);
            valid_cmd = 1;
        }
        if (valid_cmd) {
            printf("\n~~Great choice master, anything else?\n");
        } else {
            printf("\n~~I do not understand that command\n");
        }
    }

    return 0;


}
