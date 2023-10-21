/*************************************************************************
	> File Name: 156.c
	> Author: 
	> Mail: 
	> Created Time: Sat 21 Oct 2023 08:56:22 PM CST
 ************************************************************************/

#include <stdio.h>

int sqr(int i) {
    for(int j = 1; j <= i; j++){
        if(j * j == i) return 1;
    }
    return 0;
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int n = 0;
    for(int i = a; i <= b; i++) {
        int flag = 0;
        for(int j = 2; j * j <= i; j++){
            if(i % j == 0) {
                flag = 1; 
                break;
            }
        }

        if(!flag && sqr(i / 100) && sqr(i % 100)) {
            n && printf(" ");
            printf("%d", i);
            n++;
        }
    }
    printf("\n");
    printf("%d\n", n);

    return 0;
}




