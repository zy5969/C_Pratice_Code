/*************************************************************************
	> File Name: class定义_1.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 30 Dec 2023 07:44:41 PM CST
 ************************************************************************/

#include<iostream>
#include <map>
#include <string>
using namespace std;

class A;
class Mymap : public map<void *, string> {
public :
    void output(void *p, string s){
        if(find(p) == end()) {
            cout << "unknown name " << p;
        }else {
            cout << operator[](p);
        }
        cout << s << endl;
        return ;
    }
}name;

//在哪个类中引用空间，就在哪个类销毁空间
class A {
public:
    A(string n){
        name[this] = n;
        name.output(this, " class A 构造");
    }
    ~A(){
        name.output(this, " class A 析构");
    }
    int *p;//整型指针
};


class B {
public : 
    B(string n, A &a) : a(a){
        name[this] = n;//申请整型空间
        name.output(this, " class B 构造");
        a.p = new int;
    }
    A &a;
    ~B() {
        name.output(this, " class B 析构");
        delete a.p;//清除A类对象
    }
};

//属性与当前构造顺序
class C {
public:
    //初始化列表，:后即初始化
    C(string n) : a(n + ".a"), b(n + ".b"){
        name[this] = n;
        name.output(this, " class C 构造");
    }
    char ch;//加占位符，区别a,b位置,a位置与C类的首地址相同
    A a, b;
    ~C() {
        name.output(this, " class C 析构");
        //
    }
};

class Point {
public:
    Point() : x(3), y(x + 2) {} //先使用x，应先声明x
    void output() {
        cout << "(" << x << " , " << y << ")" << endl;
    }
private:
    int x, y;
};

int main() {
    A a("a");
    B b("b", a);
    C c("c");
    Point P;
    P.output();//x没有初始化,生成一个随机值:定义顺序与使用顺序不同
    return 0;
}

