/*************************************************************************
 最小的能够被1到20整除的正数是多少？
 ************************************************************************/

#include<iostream>
using namespace std;
//最小公约数
int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main() {
    int a = 2520;
    for(int i = 11; i <= 20; i++){
        if(a % i == 0) continue;
        a = a/gcd(a, i) * i;
        cout << a << " " << i << endl;
        
        //最小公倍数=ab/最大公约数
    }
    cout << a << endl;
    return 0;
}


