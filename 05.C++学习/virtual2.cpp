/*************************************************************************
	> File Name: virtual2.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 24 Dec 2023 08:46:19 PM CST
 ************************************************************************/
//虚函数跟着对象走
#include<iostream>
using namespace std;

class Base {
public:
    virtual void say(int x){
        cout << this << " : " << x << endl;
        cout <<"base : " << x << endl;;
    }
};

class A : public Base{
public:
    void say(int x) {
        cout << this << " : " << this->x << endl;
        cout << "class A : " << x << endl;
    }
    int x;
};
class B : public Base{
public:
    void say(int x) {
        cout << this << " : " << this->x << endl;
        cout << "class B : " << x << endl;
    }
    int x;
};

int main() {
    A a;
    B b;
    int x = 10;
    a.say(x);
    b.say(x);
    return 0;
}

