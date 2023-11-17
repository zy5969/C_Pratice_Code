/*************************************************************************
	> File Name: static.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 17 Nov 2023 08:21:29 PM CST
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

class point {
public:
    point() : x(0), y(0) {}
    point(int x, int y) : x(x), y(y) {}
    void set_x(int x) {this->x = x;}
    void set_y(int y) {this->y = y;}

    int get_x() {
        point::get_x_cnt += 1;
        return this->x;
    }

    int get_y() {return this->y;}
    static int x_cnt() {
        return point::get_x_cnt;
    }
private:
    static int get_x_cnt;
    int x, y;
};

int point::get_x_cnt = 0;//define

int main() {
    point p1(3, 4), p2(5, 6);
    cout << p1.get_x() << ", " << p1.get_y() << endl;
    cout << p2.get_x() << ", " << p2.get_y() << endl;
    p1.get_x(), p1.get_x(), p1.get_x();
    cout << "x_cnt : " << point::x_cnt() << endl;
    return 0;
}

