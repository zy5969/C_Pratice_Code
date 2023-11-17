/*************************************************************************
	> File Name: constructor.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 16 Nov 2023 08:09:21 PM CST
 ************************************************************************/

#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

class A;
    class MyMap : public map < A *, string > {
    public:
        void output(A *p, string s) {
            if(find(p) == end()) {
                cout << "unknown name " << p;
            }
            else {
                cout << operator[](p);
            }
            cout << s << endl;
            return;
        }
    } name;

class A {
public :
    A() {
        name.output(this, " default constructor");
    }
    A(int x) {
        name.output(this, " transfer constructor");
        this->x = x;
        this->y = 0;
    }
    A(const A& a) {
        name.output(this, " copy constructor");
        this->x = a.x;
        this->y = a.y;
    }
    A(int x, int y) {
        name.output(this, " 2 arguments constructor");
        this->x = x;
        this->y = y;
    }
    void operator = (const A &a) {
        name.output(this, " operator = ");
        this->x = a.x;
        this->y = a.y;
        return ;
    }
    void output() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
    ~A() {
        name.output(this, " destructor");
    }
    private:
    int x, y;
};

void func(A a) {
    cout << "func : ";
    a.output();
    return ;
}

namespace copy_constructor {
    int main() {
        const A d;
        A a;
        A b = a, c = d;
        name[&a] = "a";
        name[&b] = "b";
        name[&c] = "c";
        cout << "c = a " << endl;
        c = a;
        cout << "a = " << &a << endl;
        cout << "b = " << &b << endl;
        cout << "c = " << &c << endl;
        return 0;
    }
}

namespace test1 {
    int main() {
        A a(3, 4), b(3), c = 4;
        a.output();
        b.output();
        func(a);
        func(b);
        cout << "==========" << endl;
        func(6);
        return 0;
    }
}

int main() {
    copy_constructor::main();
    return 0;
}

