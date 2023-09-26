//排序
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define swap(a, b){\
    __typeof(a) __temp = a;\
    a = b; b = __temp; }

//插入排序
void insert(int *num, int n){
    for(int i = 1; i < n; i++){
        for(int j = i; j > 0 && num[j] < num[ j - 1]; j--){
            swap(num[j], num[j - 1]);
        }
    }
    return ;
}

//冒泡排序
void bubble(int *num, int n){
    int times = 1;
    for(int i = 0; i < n && times; i++){
        for(int j = 0; j < n - i; j++){
            times = 0;
            if(num[j] < num[j + 1]) continue;
            swap(num[j], num[j + 1]);
            times++;
        }
    }
    return ;
}

//归并排序
void merge(int *num , int l, int r) {
    if(r - l <= 1) {
        if(r - l <= 1 && num[l] > num[r]){
            swap(num[l], num[r]);
        }
        return ;
    } 
    int mid = (l + r) >> 1;
    merge(num, l, mid);
    merge(num, mid + 1, r);
    int *temp = (int *)malloc(sizeof(int) * (r - l + 1));
    int p1 = l, p2 = mid + 1, k = 0;
    while(p1 < mid || p2 <= r){
        if(p2 > r || (p1 <= mid && num[p1] <= num[p2])) {
            temp[k++] = num[p1++];
        }
        else temp[k++] = num[p2++];
    }
    memcpy(num + l, temp, sizeof(int) * (r - l + 1));
    free(temp);
    return ;
}


int main(){
    srand(time(0));
    int arr[100] = {0};
    for(int i = 0; i < 10; i++){
        arr[i] = rand() % 100;
    }
 //   bubble(arr, 10);
    merge(arr, 0, 9);
 //   insert(arr, 10);
    for(int j = 0; j < 10; j++){
        j && printf(" ");
        printf("%d", arr[j]);
    }
    printf("\n");
    return 0;
}

