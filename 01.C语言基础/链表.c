/*************************************************************************
	> File Name: 链表.c
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Dec 2023 11:13:57 AM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

//定义
typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef struct Link{
    struct Node head;
    int length;
}Link;
//初始化
Node *nodeget(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->next = NULL;
    p->data = val;
    return p;
}

Link *linkinit() {
    Link *l = (Link *)malloc(sizeof(Link));
    l->head.next = NULL;
    l->length = 0;
    return l;
}
//插入
void insert(Link *l, int ind, int val) {
    if(l == NULL) return ;
    if(ind < 0 || ind > l->length) return ;
    Node *p = &(l->head), *q = nodeget(val);
    while(ind--) p = p->next;
    q->next = p->next;
    p->next = q;
  //  free(q);
    l->length += 1;
    return ;
}
//删除
void delete(Link *l, int ind){
    if(l == NULL) return ;
    if(ind < 0 || ind >= l->length) return;
    Node *p = &(l->head), *q;
    while(ind--) p = p->next;
    q = p->next;
    p->next = q->next;
    free(q);
    l->length -= 1;
    return ;
}
//清空
void clear(Link *l){
    if(l == NULL) return ;
    Node *p = l->head.next, *q;
    while(p){
        q = p;
        p = p->next;//
        free(q);
    }
    free(l);
    return ;

}
//输出
void output(Link *l){
    if(l == NULL) return ;
    printf("Link:\n");
    Node *p = &(l->head);
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
  //  free(p);
    printf("\n");
    return ;
}


int main() {
    int ind , val, x;
    srand(time(0));
    Link *l = linkinit();
    for(int i = 0; i < 10; i++){
        val = rand() % 100;
        ind = rand() % (l->length + 1);
        x = rand() % 4;
        switch(x){
            case 0:
            case 1:
            case 2:printf("insert: "); insert(l, i, val);output(l);break;
            case 3:printf("delete: "); delete(l, i); output(l);break;
        }
    }
    clear(l);
    return 0;
}


