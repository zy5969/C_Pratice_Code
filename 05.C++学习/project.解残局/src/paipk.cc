/*************************************************************************
	> File Name: 解残局.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 20 Dec 2023 11:14:46 AM CST
 ************************************************************************/
#include <iostream>
#include <vector>
#include <paipk.h>
using namespace std;
#define max 18
//直接列出各牌型
string name[max + 5] = {" ", " ", " ", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A", "2", "king", "KING"};

ostream &PASS::output()  {
    return cout << "pass";
}

vector<Pmes *> PASS::get(int *arr) {
    vector<Pmes *> v;
    v.push_back(new PASS());
    return v;
}


//派生关系生成单牌
DAN::DAN(int x) : x(x) {}
ostream &DAN::output() { 
    cout << "DAN " << name[x];
    return cout;
}
//类方法根据首牌获取所有可行牌
vector<Pmes *> DAN::get(int *arr) {
    vector<Pmes *> ret;
    for (int i = 3; i < max; i++) {
        if (arr[i] == 0) continue;
        ret.push_back(new DAN(i));
    }
    return ret;
}

DOUB::DOUB(int x) :x(x) {}
    //输出对子及牌型
    ostream &DOUB::output() {
        cout <<"DOUB : " << name[x] ;
        return cout;
    }
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
    SHUN::SHUN(int x, int l) : x(x),l(l) {} //起始，长度
    ostream &SHUN::output() {
        cout << "SHUN : " ;
        for(int i = x; i <= l + x; i++){
            cout << name[i] << " "; 
        }
        return cout;
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
    THERR::THERR(int x, Pmes *dai) :x(x), dai(dai) {}
    ostream &THERR::output()  {
        cout << "SAN " << name[x] << "DAI ";
        dai->output();
        return cout;
    }
vector<Pmes *> THERR::get(int *arr){
        vector<Pmes *> v;
        for(int i = 3; i < max; i++){
            if(arr[i] < 3) continue;
            v.push_back(new THERR(i, new PASS()));//3个相同
            for(int j = 3; j < max; j++){
                if(arr[j] == 0 || i == j) continue;
                v.push_back(new THERR(i, new DAN(j)));//3带1
                if(arr[j] >= 2) v.push_back(new THERR(i, new DOUB(j)));//3带2(对子)
            }
        }
        return v;
    }

//炸弹4个相同
ZHADAN::ZHADAN(int x) : x(x) {}
ostream &ZHADAN::output()  {
    return cout << "ZDAN" << name[x];
}

vector<Pmes *> ZHADAN::get(int *arr){
    vector<Pmes *> v;
    for(int i = 3; i < max; i++){
        if(arr[i] < 4) continue;
        v.push_back(new ZHADAN(i));
    }
    return v;
}

//王炸
ostream &DKING::output() {
    return cout << "D_KING";
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
