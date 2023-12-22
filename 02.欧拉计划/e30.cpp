/*****************************所有可以写成其各位数字的五次幂之和的数，并求这些数的和
 **************************************************/

#include<iostream>
#include<cmath>
#define max 354294
//上界值估算:10^n:n位数字的最大值;
//n*9^5:n位数每位的5次幂和最大值 
using namespace std;
//各位数的5次幂和
int isval(int n){
    int m = n, sum = 0;
    while(m){
        sum += pow(m % 10, 5);
        m /= 10;
    }
    return sum == n;
}

int main() {
    int n = 0;
    for(int i = 2; i <= max; i++){
        if(!isval(i)) continue;
        n += i;
    }
    cout << n << endl;

    return 0;
}


