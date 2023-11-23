/*************************************************************************
	> File Name: 203.c
	> Author: 
	> Mail: 
	> Created Time: Thu 23 Nov 2023 10:07:57 PM CST
 ************************************************************************/

#include<stdio.h>
#define swap(a, b){\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
    }

//单排序
void insert(int *a, int n){
    for(int i = 1; i < n; i++){
        for(int j = i; j > 0; j--){
            if(a[j] > a[j - 1]) swap(a[j], a[j - 1]);
        }
    }
    return ;
}

//每列最大值
int height(int arr[10][10], int n, int m){
    int a[10] = {0};
    for(int i = 0; i < n; i++){
        for(int j = 1; j < m; j++){
            if(arr[j][i] > arr[j - 1][i]) a[i] = arr[j][i];
            else {
                a[i] = arr[j - 1][i];
                swap(arr[j][i], arr[j - 1][i]);
            }
        }
    } 
    for(int k = 0; k < n; k++){
        printf("%d\n", a[k]);
    }
    return 0;
}


int main() {
    int M, N, a = 0, b = 0;
    int arr[10][10] = {0};
    int arr1[105] = {0};
    int sum = 0, c;
    scanf("%d%d", &M, &N);
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++)
        {
            scanf("%d", &arr[i][j]);
            arr1[a] = arr[i][j];
            sum += arr1[a];
            a++;
        }
    }
    height(arr, N, M);
    insert(arr1, a);
    if(sum % a >= a / 2) c = sum / a + 1;
    else c = sum / a;

    for(int k = 0; k < a; k++){
        k && putchar(32);
        printf("%d", arr1[k]);
        if(arr1[k] >= c) b++;
    }

    printf("\n");
    printf("%d\n%d\n", c, b);
    return 0;
}



