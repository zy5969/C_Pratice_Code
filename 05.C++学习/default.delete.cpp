/*************************************************************************
	> File Name: default.delete.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 03 Jan 2024 09:49:21 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class A {
public:
    A() {
        cout << "class A : default " << endl;
    }
    A(int x) {
        cout << "class A : 传参" << endl;
    }
    A(const A &a) {
        cout << "class A : 拷贝" << endl;
    }
};

class B {
public:
    B() = default;//指定调用默认构造函数
    B(const B &) = default;
private:
    A a1, a2, a3;
};

class C {
public:
    C() = default;
    C(const C &) {}
private:
    A a1, a2, a3;
};

class Point {
public :
    Point() = delete;//等同于删除默认构造
    Point(int x, int y) : p(new int(4)), x(x), y(y),a(3){}
    Point(const Point &a) : x(a.x + 1),y(a.y+2),a(a.a){
        this->p = new int;
        *(this->p) = *(a.p);
    }
    void output() {
        cout << "this object : " << this << endl;
        cout << "p = " << p << ", ";
        cout << "*p = " << *p << ", ";
        cout << "x = " << x << ", ";
        cout << "y = " << y << ", ";
        cout << "a = " << &a << endl;
        return ;
    }
    ~Point() {
        delete p;
    }
private:
    int *p;
    int x, y;
    A a;
};

int main() {
    cout << "b2 = b1 : " << endl;
    B b1, b2 = b1;
    cout << "c2 = c1 : " << endl;
    C c1, c2 = c1;
    cout << "-----------------" << endl;
    Point p(3, 4), q = p; // q进行拷贝
    p.output();
    q.output();
    return 0;
}

