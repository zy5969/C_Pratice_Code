/*************************************************************************
	> File Name: OJ1128.algorithm-sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 19 Dec 2023 03:29:37 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int n;
    vector<int> v;
    cin >> n;
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        v.push_back(m);
    }
    sort(v.begin(), v.end());
    for(int j = 0; j < n; j++){
        j && cout << " ";
        cout << v[j];
    }
    cout << endl;
    return 0;
}

