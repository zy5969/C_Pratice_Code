/*************************************************************************
	> File Name: OJ1105.map访问与操作.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 17 Dec 2023 03:55:20 PM CST
 ************************************************************************/

#include<iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    int n;
    string str;
    map<string, int> mp;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str;
        auto p = mp.find(str);
        if(p != mp.end()) mp[str] += 1;
        else mp[str] = 1;
    }

    for(auto k = mp.begin(); k != mp.end(); k++){
        cout << k->first << " " << k->second << endl;
    }
    return 0;
}

