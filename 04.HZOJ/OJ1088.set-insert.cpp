/*************************************************************************
	> File Name: OJ1088.set-insert.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 17 Dec 2023 05:24:18 PM CST
 ************************************************************************/

#include<iostream>
#include <set>
using namespace std;

int main() {
    int n;
    set<int> s;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        s.insert(a);
    }

    for(auto j = s.begin(); j != s.end(); j++){
        if(j != s.begin()) cout << " ";
        cout << *j;
    }
    cout << endl;
    return 0;
}

