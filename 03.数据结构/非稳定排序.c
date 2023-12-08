//排序
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define swap(a, b){\
    __typeof(a) __temp = a;\
    a = b; b = __temp; }

//选择
void selet(int *num, int n) {
    
    for(int i = 0; i < n - 1; i++){
        int x = i;
        for(int j = i + 1; j < n; j++){
            if(num[x] < num[j]) x = j;//保留最大/小值下标
        }
        swap(num[i], num[x]);
    }    
    return ;
}
//快速
void quick(int *num, int l, int r){
    if(l > r) return ;
    int a = l, b = r, m = num[l];
    while(a < b){
        while(a < b && num[b] >= m) b--;
        if(a < b ) num[a++] = num[b];
        while(a < b && num[a] <= m) a++;
        if(a < b) num[b--] = num[a];
    }
    num[a] = m;
    //分区
    quick(num, l, a - 1);
    quick(num, a + 1, r);
    return ;    
}

//希尔

//堆


int main(){
    srand(time(0));
    int arr[100] = {0};
    for(int i = 0; i < 10; i++){
        arr[i] = rand() % 100;
    }
//    selet(arr, 10);
    quick(arr, 0, 9);
    for(int j = 0; j < 10; j++){
        j && printf(" ");
        printf("%d", arr[j]);
    }
    printf("\n");
    return 0;
}

