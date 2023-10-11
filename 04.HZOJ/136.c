/*************************************************************************
	> File Name: 136.c
	> Author: 
	> Mail: 
	> Created Time: Wed 11 Oct 2023 07:48:48 PM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if(n == 0) return 0;
    for(int i = 1; i <= n; i++) {
          if(i % 7 == 0) printf("%d\n", i);

    }
    return 0;
}



