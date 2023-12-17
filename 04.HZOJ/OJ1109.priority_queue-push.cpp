/*************************************************************************
	> File Name: OJ1109.priority_queue-push.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 17 Dec 2023 06:54:37 PM CST
 ************************************************************************/

#include<iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    priority_queue<int> q;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        q.push(a);
    }
    cout << q.top() << endl;
    return 0;
}

