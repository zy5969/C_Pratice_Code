/*************************************************************************
	> File Name: 1047.素数.c
	> Author: 
	> Mail: 
	> Created Time: Sun 24 Dec 2023 08:52:59 AM CST
 ************************************************************************/

#include<stdio.h>
#define max 1000000

int arr[max + 5] = {1, 1};
void prime(){
    for(int i = 2; i <= max; i++){
        if(arr[i]) continue;
        for(int j = i, d = max / i; j <= d; j++){
            arr[i * j] = 1;
        }
    }
    return ;
}

int main() {
    int n, m = 0;
    prime();
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        if(arr[i]) continue;
        m++;
    }
    printf("%d\n", m);
    return 0;
}

