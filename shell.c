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
#include <sys/wait.h>

#define EQUAL 0
#define PORT 54322
#define IP "127.0.0.1"


struct sockaddr_in sockaddrIn;

/**
 * Open TCP socket to conttion with the server
 * @return TCP socket
 */
int open_socket() {

    int socketF = socket(AF_INET, SOCK_STREAM, 0);
    if (socketF == -1) {
        perror("Failed with open socket \n");
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

    //get the current directory path of this project
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

        //kill this processes
        if (strcmp("EXIT", command) == EQUAL) {
            exit(1);

            // print to output the text after ECHO
        } else if (strncmp("ECHO", command, 4) == EQUAL) {
            printf(" echo pid =  %d\n", getpid());


            char *echo;
            echo = (char *) malloc((line_size - 4) * (sizeof(char)));
            //copy the text from the right position
            for (int i = 5; i < line_size; i++) {
                echo[i - 5] = command[i];
            }
            echo[line_size - 1] = '\0';
            printf("%s\n", echo);
            free(echo);
            valid_cmd = 1;

            // print to output all the file in the current directory
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

            //changing  the position to command
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


            //change output to server
        } else if (strcmp("TCP PORT", command) == EQUAL) {
            sok = open_socket();
            if (sok == -1) {
                perror("connection failed  !");
            }
            valid_cmd = 1;

            // close the socket with the server
            // return output to this shell
        } else if (strcmp("LOCAL", command) == EQUAL) {
            status = 1;
            printf("Close Connection");
            dup2(desc, 1);
            close(sok);
            valid_cmd = 1;
        } else if (strncmp("COPY", command, 4) == EQUAL) {
            char *src;
            char *dest;
            int counter = 0;

            //skip space
            int j = 5;

            //count space for size of src dir
            while (j < line_size && command[j] != ' ') {
                counter++;
                j++;
            }

            src = (char *) malloc(counter * sizeof(char));
            counter = 0;
            //copy name of src
            for (int i = 5; i < j; i++, counter++) {
                src[counter] = command[i];
            }
            src[counter] = '\0';
            counter = 0;
            //skip space
            j++;
            int temp = j;
            //count space for size of dest dir
            while (j < line_size) {
                j++;
                counter++;
            }

            dest = (char *) malloc(counter * sizeof(char));
            dest[counter] = '\0';
            counter = 0;
            //copy name of dest
            for (int i = temp; i < line_size; i++, counter++) {
                dest[counter] = command[i];
            }


            //open file to read
            FILE *file_src = fopen(src, "rb");
            if (file_src == NULL) {
                printf("Cannot open file %s \n", src);
                exit(0);
            }

            //create file to write
            FILE *file_dest = fopen(dest, "wb");
            if (file_dest == NULL) {
                printf("Cannot open file %s \n", dest);
                exit(0);
            }
            char c;
            // read from fhe src
            // char by char
            while (fread(&c, 1, 1, file_src) == 1) {

                //write to dest file
                fwrite(&c, 1, 1, file_dest);
            }


            fclose(file_src);
            fclose(file_dest);


            free(src);
            free(dest);
            valid_cmd = 1;
        }

            //delete file from directory
        else if (strncmp("DELETE", command, 6) == EQUAL) {
            char *fileName;
            fileName = (char *) malloc((line_size - 6) * sizeof(char));
            for (int i = 7; i < line_size; i++) {
                fileName[i - 7] = command[i];
            }

            if (unlink(fileName) == -1) {
                perror("Cannot delete the file !\n");
            }

            free(fileName);
            valid_cmd = 1;
        }


            //TODO
        else {

            int pid = fork();
            if (pid == -1) {
                printf(" the child is not born\n");
                exit(1);
            } else if (pid == 0) {
                char *binaryPath = "/bin/ls";
                char *arg1 = "-lh";
                char *arg2 = "/home";

                execl(binaryPath, binaryPath, arg1,arg2, NULL);

//
//                if (execl(, "sh", "-c", command, (char *) NULL) == -1) {
//                    printf(" ll hello from pid =  %d\n", getpid());
//                    printf(" execl filed\n");
//                    exit(1);
            } else {
                wait(NULL);
            }
        }


        if (valid_cmd) {
            printf("\n~~Great choice master, anything else?\n");
        } else {
            printf("\n~~I do not understand that command\n");
        }

    }

    return 0;


}