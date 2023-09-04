//AC自动机实现
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 26
//字典树
typedef struct Node {
    int flag;//为1时节点独立成词
    struct Node *next[N], *fail;//next存放26条边，fail，错误指针
}Node;

Node *getnode() {
    Node *p = (Node *)malloc(sizeof(Node));
    return p;
}
//队列
typedef struct Queue {
    Node **data;//存放指针的指针数组
    int head, tail, size;//队头，队尾，大小
}Queue;

Queue *initqueue(int n){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (Node **)malloc(sizeof(Node *) * (n + 1));
    q->head = q->tail = 0;
    q->size = n;
    return q;
}

//判断队列是否为空
int empty(Queue *q){
    return q->head == q->tail;
}

//或取队首的Node类型的指针
Node *front(Queue *q){
    return q->data[q->head];
}

//入队，队尾后移
void push(Queue *q, Node *p){
    q->data[q->tail++] = p;
    return ;
}

//出队，队首后移
void pop(Queue *q){
    q->head++;
    return ;
}
//清空
void clearqueue(Queue *q){
    if(q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}
//字典树插入
int insert(Node *root, char *s){
    Node *p = root;
    int n = 0;//记录插入需要的节点个数
    for(int i = 0; s[i]; i++){
        int x = s[i] - 'a';//字符转换为数字下标
        //为空时建立节点
        if(p->next[x] == NULL) p->next[x] = getnode(), n++;
        p = p->next[x];//向下插入
    }
    p->flag = 1;//末尾节点独立成词
    return n;
}
//查找字符串中的树中的字符串
int search(Node *root, char *s){
    Node *p = root;
    int n = 0;
    for(int i = 0; s[i]; i++){
        int x = s[i] - 'a';//转换字符
        //节点不为空，子孩子为空时指向错误指针
        while(p && p->next[x] == NULL) p = p->fail;
        if(p == NULL) p = root;//节点为空时，由根节点重新开始找
        else p = p->next[x];//向其子孩子查找
        Node *q = p;
        while(q){
            n += q->flag;//计算出现的字符串个数
            q = q->fail;
        }
    }
    return n;
}

//按字典序输出，x为层数
void output(Node *root, int x, char *s){
    if(root == NULL) return ;
    s[x] = '\0';//初始化为0
    if(root->flag) printf("%s\n", s);//节点独立时输出字符串
    for(int i = 0; i < N; i++){
        s[x] = i + 'a';//数字转换为字符
        output(root->next[i], x + 1, s);//向下一层遍历
    }
    return ;
}
//清空字典树
void clear(Node *p){
    if(p == NULL) return ;
    for(int i = 0; i < N; i++){
        clear(p->next[i]);//清空每个节点的每条边
    }
    free(p);
    return ;
}

void build(Node *root, int n){
    Queue *q = initqueue(n + 10);//初始化队列
    root->fail = NULL;//根节点的错误指针为空
    push(q, root);
    while(!empty(q)){
        Node *p = front(q);
        pop(q);
        //建立每条有效边的错误指针
        for(int i = 0; i < N; i++){
            if(p->next[i] == NULL) continue;//为空时跳过
            Node *p1 = p->fail;//指向其错误指针
            //指针不为空，其孩子为空，向下
            while(p1 && p1->next[i] == NULL) p1 = p1->fail;
            //指针为空时，子孩子错误指针为根节点
            if(p1 == NULL) p->next[i]->fail = root;
            else p->next[i]->fail = p1->next[i];//否则其子孩子
            push(q, p->next[i]);
        }
    }
    return ;
}

int main() {
    int n, cnt = 0;
    char str[100] = {0};
    Node *root = getnode();
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", str);
        cnt += insert(root, str);//获取所有字符串插入所需要的节点个数
    }
    build(root, cnt);//建立AC自动机
    printf("============search============\n");
    printf("if you want to end ,please write:_qw\n");
    while(~scanf("%s", str)){//查找
        if(strcmp(str, "_qw") == 0) break;//结束符
        printf("result : %d\n", search(root, str));
    }
    printf("============output============\n");
    output(root, 0, str);//按字典序输出，从根/0层开始
    clear(root);
    return 0;
}


