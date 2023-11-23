/*************************************************************************
	> File Name: 202.c
	> Author: 
	> Mail: 
	> Created Time: Thu 23 Nov 2023 10:07:27 PM CST
 ************************************************************************/

#include<stdio.h>
#define max 1000
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
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
    int n, arrn[max + 5] = {0};
    int arrh[max + 5] = {0};
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &arrh[i]);
        arrn[i] = i;
    }
    insert(arrh, arrn, n);
    for(int j = 1; j <= n; j++){
        (j - 1) && printf(" ");
        printf("%d", arrn[j]);
    }
    printf("\n");
    return 0;
}



