/*************************************************************************
	> File Name: 199.c
	> Author: 
	> Mail: 
	> Created Time: Tue 21 Nov 2023 08:39:37 PM CST
 ************************************************************************/


#include<stdio.h>
#define max_n 100000

int num[max_n + 5] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int fun(int *arr, int x){
    return arr[1] * num[x - 1] + arr[2] * num[x - 2]
        + arr[3] * num[x - 3] + arr[4] * num[x - 4]
        + arr[5] * num[x - 5] + arr[6] * num[x - 6]
        + arr[7] * num[x - 7] + arr[8] * num[x - 8]
        + arr[9] * num[x - 9]+ arr[10] * num[x - 10];
}

int main() {
    int k, m, s = 0;
    int arr[11] = {0};
    scanf("%d%d", &k, &m);
    for(int i = 1; i < 11; i++){
        scanf("%d", &arr[i]);
    }
    for(int j = 10; j <= k; j++){
        num[j] = fun(arr, j) % m;
    }
    printf("%d\n", num[k]);
    return 0;
}



