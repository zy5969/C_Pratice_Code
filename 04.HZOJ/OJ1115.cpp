/*************************************************************************
	> File Name: OJ1115.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 15 Dec 2023 12:00:59 PM CST
 ************************************************************************/

#include<iostream>
#include <stack>

using namespace std;

int main() {
    int n, k;
    stack<int> s;
    cin >> n;
    cin >> k;
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        s.push(m);
    }
    for(int j = 0; j < k; j++){
     //   if(s.empty()) break;
        s.pop();
    }
    if(s.empty()) cout << "empty stack" << endl;
    else cout << s.top() << endl;
    return 0;
}


