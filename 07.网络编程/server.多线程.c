/*************************************************************************
	> File Name: server.多线程.c
	> Author: 
	> Mail: 
	> Created Time: Tue 26 Dec 2023 08:29:37 PM CST
 ************************************************************************/

#include "./common/head.h"
#include "./common/mytcp.h"

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
    port = atoi(argv[1]);
    if((server_listen = socket_create(port)) < 0) {
        perror("socket_create");
        exit(1);
    }
    while(1){
        int sockfd;
        struct sockaddr_in client;
        socklen_t len = sizeof(client);
        bzero(&client, len);
        if((sockfd = accept(server_listen, (struct sockaddr *)&client, &len)) < 0) {
            perror("accept");
            exit(1);
        }
        pthread_t tid;
        pthread_create(&tid, NULL, worker, (void *)&sockfd);
    }
    return 0;
}
