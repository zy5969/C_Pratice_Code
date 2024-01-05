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

int udp_connect(struct sockaddr_in *addr, int local_port) {
    int sockfd;
    if((sockfd = socket_create_udp(local_port)) < 0) return -1;

    if(connect(sockfd, (struct sockaddr *)addr, sizeof(struct sockaddr_in)) < 0) return -1;

    return sockfd;
}

//三次握手
int udp_accept(int sockfd, struct sockaddr_in *addr, int local_port){
    int newfd;
    struct udp_login login;
    bzero(&login, sizeof(login));
    socklen_t len = sizeof(struct sockaddr);
    //1
    ssize_t rsize = recvfrom(sockfd, &login, sizeof(login), 0, (struct sockaddr *)addr, &len);
    if(rsize != sizeof(login)) return -1;
    
    if(login.type & UDP_SYN) {
        printf("client %s:%d want to login : %s!\n", inet_ntoa(addr->sin_addr), addr->sin_port, login.msg);
        login.type |= UDP_ACK;
        bzero(login.msg, sizeof(login.msg));
        strcpy(login.msg, "SYN reced!\n");
        //2
        sendto(sockfd, &login, sizeof(login), 0, (struct sockaddr *)addr, len);
    } else {
        printf("Error , Not UDP_SYN!\n");
        return -1;
    } 

    if((newfd = udp_connect(addr, local_port)) < 0) return -1;
    //3
    printf("newfd got a %d\n", newfd);

    recv(newfd, &login, sizeof(login), 0);
    printf("newfd --> %s\n", login.msg);
    return newfd;
}

