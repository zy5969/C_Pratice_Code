/*************************************************************************
	> File Name: 1049.最小素数.c
	> Author: 
	> Mail: 
	> Created Time: Sun 24 Dec 2023 09:10:02 AM CST
 ************************************************************************/

#include<stdio.h>
#define max 1000000

int arr[max + 5] = {0};
void prime() {
    for(int i = 2; i <= max; i++){
        if(arr[i]) continue;
        for(int j = i, x = max / i; j <= x; j++){
            arr[i * j] = 1;
        }
    }
    return ;
}

int main() {
    int n;
    prime();
    scanf("%d", &n);
    for(int i = n; i <= max; i++){
        if(arr[i]) continue;
        printf("%d\n", i);
        break;
    }
    return 0;
}


