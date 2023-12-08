//堆/优先队列 大顶堆
#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(a,b){\
        __typeof(a) __temp = a;\
        a = b; b = __temp;\
    }

typedef struct priority{
    int *data;//存储空间
    int cnt, size;//个数。大小
}priority;
priority *init(int n) {
    priority *q = (priority *)malloc(sizeof(priority));
    q->data = (int *)malloc(sizeof(int) * (n + 1));//为队列中的数据获取空间，从下标1开始
    q->cnt = 0;
    q->size = n;//可存n个数据
    return q;
}
int empty(priority *q) {
    return q->cnt == 0;
}
//获取队首元素
int top(priority *q) {
    return q->data[1];
}
//入队、调整
int push(priority *q, int val) {
    if(q == NULL) return 0 ;
    if(q->cnt == q->size) return 0;//堆已经满
    printf("insert: %d \n", val);
    q->cnt += 1;//元素位置
    q->data[q->cnt] = val;///位置元素赋值为vql
    int ind = q->cnt;
    while (ind >> 1 && q->data[ind] > q->data[ind >> 1]) {
        swap(q->data[ind], q->data[ind >> 1]);//有父节点，且元素大于父节点值交换
        ind >>= 1;//下标
    }
    return 1;
}
//出队调整，直到没有叶子节点
int pop(priority *q) {
    if(q == NULL) return 0;
    if(empty(q)) return 0;
    printf("delete: \n");
    q->data[1] = q->data[q->cnt--];//下标为1的元素等于队尾元素
    int ind = 1;
    while ((ind << 1) <= q->cnt) {//判断左孩子有元素，左孩子编号合法
        int temp = ind, l = ind << 1, r = ind <<1 | 1;//
        if(q->data[l] > q->data[temp]) temp = l;//左孩子大于temp，交换位置
        if(r <= q->cnt && q->data[r] > q->data[temp]) temp = r;//判断有右孩子，用temp保留最大元素位置
        if(temp == ind) break;
        swap(q->data[ind], q->data[temp]);
        ind = temp;//保留temp最大位置
    }
    return 1;
}
void clear(priority *q) {
    if(q == NULL) return;
    free(q->data);
    free(q);
    return;
}
void output (priority *q) {
    if(q == NULL) return;
    if(q->cnt == 0) return;
    printf("priority: \n");
    for(int i = 1; i <= q->cnt; i++) {
        i != 1 && printf(" ");
        printf("%d", q->data[i]);
    }
    printf("\n");
    return;
}
int main() {
    srand(time(0));
    #define max_op 10
    priority *q = init(max_op);
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        push(q, val);
        output(q);
    }
    for(int i = 0; i < max_op; i++) {
        printf("%d ",top(q));
        pop(q);
        output(q);
    }
    printf("\n");
    clear(q);
    return 0;
}
