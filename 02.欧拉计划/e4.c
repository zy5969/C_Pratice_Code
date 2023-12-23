/*************************************************************************
	> File Name: e4.c
	> Author: 
	> Mail: 
	> Created Time: Sun 29 Oct 2023 09:40:46 PM CST
 ************************************************************************/

#include<stdio.h>

int count() {
    int s1 = 1, s2 = 1;
    for(int i = 2; i <= 100; i++){
        s1 = s1 + i * i;
        s2 = s2 + i;
//        printf("%d * %d = %d \n", i, i, i * i);
    }
    printf("%d %d\n", s1, s2);
    printf("%d\n", s1 - s2 * s2);
    return 0;
}


//优化

int main() {
    int sum1 = (1 + 100) * 100 / 2;
    int sum2 = 100 * 201 * 102 / 6;
    count();
    printf("优化:\n");
    printf("%d %d\n", sum1 , sum2);
    printf("%d\n", sum2 - sum1);
    return 0;
}



