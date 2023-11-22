/*************************************************************************
	> File Name: 200.c
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Nov 2023 08:21:00 PM CST
 ************************************************************************/

#include<stdio.h>

int fun(int *arrx, int *arry, int n, int x, int y){
    for(int i = 1; i <= n; i++){
        if(i == 1) {
            arrx[i] = x;
            arry[i] = y;
        }
        if(i > 1) {
            arrx[i] = arry[i - 1];
            arry[i] = arrx[i - 1] + arry[i - 1];
        }
    }
    return 1;
}

int main() {
    int N;
    double sum = 0;
    int arrx[35] = {0};
    int arry[35] = {0};
    scanf("%d", &N);
    fun(arrx, arry, N, 4, 7);
    for(int i = 1; i <= N; i++){
        sum += 1.0 * arrx[i] / arry[i];
      //  printf("%.2lf ", sum);
    }
    printf("%d/%d\n%.2lf\n", arrx[N], arry[N], sum);
    return 0;
}



