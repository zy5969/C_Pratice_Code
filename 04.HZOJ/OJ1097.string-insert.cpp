/*************************************************************************
	> File Name: OJ1097.string-insert.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 18 Dec 2023 03:53:57 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int main() {
    string s;
    int k1, k2;
    char c;
    cin >> s;
    cin >> k1 >> c;
    cin >> k2;
    s.insert(s.begin() + k1, c);
    s.erase(s.begin() + k2);
    cout << s << endl;
    return 0;
}

