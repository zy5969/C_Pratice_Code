/*************************************************************************
	> File Name: fileopt.c
	> Author: 
	> Mail: 
	> Created Time: Mon 18 Dec 2023 08:46:08 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
    
    FILE *fd = fopen(argv[1], "r");//文件名, read
    if(!fd) {
        perror("open");
        exit(1);
    }
    
    fseek(fd, 0, SEEK_END);//0移动指示器位置到开始、末尾、当前
    printf("size = %ld\n", ftell(fd));//返回当前读写位置的偏移量
    fclose(fd);
    return 0;
}

