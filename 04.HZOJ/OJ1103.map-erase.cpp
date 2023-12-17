/*************************************************************************
	> File Name: OJ1103.map-erase.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 17 Dec 2023 03:36:58 PM CST
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
    mp.erase(k);
    for(auto j = mp.begin(); j != mp.end(); j++){
        cout << j->first << " " << j->second << endl;
    }
    return 0;
}

