/*************************************************************************
	> File Name: 187.c
	> Author: 
	> Mail: 
	> Created Time: Sat 11 Nov 2023 08:54:01 PM CST
 ************************************************************************/

#include<stdio.h>
//次数
long once(int n){
    if(n == 1) return 1;
    return 2 * once(n - 1) + 1;
}
//体力
long fun(int n) {
    if(n == 1) return 1;
    return 2 * fun(n - 1) + n;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%ld %ld\n", once(n), fun(n));
    return 0;
}



