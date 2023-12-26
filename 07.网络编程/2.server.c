/*************************************************************************
	> File Name: server.c
	> Author: 
	> Mail:多进程 
	> Created Time: Thu 21 Dec 2023 08:25:11 PM CST
 ************************************************************************/

#include "./common/head.h"
#include "./common/mytcp.h"

int main(int argc, char **argv) {
    if(argc < 2) {
        fprintf(stderr, "Usage : %s port\n", argv[0]);
        exit(1);
    }
    int servelisten, sockfd, port = 0;
    port = atoi(argv[1]);
    if((servelisten = socket_create(port)) < 0) {
        perror("socket_create");
        exit(1);
    }

 // 连接
    while(1){
        //
        struct sockaddr_in client;
        memset(&client, 0, sizeof(client));//初始化
        socklen_t len = sizeof(client);
        if((sockfd = accept(servelisten, (struct sockaddr *)&client, &len)) < 0){
            perror("accept");
            exit(1);
        }
        pid_t pid;
        if((pip = fork()) < 0) {
            perror("fork()");
            exit(1);
        }
        //关闭
        if(pid == 0) break;
        close(sockfd);
        printf("<%s : %d> in!\n", inet_ntoa(client.sin_addr),ntohs(client.sin_port));
        char buff[512] = {0};
        size_t rsize = recv(sockfd, buff, sizeof(buff) - 1, 0);
        printf("%s\n", buff);
    }
    //结束
    while(1){
        char buff[512] = {0};
        size_t rsize = recv(sockfd, buff, sizeof(buff) - 1,0);
        if(rsize <= 0){
            perror("recv");
            close(sockfd);
            exit(1);
        }
        send(sockfd, buff, strlen(buff), 0);
        printf("%s\n", buff);
    }
    return 0;
}

