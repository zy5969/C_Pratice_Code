/*************************************************************************
	> File Name: 195.c
	> Author: 
	> Mail: 
	> Created Time: Sun 19 Nov 2023 08:48:43 PM CST
 ************************************************************************/

#include <stdio.h>
#define max_n 100000

int bin_serch(int *s, int val, int n){
    int min = 0, max = n, mid;
    if(val > s[max]) return max;
    if(val < s[min]) return min;
    while(max >= min){
        mid = (min + max) / 2;
        if(s[mid] == val) return mid;
        if(s[mid] > val) max = mid -1;
        else min = mid + 1;
    }
    if(s[mid] > val) return mid - 1;
    else return mid;
}

int main() {
    int n, m;
    int a[max_n + 5] = {0}, b[max_n + 5] = {0};
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < m; i++){
        scanf("%d", &b[i]);
    }

    for(int j = 0; j < m; j++){
        j && printf(" ");
        int x = bin_serch(a, b[j], n -1);   
        printf("%d", a[x]);
    }
    printf("\n");
    return 0;
}



