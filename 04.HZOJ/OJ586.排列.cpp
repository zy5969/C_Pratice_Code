/*************************************************************************
	> File Name: OJ586.排列.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 06 Jan 2024 10:48:47 PM CST
 ************************************************************************/

#include<iostream>
#include <cmath>
#include <vector>
#define max 1000
using namespace std;

int gcd(int x, int y) {
    if(x == 0 || y == 0){
        return x ? x : y;
    }
    return gcd(y, x % y);
}

int gcdval(int x, int y, int z){
    if(x == 1 || y == 1 || z == 1) return 1;
    int n = gcd(x, y);
    return gcd(n, z);
}

int digit(int n){
    return (floor(log10(n)) + 1);
}

int count(int a1, int a2, int a3) {
    if(digit(a1) + digit(a2) + digit(a3) != 9) return 0;
    int num[10] = {0};
    num[0] = 1;
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

//测试！！！！！！！！！！！！！！！！！！
int main() {
    int x, y, z;
    int arr[max + 5] = {0};
    cin >> x >> y >> z;
    int n = gcdval(x, y, z);
    int m = 0;
 //   cout << n << endl;
    vector<vector<int> > result;
    for(int i = 100; i < max; i++){
        vector<int> v;
        int val = i / n;
        int val1 = val * x;
        int val2 = val * y;
        int val3 = val * z;
        if(!count(val1, val2, val3)) continue;
        if(arr[val1]) continue;
        v.push_back(val1);
        v.push_back(val2);
        v.push_back(val3);
        m++;
        if(n == 1) result.push_back(v);
        else if(n != 1 && m == n) result.push_back(v);      
        v.clear();
        arr[val1] = 1;
    }
 //   cout << result.size() << endl;
    output(result);
    return 0;
}

