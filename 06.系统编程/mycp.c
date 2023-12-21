/*************************************************************************
	> File Name: mycat.c
	> Author: 
	> Mail:实现复制文件功能 
	> Created Time: Mon 18 Dec 2023 06:44:35 PM CST
 ************************************************************************/

#include<stdio.h>

int main(int argc, char *argv[]){
    //判断传入参数是否合法
    if(argc < 3){
        printf("usage:cmd + originfilename + newfilename\n");
        return 1;
    }
    //打开原文件
    FILE *fd1 = fopen(argv[1], "r+");
    //判断是否打开成功
    if(!fd1){//打开失败
        perror("open originfile");
        return 1;
    }
    //打开复制的文件
    FILE *fd2 = fopen(argv[2], "w+");
    char c;
    while(~(c = fgetc(fd1))) {
        fputc(c, fd2);
     //   fclose(fd1);当前关闭文件只cp文件一个字符
    }

    fclose(fd1);
    fclose(fd2);
    return 0;
}


