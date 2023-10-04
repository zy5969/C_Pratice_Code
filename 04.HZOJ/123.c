/*************************************************************************
	> File Name: 123.c
	> Author: 
	> Mail: 
	> Created Time: Wed 04 Oct 2023 10:53:20 PM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    double a, b, c, d;
    scanf("%lf%lf\n%lf%lf", &a, &b, &c, &d);
   // scanf("%lf%lf", &c, &d);
    if(a >= c && b<=d && a<b && c<d) printf("YES\n");
    else printf("NO\n");
    return 0;
}

