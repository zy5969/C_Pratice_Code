/*******************************************************
 600851475143的最大质因数是多少？
 *******************************************************/
//范围估计
#include<iostream>
using namespace std;
//#define max 600851475143LL
#define max 600851475143

int main(){
    long long n = max;//转为long long
    long num, m = 2;
    while(m * m <= n) { //最大素因子在2~根号n内
        if(n % m == 0) num = m; //num记录最大素因子
        while(n % m == 0) n /= m;
        m++;
    }
    if(n != 1) num = n;//
    cout << num << endl;
    return 0;
}

