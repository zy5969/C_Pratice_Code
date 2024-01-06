/*************************************************************************
	> File Name: OJ586.排列.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 06 Jan 2024 10:48:47 PM CST
 ************************************************************************/

#include<iostream>
#include <vector>
#define max 1000
using namespace std;

int ans[max + 5] = {0};

int count(int a1, int a2, int a3) {
    int num[10] = {0};
    int a = a1;
    while(a) {
        int n = a % 10;
        if(!num[n]) num[n] = 1;
        else return 0;
        a /= 10;
    }
    a = a2;
    while(a) {
        int n = a % 10;
        if(!num[n]) num[n] = 1;
        else return 0;
        a /= 10;
    }
    a = a3;
    while(a) {
        int n = a % 10;
        if(!num[n]) num[n] = 1;
        else return 0;
        a /= 10;
    }
    return 1;
}

void output(vector<vector<int> >& result){
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < 3; j++){
            j && cout << " ";
            cout << result[i][j] ;
        }
        cout << endl;
    }
    return ;
}

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    int n = x + y + z;
    vector<int> v;
    vector<vector<int> > result;
    for(int i = 100; i < max; i++){
        if(i % n) continue;
        int val = i / n;
        int val1 = i * x;
        int val2 = i * y;
        int val3 = i * z;
        if(!count(val1, val2, val3)) continue;
        v.push_back(val1);
        v.push_back(val2);
        v.push_back(val3);
        result.push_back(v);
        v.clear();
    }
    cout << result.size() << endl;
    cout << v.size() << endl;
    output(result);
    return 0;
}

