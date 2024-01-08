/*************************************************************************
	> File Name: 解残局.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 20 Dec 2023 11:14:46 AM CST
 ************************************************************************/
#include <iostream>
#include <vector>
#include "paipk.h"
using namespace std;
#define max 18
//直接列出各牌型
string name[max + 5] = {" ", " ", " ", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A", "2", "king", "KING"};

Pmes::Pmes(P_TYPE type) : type(type) {}
//不要
PASS::PASS() : Pmes(P_TYPE::PASS_TYPE) {}
ostream &PASS::output()  {
    return cout << "pass";
}
//对手只要出牌,就可以不要
bool PASS::operator>(Pmes *p) {
    return p->type != P_TYPE::PASS_TYPE;
}
void PASS::take(int *arr) {return ;}//去除
void PASS::back(int *arr) {return ;}//放入

vector<Pmes *> PASS::get(int *arr) {
    vector<Pmes *> v;
    v.push_back(new PASS());
    return v;
}


//派生关系生成单牌
DAN::DAN(int x) : Pmes(P_TYPE::DAN_TYPE), x(x) {}
ostream &DAN::output() { 
    cout << "DAN " << name[x];
    return cout;
}
//对手出单牌 / 不要时可出单牌
bool DAN::operator>(Pmes *p) {
    switch(p->type) {
        case P_TYPE::PASS_TYPE : return true;
        case P_TYPE::DAN_TYPE : {
            DAN *q = dynamic_cast<DAN *>(p);
            return this->x > q->x;
        } break;
        default : return false;
    }
    return false;
}

void DAN::take(int *arr) { arr[x] -= 1; }
void DAN::back(int *arr) { arr[x] += 1;}

//类方法根据首牌获取所有可行牌
vector<Pmes *> DAN::get(int *arr) {
    vector<Pmes *> v;
    for (int i = 3; i < max; i++) {
        if (arr[i] == 0) continue;
        v.push_back(new DAN(i));
    }
    return v;
}

DOUB::DOUB(int x) : Pmes(P_TYPE::DUIZI_TYPE), x(x) {}
    //输出对子及牌型
    ostream &DOUB::output() {
        cout <<"DOUB : " << name[x] ;
        return cout;
    }
//对手不要，对子
bool DOUB::operator>(Pmes *p) {
    switch(p->type) {
        case P_TYPE::PASS_TYPE : return true;
        case P_TYPE::DUIZI_TYPE: {
            DOUB *d = dynamic_cast<DOUB *>(p);
            return this->x > d->x;
        } break;
        default : return false;
    }
    return false;
}

void DOUB::take(int *arr) { arr[x] -= 2;}
void DOUB::back(int *arr) { arr[x] += 2;}

//获取已有牌的对子
vector<Pmes *> DOUB::get(int *arr) {
    vector<Pmes *> v;
    for(int i = 3; i < max; i++){
        if(arr[i] < 2) continue;
        v.push_back(new DOUB(i));
    }
    return v;
}

//顺子，起始，长度，输出，获取
SHUN::SHUN(int x, int l) : Pmes(P_TYPE::SHUNZI_TYPE), x(x),l(l) {} //起始，长度
    ostream &SHUN::output() {
        cout << "SHUN : " ;
        for(int i = x; i <= l + x; i++){
            cout << name[i] << " "; 
        }
        return cout;
    }
//对手不要 / 顺子
bool SHUN::operator>(Pmes *p){
    switch(p->type) {
        case P_TYPE::PASS_TYPE : return true;
        case P_TYPE::SHUNZI_TYPE : {
            SHUN *s = dynamic_cast<SHUN *>(p);
            if(this->l != s->l) return this->l > s->l;
            return this->x > s->x;
        } break;
        default : return false;
    }
    return false;
}

void SHUN::take(int *arr) {
    for(int i = x; i < l + x; i++){
        arr[i] -= 1;
    }
}
void SHUN::back(int *arr) {
    for(int i = x; i < l + x; i++){
        arr[i] += 1;
    }
}

vector<Pmes *> SHUN::get(int *arr) {
    vector<Pmes *> v;
    for(int i = 5; i <= 12; i++){ //长度
        for(int j = 3; j <= 14 - i + 1; j++){ //长度范围内的牌
            int flag = 1;
            for(int k = j; k < i + j; k++){ 
                if(arr[k]) continue;
                flag = 0;//范围内没有连续牌
                break;
            }
            if(flag == 1) v.push_back(new SHUN(j, i));
        }
    }
    return v;
}

//三带
THERR::THERR(int x, Pmes *dai) : Pmes(P_TYPE::SANDAI_TYPE), x(x), dai(dai) {}
ostream &THERR::output()  {
    cout << "SAN " << name[x] << "DAI ";
    dai->output();
    return cout;
}
//
bool THERR::operator>(Pmes *p) {
    switch(p->type){
        case P_TYPE::PASS_TYPE : return true;
        case P_TYPE::SANDAI_TYPE : {
            THERR *t = dynamic_cast<THERR *>(p);
            if(t->dai->type != this->dai->type) return false;
            return this->x > t->x;
        } break;
        default : return false;
    }
    return false;
}



vector<Pmes *> THERR::get(int *arr){
    vector<Pmes *> v;
    for(int i = 3; i < max; i++){
        if(arr[i] < 3) continue;
        v.push_back(new THERR(i, new PASS()));//3个相同
        for(int j = 3; j < max; j++){
            if(arr[j] == 0 || i == j) continue;
            v.push_back(new THERR(i, new DAN(j)));//3带1
            if(arr[j]>=2)v.push_back(new THERR(i,new DOUB(j)));//3带2
        }
    }
    return v;
}

//炸弹4个相同
ZHADAN::ZHADAN(int x) : Pmes(P_TYPE::ZHADAN_TYPE), x(x) {}
ostream &ZHADAN::output()  {
    return cout << "ZDAN" << name[x];
}
//除王炸的所有大于对手的炸弹
bool ZHADAN::operator>(Pmes *p) {
    switch(p->type) {
        case P_TYPE::DKING_TYPE : return false;
        case P_TYPE::ZHADAN_TYPE : {
            //实现虚函数类型转换dynamic_cast
            ZHADAN *q = dynamic_cast<ZHADAN *>(p);
            return this->x > q->x;
        } break;
        default : return true;
    }
    return false;
}

void ZHADAN::take(int *arr) { arr[x] -= 4; }
void ZHADAN::back(int *arr) { arr[x] += 4; }

vector<Pmes *> ZHADAN::get(int *arr){
    vector<Pmes *> v;
    for(int i = 3; i < max; i++){
        if(arr[i] < 4) continue;
        v.push_back(new ZHADAN(i));
    }
    return v;
}

//王炸
DKING::DKING() : Pmes(P_TYPE::DKING_TYPE) {}
ostream &DKING::output() {
    return cout << "D_KING";
}
//对手出除了王炸的任何牌
bool DKING::operator>(Pmes *p) {
    switch(p->type) {
        case P_TYPE::DKING_TYPE : return false;
        default : return true;
    }
    return false;
}

void DKING::take(int *arr) {
    arr[16] -= 1;
    arr[17] -= 1;
}
void DKING::back(int *arr){
    arr[16] += 1;
    arr[17] += 1;
}

vector<Pmes *> DKING::get(int *arr){
    vector<Pmes *> v;
    if(arr[16] && arr[17]) v.push_back(new DKING());
    return v;
}

//所有可能结果
vector<Pmes *> Pmes::getpk(int *arr) {
    vector<Pmes *> temp;
    vector<Pmes *> p1 = DAN::get(arr);//单牌
    vector<Pmes *> p2 = DOUB::get(arr);//对子
    vector<Pmes *> p3 = SHUN::get(arr);//顺子
    vector<Pmes *> p4 = THERR::get(arr);//三带
    vector<Pmes *> p5 = PASS::get(arr);//不要
    vector<Pmes *> p6 = ZHADAN::get(arr);//炸弹
    vector<Pmes *> p7 = DKING::get(arr);//王炸
    for(auto i : p1) temp.push_back(i);
    for(auto i : p2) temp.push_back(i);
    for(auto i : p3) temp.push_back(i);
    for(auto i : p4) temp.push_back(i);
    for(auto i : p5) temp.push_back(i);
    for(auto i : p6) temp.push_back(i);
    for(auto i : p7) temp.push_back(i);
    return temp;
}

//可出牌
vector<Pmes *> Pmes::getpais(int *arr, Pmes *pai){
    vector<Pmes *> p1 = getpk(arr);
    vector<Pmes *> p;
    for(auto i : p1) {
        if(i->operator>(pai)) p.push_back(i);
        else delete i;
    }
    return p;
}

//剩余牌的类型，数量
void Pmes::output_ab(int *arr){
    for(int i = 3; i < max; i++){
        if(!arr[i]) continue;
        cout << name[i] << " : " << arr[i] << "|| ";
    }
    cout << endl;
    return ;
}


