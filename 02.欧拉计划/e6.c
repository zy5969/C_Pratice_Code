/*************************************************************************
	> File Name: e6.c
	> Author: 
	> Mail: 
	> Created Time: Mon 30 Oct 2023 08:59:23 PM CST
 ************************************************************************/

//整除1~20的最小数 最小公倍数 = 各个乘积/最大公约数
//1~10 2520
#include<stdio.h>
//最大公约数
int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main() {
    int a = 1;//a = 2520, i直接由已知值开始
    for(int i = 2; i <= 20; i++){
        a = a / gcd(a, i) * i;//先除在乘防止溢出
    }
    printf("%d\n", a);
    return 0;
}



