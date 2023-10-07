/*************************************************************************
	> File Name: 128.c
	> Author: 
	> Mail: 
	> Created Time: Sat 07 Oct 2023 09:36:07 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    
    float n, m;
    int i, b=0, a=0;
    
    scanf("%f\n", &n);
    for(i = 0;i < n; i++) { 
        scanf("%d", &a);
        b = b + a;
    }

    m = b / n;
    printf("%.2f\n", m);

    return 0;
}

