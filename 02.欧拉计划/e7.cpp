/*************************************************************************
	> File Name: e7.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 22 Dec 2023 04:16:08 PM CST
 ************************************************************************/

#include<iostream>
#define max 1000000
using namespace std;

int arr[max];
//素数筛
void prime(){
    for(int i = 2; i <= max; i++){
        if(arr[i]) arr[i] = i;
        for(int j = i, t = max / i; j <= t; j++){
            arr[i * j] = i;
        }
    }
    return ;
}

//线性筛取arr[10001]
void prime2() {
     for(int i = 2; i < max; i++){
        if(arr[i]) arr[++arr[0]] = i;//从1开始记录素数值
        for(int j = i, t = max / i; j <= t; j++){
            if(arr[j] *i > max) break;//被标记的值不超过范围
            arr[arr[j] * i] = 1;
            if(i % arr[j] == 0)break;//i中最小素因子与arr[j]相等
        }
    }
    return ;
}


int main() {
    int n = 1, val = 0;
    prime();
    for(int i = 2; i <= max; i++){
        if(arr[i]) continue;
        n++;
        if(n == 10001) {
            val = i;
            break;
        }
    }
    cout << val << endl;
    return 0;
}


