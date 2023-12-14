/*************************************************************************
	> File Name: opt.c
	> Author: 
	> Mail: 
	> Created Time: Thu 14 Dec 2023 10:31:26 AM CST
 ************************************************************************/

#include "./common/head.h"

int main(int argc, char **argv) {
    char output[20] = {0};
    char intput[20] = {0};
    if(argc < 2) {
        fprintf(stderr, "Usage : %s -o file\n", argv[0]);
        exit(1);//return 1;
    }
    int opt;
    //o与文件名可空格，可不空；加上":O"不能空格
    while((opt = getopt(argc, argv, "o:")) != -1) {
        switch(opt){
            case 'o': 
            case 'O': strcpy(output, optarg); break;//可大写可小写
            default:fprintf(stderr, "Usage : %s -o file", argv[0]);exit(1);
        }
    }
    printf("intput file = %s\n", argv[optind]);
    printf("output = %s\n", output);
    return 0;
}


