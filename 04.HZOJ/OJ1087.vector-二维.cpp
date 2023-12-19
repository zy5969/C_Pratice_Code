/*************************************************************************
	> File Name: OJ1087.vector-二维.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 19 Dec 2023 01:58:20 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, k;
    cin >> n;
    vector<int> v;
    vector<vector<int> > vs(n, vector<int>());
    for(int i = 0; i < n; i++){
        cin >> k;
        v.push_back(k);
        for(int j = 0; j < k; j++){
            int m;
            cin >> m;
            vs[i].push_back(m);
        }
    }

    //输出
    for(int i = 0; i < n; i++){
        for(int j = 0; j < v[i]; j++){
            j && cout << " ";
            cout << vs[i][j];
        }
        cout << endl;
    }
    return 0;
}


