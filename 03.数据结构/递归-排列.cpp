/*************************************************************************
	> File Name: 递归-排列.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 19 Dec 2023 11:00:19 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int arr[10];
void output(int n){
    for(int i = 0; i <= n; i++){
        if(i) cout << " ";
        cout << arr[i];
    }
    cout << endl;
    return ;
}

void fun(int x, int y, int n){
    if(y > n) return ;//最大值不超过n
    for(int i = y; i <= n; i++){
        arr[x] = i;
        output(x);
        fun(x + 1, i + 1, n);
    }
    return ;
}

int main() {
    int n;
    cin >> n;
    fun(0, 1, n);//获取一组方案的排列
    return 0;
}

