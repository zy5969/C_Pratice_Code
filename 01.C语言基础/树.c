/*************************************************************************
	> File Name: 树.c
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Dec 2023 05:27:41 PM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
}Node;

typedef struct Tree{
    Node *root;
    int cnt;
}Tree;
//初始化
Node *getnode(int val){
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->left = p->right = NULL;
    return p;
}

Tree *inittree(){
    Tree *t = (Tree *)malloc(sizeof(Tree));
    t->root = NULL;
    t->cnt = 0;
    return t;
}

//构建树
Node *buildtree(Node *root, int val, int *flag) {
    if(root == NULL) {
        *flag = 1;
        return getnode(val);
    }
    if(root->data == val) return root;
    if(root->data > val) root->left = buildtree(root->left, val, flag);
    else root->right = buildtree(root->right, val, flag);
    return root;
}
//遍历
//先

//中

//后

//输出

//清空

int main() {

    return 0;
}


