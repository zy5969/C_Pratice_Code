/*************************************************************************
	> File Name: 函数重载.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 04 Jan 2024 09:32:30 AM CST
 ************************************************************************/
//同名函数的不同实现功能
#include<iostream>
#include <string>
using namespace std;

void output(int n){
    cout << "outputn : " << n << endl;
    return ;
}

void output(long long s){
    cout << "outputl : " << s << endl;
    return ;
}

void output(string s){
    cout << "outputs : " << s << endl;
    return ;
}

void output(int *a){
    if(a) cout << "a = " << a << endl;
    else cout << "output* : nullptr" << endl;
    return ;
}

void output(int a, int b){
    cout << "output2 : " << a << " " << b << endl;
    return ;
}

void count(int a = 0, int b = 3, int c = 5){
    cout << "count3 : " << a << " " << b << " " << c << endl;
    return ;
}

int main() {
    int n = 9;
    output(9);//传入参数默认为int型
    output(5LL);
    output("abcdeab");
    output(5, 10);
    output(nullptr);
    output(&n);
    cout << "-----count------" << endl;
    count();
    count(12);
    count(12, 13);
    count(12, 13, 14);
    return 0;
}

