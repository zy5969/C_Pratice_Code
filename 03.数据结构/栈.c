//栈
#include<stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Strac{
    int *data;
    int top, size;
}Strac;

Strac *init(int n){
    Strac *s = (Strac *)malloc(sizeof(Strac));
    s->data = (int *)malloc(sizeof(int ) * n);
    s->top = -1;
    s->size = n;
    return s;
}

int empty(Strac *s){
    return s->top == -1;
}

int front(Strac *s){
    return s->data[s->top];
}

int push(Strac *s, int val){
    if(s == NULL) return 0;
    if(s->top + 1 == s->size) return 2;
    s->top++;
    s->data[s->top] = val;
    return 1;
}

int pop(Strac *s){
    if(s == NULL) return 0;
    if(empty(s)) return 2;
    s->top--;
    return 1;
}

void output(Strac *s){

    for(int i = s->top; i >= 0; i--){
        printf("%d", s->data[i]);
        i && printf(" ");
    }
    printf("\n");
    return ;
}

void clear(Strac *s){
    if(s == NULL) return;
    free(s->data);
    free(s);
    return ;
}

int main() {
    Strac *s = init(10);
    srand(time(0));
    for(int i = 0; i < 10; i++){
        int val = rand() % 100;
        int x = rand() % 4;
        switch(x) {
            case 0:
            case 1:
            case 2:printf("push %d ", val); 
                printf(" %d\n", push(s, val)); 
                output(s);break;
            case 3:printf("pop %d\n", pop(s)); output(s); break;
        }
    }
    clear(s);
    return 0;
}



