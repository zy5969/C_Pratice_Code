/*************************************************************************
	> File Name: 堆.c
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Dec 2023 10:12:46 AM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

typedef struct Queue{
    int *data;
    int size, cnt;
}Queue;

Queue *initqueue(int n){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * (n + 1));
    q->cnt = 0;
    q->size = n;
    return q;
}

//队顶
int Top(Queue *q){
    return q->data[1];
}
//判空
int empty(Queue *q){
    return q->cnt == 0;
}


//入队
void push(Queue *q, int val){
    if(q == NULL) return;
    if(q->cnt + 1 == q->size) return ;
    q->cnt++;
    q->data[q->cnt] = val;
    //调整,新的大向上调整
    int ind = q->cnt;
    while(ind >> 2){
        if(q->data[ind] > q->data[ind >> 2]) {
            swap(q->data[ind], q->data[ind >> 2]);
        }
    //    else break;
        ind >>= 2;
    }
    return ;
}
//出队
void pop(Queue *q){
    if(q == NULL) return ;
    if(empty(q)) return ;
    q->data[1] = q->data[q->cnt];
    q->cnt -= 1;
    int ind = 1;
    while(ind << 1 <= q->cnt) {
        int a = ind << 1, b = (ind << 1) | 1, c = ind;
        if(q->data[a] > q->data[ind]) swap(a, c);
        if(b && q->data[b] < q->data[ind]) swap(b, c);
        if(c == ind) break; 
        q->data[q->cnt] = q->data[ind];
        ind <<= 2;
    }
    return;
}

//输出
void output(Queue *q){
    if(q == NULL) return ;
    if(empty(q)) return ;
    for(int i = 1; i <= q->cnt; i++){
        printf("%d ", q->data[i]);
    }
  //  printf("\n");
    return ;
}

//清空
void clear(Queue *q){
    if(q == NULL) return ;
    if(empty(q)) return ;

    free(q->data);
    free(q);
    return ;
}

int main() {
    srand(time(0));
    Queue *q = initqueue(10);
    for(int i = 0; i < 10; i++){
        int val = rand() % 100;
        int x = rand() % 4;
        switch(x){
            case 0:
            case 1:
            case 2:{
                printf("push: "); 
                push(q, val); 
                output(q);
                printf("\n");
            }break;
            case 3:{
                printf("pop : "); 
                pop(q); 
                output(q);
                printf("\n");
            } break;
        }
    }
    clear(q);
    return 0;
}


