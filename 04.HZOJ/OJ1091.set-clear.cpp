/*************************************************************************
	> File Name: OJ1091.set-clear.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 18 Dec 2023 09:05:53 AM CST
 ************************************************************************/

#include<iostream>
#include<set>
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
    s.clear();
    cout << s.size() << endl;
    return 0;
}


