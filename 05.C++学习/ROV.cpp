/*************************************************************************
	> File Name: ROV.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 15 Nov 2023 08:14:34 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public :
    A() { //默认
        cout << this << " default" << endl;
    }
    A(const A &) { //拷贝
        cout << this << " 拷贝" << endl;
    }
    string s;
};

A func() {
    A temp; //引用，优化返回值
    cout << "temp = " << &temp << endl;
    temp.s = "func";
    return temp;
}

int main() {
    A a = func();
    A b = func();
    cout << "a = " << &a << endl;
    cout << "b = " << &b << endl;
    return 0;
}

