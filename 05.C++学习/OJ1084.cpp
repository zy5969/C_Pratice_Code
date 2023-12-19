/*************************************************************************
	> File Name: OJ1084.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 13 Dec 2023 06:00:02 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;
    int n, x, k1, k2;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    cin >> x;
    cin >> k1;
    cin >> k2;
    v.insert(v.begin() + k1, x);
    v.erase(v.begin() + k2, v.begin() + k2 + 1);
    for(int j = 0; j < v.size(); j++){
        j && cout << " ";
        cout << v[j];
    }
    cout << endl;
    return 0;
}


