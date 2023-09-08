//链表
#include<stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;//节点值
    struct Node *next;//节点保存下一个节点地址的指针
}Node;

typedef struct Link {
    struct Node head;//虚拟头指针
    int length;//链表长度
}Link;

Node *getnode (int val){
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->next = NULL;
    return p;
}

Link *initlink(){
    Link *l = (Link *)malloc(sizeof(Link));
    l->head.next = NULL;
    l->length = 0;
    return l;
}
//插入
int insert(Link *l, int ind, int val){
    if(l == NULL) return 2;
    if(ind < 0 || ind > l->length) return 0;
    Node *p = &(l->head), *q = getnode(val);
    while(ind--) p = p->next;
    q->next = p->next;
    p->next = q;
    l->length++;
    return 1;
}
//删除
void delect(Link *l, int ind){
    if(l == NULL) return ;
    if(ind < 0 || ind >= l->length) return ;
    Node *p = &(l->head), *q;
    while(ind--) p = p->next;
    q = p->next;
    p->next = q->next;
    free(q);
    l->length--;
    return ;
}
//清空，删除每个节点
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
void output(Link *l) {
    Node *p = l->head.next;
    while(p){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return ;
}

int main() {
    Link *l = initlink();
    int n = 0, val = 0;
    srand(time(0));
    for(int i = 0; i < 10; i++){
        n = rand() % 4;
        val = rand() % 100;
        int ind = rand() % (l->length + 1);// 确保位置合法
        switch(n) {
            case 0:
            case 1:
            case 2: printf("insert %d", val); printf(" %d\n", insert(l, ind, val));  output(l) ; break;
            case 3: printf("delect %d :\n", ind); delect(l, ind); output(l); break;
        }
    }
    clear(l);
    return 0;
}



