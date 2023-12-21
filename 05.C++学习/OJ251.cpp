/*************************************************************************
	> File Name: OJ251.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 21 Dec 2023 09:53:58 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    
    //取y第K大值
    int mid = n / 2;
    //将第k大值放在k位置
    nth_element(y.begin(), y.begin() + mid, y.end());
    //x排序，横坐标相对位置不变
    sort(x.begin(), x.end());
    for(int i = 0; i < n; i++){
        x[i] -= i;//获取相对规则坐标的偏差值
    }
    nth_element(x.begin(), x.begin() + n / 2, x.end());
    int m = x[n / 2];//取中间大的元素
    int sum = 0;//步数
    for(int i = 0; i < n; i++){
        //两边向中间移动
        sum += abs(y[i] - y[mid]) + abs(x[i] - m);
    }
    cout << sum << endl;
    return 0;
}


