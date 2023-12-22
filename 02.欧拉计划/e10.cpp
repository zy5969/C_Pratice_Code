/*************************************************************************
	> File Name: e10.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 22 Dec 2023 05:13:55 PM CST
 ************************************************************************/

#include<iostream>
#define max 2000000
using namespace std;

//线性筛
void dealprime(int *arr){
    for(int i = 2; i < max; i++){
        if(!arr[i]) arr[++arr[0]] = i;
        for(int j = 1; j <= arr[0]; j++){
            if(arr[j] * i > max) break;
            arr[arr[j] * i] = 1;//m * p
            if(i % arr[j] == 0) break;
        }
    }
    return ;
}

int main() {
    long val = 0;
    int a[10] = {0};
    //开辟空间
    int *arr = (int *)calloc(max + 5, sizeof(int));
    dealprime(arr);
    for(int i = 1; i <= arr[0]; i++){
        val += arr[i];
    }
    cout << arr[0] << endl;
    cout << val << endl;
    return 0;
}

