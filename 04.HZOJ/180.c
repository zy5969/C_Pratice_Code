/*************************************************************************
	> File Name: 180.c
	> Author: 
	> Mail: 
	> Created Time: Wed 08 Nov 2023 08:58:05 PM CST
 ************************************************************************/

#include <math.h>
#include <stdio.h>

double mpow(int n) {
    double a = 1;
    
    for(int i = 0; i < n; i++) {
        
        a = 2 * a;
    }
   
    return a;
}


int main() {
    int n;
    scanf("%d", &n);
    double a = mpow(n);
   // printf("%lf\n", pow(2,63));
    printf("%.0lf\n", a);
    return 0;
}


