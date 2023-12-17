/*************************************************************************
	> File Name: OJ1092.string输入输出.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 17 Dec 2023 06:21:11 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int main() {
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        cout << s[i];
    }
    cout << endl;
    return 0;
}

