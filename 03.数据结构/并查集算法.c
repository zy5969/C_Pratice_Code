
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define swap(a, b){\
    __typeof(a) __temp = a; \
    a = b; b = __temp;\
}


//quick_find
typedef struct Quick{
    int *color;
    int n;
}Quick;
//quick_union算法
typedef struct Q_union{
    int *father, *size;//父节点，节点个数
    int cnt;//大小
}Q_union;

Quick *initquick(int m){
    Quick *q = (Quick *)malloc(sizeof(Quick));
    q->color = (int *)malloc(sizeof(Quick) * m);
    q->n = m;
    for(int i = 0; i < m; i++){
        q->color[i] = i;//初始化每个元素代表颜色为其本身
    }
    return q;
}

Q_union *initunion(int m){
    Q_union *q = (Q_union *)malloc(sizeof(Q_union));
    q->father = (int *)malloc(sizeof(int) * m);
    q->size = (int *)malloc(sizeof(int) * m);
    q->cnt = m;
    for(int i = 0; i < m; i++){
        q->father[i] = i;
        q->size[i] = 1;
    }
    return q;
}

//获取代表元素
int find(Quick *q, int n){
    return q->color[n];
}

int findu(Q_union *q, int n){
    return q->father[n] = (q->father[n] == n) ? n:findu(q,q->father[n]);
}
//建立连接
void Union(Quick *q, int a, int b){
    if(q == NULL) return ;
    if(find(q, a) == find(q, b)) return ;
    int la = q->color[a];
    for(int i = 0; i < q->n; i++){
        if(q->color[i] != la) continue;
        q->color[i] = q->color[b];
        //与前一个颜色相同的，变为后一个数颜色
    }
    return ;
}

void qunion(Q_union *q, int a, int b){
    int fa = findu(q, a), fb = findu(q, b);
    if(fa == fb) return ;
    //代表元素节点少的作为节点多的子树
    if(q->size[a] > q->size[b]) swap(fa, fb);
    q->father[a] = fb;
    q->size[b] += q->size[a];
    return ;
}

//清空
void clear(Quick *q){
    if(q == NULL) return ;
    free(q->color);
    free(q);
    return ;
}

void clears(Q_union *p){
    if(p == NULL) return ;
    free(p->father);
    free(p->size);
    free(p);
    return ;
}

int main() {
    int a, b, x;
    Quick *q = initquick(10);
    Q_union *p = initunion(10);
    while(~scanf("%d%d%d", &x, &a, &b)){
        switch(x){
            case 1: Union(q, a, b);break;
            case 2: {
                if(find(q, a) == find(q, b)) printf("%d and %d linked\n", a, b);
                else printf("file\n");
            }break;
            case 3: qunion(p, a, b); break;
            case 4: {
                if(findu(p, a) == findu(p ,b)) printf("Linked\n");
                else printf("not link\n");
            }break;
        }
    }
    clear(q);
    clears(p);
    return 0;
}


