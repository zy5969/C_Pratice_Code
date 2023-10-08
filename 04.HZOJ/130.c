/*************************************************************************
	> File Name: 130.c
	> Author: 
	> Mail: 
	> Created Time: Sun 08 Oct 2023 10:46:55 PM CST
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int main(){
    int m, n;
    double i, L=1.00417;
    double M=0;
    scanf("%d%d", &m, &n);
    for(i=1;i<=n;i++) M = M + m * pow(L,i);
    printf("$%.2lf\n", M);

    return 0;
}

