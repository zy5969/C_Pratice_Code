/*************************************************************************
	> File Name: 209.c
	> Author: 
	> Mail: 
	> Created Time: Sun 26 Nov 2023 09:36:40 PM CST
 ************************************************************************/

#include<stdio.h>
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

void insert(double *arr, int n){
    for(int i = 1; i < n; i++){
        for(int j = i; j > 0; j--){
            if(arr[j] < arr[j - 1]) swap(arr[j], arr[j - 1]);
        }
    }
    return ;
}

int main() {
    int N;
    double arr[100] = {0};
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%lf", &arr[i]);
    }
    insert(arr, N);
    for(int i = 0; i < N; i++){
        printf("%g\n", arr[i]);
    }
    return 0;
}


