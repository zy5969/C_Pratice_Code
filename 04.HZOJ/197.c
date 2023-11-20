/*************************************************************************
	> File Name: 197.c
	> Author: 
	> Mail: 
	> Created Time: Mon 20 Nov 2023 07:15:14 PM CST
 ************************************************************************/

//选择排序
#include<stdio.h>
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

void select(int *arr, int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] < arr[j]) swap(arr[i], arr[j]);
        }
    }
    return ;
}

int main() {
    int arr[10] = {0};
    for(int i = 0; i < 10; i++){
        scanf("%d", &arr[i]);
    }
    select(arr, 10);
    for(int j = 0; j < 10; j++){
        j && printf(" ");
        printf("%d", arr[j]);
    }
    printf("\n");
    return 0;
}



