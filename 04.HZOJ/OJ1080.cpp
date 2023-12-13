/*************************************************************************
	> File Name: OJ1080.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 13 Dec 2023 10:56:59 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<int> v;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    //输出
    for(int j = 0; j < n; j++){
        j && cout << " ";
        cout << v[j];
    }
    cout << endl;
    return 0;
}


