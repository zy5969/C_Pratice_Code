/*************************************************************************
	> File Name: file.server.c
	> Author: 
	> Mail: 
	> Created Time: Tue 09 Jan 2024 09:20:05 PM CST
 ************************************************************************/

#include "./common/head.h"

int main(int argc, char **argv) {
    if(argc != 2) exit(1);
    int server_listen = 0, sockfd;
    
    if((server_listen = socket_create(atoi(argv[1]))) < 0) {
        perror("socket_creat");
        exit(1);
    }

    while(1) {
        if((sockfd = accept(server_listen, NULL, NULL)) < 0) {
            perror("accept");
            exit(1);
        }
        pid_t pid;
        if((pid = fork()) < 0) {
            perror("fork");
            exit(1);
        }
        if(pid == 0) {
            recv_file(sockfd);
            break;
        }
        close(sockfd);
    }

    return 0;
}

