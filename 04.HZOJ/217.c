/*************************************************************************
	> File Name: 217.c
	> Author: 
	> Mail: 
	> Created Time: Thu 30 Nov 2023 10:08:31 PM CST
 ************************************************************************/

#include<stdio.h>
#define max_n 100000
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}
/*
void quick(int *arr, int n, int m){
    if(n > m) return ;
    int a = n, b = m, c = arr[(n + m) / 2];
    while(a <= b){
        while(a < b && arr[b] >= c) b--;
        if(a < b ) arr[a++] = arr[b];
        while (a < b && arr[a] <= c) a++;
        if(a < b) arr[b--] = arr[a];
    }
    arr[a] = c ;
    quick(arr, n, m - 1);
    quick(arr, n + 1, m);
    return ;
}
*/
void quick(int *arr, int l, int r){
    if(l > r) return ;
    int a = l, b = r, c = arr[(l + r) / 2];
    do{
        while(a <= b && arr[a] < c) a++;
        while(a <= b && arr[b] > c) b--;
        if(a <= b){
            swap(arr[a], arr[b]);
            a++, b--;
        }
    }while(a <= b);
    quick(arr, a, r);
    r = b;
    quick(arr, l, b);
    return ;
}

int select(int *arr, int n) {
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] < arr[j]) swap(arr[i], arr[j]);
        }
    }
    return 0;
}

int main() {
    int n, m = 0;
    int arr[max_n + 5] = {0};
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    quick(arr, 0, n - 1);
   // select(arr, n);
    for(int j = 0; j < n; j++){
        if(arr[j] >= arr[n / 2]) m++;
      //  printf("%d ", arr[j]);
    }
    printf("%d %d\n", arr[n / 2], m);
    return 0;
}




