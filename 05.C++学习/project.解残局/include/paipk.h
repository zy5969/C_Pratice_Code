/*************************************************************************
	> File Name: paipk.h
	> Author: 
	> Mail: 
	> Created Time: Sun 07 Jan 2024 09:03:44 PM CST
 ************************************************************************/

#ifndef _PAIPK_H
#define _PAIPK_H
#include <vector>
#include <iostream>
using namespace std;

class Pmes {
public :
    static vector<Pmes *> getpk(int *);
    virtual ostream &output() = 0;//virtual,定义虚函数
};

class PASS : public Pmes{
public :
    ostream &output();
    static vector<Pmes *> get(int *arr) ;
};

//派生关系生成单牌
class DAN : public Pmes {
public :
    DAN(int x);
    ostream &output() ; 
    //类方法根据首牌获取所有可行牌
    static vector<Pmes *> get(int *arr) ;
private :
    int x;
};

class DOUB : public Pmes {
public :
    DOUB(int x);
    //输出对子及牌型
    ostream &output();
    //获取已有牌的对子
    static vector<Pmes *> get(int *arr);
private :
    int x;
};

//顺子，起始，长度，输出，获取
class SHUN : public Pmes {
public :
    SHUN(int x, int l); //起始，长度
    ostream &output();
    static vector<Pmes *> get(int *arr);
private :
    int x, l;
};

//三带
class THERR : public Pmes {
public : 
    THERR(int x, Pmes *dai);
    ostream &output();
    static vector<Pmes *>get(int *arr);
private :
    int x;
    Pmes *dai;
};

//炸弹4个相同
class ZHADAN : public Pmes {
public :
    ZHADAN(int x);
    ostream &output();
    static vector<Pmes *> get(int *arr);
private:
    int x;
};

//王炸
class DKING : public Pmes{
public:
    ostream &output();
    static vector<Pmes *> get(int *arr);
};

#endif
