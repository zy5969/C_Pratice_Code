/*************************************************************************
	> File Name: udp_server.c
	> Author: 
	> Mail: 
	> Created Time: Thu 28 Dec 2023 09:29:50 PM CST
 ************************************************************************/

#include "./common/head.h"
#include "./common/myudp.h"

int main(int argc, char **argv) {
    if(argc != 2) {
        fprintf(stderr, "Usage: %s port!\n", argv[0]);
        exit(1);
    }

    int listener, port = -1;
    struct sockaddr_in client;
    port = atoi(argv[1]);
    
    if((listener = socket_create_udp(port)) < 0) {
        perror("socket_create_udp");
        exit(1);
    }

    while(1){
        udp_accept(listener, &client, port);
    }
    return 0;
}


