/*************************************************************************
	> File Name: 递归-组合型枚举.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Dec 2023 05:47:40 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int arr[10] = {0};

void output(int n){
    for(int i = 0; i < n; i++){
        if(i) cout << " ";
        cout << arr[i];
    }
    cout << endl;
    return ;
}

void fun(int x, int y, int n, int m){
    if(x >= m) return ;//数组大小控制在m以内
    for(int i = y ; i <= n; i++){
        if(x == 0 && i > n - m + 1) return;//每组的给个值都在1-n
        arr[x] = i;
        if(x == m - 1) output(m);//每到m个数就输出
        fun(x + 1, i + 1, n, m);
    }
    return ;
}

int main() {
    int n, m;
    cin >> n >> m;
    fun(0, 1, n, m);//0位置最小值为1的情况
    return 0;
}

