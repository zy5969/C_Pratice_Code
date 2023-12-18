/*************************************************************************
	> File Name: OJ1117.pair-first.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 18 Dec 2023 02:12:27 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include <utility>
using namespace std;

int main() {
    int k;
    string str;
    //pair
    pair<string, int> p;
    cin >> str >> k;
    auto q = make_pair(str, k);

    cout << q.first << " " << q.second << endl;
    return 0;
}

