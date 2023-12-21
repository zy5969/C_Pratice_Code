/*************************************************************************
	> File Name: tcp.c
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Dec 2023 08:10:46 PM CST
 ************************************************************************/

#include "head.h"
#include "mytcp.h"

int socket_create(int port) {
    int server_listen;
    if(server_listen = socket(AF_INET, SOCK_STREAM, 0) < 0){
        return -1;
    }
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("0.0.0.0");
    int reuse_val = 1;
    setsockopt(server_listen, SOL_SOCKET, SO_REUSEADDR, (void *)&reuse_val, sizeof(int));
    if(bind(server_listen, (struct sockaddr_in *)&server, sizeof(server)) < 0) return -1;

    if(listen(server_listen , 20) < 0) return -1;
    return server_listen;
}

int socket_connect(const char *ip, const int port){
    int sockfd;
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        return -1;
    }
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(ip);
    if(connect(sockfd, (struct sockaddr_in *)&server, sizeof(server)) < 0) {
        return -1;
    }
    return sockfd;
}
