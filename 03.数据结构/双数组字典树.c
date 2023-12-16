/*************************************************************************
	> File Name: 双数组字典树.c
	> Author: 
	> Mail: 
	> Created Time: Tue 12 Dec 2023 09:30:21 AM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 26

typedef struct Node {
    int flag;
    struct Node *next[N];
}Node;

Node *getnode(){
    Node *p = (Node *)malloc(sizeof(Node));
    memset(p->next, 0, sizeof(Node *) * N);
    p->flag = 0;
    return p;
}

int insert(Node *p, char *s){
    Node *q = p;
    for(int i = 0; s[i]; i++){
        int d = s[i] - 'a';
        if(q->next[d] == NULL) q->next[d] = getnode();
        q = q->next[d];
    }
    q->flag = 1;
    return 1;
}


void clear(Node *p){
    if(p == NULL) return ;
    for(int i = 0; i < N; i++){
        clear(p->next[i]);
    }
    free(p);
    return ;
}

void output(Node *p, int n, char *s){
    if(p == NULL) return ;
    s[n] = '\0';
    if(p->flag) printf("%s\n", s);
    for(int i = 0; i < N; i++){
        s[n] = i + 'a';
        output(p->next[i], n + 1, s);
    }
    return ;
}

//定义双数组的结构体
typedef struct Tree{
    int base, check;
}Tree;

//base数组
void baseval(Node *root, Tree *q, int ind) {
    int base = 1, flag = 0;
    while(flag == 0){
        flag = 1;//
        for(int i = 0; i < N && flag; i++){
            if(root->next[i] == NULL) continue;//边为空
            if(q[base + i].check == 0) continue;//没有父节点
            flag = 0;///
        }
        if(flag) break;
        base += 1;
    }
    q[ind].base = base;
    return ;
}

//构成双数组字典树
int doubletree(Node *root, Tree *tree, int ind){
    if(root == NULL) return 1;
    int maxind = ind;//记录最大节点编号
    if(root->flag) tree[ind].check = -tree[ind].check;//节点独立成词,check取负
    baseval(root, tree, ind);//获取base值
    for(int i = 0; i < N; i++){
        if(root->next[i] == NULL) continue;//边为空,不做操作
        //节点编号(父节点base值+i)的check值为父节点
        tree[tree[ind].base + i].check = ind;
    }
    //转化为双数组
    for(int j = 0; j < N; j++){
        if(root->next[j] == NULL) continue;
        //建立每个节点的check值
        int y = doubletree(root->next[j], tree, tree[ind].base + j);
        if(y > maxind) maxind = y; //记录最大编号
    }
    return maxind;//返回最大编号
}

//查找
int search(Node *p, char *s){
    return 1;
}

int main() {

    return 0;
}


