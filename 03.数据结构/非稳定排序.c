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
void shell(int *arr, int n){
    int step = n / 2;//初始步长
    int temp;
    for(step; step > 0; step /= 2){ //递减
        for(int i = step; i < n; i++){
            temp = arr[i];//步长位置上的数
            int j;
            for(j = i; j >= step && arr[j - step] >  temp; j -= step){
                swap(arr[j] , arr[j - step]);//步长左边数大，移到右边
            }
         //   arr[j] = step;
        }
    }
    return;
}


//堆
void build(int *arr, int val, int n){
    int a = n;
    while(a >> 1 && arr[a] > arr[a >> 1]){
        swap(arr[a], arr[a >> 1]);
        a >>= 1;
    }
    return ;
}

void sortnum(int *arr, int n){
    for(int i = 1; i < n; i++){
        build(arr, arr[i], i);
    }
    for(int i = n - 1; i >= 1; i--){
        int ind = 1;
        swap(arr[ind], arr[i]);
        while((ind << 1) <= (i - 1)) {
            int temp = ind, a = ind << 1, b = ind << 1 | 1;
            if(arr[temp] < arr[a]) temp = a;
            if((b <= i - 1) && arr[b] > arr[temp]) temp = b;
            if(temp == ind) break;
            swap(arr[ind], arr[temp]);
            ind = temp;
        }
    }
    return;
}


int main(){
    srand(time(0));
    int arr[100] = {0};
    for(int i = 0; i < 10; i++){
        arr[i] = rand() % 100;
    }
    
    for(int j = 0; j < 10; j++){
        j && printf(" ");
        printf("%d", arr[j]);
    }
    printf("\n");
  //  mainshell(arr);
    shell(arr, 10);
  //  sortnum(arr, 11);
//    selet(arr, 10);
//    quick(arr, 0, 9);
    for(int j = 0; j < 10; j++){
        j && printf(" ");
        printf("%d", arr[j]);
    }
    printf("\n");
    return 0;
}

