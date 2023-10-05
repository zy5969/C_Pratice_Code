/*************************************************************************
	> File Name: 124.c
	> Author: 
	> Mail: 
	> Created Time: Thu 05 Oct 2023 11:12:44 PM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
  /*  if(a==1 || a==2 || b <= 50) {
        if(c <= 25 || d >= 5) printf("ok\n");
        else printf("pass\n");
    }*/
    if((a == 1 || a ==2 || b <= 50) && (c <= 25 || d >= 5)) printf("ok\n");
    else printf("pass\n");
    return 0;
}

