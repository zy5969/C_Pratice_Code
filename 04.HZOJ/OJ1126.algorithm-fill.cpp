/*************************************************************************
	> File Name: OJ1126.algorithm-fill.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 19 Dec 2023 02:59:30 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int k;
    int a[3][5];
    cin >> k;
    for(int i = 0; i < 3; i++){
        fill(&a[i][0], &a[i][5], k);
        for(int j = 0; j < 5; j++){
            j && cout << " ";
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}

