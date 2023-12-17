/*************************************************************************
	> File Name: OJ1111.priority_q-size.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 17 Dec 2023 11:13:57 PM CST
 ************************************************************************/
//优先队列
#include<iostream>
#include <queue>
using namespace std;

int main() {
    int n, k;
    priority_queue<int> q;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        q.push(a);
    }
    for(int j = 0; j < k; j++){
        q.pop();
    }
    cout << q.size() << endl;
    return 0;
}


