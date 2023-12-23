/*************************************************************************
 求最大的由两个3位数相乘得到的回文数
 ************************************************************************/

#include<iostream>
using namespace std;
//翻转数字并判断
int reverse(int n) {
    int a = n, b = 0;
    while(a){
        b = b * 10 + a % 10;
        a /= 10;
    }
    return b == n;
}

int main(){
    int sum = 1;
    //循环枚举100-999
    for(int i = 100; i < 1000; i++){
        for(int j = 100; j < 1000; j++){ 
            //优化 j = (sum/i >= 100?ans/a + 1 : a)
            if(reverse(i * j) && sum < i * j) {
                sum = i * j;
            }
        }
    }
    cout << sum << endl;
    return 0;
}

