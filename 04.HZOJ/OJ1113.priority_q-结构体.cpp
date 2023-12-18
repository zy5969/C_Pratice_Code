/*************************************************************************
	> File Name: OJ1113.priority_q-结构体.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 17 Dec 2023 11:26:00 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

struct Fruit{
    string name;
    int price;
    //重载<操作符*
    bool operator<(const struct Fruit &a) const{
        return this->price > a.price;
    }
};

int main() {
    int n;
    priority_queue<Fruit> q;
    
    cin >> n;
    for(int i = 0; i < n; i++){
        Fruit ft;
        
        cin >> ft.name >> ft.price;
        q.push(ft);
        
    }
 
    cout << q.top().name << " ";
    cout << q.top().price << endl;
    return 0;
}

