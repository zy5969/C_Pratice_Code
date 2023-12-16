/*************************************************************************
	> File Name: 字典树.c
	> Author:字符串存储，查询，排序 
	> Mail: 
	> Created Time: Mon 11 Dec 2023 02:10:19 PM CST
 ************************************************************************/
/*
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 26
//定义
typedef struct Node{
    int flag;
    struct Node *next[26];
}Node;

//初始化
Node *getnode() {
    Node *p = (Node *)malloc(sizeof(Node));
    p->flag = 0;
    memset(p->next, 0, sizeof(Node *) * N);
    return p;
}

int ind(char s){
    return s - 'a';
}

//插入
int insert(Node *p, char *s){
    Node *q = p;
    for(int i = 0; s[i]; i++){
        int a = ind(s[i]);//字母下标
        //为空时直接插入
        if(q->next[a] == NULL) q->next[a] = getnode();
        q = q->next[a];
    }
    q->flag = 1;
    return 1;
}

//查找
int search(Node *p, char *s){
    Node *q = p;
    for(int i = 0; s[i]; i++){
        int n = ind(s[i]);
        q = q->next[n];
        if(q == NULL) return 0;
    }
    return q->flag;
}

//清除
void clear(Node *p){
    if(p == NULL) return ;
    for(int i = 0; i < 26; i++){
        clear(p->next[i]);
    }
    free(p);
    return ;
}

//按字典序排序输出
void output(Node *p, int n, char *s){
    if(p == NULL) return ;
    s[n] = '\0';//初始化
    if(p->flag) printf("%s\n", s);
    for(int i = 0; i < 26; i++){
        s[n] = i + 'a';//
        output(p->next[i], n + 1, s);
    }
    return ;
}

int main() {
    Node *p = getnode();
    int n, m;
    char s[100] = {0};
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d%s", &n, s);
        switch(n){
            case 1:insert(p, s);break;
            case 2:printf("search result : %d\n", search(p, s));break;
        }
    }
    output(p, 0, s);
    clear(p);
    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 26

typedef struct Node {
    int flag; //是否独立成词
    struct Node *next[N]; //存放每个节点的各条边
}Node;

Node *init(){
    Node *p = (Node *)malloc(sizeof(Node));
    memset(p->next, 0, sizeof(Node *) * N);//初始化为0
    p->flag = 0;
    return p;
}

//字母对应下标
int ind(char s){
    return (s - 'a');
}

//插入
int insert(Node *p, char *s){
    Node *q = p;
    for(int i = 0; s[i]; i++){
        int x = ind(s[i]);//获取字母对应下标存放在next数组中
        //对应边为空时直接存放在新的对应边中
        if(q->next[x] == NULL) q->next[x] = init();
        q = q->next[x];//继续向下遍历插入
    }
    q->flag = 1;//一个字符插入完成时最后节点flag置1
    return 1;
}

//查找
int search(Node *p, char *s){
    if(p == NULL) return 0;
    Node *q = p;
    //遍历每条边
    for(int i = 0; s[i]; i++){
        int x = ind(s[i]);
        q = q->next[x];
        if(q == NULL) return 0;
    }
    return q->flag;//保证查找到的是完整字符串
}

//清空
void clear(Node *p){
    if(p == NULL) return ;
    for(int i = 0; i < N; i++){
        clear(p->next[i]);//每个节点的每条边都清空
    }
    free(p);
    return ;
}

//输出
void output(Node *p, int n, char *s){
    if(p == NULL) return ;
    s[n] = '\0';
    if(p->flag) printf("%s\n", s);
    for(int i = 0; i < N; i++){
        s[n] = i + 'a';//当前边代表的字符
        output(p->next[i], n + 1, s);
    }
    return ;
}

int main() {
    char str[100] = {0};
    int n, m;
    Node *p = init();
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%s", &m, str);
        switch(m){
            case 1: insert(p, str); break;
            case 2: printf("search result: %d\n", search(p, str)); break;
        }
    }
    output(p, 0, str);//从0层开始
    clear(p);
    return 0;
}


