/*************************************************************************
	> File Name: OJ1107.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 15 Dec 2023 03:47:12 PM CST
 ************************************************************************/

#include<iostream>
#include <queue>

using namespace std;

int main() {
    int n, k;
    queue<int> q;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        q.push(a);
    }
    for(int j = 0; j < k; j++){
        q.pop();
    }
    //判空
    if(q.empty()) cout << "empty queue" << endl;
    else cout << q.front() << " " << q.back() << endl;
    return 0;
}


