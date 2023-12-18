/*************************************************************************
	> File Name: nonblockread.c
	> Author: 非阻塞从终端读（使用轮询）
	> Mail: 
	> Created Time: Mon 18 Dec 2023 07:21:05 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main() {
    //非阻塞打开终端,打开方式：只读，IO操作设为非阻塞模式
    int fd = open("/dev/tty", O_RDONLY | O_NONBLOCK);
    //是否打开成功
    if(fd < 0) {
        perror("open");
        exit(1);
    }
    ssize_t n;//有符号整型,32位机上等同于int;64位机上等同long int型
    char str[10];
    //轮询机制读取文件
    while(1) { //读取成功
        n = read(fd, str, 10);
        if(n != -1) {
            printf("read %ld bytes\n", n);
            write(STDOUT_FILENO, str, n);//标准输出,非阻塞方式读文件
            break;
        }
        if(errno != EAGAIN) {
            perror("read");
            exit(1);
        }
        //没有输入时打印try
        write(STDOUT_FILENO, "try?\n", 5);
        sleep(1);//延迟1s
    }
    
    close(fd);
    return 0;
}


