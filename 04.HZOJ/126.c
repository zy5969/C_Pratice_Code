/*************************************************************************
	> File Name: 126.c
	> Author: 
	> Mail: 
	> Created Time: Fri 06 Oct 2023 10:58:14 PM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    double r1, r2, s;
    scanf("%lf%lf", &r1, &r2);
    s = 3.14 * (r1 * r1 - r2 * r2);
    printf("%.2lf\n", s);
    return 0;
}

