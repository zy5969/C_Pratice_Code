/*************************************************************************
	> File Name: class定义.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 30 Dec 2023 10:17:26 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class People {
public:   //添加访问权限为公共
    string name;
    unsigned int age;
    char sex;
    //行为，介绍自己
    void say() { 
        cout << "My name is " << name;
        cout << ", I'm " << age << "years old, ";
        if(sex == 'm') {
            cout << "I'm a boy!" << endl;
        } else {
            cout << "I'm a girl!" << endl;
        }
    }
};



class A {
public:
    A(){
        cout << "默认构造" << endl;
    } 
    A(int x, int y) {
        cout << "两个参数" ;
        this->x = x;
        this->y = y;
    }
    A(int x) {
        //转换构造函数
        this->x = x;
        this->y = 0;       
    }
    void output() {
        cout << "(" << x << " , " << y  << ")" << endl;
    }
    ~A() {
        cout << "析构函数" << endl;
    }
private:
    int x, y;
};

void fun(A a){
    cout << "fun : " ;
    a.output();
    return;
}

int main() {
    People hug;//定义一个People类对象
    hug.name = "naming";//赋值类对象内要使用的成员
    hug.age = 20;
    hug.sex = 's';
    hug.say();//调用类对象中的方法
    cout << "----------"<< endl;
    
    A a; //默认调用
    A b(3, 4), c(5);//d = 4;使用时调用的是转换构造
    b.output();
    c.output();
    cout << "----------"<< endl;

    fun(b);
    fun(c);
    cout << "----------"<< endl;
    fun(6);//将6转换为A类的6值
    return 0;
}

