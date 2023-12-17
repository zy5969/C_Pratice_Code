/*************************************************************************
	> File Name: OJ1090.set-erase.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 17 Dec 2023 06:03:19 PM CST
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
    auto pos = s.find(x);//获取删除元素位置的迭代器
    if(pos != s.end()) s.erase(pos);
    for(auto i = s.begin(); i != s.end(); i++){
        if(i != s.begin()) cout << " ";
        cout << *i;//相应位置上的值
    }
    cout << endl;
    return 0;
}

