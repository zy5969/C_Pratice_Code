/*************************************************************************
	> File Name: sort.cpp
    sort排序
************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



int main() {
    //容器初始化
    vector<int> arr = {12, 23, 4, 25, 36, 41, 78, 32, 9, 93};
    sort(arr.begin(), arr.end());//起始位置
    for(int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}


