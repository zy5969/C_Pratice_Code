/*************************************************************************
	> File Name: OJ585排名.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 12 Jan 2024 04:51:24 PM CST
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int getnum(vector<vector<int> >& vi, int val, int a) {
    int n = 0;
    //排名高且年级低
    for(int i = a; i >= 0; i--){
        if(vi[i][1] < val) n += 1;
    }
    return n;
}


void fun(vector<vector<int> >& vs) {
    int cnt = 0;
    for(int i = 0; i < vs.size(); i++){
        cnt = getnum(vs, vs[i][1], i);
        vs[i].push_back(cnt);
    }
    return ;
}


void output(vector<vector<int> >& v) {
    for(int i = 0; i < v.size(); i++){
        cout << v[i][2] << endl;
    //    cout << v[i][0] << " " << v[i][1]  << " " << v[i][2] << endl;
    }
    return ;
}

//重载
struct {
    bool operator()(vector<int>& a, vector<int>& b) {
        if(a[0] == b[0]) {
            return a[1] < b[1];
        }
        if(a[0] > b[0]) return a > b;
    }
}comp;


int main() {
    int n;
    vector<vector<int> > vs;
    vector<int> v;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        v.push_back(a);
        v.push_back(b);
        vs.push_back(v);
        v.clear();
    }
    //排名:成绩高到低，年级低到高
//    sort(vs.begin(), vs.end());
    sort(vs.begin(), vs.end(), comp);
    fun(vs);
    
    output(vs);
    return 0;
}

