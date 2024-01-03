/*************************************************************************
 const方法
 ************************************************************************/

#include<iostream>
using namespace std;

class Point {
public:
    Point() : x(0), y(0){} //默认构造，初始化
    Point(int x, int y) :get_x_cnt(0), x(x), y(y) {} 
    void set_x(int x) {this->x = x;} //
    void set_y(int y) {this->y = y;} //
    int get_x() const{ //const,函数内的值不发生改变
        this->get_x_cnt += 1;
        return this->x;
    }
    int get_y() const{return this->y;} 
    int x_cnt() const {
        return this->get_x_cnt;
    }
private :
    mutable int get_x_cnt; //mutable关键字，const方法中能够修改值
    int x, y;
};

int main() {
    const Point p(10, 20), q(19, 30);
    cout << p.get_x() << ", " << p.get_y() << endl;
    p.get_x(), q.get_x();
    cout << "p.x_cnt = " << p.x_cnt() << endl;
    cout << "q.x_cnt = " << q.x_cnt() << endl;
    return 0;
}


