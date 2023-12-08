/*************************************************************************
	> File Name: bincheck.c
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Dec 2023 04:32:26 PM CST
 ************************************************************************/

#include<stdio.h>
#include <time.h>
#include <stdlib.h>

int bin(int *sum, int a, int b, int val){
    if(a > b) return 0;
    int i = a, j = b, mid;
    while(i <= j){
        mid = (i + j) / 2;
        if(sum[mid] > val) j = mid - 1;
        else if(sum[mid] == val) return mid;
        else i = mid + 1;
    }
    return -1;
}

int main() {
    srand(time(0));
    int sum[10] = {12, 18, 23, 24, 54, 61, 73, 80, 92, 98};
    printf("12, 18, 23, 24, 54, 61, 73, 80, 92, 98\n");
    int n;
    while(~scanf("%d", &n)) {
        printf("result: %d\n", bin(sum, 0, 9, n));
    }
    return 0;
}


