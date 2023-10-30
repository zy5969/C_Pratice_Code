/*************************************************************************
	> File Name: e5.c
	> Author: 
	> Mail: 
	> Created Time: Mon 30 Oct 2023 08:58:48 PM CST
 ************************************************************************/

//阶乘和
#include<stdio.h>
#define max_n 3628800  //9! * 7

int fun(int *s) {
    s[0] = 1;
    for(int i = 1; i < 10; i++){
        s[i] = s[i - 1] * i;
    }
    return 0;
}

int is_val(int *arr, int n){
    int a = n, temp = 0;
    while(a){
        temp += arr[a % 10];
        a = a / 10;
    }
    return temp == n;
}

int main() {
    int arr[10] = {0};
    int n = 0;
    fun(arr);
    for(int i = 10; i < max_n; i++){
        if(!is_val(arr, i)) continue;//判断符号条件的值
        n += i;
    }
    printf("%d\n", n);
    return 0;
}



