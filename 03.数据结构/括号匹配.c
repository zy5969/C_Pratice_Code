//栈实现括号匹配
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>//使用bool

typedef struct strac {
    int *data;
    int top, size;//栈顶 长度
}strac;

//栈初始化
strac *init(int n) {
    strac *s = (strac *)malloc(sizeof(strac));
    s->data = (int *)malloc(sizeof(int) * n);//存储空间
    s->size = n;
    s->top = -1;
    return s;
}
//判空
int empty(strac *s) {
    return s->top == -1;
}

int front(strac *s) {
    return s->data[s->top];//返回栈顶
}
//入栈，成功返回1
int push(strac *s, int val) {
    if(s == NULL) return 0;
    if(s->top +1 == s->size) return 0;//判断当前是否满
s->data[++s->top] = val;//先加入栈
   
return 1;
}

//出栈，成功返回1
int pop(strac *s) {
    if(s == NULL) return 0;
    if(empty(s)) return 0;
    s->top -= 1;
    return 1;
}
void output(strac *s) {
    printf("strac(%d) = [", s->top);//输出栈顶
    for (int j = s->top; j>=0;  j--) {
        printf("%d ", s->data[j]);
    }
    printf("]\n");
    return;
}
//清空
void clear(strac *s) {
    if(s == NULL) return;
    free(s->data);//释放节点
    free(s);//释放表
    return;
}

bool isvalid(strac *s, char *str) {//返回值真/假
    while(str[0]) {
        switch(str[0]) {//匹配
            case '(':
            case '[':
            case '{':push(s, str[0]); break;
            case ')':if(!empty(s) && (front(s) == '(')) {pop(s); break;} else return false; break;
            case ']':if(!empty(s) && (front(s) == '[')) {pop(s); break;} else return false;  break;
            case '}':if(!empty(s) && (front(s) == '{')) {pop(s); break;} else return false; break;
        }
        str++;//数组后移
    }
    if(empty(s)) return true;
    return false;
} 
int main() {
    char str[20] = {0};
    while (~scanf("%s",str)) {
        strac *s = init(20);
        if(isvalid(s,str)) printf("true\n");//匹配
        else printf("false\n");
    memset(str, 0, sizeof(str));//清空
    clear(s);
}
return 0;
}
