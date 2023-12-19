/*************************************************************************
	> File Name: OJ1125.algorithm-next_permutation.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 19 Dec 2023 02:29:38 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

namespace Test{
    void put(vector<int> v, int n){
        for(int i = 0; i < n; i++){
            i && cout << " ";
            cout << v[i];
        }
        cout << endl;
    }
}

int main() {
    int n;
    vector<int> v;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        v.push_back(i);
    }
    Test::put(v, n);
    while(next_permutation(v.begin(), v.end())){
        Test::put(v, n); 
    }
    return 0;
}

