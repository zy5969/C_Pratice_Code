/*************************************************************************
	> File Name: 131.c
	> Author: 
	> Mail: 
	> Created Time: Sun 08 Oct 2023 10:48:16 PM CST
 ************************************************************************/

#include <stdio.h>
#define max 10001
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}


int main() {
    int n, x;
    int arr[max + 5] = {0};
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d",&x);
        arr[i] = x;
    }
    for(int j = 1; j < n; j++) {
        for(int k = j; k > 0 && arr[k] < arr[k - 1]; k--) {
            swap(arr[k], arr[k - 1]);
        }
    }
   
    printf("%d\n", arr[n - 1] - arr[0]);
    return 0;
}


