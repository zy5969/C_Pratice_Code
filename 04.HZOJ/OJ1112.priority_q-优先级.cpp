/*************************************************************************
	> File Name: OJ1112.priority_q-优先级.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 17 Dec 2023 11:19:36 PM CST
 ************************************************************************/

#include<iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n;
    //greater使最小元素在队首
    priority_queue<int, vector<int>, greater<int> > q;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        q.push(a);
    }
    cout << q.top() << endl;
    return 0;
}

