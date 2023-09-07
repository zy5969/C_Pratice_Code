//队列
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Queue {
    int *data;
    int head, tail, size, cnt;//队首，队尾， 长度
}Queue;
//********

//队列初始化
Queue *init(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * n);//存储空间
    q->head = q->tail = q->cnt = 0;
    q->size = n;
    return q;
}
//判空
int empty(Queue *q) {
    return q->cnt == 0;
}
//队首元素
int front(Queue *q) {
    return q->data[q->head];//返回队首
}

//入队，成功返回1
int push(Queue *q, int val) {
    if(q == NULL) return 0;
 //   if(q->tail == q->size) return 0;
    if(q->cnt == q->size) return 0;//判断当前是否满
    q->data[q->tail++] = val;//入队
    if(q->tail == q->size) q->tail -= q->size;//入队时，此时下次可入队的位置在0号位置
    q->cnt += 1;
    return 1;
}

//出队，成功返回1
int pop(Queue *q) {
    if(q == NULL) return 0;
    if(empty(q)) return 0;
    q->head += 1;
    if(q->head == q->size) q->head -= q->size;
    q->cnt -= 1;
    return 1;
}

void output(Queue *q) {
    printf("Queue(%d) = [", q->cnt);
    for (int i = q->head, j = 0; j < q->cnt; j++) {
        j && printf (", ");//i!=q->head时打印逗号和空格循环时j
        printf("%d", q->data[(i + j) % q->size]);
    }
    printf("]\n");
    return;
}

//清空
void clear(Queue *q) {
    if(q == NULL) return;
    free(q->data);
    free(q);
    return;
}

int main() {
    srand(time(0));
    #define MAX_op 10
    Queue *q = init(MAX_op);
    int op, val;
    for(int i = 0; i < MAX_op; i++) {
        op = rand() % 4;
        val = rand() % 100;
        switch (op) {
            case 0:
            case 1:
            case 2:printf("push %d to %d\n", val, push(q, val));
            break;
            case 3:printf("pop %d to %d\n", front(q), pop(q));
            break;
        }
        output(q);
        printf("\n");
    }
    clear(q);
    return 0;
}
