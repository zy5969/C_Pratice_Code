/*************************************************************************
	> File Name: paipk.h
	> Author: 
	> Mail: 
	> Created Time: Sun 07 Jan 2024 09:03:44 PM CST
 ************************************************************************/

#ifndef _PAIPK_H
#define _PAIPK_H

#include <iostream>
#include <vector>
using namespace std;

enum class P_TYPE {
    DAN_TYPE,
    DUIZI_TYPE,
    SHUNZI_TYPE,
    SANDAI_TYPE,
    ZHADAN_TYPE,
    DKING_TYPE,
    PASS_TYPE
};

class Pmes {
public :
    Pmes(P_TYPE type);
    static void output_ab(int *arr);
    static vector<Pmes *> getpk(int *);
    static vector<Pmes *> getpais(int *, Pmes *);
    virtual ostream &output() = 0;//virtual,定义虚函数
    virtual bool operator>(Pmes *p) = 0;//重载大于符号
    virtual void take(int *) = 0;//去除
    virtual void back(int *) = 0;//放入

    P_TYPE type;
    virtual ~Pmes() = default;
};

class PASS : public Pmes{
public :
    PASS();
    ostream &output();
    bool operator>(Pmes *p) override;
    void take(int *) override;//去除
    void back(int *) override;//放入
    static vector<Pmes *> get(int *arr) ;
};

//派生关系生成单牌
class DAN : public Pmes {
public :
    DAN(int x);
    ostream &output() ; 
    bool operator>(Pmes *p) override;
    void take(int *) override;//去除
    void back(int *) override;//放入
    //类方法根据首牌获取所有可行牌
    static vector<Pmes *> get(int *arr);
private :
    int x;
};

class DOUB : public Pmes {
public :
    DOUB(int x);
    //输出对子及牌型
    ostream &output();
    bool operator>(Pmes *p) override;
    void take(int *) override;//去除
    void back(int *) override;//放入
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
    bool operator>(Pmes *p) override;
    void take(int *) override;//去除
    void back(int *) override;//放入
    static vector<Pmes *> get(int *arr);
private :
    int x, l;
};

//三带
class THERR : public Pmes {
public : 
    THERR(int x, Pmes *dai);
    ostream &output();
    bool operator>(Pmes *p) override;
    void take(int *) override;//去除
    void back(int *) override;//放入
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
    bool operator>(Pmes *p) override;
    void take(int *) override;//去除
    void back(int *) override;//放入
    static vector<Pmes *> get(int *arr);
private:
    int x;
};

//王炸
class DKING : public Pmes{
public:
    DKING();
    ostream &output();
    bool operator>(Pmes *p) override;
    void take(int *) override;//去除
    void back(int *) override;//放入
    static vector<Pmes *> get(int *arr);
};

#endif
