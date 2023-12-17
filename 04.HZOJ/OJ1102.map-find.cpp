/*************************************************************************
	> File Name: OJ1102.map-find.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 17 Dec 2023 03:23:53 PM CST
 ************************************************************************/

#include<iostream>
#include <map>
using namespace std;

int main() {
    int n, val;
    char key, k;
    map<char, int> mp;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> key >> val;
        mp[key] = val;
    }
    cin >> k;
    auto a = mp.find(k);
    if(a != mp.end()) cout << mp[k] << endl;
    else cout << "-1" << endl;
    return 0;
}

