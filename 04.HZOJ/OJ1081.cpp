/*************************************************************************
	> File Name: OJ1081.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 13 Dec 2023 11:06:36 PM CST
 ************************************************************************/

#include<iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n;
    cin >> k;
    vector<int> v(n, k);
    for(int i = 0; i < n; i++){
        i && cout << " ";
        cout << v[i] ;
    }
    cout << endl;
    return 0;
}


