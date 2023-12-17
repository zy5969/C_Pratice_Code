/*************************************************************************
	> File Name: OJ1101.map赋值与遍历.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 17 Dec 2023 02:24:07 PM CST
 ************************************************************************/

#include<iostream>
#include <string>
#include <map>
using namespace std;


int main() {
    int n;
    char s;
    int val;
    map<char, int> mp;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s >> val;
        mp[s] = val;
        
    }
    //输出
    for(auto j = mp.begin(); j != mp.end(); j++){
        cout << j->first <<  " " << j->second << endl;
    }
    return 0;
}


