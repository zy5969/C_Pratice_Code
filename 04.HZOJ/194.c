/*************************************************************************
	> File Name: 194.c
	> Author: 
	> Mail: 
	> Created Time: Sun 19 Nov 2023 08:47:52 PM CST
 ************************************************************************/

#include<stdio.h>
#define max 100000

int fun(int a, int b, int s){
    if(a + b == s) return 1;
    else return 0;
}

int main() {
    int n, s;
    int a[max + 5] = {0};
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &s);
    for(int j = 0; j < n; j++){
        for(int k = j + 1; a[k] <= s - a[j]; k++){
            if(fun(a[j], a[k], s)) {
                printf("Yes\n");
                return 0;
            }
        }
    }
    printf("No\n");
    return 0;
}



