/*************************************************************************
	> File Name: 155.c
	> Author: 
	> Mail: 
	> Created Time: Sat 21 Oct 2023 08:55:01 PM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    int n, m = 3;
    scanf("%d", &n);
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        printf("%d\n", m);
        sum += m;
        m = m + 2 * i;
    }
    printf("%d\n", sum);
    return 0;
}



