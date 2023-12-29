/*************************************************************************
	> File Name: OJ256.封装.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Dec 2023 11:08:34 PM CST
 ************************************************************************/
//类封装大整数
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//普通处理，小范围数据,数据类型存在问题
int data(int n){
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    vector<int> ind(n + 1);
    for(int i = 0; i < n + 1; i++){
        cin >> a[i] >> b[i];
        ind[i] = i;
    }
    sort(ind.begin() + 1, ind.end(), [&](int i, int j) -> bool{
        return a[i] * b[i] < a[j] * b[j];
    });
    int p = a[0], ans = 0, temp;
    for(int i = 1; i <= n; i++){
        temp = p / b[ind[i]];
        if(temp > ans) ans = temp;
        p *= a[ind[i]];
    }
    return ans;
}


class Winsort : public vector<vector<int> > {
public: 
    void push(int x){
    }

};

int main() {

    return 0;
}

