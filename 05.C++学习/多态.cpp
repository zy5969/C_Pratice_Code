/*************************************************************************
	> File Name: 多态.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 22 Dec 2023 09:13:29 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public :
    A() {
        cout << "A class" << endl;
    }
};

class B : public A {
public:
    B() {
        cout << "B class" << endl;
    }
};


int main() {
    A a;
    B b;
    return 0;
}

