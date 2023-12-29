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

int nodecnt = 0;

Node *getnode(){
    Node *p = (Node *)malloc(sizeof(Node));
    memset(p->next, 0, sizeof(Node *) * N);
    p->flag = 0;
    nodecnt++;
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
            //边对应check为0时没有冲突，不更新base值
            if(q[base + i].check == 0) continue;
            flag = 0;//发生冲突，跳出循环更新base值
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
int search(Tree *tree, char *s){
    int p = 1;
    for(int i = 0; s[i]; i++){
        if(abs(tree[tree[p].base + (s[i] - 'a')].check) != p) return 0; //其父节点的check值为其本身
        p = tree[p].base + s[i] - 'a';//求节点父节点
    }
    return tree[p].check < 0;
}

int main() {
    int n;
    char str[1000] = {0};
    Node *root = getnode();
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", str);
        insert(root, str);
    }
    Tree *arr = (Tree *)malloc(sizeof(Tree) * nodecnt * N);//定义Tree类的双数组
    memset(arr, 0, sizeof(Tree) * nodecnt * N);
    //最大编号
    int cnt = doubletree(root, arr, 1);
    //字典树的空间大小
    int size1 = nodecnt * sizeof(Node);
    //双数组字典树的空间大小
    int size2 = cnt * sizeof(Tree);
//    printf("tree space : %d bit\n", size1);
//    printf("double tree space: %d bit\n", size2);
//    printf("compress rate :%.2lf%%\n", 100.0 * size2 / size1);
    printf("---------search---------\n");
    while(~scanf("%s", str)){
        printf("result : %d\n", search(arr, str));
    }
    free(arr);
    
    return 0;
}


