/*************************************************************************
	> File Name: KMP.c
	> Author: 
	> Mail: 
	> Created Time: Mon 11 Dec 2023 09:09:07 AM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>


int *getnext(char *s, int n){
    int *next = (int *)malloc(sizeof(int) * n);
    next[0] = -1;
    int p = -1;
    for(int i = 1; s[i]; i++){
        while(p != -1 && s[i] != s[p + 1]) p = next[p];
        if(s[i] == s[p + 1]) {
            next[i] = next[i - 1] + 1;
            p++;
        }
     //   if(s[i] == s[p + 1]) p++;
        else next[i] = -1;
    }
    for(int j = 0; j < n; j++){
        printf("%d ", next[j]);
    }
    printf("\n");
    return next;
}

int KMP(char *s1, char *s2){
    int a = strlen(s1), b = strlen(s2);
    int *next = getnext(s2, b);
    int p = -1;
    for(int i = 0; s1[i]; i++){
        while(p != -1 && s1[i] != s2[p + 1]) p = next[p];
        if(s1[i] == s2[p + 1]) p++;
        if(s2[p + 1] == '\0') {
            free(next);
            return i - b + 1;
        }
    }
    return -1;
}

int main() {
    char s[100] = {0};
    char t[100] = {0};
    scanf("%s%s", s, t);
    printf("result: %d\n", KMP(s, t));
    return 0;
}


