/*************************************************************************
	> File Name: 184.c
	> Author: 
	> Mail: 
	> Created Time: Fri 10 Nov 2023 08:03:59 PM CST
 ************************************************************************/

#include <stdio.h>
//倒着算：第一天为1，随后每天为前一天加1的两倍
int fun(int n) {
    if(n == 1) return 1;
    return (fun(n - 1) + 1) * 2;
}  

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", fun(n));

    return 0;
}


