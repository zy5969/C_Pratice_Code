/*************************************************************************
	> File Name: 219.c
	> Author: 
	> Mail: 
	> Created Time: Fri 01 Dec 2023 10:26:22 PM CST
 ************************************************************************/

#include <stdio.h>
#define max 10000
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

void insert(int *a, int l, int r, int flag){
    for(int i = l + 1; i <= r; i++){
        for(int j = i; j > l; j--){
            if(flag == 1 && a[j] < a[j - 1]) swap(a[j], a[j - 1]);
            if(flag == 2 && a[j] > a[j - 1]) swap(a[j], a[j - 1]);
        }
    }
    return ;
}

int main() {
    int n, l1, r1, l2, r2;
    int arr[max + 5] = {0};
    scanf("%d%d%d%d%d", &n, &l1, &r1, &l2, &r2);
    for(int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
    }
    insert(arr, l1, r1, 1);
    insert(arr, l2, r2, 2);
    for(int j = 1; j <= n; j++){
        (j - 1) && printf(" ");
        printf("%d", arr[j]);
    }
    printf("\n");
    return 0;
}




