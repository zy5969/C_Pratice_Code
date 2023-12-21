/*************************************************************************
	> File Name: client.c
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Dec 2023 08:54:39 PM CST
 ************************************************************************/

#include "./common/head.h"
#include "./common/mytcp.h"

int main(int argc, char **argv) {
    if(argc < 3){
        fprintf(stderr, "Usage : %s ip port\n", argv[0]);
        exit(1);
    }
    //接收连接
    int sockfd;
    if((sockfd = socket_connect(argv[1], atoi(argv[2]))) < 0){
        perror("socket_connect");
        exit(1);
    }
    while(1){
        char buff[512] = {0};
        scanf("%[^\n]", buff);
        if(strlen(buff)){
            send(sockfd, buff, strlen(buff), 0);
        }
    }
    return 0;
}

