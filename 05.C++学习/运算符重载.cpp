/*************************************************************************
	> File Name: 运算符重载.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 04 Jan 2024 10:16:36 AM CST
 ************************************************************************/

#include<iostream>
#include <vector>
#include <cmath>
using namespace std;

class Point {
public :
    Point(double x, double y) : x(x), y(y), indx(0) {}
    //
private :
    double x, y;
    int indx;
    friend ostream & operator<<(ostream &, const Point &);
    friend double operator*(const Point &, const Point &);
    friend Point operator*(const Point &, double);
    friend Point operator+(const Point &, double);
    friend Point &operator-(Point &, int);
    friend Point &operator-(Point &, Point &);
    friend class Putaxis;
};

//类外重载
ostream & operator<<(ostream &out, const Point &p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

//p1*p2
double operator*(const Point &a, const Point &b){
    return a.x * b.x + a.y * b.y;
}

//p1*n
Point operator*(const Point &a, double b){
    return Point(a.x * b , a.y * b);
}

//n*p1
Point operator*(double b, const Point &a){
    return a * b;//返回值后调用Point * double函数
}

//p1+n
Point operator+(const Point &a, double b){
    return Point(a.x + b, a.y + b);
}

//p1-6-p2-"\n"
//存储6的值
Point &operator-(Point &a, int n){
    a.indx = n;
    return a;
}
//-p2
Point &operator-(Point &a, Point &b) {
    char s[100] = {0};
    snprintf(s, 99, "(%%%dg, %%%dg)", a.indx, a.indx);
    printf(s, b.x, b.y);
    return a;
}
//"\n"
Point &operator-(Point &a, const char *s){
    cout << s;
    return a;
}

//p1^p2^p3^p4^1,p1,p2,p3,p4放在坐标轴上^1时输出
class Putaxis {
public :
    Putaxis() : per_x(5), per_y(2) {};
    void add(Point &a) const {points.push_back(a);}//添加点坐标
    void output() const;
    //画x轴
    void draw_axisx(char **n, int y0, int maxlen, int x)const{
        for(int i = 0; i < maxlen; i++){
            if((i - 2) % per_x == 0) {
                n[y0][i] = '.';
                int ret = snprintf(n[y0 + 1] + i + 1, maxlen, "%d", x);
                n[y0 + 1][i + 1 + ret] = ' ';
                x += 1;
            } else {
                n[y0][i] = '-';
            }
        }
        return ;
    }
    //y轴
    void draw_axisy(char **n, int x0, int maxlen, int y)const{
        for(int i = 0; i < maxlen; i++){
            if(i >= 2 && (i - 2) % per_y == 0) {
                if(y == 0) {
                    n[i][x0] = '+';
                    y--; continue;
                }
                n[i][x0] = '-';
                int ret = snprintf(n[i] +x0 + 2, maxlen, "%d", y);
                n[i][x0 + 2 + ret] = ' ';
                y--;
            } else n[i][x0] = '.';
        }
        return ;
    }
    //输出坐标轴
    void output_xy(char **n, int Xmax, int Ymax) const {
        for(int i = 0; i < Ymax; i++){
            for(int j = 0; j < Xmax; j++){
                printf("%c", n[i][j]);
            }
            printf("\n");
        }
        return ;
    }
    //描点
    void draw_point(char **n, int x0, int y0, Point &p) const{
        int x = x0 + p.x * per_x;
        int y = y0 - p.y * per_y; 
        
        n[y][x] = '*';
        int t = points.size();
        return ;
    }
private :
    mutable vector<Point> points;//存坐标信息
    int per_x, per_y;
};

//输出
void Putaxis::output() const {
    double xmin = INT32_MAX, xmax = INT32_MIN;
    double ymin = INT32_MAX, ymax = INT32_MIN;
    //遍历坐标信息，取坐标轴范围
    for(auto p : points) {
        xmin = min(xmin, p.x);
        xmax = max(xmax, p.x);
        ymin = min(ymin, p.y);
        ymax = max(ymax, p.y);
    }
    xmin = min(0.0, floor(xmin)) - 1;//最小值减1
    ymin = min(0.0, floor(ymin)) - 1;
    xmax = ceil(xmax) + 1;//最大值加1
    ymax = ceil(ymax) + 1;
    int max_x = max(xmax - xmin, ymax - ymin) * per_x + 5;
    int max_y = max(xmax - xmin, ymax - ymin) * per_y + 5;
    //开辟空间存放坐标，初始为空格
    char **str = (char **)malloc(sizeof(char *) * max_y);
    for(int i = 0; i < max_y; i++){
        str[i] = (char *)malloc(sizeof(char) * max_x);
        for(int j = 0; j < max_x; j++) str[i][j] = ' ';
    }
    //相对原点的偏移量
    int x0 = per_x * (int)fabs(xmin - 0) + 2;
    int y0 = per_y * (int)fabs(ymax - 0) + 2;//
    //建立坐标轴
    draw_axisx(str, y0, max_x, xmin);
    draw_axisy(str, x0, max_y, ymax);
    //描点
    for(auto p : points) draw_point(str, x0, y0, p);
    //输出坐标轴
    output_xy(str, max_x, max_y);
    return ;
}


//p1^p2
Putaxis operator^(Point &a, Point &b) {
    Putaxis c;
    c.add(a);//存入坐标数组
    c.add(b);
    return c;
}

//(p1^p2)^p3
Putaxis operator^(const Putaxis &a, Point &b){
    a.add(b);
    return a;
}

//(p1^p2)^1
Putaxis operator^(const Putaxis &a, int n){
    a.output();
    return a;
}

int main() {
    Point p1(2, 3), p2(3, 6), p3(1, 3), p4(3, 4);
    cout << p1 << " " << p2 << endl;
    cout << p1 * p2 << endl;//求内积
    cout << p1 * 1.2 << endl;
    cout << 1.2 * p1 << endl;
    cout << p1 + 5 << endl;
    p1-4-p2-"\n";
    cout << "--------------------------------" << endl;
    p1^p2^p3^p4^1;
    return 0;
}

