/*************************************************************************
	> File Name: myudp.h
	> Author: 
	> Mail: 
	> Created Time: Thu 28 Dec 2023 09:04:05 PM CST
 ************************************************************************/

#ifndef _MYUDP_H
#define _MYUDP_H
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include "head.h"
struct udp_login {
    int port;//能够反向连回去
    int type;//1,三次握手;
    char msg[512];//传输信息
};

int socket_create_udp(int port);
int socket_udp();
int udp_connect(struct sockaddr_in *addr, int local_port);
int udp_accept(int sockfd, struct sockaddr_in *addr, int local_port);

#endif
