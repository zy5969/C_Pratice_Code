/*************************************************************************
	> File Name: tree.c
	> Author: 
	> Mail: 
	> Created Time: Tue 12 Dec 2023 08:56:17 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 26

typedef struct Node {
    int flag;
    struct Node *next[N];
} Node;

Node *getnode(){
    Node *p = (Node *)malloc(sizeof(Node));
    memset(p->next, 0, sizeof(Node *) * N);
    p->flag = 0;
    return p;
}

int ind(char s){
    return s - 'a';
}

//插入
int insert(Node *p, char *s){
    Node *q = p;
    for(int i = 0; s[i]; i++){
        int x = ind(s[i]);
        if(q->next[x] == NULL) q->next[x] = getnode();
        q = q->next[x];
    }
    q->flag = 1;
    return 1;
}

//查找
int search(Node *p, char *s){
    if(p == NULL) return 0;
    Node *q = p;
    for(int i = 0; s[i]; i++){
        int x = ind(s[i]);
        q = q->next[x];
        if(q == NULL) return 0;
    }
    return q->flag;
}

//输出
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

//清空
void clear(Node *p){
    if(p == NULL) return ;
    for(int i = 0; i < N; i++){
        clear(p->next[i]);
    }
    free(p);
    return ;
}

int main() {
    char str[100] = {0};
    Node *p = getnode();
    int n;
    while(~scanf("%d%s", &n, str)){
        if(n == 0) break;
        switch(n){
            case 1:insert(p, str); break;
            case 2:{
                if(search(p, str)) printf("YES\n");
                else printf("NO\n");
            }break;
        }
    }
    printf("-------output---------\n");
    output(p, 0, str);
    clear(p);
    return 0;
}


