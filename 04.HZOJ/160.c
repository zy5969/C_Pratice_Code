/*************************************************************************
	> File Name: 160.c
	> Author: 
	> Mail: 
	> Created Time: Mon 23 Oct 2023 08:05:09 PM CST
 ************************************************************************/

#include<stdio.h>
#include <math.h>
#define pi 3.14

int main() {
    double r, h, s;
    scanf("%lf%lf", &r, &h);
    s = (4 + pi) * r * r + r * h * (2 * sqrt(2) + pi + 2);
    printf("%.2lf\n", s);

    return 0;
}



