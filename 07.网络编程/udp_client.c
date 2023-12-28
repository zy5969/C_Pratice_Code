/*************************************************************************
	> File Name: udp_client.c
	> Author: 
	> Mail: 
	> Created Time: Thu 28 Dec 2023 09:33:51 PM CST
 ************************************************************************/

#include "./common/head.h"
#include "./common/myudp.h"

int main(int argc, char **argv) {
    if(argc != 3) exit(1);
    char ip[20] = {0};
    int port = -1, sockfd;
    strcpy(ip, argv[1]);
    port = atoi(argv[2]);
    
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_port = htons(port);

    if((sockfd = socket_udp()) < 0) {
        perror("socket_udp");
        exit(1);
    }

    while(1){
        char buff[512] = {0};
        scanf("%s", buff);
        if(!strlen(buff)) continue;
        sendto(sockfd, buff, strlen(buff), 0, (struct sockaddr *)&server, sizeof(server));
    }
    return 0;
}


