/*************************************************************************
	> File Name: OJ1132.algorithm-lower.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 19 Dec 2023 09:53:10 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int n, k;
    vector<int> v;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    auto ind = lower_bound(v.begin(), v.end(), k);
    if(ind == v.end()) cout << (n + 1) << endl;
    else cout << ind - v.begin() + 1 << endl;
    return 0;
}

