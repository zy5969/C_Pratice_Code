/*************************************************************************
	> File Name: 163.c
	> Author: 
	> Mail: 
	> Created Time: Tue 24 Oct 2023 08:44:20 PM CST
 ************************************************************************/

#include<stdio.h>
#include<math.h>


int main(){
    double a, b, d, e;
    scanf("%lf%lf%lf", &a, &b, &e);
    d = sqrt(a * a + b * b - 2 * a * b * cos(e * acos(-1) / 180));
    printf("%.6lf\n", d);
    return 0;
}

