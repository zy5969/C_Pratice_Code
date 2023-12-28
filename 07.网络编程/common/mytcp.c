/*************************************************************************
	> File Name: tcp.c
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Dec 2023 08:10:46 PM CST
 ************************************************************************/

#include "head.h"

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
    if(bind(server_listen, (struct sockaddr *)&server, sizeof(server)) < 0) return -1;

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
    if(connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        return -1;
    }
    return sockfd;
}
/*
//定时发送
int socket_connect_timeout(const char *ip, const int port, const long timeout) {
    int sockfd;
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_port = htons(port);//转化为整数
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) return -1;
    make_nonblock(sockfd);
    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = timeout;
    fd_set wfds;
    FD_ZERO(&wfds);
    FD_SET(sockfd, &wfds);
    if(connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        int err = -1;
        int len = sizeof(int);
        int ret = select(sockfd + 1, NULL, &wfds, NULL, &tv);
        if(ret <= 0) {
            close(sockfd);
            return -1;
        } else if(ret) {
            if(getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &err, (socklen_t *)&len) < 0) {
                close(sockfd);
                return -1;
            }
            if(err){
                close(sockfd);
                return -1;
            }
        }
    }
    make_block(sockfd);
    return sockfd;
}
*/

