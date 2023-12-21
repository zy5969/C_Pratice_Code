/*************************************************************************
	> File Name: server.c
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Dec 2023 08:25:11 PM CST
 ************************************************************************/

#include "./common/head.h"
#include "./common/mytcp.h"

int main(int argc, char **argv) {
    if(argc < 2) {
        fprintf(stderr, "Usage : %s port\n", argv[0]);
        exit(1);
    }
    int servelisten, port = 0;
    port = atoi(argv[1]);
    if((servelisten = socket_create(port)) < 0) {
        perror("socket_create");
        exit(1);
    }

    int new_fd;
    if((new_fd = accept(servelisten, NULL, NULL)) < 0){
        perror("accept");
        exit(1);
    }
 //   DBG()
    while(1){
        char str[512] = {0};
      //  recv(new_fd, str, 511, 0);
        read(new_fd, str, 511);
        printf("%s\n", str);//必须换行，结束一次接收
    }
    return 0;
}

