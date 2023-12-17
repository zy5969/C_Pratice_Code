/*************************************************************************
	> File Name: OJ1104.map-clear.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 17 Dec 2023 03:49:57 PM CST
 ************************************************************************/

#include<iostream>
#include <map>
using namespace std;

int main() {
    int n, val;
    char key;
    map<char, int> mp;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> key >> val;
        mp[key] = val;
    }
    cout << mp.size() << " ";
    mp.clear();
    cout << mp.size() << endl;
    return 0;
}

