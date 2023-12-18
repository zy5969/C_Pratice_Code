/*************************************************************************
	> File Name: OJ1098.string-substr.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 18 Dec 2023 05:01:03 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int main() {
    int k, len;
    string s, s2;
    cin >> s;
    cin >> k >> len;
    s2 = s.substr(k, len);
    
    cout << s2 << endl;
    return 0;
}

