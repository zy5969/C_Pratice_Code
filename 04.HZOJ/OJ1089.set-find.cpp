/*************************************************************************
	> File Name: OJ1089.set-find.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 17 Dec 2023 05:34:47 PM CST
 ************************************************************************/

#include<iostream>
#include <set>
using namespace std;

int main() {
    int n, x;
    set<int> s;
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        s.insert(a);
    }
    //查询，删除
  //  cin >> x;
    auto a = s.find(x);
    if(a != s.end()) s.erase(a);

    for(auto k = s.begin(); k != s.end(); k++){
        if(k != s.begin()) cout << " ";
        cout << *k;
    }
    cout << endl;
    return 0;
}


