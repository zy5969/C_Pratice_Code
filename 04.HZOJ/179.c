/*************************************************************************
	> File Name: 179.c
	> Author: 
	> Mail: 
	> Created Time: Tue 07 Nov 2023 09:58:24 PM CST
 ************************************************************************/

//二分查找求近似解
#include<stdio.h>
#include <cstdio>
#include <cmath>
#define EPSILON 1e-7
//px+q=0
double bisection(int p, int q, double (*func)(int, int, double));
double f(int p, int q, double x);
int main() {
    int p;
    int q;
    scanf("%d %d", &p, &q);
    printf("%.4lf\n", bisection(p, q, f));
    return 0;
}

double bisection(int p, int q, double (*func)(int, int, double)) {
    double head = -20, tail = 20, mid;
   
    do {
        mid = (head + tail) / 2;
        if(func(p, q, mid) * func(p, q, head) < 0) tail = mid;
        else head = mid;
    //    return head;
    }while(fabs(func(p, q, head) - func(p, q, tail)) > EPSILON);
    return mid;
}

double f(int p, int q, double x) {
    return p * x + q;
}


