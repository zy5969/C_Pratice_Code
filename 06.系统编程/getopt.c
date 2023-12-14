/*************************************************************************
	> File Name: getopt.c
    getopt: 从命令行参数列表中获取选项
    atoi:#include <stdlib.h>
    int atoi(const char *nptr);//字符转换为整数
 ************************************************************************/

//#include <unistd.h>
// #include <stdlib.h>
// #include <stdio.h>
#include "./common/head.h"

int main(int argc, char *argv[]){
    int flags, opt;
    int nsecs, tfnd;
    nsecs = 0;
    tfnd = 0;
    flags = 0;
    while ((opt = getopt(argc, argv, "nt:")) != -1) {
        switch (opt) {
            case 'n': flags = 1; break;
            case 't': nsecs = atoi(optarg); tfnd = 1; break;
            default:fprintf(stderr, "Usage: %s [-t nsecs] [-n] name\n",argv[0]); return 0;
        //  exit(EXIT_FAILURE);
        }
    }

    printf("flags = %d; tfnd = %d; nsecs = %d; optind = %d\n",flags, tfnd, nsecs, optind);

    if (optind >= argc) {
        fprintf(stderr, "Expected argument after options.\n");
        return 0;
      //  exit(EXIT_FAILURE);
    }

    printf("name argument = %s\n", argv[optind]);


//    exit(EXIT_SUCCESS);//结束程序并返回
    return 1;
}

