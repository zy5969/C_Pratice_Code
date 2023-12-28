/*************************************************************************
	> File Name: mytcp.h
	> Author: 
	> Mail: 
	> Created Time: Thu 28 Dec 2023 07:45:21 PM CST
 ************************************************************************/

#ifndef _MYTCP_H
#define _MYTCP_H
#include "head.h"
int socket_create(int port);
int socket_connect(const char *ip, const int port);
int socket_connect_timeout(const char *ip, const int port, const long timeout);
#endif
