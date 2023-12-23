/******************************************************
145是个有趣的数，因为1!+4!+5!=145
找出所有各位数字的阶乘和等于其本身的数，并求它们的和。
注意：1!和2!因为和不是和的形式，所以它们并不在讨论范围内。
 ******************************************************/
//临界值*
#include<iostream>
using namespace std;
#define max 3628800
//最值估算，9!*n与10^n
//阶层
int arr[max] = {1};
void deal(){
    for(int i = 1; i < max; i++){
        arr[i] = i * arr[i - 1];
    }
    return ;
}
//数是否符号
int isval(int n){
    int m = n, val = 0;
    while(m){
        val += arr[m % 10];
        m /= 10;
    }
    return n == val;
}
int main() {
    int sum = 0;
    deal();
    for(int i = 3; i < max; i++){
        if(isval(i)) sum += i;
    }
    cout << sum << endl;
    return 0;
}

