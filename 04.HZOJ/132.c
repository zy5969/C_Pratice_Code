/*************************************************************************
	> File Name: 132.c
	> Author: 
	> Mail: 
	> Created Time: Mon 09 Oct 2023 10:35:33 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int n, m, i;
    long long int x=1;
    scanf("%d\n", &n);
    for(i=0;i<n;i++)  {
        scanf("%d", &m);
        x = x * m;
    }
    printf("%lld\n", x);
    return 0;

}
