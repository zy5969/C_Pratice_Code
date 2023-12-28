/*************************************************************************
	> File Name: myudp.c
	> Author: 
	> Mail: 
	> Created Time: Thu 28 Dec 2023 09:07:12 PM CST
 ************************************************************************/

#include "head.h"

int socket_create_udp(int port){
    int listener;
    if((listener = socket(AF_INET, SOCK_DGRAM, 0)) < 0) return -1;

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(port);
    int reuse = 1;

    setsockopt(listener, SOL_SOCKET, SO_REUSEADDR,&reuse, (socklen_t)sizeof(reuse));

    if(bind(listener, (struct sockaddr *)&server, sizeof(server)) < 0) return -1;

    return listener;
}

int socket_udp(){
    int sockfd;
    if(sockfd = socket(AF_INET, SOCK_DGRAM, 0) < 0) return -1;

    return sockfd;
}

