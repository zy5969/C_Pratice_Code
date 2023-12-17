/*************************************************************************
	> File Name: OJ1108.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 15 Dec 2023 03:55:06 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, k;
    queue<int> q;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        q.push(x);
    }
    
    //出队
    for(int j = 0; j < k; j++){
        q.pop();
    }
    cout << q.size() << endl;

    return 0;
}

