/*************************************************************************
	> File Name: 205.c
	> Author: 
	> Mail: 
	> Created Time: Fri 24 Nov 2023 09:48:58 PM CST
 ************************************************************************/

#include <stdio.h>

int average(int a[30][30], int n, int m){
    int s = 0;
    int arr[30] = {0};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            s += a[i][j];
        }
        arr[i] = s;
        s = 0;
    }
    for(int k = 0; k < n; k++){
        double cnt = 1.0 * arr[k] / m;
        printf("%.6lf\n", cnt);
    }
    return 0;
}

int main() {
    int n, m;
    int arr[30][30] = {0};
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    average(arr, n, m);
    return 0;
}



