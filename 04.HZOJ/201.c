/*************************************************************************
	> File Name: 201.c
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Nov 2023 08:35:14 PM CST
 ************************************************************************/

#include <stdio.h>
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

//去重
int a = 0;
void clean(int *arr, int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] && arr[i] == arr[j]) {
                arr[j] = 0;
                a++;
            }
        }
    } 
    printf("%d\n", n - a);
    return ;
}

//排序
void select(int *s, int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(s[i] > s[j]) swap(s[i], s[j]);
        }
    }
    return ;
}

int main() {
    int n, arr[105] = {0};
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    clean(arr, n);
    select(arr, n);
    for(int j = a; j < n; j++){
        (j - a) && printf(" ");
        printf("%d", arr[j]);
    }
    printf("\n");
    return 0;
}



