/*************************************************************************
	> File Name: hash.c
	链表法，存储字符串，查找字符串
	 
	> Created Time: Sat 09 Dec 2023 11:16:36 AM CST
 ************************************************************************/
/*
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *str;
    struct Node *next;
}Node;

typedef struct Hash{
    Node **data;//存放地址
    int size;
}Hash;

Node *initnode(char *s, Node *ind){
    Node *p = (Node *)malloc(sizeof(Node));
    p->next = ind;
    p->str = strdup(s);
    return p;
}

Hash *inithash(int n){
    Hash *h = (Hash *)malloc(sizeof(Hash));
    h->size = n << 1;
    h->data = (Node **)calloc(sizeof(Node *), h->size);
    return h;
}

//处理字符，计算哈希值
int BKDRhash(char *str) {
    int seed = 31, hash = 0;//seed是随机种子
    for(int i = 0; str[i]; i++){
        hash = hash * seed + str[i]; // 前缀和计算
    }
    return hash & 0x7fffffff;//取正
}

//插入
int insert(Hash *h, char *str) {
    int hash = BKDRhash(str);
    int ind = hash % h->size;//保证插入位置在范围内
    h->data[ind] = initnode(str, h->data[ind]);//生成一个结点位置
    return 1;
}

//查找
int search(Hash *h, char *str) {
    int hash = BKDRhash(str);
    int ind = hash % h->size;
    Node *p = h->data[ind];//定义链表首地址
    while(p && strcmp(p->str, str)) p = p->next;
    return p != NULL;
}

//清空点、表
void nodeclear(Node *node){
    if(node == NULL) return ;
    Node *p = node, *q;
    while(p) {//清空结点
        q = p->next;
        free(p->str);
        free(p);
        p = q;
    }
    free(q);
    return ;
}

void hashclear(Hash *h) {
    if(h == NULL) return ;
    for(int i = 0; i < h->size; i++){
        nodeclear(h->data[i]);//清除每个结点
    }
    free(h->data);
    free(h);
    return;
}


int main() {
    char s[20] = {0};
    int n;
    Hash *h = inithash(20);
    while(~scanf("%d%s", &n, s)){
        switch(n){
            case 1:printf("insert result: %d\n", insert(h, s)); break;
            case 2:printf("search result: %d\n", search(h, s)); break;
            default: printf("error!!\n"); break;
        }
    }
    hashclear(h);
    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *str;
    struct Node *next;
}Node;

typedef struct Hash{
    Node **data;
    int size;
}Hash;

Node *initnode(char *s, Node *dir){
    Node *p = (Node *)malloc(sizeof(Node));
    p->str = strdup(s);
    p->next = dir;
    return p;
}

Hash *inithash(int n){
    Hash *h = (Hash *)malloc(sizeof(Hash));
    h->size = n << 1;
    h->data = (Node **)calloc(sizeof(Node *), h->size);
    return h;
}

int BKDRhash(char *s){
    int seed = 31, hash = 0;
    for(int i = 0; s[i]; i++){
        hash = hash * seed + s[i];
    }
    return hash & 0x7fffffff;
}

int insert(Hash *h, char *s){
    int hash = BKDRhash(s);
    int ind = hash % h->size;
    h->data[ind] = initnode(s, h->data[ind]);
    return 1;
}

int search(Hash *h, char *s){
    int hash = BKDRhash(s);
    int ind = hash % h->size;
    Node *p = h->data[ind];
    while(p && strcmp(p->str, s)) p = p->next;
    return p != NULL;
}

void clearnode(Node *p){
    if(p == NULL) return ;
    Node *q = p, *l;
    while(q) {
        l = q->next;
        free(q->str);
        free(q);
        q = l;
    }
    free(l);
    return ;
}

void clearhash(Hash *h){
    if(h == NULL) return ;
    for(int i = 0; i < h->size; i++){
        clearnode(h->data[i]);
    }
    free(h->data);
    free(h);
    return ;
}

int main() {
    int x;
    char str[50] = {0};
    Hash *h = inithash(50);
    while(~scanf("%d%s", &x, str)){
        switch(x){
            case 1:insert(h, str); break;
            case 2:printf("search result: %d\n", search(h, str)); break;
            default: printf("error!"); break;
        }
    }
    clearhash(h);
    return 0;
}


