#include<stdio.h>
#include <time.h>
#include <stdlib.h>

//树的节点
typedef struct Node {
    int data;
    struct Node *lchild, *rchild;
}Node;

//树根节点，节点数
typedef struct Tree {
    Node *root;
    int n;//节点个数
}Tree;

//节点初始化
Node *initNewNode(int val) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = val;
    node->lchild = node->rchild = NULL;
    return node;
}

//树初始化
Tree *getNewTree() {
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->root = NULL;
    tree->n = 0;
    return tree;
}
//结构操做，构建一个节点
//val插入的值，flag判断是否插入成功，*root插入的位置
Node *insertNode (Node *root, int val, int *flag) {
    if(root == NULL) {
        *flag = 1;//
        return initNewNode(val);
    }
    if(root->data == val) return root;
    if(val < root->data) root->lchild = insertNode(root->lchild,val, flag);//如果值小于该节点，放在左子树
    else root->rchild = insertNode(root->rchild, val, flag);
    return root;//插入成功返回根节点
}
//树里插入
void insert(Tree *tree, int val) {
    int flag = 0;
    tree->root = insertNode(tree->root, val, &flag);//树的根节点指向插入的节点
    tree->n += flag;//等同于节点个数加1
    return;
}
//遍历方式
//先序节点遍历
void pre_orderNode(Node *root) {
    if(root == NULL) return;
    printf("%d ", root->data);//打印根元素
    pre_orderNode(root->lchild);
    pre_orderNode(root->rchild);
    return;
}
//树先序
void pre_order(Tree *tree) {
    printf("pre_order: ");
    pre_orderNode(tree->root);
    printf("\n");
    return;
}
//中序
void in_orderNode(Node *root) {
    if(root == NULL) return;
    in_orderNode(root->lchild);
     printf("%d ", root->data);
    in_orderNode(root->rchild);
    return;
}
void in_order(Tree *tree) {
    printf("in_order: ");
    in_orderNode(tree->root);
    printf("\n");
    return;
}
//后序
void le_orderNode(Node *root) {
    if(root == NULL) return;
    le_orderNode(root->lchild);
    le_orderNode(root->rchild);
     printf("%d ", root->data);//后序遍历后输出根
    return;
}
void le_order(Tree *tree) {
    printf("le_order: ");
    le_orderNode(tree->root);
    printf("\n");
    return;
}

//广义表输出
void outputNode(Node *root) {
    if(root == NULL) return;
    printf("%d", root->data);
    printf("(");
    if(root->lchild == NULL && root->rchild == NULL) return ;
    outputNode(root->lchild);
    printf(",");
    outputNode(root->rchild);
    printf(")");
    return ;
}
void output(Tree *tree) {
    printf("tree(%d): ", tree->n);
    outputNode(tree->root);
    printf("\n");
    return;
}
//树清空
void clear_Node(Node *node) {
    if(node == NULL) return;//判断
    clear_Node(node->lchild);//清空左子树
    clear_Node(node->rchild);//////清空右子树
    free(node);//根
    return;
}
void clear_Tree(Tree *tree) {
    if(tree == NULL) return;
    clear_Node(tree->root);//清空所有节点
    free(tree);
    return;
}
int main() {
    srand(time(0));//随机产生值
    Tree *tree = getNewTree();//树初始化
    for(int i = 0; i < 10; i++) {
        int val = rand() % 100;//生成100以内数
        insert(tree, val);
        output(tree);
        pre_order(tree);
    	in_order(tree);
    	le_order(tree);
        printf("\n");
    }
    clear_Tree(tree);
    return 0;
}





