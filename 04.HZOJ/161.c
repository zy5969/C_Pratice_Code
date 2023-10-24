/*************************************************************************
	> File Name: 161.c
	> Author: 
	> Mail: 
	> Created Time: Tue 24 Oct 2023 08:43:02 PM CST
 ************************************************************************/

#include <stdio.h>
#define p 1.06

int main() {
    int x, n;
    double m = 1;
    scanf("%d%d", &x, &n);
    for(int i = 1; i <= n; i++) {
        m = m * p;
    }
    printf("%.6lf\n", x * m);
    return 0;
}


