/*************************************************************************
	> File Name: OJ1129.sort2.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 19 Dec 2023 03:49:30 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int n;
    vector<int> v;
    cin >> n;
    for(int i = 0, m; i < n; i++){
        cin >> m;
        v.push_back(m);
    }
    sort(v.begin(), v.end(), greater<int>());
    for(int i = 0; i < n; i++){
        i && cout << " ";
        cout << v[i] ;
    }
    cout << endl;
    return 0;
}


