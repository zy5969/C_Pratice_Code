/*************************************************************************
	> File Name: OJ1082.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 15 Dec 2023 09:43:30 AM CST
 ************************************************************************/

#include<iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n;
    cin >> k;
    vector<int> v(n, k);
    for(int i = 0; i < k; i++){
        v.pop_back();
    }
    if(n < k) {
        cout << n - k << endl;
        return 0;
    }
    cout << v.size() << endl;
    return 0;
}


