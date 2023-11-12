/*************************************************************************
	> File Name: 189.c
	> Author: 
	> Mail: 
	> Created Time: Sun 12 Nov 2023 08:44:43 PM CST
 ************************************************************************/

#include <stdio.h>
#define max_n 1000000

int reserch(int *arr, int a, int x){
    int max = a, min = 1, mid;
    
    while(max >= min) {
        mid = (max + min) / 2;
        if(x > arr[mid]) min = mid + 1;
        else if(x == arr[mid]) return mid;
        else max = mid - 1;
        
    }

    return 0;
}

int main() {
    int N, K;
    int arr1[max_n + 5] = {0};
    int arr2[max_n + 5] = {0};
    scanf("%d%d", &N, &K);
    for(int i = 1; i <= N; i++){
        scanf("%d", &arr1[i]);
    }
    for(int j = 0; j < K; j++){
        scanf("%d", &arr2[j]);
    }
    
    
    for(int a = 0; a < K; a++){
        a && printf(" ");
        printf("%d", reserch(arr1, N, arr2[a]));
    }
    printf("\n");
    return 0;
}


