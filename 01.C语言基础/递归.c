/*************************************************************************
	> File Name: 递归.c
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Dec 2023 10:19:53 AM CST
 ************************************************************************/

#include <stdio.h>

int fun(int n) {
    if(n == 1 || n == 2) return 1;
    return fun(n - 1) + fun(n - 2);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", fun(n));
    return 0;
}
