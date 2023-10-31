/*************************************************************************
	> File Name: e8.c
	> Author: 
	> Mail: 
	> Created Time: Tue 31 Oct 2023 09:11:13 PM CST
 ************************************************************************/

//600851475143的最大质因数
//写成素因子加幂次乘积
#include <stdio.h>
//将宏替换为long long类型
#define P 600851475143LL

int main() {
    long long i = 2, n = 0, sum = P;
    while(i * i <= sum) {
        if(sum % i == 0) n = i;//n就为素数
        while(sum % i == 0) sum /= i;//素因子不断被P除尽
        i++;
    }
    if(sum != 1) n = sum;//sum不为1则剩下部分是最大的素因子
    printf("%lld\n", n);
    return 0;
}


