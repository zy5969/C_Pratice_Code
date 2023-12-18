/*************************************************************************
	> File Name: OJ1099.string-find.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 18 Dec 2023 05:11:35 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    if(s1.find(s2) != -1) cout << s1.find(s2) << endl;
    else cout << "-1" << endl;
    return 0;
}

