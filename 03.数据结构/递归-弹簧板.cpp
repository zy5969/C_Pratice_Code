/*************************************************************************
	> File Name: 递归-弹簧板.cpp
	> Author: OJ186
	> Mail: 
	> Created Time: Tue 19 Dec 2023 11:34:11 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int fun(int n, vector<int> &v, int x){ //&,引用，减少一次变量拷贝
    if(x >= n) return 0;//跳出的位置大于n时返回
    return (fun(n, v, x + v[x]) + 1);//(x + v[x] + 1) 跳出后的位置
}

int main() {
    int n, m;
    vector<int> v;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    m = fun(n, v, 0);//从0开始弹出弹簧板的次数 
    cout << m << endl;
    return 0;
}

