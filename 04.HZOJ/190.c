/*************************************************************************
	> File Name: 190.c
	> Author: 
	> Mail: 
	> Created Time: Mon 13 Nov 2023 07:26:07 PM CST
 ************************************************************************/

//任一个大于2的偶数，写成2个质数的和
#include<stdio.h>
#define max_n 8000000

int num[max_n + 5] = {0};
void prime(){ 
    for(int i = 2; i < max_n; i++){
        if(num[i]) continue;
        for(int j = i, I = max_n / j; j <= I; j++){
            num[i * j] = 1;   
        }
    }
}

    
//运行时间问题
int main() {
    int n;
    int x = 0;
    scanf("%d", &n);
    prime();
    for(int i = 2; i <= n / 2; i++){
        if(!num[i] && !num[n - i]) {
            x++;
        }
    }
    printf("%d\n", x);
    return 0;
}



