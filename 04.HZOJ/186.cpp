/*************************************************************************
	> File Name: 186.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 19 Dec 2023 10:30:27 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int fun(vector<int> v, int n, int a){
    if(v[0] >= n) return 1;
    return (fun(v, n, a + v[a]) + 1);
}

int main() {
    int n;
    vector<int> v;
    cin >> n;
    for(int i = 0, a; i < n; i++){
        cin >> a;
        v.push_back(a);
    }
    cout << fun(v, n, 0) << endl;//从初始位置到跳出的次数
    return 0;
}

