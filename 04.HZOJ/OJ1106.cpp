/*************************************************************************
	> File Name: OJ1106.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 15 Dec 2023 03:42:30 PM CST
 ************************************************************************/

#include<iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    queue<int> q;
    cin >> n;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        q.push(t);
    }
    cout << q.front() << " " << q.back() << endl;
    return 0;
}


