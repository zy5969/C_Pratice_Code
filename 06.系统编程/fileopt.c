/*************************************************************************
	> File Name: fileopt.c
	> Author: 
	> Mail: 
	> Created Time: Mon 18 Dec 2023 08:46:08 PM CST
 ************************************************************************/

#include<stdio.h>

int main(void){
    
    FILE *fd = fopen("./test.txt", "a");//文件名,追加方式写入文件
    
    fputc('A', fd);
    fputc('B', fd);
    fputc('C', fd);
    
    fclose(fd);
    return 0;
}

