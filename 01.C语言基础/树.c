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
//
void Trees(Tree *tree, int val){
    int flag = 0;
    tree->root = buildtree(tree->root, val, &flag);
    tree->cnt += flag;
    return ;
}

//遍历
//先
void preorder(Node *root){
    if(root == NULL) return ;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
    return ;
}

void putpre(Tree *tree){
    printf("putpre: ");
    preorder(tree->root);
    printf("\n");
    return ;
}

//中
void midorder(Node *root){
    if(root == NULL) return;
    midorder(root->left);
    printf("%d ", root->data);
    midorder(root->right);
    return ;
}

void putmid(Tree *tree){
    printf("putmid: ");
    midorder(tree->root);
    printf("\n");
    return ;
}

//后
void lesorder(Node *root){
    if(root == NULL) return;
    lesorder(root->left);
    lesorder(root->right);
    printf("%d ", root->data);
    return ;
}

void putles(Tree *tree){
 //   if(tree == NULL) return;
    printf("putles: ");
    lesorder(tree->root);
    printf("\n");
    return ;
}

//广义表
void putorder(Node *root){
    if(root == NULL) return;
    printf("%d", root->data);
    if(root->left == NULL && root->right == NULL) return;
    printf("(");
    putorder(root->left);
    printf(",");
    putorder(root->right);
    printf(")");
    return ;
}

void order(Tree *tree){
    if(tree == NULL) return ;
    printf("广义表: ");
    putorder(tree->root);
    printf("\n");
    return;
}

//清空
void nodeclear(Node *root){
    if(root == NULL) return ;
    nodeclear(root->left);
    nodeclear(root->right);
    free(root);
    return;
}

void treeclear(Tree *tree){
    if(tree == NULL) return;
    nodeclear(tree->root);
    free(tree);
    return;
}

int main() {
    srand(time(0));
    int val;
    Tree *tree = inittree();
    for(int i = 0; i < 10; i++){
        val = rand() % 100;
        Trees(tree, val);
    }
    putpre(tree);
    putmid(tree);
    putles(tree);
    order(tree);
    free(tree);
    return 0;
}


