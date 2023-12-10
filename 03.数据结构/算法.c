/*************************************************************************
	> File Name: 算法.c
	> Author:暴力匹配、KMP、Sunday、Shift_And 
	> Mail: 
	> Created Time: Sun 10 Dec 2023 10:59:45 AM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define PUT(func) {\
    char temp_s[200];\
    sprintf(temp_s, "%s result %d", #func, func(str, s));\
    printf("%s\n", temp_s);\
}


//暴力匹配
int Brue(char *s1, char *s2){
    int a = strlen(s1), b = strlen(s2);
    for(int i = 0; (i + b) <= a; i++){
        int flag = 1;
        for(int j = 0; j < b; j++){
            if(s1[j + i] == s2[j]) continue;
            else {
                flag = 0;
                break;
            }
        }
        if(flag) return i;
    }
    return -1;
}

//KMP*
//处理模式串T（短）获取next数组
int *getnext(char *s, int n){
    int *next = (int *)malloc(sizeof(int) * n);
    next[0] = -1;
    int p = -1;
    for(int i = 1; s[i]; i++){
        while(p != -1 && s[i] != s[p + 1]) p = next[p];
        if(s[i] == s[p + 1]) next[i] = next[i - 1] + 1;
        else next[i] = -1;
    }
    return next;
}

int KMP(char *s1, char *s2){
    int n = strlen(s2);
    int *next = getnext(s2, n); 
    int p = -1;
    for(int i = 0; s1[i]; i++){
        while(p != -1 && s1[i] != s2[p + 1]) p = next[p];
        if(s1[i] == s2[p + 1]) p++;
        if(s2[p + 1] == '\0') {
            free(next);
            return i - n + 1;
        }
    }
    return -1;
}

//Sunday*
int Sunday(char *s1, char *s2){
    int str[256] = {0};
    int l = strlen(s2);
    //处理模式串，记为倒数第几位
    for(int i = 0; s2[i]; i++) str[s2[i]] = l - i;

    for(int j = 0; (l + j) <= strlen(s1); j++){
        int flag = 1;
        for(int i = 0; s2[i]; i++){
            if(s2[i] == s1[i + j]) continue;
            else {
                flag = 0;
                break;
            }
        }
        if(flag) return j;
        j += str[s2[l + j]];//匹配失败后移至下一个匹配点
    }
    return -1;
}

//shift_and*
int Shift_And(char *s1, char *s2){
    int ind[256] = {0};
    int n = strlen(s2);
    //预处理表
    for(int i = 0; s2[i]; i++){
        ind[s2[i]] |= (1 << i);
    }
    int p = 0;
    for(int j = 0; s1[j]; j++){
        p = (p << 1 | 1) & ind[s1[j]];//求P值
        if(p & (1 << (n - 1))) return j - n + 1;//判断第几位匹配成功
    }
    return -1;
}

char str[50] = {0};
char s[50] = {0};
int main() {
    scanf("%s%s", str, s);
  //  int m;
  //  m = Brue(str, s);
    PUT(Brue);
    PUT(KMP);
    PUT(Sunday);
    PUT(Shift_And);
    printf("------------------------\n");
    printf("Brue result: %d\n", Brue(str, s));
    printf("KMP  result: %d\n", KMP(str, s));
    printf("Sunday    result: %d\n", Sunday(str, s));
    printf("Shift_And result: %d\n", Shift_And(str, s));
    return 0;
}


