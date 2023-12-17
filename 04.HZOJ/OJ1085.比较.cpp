/*************************************************************************
	> File Name: OJ1085.比较.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 17 Dec 2023 11:49:07 AM CST
 ************************************************************************/

#include<iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v1;
    vector<int> v2;
    //读入
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        v1.push_back(a);
    }
    for(int j = 0; j < m; j++){
        int b;
        cin >> b;
        v2.push_back(b);
    }
    //判断
    int flag = 0;
    for(int k = 0; k < n || k < m; k++){
        if(v1[k] < v2[k])  {
            flag = 1;
            break;
        } 
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}

