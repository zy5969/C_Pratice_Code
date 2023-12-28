/*************************************************************************
	> File Name: udp_server.c
	> Author: 
	> Mail: 
	> Created Time: Thu 28 Dec 2023 09:29:50 PM CST
 ************************************************************************/

#include "./common/head.h"
#include "./common/myudp.h"

int main(int argc, char **argv) {
    int listener, port = -1;
    if(argc != 2) {
        fprintf(stderr, "Usage: %s port!\n", argv[0]);
        exit(1);
    }

    port = atoi(argv[1]);
    if((listener = socket_create_udp(port)) < 0) {
        perror("socket_create_udp");
        exit(1);
    }

    while(1){
        char buff[4096] = {0}; //8k
        recvfrom(listener, buff, sizeof(buff) - 1, 0, NULL, NULL);
        printf("%s\n", buff);
    }
    return 0;
}


