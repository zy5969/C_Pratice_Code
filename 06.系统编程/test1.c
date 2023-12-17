/********************************************
	> File Name: test1.c
**********************************************/

#include "./common/head.h"


void do_ls(const char *str);
void do_stat(const char *str);
void showinfo(const char *str, struct stat *st);
void mode_str(mode_t mode, char *str);

int a_flag = 0, l_flag = 0;
int dir_num = 0;

int main(int argc, char **argv) {
    int opt;//从参数列表中获取选项
    while((opt = getopt(argc, argv, "al")) != -1) {
        //处理选项
        switch(opt){
            case 'a': a_flag = 1; break;
            case 'l': l_flag = 1; break;
            default: 
                fprintf(stderr, "Usage: %s [-al] [args...]\n", argv[0]);
                exit(1);
            
        }    
    }
    //剔除选项, 获取参数, optind,选项个数
    argc -= (optind - 1);
    argv += (optind - 1);
    DBG("argc = %d, argv[1] = %s\n", argc, argv[1]);
    
    if(argc == 1) {
        do_ls("."); //打印当前目录
    } else {
        for(int i = 1; i < argc; i++){
            do_ls(argv[i]);
        }
    }
    return 0;
}

//处理参数/选项
void do_ls(const char *str){
    DBG("%s\n", str);//输出传入的字符
    //判断是否是目录,打开目录opendir()
    DIR *dir = NULL;
    struct dirent *direntp;
    if((dir = opendir(str)) == NULL) { //目录指针到达末尾或出现错误时返回NULL
        DBG("open error\n");
        //确定文件或目录访问权限,指定存取方式有效返回0，否则-1,R_OK是否可读
        if(access(str, R_OK) == 0) { 
            if(l_flag == 1) do_stat(str);//处理文件信息
            else printf("%s\n", str);
        }
    }
    else { 
        DBG("open sucess!\n");//目录打开成功
        //读入目录内容,readdir(),
        if(dir_num > 1) printf("%s\n", str);
        while((direntp = readdir(dir))){ //成功读取，失败NULL
            if(a_flag == 0 && direntp->d_name[0] == '.') continue;
            if(l_flag == 1) do_stat(direntp->d_name);//传入文件名
        }
    }
    return ;
}

//通过传入文件名获取文件信息并保存在buf所指的结构体stat中，
//成功返回0，失败-1
void do_stat(const char *str){ 
    DBG("%s\n", str);//输出传入的字符
    struct stat std;//stat结构体描述文件属性
    if(lstat(str, &std) < 0) { //获取文件信息，成功返回0，失败-1
        perror(str);
        exit(1);
    }
    DBG("uid = %d\n", std.st_uid);//打印输出用户ID
    showinfo(str, &std);//打印参数

}

//st_mode(文件类型信息) 成员转换为字符
void mode_str(mode_t mode, char *str){
    //文件类型
    if(S_ISREG(mode)) str[0] = '-';//普通文件
    if(S_ISDIR(mode)) str[0] = 'd';//目录文件
    if(S_ISSOCK(mode)) str[0] = 's';//套接字
    if(S_ISFIFO(mode)) str[0] = 'p';//FIFO
    if(S_ISLNK(mode)) str[0] = 'l';//符号链接
    if(S_ISCHR(mode)) str[0] = 'c';//块特殊文件
    if(S_ISBLK(mode)) str[0] = 'b';//字符特殊文件
    
    //文件权限:读、写、执行
    if (mode & S_IRUSR) str[1] = 'r';
    if (mode & S_IWUSR) str[2] = 'w';
    if (mode & S_IXUSR) str[3] = 'x';

    if (mode & S_IRGRP) str[4] = 'r';
    if (mode & S_IWGRP) str[5] = 'w';
    if (mode & S_IXGRP) str[6] = 'x';
    
    if (mode & S_IROTH) str[7] = 'r';
    if (mode & S_IWOTH) str[8] = 'w';
    if (mode & S_IXOTH) str[9] = 'x';
}

//获取创建文件的用户名
char *uid_name(uid_t uid) {
    struct passwd *pw;
    static char tmpname[20] = {0};
    if ((pw = getpwuid(uid)) == NULL) {
        sprintf(tmpname, "%d", uid); //获取失败输出文件用户ID
        return tmpname;
    } else {
        return pw->pw_name;//返回用户名
    }
}

//获取文件组名
char *gid_name(gid_t gid) {
    struct group *grp;
    static char tmpname[20] = {0};
    if ((grp = getgrgid(gid)) == NULL) {
        sprintf(tmpname, "%d", gid);
        return tmpname;
    } else {
        return grp->gr_name;
    }
}

//终端输出命令结果
void showinfo(const char *str, struct stat *st) {
    //
    char s[] = "----------";
    mode_str(st->st_mode, s);
    printf("%s", s);
    printf(" %ld", st->st_nlink);
    printf(" %s", uid_name(st->st_uid));
    printf(" %s", gid_name(st->st_gid));
    printf("\n");
}

