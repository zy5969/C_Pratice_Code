/*************************************************************************
	> File Name: 归并+基数.c
	> Author: 
	> Mail: 
	> Created Time: Fri 08 Dec 2023 04:18:00 PM CST
 ************************************************************************/

#include<stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define swap(a ,b) {\
    __typeof(a) __temp = a;\
}

//归并
void merge(int *num, int l, int r){
    if(r - l <= 1) {
        if(r - l <= 1 && num[l] > num[r]) swap(num[l], num[r]);
        return ;
    }
    int mid = (l + r) / 2;
    merge(num, l, mid);
    merge(num, mid + 1, r);
    int *temp = (int *)malloc(sizeof(int) * (r - l + 1));
    int p1 = l, p2 = mid + 1, k = 0;//k存新数组下标位置
    //
    while(p1 <= mid || p2 <= r) {
        if(p2 > r || (p1 <= mid && num[p1] <= num[p2])) {
            temp[k++] = num[p1++];
        }
        else temp[k++] = num[p2++];
    }
    memcpy(num + l, temp, sizeof(int) * (r - l + 1));//拷贝
    free(temp);
    return ;
}

//基数
#define max(a, b) (a > b) ? a : b
int getmax(int *arr, int n){
    int max_n = 0;
    for(int i = 0; i < n; i++){
        max_n = max(arr[i], max_n);
    }
    return max_n;
}

void count(int *arr, int n, int exp) {
    int num[10] = {0};
    //统计数字对应位分组个数，数组大小
    for(int i = 0; i < 10; i++){
        num[arr[i] / exp % 10]++;
    }
    //统计区域尾坐标，
    for(int i = 1; i < 10; i++){
        num[i] += num[i - 1];
    }
    //排序
    int output[n];
    for(int i = n - 1; i >= 0; i--){
        //由基数大小存放数字
        output[num[arr[i] / exp % 10] - 1] = arr[i];
        
        num[(arr[i] / exp) % 10]--;//更新尾坐标
    }
    for(int i = 0; i < n; i++){
        arr[i] = output[i];
    }
    return;
}

void radix(int *arr, int n){
    int max = getmax(arr, n);
    for(int exp = 1; max / exp > 0; exp *= 10){
        count(arr, n, exp);//exp为1,从个位开始
    }
    return ;
}


int main() {
    srand(time(0));
    int arr[20] = {0};
    for(int i = 0; i < 10; i++){
        arr[i] = rand() % 100;
    }
    merge(arr, 0, 9);
  //  radix(arr, 10);
    for(int j = 0; j < 10; j++){
        j && printf(" ");
        printf("%d", arr[j]);
    }
    printf("\n");
    return 0;
}



