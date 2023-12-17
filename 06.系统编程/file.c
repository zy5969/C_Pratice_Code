/********************************************
	> File Name: file.c
	文件操作 
 ********************************************/

#include "./common/head.h"

int main(int argc, char **argv) {
    //初步处理，传入参数符合
    if(argc != 3) {
        fprintf(stderr, "Usage : %s file1 file2\n", argv[0]);
        exit(1);
    }
    if(argv[1] == argv[2]) {
        fprintf(stderr, "Usage : file1 and file2 not to same");
        exit(1);
    }
    int fd_in, fd_out;//操作结果
    char str[10] = {0};
    //文件打开，O_RDONLY方式
    if((fd_in = open(argv[1], O_RDONLY)) == -1) {
        perror("open");//printf("open erorr");
        exit(1);//return 1;
    }
    //O_CREAT，文件不存在，新建文件并提供第三个参数
    //O_EXCL，文件已存在，open()调用失败
    //O_APPEND,追加方式写入文件，O_RDWR,文件打开可读可写
    if((fd_out = open(argv[2], O_RDWR | O_APPEND, 0644)) < 0) {
        perror("out file");//printf("out file erorr");
        exit(1);//return 1;return在子函数中结束当前函数
    }
    //读取文件，写入文件
    while(1){
        int ret = read(fd_in, str, sizeof(str) - 1);
        int writs = write(fd_out, str, sizeof(str) - 1);//文件1写入文件2
        if(ret < 0) {
            perror("read");//错误前面的词read
            exit(1);//退出当前进程
        }
        if(ret < 0) {
            perror("read");
            exit(1);
        }
        if(ret == 0) break;
        printf("%s\n", str);
        memset(str, 0, sizeof(str));
    }
    //关闭文件
    close(fd_in);
    close(fd_out);
    return 0;
}


