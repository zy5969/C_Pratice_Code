/*************************************************************************
	> File Name: OJ110.priority_q-pop.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 17 Dec 2023 07:01:32 PM CST
 ************************************************************************/

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

    if(q.empty()) cout << "empty priority queue" << endl;
    else cout << q.top() << endl;

    return 0;
}

