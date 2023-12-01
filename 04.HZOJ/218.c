/*************************************************************************
	> File Name: 218.c
	> Author: 
	> Mail: 
	> Created Time: Fri 01 Dec 2023 10:21:08 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 1000
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

void merge(int *a, int *b, int l, int r) {
    if(r - l <= 0) {
        if(r - 1 < 1 && a[l] > a[r]) {
            swap(a[l], a[r]);        
            swap(b[l], b[r]);
        }
        return;
    }
    int mid = (l + r) >> 1;
    merge(a, b, l, mid);
    merge(a, b, mid + 1, r);
    int *temp = (int *)malloc(sizeof(int) * (r - l + 1));
    int *m = (int *)malloc(sizeof(int) * (r - l + 1));
    int p1 = l, p2 = mid + 1, k = 0;
    while(p1 <= mid || p2 <= r) {
        if(p2 > r || (p1 <= mid && a[p1] <= a[p2])) {
            temp[k] = a[p1];
            m[k] = b[p1];
            k++, p1++;
        }
        else {
            temp[k] = a[p2];
            m[k] = b[p2];
            k++, p2++;
        }
    }
    memcpy(a + l, temp, sizeof(int) * (r - l + 1));
    memcpy(b + l, m, sizeof(int) * (r - l + 1));
    free(temp);
    free(m);
    return;
}



void quick(int *a, int *b, int l, int r){
    if(r < l) return ;
    int x = l,y = r, z = a[l], n = b[l];
    while(x < y) {
        while(x < y && a[y] >= z) y--;
        if(x < y) {
            a[x] = a[y];
            b[x] = b[y];
            x++;
        }
        while (x < y && a[x] <= z) x++;
        if(x < y) {
            a[y] = a[x];
            b[y] = b[x];
            y--;
        }
    }
    a[x] = z;
    b[x] = n;
    quick(a, b, l, x - 1);
    quick(a, b, x + 1, r);
    return ;
}

void insert(int *a, int *b, int n){
    for(int i = 2; i <= n; i++){
        for(int j = i; j > 0; j--){
            if(a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
                swap(b[j], b[j - 1]);
            }
        }
    }
    return ;
}

int main() {
    int n, arr1[max + 5] = {0};
    int arr2[max + 5] = {0};
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &arr2[i]);
        arr1[i] = i;
    }
    merge(arr2, arr1, 1, n);
 //   insert(arr2, arr1, n);
    for(int j = 1; j <= n; j++){
        (j - 1) && printf(" ");
        printf("%d", arr1[j]);
    }
    printf("\n");
    return 0;
}


