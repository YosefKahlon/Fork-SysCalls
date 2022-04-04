//
// Created by kahlon on 04/04/2022.
//
#include <unistd.h>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "netinet/in.h"
#include "sys/socket.h"

#define EQUAL 0
#define PORT 55001
#define IP "127.0.0.1"



int open_socket(){

    int socketF = socket(AF_INET, SOCK_STREAM,0);
    if (socketF == -1){
        perror("dsd");
    }
    int con =connect(socketF,struct sockaddr *serv_addr ,)



}

int main() {

    int sok =-1;
    int desc = dup(1); // close stout
    while (1) {
        printf("Welcome master \n");
        char path[256];

        if (getcwd(path, sizeof path) != NULL) {
            printf("Current working directory is: %s \n", getcwd(path, sizeof path));
        } else {
            perror("getcwd()  error\n");
        }


        printf("I'm ready to serve you .  \n");
        char *command = NULL;


        size_t size = 0;

        //s-size_t type to be able to receive value -1 // size of the input  line
        ssize_t line_size = getline(&command, &size, stdin);
        command[line_size - 1] = '\0';


        if (strcmp("EXIT", command) == EQUAL) {
            exit(1);
        } else if (strncmp("ECHO", command, 4) == EQUAL) {
            char *echo;
            echo = (char *) malloc((line_size - 5) * (sizeof(char)));
            for (int i = 5; i < line_size; i++) {
                echo[i - 5] = command[i];
            }
            printf("%s\n", echo);
            free(echo);
        }
        else if (strcmp("TCP PORT", command) == EQUAL) {
            sok = open_socket();

            if(sok == -1 ){

                perror("connection failed  !");
            }
        }

    }

    return 0;


}
