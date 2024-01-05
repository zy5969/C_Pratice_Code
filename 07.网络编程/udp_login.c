/*************************************************************************
	> File Name: udp_login.c
	> Author: 
	> Mail: 
	> Created Time: Thu 04 Jan 2024 07:45:44 PM CST
 ************************************************************************/

#include "./common/head.h"
#include "./common/myudp.h"
#include <arpa/inet.h>

int main(int argc, char **argv) {
    if(argc < 3) return 1;
    char ip[20] = {0};
    int port = -1;
    struct udp_login login;
    bzero(&login, sizeof(login));
    strcpy(ip, argv[1]);
    port = atoi(argv[2]);
    
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(ip);

    int sockfd;
    if((sockfd = socket_udp()) < 0) return 1;

    login.type = UDP_SYN;
    strcpy(login.msg, "hello");
    sendto(sockfd, &login, sizeof(login), 0, (struct sockaddr *)&server, sizeof(server));
    
    recvfrom(sockfd, &login, sizeof(login), 0, NULL, NULL);
    printf("login.msg = %s\n", login.msg);
    
    int ret = connect(sockfd, (struct sockaddr *)&server, sizeof(server));
    printf("ret = %d\n", ret);
    perror("ret");
    
    return 0;
}

