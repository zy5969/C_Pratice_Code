/*************************************************************************
	> File Name: OJ1095.string-比较.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 18 Dec 2023 09:10:15 AM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int p = s1.compare(s2);
    if(p == 0) cout << "0" << endl;
    else if(p > 0) cout << "1" << endl;
    else cout << "-1" << endl;
    return 0;
}

