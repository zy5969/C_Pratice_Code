/*************************************************************************
	> File Name: 198.c
	> Author: 
	> Mail: 
	> Created Time: Tue 21 Nov 2023 08:38:07 PM CST
 ************************************************************************/

#include<stdio.h>
#define f 1000000007
#define max 100000

int fun(int n) {
    unsigned int arr[max + 5] = {0};
    arr[1] = 1, arr[2] = 1;
    
    for(int i = 3; i <= n; i++){
        arr[i] = arr[i - 1] + arr[i - 2];
        arr[i] = arr[i] % f;
    }
    return arr[n];
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", fun(n));
    return 0;
}



