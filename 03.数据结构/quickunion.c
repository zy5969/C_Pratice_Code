/*************************************************************************
	>ss File Name: quickfind.cA
    字符串存储，查找
 ***********************************************************************/
/*
#include<stdio.h>
#include <stdlib.h>
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

typedef struct Qfind{
    int *father, *count;//父节点，节点数
    int size;
}Qfind;

//初始化
Qfind *initfind(int n){
    Qfind *q = (Qfind *)malloc(sizeof(Qfind));
    q->father = (int *)malloc(sizeof(int) * (n + 1));
    q->count = (int *)malloc(sizeof(int) * (n + 1));
    q->size = n;
    for(int i = 1; i <= n; i++){
        q->father[i] = i;//初始化代表元素为其本身
        q->count[i] = 1;
    }
    return q;
}

//获取元素父节点
int find(Qfind *q, int n){
    if(q->father[n] == n) return n;
    return q->father[n] = find(q, q->father[n]);
}

//合并
int unions(Qfind *q, int a, int b){
    int fa = find(q, a), fb = find(q, b);
    if(fa == fb) return 0;
    if(q->count[fa] < q->count[fb]) swap(fa, fb);
    q->father[fa] = fb;
    q->count[fa] += q->count[fb];
    return 1;
}

//清空
void clear(Qfind *q){
    if(q == NULL) return ;
    free(q->father);
    free(q->count);
    free(q);
    return ;
}

void output(Qfind *q, int m){ 
    for(int i = 0; i < m; i++){
        printf("%d.father = %d root = %d\n", i, q->father[i], find(q, i));
    }
    return ;
}

int main() {
    int n, m, a, b;
    scanf("%d", &m);
    Qfind *q = initfind(m);
    output(q, m);
    printf("------------------------\n");
    while(~scanf("%d%d%d", &n, &a, &b)){
        switch(n) {
            case 1:unions(q, a, b);output(q, m); break;
            case 2: {
                if(find(q, a) == find(q, b)) printf("YES\n");
                else printf("NO\n");
            } break;
        }
        printf("------------------------\n");
    }
    clear(q);
    return 0;
}
*/

#include <stdlib.h>
#include <stdio.h>
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

typedef struct qunion{
    int *father, *cnt;//父节点、节点数
    int size;//大小
}qunion;

qunion *initunion(int n){
    qunion *q = (qunion *)malloc(sizeof(qunion));
    q->father = (int *)malloc(sizeof(int) * (n + 1));
    q->cnt = (int *)malloc(sizeof(int) * (n + 1));
    q->size = n;
    for(int i = 0; i < n; i++){
        q->father[i] = i;
        q->cnt[i] = 1;
    }
    return q;
}

//查找父节点
int find(qunion *q, int n){
    if(q->father[n] == n) return n;
    return q->father[n] = find(q, q->father[n]);
}

//合并
int q_union(qunion *q, int a, int b){
    int fa = find(q, a), fb = find(q, b);
    if(fa == fb) return 0;
    if(q->cnt[fa] < q->cnt[fb]) swap(fa, fb);
    q->father[fa] = fb;
    q->cnt[fa] += q->cnt[fb];
    return 1;
}

//清空
void clear(qunion *q) {
    if(q == NULL) return ;
    free(q->father);
    free(q->cnt);
    free(q);
    return ;
}

void output(qunion *q, int n){
    for(int i = 0; i < n; i++){
        printf("%d:father = %d  root = %d\n", i, q->father[i], find(q, i));
    }
    return ;
}

int main() {
    int n, m, a, b;
    scanf("%d", &m);
    qunion *q = initunion(m);
    output(q, m);
    printf("------------------------\n");
    while(~scanf("%d%d%d", &n, &a, &b)){
        switch(n) {
            case 1:q_union(q, a, b);output(q, m); break;
            case 2: {
                if(find(q, a) == find(q, b)) printf("YES\n");
                else printf("NO\n");
            } break;
        }
        printf("------------------------\n");
    }
    clear(q);
    
    return 0;
}


