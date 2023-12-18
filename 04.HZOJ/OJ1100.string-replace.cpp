/*************************************************************************
	> File Name: OJ1100.string-replace.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 18 Dec 2023 05:20:18 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int main() {
    string s1, s2, s3;
    int k, len;
    cin >> s1;
    cin >> k >> len;
    cin >> s2;
    s3 = s1.replace(k, len, s2);
    
    cout << s3 << endl;
    return 0;
}

