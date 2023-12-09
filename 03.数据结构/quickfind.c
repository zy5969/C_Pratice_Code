/*************************************************************************
	> File Name: quickfind.c
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Dec 2023 05:50:36 PM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

typedef struct Qfind{
    int *color;
    int size;
}Qfind;

//初始化
Qfind *initfind(int n){
    Qfind *q = (Qfind *)malloc(sizeof(Qfind));
    q->color = (int *)malloc(sizeof(int) * (n + 1));
    q->size = n;
    for(int i = 1; i <= n; i++){
        q->color[i] = i;//初始化代表元素为其本身
    }
    return q;
}

//获取代表元素
int find(Qfind *q, int n){
    return q->color[n];
}

//合并
int qunion(Qfind *q, int a, int b){
    if(find(q, a) == find(q, b)) return 0;
    int la = q->color[a];
    for(int i = 1; i < q->size; i++){
        if(q->color[i] == la) q->color[i] = q->color[b]; 
    }
    return 1;
}

//清空
void clear(Qfind *q){
    if(q == NULL) return ;
    free(q->color);
    free(q);
    return ;
}

int main() {
    int n, m, a, b;
    Qfind *q = initfind(10);
    for(int i = 0; i < 5; i++){
        scanf("%d%d", &a, &b);
        qunion(q, a, b);
    }
    printf("------------------------\n");
    while(~scanf("%d%d", &n, &m)) {
        if(find(q, n) == find(q, m)) printf("n & m\n");
        else printf("n - m\n");
    }
    clear(q);
    return 0;
}
