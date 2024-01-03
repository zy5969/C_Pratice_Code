/*************************************************************************
	> File Name: select.c
	> Author: 
	> Mail: 
	> Created Time: Sun 17 Dec 2023 10:13:12 PM CST
 ************************************************************************/

#include "./common/head.h"
#include "block.h"
#include <sys/select.h>

int main() {
    int age = 18;
    fd_set rfds;
    make_nonblock(0);
    
    struct timeval tv;
    tv.tv_sec = 30;
    tv.tv_usec = 0;
    
    FD_ZERO(&rfds);
    FD_SET(0, &rfds);
    while(1){
    FD_SET(0, &rfds);
        int ret = select(1, &rfds, NULL, NULL, &tv); 
        if(ret <= 0) continue;
        if(FD_ISSET(0, &rfds)) scanf("%d", &age);
        printf("age = %d\n", age);
    }
    return 0;
}


