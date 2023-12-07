/*************************************************************************
	> File Name: 顺序表.c
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Dec 2023 10:59:57 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//结构定义
typedef struct Vector{
    int *data;
    int size, length;
}Vector;

void expand(Vector *p);

//初始化
Vector *init(int n) {
    Vector *p = (Vector *)malloc(sizeof(Vector));
    p->data = (int *)malloc(sizeof(int) * n);
    p->size = n;
    p->length = 0;
    return p;
}
//插入
void insert(Vector *p, int ind, int val){
    if(ind < 0 || ind >= p->size) return ;
    p->length++;
    p->data[ind] = val;
    for(int i = p->length; i <ind; i--){
        p->data[i] = p->data[i - 1];
    }
    if(p->length == p->size) expand(p);
    
    return ;
}
//删除, 空间
void delete(Vector *p, int ind){
    if(p == NULL) return ;
    if(ind < 0 || ind >= p->length) return ;
    for(int i = ind + 1; i < p->length; i++){
        p->data[i - 1] = p->data[i];
    }
    p->length--;
    return;
}
//扩容
void expand(Vector *p) {
    int rsize = p->size;
    int *newsize = (int *)realloc(p->data, sizeof(int) * rsize * 2);
    if(p == NULL) return ;
    p->data = newsize;
    p->size *= 2;

    return;
}
//输出
void output(Vector *p) {
    if(p == NULL) return ;
    for(int i = 0; i < p->length; i++){
        printf("%d ", p->data[i]);
    }
    printf("\n");
    return ;
}
//清空
void clear(Vector *p){
    if(p == NULL) return;
    free(p->data);
    free(p);
    return;
}


int main() {
    int val, x, ind;
    Vector *p = init(2);
    srand(time(0));
    for(int i = 0; i < 8; i++){
        val = rand() % 100;
        x = rand() % 4;
        ind = rand() % (p->length + 1);
        switch(x) {
            case 0:
            case 1:
            case 2:printf("insert! "); insert(p, i, val); output(p); break;
            case 3:printf("delete! "); delete(p, ind); output(p);break;  

        }
    }
    free(p);
    return 0;
}


