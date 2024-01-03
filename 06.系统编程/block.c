/*************************************************************************
	> File Name: block.c
	> Author: 
	> Mail: 
	> Created Time: Wed 03 Jan 2024 11:42:09 AM CST
 ************************************************************************/

#include "./common/head.h"

int make_block(int fd){
    int flag;
    if((flag = fcntl(fd, F_GETFL)) < 0) return -1;
    flag &= ~O_NONBLOCK;
    return fcntl(fd, F_SETFL, flag);
}

int make_nonblock(int fd){
    int flag;
    if((flag = fcntl(fd, F_GETFL)) < 0) {
        return -1;
    }
    flag |= O_NONBLOCK;
    return fcntl(fd, F_SETFL, flag);
}


