/*************************************************************************
	> File Name: mycat.c
	> Author: 
	> Mail: 
	> Created Time: Mon 18 Dec 2023 06:44:35 PM CST
 ************************************************************************/

#include<stdio.h>

int main(int argc, char *argv[]){
    //判断传入参数是否合法
    if(argc < 2){
        printf("usage:cmd + filename\n");
        return 1;
    }
    //打开文件
    FILE *fd = fopen(argv[1], "r");
    //判断是否打开成功
    if(!fd){//打开失败
        perror("open file");
        return 1;
    }
 //   int i;
    char c;
    //fgetc,从给定输入流中读取下一个字符,返回一个字符,失败时返回EOF
    while(~(c = fgetc(fd))) {
        printf("%c", c);
    }
    fclose(fd);
    return 0;
}


