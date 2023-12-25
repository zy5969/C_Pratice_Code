/*************************************************************************
类似地，将9分别与1、2、3、4、5相乘，可以得到1至9全数字的数918273645，并称之为9和(1\2\3\4\5)的拼接乘积。
考虑所有n>1时某个整数和(1/2...n)的拼接乘积，
其中最大的1至9全数字的数是多少？
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#define N 10000

//获取数字的位数
int digitnum(int n){
    return floor(log10(n)) + 1;
}

int count(int a){
    int n = 1, sum = 0;//(1--n), 拼接乘积
    //拼接
    while(digitnum(sum) < 9){
        int x = digitnum(a * n);
        sum *= (int)pow(10, x);//强制将10的x次方转为int型,便计算
        sum += a * n;
        n += 1;
    }
    //拼接后的数字位为9
    if(digitnum(sum) != 9) return 0;
    int arr[10] = {0};//取1-9位数是否都存在
    arr[0] = 1;
    int m = sum;
    while(m){
        if(arr[m % 10]) return 0;
        arr[m % 10] = 1;
        m /= 10;
    }
    return sum;
}

int main() {
    int val = 0;
    for(int i = 1; i < N; i++){
        int a = count(i);//拼接乘积
        if(a > val) val = a;
    }
    printf("val = %d\n", val);
    return 0;
}

