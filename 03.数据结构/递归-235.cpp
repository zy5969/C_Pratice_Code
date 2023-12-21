/*********************************************************
	> File Name: 递归-235.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Dec 2023 05:10:39 PM CST
 *********************************************************/

#include<iostream>
using namespace std;

int arr[10] = {0};//存放每组方案的值
void output(int n){
    for(int i = 0; i <= n; i++){
        if(i) cout << " ";
        cout << arr[i];
    }
    cout << endl;
    return ;
}

void fun(int x, int y, int n){
    if(y > n) return ;//值不超过n
    for(int i = y; i <= n; i++){
        arr[x] = i;
        output(x);//当前方案的前x个元素输出
        fun(x + 1, i + 1, n);//后一个位置上的值方案
    }
    return ;
}

int main() {
    int n;
    cin >> n;
    fun(0, 1, n);//0位置上为1时的方案输出

    return 0;
}


