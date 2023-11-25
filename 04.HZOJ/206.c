/*************************************************************************
	> File Name: 206.c
	> Author: 
	> Mail: 
	> Created Time: Sat 25 Nov 2023 09:47:15 PM CST
 ************************************************************************/

#include <stdio.h>

int sum(int (*arr)[30], int n, int m){
    int s[30] = {0};
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            s[i] += arr[j][i];
        }
        printf("%d\n", s[i]);
    }
    return 0;
}

int main() {
    int n, m, arr[30][30] = {0};
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    sum(arr, n, m);
    return 0;
}



