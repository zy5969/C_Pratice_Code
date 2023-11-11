/*************************************************************************
	> File Name: 186.c
	> Author: 
	> Mail: 
	> Created Time: Sat 11 Nov 2023 08:53:15 PM CST
 ************************************************************************/

#include <stdio.h>
#define max_n 100000

int n;
int arr[max_n + 5] = {0};
//x 代表次数，d 位置
int fun(int d, int x){
    if(d >= n) return x - 1;//输出第一次的x
    return fun(d + arr[d], x + 1);//次数加1，位置更新为前一次跳到的位置
}

int main() {
   
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("%d\n", fun(0, 1));//初始位置和次数
    return 0;
}



