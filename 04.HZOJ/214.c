/*************************************************************************
	> File Name: 214.c
	> Author: 
	> Mail: 
	> Created Time: Wed 29 Nov 2023 10:48:59 PM CST
 ************************************************************************/

#include <stdio.h>
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

int search(int *a, int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] < a[j]) swap(a[i], a[j]);
        }
    }
    return 0;
}

int main() {
    int N, n;//人数，前几名
    int arr[30] = {0};//分数
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d", &n);
    search(arr, N);
    double s = 0;
    for(int j = 0; j < n; j++){
        s += arr[j];
    }
    printf("%.2lf\n", s / n);
    return 0;
}


