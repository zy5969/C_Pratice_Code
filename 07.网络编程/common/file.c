/*************************************************************************
	> File Name: file.c
	> Author: 
	> Mail: 
	> Created Time: Tue 09 Jan 2024 08:01:18 PM CST
 ************************************************************************/

#include "head.h"
#include "file.h"

//发送文件
void send_file(int sockfd, const char *filename) {
    
    FILE *fd = NULL;
    struct file_message filemsg;
    size_t size;
    char *p;
    bzero(&filemsg, sizeof(filemsg));
    //打开文件
    if((fd = fopen(filename, "rb")) == NULL) {
        perror("fopen");
        return ;
    }
    
    fseek(fd, 0, SEEK_END);//移动标识符至末尾
    filemsg.size = ftell(fd);//当前指针位置
    fseek(fd, 0, SEEK_SET);
    strcpy(filemsg.name, (p = strrchr(filename, '/')) ? p + 1 : filename);
    
    //读文件fread,并发送，发送后清空文件信息
    while((size = fread(filemsg.buff, 1, sizeof(filemsg.buff), fd))) {
        filemsg.size = size;
        send(sockfd, (void *)&filemsg, sizeof(filemsg), 0);
        bzero(filemsg.buff, sizeof(filemsg.buff));
    }

    return ;
}

//接收
void recv_file(int sockfd) {
    struct file_message packet, packet_t, packet_pre;
    int packet_size = sizeof(packet);
    int offset = 0, recv_size = 0, cnt = 0;
    FILE *fd = NULL;
    
    //清空
    bzero(&packet, sizeof(packet));
    bzero(&packet_t, sizeof(packet_t));
    bzero(&packet_pre, sizeof(packet_pre));

    //循环读取
    while(1) {
        //拷贝
        if(offset) memcpy(&packet, &packet_pre, offset);
        //
        while((recv_size = recv(sockfd, (void *)&packet_t, packet_size, 0)) > 0) {
            //
            if(offset + recv_size == packet_size) {
                memcpy((char *)&packet + offset, (char *)&packet_t, recv_size);
                offset = 0;
                printf("整包\n");
                break;
            } else if(offset + recv_size < packet_size) {
                memcpy((char *)&packet + offset, &packet_t, recv_size);
                offset += recv_size;
                printf("拆包\n");
            } else {
                int wait = packet_size - offset;
                memcpy((char *)&packet, &packet_t, wait);
                offset = recv_size - wait;//
                memcpy((char *)&packet_pre, (char *)&packet_t + wait, offset);
                printf("粘包\n");
                break;
            }
        }
        if(!cnt) {
            printf("File transfer start: %s, with size of <%ld>\n", packet.name, packet.size);
            char name[1024] = {0};
            sprintf(name, "./data/%s", packet.name);
            if((fd = fopen(name, "wb")) == NULL) {
                perror("fopen");
                return ;
            }
        }
        cnt += 1;
        int wsize = fwrite(packet.buff, 1, packet.size, fd);
        if(recv_size <= 0) break;
    }
    
    printf("file transfer finished\n");
    fclose(fd);

    return ;
}

