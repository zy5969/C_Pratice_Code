/*************************************************************************
树
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val; 
    struct Node *rchild, *lchild;
}Node;

typedef struct Tree{
    int n;
    Node *root;
}Tree;

Node *getnode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->val = val;
    p->rchild = NULL;
    p->lchild = NULL;
    return p;
}

Tree *init(int a){
    Tree *T = (Tree *)malloc(sizeof(Tree));
    T->n = a;
    T->root = NULL;
    return T;
}

int main() {

    return 0;
}

