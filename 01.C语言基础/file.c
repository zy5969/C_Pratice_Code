#include<stdio.h>
#include<string.h>
#define MAX_N 100
//int MAX_N = 100;

int main() {
    char filename[255] = {0};
    char w_file[256] = {0};
    scanf("%s%s", filename, w_file);
    FILE *fin = fopen(filename, "rb");//'b',二进制相关
    FILE *fout = fopen(w_file,"wb");  //*"a"在文件中追加另一个文件的内容，”w"覆盖原内容*
    //判断是否打开
    if(fin == NULL) {
        printf("err\n");
        return 0;
    }
    char buff[MAX_N + 1] = {0};    //临时数组,+1防止读取时出现乱码
    while(feof(fin) == 0) {
    memset(buff, 0, sizeof(buff));  //初始化
    int size = fread(buff, sizeof(char), MAX_N, fin);
    fwrite(buff, sizeof(char), size, fout);   //sizeof获取内存空间
}

fclose(fin);
fclose(fout);
return 0;
}
