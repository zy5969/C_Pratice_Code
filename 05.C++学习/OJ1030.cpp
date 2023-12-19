/*************************************************************************
	> File Name: OJ1030.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 13 Dec 2023 05:39:34 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, k;
    vector<int> arr;
    cin >> n;
    cin >> k;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    cout << arr[k - 1] << endl;
    return 0;
}


