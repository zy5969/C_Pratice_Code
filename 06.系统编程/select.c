/*************************************************************************
	> File Name: select.c
	> Author: 
	> Mail: 
	> Created Time: Sun 17 Dec 2023 10:13:12 PM CST
 ************************************************************************/

#include<stdio.h>
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
    int ret;
    if((ret = select(1, &rfds, NULL, NULL, &tv)) <= 0) {
        fprintf(stderr, "Nothing read!\n");
    }
    scanf("%d", &age);
    printf("test\n");
    return 0;
}


