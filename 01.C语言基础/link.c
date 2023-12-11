/*************************************************************************
	> File Name: link.c
	> Author: 
	> Mail: 
	> Created Time: Mon 11 Dec 2023 09:29:13 PM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

typedef struct Link{
    struct Node head;
    int size;
}Link;

Node *getnode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->next = NULL;
    return p;
}

Link *initlink(){
    Link *l = (Link *)malloc(sizeof(Link));
    l->head.next = NULL;
    l->size = 0;
    return l;
}

//插入
int insert(Link *l, int val, int ind){
    if(l == NULL) return 0;
    if(ind < 0 || ind > l->size) return 0;
    Node *p = &(l->head), *q = getnode(val);
    while(ind--) p = p->next;
    q->next = p->next;
    p->next = q;
    l->size++;
    return 1;
}

//删除
void delete(Link *l, int ind){
    if(l == NULL) return ;
    if(ind < 0 || ind >= l->size) return ;
    Node *p = &(l->head) , *q;
    while(ind--) p = p->next;
    q = p->next;
    p->next = q->next;
    free(q);
    l->size--;
    return ;
}

//清空
void clear(Link *l){
    if(l == NULL) return ;
    Node *p = l->head.next, *q;
    while(p){
        q = p;
        p = p->next;
        free(q);
    }
    free(l);
    return ;
}

//输出
void output(Link *l){
    if(l == NULL) return ;
    Node *p = l->head.next;
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return ;
}

int main() {
    int ind, val;
    srand(time(0));

    Link *l = initlink();
    for(int i = 0; i < 10; i++){
        val = rand() % 100;
        ind = rand() % (l->size + 1);
        int x = rand() % 4;
        switch(x){
            case 0:
            case 1:
            case 2:insert(l, val, ind); output(l);break;
            case 3:delete(l, ind); output(l); break;
        }
    }
    clear(l);
    return 0;
}


