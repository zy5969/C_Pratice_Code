/*************************************************************************
	> File Name: 栈.c
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Dec 2023 03:32:30 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Stack{
    int *data;
    int top, size;
}Stack;

//初始化
Stack *init(int n){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * n);
    s->size = n;
    s->top = -1;
    return s;
}
//栈顶元素
int empty(Stack *s) {
    return s->top = -1;
}

//入栈
int push(Stack *s, int val){
    if(s == NULL) return 0;
    if(s->top + 1 == s->size) return 0;
    s->data[++s->top] = val;
    return 1;
}
//出栈
int pop(Stack *s){
    if(s == NULL) return 0;
    if(empty(s)) return 0;
    s->top--;
    return 1;
}
//输出
void output(Stack *s){
    if(s == NULL) return ;
    for(int i = s->top; i >= 0; i--){
        printf("%d ", s->data[i]);
    }
    printf("\n");
    return ;
}

//清空
void clear(Stack *s){
    if(s == NULL) return ;
    free(s->data);
    free(s);
    return ;
}

int main() {
    srand(time(0));
    Stack *s = init(10);
    for(int i = 0; i < 10; i++){
        int val = rand() % 100;
        int x = rand() % 4;
        switch(x){
            case 0:
            case 1:
            case 2:printf("push:"); push(s, val);output(s);break;
            case 3:printf("pop: "); pop(s); output(s); break;
        }
        
    }
    clear(s);
    return 0;
}

