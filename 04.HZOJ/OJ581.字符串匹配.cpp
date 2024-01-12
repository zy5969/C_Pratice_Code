/*************************************************************************
	> File Name: OJ581.字符串匹配.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 09 Jan 2024 04:21:10 PM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    if(a == 0 || b == 0) {
        return a ? a : b;
    }
    return gcd(b ,a % b);
}
//结果转字符
string push(int p, int m){
    string s;
    int x = p, i = 0;
    while(x) {
        s.insert(s.begin(), (x % 10) + '0');
        x /= 10;
    }
    if(p == m) return s;
    s.push_back('/');
    x = m;
    while(x) {
        s.insert(s.end() - i, (x % 10) + '0');
        x /= 10;
        i++;
    }
    return s;
}

//计算
string count(vector<string>& a){
    string s; 
    int p = 0, m = a[0].size() + a[1].size();
    //匹配
    if(a[0] == a[1]) {
        s = "1";
        return s;
    }
    for(int i = 0; i < a[1].size(); i++) {
        int val = 0;
        for(int j = 0; j < a[0].size(); j++){
            if(a[1][j + i] == a[0][j]) val += 1;
        }
        if(p < val) p = val;
    }
    int c;
    p *= 2;
    c = gcd(m, p);
    //答案存放到字符串 
    if(p == 0 || m == 0) s.push_back('0');
    else s = push(p / c, m / c);
    return s;
}

//匹配
void comp(vector<vector<string> >& v){
    string s;//a/b
    for(int i = 0; i < v.size(); i++){
        s = count(v[i]);
        v[i].push_back(s);
    }
    return ;
}

//输出
void output(vector<vector<string> >& v) {
    for(int i = 0; i < v.size(); i++){
    cout << "appx(" << v[i][0] << "," << v[i][1] << ")=" << v[i][2] << endl;
    }
    return ;
}

int main() {
    string s, s2;
    vector<string> vs;
    vector<vector<string> > v;
    int n = 0;
    //获取输入信息
    while(1) {
        cin >> s;
        if(s == "-1") break;
        n += 1;
        vs.push_back(s);
        if(n == 2) {
            v.push_back(vs);
            vs.clear();
            n = 0;
        }
    }
    //匹配
    comp(v);
    output(v);
    return 0;
}

