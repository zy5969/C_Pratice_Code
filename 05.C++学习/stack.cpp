/*************************************************************************
	> File Name: stack.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 15 Dec 2023 10:21:47 AM CST
 ************************************************************************/

#include <iostream>
#include <stack>

using namespace std;

namespace Test {
    void output(stack<int> s) {
        for(int j = 0; j < 5; j++){
            cout << s.top();
            cout << " ";
            //出栈
            s.pop();
        }
        cout << endl;
    }
}

int main() {
    stack<int> s;
    stack<int> s1;
    //判空
    //入栈
    for(int i = 1; i <= 5; i++){
        s.push(i);
    }
    if(s.empty()) cout << "stack empty" << endl;
    else cout << "stack not empty" << endl;
    for(int i = 6; i <= 10; i++){
        s1.push(i);
    }
    Test::output(s);
    Test::output(s1);
    swap(s.top(), s1.top());//交换栈顶
    swap(s, s1);//交换两个栈;s.swap(s1);
    
    Test::output(s);
    Test::output(s1);
    return 0;
}


