/*************************************************************************
	> File Name: OJ1114.cpp
	> Author: 
	> Mail:栈，插入，输出栈顶 
	> Created Time: Fri 15 Dec 2023 11:55:10 AM CST
 ************************************************************************/

#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    stack<int> s;
    cin >> n;
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        s.push(m);
    }
    cout << s.top() << endl;
    return 0;
}


