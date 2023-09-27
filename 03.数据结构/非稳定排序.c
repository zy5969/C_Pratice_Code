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
        if(r - 1 <= 1 && num[l] > num[r]){
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
//取最大值
#define max(a, b) (a >  b) ? a : b
int get_max(int *arr, int n){
    int max_n = 0;
        for(int i = 0; i < n; i++){
            max_n = max(max_n, arr[i]);
        }
    return max_n;
}

//按照指定的位数进行基数排序
//exp,从1开始一直到最大值的位数，exp表示从个位开始
void counts(int *num, int n, int exp) {
    int count[10] = {0};
    //循环统计每个数字的对应位的分组个数
    for(int i = 0; i < n;i++) {
        count[num[i] / exp % 10]++;
    }
    //循环统计每个基数区域尾坐标,从1开始，第一个就是确定的尾坐标
    for(int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    //排序
    int output[n];
    for(int i = n - 1; i >= 0; i--) {
        output[count[num[i] / exp % 10] - 1] = num[i];
        //更新尾坐标
        count[(num[i] / exp) % 10]--;
    }
    for(int i = 0; i < n; i++) {
        num[i] = output[i];
    }
    return ;
}

//基数排序
void radix(int *num, int n) {
    int max = get_max(num, n);
    for(int exp = 1; max / exp > 0; exp *= 10) {
        counts(num, n, exp);
    }
}

int main(){
    srand(time(0));
    int arr[100] = {0};
    for(int i = 0; i < 10; i++){
        arr[i] = rand() % 100;
    }
 //   bubble(arr, 10);
//    merge(arr, 0, 9);
    radix(arr, 10);
 //   insert(arr, 10);
    for(int j = 0; j < 10; j++){
        j && printf(" ");
        printf("%d", arr[j]);
    }
    printf("\n");
    return 0;
}

