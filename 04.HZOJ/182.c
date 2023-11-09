/*************************************************************************
	> File Name: 182.c
	> Author: 
	> Mail: 
	> Created Time: Thu 09 Nov 2023 09:52:35 PM CST
 ************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#define max 1000000
#define swap(a, b){\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

//判断
void quick(int *s, int l, int r){
    if(r < l) return ;
    int x = l,y = r, z = s[l];
    while(x < y) {
        while(x < y && s[y] >= z) y--;
        if(x < y) s[x++] = s[y];
        while (x < y && s[x] <= z) x++;
        if(x < y) s[y--] = s[x];
    }
    s[x] = z;
    quick(s, l, x - 1);
    quick(s, x + 1, r);//
return ;
}

//插入排序
int Max(int *s, int n){
    for(int i = 0; i < n; i++){
        for(int j = i; j > 0; j--) {
            if(s[j] < s[j - 1]) swap(s[j], s[j - 1]);
        }
    }
    
    return 0;
}

int main() {
    int n;
    int arr[max + 5] = {0};
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
   // Max(arr, n);
    quick(arr, 0, n - 1);
    printf("%d\n", arr[n - 1]);
    return 0;
}


