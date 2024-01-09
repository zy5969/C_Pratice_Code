/*************************************************************************
	> File Name: file.h
	> Author: 
	> Mail: 
	> Created Time: Tue 09 Jan 2024 07:50:39 PM CST
 ************************************************************************/

#ifndef _FILE_H
#define _FILE_H

struct file_message {
    char name[512];
    char buff[4096];
    long size;
};

void send_file(int sockfd, const char *name);
void recv_file(int sockfd);

#endif
