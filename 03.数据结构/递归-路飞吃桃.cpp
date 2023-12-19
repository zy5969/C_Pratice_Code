/*************************************************************************
	> File Name: 递归-路飞吃桃.c
	> Author:OJ168 
	> Mail: 
	> Created Time: Tue 19 Dec 2023 10:34:21 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int count(int n){
    if(n == 1) return 1;//一天，1个,边界条件
    return (count(n - 1) + 1) * 2;//本层f(n),由(n - 1)求n天的个数
}

int main() {
    int n;//吃桃子的天数
    cin >> n;
    int m = count(n);//n天能吃的桃子的个数
    cout << m << endl;
    return 0;
}

