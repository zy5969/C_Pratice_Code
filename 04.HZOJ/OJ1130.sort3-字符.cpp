/*************************************************************************
	> File Name: OJ1130.sort3-字符.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 19 Dec 2023 04:06:04 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

struct strsort {
    bool operator() (string s1, string s2) const {
        return s1.compare(s2) < 0;
    }
}strsort;

int main() {
    int n;
    vector<string> v;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), strsort);
    for(int i = 0; i < n; i++){
        cout << v[i] << endl;
    }
    return 0;
}

