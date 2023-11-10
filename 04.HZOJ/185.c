/*************************************************************************
	> File Name: 185.c
	> Author: 
	> Mail: 
	> Created Time: Fri 10 Nov 2023 08:05:21 PM CST
 ************************************************************************/

#include<stdio.h>

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


