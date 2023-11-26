/*************************************************************************
	> File Name: 208.c
	> Author: 
	> Mail: 
	> Created Time: Sun 26 Nov 2023 09:35:54 PM CST
 ************************************************************************/

#include<stdio.h>
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}
//排序
int select(int *arr, int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] < arr[j]) swap(arr[i], arr[j]);
        }
    }
    return 0;
}
//记相同数字的对应他们相同的个数
int cnt[100] = {0};
int count (int *arr, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i] == arr[j]) cnt[i] += 1;
        }
    }
    return 0;
}

int main() {
    int M, N, n = 0;
    int arr[100] = {0};
    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d", &N);
    select(arr, M);
    count(arr, M);
    for(int j = 0; j < M; j++){
        if(cnt[j] >= N) {
            printf("%d\n", cnt[j]);
            break;
        }
    }
    return 0;
}



