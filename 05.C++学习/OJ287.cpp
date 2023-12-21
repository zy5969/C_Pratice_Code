/*************************************************************************
	> File Name: OJ287.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Dec 2023 10:55:26 AM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<utility>
using namespace std;

//小顶堆
typedef pair<int, int> PAIR;//
class Head : public set<PAIR> {
public:
    Head() : t(0) {};
    int top() { return begin()->first;}//堆顶
    void push(int x){//入堆
        insert(PAIR(x, ++t));
        return ;
    }
    void pop() {
        erase(begin());//堆首删除
        return ;
    }
private:
    int t;//时间戳
};


int main() {
    int n;
    Head count;//果子数
    cin >> n;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        count.push(val);
    }
    int a = 0, b = 0, c = 0;
    for(int i = 1; i < n; i++){
        a = count.top();
        count.pop();
        b = count.top();
        count.pop();
        c += a + b;
        count.push(a + b);//每一次合并后的果子要参与后续的合并
    }
   
    cout << c << endl;
    return 0;
}


