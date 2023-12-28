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
int socket_create_udp(int port);
int socket_udp();

#endif
