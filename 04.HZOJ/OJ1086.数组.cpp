/*************************************************************************
	> File Name: OJ1086.数组.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 17 Dec 2023 02:06:02 PM CST
 ************************************************************************/

#include<iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    vector<int> vs[10];
    vector<int> v;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> k;
        v.push_back(k);
        for(int j = 0; j < k; j++){
            int val;
            cin >> val;
            vs[i].push_back(val);
        }
    }
    //遍历
    for(int i = 0; i < n; i++){
        for(int j = 0; j < v[i]; j++){
            j && cout << " ";
            cout << vs[i][j];
        }
        cout << endl;
    }

    return 0;
}

