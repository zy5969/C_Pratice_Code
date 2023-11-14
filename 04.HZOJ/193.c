/*************************************************************************
	> File Name: 193.c
	> Author: 
	> Mail: 
	> Created Time: Tue 14 Nov 2023 07:57:12 PM CST
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#define e 2.718282



int fun(int a, double x){
    x = log(a / x);
    if(a == 0) x = 0;
    
    return fun(a, x);
   // else if(a / x * 1.0 == pow(e, x)) return x;
}


int main() {
    int a;
    double b,c;
    scanf("%d", &a);
    b = fun(a, c);
    
    printf("%.4lf\n", b);
    return 0;
}



