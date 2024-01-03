/*************************************************************************
 const方法
 ************************************************************************/

#include<iostream>
using namespace std;

class Point {
public:
    //声明，不含函数的操作
    Point(); //默认构造，初始化
    Point(int x, int y); 
    void set_x(int x);
    void set_y(int y);
    int get_x() const;
    int get_y() const;
    static int x_cnt();
private :
    static int get_x_cnt; 
    int x, y;
};
//定义
Point::Point() : x(0), y(0){} //默认构造，初始化
Point::Point(int x, int y) : x(x), y(y) {} 
void Point::set_x(int x) {this->x = x;} //
void Point::set_y(int y) {this->y = y;} //
int Point::get_x() const{ //const,函数内的值不发生改变
    Point::get_x_cnt += 1;
    return x;
}
int Point::get_y() const{return y;} 
int Point::x_cnt() {
    return Point::get_x_cnt;
}

int Point::get_x_cnt = 0;//定义并初始化

int main() {
    Point p(10, 20), q(19, 30);
    cout << p.get_x() << ", " << p.get_y() << endl;
    cout << q.get_x() << ", " << q.get_y() << endl;
    p.get_x(), p.get_x();
    cout << "x_cnt = " << Point::x_cnt() << endl;
    return 0;
}


