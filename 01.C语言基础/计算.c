/*************************************************************************
	> File Name: 计算.c
	> Author: 
	> Mail: 
	> Created Time: Thu 07 Dec 2023 10:38:13 AM CST
 ************************************************************************/

#include<stdio.h>

int count(int a, int b, int *x, int *y) {
    if(b == 0){
        *x = 1;
        *y = 0;
        return a;
    }
    int x1, y1, ans;
    ans = count(b, a % b, &x1, &y1);
    *y = x1 - a / b * y1;
    *x = y1;
    return ans;
}

int main() {
    int a, b, y, x;
    scanf("%d%d", &a, &b);
    int ans = count(a, b, &x, &y);
    printf("x = %d, y = %d\n", x, y);
    return 0;
}


