/*************************************************************************
	> File Name: static.类方法.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 03 Jan 2024 08:56:17 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Point {
public:
    Point() : x(0), y(0){} //默认构造，初始化
    Point(int x, int y) : x(x), y(y) {} //有参,初始化x,y传入参数
    void set_x(int x) {this->x = x;} //
    void set_y(int y) {this->y = y;} //
    int get_x() {
        Point::get_x_cnt += 1;//访问类对象,计数get_x调用次数
        return this->x;
    }
    int get_y() {return this->y;} 
    static int x_cnt() {
        return Point::get_x_cnt;//命名空间方式访问类
    }
private :
    static int get_x_cnt; //声明类对象
    int x, y;
};

int Point::get_x_cnt = 0;//定义类对象，初始化为0

int main() {
    Point p(1, 2), q(9, 0);
    cout << p.get_x() << ", " << p.get_y() << endl;
    cout << q.get_x() << ", " << q.get_y() << endl;
    p.get_x(), p.get_x();
    cout << "xcnt : " << Point::x_cnt() << endl;
    return 0;
}


