/*************************************************************************
	> File Name: OJ562.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 01 Jan 2024 05:42:41 PM CST
 ************************************************************************/

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    vector<int> v;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    for(int j = 0; j < v.size(); j += 2){
        if(v[j] == v[j + 1]) continue;
        else {
            cout << v[j] << endl;
            break;
        }
    }
    return 0;
}

