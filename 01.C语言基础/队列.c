/*************************************************************************
	> File Name: 队列.c
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Dec 2023 04:04:01 PM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Queue{
    int *data;
    int head, tail, size, cnt;
}Queue;

Queue *init(int n){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * n);
    q->head = q->tail = q->cnt = 0;
    q->size = n;
    return q;
}

//判空
int empty(Queue *q){
    return q->head == q->tail;
}
//入队
int push(Queue *q, int val){
 //   if(q == NULL) return 0;
    q->tail += 1;
    q->data[q->tail] = val;
    q->cnt++;
    return 1;
}
//出队
int pop(Queue *q){
    if(q == NULL) return 0;
    if(empty(q)) return 0;
    q->head++;
    q->cnt--;
    return 1;
}
//清空
void clear(Queue *q) {
    if(q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}


int main() {
    int val;
    srand(time(0));
    Queue *q = init(10);
    for(int i = 0; i < 10; i++){
        val = rand() % 100;
        push(q, val);
        printf("%d ", q->data[q->tail]);
    }
    printf("\n");
    for(int j = 0; j < 10; j++){
        pop(q);
        printf("%d ", q->data[q->head]);
    }
    printf("\n");
    clear(q);

    return 0;
}



