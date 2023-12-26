/*************************************************************************
	> File Name: server.多线程.c
	> Author: 
	> Mail: 
	> Created Time: Tue 26 Dec 2023 08:29:37 PM CST
 ************************************************************************/

#include "./common/head.h"
#include "./common/mytcp.h"
#define MAXUSER 512

void *worker(void *arg) {
    int fd = *(int *)arg;
    while(1){
        char buff[512] = {0};
        size_t rsize = recv(fd, buff, sizeof(buff) - 1, 0);
        if(rsize <= 0) {
            perror("recv");
            close(fd);
            break;
        }
        printf("%s\n", buff);
        send(fd, buff, strlen(buff), 0);
    }
    return NULL;
}   

int main(int argc, char **argv){
    if(argc != 2){
        fprintf(stderr, "Usage : %s port!\n", argv[1]);
        exit(1);
    }
    int server_listen, port = -1;
    int fd[MAXUSER] = {0};
    port = atoi(argv[1]);
    if((server_listen = socket_create(port)) < 0) {
        perror("socket_create");
        exit(1);
    }

    fd_set readfds;
    fd[server_listen] = server_listen;
    int maxfd = server_listen;
    int sockfd;
    while(1){
        FD_ZERO(&readfds);
        for(int i = 3; i < MAXUSER; i++){
            if(fd[i]) FD_SET(fd[i], &readfds);
        }
        int ret = select(maxfd + 1, &readfds, NULL, NULL, NULL);
        if(FD_ISSET(server_listen, &readfds)) {
            struct sockaddr_in client;
            socklen_t len = sizeof(client);
            bzero(&client, len);
            if((sockfd = accept(server_listen, (struct sockaddr *)&client, &len)) < 0) {
                perror("accept");
                exit(1);
            }
            printf("%s : <%d> login!\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
            if(sockfd >= MAXUSER - 5) {
                fprintf(stderr, "Too Many users!\n");
                close(sockfd);
            } else {
                fd[sockfd] = sockfd;
                if(sockfd > maxfd) maxfd = sockfd;
            }
        }
        for(int i = 3; i < MAXUSER; i++){
            if(fd[i] == 0) continue;
            if(fd[i] == server_listen) continue;
            if(FD_ISSET(fd[i], &readfds)) {
                printf("%d is ready!\n", fd[i]);
                char buff[512] = {0};
                size_t rsize = recv(fd[i], buff, sizeof(buff) - 1, 0);
                if(rsize <= 0) {
                    perror("recv");
                    close(fd[i]);
                    fd[i] = 0;
                    continue;
                }
                printf("%s\n", buff);
                send(fd[i], buff, rsize, 0);
            }
        }
    }
    return 0;
}
