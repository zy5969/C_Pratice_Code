/*************************************************************************
	> File Name: OJ1118.pair-比较.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 18 Dec 2023 03:02:56 PM CST
 ************************************************************************/

#include<iostream>
#include<utility>
using namespace std;

int main() {
    int k1, k2, k3, k4;
    cin >> k1 >> k2;
    cin >> k3 >> k4;
    pair<int, int> p1;
    pair<int, int> p2;
    p1 = make_pair(k1, k2);
    p2 = make_pair(k3, k4);
    if(p1.first < p2.first) cout << "Yes";
    else if(p1.first > p2.first) cout << "No" ;
    else {
        if(p1.second < p2.second) cout << "Yes" ;
        else cout << "No";
    }
    cout << endl;
    return 0;
}

