/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 07 Jan 2024 10:59:22 PM CST
 ************************************************************************/

#include<iostream>
#include "paipk.h"
using namespace std;
#define max 18

//提示牌类型
void usages(int n) {
    if(n >= 1) printf("1 : Dan\n");
    if(n >= 2) printf("2 : Duizi\n");
    if(n >= 3) printf("3 : Shunzi\n");
    if(n >= 4) printf("4 : SanDai\n");
    if(n >= 5) printf("5 : ZhaDan\n");
    if(n >= 6) printf("6 : DKing\n");
    if(n >= 7) printf("7 : PASS\n");
    printf("input : ");
    return ;
}

Pmes *read_p(int n = 7) {
    Pmes *ps;
    
    int m, x, l;
    while(1) {
        usages(n);
        cin >> m;//输入出牌情况
        if(m > n) continue;
        switch(m){
            case 1:cin >> x; ps = new DAN(x); break;
            case 2:cin >> x; ps = new DOUB(x); break;
            case 3:{
                cin >> x >> l; 
                ps = new SHUN(x, l);
            }break;
            case 4:{
                cin >> x;
                Pmes *dai = read_p(2);
                ps= new THERR(x, dai);
            }break;
            case 5:cin >> x; ps = new ZHADAN(x); break;
            case 6:ps = new DKING(); break;
            case 7:ps = new PASS(); break;
        }
        break;
    }
    return ps;
}

int main() {
    int x;
    int arr[max + 5] = {0};
    while(cin >> x){
        if(x == 0) break;
        arr[x] += 1;
    }
    Pmes *p = read_p();//读取
    vector<Pmes *> vec = Pmes::getpais(arr, p);//获取所有牌型
    for(auto i : vec){
        i->output() << endl;
    }
    return 0;
}
