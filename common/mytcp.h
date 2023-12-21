/*************************************************************************
	> File Name: mytcp.h
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Dec 2023 08:53:09 PM CST
 ************************************************************************/

#ifndef _MYTCP_H
#define _MYTCP_H
#include <arpa/inet.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int socket_create(int port);
int socket_connect(const char *ip, const int port);
#endif
