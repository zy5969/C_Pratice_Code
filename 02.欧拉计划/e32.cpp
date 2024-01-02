/********************************************************
如果一个n位数包含了1至n的所有数字恰好一次，我们称它为全数字的；
例如，五位数15234就是1至5全数字的。
7254是一个特殊的乘积，因为在等式39×186=7254中，被乘数、乘数和
乘积恰好是1至9全数字的。
找出所有被乘数、乘数和乘积恰好是1至9全数字的乘法等式，并求出这
些等式中乘积的和。
注意：有些乘积可能从多个乘法等式中得到，但在求和的时候只计算一次。
**********************************************************/

#include <stdio.h>
#include <math.h>
#define N 10000
#define max 100000

int digitnum(int n){
    return floor(log10(n)) + 1;
}
//判断重复数字
int dcf(int n, int *num){
    int x = n, m;
    while(x){
        m = x % 10;
        if(num[m]) return 0;
        num[m] = 1;
        x /= 10;
    }
    return 1;
}

//判断一组数是否符号要求
int count(int n, int m, int sum){
    //三个数共9位数
    if(digitnum(n) + digitnum(m) + digitnum(sum) != 9) return 0;
    int arr[10] = {0};
    arr[0] = 1;
    int flag = 1;
    //三个数之间没有重复数字
    flag = flag && dcf(n, arr);
    flag = flag && dcf(m, arr);
    flag = flag && dcf(sum, arr);
    return flag;
}

int main() {
    int sum = 0;
    int keep[max + 5] = {0};
    for(int i = 1; i < 100; i++){
        for(int j = i + 1; j < N; j++){
            if(!count(i, j, i * j)) continue;
            if(keep[i * j]) continue;//跳过重复数
            printf("%d ", i * j);
            sum += i * j;
            keep[i * j] = 1;//计算过的值标记保存
        }
    }
    printf("\n");
    printf("%d\n", sum);
    return 0;
}

