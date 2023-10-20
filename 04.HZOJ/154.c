/*************************************************************************
	> File Name: 154.c
	> Author: 
	> Mail: 
	> Created Time: Fri 20 Oct 2023 09:47:20 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    int n ;
    scanf("%d", &n);
    for(int i = n; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            j && printf(" ");
            printf("%d", i - j);
        }
        printf("\n");
    }

    return 0;
}



