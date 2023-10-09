/*************************************************************************
	> File Name: 133.c
	> Author: 
	> Mail: 
	> Created Time: Mon 09 Oct 2023 10:55:58 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int n, i, j;

    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        for(j = i; j <= n; j++) {
          //  printf("%d*%d=%d\t", i, j, i * j);
            if(j == n) printf("%d*%d=%d", i, j, i * j);
            else printf("%d*%d=%d\t", i, j, i*j);
        }
       // printf("\b");
        printf("\n");
    }
    return 0;

}

